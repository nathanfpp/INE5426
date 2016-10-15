#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo DefinicaoDeFuncao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Conta a quantidade de parâmetros: se não houver parâmetros a quantidade é 0
    definida = true;
    Funcao::contarParametros();

  // Definição ou Chamada de Função
    TabelaDeSimbolos *novoEscopo; 
    novoEscopo = tabelaSimbolos->novoEscopo(tabelaSimbolos);

  // Recupera a Função, caso ela já tenha sido DECLARADA anteriormente
    Funcao *f = ((Funcao*) tabelaSimbolos->recuperar(id, -1, false));
    if(f != NULL) {

    // Caso a função já tenha sido DEFINIDA anterioremente, impre-se um erro
      if(f->definida) {
          tipo = Tipo::nulo;
          std::cerr << "[Line " << linha << "] semantic error: re-definition of function " << f->id << "\n"; 
          return f->tipoDoRetorno;
      }

    // Define a função DECLARADA como DEFINIDA
      f->definida = true;

      // Obtém a quantidade de parâmetros da Função encontrada na Tabela de Símbolos
        int quantidadeEsperada = f->contarParametros();

      // Se a quantidade de parâmetros for diferente, ocorre um erro semântico
        if(quantidadeDeParametros != quantidadeEsperada) {
            std::cerr << "[Line " << linha << "] semantic error: function " << id;
            std::cerr << " expects " << quantidadeEsperada << " parameters";
            std::cerr << " but received " << quantidadeDeParametros << "\n";
        }

      // Se os parâmetros não foram nulos, eles podem ser comparados
        else if(parametros != NULL) {                
            ((Parametro*)f->parametros)->comparar(novoEscopo, ((Parametro*)parametros), linha, true);
        }

      // Se o corpo da Função não for nulo, ele deve ser analisado
        if(corpo != NULL) {                  
            corpo->analisar(novoEscopo, linha);   
        }

      // Atribui o tipo da função definida à declaração ou chamada
        tipoDoRetorno = f->tipoDoRetorno;

      // Retorna ao escopo anterior a Função
        novoEscopo->retornarEscopo(linha);    
    
      // Retorna o tipo da variável retornada pela função
        return tipoDoRetorno;
    }
 
    definida = true;
    if(parametros != NULL) {                
        ((Parametro*) parametros)->comparar(novoEscopo, ((Parametro*)parametros), linha, true);
    }
    if(corpo != NULL) {                  
        corpo->analisar(novoEscopo, linha);   
    }    
    tabelaSimbolos->adicionar(this, linha, false);
    return tipo;    
};


void DefinicaoDeFuncao::imprimir(int espaco, bool novaLinha) {
    if(tipo == Tipo::funcao_def){
        imprimirEspaco(espaco);
        imprimirTipo(tipoDoRetorno);
        std::cout << " fun: " << id << " (params: ";
        if(parametros != NULL) {
            parametros->imprimir(0, true);
        }
        std::cout << ")\n";
        if(corpo != NULL) {
                corpo->imprimir(espaco+2, true);
        }
        imprimirEspaco(espaco);        
        std::cout << "  ret ";
        retorno->imprimir(espaco+2, false);
        std::cout << "\n";
    }
};

