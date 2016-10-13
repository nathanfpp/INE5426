#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Bloco::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

// Associa o escopo ao Bloco
  escopo = tabelaSimbolos;  

  // Verificar os Tipos de todas as linhas do Bloco   
    for (Nodo* l: linhas) {
        if(l != NULL) {
            linha++;
            l->analisar(escopo, linha);
        }
    }

  // Desempilha-se este escopo, removendo seu endereçamento da tabela de símbolos ...
  // ... sendo o ponteiro para o escopo guardado apenas no Nodo::Bloco
    escopo->retornarEscopo(linha);

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
