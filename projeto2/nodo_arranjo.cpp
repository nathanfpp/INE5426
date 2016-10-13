#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Arranjo::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // O tipo usado como índice é válido?
    Tipo indice = tamanho->analisar(tabelaSimbolos, linha);
    if(indice != Tipo::inteiro) {
        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received ";
        std::cerr << imprimirTipoPorExtenso(indice) << "\n"; 
    }

  // O arranjo foi declarado? Senão o erro é imprimido pela tabela
    Arranjo *v = ((Arranjo*) tabelaSimbolos->recuperar(id, linha, true));
    if(v != NULL) {
        return v->tipoDeVariavel;
    }

  // Retorna o tipo
    return tipoDeVariavel;
}


void Arranjo::imprimir(int espaco, bool declaracao) {    

 // Impressão para declaração de arranjo
    if(declaracao) {
        std::cout << id << " (size: ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
        std::cout << ")";
    }

  // Impressão para uso comum
    else {
        std::cout << "[index] " << id << " ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
    }
}
