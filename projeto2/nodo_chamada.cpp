#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Chamada::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Caso a função/arranjo/hash não tenha sido definida/declarada, ocorre um erro semântico
    Nodo *n = tabelaDeSimbolos->recuperar(id, -1, false);

    if(n != NULL) {

      // Uma chamada pode ser...
        switch(n->tipo) {

// Função
            case Tipo::funcao_dec:
            case Tipo::funcao_def: {

//std::cerr << "chamada::analisar " << id << " 1\n";

              // Define o tipo desta Chamada como Chamada de Função
                tipo = Tipo::funcao_cha;

              // Conta a quantidade de parâmetros (0 caso não hajam parâmetros)
                Funcao::contarParametros();              
              
              // Recupera a Função a partir do Nodo
                Funcao *f = ((Funcao*) n);
     
              // Analisa os parâmetros, caso existam  
                if(parametros!=NULL) {           
                    parametros->analisar(tabelaDeSimbolos, linha, analisador);
                }

              // Compara a quantidade parâmetros da Função retornada e da Chamada
                int quantidadeEsperada = f->contarParametros();
                if(quantidadeDeParametros != quantidadeEsperada) {
                    std::cerr << "[Line " << linha << "] semantic error: function " << id;
                    std::cerr << " expects " << quantidadeEsperada << " parameters";
                    std::cerr << " but received " << quantidadeDeParametros << "\n";
                }          

              // Se os parâmetros não foram nulos, eles podem ser comparados
                else if(parametros != NULL) {
                    ((Parametro*)f->parametros)->comparar(tabelaDeSimbolos, ((Parametro*)parametros), linha, false, analisador);
                }

              // Atribui o tipo da função definida à declaração ou chamada
                tipoDoRetorno = f->tipoDoRetorno;

              // Executa a função e armazena o retorno na Chamada, caso ela tenha sido definida
                if(analisador) {
                    if(f->definida) {
                        ((DefinicaoDeFuncao*)f)->executar(tabelaDeSimbolos, ((Parametro*)parametros), linha, analisador);
                        boolean = f->boolean;
                        inteiro = f->inteiro;
                        real    = f->real;
//std::cout << "@chamada: " << id << " " << inteiro << "\n";
                    }

                  // Caso a função não tenha sido definida, e o analisador estiver ativo, uma mensagem de erro é emitida
                    else {
                        std::cerr <<"[Line "<<linha<<"]"<< " $ Undefined function " << f->id << ", the result below should not be trusted\n";                        
                    }
                }

              // Retorna o tipo da variável retornada pela função
                return tipoDoRetorno;
            }

// Arranjo Duplo
            case Tipo::arranjo_duplo: {

              // Define o tipo desta Chamada como ArranjoDuplo
                tipo = Tipo::arranjo_duplo;

              // Recupera o Arranjo 
                ArranjoDuplo *d = ((ArranjoDuplo*) n);

              // Caso a quantidade de "parâmetros" do arranjo duplo seja diferente de 2, erro!
                if(((Parametro*)parametros)->contar() != 2) {
                    std::cerr << "[Line " << linha << "] semantic error: array double requires exactly two parameters\n";
                } else {

                  // O tipo usado como índice é válido? parametros = tamanho
                    Tipo indice1 = (((Parametro*)parametros)->parametro)->analisar(tabelaDeSimbolos, linha, analisador);
                    Tipo indice2 = (((Parametro*)((Parametro*)parametros)->proximo)->parametro)->analisar(tabelaDeSimbolos, linha, analisador);
                    if(indice1 != Tipo::inteiro) {
                        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received " << imprimirTipoPorExtenso(indice1) << "\n";
                    } else if(indice2 != Tipo::inteiro) {
                        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received " << imprimirTipoPorExtenso(indice2) << "\n";
                    }
                }

              // Retorna-se o tipo da variável do arranjo
                tipoDoRetorno = d->tipoDeVariavel;
                return tipoDoRetorno;
            }

// Arranjo Simples
            case Tipo::arranjo: {

              // Define o tipo desta Chamada como Arranjo
                tipo = Tipo::arranjo;

              // Recupera o Arranjo 
                Arranjo *a = ((Arranjo*) n);

              // Caso a quantidade de "parâmetros" do arranjo simples seja diferente de 1, erro!
                if(((Parametro*)parametros)->contar() != 1) {
                    std::cerr << "[Line " << linha << "] semantic error: array requires exactly one parameter\n";
                } else {

                  // O tipo usado como índice é válido? parametros = tamanho
                    Tipo indice = (((Parametro*)parametros)->parametro)->analisar(tabelaDeSimbolos, linha, analisador);
                    if(indice != Tipo::inteiro) {
                      std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received " << imprimirTipoPorExtenso(indice) << "\n";
                    }
                }

              // Retorna o tipo da variável do arranjo
                 tipoDoRetorno = a->tipoDeVariavel;
//std::cerr << "@chamada : " << imprimirTipoPorExtenso(tipoDoRetorno) << "\n";
                 return tipoDoRetorno;
            }

// Hash
            case Tipo::hash: {

              // Define o tipo
                tipo = Tipo::hash;

              // Recupera o Arranjo 
                Hash *h = ((Hash*) n);

              // Caso a quantidade de "parâmetros" do hash seja diferente de 1, erro!
                if(((Parametro*)parametros)->contar() != 1) {
                    std::cerr << "[Line " << linha << "] semantic error: hash requires exactly one key\n";
                } else {
                  
                  // O tipo usado como índice é válido? parametros = tamanho
                    Tipo recebido = ((Parametro*)parametros)->parametro->analisar(tabelaDeSimbolos,linha, analisador);
                    Tipo chave = h->tipoDeChave;
                    if(chave != recebido) {
                        std::cerr << "[Line " << linha << "] semantic error: key operator expects ";
                        std::cerr << imprimirTipoPorExtenso(chave) << " but received " << imprimirTipoPorExtenso(recebido) << "\n";
                    }
                }                     

              // Retorna o "tipo da variável", o valor do hash
                tipoDoRetorno = h->tipoDeVariavel;
                 return tipoDoRetorno;
            }

// Evitando warnings
            default:
                break;
        }
    }
    

  // A Chamada de Função ou Arranjo não foi declarada
    std::cerr << "[Line " << linha << "] semantic error: undeclared array, function or hash " << id << "\n";
    //std::cerr << "[Line " << linha << "] semantic error: undeclared function " << id << "\n";
    return tipo;
}

void Chamada::imprimir(int espaco, bool novaLinha) {

    switch(tipo) {
        case Tipo::funcao_cha:
            std::cout << id << "["<< quantidadeDeParametros << " params]";
            if(parametros != NULL) {
                parametros->imprimir(0, false);
            }
            break;

        case Tipo::arranjo_duplo:
	    if(ponteiroEsqAtribuicao == true && ponteiros > 0) {
	    std::cout << "[ref] "; 
 	    }
            std::cout << "[index][index] " << id << "";
            if(parametros != NULL) {
                parametros->imprimir(0, false);
            }
            break;
        case Tipo::arranjo:
	    if(ponteiroEsqAtribuicao == true && ponteiros > 0) {
	    std::cout << "[ref] "; 
 	    }
            std::cout << "[index] " << id << "";
            if(parametros != NULL) {
                parametros->imprimir(0, false);
            }
            break;
        case Tipo::hash:
	    if(ponteiroEsqAtribuicao == true && ponteiros > 0) {
	    std::cout << "[ref] "; 
 	    }
            std::cout << "[key] " << id << "";
            if(parametros != NULL) {
                parametros->imprimir(0, false);
            }
            break;
        default:
	    if(ponteiroEsqAtribuicao == true && ponteiros > 0) {
	    std::cout << "[ref] "; 
 	    }
           std::cout << "[" << imprimirTipoPorExtenso(tipo) << "] "<< id << "";
           if(parametros != NULL) {
                parametros->imprimir(0, false);
            }
           break;
break;
    }
};

