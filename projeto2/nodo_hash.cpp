#include "arvoreSintatica.h"

using namespace AST;


Tipo Hash::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {
    return tabelaDeSimbolos->tipoDeHash(tipoDeVariavel, tipoDeChave);
}


Tipo Hash::tipoDeHash(AST::TabelaDeSimbolos *tabelaDeSimbolos) {
    return tabelaDeSimbolos->tipoDeHash(tipoDeChave, tipoDeVariavel);
}

void Hash::imprimir(int espaco, bool declaracao) {    
    if (ponteiros > 0 && ponteiroParametro == true){
	std::cout << "ref ";
        ponteiroParametro = false; 
    }
    std::cout << id << "";
}

