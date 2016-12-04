#include "arvoreSintatica.h"

using namespace AST;

Tipo Condicao::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Caso a Condição seja um "if"
    if(tipo == Tipo::condicao) {

      // O teste de uma Condição deve ser Booleano
        Tipo esperado = teste->analisar(tabelaDeSimbolos, linha, analisador);
        if(esperado != Tipo::boolean) {
            imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado, linha);
        }   

      // Caso "se" não seja nulo, cria um escopo próprio e é avaliado
        if(se != NULL) {
            TabelaDeSimbolos *novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);

          // Caso a condição seja verdadeira e o código esteja sendo executado, o bloco "then" também é executado
            if(analisador && teste->boolean) {
                se->analisar(novoEscopo, linha, true);
            }

          // Caso contrário, o bloco "then" é apenas analisado
            else if (!analisador){
                se->analisar(novoEscopo, linha, false);
            }

            novoEscopo->retornarEscopo(linha);
        }

      // Caso "senão" não seja nulo, cria um escopo próprio e é avaliado
        if(senao != NULL) {
            TabelaDeSimbolos *novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);

          // Caso a condição seja falsa e o código esteja sendo executado, o bloco "else" também é executado
            if(analisador && !teste->boolean) {
                senao->analisar(novoEscopo, linha, true);
            }

          // Caso contrário, o bloco "else" é apenas analisado
            else if (!analisador){
                senao->analisar(novoEscopo, linha, false);
            }

            novoEscopo->retornarEscopo(linha);  
        }
    }

  // Caso a condição pertença a um "switch"
    else if (tipo == Tipo::caso) {
        teste->analisar(tabelaDeSimbolos, linha, analisador);

      // Se o switch possuir um corpo, ele recebe um novoEscopo e é analisado
    	if(se != NULL) {
    	    TabelaDeSimbolos *novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);
    	    se->analisar(novoEscopo, linha, analisador);
    	    novoEscopo->retornarEscopo(linha);
    	}
    }

  // Caso default
    else if (tipo == Tipo::padrao){ //trato caso default que não possui teste.
        if(se != NULL) {
    	    TabelaDeSimbolos *novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);
    	    se->analisar(novoEscopo, linha, analisador);
    	    novoEscopo->retornarEscopo(linha);
    	}
    }

  // Retorna o tipo do nodo
    return tipo;
}


void Condicao::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    // impressao para if-then-else
    if(tipo == Tipo::condicao){
       std::cout << "if: ";
       teste->imprimir(0, false);
       if(se != NULL) {
           std::cout << "\n";
           imprimirEspaco(espaco);
           std::cout << "then:\n";
           se->imprimir(espaco+2, false);
       }
       if(senao != NULL) {        
          imprimirEspaco(espaco);
          std::cout << "else:\n";
          senao->imprimir(espaco+2, false);
       }
       if(se == NULL && senao == NULL) {
          std::cout << "\n";
       }
       return;
    }
    //impressao para casos de switch (casos ou default)
    if (tipo == Tipo::caso){
        std::cout << "case: ";
        teste->imprimir(0, false);
    }
    else if(tipo == Tipo::padrao) 
        std::cout << "default: ";
        if(se != NULL) {
           std::cout << "\n";
           imprimirEspaco(espaco);
           std::cout << "then:\n";
           se->imprimir(espaco+2, false);
        }
        else {
          std::cout << "\n";
        }
   

}
