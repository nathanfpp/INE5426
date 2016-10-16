#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo OperacaoTernaria::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {  

  // Captura os tipos dos filhos esquerda e direita
    Tipo e = esquerda->analisar(tabelaSimbolos, linha);
    Tipo d = direita->analisar(tabelaSimbolos, linha);

  // Se um dos tipos foram nulo não tem porque seguir adiante
  if (e == Tipo::nulo)
	return e;
  if (d == Tipo::nulo)
	return d;

  //Retorna o nodo a direita que é o valor da atribuicao a ser retornado.
	return d;
}


void OperacaoTernaria::imprimir(int espaco, bool novaLinha) {  
   // imprimirEspaco(espaco);
    esquerda->imprimir(0, false);
    direita->imprimir(0, false);
}
