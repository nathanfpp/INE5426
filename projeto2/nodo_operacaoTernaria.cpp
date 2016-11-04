#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo OperacaoTernaria::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha, bool analisador) {  

  // Captura os tipos dos filhos esquerda e direita
    Tipo e = esquerda->analisar(tabelaSimbolos, linha, analisador);
    Tipo d = direita->analisar(tabelaSimbolos, linha, analisador);

  // Se um dos tipos foram nulo não tem porque seguir adiante
  if (e == Tipo::nulo)
	return e;
  if (d == Tipo::nulo)
	return d;
   
   //Interpretador opera atribuicao condicional

   if (analisador){
	inteiro = esquerda->boolean ? direita->esquerda->inteiro : direita->direita->inteiro;
	boolean = esquerda->boolean ? direita->esquerda->boolean : direita->direita->boolean;
	real =    esquerda->boolean ? direita->esquerda->real : direita->direita->real;
   }
  //Retorna o nodo a direita que é o valor da atribuicao a ser retornado.
	return d;
}


void OperacaoTernaria::imprimir(int espaco, bool novaLinha) {  
   // imprimirEspaco(espaco);
    esquerda->imprimir(0, false);
    direita->imprimir(0, false);
}
