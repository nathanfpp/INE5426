#include "arvoreSintatica.h"

using namespace AST;

Tipo Bloco::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Tipo encontrado após cada linha
    Tipo analise = Tipo::nulo;

  // Tipo do retorno encontrado
    Tipo retorno = Tipo::bloco;  

  // Verificar os Tipos de todas as linhas do Bloco   
    for (Nodo *l : linhas) {    
        if(l != NULL) {
            linha++;
//if(l->tipo == Tipo::retorno) std::cerr << "@bloco:retorno ";
            analise = l->analisar(tabelaDeSimbolos, linha, analisador);
            if(l->tipo == Tipo::retorno) {
                if(retorno == Tipo::bloco) {
                    retorno = analise;
                    boolean = l->boolean;
                    inteiro = l->inteiro;
                    real    = l->real;
                } else {
                    retorno = Tipo::nulo;
                }
            }            
        }
    }

  // Caso o retorno seja "nulo", dois retornos ocorreram numa função
    //if(retorno == Tipo::nulo) {        std::cerr << "Erro para dois retornos em função" << "\n";    }

  // Desempilha-se este escopo, removendo seu endereçamento da tabela de símbolos ...
  // ... sendo o ponteiro para o escopo guardado apenas no Nodo::Bloco

    if(tabelaDeSimbolos->escopoPrincipal()) {
        tabelaDeSimbolos->retornarEscopo(linha);
    }

  // Retorna-se o retorno obtido, ou o Tipo::bloco
    return retorno;
}


void Bloco::imprimir(int espaco, bool novaLinha) {
    for (Nodo* l: linhas) {
        if(l != NULL) {
            l->imprimir(espaco, true);
        }
    }
}


void Bloco::novaLinha(Nodo *linha) {
    linhas.push_back(linha);
}
