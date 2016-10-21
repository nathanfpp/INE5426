#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo Parametro::analisar(TabelaDeSimbolos *tabelaDeSimbolos, int linha) {
    if(parametro != NULL) {
        tabelaDeSimbolos->adicionar(parametro, linha, true);
        tipoDoParametro = parametro->analisar(tabelaDeSimbolos, linha);
    }
    if(proximo != NULL) {
        proximo->analisar(tabelaDeSimbolos, linha);
    }
    return tipoDoParametro;
}


void Parametro::imprimir(int espaco, bool naoArgumento) {
    imprimirEspaco(espaco);
    if(naoArgumento) {
        imprimirTipo(tipoDoParametro);
    }
    std::cout << " ";
    parametro->imprimir(0,false);
    if(proximo != NULL) {
       if(naoArgumento) {
           std::cout << ", ";
       }
       proximo->imprimir(espaco, naoArgumento);
    }
}


void Parametro::comparar(TabelaDeSimbolos *tabelaDeSimbolos, Parametro *comparado, int linha, bool definicao) {

  // Adiciona o parâmetro ao escopo da função
    ((Variavel*)parametro)->tipoDeVariavel = tipoDoParametro;

  // Coleta os tipos dos parâmetros
    Tipo tipoComparado;
    if(definicao) {
        tipoComparado = comparado->tipoDoParametro;
        tabelaDeSimbolos->adicionar(parametro,linha, true);
    } else {
        tipoComparado = comparado->parametro->analisar(tabelaDeSimbolos, linha);
    } 

  // Se os parâmetros forem do mesmo tipo
    if(tipoDoParametro == tipoComparado) {

      // Caso se trate de um parâmetro, não um argumento de uma chamada de função...
        if(definicao) {

          // Captura-se os nomes dos parâmetros
            std::string nomeEsperado = ((Variavel*) parametro)->id;
            std::string nomeRecebido = ((Variavel*) comparado->parametro)->id;

          // Compara-se os nomes dos parâmetros, se forem diferentes um erro é emitido
            if(nomeEsperado.compare(nomeRecebido) != 0) {
                std::string id = ((Variavel*) parametro)->id;
                std::cerr << "[Line " << linha << "] semantic error: parameter " << nomeEsperado;
                std::cerr << " expected to be called " << nomeEsperado << " but was named " << nomeRecebido << "\n"; 
            }
        }            
    }

  // Se o Parâmetro atual for diferente do Parâmetro comparado, erro 
    else {
        std::string id = ((Variavel*) parametro)->id;
        std::cerr << "[Line " << linha << "] semantic error: parameter " << id;
        std::cerr << " expected " << imprimirTipoPorExtenso(tipoDoParametro);
        std::cerr << " but received " << imprimirTipoPorExtenso(tipoComparado) << "\n";              
    }   

  // Se os parâmetros atuais forem igual e os próximos forem nulos, então todos os Parâmetro são iguais
    if(proximo != NULL && comparado->proximo != NULL) {           
      // Caso contrário, compara os próximos parâmetros
        ((Parametro*)proximo)->comparar(tabelaDeSimbolos, ((Parametro*)comparado->proximo), linha, definicao);
    }
}


int Parametro::contar() {
    if(proximo == NULL) {
        return 1;
    } else {
        return (((Parametro*)proximo)->contar() + 1);
    }    
}

