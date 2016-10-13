#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Condicao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // O teste de uma Condição deve ser Booleano
    Tipo esperado = teste->analisar(tabelaSimbolos, linha);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado, linha);
    }   

  // Caso "se" não seja nulo, cria um escopo próprio e é avaliado
    if(se != NULL) {
        TabelaDeSimbolos *novoEscopo = tabelaSimbolos->novoEscopo(tabelaSimbolos);
        se->analisar(novoEscopo, linha);
        novoEscopo->retornarEscopo(linha);
    }

  // Caso "senão" não seja nulo, cria um escopo próprio e é avaliado
    if(senao != NULL) {
        TabelaDeSimbolos *novoEscopo = tabelaSimbolos->novoEscopo(tabelaSimbolos);
        senao->analisar(novoEscopo, linha);
        novoEscopo->retornarEscopo(linha);  
    }

  // Retorna o tipo do nodo
    return tipo;
}


void Condicao::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    std::cout << "if: ";
    teste->imprimir(0, false);
    if(se != NULL) {
        std::cout << "\n";
        imprimirEspaco(espaco);
        std::cout << "then:\n";
        se->imprimir(espaco+2, false);
    }
    if(senao != NULL) {        
        imprimirEspaco(espaco);
        std::cout << "else:\n";
        senao->imprimir(espaco+2, false);
    }
    if(se == NULL && senao == NULL) std::cout << "\n";
}
