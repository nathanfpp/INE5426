#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo ArranjoDuplo::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {

  // O tipo do primeiro índice é válido?
    Tipo indice = tamanho->analisar(tabelaDeSimbolos, linha);
    if(indice != Tipo::inteiro) {
        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received ";
        std::cerr << imprimirTipoPorExtenso(indice) << "\n"; 
    }

  // O tipo do segundo índice é valido?
    indice = tamanho2->analisar(tabelaDeSimbolos, linha);
    if(indice != Tipo::inteiro) {
        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received ";
        std::cerr << imprimirTipoPorExtenso(indice) << "\n"; 
    }

  // O arranjo foi declarado?
    Arranjo *v = ((Arranjo*) tabelaDeSimbolos->recuperar(id, linha, true));
    if(v != NULL) {
        return v->tipoDeVariavel;
    } else {
        std::cerr << "[Line " << linha << "] semantic error: undeclared variable " << id << "\n";
    }

  // Retorna-se o tipo
    return tipoDeVariavel;
}


void ArranjoDuplo::imprimir(int espaco, bool declaracao) {    

 // Impressão para declaração de arranjo
    if(declaracao) {
        std::cout << id << " (size: ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
        std::cout << ", ";
        if(tamanho2 != NULL) {        
            tamanho2->imprimir(0, false);
        }
        std::cout << ")";
    }

  // Impressão para uso comum
    else {
        std::cout << "[index][index] " << id << " ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
        std::cout << " ";
        if(tamanho2 != NULL) {        
            tamanho2->imprimir(0, false);
        }
    }
}
