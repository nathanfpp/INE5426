#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Parametro::analisar(TabelaDeSimbolos *tabelaDeSimbolos, int linha) {

  // Tipos de paraâmetros diferentes possuem tratamento diferenciado
    if(parametro != NULL) {
        switch(parametro->tipo) {
            case Tipo::variavel:
                ((Variavel*)parametro)->tipoDeVariavel = tipoDoParametro; 
                break;
            case Tipo::hash:
                ((Hash*)parametro)->tipoDeVariavel = tipoDoParametro; 
                ((Hash*)parametro)->tipoDeChave = tipoReserva;
                break;
	   default: break;

        }
    }

  // Analisa o próximo parâmetro, caso ele exista
    if(proximo != NULL) {
        proximo->analisar(tabelaDeSimbolos, linha);
    }

  // Retorna o tipo
    return tipoDoParametro;
}


void Parametro::imprimir(int espaco, bool naoArgumento) {
    imprimirEspaco(espaco);
    if(naoArgumento) {

	if (parametro->tipo == hash){
	Tipo tipoHashImpressao = Tipo::nulo;
	 switch(tipoReserva) {
        case Tipo::boolean:
            switch(tipoDoParametro) {
                case Tipo::boolean: tipoHashImpressao = Tipo::hash_bb; break;
                case Tipo::inteiro: tipoHashImpressao = Tipo::hash_bi; break;
                case Tipo::real:    tipoHashImpressao = Tipo::hash_bf; break;
                default: break;
            } break;
        case AST::Tipo::inteiro:
            switch(tipoDoParametro) {
                case Tipo::boolean: tipoHashImpressao = Tipo::hash_ib; break;
                case Tipo::inteiro: tipoHashImpressao = Tipo::hash_ii; break;
                case Tipo::real:    tipoHashImpressao = Tipo::hash_if; break;
                default: break;
            } break;
        case AST::Tipo::real:
            switch(tipoDoParametro) {
                case Tipo::boolean: tipoHashImpressao = Tipo::hash_fb; break;
                case Tipo::inteiro: tipoHashImpressao = Tipo::hash_fi; break;
                case Tipo::real:    tipoHashImpressao = Tipo::hash_ff; break;
                default: break;
            } break;
        default: break;
    }
	
        imprimirTipo(tipoHashImpressao);

    }
	else
        imprimirTipo(tipoDoParametro);
    }
    std::cout << " ";
    parametro->imprimir(0,false);
    if(proximo != NULL) {
       if(naoArgumento) {
           std::cout << ", ";
       }
       proximo->imprimir(espaco, naoArgumento);
    }
}


void Parametro::comparar(TabelaDeSimbolos *tabelaDeSimbolos, Parametro *comparado, int linha, bool definicao) {

  // Se o tipoReserva não for nulo, ele representa a chave do parâmetro de HASH //
    if(tipoReserva != Tipo::nulo) {

      // Coleta os tipos dos parâmetros
        Tipo tipoChave = Tipo::nulo, tipoValor = Tipo::nulo;

      // Definição de Função acrescenta os parâmetros à tabela de símbolos
        if(definicao) {
            tipoValor = comparado->tipoDoParametro;
            tipoChave = comparado->tipoReserva;
            tabelaDeSimbolos->adicionar(parametro, linha, true);
        }

      // Chamada de Função consulta a tabela de símbolos para extrair a variável 
       else {
	    //Recupera nodo se for variavel
	    if(comparado->parametro->tipo == Tipo::hash) {
            Nodo *n = tabelaDeSimbolos->recuperar(comparado->parametro->id, linha, true);
	    if (n != NULL && n->tipo == Tipo::hash){//é uma variavel
            	tipoValor = ((Variavel*)n)->tipoDeVariavel;
	        tipoChave = ((Hash*)n)->tipoDeChave;
	    	}
	    }
	    else{ //Parametro recebido é alguma coisa qualquer, menos um hash
		tipoValor = comparado->parametro->analisar(tabelaDeSimbolos, linha);
		std::cerr <<"[Line " << linha << "]"<<" semantic error: expected hash "<<imprimirTipoPorExtenso(tipoReserva)<<":";
		std::cerr <<imprimirTipoPorExtenso(tipoDoParametro);	
                std::cerr << " but received " << imprimirTipoPorExtenso(tipoValor) << "\n";              			
		return;
	    }
        }
	
	
      // Compara as Chaves dos Hashes
       if(tipoChave == tipoReserva) {
    
          // Compara os Valores do Hashes
            if(tipoValor == tipoDoParametro) {

              // Caso se trate de um parâmetro, não um argumento de uma chamada de função...
                if(definicao) {
                  // Captura-se os nomes dos parâmetros
                    std::string nomeEsperado = ((Variavel*) parametro)->id;
                    std::string nomeRecebido = ((Variavel*) comparado->parametro)->id;

                  // Compara-se os nomes dos parâmetros, se forem diferentes um erro é emitido
                    if(nomeEsperado.compare(nomeRecebido) != 0) {
                        std::string id = ((Variavel*) parametro)->id;
                        std::cerr << "[Line " << linha << "] semantic error: hash parameter " << nomeEsperado;
                        std::cerr << " expected to be called " << nomeEsperado << " but was named " << nomeRecebido << "\n"; 
                    }
                }            
            }
          // Se os Valores forem de tipos diferentes
            else {              
                std::cerr << "[Line " << linha << "] semantic error: hash parameter " << parametro->id;
                std::cerr << " expected value of type " << imprimirTipoPorExtenso(tipoDoParametro);
                std::cerr << " but received " << imprimirTipoPorExtenso(tipoValor) << "\n";              
            }
        }
       // Se as Chaves forem de tipos diferentes
        else {
            std::cerr << "[Line " << linha << "] semantic error: hash parameter " << parametro->id;
            std::cerr << " expected key of type " << imprimirTipoPorExtenso(tipoReserva);
            std::cerr << " but received " << imprimirTipoPorExtenso(tipoChave) << "\n";              
        }    
    }


// Variáveis Simples
    else {

      // Coleta os tipos dos parâmetros
        Tipo tipoComparado = Tipo::nulo;

      // Definição de Função acrescenta os parâmetros à tabela de símbolos
        if(definicao) {
            tipoComparado = comparado->tipoDoParametro;
            tabelaDeSimbolos->adicionar(parametro,linha, true);
        }

      // Chamada de Função analisa o parâmetro 
        else {
            // Nodo *n = tabelaDeSimbolos->recuperar(comparado->parametro->id, linha, true);
            tipoComparado = comparado->parametro->analisar(tabelaDeSimbolos, linha);
        } 

      // Ajusta o tipoDoParametro caso se trate de um arranjo ou arrranjo duplo
        if(parametro->tipo == Tipo::arranjo) {
            tipoDoParametro = tabelaDeSimbolos->tipoDeArranjo(((Variavel*)parametro)->tipoDeVariavel);
        } else if (parametro->tipo == Tipo::arranjo_duplo) {
            tipoDoParametro = tabelaDeSimbolos->tipoDeArranjoDuplo(((Variavel*)parametro)->tipoDeVariavel);
        }

      // Se os parâmetros forem do mesmo tipo
        if(tipoDoParametro == tipoComparado) {
    
          // Caso se trate de um parâmetro, não um argumento de uma chamada de função...
            if(definicao) {

              // Captura-se os nomes dos parâmetros
                std::string nomeEsperado = ((Variavel*) parametro)->id;
                std::string nomeRecebido = ((Variavel*) comparado->parametro)->id;

              // Compara-se os nomes dos parâmetros, se forem diferentes um erro é emitido
                if(nomeEsperado.compare(nomeRecebido) != 0) {
                    std::string id = ((Variavel*) parametro)->id;
                    std::cerr << "[Line " << linha << "] semantic error: parameter " << nomeEsperado;
                    std::cerr << " expected to be called " << nomeEsperado << " but was named " << nomeRecebido << "\n"; 
                }
            }            
        }

      // Se o Parâmetro atual for diferente do Parâmetro comparado, erro 
        else {
            std::string id = ((Variavel*) parametro)->id;
            std::cerr << "[Line " << linha << "] semantic error: parameter " << id;
            std::cerr << " expected " << imprimirTipoPorExtenso(tipoDoParametro);
            std::cerr << " but received " << imprimirTipoPorExtenso(tipoComparado) << "\n";              
        }   
    }


  // Se os parâmetros atuais forem igual e os próximos forem nulos, então todos os Parâmetro são iguais
    if(proximo != NULL && comparado->proximo != NULL) {           
      // Caso contrário, compara os próximos parâmetros
        ((Parametro*)proximo)->comparar(tabelaDeSimbolos, ((Parametro*)comparado->proximo), linha, definicao);
    }
}


void Parametro::acrescentarAoEscopo(TabelaDeSimbolos *tabelaDeSimbolos, int linha) {
    if(parametro != NULL) {
      ((Variavel*)parametro)->tipoDeVariavel = tipoDoParametro; 
        if(parametro->tipo == Tipo::hash) {
            ((Hash*)parametro)->tipoDeChave = tipoReserva;
        }
    }
    tabelaDeSimbolos->adicionar(parametro, linha, variavel);
    if(proximo != NULL) {
        return ((Parametro*)proximo)->acrescentarAoEscopo(tabelaDeSimbolos, linha);
    }
}


int Parametro::contar() {
    if(proximo == NULL) {
        return 1;
    } else {
        return (((Parametro*)proximo)->contar() + 1);
    }    
}

