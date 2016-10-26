#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Bloco::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {

  // Associa o escopo ao Bloco
    escopo = tabelaDeSimbolos;  

  // Tipo encontrado após cada linha
    Tipo analise = Tipo::nulo;

  // Tipo do retorno encontrado
    Tipo retorno = Tipo::bloco;  

  // Verificar os Tipos de todas as linhas do Bloco   
    for (Nodo *l : linhas) {    
        if(l != NULL) {
            linha++;
            analise = l->analisar(escopo, linha);
            if(l->tipo == Tipo::retorno) {
                if(retorno == Tipo::bloco) {
                    retorno = analise; 
                } else {
                    retorno = Tipo::nulo;
                }
            }            
        }
    }

  // Caso o retorno seja "nulo", dois retornos ocorreram numa função
    //if(retorno == Tipo::nulo) {        std::cerr << "Erro para dois retornos em função" << "\n";    }

  // Desempilha-se este escopo, removendo seu endereçamento da tabela de símbolos ...
  // ... sendo o ponteiro para o escopo guardado apenas no Nodo::Bloco
    escopo->retornarEscopo(linha);

  // Retorna-se o retorno obtido, ou o Tipo::bloco
    return retorno;
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
