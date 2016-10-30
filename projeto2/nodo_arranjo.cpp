#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Arranjo::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {

  // O tipo usado como índice é válido?
    Tipo indice = tamanho->analisar(tabelaDeSimbolos, linha);
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
	if (ponteiros > 0 && ponteiroParametro == true){
	std::cout << "ref ";
        ponteiroParametro = false; 
        }
        std::cout << "[index] " << id << " ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
    }
}
