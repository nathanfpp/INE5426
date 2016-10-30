#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Variavel::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {

  // Busca a variável na tabela de símbolos 
    Variavel *v = ((Variavel*) tabelaDeSimbolos->recuperar(id, linha, true));

  // Caso a variável seja encontrada, ela pode ser de diferentes tipos
    if(v != NULL) {
        switch(v->tipo) {
            case Tipo::arranjo:       return tabelaDeSimbolos->tipoDeArranjo(v->tipoDeVariavel);
            case Tipo::arranjo_duplo: return tabelaDeSimbolos->tipoDeArranjoDuplo(v->tipoDeVariavel);
            case Tipo::hash:          return tabelaDeSimbolos->tipoDeHash(v->tipoDeVariavel,((Hash*)v)->tipoDeChave);
            case Tipo::variavel:      return v->tipoDeVariavel;
            default:break;
        }
    }

  // Caso a variável não tenha sido declarada, retorna-se o tipoDeVariavel
    return tipoDeVariavel;
}

Tipo Variavel::obterTipoDaTabela(TabelaDeSimbolos *tabelaDeSimbolos) {
    Variavel *v = ((Variavel*) tabelaDeSimbolos->recuperar(id, -1, true));
    if(v != NULL) {
        return v->tipo;
    }
    return Tipo::nulo;
}


int Variavel::recuperarPonteiros(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {

  // Busca a variável na tabela de símbolos e, caso ele seja encontrado, retorna o número de referencias, 
    Variavel *v = ((Variavel*) tabelaDeSimbolos->recuperar(id, linha, true));
    if(v != NULL) {
        return v->ponteiros;
    }

  // Caso contrário, a variável não está na tabela de simbolos e por padrão, retorna 0
    return 0;
}


void Variavel::imprimir(int espaco, bool novaLinha) {
    if(ponteiroEsqAtribuicao == true && ponteiros > 0) {
        std::cout << "[ref] "; 
    }
    if (ponteiros > 0 && ponteiroParametro == true){
	std::cout << "ref ";
        ponteiroParametro = false; 
    }
    std::cout << id << "";
}

