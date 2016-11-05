#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

/* MÉTODO DEFAULT

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

  // Analisa-se a iteração do Laço, caso ela exista
    if(iteracao != NULL) {
       // Caso o código esteja sendo executado, e a condição do teste for verdadeira, ocorre uma iteração
         if(analisador) {
             while(teste->boolean) {
                 iteracao->analisar(tabelaDeSimbolos, linha, true);
                 teste->analisar(tabelaDeSimbolos, linha, true);
             }
        }

      // Caso contrário, a iteração é analisada apenas uma vez
        else {
            iteracao->analisar(tabelaDeSimbolos, linha, false);
        }
    }

  // Se o conteúdo do laço não for vazio, também deve ser verificado
    TabelaDeSimbolos *novoEscopo;
    if(laco != NULL) {
        novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);
        laco->analisar(novoEscopo, linha, analisador);
        novoEscopo->retornarEscopo(linha);
    }

  // Retorna o tipo do nodo
    return tipo;
}

*/


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

  // Analisa-se a iteração do Laço, caso ela exista
    if(iteracao != NULL) { //NAO RECONHECE tipo = for_laco
       // Caso o código esteja sendo executado, e a condição do teste for verdadeira, ocorre uma iteração
         if(analisador) { //SE EU CRIO UM NOVO ESCOPO NÃO FUNCIONA
             while(teste->boolean) {
                 iteracao->analisar(tabelaDeSimbolos, linha, true);
                 teste->analisar(tabelaDeSimbolos, linha, true);
		 if(laco != NULL)
	         laco->analisar(tabelaDeSimbolos, linha, analisador);
             }
        }

      // Caso contrário, a iteração é analisada apenas uma vez
        else {
            iteracao->analisar(tabelaDeSimbolos, linha, false);
        }
    }
    else{
         if(analisador) {
	      while(teste->boolean) {
                 teste->analisar(tabelaDeSimbolos, linha, true);
		 if(laco != NULL)
	         laco->analisar(tabelaDeSimbolos, linha, analisador);
             }
       }
       //NESSE ESQUEMA BIZONHO, NÃO TENHO COMO INTERPRETAR O DO_WHILE, APENAS INTERPRETAR
 }

  // Se o conteúdo do laço não for vazio, também deve ser verificado
    TabelaDeSimbolos *novoEscopo;
    if(laco != NULL) {
        novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);
        laco->analisar(novoEscopo, linha, analisador);
        novoEscopo->retornarEscopo(linha);
    }

  // Retorna o tipo do nodo
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
