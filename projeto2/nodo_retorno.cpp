#include "arvoreSintatica.h"


using namespace AST;

Tipo Retorno::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {
    Tipo analise = retorno->analisar(tabelaDeSimbolos, linha, analisador);
    boolean = retorno->boolean;
    inteiro = retorno->inteiro;
    real    = retorno->real;
//std::cout << "@return: " << inteiro << "\n";
    return analise;
}

void Retorno::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    std::cout << "ret ";
    retorno->imprimir(0, false);
}

