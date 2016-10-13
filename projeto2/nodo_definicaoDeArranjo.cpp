#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo DefinicaoArranjo::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Atribui tipoDeVariavel, recebido da Declaração, ao Nodo Variável (neste caso um Arranjo)
    variavel->tipoDeVariavel = tipoDeVariavel;

  // O tipo da próxima Definição que caso não exista será Tipo::nulo
    Tipo tipoDoProximo = Tipo::nulo;

  // Salva a Variável na Tabela de Símbolos
    if(!tabelaSimbolos->adicionar(variavel, linha, true)) {

      // Porém, caso a variável já tenha sido declarada, além da impressão do erro, a definição é marcada
        tipo = Tipo::nulo;
    }

  // Se outra Variável foi declarada, atribui o tipo da Declaração e inicia sua análise 
    if(proxima != NULL) {
        proxima->tipoDeVariavel = tipoDeVariavel;
	proxima->variavel->ponteiros = variavel->ponteiros;
        proxima->analisar(tabelaSimbolos, linha);

      // E também registra-se seu Tipo de Nodo
        tipoDoProximo = proxima->tipoDeVariavel;
    }

  // Caso o tipo desta Definição seja nulo, assim como o da próxima Definição...
    if(tipo == Tipo::nulo && tipoDoProximo == Tipo::nulo) {

      // ... isto significa que todas as Variáveis já foram declaradas anteriormente
        return Tipo::nulo;
    }

  // Retorna o tipo do Nodo
    return Tipo::definicao_arranjo;
}


void DefinicaoArranjo::imprimir(int espaco, bool imprimirArray) {

  // A primeira definição após a declaraçãp imprime "array:"
    if(imprimirArray && variavel->ponteiros == 0) {
        std::cout << " array: ";
    }

    else if(imprimirArray && variavel->ponteiros > 0) {
	for(int i = 0; i < variavel->ponteiros; i++)
      	  std::cout << " ref";
        std::cout << " array: ";
    }


    variavel->imprimir(0, true);
    if(proxima != NULL) {
        std::cout << ", ";        
        proxima->imprimir(0, false);
    }
}

