#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo DeclaracaoDeHash::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {

  // Atribui o tipoDeVariavel da Declaração à primeira variável da declaração
    variaveis->tipoDeVariavel = tipoDeVariavel;
    ((DefinicaoDeHash*)variaveis)->tipoDeChave = tipoDeChave;

  // Inicia a análise das variáveis declaradas
    Tipo valida;
    valida = ((DefinicaoDeHash*) variaveis)->analisar(tabelaDeSimbolos, linha);

  // Caso todas as variáveis já tenham sido declaradas, troca o tipo da Declaração para não ser impressa
    if(valida == Tipo::nulo) {
        tipo = Tipo::nulo;
    }

  // Retorna o tipo do nodo
    return tipo;
}


void DeclaracaoDeHash::imprimir(int espaco, bool novaLinha) {

  // Imprime apenas se a declaração for válida
    if(tipo == Tipo::declaracao_hash) {
        imprimirEspaco(espaco);
        imprimirTipo(tipoDeChave);
        std::cout << ":";
        imprimirTipo(tipoDeVariavel);

        if(variaveis != NULL) {
            variaveis->imprimir(0, true);
        }
        std::cout << "\n";
    }
}
