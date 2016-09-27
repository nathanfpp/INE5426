// Adaptado de: https://github.com/llpilla/compiler_examples/blob/master/simple_ast/ast.cpp
// Passar map como parâmetro: http://stackoverflow.com/questions/7763397/c-pass-a-map-by-reference-into-function

#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

/////////////////
// imprimir() //

void Variavel::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool atribuicao) {
   // if(atribuicao) { tabelaSimbolos->variavelDeclarada(id, linha); }
    std::cout << id << ""; 
}

void Inteiro::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {
    std::cout << valor << "";
    return;
}

void Real::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {
    std::cout << valor << "";
    return;
}

void Boolean::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {
    std::cout << std::boolalpha << valor << "";
    return;
}

void Declaracao::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {
    imprimirEspaco(espaco);
    imprimirTipo(tipoDeVariavel);
    std::cout << " var: ";
    if(variaveis != NULL)  variaveis->imprimir(tabelaSimbolos, espaco, linha, false);
    std::cout << "\n";
}

void Definicao::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {
    variavel->imprimir(tabelaSimbolos, espaco, linha, false);
    if(valor != NULL) {
        std::cout << " = ";
        valor->imprimir(tabelaSimbolos, 0, linha, false);
    }
    if(proxima != NULL) {
        std::cout << ", ";
        proxima->imprimir(tabelaSimbolos, 0, linha, false);
    }
    if(novaLinha) std::cout << "\n";
}

void OperacaoUnaria::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {
    imprimirTipo(operacao);
    filho->imprimir(tabelaSimbolos, 0, linha, false);
}

void OperacaoBinaria::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {  
    imprimirEspaco(espaco);
    imprimirTipo(operacao);
    std::cout << " ";
    esquerda->imprimir(tabelaSimbolos, 0, linha, false);
    std::cout << " ";
    direita->imprimir(tabelaSimbolos, 0, linha, false);
    if(novaLinha) std::cout << "\n";
}

void Condicao::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {
// if ...
    imprimirEspaco(espaco);
    std::cout << "if: ";
    teste->imprimir(tabelaSimbolos, 0, linha, false);
// then:    
    if(se != NULL) {
        std::cout << "\n";
        imprimirEspaco(espaco);
        std::cout << "then:\n";
        se->imprimir(tabelaSimbolos, espaco+2, linha, false);
    }
// else:
    if(senao != NULL) {
        if(se == NULL) std::cout << "\n";
        imprimirEspaco(espaco);
        std::cout << "else:\n";
        senao->imprimir(tabelaSimbolos, espaco+2, linha, false);        
    }
    if(se == NULL && senao == NULL) std::cout << "\n";
}

void Laco::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {
    imprimirEspaco(espaco);
    std::cout << "for: ";
    if(inicializacao != NULL) inicializacao->imprimir(tabelaSimbolos, 0, linha, false);
    std::cout << ", ";
    teste->imprimir(tabelaSimbolos, 0, linha, false);
    std::cout << ", ";
    if(iteracao != NULL) iteracao->imprimir(tabelaSimbolos, 0, linha, false);
    std::cout << "\n";
    imprimirEspaco(espaco);
    std::cout << "do:";
    if(laco != NULL) {
        std::cout << "\n";
        laco->imprimir(tabelaSimbolos, espaco+2, linha, true);
    } else std::cout << "\n";
}


////////////
// Bloco //
//////////

void Bloco::imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {
    for (Nodo* l: linhas) {
        if(l != NULL) {
            linha++;
            l->imprimir(escopo, espaco, linha, true);
        }
    }    
}

Tipo Bloco::verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) {

// Se a tabela de símbolos recebida for a principal, o Bloco é o principal
  if(linha == 0) {
      escopo = tabelaSimbolos;
  } else {
      escopo = tabelaSimbolos->novoEscopo();        
  }

  // Verificar os Tipos de todas as linhas do Bloco   
    for (Nodo* l: linhas) {
        if(l != NULL) {
            linha++;
            l->verificarTipo(escopo, t, operador, linha);
        }
    }

  // Desempilha-se este escopo, removendo seu endereçamento da tabela de símbolos ...
  // ... sendo o ponteiro para o escopo guardado apenas no Nodo::Bloco
    tabelaSimbolos->retornarEscopo();

  // O Bloco não possui um Tipo a ser retornado
    return Tipo::nulo;
}


//////////////////////
// verificarTipo() //
////////////////////

Tipo Variavel::verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) {
    Variavel *v = tabelaSimbolos->recuperarVariavel(id, linha);
    if(v != NULL) {
        return v->tipo;
    }
    return tipo;
}

Tipo Declaracao::verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) {

  // A Declaração passa seu tipo adiante, para que seja possível verificar os tipos das variáveis declaradas
    if(variaveis != NULL) variaveis->verificarTipo(tabelaSimbolos, tipoDeVariavel, operador, linha);

  // A Declaração não possui um Tipo a ser retornado
    return Tipo::nulo;
}


Tipo Definicao::verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo tipoDaDeclaracao, Tipo operador, int linha) {

  // Caso a declaração possua um valor atribuído
    if(valor != NULL) {
      // Caso o valor atribuído a variável seja de um tipo diferente do declarado, coerção ou erro
        coercaoDaDefinicao(this, tipoDaDeclaracao, valor->tipo, linha);
    }

  // Atribui tipo à Variável
    variavel->tipo = tipoDaDeclaracao;

  // Salva a variável na tabela de símbolos
    tabelaSimbolos->adicionarVariavel(variavel, linha);

  // Se houver mais de uma definição para a atribuição, ela acontece
    if(proxima != NULL) proxima->verificarTipo(tabelaSimbolos, tipoDaDeclaracao, operador, linha);

  // Definição não possui um Tipo a ser retornado
    return Tipo::nulo;
}


bool Nodo::coercaoDaDefinicao(Definicao *coagido, Tipo esperado, Tipo recebido, int linha) {
 // Se o tipo esperado e o recebido forem diferentes, ocorreu um erro...
    if(esperado != recebido) {
      // ... a não ser que possa ocorrer coerção de int para float
        if(esperado == Tipo::real && recebido == Tipo::inteiro) {
            OperacaoUnaria *coercao = new OperacaoUnaria(Tipo::opUnaria, Tipo::conversao_float, coagido->valor);
            coagido->valor = ((Nodo*) coercao);
        }
      // Caso contrário, ocorreu um erro na operação
        else {
            imprimirErroDeOperacao(Tipo::atribuicao, esperado, recebido, linha);
            return false;
        }
    }

 // Se os tipos são compatíveis, com ou sem coerção, o retorno é <true>
    return true;
}


Tipo OperacaoUnaria::verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) {

  // Captura-se o tipo do único filho
    Tipo d = filho->verificarTipo(tabelaSimbolos, t, operador, linha);

  // Operações Unárias possuem tratamento diferenciado
    switch(operacao) {
      // Operação de Negação recebe um "int" ou "float" e devolve "int" ou "float"
        case Tipo::negacao:
            if(d == Tipo::boolean) {
                imprimirErroDeOperacao(tipo, t, d, linha);
            }
            retorno = d;
            break;

      // Operação "Inversão", ou Negação Lógica recebe "bool" e devolve "bool"
        case Tipo::inversao:
            if( d != Tipo::boolean) {
                imprimirErroDeOperacao(tipo, t, d, linha);
            }              
            retorno = Tipo::boolean;
            break;

      // Conversões retornam o tipo convertido, independente da entrada
        case Tipo::conversao_int:    retorno = Tipo::inteiro;  break;
        case Tipo::conversao_float:  retorno = Tipo::real;     break;
        case Tipo::conversao_bool:   retorno = Tipo::boolean;  break;      

      // Parênteses apenas retornam o tipo contido
        case Tipo::parenteses:  retorno = d;  break;

        default:  retorno = Tipo::nulo;  break;
    }

    return retorno;
}


Tipo OperacaoBinaria::verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) {
  
  // Coleta-se os Tipos dos filhos esquerda e direita
    Tipo e = esquerda->verificarTipo(tabelaSimbolos, t , operador, linha);

    Tipo d = direita->verificarTipo(tabelaSimbolos, t, operador, linha);

  // Operações Binárias possuem comportamentos diferentes
    switch(operacao) {

  // A Atribuição recebe
        case Tipo::atribuicao:
            coercao(this, e, d, linha);
            retorno = e;
            break;

  // Operaçãos Aritméticas recebem "int" ou "float" e devolvem "int" ou "float"
        case Tipo::adicao:
        case Tipo::subtracao:
        case Tipo::multiplicacao:
        case Tipo::divisao:
            
         // O tipo da esquerda é inválido?
            if(e == Tipo::boolean) {
                imprimirErroDeOperacao(tipo, t, e, linha);

          // O tipo da direita é inválido?
            } else if (d == Tipo::boolean) {
                imprimirErroDeOperacao(tipo, e, d, linha);
            }
   
          // A coerção de tipos é necessária?
            if(coercao(this, e, d, linha)) {

              // Se a coerção ocorre, é garantido que a operação binária retorna um tipo float
                retorno = Tipo::real;
                break;
            } 

          // Caso não ocorra coerção, os tipos da esquerda e direita são iguais
            else {
                retorno = e;
                break;
            }
            break;

  // Operações Lógicas recebem "bool" e devolvem "bool"
         case Tipo::e:
         case Tipo::ou:

          // O tipo da esquerda é válido?
            if(e != Tipo::boolean) {
                imprimirErroDeOperacao(tipo, Tipo::boolean, e, linha);

          // O tipo da direita é válido?
            } else if (d != Tipo::boolean) {
              imprimirErroDeOperacao(tipo, Tipo::boolean, d, linha);
            }

          // Retorna o tipo boolean
           retorno = Tipo::boolean;
           break;

  // Comparadores recebem "int" ou "float" e devolvem "bool"
         case Tipo::igual:
         case Tipo::diferente:
         case Tipo::maior:
         case Tipo::maior_igual:
         case Tipo::menor:
         case Tipo::menor_igual:

           // O tipo da esquerda é válido?
            if(e == Tipo::boolean) {
                imprimirErroDeOperacao(tipo, t, e, linha);

          // O tipo da direita é válido?
            } else if (d == Tipo::boolean) {
                imprimirErroDeOperacao(tipo, e, d, linha);
            }

          // Realiza-se coerção, se necessário
            coercao(this, e, d, linha);

          // Independente do retorno da coerção, retorna-se um valor booleano
            retorno = Tipo::boolean;
            break;

        default:
            retorno = Tipo::nulo;
            break;               
      }

    return retorno;
}


Tipo Condicao::verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) {
  // O teste de uma Condição deve ser Booleano
    Tipo esperado = teste->verificarTipo(tabelaSimbolos, t, operador, linha);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado, linha);
    }

  // Se o conteúdo do "se" ou "senão" não forem vazios, também devem ser verificados
    if(se != NULL)     se->verificarTipo(tabelaSimbolos, t, operador, linha);
    if(senao != NULL)  senao->verificarTipo(tabelaSimbolos, t, operador, linha);

  // A Condição não possui um Tipo a ser retornado
    return Tipo::nulo;
}


Tipo Laco::verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) {

  // O teste de um Laço deve ser Booleano
    Tipo esperado = teste->verificarTipo(tabelaSimbolos, t, operador, linha);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado, linha);
    }

  // Se o conteúdo do laço não for vazio, também deve ser verificado
    if(laco != NULL) laco->verificarTipo(tabelaSimbolos, t, operador, linha);

  // A Condição não possui um Tipo a ser retornado
    return Tipo::nulo;
}


//
//////////
// etc //

void Bloco::novaLinha(Nodo *linha) {
    linhas.push_back(linha);
}

void Definicao::ajustarProxima(Definicao *p) {
    if(proxima != NULL) {
        proxima->ajustarProxima(p);
    } else {
      proxima = p;
    }
}

bool Nodo::coercao(OperacaoBinaria *coagido, Tipo e, Tipo d, int linha) {

// Segundo a descrição da versão 0.3, apenas tipo int pode sofrer coerção para float, logo:

  // Se o tipo da esquerda for int e o da direita float, o da esquerda sofre coerção e retorna-se Tipo::real
    if (e == Tipo::inteiro && d == Tipo::real) {
      // Acrescenta-se um nodo com a operação de coerção entre o filho da esquerda e a operação binária
        OperacaoUnaria *coercao = new OperacaoUnaria(Tipo::opUnaria, Tipo::conversao_float, coagido->esquerda);
        coagido->esquerda = ((Nodo*) coercao);
        return true;
    }

  // Se o tipo da esquerda for float e o da direita int, o da direita sofre coerção e retorna-se Tipo::real
    else if (e == Tipo::real && d == Tipo::inteiro) {       
      // Acrescenta-se um nodo com a operação de coerção entre o filho da esquerda e a operação binária
        OperacaoUnaria *coercao = new OperacaoUnaria(Tipo::opUnaria, Tipo::conversao_float, coagido->direita);
        coagido->direita = ((Nodo*) coercao);
        return true;
    }

  // Se não ocorreu coerção, retorna-se false
    return false;  
}

void Nodo::imprimirEspaco(int espaco) {
    for(int i = 0; i < espaco; i++) {
        std::cout << " "; 
    }
}

void Nodo::imprimirTipo(Tipo t) {
  // One switch to rule them all
    switch(t) {
        case Tipo::inteiro:          std::cout << "int";       break;
        case Tipo::real:             std::cout << "float";     break;
        case Tipo::boolean:          std::cout << "bool";      break;

        case Tipo::atribuicao:       std::cout << "=";         break;
        case Tipo::adicao:           std::cout << "+";         break;
        case Tipo::subtracao:        std::cout << "-";         break;
        case Tipo::multiplicacao:    std::cout << "*";         break;
        case Tipo::divisao:          std::cout << "/";         break;
        case Tipo::e:                std::cout << "&";         break;
        case Tipo::ou:               std::cout << "|";         break;

        case Tipo::igual:            std::cout << "==";        break;
        case Tipo::diferente:        std::cout << "!=";        break;
        case Tipo::maior:            std::cout << ">";         break;
        case Tipo::maior_igual:      std::cout << ">=";        break;
        case Tipo::menor:            std::cout << "<";         break;
        case Tipo::menor_igual:      std::cout << "<=";        break;

        case Tipo::negacao:          std::cout << "-u ";       break;
        case Tipo::inversao:         std::cout << "! ";        break;
        case Tipo::conversao_int:    std::cout << "[int] ";    break;
        case Tipo::conversao_float:  std::cout << "[float] ";  break;
        case Tipo::conversao_bool:   std::cout << "[bool] ";   break;

        case Tipo::parenteses:       std::cout << "";          break;
        default:                     std::cout << "";          break;
    }
}

std::string Nodo::imprimirTipoPorExtenso(Tipo t) {
  // One switch to rule them all
    switch(t) {
        case Tipo::inteiro:          return "integer";         
        case Tipo::real:             return "float";           
        case Tipo::boolean:          return "bool";            
        case Tipo::atribuicao:       return "attribution";     
        case Tipo::adicao:           return "addition";        
        case Tipo::subtracao:        return "subtraction";     
        case Tipo::multiplicacao:    return "multiplication";  
        case Tipo::divisao:          return "division";        
        case Tipo::e:                return "and";             
        case Tipo::ou:               return "or";              
        case Tipo::negacao:          return "- ";        
        case Tipo::inversao:         return "! ";              
        case Tipo::igual:            return "==";              
        case Tipo::diferente:        return "!= ";             
        case Tipo::maior:            return "> ";              
        case Tipo::maior_igual:      return ">= ";             
        case Tipo::menor:            return "< ";              
        case Tipo::menor_igual:      return "<= ";             
        case Tipo::conversao_int:    return "[int] ";          
        case Tipo::conversao_float:  return "[float] ";        
        case Tipo::conversao_bool:   return "[bool] ";         
        case Tipo::parenteses:       return "()";
        case Tipo::teste:            return "test";              
        default:                     return " ";            
    }
}

void Nodo::imprimirErroDeOperacao(Tipo operacao, Tipo esperava, Tipo recebeu, int linha) {

  // Imprime num arquivo de erros. Temporário.
    std::ofstream arquivoDeErros("tests/erros.txt", std::ios::app); 
    arquivoDeErros << "[Line " << linha << "] semantic error:";
    arquivoDeErros << " operation " << imprimirTipoPorExtenso(operacao);
    arquivoDeErros << " expected " << imprimirTipoPorExtenso(esperava);
    arquivoDeErros << " but received " <<  imprimirTipoPorExtenso(recebeu);
    arquivoDeErros << "\n";              //exit(0);
    arquivoDeErros.close();
    
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

TabelaDeSimbolos* TabelaDeSimbolos::novoEscopo() {

    TabelaDeSimbolos *novoEscopo = new TabelaDeSimbolos(); 
    novoEscopo->anterior = this;
    novoEscopo->principal = false;
    return novoEscopo;
}


bool TabelaDeSimbolos::retornarEscopo() {

  // Se este for o último escopo, ele retorna <true>
    if(anterior == NULL) {
        return false;
    } 

  // Senão, ele pode remover o último escopo, caso ele retorne <true>
    else {

      // Isto só é viável pois cada Nodo::Bloco possui uma referência para a TabelDeSimbolos de seu escopo
        anterior = NULL;
        return true;
    }    
}


void TabelaDeSimbolos::adicionarVariavel(AST::Variavel *v, int linha) {
  // Se a variável não foi declarada, ela é adicionada ao map
    std::map<std::string, AST::Variavel*>::const_iterator it;
    it = variaveis.find(v->id);
    if (it == variaveis.end()) {
        variaveis.insert ( std::pair< std::string, AST::Variavel*> (v->id,v) );
  // Caso a variável já tenha sido declarada, ocorre um erro semântico
    } else {
        std::ofstream arquivoDeErros("tests/erros.txt", std::ios::app); 
        arquivoDeErros << "[Line " << linha << "] semantic error: re-declaration of variable " << v->id << "\n"; 
        arquivoDeErros.close(); 
    }
}

Variavel* TabelaDeSimbolos::recuperarVariavel(std::string id, int linha) {

  // Variável encontrada no escopo atual
    std::map<std::string, AST::Variavel*>::const_iterator it;
    it = variaveis.find(id);
    if (it != variaveis.end()) {
        return it->second;
    }

  // Variavel não encontrada, procurar no escopo anterior
    else if (anterior != NULL) {
        return anterior->recuperarVariavel(id, linha);
    }

  // Variável não encontrada em nenhum escopo
    else {
        std::ofstream arquivoDeErros("tests/erros.txt", std::ios::app); 
        arquivoDeErros << "[Line " << linha << "] semantic error: undeclared variable " << id << "\n"; 
        arquivoDeErros.close();       
        return NULL;
    }
}





