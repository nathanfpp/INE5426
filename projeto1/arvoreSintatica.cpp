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

void Variavel::imprimir() {
    std::cout << id << " ";
    return;
}

void Inteiro::imprimir() {
    std::cout << valor << " ";
    return;
}

void Real::imprimir() {
    std::cout << valor << " ";
    return;
}

void Boolean::imprimir() {
    std::cout << std::boolalpha << valor << " ";
    return;
}

void Nodo::imprimir() {

  // Switcheption
    switch(classe) {

      // Declarações imprimem tipo e à direita
        case ClasseDeNodo::declaracao:
            switch(tipo) {
                case TipoDeNodo::inteiro:  std::cout << "int ";    break;
                case TipoDeNodo::real:     std::cout << "float ";  break;
                case TipoDeNodo::boolean:  std::cout << "bool ";   break;          
                default:                   std::cout << "? ";      break;      
            }
            imprimirDireita();
            break;

      // Atribuições imprimem esquerda, "= " e direita, se não forem atômicas ("int a;")
        case ClasseDeNodo::atribuicao:
            imprimirEsquerda();
            if(tipo != TipoDeNodo::atomica){
                std::cout << "= ";
                imprimirDireita();
            }
            if(proximo != NULL) {
                std::cout << ", ";
                imprimirProximo();
            }
            break;

      // Operações Binárias imprimem direita e esquerda
        case ClasseDeNodo::operacaoBinaria:
            imprimirEsquerda();
            switch(tipo) {
                case TipoDeNodo::adicao:         std::cout << "+ ";   break;
                case TipoDeNodo::subtracao:      std::cout << "- ";   break;
                case TipoDeNodo::multiplicacao:  std::cout << "* ";   break;
                case TipoDeNodo::divisao:        std::cout << "/ ";   break; 
                case TipoDeNodo::igual:          std::cout << "== ";  break;
                case TipoDeNodo::e:              std::cout << "& ";   break; 
                case TipoDeNodo::ou:             std::cout << "| ";   break;
                case TipoDeNodo::diferente:      std::cout << "!= ";  break;
                case TipoDeNodo::maior:          std::cout << "> ";   break;
                case TipoDeNodo::maior_igual:    std::cout << ">= ";  break;
                case TipoDeNodo::menor:          std::cout << "< ";   break;                 
                case TipoDeNodo::menor_igual:    std::cout << "<= ";  break;                 
                default:                         std::cout << "? ";   break;  
            }
            imprimirDireita();
            break;

      // Operações Unárias imprimem direita
        case ClasseDeNodo::operacaoUnaria:
            switch(tipo){
                case TipoDeNodo::negacao:          std::cout << "- ";        break;
                case TipoDeNodo::inversao:         std::cout << "! ";        break;
                case TipoDeNodo::parenteses:       std::cout << "( ";        break;
                case TipoDeNodo::conversao_int:    std::cout << "[int] ";    break;
                case TipoDeNodo::conversao_float:  std::cout << "[float] ";  break;
                case TipoDeNodo::conversao_bool:   std::cout << "[bool] ";   break;
                default:                           std::cout << "? ";        break;
           }
           imprimirDireita();
           if(tipo == TipoDeNodo::parenteses) {
               std::cout << ")";
           }
           break;
    }
    return;
}

void Bloco::imprimir(){
    for (NodoBase* linha: linhas) {
        linha->imprimir();
        std::cout << std::endl;
    }
}

//////////////////////
// adicionarTipo() //

void Variavel::adicionarTipo(TipoDeNodo t) {
    if(tipo == semTipo) {
        tipo = t;
    }
    //else: nesse caso se o tipo já tiver sido atribuído cairá no erro de declaração duplicada preservando a variável original.
    return;  
}

//Verificar Tipo Raiz: compara variável a esquerda com nodo raiz.

void Nodo::verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){

    if(esquerda != direita){
        std::cout << "expected ";      imprimirTipo(esquerda);
        std::cout << "but received ";  imprimirTipo(direita);
        std::cout << "\n";             exit(0);

	}
}		


// Verificar Tipo //

TipoDeNodo Variavel::verificarTipo(TipoDeNodo t, TipoDeNodo operador) {
    return tipo;   
}

TipoDeNodo Inteiro::verificarTipo(TipoDeNodo t, TipoDeNodo operador) {
    return tipo;
}

TipoDeNodo Real::verificarTipo(TipoDeNodo t, TipoDeNodo operador) {
    return tipo;
}

TipoDeNodo Boolean::verificarTipo(TipoDeNodo t, TipoDeNodo operador) {
    return tipo;
}

TipoDeNodo Nodo::verificarTipo(TipoDeNodo t, TipoDeNodo operador) {

    std::cout << "-> ";
    imprimirTipo(tipo);
    std::cout << "\n";
  
  // Caso exista um próxima, verifica-o antes:
    if(proximo != NULL)   proximo->verificarTipo(t, tipo);

  // Se filho da esquerda != NULL, trata-se de uma Operação Binária 
    if(esquerda != NULL) {

  // Captura 
    TipoDeNodo e = esquerda->verificarTipo(t, tipo);  TipoDeNodo d = direita->verificarTipo(t, tipo);

  // Big switch for all cases
    switch(tipo) {

      // Operaçãos Aritméticas recebem "int" ou "float" e devolvem "int" ou "float"
        case TipoDeNodo::adicao:
        case TipoDeNodo::subtracao:
        case TipoDeNodo::multiplicacao:
        case TipoDeNodo::divisao:

         // O tipo da esquerda é inválido?
            if(e == TipoDeNodo::boolean) {
                std::cout << "operation ";     imprimirTipo(tipo);
                std::cout << "expected ";      imprimirTipo(t);
                std::cout << "but received ";  imprimirTipo(e);
                std::cout << "\n";             exit(0);

          // O tipo da direita é inválido?
            } else if (d == TipoDeNodo::boolean) {
                std::cout << "operation ";     imprimirTipo(tipo);
                std::cout << "expected ";      imprimirTipo(e);
                std::cout << "but received ";  imprimirTipo(d);
                std::cout << "\n";             exit(0);
            }
            if (e == TipoDeNodo::real || d == TipoDeNodo::real){
               return TipoDeNodo::real;
            }
            return TipoDeNodo::inteiro;

       // Operações Lógicas recebem "bool" e devolvem "bool"
         case TipoDeNodo::e:
         case TipoDeNodo::ou:

          // O tipo da esquerda é válido?
            if(e != TipoDeNodo::boolean) {
                std::cout << "operation ";     imprimirTipo(tipo);
                std::cout << "expected "       << "bool ";
                std::cout << "but received ";  imprimirTipo(e);
                std::cout << "\n";             exit(0);

          // O tipo da direita é inválido?
            } else if (d != TipoDeNodo::boolean) {
              std::cout << "operation ";     imprimirTipo(tipo);
              std::cout << "expected "       << "bool ";
              std::cout << "but received ";  imprimirTipo(d);
              std::cout << "\n";             exit(0);
            }

          // Retorna o tipo boolean
           return TipoDeNodo::boolean;

       // Comparadores recebem "int" ou "float" e devolvem "bool"
         case TipoDeNodo::igual:
         case TipoDeNodo::diferente:
         case TipoDeNodo::maior:
         case TipoDeNodo::maior_igual:
         case TipoDeNodo::menor:
         case TipoDeNodo::menor_igual:

           // O tipo da esquerda é válido?
            if(e == TipoDeNodo::boolean) {
                std::cout << "operation ";     imprimirTipo(tipo);
                std::cout << "expected ";      imprimirTipo(t);
                std::cout << "but received ";  imprimirTipo(e);
                std::cout << "\n";             exit(0);

          // O tipo da direita é válido?
            } else if (d == TipoDeNodo::boolean) {
                std::cout << "operation ";     imprimirTipo(tipo);
                std::cout << "expected ";      imprimirTipo(e);
                std::cout << "but received ";  imprimirTipo(d);
                std::cout << "\n";             exit(0);
            }

          // Retorna o tipo boolean
            return TipoDeNodo::boolean;

        default: return TipoDeNodo::x;               
      }

  // Caso não haja filho da esquerda, trata-se de uma Operação Unária
    } else {

      // Captura tipo do único filho
        TipoDeNodo d = direita->verificarTipo(t, tipo);

      //
        switch(tipo) {

         // Operação de Negação recebe um "int" ou "float" e devolve "int" ou "float"
            case TipoDeNodo::negacao:
                if(d == TipoDeNodo::boolean) {
                    std::cout << "operation ";     imprimirTipo(tipo);
                    std::cout << "expected ";      imprimirTipo(t);
                    std::cout << "but received ";  imprimirTipo(d);
                    std::cout << "\n";             exit(0);
                }
            return d;

       // Operação "Inversão", ou Negação Lógica recebe "bool" e devolve "bool"
            case TipoDeNodo::inversao:
                if( d != TipoDeNodo::boolean) {
                    std::cout << "operation ";     imprimirTipo(tipo);
                    std::cout << "expected ";      imprimirTipo(t);
                    std::cout << "but received ";  imprimirTipo(d);
                    std::cout << "\n";             exit(0);
                }              
            return TipoDeNodo::boolean;

      // Conversao de float ou bool para int
        case TipoDeNodo::conversao_int:
            return TipoDeNodo::inteiro;
            break;

      // Conversao de int ou float para int
        case TipoDeNodo::conversao_float:
            return TipoDeNodo::real;
            break;

      // Conversao de int ou float para bool
        case TipoDeNodo::conversao_bool:
            return TipoDeNodo::boolean;
            break;

      // Parênteses apenas retornam o tipo contido
            case TipoDeNodo::parenteses:
                std::cout << "(parenteses)\n";
                return d;

        default: return TipoDeNodo::x;
      }
    }
}

//////////////////////////
// verificarSimbolos() //

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

void Nodo::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
    if(esquerda != NULL)  esquerda->verificarSimbolos(tabela_simbolos);
    if(direita != NULL)   direita->verificarSimbolos(tabela_simbolos);  
    if(proximo != NULL)   proximo->verificarSimbolos(tabela_simbolos);
    return;    
}

////////////////////////////
// acrescentarSimbolos() //

void Variavel::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos,  AST::TipoDeNodo ultimoTipo) {
    std::map<std::string, AST::Variavel*>::iterator it;
    it = tabela_simbolos.find(id);
    if (it != tabela_simbolos.end()) {
        std::cout << "semantic error: re-declaration of variable " << id << "\n";
    } else {
        //std::cout << "semantic ok: declaration of variable " << id << "\n";
	adicionarTipo(ultimoTipo);
        tabela_simbolos[std::string(id)] = this;
    }
}

void Nodo::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {
    if(esquerda != NULL)  esquerda->acrescentarSimbolos(tabela_simbolos,ultimoTipo);
    if(direita != NULL)   direita->acrescentarSimbolos(tabela_simbolos, ultimoTipo);  
    if(proximo != NULL)   proximo->acrescentarSimbolos(tabela_simbolos, ultimoTipo);
    return;
}

//////////
// etc //

void Nodo::imprimirEsquerda() {
    if(esquerda != NULL) {
        esquerda->imprimir();
    }
}

void Nodo::imprimirDireita() {
    if(direita != NULL) {
        direita->imprimir();
    }
}

void Nodo::imprimirProximo() {
    if(proximo != NULL) {
        proximo->imprimir();
    }
}

void Bloco::novaLinha(NodoBase *linha) {
    linhas.push_back(linha);
}

void NodoBase::imprimirTipo(TipoDeNodo t){
  // One switch to rule them all
    switch(t) {
        case TipoDeNodo::inteiro:          std::cout << "integer ";  break;
        case TipoDeNodo::real:             std::cout << "float ";    break;
        case TipoDeNodo::boolean:          std::cout << "bool ";     break;
        case TipoDeNodo::adicao:           std::cout << " ";         break;
        case TipoDeNodo::subtracao:        std::cout << "- ";        break;
        case TipoDeNodo::multiplicacao:    std::cout << "* ";        break;
        case TipoDeNodo::divisao:          std::cout << "/ ";        break;
        case TipoDeNodo::e:                std::cout << "& ";        break;
        case TipoDeNodo::ou:               std::cout << "| ";        break;
        case TipoDeNodo::negacao:          std::cout << "- ";        break;
        case TipoDeNodo::inversao:         std::cout << "! ";        break;
        case TipoDeNodo::igual:            std::cout << "== ";       break;
        case TipoDeNodo::diferente:        std::cout << "!= ";       break;
        case TipoDeNodo::maior:            std::cout << "> ";        break;
        case TipoDeNodo::maior_igual:      std::cout << ">= ";       break;
        case TipoDeNodo::menor:            std::cout << "< ";        break;
        case TipoDeNodo::menor_igual:      std::cout << "<= ";       break;
        case TipoDeNodo::conversao_int:    std::cout << "[int] ";    break;
        case TipoDeNodo::conversao_float:  std::cout << "[float] ";  break;
        case TipoDeNodo::conversao_bool:   std::cout << "[bool] ";   break;

        case TipoDeNodo::atomica:    std::cout << " "; break;
        case TipoDeNodo::parenteses: std::cout << "() "; break;

        default:                          std::cout << "? ";       break;

    }
}

/*

inteiro, real, boolean, atomica, adicao, subtracao, multiplicacao, divisao, e, ou, negacao, inversao, 
                      igual, diferente, maior, maior_igual, menor, menor_igual, parenteses, 
                      conversao_int, conversao_float, conversao_bool, x, semTipo
*/
