// Adaptado de: https://github.com/llpilla/compiler_examples/blob/master/simple_ast/ast.cpp
// Passar map como parâmetro: http://stackoverflow.com/questions/7763397/c-pass-a-map-by-reference-into-function

#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace AST;

/////////////////
// imprimir() //

void Variavel::imprimir(int espaco, bool linha) {
    std::cout << id << "";
    return;
}

void Inteiro::imprimir(int espaco, bool linha) {
    std::cout << valor << "";
    return;
}

void Real::imprimir(int espaco, bool linha) {
    std::cout << valor << "";
    return;
}

void Boolean::imprimir(int espaco, bool linha) {
    std::cout << std::boolalpha << valor << "";
    return;
}

void Declaracao::imprimir(int espaco, bool linha) {
    imprimirEspaco(espaco);
    imprimirTipo(tipo);
    std::cout << " var: ";
    if(variaveis != NULL)  variaveis->imprimir(espaco, false);
    std::cout << "\n";
}

void Definicao::imprimir(int espaco, bool linha) {
    variavel->imprimir(espaco, false);
    if(valor != NULL) {
        std::cout << " = ";
        valor->imprimir(0, false);
    }
    if(proxima != NULL) {
        std::cout << ", ";
        proxima->imprimir(0, false);
    }
    if(linha) std::cout << "\n";
}

void OperacaoUnaria::imprimir(int espaco, bool linha) {
    imprimirTipo(tipo);
    if(filho != NULL)  filho->imprimir(0, false);
}

void OperacaoBinaria::imprimir(int espaco, bool linha) {    
    imprimirEspaco(espaco);
    imprimirTipo(tipo);
    std::cout << " ";
    if(esquerda != NULL)  esquerda->imprimir(0, false);
    std::cout << " ";
    if(direita  != NULL)  direita->imprimir(0, false);
    if(linha) std::cout << "\n";
}

void Condicao::imprimir(int espaco, bool linha) {
// if ...
    imprimirEspaco(espaco);
    std::cout << "if: ";
    teste->imprimir(0, false);
// then:    
    if(se != NULL) {
        std::cout << "\n";
        imprimirEspaco(espaco);
        std::cout << "then:\n";
        se->imprimir(espaco+2, false);
    }
// else:
    if(senao != NULL) {
        if(se == NULL) std::cout << "\n";
        imprimirEspaco(espaco);
        std::cout << "else:\n";
        senao->imprimir(espaco+2, false);        
    }
    if(se == NULL && senao == NULL) std::cout << "\n";
}

void Laco::imprimir(int espaco, bool linha) {
    imprimirEspaco(espaco);
    std::cout << "for: ";
    if(inicializacao != NULL) inicializacao->imprimir(espaco, false);
    std::cout << ", ";
    if(teste != NULL) teste->imprimir(espaco, false);
    std::cout << ", ";
    if(iteracao != NULL) iteracao->imprimir(espaco, false);
    std::cout << "\ndo:";
    if(laco != NULL) {
        std::cout << "\n";
        laco->imprimir(espaco+2, true);
    } else std::cout << "\n";
}

void Bloco::imprimir(int espaco, bool linha) {
    for (NodoBase* linha: linhas) {
        if(linha != NULL) {
          linha->imprimir(espaco, true);
        }
    }    
}


//////////////////////
// verificarTipo() //
////////////////////


Tipo Declaracao::verificarTipo(Tipo t, Tipo operador) {

  // A Declaração passa seu tipo adiante, para que verificar os tipos das variáveis declaradas
    if(variaveis != NULL) verificarTipo(tipo, operador);

  // A Declaração não possui um Tipo a ser retornado
    return Tipo::nulo;
}


Tipo Definicao::verificarTipo(Tipo t, Tipo operador) {

  // Captura-se o tipo do valor atribuido à variável
    Tipo esperado = valor->verificarTipo(t, operador);

  // Caso os tipos sejam diferentes, erro
    if(esperado != t) {
      imprimirErroDeOperacao(Tipo::atribuicao,t,esperado);
    }

  // Atribui tipo à Variável
    variavel->tipo = t;

  // A Definição não possui um Tipo a ser retornado
    return Tipo::nulo;
}


Tipo OperacaoUnaria::verificarTipo(Tipo t, Tipo operador) {
  // Captura-se o tipo do único filho
    Tipo d = filho->verificarTipo(t, operador);

  // Operações Unárias possuem tratamento diferenciado
    switch(tipo) {
      // Operação de Negação recebe um "int" ou "float" e devolve "int" ou "float"
        case Tipo::negacao:
            if(d == Tipo::boolean) {
                imprimirErroDeOperacao(tipo,t,d);
            }
            return d;

      // Operação "Inversão", ou Negação Lógica recebe "bool" e devolve "bool"
        case Tipo::inversao:
            if( d != Tipo::boolean) {
                imprimirErroDeOperacao(tipo,t,d);
            }              
            return Tipo::boolean;

      // Conversao de float ou bool para int
        case Tipo::conversao_int: 
            return Tipo::inteiro;

      // Conversao de int ou float para int
        case Tipo::conversao_float:
            return Tipo::real;

      // Conversao de int ou float para bool
        case Tipo::conversao_bool:
            return Tipo::boolean;      

      // Parênteses apenas retornam o tipo contido
        case Tipo::parenteses:
            return d;

        default: return Tipo::nulo;
    }
}


Tipo OperacaoBinaria::verificarTipo(Tipo t, Tipo operador) {

  // Coleta-se os Tipos dos filhos esquerda e direita
    Tipo e = esquerda->verificarTipo(t , operador);  Tipo d = direita->verificarTipo(t, operador);

  // Operações Binárias possuem comportamentos diferentes
    switch(tipo) {

  // Operaçãos Aritméticas recebem "int" ou "float" e devolvem "int" ou "float"
        case Tipo::atribuicao:
            if(e == Tipo::nulo) e = t;
        case Tipo::adicao:
        case Tipo::subtracao:
        case Tipo::multiplicacao:
        case Tipo::divisao:

         // O tipo da esquerda é inválido?
            if(e == Tipo::boolean) {
                imprimirErroDeOperacao(tipo,t,e);

          // O tipo da direita é inválido?
            } else if (d == Tipo::boolean) {
                imprimirErroDeOperacao(tipo,e,d);
            }
   
          // A coerção de tipos é necessária?
            if(coercaoIntParaFloat(e,d)) {

              // Se a coerção ocorre, é garantido que a operação binária retorna um tipo float
                return Tipo::real;
            } 

          // Caso não ocorra coerção, os tipos da esquerda e direita são iguais
            else {
                return e;
            }

  // Operações Lógicas recebem "bool" e devolvem "bool"
         case Tipo::e:
         case Tipo::ou:

          // O tipo da esquerda é válido?
            if(e != Tipo::boolean) {
                imprimirErroDeOperacao(tipo,Tipo::boolean,e);

          // O tipo da direita é inválido?
            } else if (d != Tipo::boolean) {
              imprimirErroDeOperacao(tipo,Tipo::boolean,d);
            }

          // Retorna o tipo boolean
           return Tipo::boolean;

  // Comparadores recebem "int" ou "float" e devolvem "bool"
         case Tipo::igual:
         case Tipo::diferente:
         case Tipo::maior:
         case Tipo::maior_igual:
         case Tipo::menor:
         case Tipo::menor_igual:

           // O tipo da esquerda é válido?
            if(e == Tipo::boolean) {
                imprimirErroDeOperacao(tipo,t,e);

          // O tipo da direita é válido?
            } else if (d == Tipo::boolean) {
                imprimirErroDeOperacao(tipo,e,d);
            }

          // Realiza-se coerção, se necessário
            coercaoIntParaFloat(e,d);

          // Independente do retorno da coerção, retorna-se um valor booleano
            return Tipo::boolean;

        default: return Tipo::nulo;               
      }
}


bool OperacaoBinaria::coercaoIntParaFloat(Tipo e, Tipo d) {
// Segundo a descrição da versão 0.3, apenas tipo int pode sofrer coerção para float, logo:

  // Se o tipo da esquerda for int e o da direita float, o da esquerda sofre coerção e retorna-se Tipo::real
    if (e == Tipo::inteiro && d == Tipo::real) {

      // Acrescenta-se um nodo com a operação de coerção entre o filho da esquerda e a operação binária
        OperacaoUnaria *coercao = new OperacaoUnaria(Tipo::conversao_float, esquerda);
        esquerda = coercao;
        return true;
    }

  // Se o tipo da esquerda for float e o da direita int, o da direita sofre coerção e retorna-se Tipo::real
    else if (e == Tipo::real && d == Tipo::inteiro) {
               
      // Acrescenta-se um nodo com a operação de coerção entre o filho da esquerda e a operação binária
        OperacaoUnaria *coercao = new OperacaoUnaria(Tipo::conversao_float, direita);
        direita = coercao;
        return true;
    }

  // Se não ocorreu coerção, retorna-se false
    return false;  
}


Tipo Condicao::verificarTipo(Tipo t, Tipo operador) {
  // O teste de uma Condição deve ser Booleano
    Tipo esperado = teste->verificarTipo(t, operador);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado);
    }

  // Se o conteúdo do "se" ou "senão" não forem vazios, também devem ser verificados
    if(se != NULL)     se->verificarTipo(t, operador);
    if(senao != NULL)  senao->verificarTipo(t, operador);

  // A Condição não possui um Tipo a ser retornado
    return Tipo::nulo;
}


Tipo Laco::verificarTipo(Tipo t, Tipo operador) {

  // O teste de um Laço deve ser Booleano
    Tipo esperado = teste->verificarTipo(t, operador);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado);
    }

  // Se o conteúdo do laço não for vazio, também deve ser verificado
    if(laco != NULL) laco->verificarTipo(t, operador);

  // A Condição não possui um Tipo a ser retornado
    return Tipo::nulo;
}


Tipo Bloco::verificarTipo(Tipo t, Tipo operador) {
std::cout << ". ";
  // Verificar os Tipos de todas as linhas do Bloco
    for (NodoBase* linha: linhas) {
        linha->verificarTipo(t, operador);    
    }

  // O Bloco não possui um Tipo a ser retornado
    return Tipo::nulo;
}


//////////////////////////
// verificarSimbolos() //
////////////////////////

void Variavel::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
    std::map<std::string, AST::Variavel*>::iterator it;
    it = tabela_simbolos.find(id);
    if (it == tabela_simbolos.end()){
        std::cout << "semantic error: undeclared variable " << id << "\n";
        exit(0);
    } else {
        //std::cout << "semantic ok: declared variable " << id << "\n";
        //tabela_simbolos[std::string(id)] = this;
        tipo = tabela_simbolos[std::string(id)]-> tipo; //como cada nodo variavel começa por default sem tipo, reatribuo o tipo original
    }
    return;
}

void Declaracao::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
   if(variaveis != NULL)  variaveis->verificarSimbolos(tabela_simbolos);
}

void Definicao::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
   if(variavel != NULL)  variavel->verificarSimbolos(tabela_simbolos);
   if(valor    != NULL)  valor->verificarSimbolos(tabela_simbolos);
   if(proxima  != NULL)  proxima->verificarSimbolos(tabela_simbolos);
}

void OperacaoUnaria::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
   if(filho != NULL)  filho->verificarSimbolos(tabela_simbolos);
}

void OperacaoBinaria::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
   if(esquerda != NULL)  esquerda->verificarSimbolos(tabela_simbolos);
   if(direita  != NULL)  direita->verificarSimbolos(tabela_simbolos);
}

void Condicao::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
    if(teste != NULL)  teste->verificarSimbolos(tabela_simbolos);
    if(se != NULL)     se->verificarSimbolos(tabela_simbolos);  
    if(senao != NULL)  senao->verificarSimbolos(tabela_simbolos);
}

void Laco::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
    if(inicializacao != NULL)  inicializacao->verificarSimbolos(tabela_simbolos);
    if(teste != NULL)          teste->verificarSimbolos(tabela_simbolos);
    if(iteracao != NULL)       iteracao->verificarSimbolos(tabela_simbolos);
    if(laco != NULL)           laco->verificarSimbolos(tabela_simbolos);
}

void Bloco::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) { 

  // Verificar os Símbolos de todas as linhas do Bloco
    for (NodoBase* linha: linhas) {
        linha->verificarSimbolos(tabela_simbolos);    
    }
}

////////////////////////////
// acrescentarSimbolos() //
//////////////////////////

void Variavel::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos,  AST::Tipo ultimoTipo) {
    std::map<std::string, AST::Variavel*>::iterator it;
    it = tabela_simbolos.find(id);
    if (it != tabela_simbolos.end()) {
        std::cout << "semantic error: re-declaration of variable " << id << "\n";
    } else {
        //std::cout << "semantic ok: declaration of variable " << id << "\n";
	tipo = ultimoTipo;
        tabela_simbolos[std::string(id)] = this;
    }
}


void Declaracao::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos,  AST::Tipo ultimoTipo) {
   if(variaveis != NULL)  variaveis->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
}


void Definicao::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos,  AST::Tipo ultimoTipo) {
   if(variavel != NULL)  variavel->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
   if(valor    != NULL)  valor->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
   if(proxima  != NULL)  proxima->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
}


void OperacaoUnaria::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos,  AST::Tipo ultimoTipo) {
   if(filho != NULL)  filho->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
}


void OperacaoBinaria::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos,  AST::Tipo ultimoTipo) {
   if(esquerda != NULL)  esquerda->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
   if(direita  != NULL)  direita->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
}


void Condicao::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos,  AST::Tipo ultimoTipo) {
    if(teste != NULL)  teste->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
    if(se != NULL)     se->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
    if(senao != NULL)  senao->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
}


void Laco::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos,  AST::Tipo ultimoTipo) {
    if(inicializacao != NULL)  inicializacao->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
    if(teste != NULL)          teste->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
    if(iteracao != NULL)       iteracao->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
    if(laco != NULL)           laco->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
}


void Bloco::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos,  AST::Tipo ultimoTipo) {

  // Verificar os Símbolos de todas as linhas do Bloco
    for (NodoBase* linha: linhas) {
        linha->acrescentarSimbolos(tabela_simbolos, ultimoTipo); 
    }
}

//////////
// etc //

void Bloco::novaLinha(NodoBase *linha) {
    linhas.push_back(linha);
}

void Definicao::ajustarProxima(Definicao *p) {
    if(proxima != NULL) {
        proxima->ajustarProxima(p);
    } else {
      proxima = p;
    }
}

void NodoBase::imprimirEspaco(int espaco) {
    for(int i = 0; i < espaco; i++) {
        std::cout << " "; 
    }
}

void NodoBase::imprimirTipo(Tipo t) {
  // One switch to rule them all
    switch(t) {
        case Tipo::inteiro:          std::cout << "int";      break;
        case Tipo::real:             std::cout << "float";    break;
        case Tipo::boolean:          std::cout << "bool";     break;

        case Tipo::atribuicao:       std::cout << "=";        break;
        case Tipo::adicao:           std::cout << "+";        break;
        case Tipo::subtracao:        std::cout << "-";        break;
        case Tipo::multiplicacao:    std::cout << "*";        break;
        case Tipo::divisao:          std::cout << "/";        break;
        case Tipo::e:                std::cout << "&";        break;
        case Tipo::ou:               std::cout << "|";        break;

        case Tipo::igual:            std::cout << "==";       break;
        case Tipo::diferente:        std::cout << "!=";       break;
        case Tipo::maior:            std::cout << ">";        break;
        case Tipo::maior_igual:      std::cout << ">=";       break;
        case Tipo::menor:            std::cout << "<";        break;
        case Tipo::menor_igual:      std::cout << "<=";       break;

        case Tipo::negacao:          std::cout << "-u ";       break;
        case Tipo::inversao:         std::cout << "! ";        break;
        case Tipo::conversao_int:    std::cout << "[int] ";    break;
        case Tipo::conversao_float:  std::cout << "[float] ";  break;
        case Tipo::conversao_bool:   std::cout << "[bool] ";   break;

        case Tipo::parenteses:       std::cout << "";       break;
        default:                     std::cout << "";        break;
    }
}

void NodoBase::imprimirTipoPorExtenso(Tipo t) {
  // One switch to rule them all
    switch(t) {
        case Tipo::inteiro:          std::cout << "integer";         break;
        case Tipo::real:             std::cout << "float";           break;
        case Tipo::boolean:          std::cout << "bool";            break;
        case Tipo::atribuicao:       std::cout << "attribution";     break;
        case Tipo::adicao:           std::cout << "addition";        break;
        case Tipo::subtracao:        std::cout << "subtraction";     break;
        case Tipo::multiplicacao:    std::cout << "multiplication";  break;
        case Tipo::divisao:          std::cout << "division";        break;
        case Tipo::e:                std::cout << "and";             break;
        case Tipo::ou:               std::cout << "or";              break;
        case Tipo::negacao:          std::cout << "- ";        break;
        case Tipo::inversao:         std::cout << "! ";        break;
        case Tipo::igual:            std::cout << "==";       break;
        case Tipo::diferente:        std::cout << "!= ";       break;
        case Tipo::maior:            std::cout << "> ";        break;
        case Tipo::maior_igual:      std::cout << ">= ";       break;
        case Tipo::menor:            std::cout << "< ";        break;
        case Tipo::menor_igual:      std::cout << "<= ";       break;
        case Tipo::conversao_int:    std::cout << "[int] ";    break;
        case Tipo::conversao_float:  std::cout << "[float] ";  break;
        case Tipo::conversao_bool:   std::cout << "[bool] ";   break;
        case Tipo::parenteses:       std::cout << "()";      break;
        default:                     std::cout << "? ";       break;
    }
}

void NodoBase::imprimirErroDeOperacao(Tipo operacao, Tipo esperava, Tipo recebeu) {
    std::cout << "operation ";      imprimirTipoPorExtenso(operacao);
    std::cout << " expected ";      imprimirTipoPorExtenso(esperava);
    std::cout << " but received ";  imprimirTipoPorExtenso(recebeu);
    std::cout << "\n";              exit(0);
}

/*

inteiro, real, boolean, atomica, adicao, subtracao, multiplicacao, divisao, e, ou, negacao, inversao, 
                      igual, diferente, maior, maior_igual, menor, menor_igual, parenteses, 
                      conversao_int, conversao_float, conversao_bool, x, semTipo
*/
