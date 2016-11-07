#include "arvoreSintatica.h"

using namespace AST;

Tipo Condicao::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

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

  // Retorna o tipo do nodo
    return tipo;
}


void Condicao::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
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
}
