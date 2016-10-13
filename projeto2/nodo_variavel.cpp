#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;


//////////////
// Variavel//

Tipo Variavel::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Busca a variável na tabela de símbolos e, caso ele seja encontrado, retorna o tipo da variável, 
    Variavel *v = ((Variavel*) tabelaSimbolos->recuperar(id, linha, true));
    if(v != NULL) {
        return v->tipoDeVariavel;
    }

  // Caso contrário retorna o tipoDeVariavel deste nodo
    return tipoDeVariavel;
}

int Variavel::recuperarPonteiros(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Busca a variável na tabela de símbolos e, caso ele seja encontrado, retorna o número de referencias, 
    Variavel *v = ((Variavel*) tabelaSimbolos->recuperar(id, linha, true));
    if(v != NULL) {
        return v->ponteiros;
    }

  // Caso contrário, a variável não está na tabela de simbolos e por padrão, retorna 0
    return 0;
}


void Variavel::imprimir(int espaco, bool novaLinha) {

   if(ponteiroEsqAtribuicao == true && ponteiros > 0)
     std::cout << "[ref] "; 
     std::cout << id << "";

}

