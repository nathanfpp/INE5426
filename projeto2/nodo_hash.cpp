#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Hash::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {
    return tabelaDeSimbolos->tipoDeHash(tipoDeVariavel, tipoDeChave);
}

Tipo Hash::tipoDeHash(AST::TabelaDeSimbolos *tabelaDeSimbolos) {
    return tabelaDeSimbolos->tipoDeHash(tipoDeChave, tipoDeVariavel);
}

void Hash::imprimir(int espaco, bool declaracao) {    
    std::cout << id << "";
}
