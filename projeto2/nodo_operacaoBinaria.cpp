#include "arvoreSintatica.h"

using namespace AST;

Tipo OperacaoBinaria::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Os tipos dos filhos à esquerda e à direita da OperacaoBinaria
    Tipo e, d;
    e = esquerda->analisar(tabelaDeSimbolos, linha, analisador);
    d = direita->analisar(tabelaDeSimbolos, linha, analisador);
    tipoDoRetorno = e;

// Arranjos e Hashes, quando o operando é a variável em si e não seus itens, devem apresentar erro
   if(esquerda->tipo == Tipo::variavel) {
        Tipo tipoDeVariavel_e = ((Variavel*)esquerda)->obterTipoDaTabela(tabelaDeSimbolos);
        Tipo tipoDeVariavel_d = ((Variavel*)direita)->obterTipoDaTabela(tabelaDeSimbolos);
        if(tipoDeVariavel_e == Tipo::arranjo || tipoDeVariavel_e == Tipo::arranjo_duplo || tipoDeVariavel_e == Tipo::hash
	   || tipoDeVariavel_d == Tipo::arranjo || tipoDeVariavel_d == Tipo::arranjo_duplo || tipoDeVariavel_d == Tipo::hash) {
            if(operacao == Tipo::atribuicao) {
                if(e != d) {
                    imprimirErroDeOperacao(operacao, e, d, linha);
                }
		else{
			if(analisador && tipoDeVariavel_e == Tipo::arranjo){
			 //   memcpy(((Arranjo*)esquerda)->inteiro_a, ((Arranjo*)direita)->inteiro_a,sizeof(int)*100);
			 //   memcpy(((Arranjo*)esquerda)->boolean_a, ((Arranjo*)direita)->boolean_a,sizeof(bool)*100);
			 //   memcpy(((Arranjo*)esquerda)->real_a, ((Arranjo*)direita)->real_a,sizeof(double)*100);
			}
			if(analisador && tipoDeVariavel_e == Tipo::arranjo_duplo){
		   	 //  memcpy(((ArranjoDuplo*)esquerda)->inteiro_d, ((ArranjoDuplo*)direita)->inteiro_d,sizeof(int)*100*100);
			 //  memcpy(((ArranjoDuplo*)esquerda)->boolean_d, ((ArranjoDuplo*)direita)->boolean_d,sizeof(bool)*100*100);
			 //  memcpy(((ArranjoDuplo*)esquerda)->real_d, ((ArranjoDuplo*)direita)->real_d,sizeof(double)*100*100);
			}
			
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

	      switch (esquerda->tipo) {
		 case Tipo::arranjo: {
                     Arranjo *a = (Arranjo*) tabelaDeSimbolos->recuperar(esquerda->id, linha, true);
		     int i = ((Parametro*)((Chamada*)esquerda)->parametros)->parametro->inteiro;
		     switch(e){
			case Tipo::inteiro:
	     		    a->inteiro_a[i] = direita->inteiro;
			case Tipo::boolean:
	     		    a->boolean_a[i] = direita->boolean;
			case Tipo::real:
	     		    a->real_a[i] = direita->real;
			default: break;
		    }
                    tabelaDeSimbolos->modificar(a, esquerda->id); 
		 } break;

	      	 case Tipo::arranjo_duplo: {
                     ArranjoDuplo *d = (ArranjoDuplo*) tabelaDeSimbolos->recuperar(esquerda->id, linha, true);
		     int i = ((Parametro*)((Chamada*)esquerda)->parametros)->parametro->inteiro;
		     int j = (((Parametro*)((Parametro*)((Chamada*)esquerda)->parametros)->proximo)->parametro)->inteiro;

		     switch(e) {
			case Tipo::inteiro:
	     		    d->inteiro_d[i][j] = direita->inteiro;
			case Tipo::boolean:
	     		    d->boolean_d[i][j] = direita->boolean;
			case Tipo::real:
	     		    d->real_d[i][j] = direita->real;
			default: break;
		     }
                    tabelaDeSimbolos->modificar(d, esquerda->id); 
                 } break;

              // Substitui-se o nodo da tabela de símbolos por este com os valores atualizados
		default: {
                        tabelaDeSimbolos->modificar(esquerda, esquerda->id); 
                } break;	   
	      } 


                
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
