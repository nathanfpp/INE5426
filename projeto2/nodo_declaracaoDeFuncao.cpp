#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Funcao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Conta a quantidade de parâmetros: se não houver parâmetros a quantidade é 0
    contarParametros();
  
  // Adiciona-se a função à tabela de funções, caso já não tenha sido definida anteriormente
    definida = false;
    Funcao *f = ((Funcao*) tabelaSimbolos->recuperar(id, -1, false));
    if(f == NULL) {
        tabelaSimbolos->adicionar(this, linha, false);
    } else {
        std::cerr << "[Line " << linha << "] semantic error: re-declaration of function " << f->id << "\n"; 
    }
        

  // Retorna-se o tipo
    return tipo;

}

int Funcao::contarParametros() {
    if(parametros == NULL) {
        quantidadeDeParametros = 0;
    } else {
        quantidadeDeParametros = ((Parametro*)parametros)->contar();
    }    
    return quantidadeDeParametros;
}

