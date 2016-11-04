#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo OperacaoBinaria::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Os tipos dos filhos à esquerda e à direita da OperacaoBinaria
    Tipo e, d;
    e = esquerda->analisar(tabelaDeSimbolos, linha, analisador);
    d = direita->analisar(tabelaDeSimbolos, linha, analisador);
    tipoDoRetorno = e;

// Arranjos e Hashes, quando o operando é a variável em si e não seus itens, devem apresentar erro
   if(esquerda->tipo == Tipo::variavel) {
        Tipo tipoDeVariavel = ((Variavel*)esquerda)->obterTipoDaTabela(tabelaDeSimbolos);
        if(tipoDeVariavel == Tipo::arranjo || tipoDeVariavel == Tipo::arranjo_duplo || tipoDeVariavel == Tipo::hash) {
            if(operacao == Tipo::atribuicao) {
                if(e != d) {
                    imprimirErroDeOperacao(operacao, e, d, linha);
                }
            } else {
		    std::cerr << "[Line " << linha << "] semantic error: arrays or hashes can only be part of a simple attribution" <<"\n";
            }
            return Tipo::nulo;
        }
    }

  // Se um dos tipos for nulo não tem porque seguir adiante
  if (e == Tipo::nulo)
	return e;
  if (d == Tipo::nulo)
	return d;

  // Tenho que capturar os ponteiros dos filhos da direita e esquerda também
    int e_ponteiros = esquerda->recuperarPonteiros(tabelaDeSimbolos, linha);
    int d_ponteiros = direita->recuperarPonteiros(tabelaDeSimbolos, linha);

  // Operações Binárias possuem comportamentos diferentes
    switch(operacao) {

  // A Atribuição recebe "int","float" ou "bool" e retorna "int", "float" ou "bool"
        case Tipo::atribuicao:
          // O nodo à esquerda não pode ser uma função
            if(esquerda->tipo == Tipo::funcao_cha) {
                std::cerr << "[Line " << linha << "] semantic error: attribution operation expects a variable on the left side not a function" <<"\n";
                return Tipo::nulo;
            }

	    if((e == Tipo::inteiro && (d != Tipo::inteiro && d != Tipo::endereco))
		|| (e == Tipo::boolean && (d != Tipo::boolean && d != Tipo::endereco))
		|| (e == Tipo::real && d == Tipo::boolean)) {
            	imprimirErroDeOperacao(operacao, e, d, linha);
            }

            if(e == Tipo::real || d == Tipo::real) {
                tipoDoRetorno = Tipo::real;
            }

            else {
                coercao(this, e, d, operacao,linha, analisador);
            } //não faz sentido realizar coercao, se há erro acima

	    if(e_ponteiros > 0 && d_ponteiros == 0 && d!=Tipo::endereco) { 
		std::cerr << "[Line " << linha << "] semantic error: attribution operation expects "<<imprimirTipoPorExtenso(e)<<" pointer but received "<<imprimirTipoPorExtenso(d) <<"\n";
            }

            if(analisador) {
              // Realiza-se a atribuicao de todos os valores, independente do tipo da variável
                esquerda->inteiro = direita->inteiro; esquerda->real = direita->real; esquerda->boolean = direita->boolean;
                inteiro = direita->inteiro; real = direita->real; boolean = direita->boolean;
              // Substitui-se o nodo da tabela de símbolos por este com os valores atualizados
                tabelaDeSimbolos->modificar(esquerda, esquerda->id);
            }

          // Retorna-se o tipo da esquerda
            return e;

  // Operaçãos Aritméticas recebem "int" ou "float" e devolvem "int" ou "float"
        case Tipo::adicao:
        case Tipo::subtracao:
        case Tipo::multiplicacao:
        case Tipo::divisao:
 
          // O tipo da esquerda é inválido?
            if(e == Tipo::boolean || e == Tipo::endereco) {
                imprimirErroDeOperacao(operacao, Tipo::inteiro, e, linha);
            }

          // O tipo da direita é inválido?
            else if (d == Tipo::boolean || d == Tipo::endereco) {
                imprimirErroDeOperacao(operacao, e, d, linha);
            }
   
          // A coerção de tipos é necessária?
            if(coercao(this, e, d, operacao, linha, analisador)) {

              // Se a coerção ocorre, é garantido que a operação binária retorna um tipo float
                tipoDoRetorno = Tipo::real;
                return Tipo::real;
            } 

          // Caso não ocorra coerção, os tipos da esquerda e direita são iguais
            return e;
            

  // Operações Lógicas recebem "bool" e devolvem "bool"
         case Tipo::e:
         case Tipo::ou:

           // 
             if(operacao == Tipo::e) {
                 boolean = esquerda->boolean && direita->boolean;
             } else {
                 boolean = esquerda->boolean || direita->boolean;
             }

          // O tipo da esquerda é válido?
            if(e != Tipo::boolean) {
                imprimirErroDeOperacao(operacao, Tipo::boolean, e, linha);
            }

          // O tipo da direita é válido?
             else if (d != Tipo::boolean) {
              imprimirErroDeOperacao(operacao, Tipo::boolean, d, linha);
            }

          // Retorna o tipo boolean
           return Tipo::boolean;
           break;

  // Comparadores recebem "int" ou "float" e devolvem "bool"
         case Tipo::igual:
         case Tipo::diferente:
         case Tipo::maior:
         case Tipo::maior_igual:
         case Tipo::menor:
         case Tipo::menor_igual:

          // O tipo da esquerda é válido?
            if(e == Tipo::boolean) {
                imprimirErroDeOperacao(operacao, Tipo::inteiro, e, linha);
            }

          // O tipo da direita é válido?
            else if (d == Tipo::boolean) {
                imprimirErroDeOperacao(operacao, e, d, linha);
            }

          // Realiza-se coerção, se necessário
            coercao(this, e, d, operacao, linha, analisador);

          // Independente do retorno da coerção, retorna-se um valor booleano
            return Tipo::boolean;
            break;

   // Atribuicao condicional
	case Tipo::atribuicao_condicional:
  
         // Realiza-se coerção, se necessário
            coercao(this, e, d, operacao, linha, analisador);

          // O tipo da esquerda é válido?
            if(e != d) {
                imprimirErroDeOperacao(operacao, e, d, linha);
            }

         // Independente do retorno da coerção, retorna-se o tipo do nodo à esquerda
	    return e;
	    break;
	

      // Caso ocorra uma operação inválida, retorna-se Tipo::nulo
        default:
            return Tipo::nulo;
            break;               
      }
}


void OperacaoBinaria::imprimir(int espaco, bool novaLinha) {  
    imprimirEspaco(espaco);
    imprimirTipo(operacao);
    std::cout << " ";
    esquerda->imprimir(0, false);
    std::cout << " ";
    direita->imprimir(0, false);
    if(novaLinha) std::cout << "\n";
}
