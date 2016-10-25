#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Retorno::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {
    return retorno->analisar(tabelaDeSimbolos, linha);
}

void Retorno::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    std::cout << "ret ";
    retorno->imprimir(0, false);
}

