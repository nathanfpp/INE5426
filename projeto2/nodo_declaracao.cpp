#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Declaracao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Atribui o tipoDeVariavel da Declaração à primeira variável da declaração
    variaveis->tipoDeVariavel = tipoDeVariavel;

  // Inicia a análise das variáveis declaradas
    Tipo valida;
    if(variaveis->tipo == Tipo::declaracao){
        valida = variaveis->analisar(tabelaSimbolos, linha);
    } else {
        valida = ((DefinicaoArranjo*) variaveis)->analisar(tabelaSimbolos, linha);
    }

  // Caso todas as variáveis já tenham sido declaradas, troca o tipo da Declaração para não ser impressa
    if(valida == Tipo::nulo) {
        tipo = Tipo::nulo;
    }

  // Retorna o tipo do nodo
    return tipo;
}


void Declaracao::imprimir(int espaco, bool novaLinha) {

  // Imprime apenas se a declaração for válida
    if(tipo == Tipo::declaracao) {
        imprimirEspaco(espaco);
        imprimirTipo(tipoDeVariavel);
        if(variaveis != NULL) {
            variaveis->imprimir(0, true);
        }
        std::cout << "\n";
    }
}

