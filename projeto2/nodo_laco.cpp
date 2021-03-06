#include "arvoreSintatica.h"

using namespace AST;


Tipo Laco::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Analisa-se a inicialização do Laço, caso ela exista
    if(inicializacao != NULL) {
        inicializacao->analisar(tabelaDeSimbolos, linha, analisador);
    }

  // O teste de um Laço deve ser Booleano
    Tipo esperado = teste->analisar(tabelaDeSimbolos, linha, analisador);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado, linha);
    }

  // Caso o laço seja um "for"
    if(tipo == Tipo::for_laco){
        if(iteracao != NULL) { 
          // Caso o código esteja sendo executado, e a condição do teste for verdadeira, ocorre uma iteração
            if(analisador) { //SE EU CRIO UM NOVO ESCOPO NÃO FUNCIONA
                while(teste->boolean) {
	            TabelaDeSimbolos *novoEscopo;
		    if(laco != NULL){
		        novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);
        	        laco->analisar(novoEscopo, linha, analisador);
	                 novoEscopo->retornarEscopo(linha);
		    }
                    iteracao->analisar(tabelaDeSimbolos, linha, true);
                    teste->analisar(tabelaDeSimbolos, linha, true);
                } 
            }

          // Caso contrário, a iteração é analisada apenas uma vez
            else {
                iteracao->analisar(tabelaDeSimbolos, linha, false);
            }
        }
    }

  // Caso o laço seja um "while"
    else if(tipo == Tipo::while_laco){
        if(analisador) {
	    while(teste->boolean) {
	        TabelaDeSimbolos *novoEscopo;
		if(laco != NULL){
		    novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);
        	    laco->analisar(novoEscopo, linha, analisador);
	            novoEscopo->retornarEscopo(linha);
		}
                teste->analisar(tabelaDeSimbolos, linha, true);
            }
        }
    }

  // Caso o laço seja um "do while"
    else if(tipo == Tipo::do_while_laco){
        if(analisador) {
	    do {
	        TabelaDeSimbolos *novoEscopo;
		if(laco != NULL){
		    novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);
        	    laco->analisar(novoEscopo, linha, analisador);
	            novoEscopo->retornarEscopo(linha);
		}
                teste->analisar(tabelaDeSimbolos, linha, true);
       	    } while(teste->boolean);
        }
    }

  // Se o conteúdo do laço não for vazio, também deve ser verificado
    if(!analisador){
        TabelaDeSimbolos *novoEscopo;
        if(laco != NULL) {
            novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);
            laco->analisar(novoEscopo, linha, analisador);
            novoEscopo->retornarEscopo(linha);
        }
    }

  // Retorna-se o tipo do nodo
    return tipo;
}


void Laco::imprimir(int espaco, bool novaLinha) {
    switch(tipo){
        case Tipo::for_laco:
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
            break;

        case Tipo::do_while_laco:
            imprimirEspaco(espaco);
            std::cout << "do:\n";
            laco->imprimir(espaco+2, true);
            std::cout << "while: ";
            teste->imprimir(0, false);
            std::cout << "\n";
            break;

        case Tipo::while_laco:
           imprimirEspaco(espaco);
           std::cout << "while: ";
           teste->imprimir(0, false);
           std::cout << "\ndo:\n";
           laco->imprimir(espaco+2, true);            
           break;

        default: break;
    }    
}

