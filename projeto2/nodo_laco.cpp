#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Laco::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {

  // Analisa-se a inicialização do Laço, caso ela exista
    if(inicializacao != NULL) {
        inicializacao->analisar(tabelaDeSimbolos, linha);
    }

  // O teste de um Laço deve ser Booleano
    Tipo esperado = teste->analisar(tabelaDeSimbolos, linha);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado, linha);
    }

  // Analisa-se a iteração do Laço, caso ela exista
    if(iteracao != NULL) {
        iteracao->analisar(tabelaDeSimbolos, linha);
    }

  // Se o conteúdo do laço não for vazio, também deve ser verificado
    TabelaDeSimbolos *novoEscopo;
    if(laco != NULL) {
        novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);
        laco->analisar(novoEscopo, linha);
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
