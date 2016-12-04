#include "arvoreSintatica.h"

using namespace AST;


Tipo Retorno::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {
    //std::cerr << "r "; 
    Tipo analise = retorno->analisar(tabelaDeSimbolos, linha, analisador);
    boolean = retorno->boolean;
    inteiro = retorno->inteiro;
    real    = retorno->real;
    return analise;
}


void Retorno::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    std::cout << "ret ";
    retorno->imprimir(0, false);
}

