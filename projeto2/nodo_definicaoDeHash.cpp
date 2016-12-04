#include "arvoreSintatica.h"

using namespace AST;


Tipo DefinicaoDeHash::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Atribui os tipos ao Hash
    variavel->tipo = Tipo::hash;
    variavel->tipoDeVariavel = tipoDeVariavel;
    ((Hash*)variavel)->tipoDeChave = tipoDeChave;

  // O tipo da próxima Definição que caso não exista será Tipo::nulo
    Tipo tipoDoProximo = Tipo::nulo;

  // Salva a Variável na Tabela de Símbolos
    if(!tabelaDeSimbolos->adicionar(variavel, linha, true)) {

      // Porém, caso a variável já tenha sido declarada, além da impressão do erro, a definição é marcada
        tipo = Tipo::nulo;
    }

  // Se outra Variável foi declarada, atribui o tipo da Declaração e inicia sua análise 
    if(proxima != NULL) {
        proxima->tipoDeVariavel = tipoDeVariavel;
        ((DefinicaoDeHash*)proxima)->tipoDeChave = tipoDeChave;
	proxima->variavel->ponteiros = variavel->ponteiros;
        proxima->analisar(tabelaDeSimbolos, linha, analisador);
     
      // E também registra-se seu Tipo de Nodo
        tipoDoProximo = proxima->tipoDeVariavel;
    }

  // Caso o tipo desta Definição seja nulo, assim como o da próxima Definição...
    if(tipo == Tipo::nulo && tipoDoProximo == Tipo::nulo) {

      // ... isto significa que ambas as Variáveis já foram declaradas anteriormente
        return Tipo::nulo;
    }

  // Retorna o tipo do Nodo
    return Tipo::definicao;
}


void DefinicaoDeHash::imprimir(int espaco, bool imprimirHash) {

    if(tipo == definicao_hash) {
      // A primeira definição após a declaraçãp imprime "hash:"
        if(imprimirHash && variavel->ponteiros == 0) {
            std::cout << " hash: ";
        }

         else if(imprimirHash && variavel->ponteiros > 0) {
	    	for(int i = 0; i < variavel->ponteiros; i++)
               	    std::cout << " ref";
	            std::cout << " hash: ";
        }

        variavel->imprimir(0, true);
    }

  // Imprime a próxima definição
    if(proxima != NULL) {
	std::cout << ", ";
        proxima->imprimir(0, false);
    }
}

