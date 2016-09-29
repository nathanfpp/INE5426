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


//////////////
// Variavel//

Tipo Variavel::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Busca a variável na tabela de símbolos e retorna o tipo da variável, caso ele seja encontrado
    Variavel *v = tabelaSimbolos->recuperarVariavel(id, linha);
    if(v != NULL) {
        return v->tipo;
    }

  // Caso contrário retorna o tipo do Nodo::Variável
    return tipo;
}


/////////////////
// Declaracao //

Tipo Declaracao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Atribui o tipoDeVariavel da Declaração à primeira variável da declaração
    variaveis->tipoDeVariavel = tipoDeVariavel;

  // Inicia a análise das variáveis declaradas
    variaveis->analisar(tabelaSimbolos, linha);

    return tipo;
}

void Declaracao::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    imprimirTipo(tipoDeVariavel);
    std::cout << " var: ";
    if(variaveis != NULL) {
        variaveis->imprimir(0, false);
    }
    std::cout << "\n";
}


////////////////
// Definicao //

Tipo Definicao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Atribui tipoDeVariavel, recebido da Declaração, à Variável
    variavel->tipo = tipoDeVariavel;

  // Salva a Variável na Tabela de Símbolos
    tabelaSimbolos->adicionarVariavel(variavel, linha);

  // Verifica se a Variável foi realmente adiciona à Tabela de Símbolos
   // variavel->analisar(tabelaSimbolos, linha);

  // Caso a Definição atribua um valor à Variável, realizando coerção se necessário
    if(valor != NULL) {
        valor->analisar(tabelaSimbolos, linha); // anteriormente após a coerção
        coercaoDaDefinicao(this, tipoDeVariavel, valor->tipo, linha);        
    }

  // Se outra Variável foi declarada, atribui o tipo da Declaração e inicia sua análise 
    if(proxima != NULL) {
        proxima->tipoDeVariavel = tipoDeVariavel;
        proxima->analisar(tabelaSimbolos, linha);
    }

   return tipo;
}


void Definicao::imprimir(int espaco, bool novaLinha) {
    variavel->imprimir(0, false);

    if(valor != NULL) {
        std::cout << " = ";
        valor->imprimir(0, false);
    }

    if(proxima != NULL) {
        std::cout << ", ";        
        proxima->imprimir(0, false);
    }

    if(novaLinha) std::cout << "\n";
}

void Definicao::ajustarProxima(Definicao *p) {
    if(proxima != NULL) {
        proxima->ajustarProxima(p);
    } else {
      proxima = p;
    }
}


/////////////////////
// OperacaoUnaria //

Tipo OperacaoUnaria::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {
 
  // Captura o tipo do filho
    Tipo d = filho->analisar(tabelaSimbolos, linha);

  // Operações Unárias possuem tratamento diferenciado
    switch(operacao) {

      // Operação de Negação recebe um "int" ou "float" e devolve "int" ou "float"
        case Tipo::negacao:
            if(d == Tipo::boolean) {
                imprimirErroDeOperacao(tipo, Tipo::inteiro, d, linha);
            }
            return d;

      // Operação Inversão (Negação Lógica) recebe "bool" e devolve "bool"
        case Tipo::inversao:
            if( d != Tipo::boolean) {
                imprimirErroDeOperacao(tipo, Tipo::boolean, d, linha);
            }              
            return Tipo::boolean;

      // Conversões retornam o tipo convertido, independente da entrada
        case Tipo::conversao_int:    return Tipo::inteiro;
        case Tipo::conversao_float:  return Tipo::real;   
        case Tipo::conversao_bool:   return Tipo::boolean;

      // Parênteses apenas retornam o tipo contido
        case Tipo::parenteses:  return d;

        default:  return Tipo::nulo;
    }
}

void OperacaoUnaria::imprimir(int espaco, bool novaLinha) {
    imprimirTipo(operacao);
    filho->imprimir(0, false);
}


//////////////////////
// OperacaoBinaria //

Tipo OperacaoBinaria::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {  

  // Captura os tipos dos filhos esquerda e direita
    Tipo e = esquerda->analisar(tabelaSimbolos, linha);
    Tipo d = direita->analisar(tabelaSimbolos, linha);

  // Operações Binárias possuem comportamentos diferentes
    switch(operacao) {

  // A Atribuição recebe "int","float" ou "bool" e retorna "int", "float" ou "bool"
        case Tipo::atribuicao: 
            coercao(this, e, d, linha);
            return e;

  // Operaçãos Aritméticas recebem "int" ou "float" e devolvem "int" ou "float"
        case Tipo::adicao:
        case Tipo::subtracao:
        case Tipo::multiplicacao:
        case Tipo::divisao:
            
         // O tipo da esquerda é inválido?
            if(e == Tipo::boolean) {
                imprimirErroDeOperacao(operacao, Tipo::inteiro, e, linha);
            }
          // O tipo da direita é inválido?
            else if (d == Tipo::boolean) {
                imprimirErroDeOperacao(operacao, e, d, linha);
            }
   
          // A coerção de tipos é necessária?
            if(coercao(this, e, d, linha)) {

              // Se a coerção ocorre, é garantido que a operação binária retorna um tipo float
                return Tipo::real;
            } 

          // Caso não ocorra coerção, os tipos da esquerda e direita são iguais
            return e;
            

  // Operações Lógicas recebem "bool" e devolvem "bool"
         case Tipo::e:
         case Tipo::ou:
          // O tipo da esquerda é válido?
            if(e != Tipo::boolean) { std::cout<<" ("<<e<<") ";
                imprimirErroDeOperacao(operacao, Tipo::boolean, e, linha);
            }

          // O tipo da direita é válido?
             else if (d != Tipo::boolean) { std::cout<<" (d) ";
              imprimirErroDeOperacao(operacao, Tipo::boolean, d, linha);
            }

          // Retorna o tipo boolean
           return Tipo::boolean;
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
                imprimirErroDeOperacao(operacao, Tipo::inteiro, e, linha);
            }

            // O tipo da direita é válido?
            else if (d == Tipo::boolean) {
                imprimirErroDeOperacao(operacao, e, d, linha);
            }

          // Realiza-se coerção, se necessário
            coercao(this, e, d, linha);

          // Independente do retorno da coerção, retorna-se um valor booleano
            return Tipo::boolean;
            break;

        default:
            return Tipo::nulo;
            break;               
      }
}

void OperacaoBinaria::imprimir(int espaco, bool novaLinha) {  
    imprimirEspaco(espaco);
    imprimirTipo(operacao);
    std::cout << " ";
    esquerda->imprimir(0, false);
    std::cout << " ";
    direita->imprimir(0, false);
    if(novaLinha) std::cout << "\n";
}


///////////////
// Condicao //

Tipo Condicao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // O teste de uma Condição deve ser Booleano
    Tipo esperado = teste->analisar(tabelaSimbolos, linha);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado, linha);
    }

  // Se o conteúdo do "se" ou "senão" não forem vazios, também devem ser verificados
    if(se != NULL) {
        se->analisar(tabelaSimbolos, linha);
    }

    if(senao != NULL) {
        senao->analisar(tabelaSimbolos, linha);
    }

    return Tipo::nulo;
}

void Condicao::imprimir(int espaco, bool novaLinha) {

    imprimirEspaco(espaco);
    std::cout << "if: ";
  // O teste de uma Condição deve ser Booleano
    teste->imprimir(0, false);

  // Se o conteúdo do "se" ou "senão" não forem vazios, também devem ser verificados
    if(se != NULL) {
        std::cout << "\n";
        imprimirEspaco(espaco);
        std::cout << "then:\n";
        se->imprimir(espaco+2, false);
    }

    if(senao != NULL) {        
        imprimirEspaco(espaco);
        std::cout << "else:\n";
        senao->imprimir(espaco+2, false);
    }

  // A Condição não possui um Tipo a ser retornado
    if(se == NULL && senao == NULL) std::cout << "\n";
}


///////////
// Laco //

Tipo Laco::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Analisa-se a inicialização do Laço, caso ela exista
    if(inicializacao != NULL) {
        inicializacao->analisar(tabelaSimbolos, linha);
    }

  // O teste de um Laço deve ser Booleano
    Tipo esperado = teste->analisar(tabelaSimbolos, linha);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado, linha);
    }
    if(iteracao != NULL) {
        iteracao->analisar(tabelaSimbolos, linha);
    }

  // Se o conteúdo do laço não for vazio, também deve ser verificado
    if(laco != NULL) {
        laco->analisar(tabelaSimbolos, linha);
    }

  // A Condição não possui um Tipo a ser retornado
    return tipo;
}

void Laco::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    std::cout << "for: ";
    if(inicializacao != NULL) {
        inicializacao->imprimir(0, false);
    }
    std::cout << ", ";   
    teste->imprimir(0, false);
    std::cout << ", ";
    if(iteracao != NULL) {
        iteracao->imprimir(0, false);
    }
    std::cout << "\n";
    imprimirEspaco(espaco);
    std::cout << "do:";
    if(laco != NULL) {
        std::cout << "\n";
        laco->imprimir(espaco+2, true);
    } else {
        std::cout << "\n";
    }
}


/////////////
// Funcao //

Tipo Funcao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

 // Declaração de Nova Função
    if(tipo == Tipo::funcao_dec) {

      // Define a quantidade de parâmetros: se não houver parâmetros a quantidade é 0
        if(parametros == NULL) {
             quantidadeDeParametros = 0;
        } else {
             quantidadeDeParametros = parametros->contar(); 
        }
      // Adiciona-se a função à tabela de funções
        tabelaSimbolos->declararFuncao(this, linha);
    } 

 // Definição ou Chamada de Função
    else {

      // Recupera a Função, caso contrário um erro semântico é lançado pela Tabela de Símbolos
        Funcao *f = tabelaSimbolos->recuperarFuncao(id, linha);
        if(f != NULL) {

          // Compara os parâmetros
            ;
        }

      // Definições de Função sobrescrevem a Tabela de Símbolos
        if(tipo == Tipo::funcao_def){
            tabelaSimbolos->definirFuncao(this, linha);
        }
    }
    return tipo;
}

void Funcao::imprimir(int espaco, bool novaLinha) {
/*
    imprimirTipo(retorno);
    std::cout << " fun: " << id << " (params: ";
    parametros->imprimir(tabelaSimbolos, 0, linha, false);
    std::cout << ")\n";
    corpo->imprimir(tabelaSimbolos, espaco+2, linha, true);
*/
}


////////////////
// Parametro //

void Parametro::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    imprimirTipo(tipo);
    std::cout << " " << id;
    if(proximo != NULL) {
       std::cout << ", ";
       proximo->imprimir(espaco, novaLinha);
    }
}

bool Parametro::comparar(Parametro *comparado) {

  // Se o parâmetro comparado for nulo, os Parâmetros são diferentes
    if(comparado != NULL) {

      // Se o Parâmetro atual for diferente do Parâmetro comparado, os Parâmetros são diferentes 
        if(tipo == comparado->tipo) {

          // Se os parâmetros atuais forem igual e os próximos forem nulos, então todos os Parâmetro são iguais
            if(proximo == NULL && comparado->proximo == NULL) {
                return true;
            }             
        }
    }
    return false; 
}

int Parametro::contar() {
    if(proximo == NULL) {
        return 1;
    } else {
        return (proximo->contar() + 1);
    }    
}


//////////////
// Arranjo //

Tipo Arranjo::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {
    if(false){
        std::cout << " array: " << id << " (size: ";
        tamanho->analisar(tabelaSimbolos, linha);
        std::cout << ")";
    } else {
        std::cout << "[index] "<< id;
    }

// O tipo usado como índice é válido?
    Tipo indice = tamanho->analisar(tabelaSimbolos, linha);
    if(indice != Tipo::inteiro) {
        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received " << indice << "\n"; 
    }

  // Atribui tipo à Variável
   
  // Adiciona o arranjo à tabela de símbolos
    //tabelaSimbolos->adicionarVariavel(this, linha);
  
   return Tipo::arranjo;
}

void Arranjo::imprimir(int espaco, bool novaLinha) {
    
}


////////////
// Bloco //

Tipo Bloco::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

// Se a tabela de símbolos recebida for a principal, o Bloco é o principal
  if(linha == 0) {
      escopo = tabelaSimbolos;
  } else {
      escopo = new TabelaDeSimbolos(tabelaSimbolos->count); 
      escopo->anterior = tabelaSimbolos;
  }

  // Verificar os Tipos de todas as linhas do Bloco   
    for (Nodo* l: linhas) {
        if(l != NULL) {
            linha++;
            l->analisar(escopo, linha);
        }
    }

  // Desempilha-se este escopo, removendo seu endereçamento da tabela de símbolos ...
  // ... sendo o ponteiro para o escopo guardado apenas no Nodo::Bloco
    escopo->retornarEscopo();

  // O Bloco não possui um Tipo a ser retornado
    return Tipo::nulo;
}

void Bloco::imprimir(int espaco, bool novaLinha) {
    for (Nodo* l: linhas) {
        if(l != NULL) {
            l->imprimir(espaco, true);
        }
    }
}

void Bloco::novaLinha(Nodo *linha) {
    linhas.push_back(linha);
}


///////////
// Nodo //

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

    std::cerr << "[Line " << linha << "] semantic error:";
    std::cerr << " operation " << imprimirTipoPorExtenso(operacao);
    std::cerr << " expected " << imprimirTipoPorExtenso(esperava);
    std::cerr << " but received " <<  imprimirTipoPorExtenso(recebeu);
    std::cerr << "\n";

}

///////////////////////
// TabelaDeSimbolos //

TabelaDeSimbolos* TabelaDeSimbolos::novoEscopo(int c) {
    TabelaDeSimbolos *novoEscopo = new TabelaDeSimbolos(c); 
    novoEscopo->anterior = this;
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
        std::cerr << "[Line " << linha << "] semantic error: re-declaration of variable " << v->id << "\n"; 
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
        std::cerr << "[Line " << linha << "] semantic error: undeclared variable " << id << "\n";
        return NULL;
    }
}

void TabelaDeSimbolos::declararFuncao(AST::Funcao *f, int linha) {

  // Se a Função não foi declarada, ela é adicionada ao map
    std::map<std::string, AST::Funcao*>::const_iterator it;
    it = funcoes.find(f->id);
    if (it == funcoes.end()) {
        funcoes.insert ( std::pair< std::string, AST::Funcao*> (f->id,f) );
    }

  // Caso a Função já tenha sido declarada, ocorre um erro semântico
    else {
        std::cerr << "[Line " << linha << "] semantic error: re-declaration of function " << f->id << "\n"; 
    }
}


bool TabelaDeSimbolos::definirFuncao(AST::Funcao *f, int linha) {

  // Prepara o iterator para a busca
    std::map<std::string, AST::Funcao*>::const_iterator it;
    it = funcoes.find(f->id);

  // Se a função não for encontrada na tabela de símbolos atual...
    if (it == funcoes.end()) {

      // Procura-se em tabelas anteriores, se elas existirem
        if(anterior != NULL) {
            anterior->definirFuncao(f,linha);
        }

      // Caso contrário, a função não foi declarada 
        else {
            std::cerr << "[Line " << linha << "] semantic error: undeclared function " << f->id << "\n";
        }
    }

  // Caso a Função já tenha sido declarada, verifica-se se já foi definida
    else {
        std::cerr << "[Line " << linha << "] semantic error: re-declaration of function " << f->id << "\n"; 
    }

    return true;
}


Funcao* TabelaDeSimbolos::recuperarFuncao(std::string id, int linha) {

  // Variável encontrada no escopo atual
    std::map<std::string, AST::Funcao*>::const_iterator it;
    it = funcoes.find(id);

    if (it != funcoes.end()) {
        return it->second;
    }

  // Variavel não encontrada, procurar no escopo anterior
    else if (anterior != NULL) {
        return anterior->recuperarFuncao(id, linha);
    }

  // Variável não encontrada em nenhum escopo
    else {
        std::cerr << "[Line " << linha << "] semantic error: undeclared function " << id << "\n";
        return NULL;
    }
}

