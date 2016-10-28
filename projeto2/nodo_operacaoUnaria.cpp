#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo OperacaoUnaria::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {
 
  // Captura o tipo do filho
    Tipo d = filho->analisar(tabelaDeSimbolos, linha);

  // Se o tipo do nodo for nulo não tem porque seguir adiante
  if (d == Tipo::nulo)
	return d;

// Arranjos e Hashes, quando o operando é a variável em si e não seus itens, deve dar erro.
    if(filho->tipo == Tipo::variavel){
        Tipo tipoDeVariavel = ((Variavel*)filho)->obterTipoDaTabela(tabelaDeSimbolos);
        if(tipoDeVariavel == Tipo::arranjo || tipoDeVariavel == Tipo::arranjo_duplo || tipoDeVariavel == Tipo::hash) {
              std::cerr << "[Line " << linha << "] semantic error: arrays or hashes can only be part of a simple attribution" <<"\n";
              return Tipo::nulo;
            }

        }

  // Tenho que capturar os ponteiros do filho também
    int d_ponteiros = filho->recuperarPonteiros(tabelaDeSimbolos, linha);

  // Operações Unárias possuem tratamento diferenciado
    switch(operacao) {

      // Operação de Negação recebe um "int" ou "float" e devolve "int" ou "float"
        case Tipo::negacao:
            if(d == Tipo::boolean) {
                imprimirErroDeOperacao(tipo, Tipo::inteiro, d, linha);
            }
            return d;

      // Operação Inversão (Negação Lógica) recebe "bool" e devolve "bool"
        case Tipo::inversao:
            if( d != Tipo::boolean) {
                imprimirErroDeOperacao(tipo, Tipo::boolean, d, linha);
            }              
            return Tipo::boolean;

      // Conversões retornam o tipo convertido, independente da entrada
        case Tipo::conversao_int:    return Tipo::inteiro;
        case Tipo::conversao_float:  return Tipo::real;   
        case Tipo::conversao_bool:   return Tipo::boolean;

      // Parênteses apenas retornam o tipo contido
        case Tipo::parenteses:  return d;

      // Endereco de variavel retorna um tipo inteiro
        case Tipo::endereco:
	if (filho->id == "")
	std::cerr<<"[Line " << linha << "] semantic error: address operation expects a variable or array item\n";
	return Tipo::endereco;

      // Referencia de variavel retorna o tipo dela
        case Tipo::referencia:  
	if (filho->id == "" || (filho->id != "" && d_ponteiros == 0)) //estou referenciando um valor ou uma variavel sem ponteiro ?
	std::cerr<<"[Line " << linha << "] semantic error: reference operation expects a pointer\n";
	this->ponteiros++;
	return d;

    // Condicao booleana para uma atribuicao
	case Tipo::condicao_atribuicao:
	if (d != Tipo::boolean)
        imprimirErroDeOperacao(tipo, Tipo::boolean, d, linha);
	return Tipo::boolean;

      // Por padrão, retorna o tipo do nodo
        default:  return Tipo::nulo;
    }
}


void OperacaoUnaria::imprimir(int espaco, bool novaLinha) {
    imprimirTipo(operacao);
    filho->imprimir(0, false);
}

