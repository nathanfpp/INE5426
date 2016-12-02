#include "arvoreSintatica.h"

using namespace AST;

Tipo OperacaoBinaria::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Os tipos dos filhos à esquerda e à direita da OperacaoBinaria
    Tipo e, d;
    e = esquerda->analisar(tabelaDeSimbolos, linha, analisador);
// Armazena os valores da esquerda que são destruidos em caso de funcao recursiva
    bool esquerda_boolean = esquerda->boolean;
    int esquerda_inteiro = esquerda->inteiro;
    double esquerda_real = esquerda->real;

    d = direita->analisar(tabelaDeSimbolos, linha, analisador); 
    tipoDoRetorno = e;


// Arranjos e Hashes, quando o operando é a variável em si e não seus itens, devem apresentar erro caso a atribuicao nao seja simples e seus tipos diferentes.
   if(esquerda->tipo == Tipo::variavel && (e == Tipo::arranjo_2_f ||e == Tipo::arranjo_2_i || e == Tipo::arranjo_2_b || e == Tipo::arranjo_f ||e == Tipo::arranjo_i || e == Tipo::arranjo_b || e == hash_bb || e == hash_bi ||  e == hash_bf ||  e == hash_ib ||  e == hash_ii ||  e == hash_if ||  e == hash_fb ||  e == hash_fi || e == hash_ff || d == Tipo::arranjo_2_f ||d == Tipo::arranjo_2_i || d == Tipo::arranjo_2_b || d == Tipo::arranjo_f ||d == Tipo::arranjo_i || d == Tipo::arranjo_b || d == hash_bb || d == hash_bi ||  d == hash_bf ||  d == hash_ib ||  d == hash_ii ||  d == hash_if ||  d == hash_fb ||  d == hash_fi || d == hash_ff )) { //todas essas condicoes acima sao necessarias
        Tipo tipoDeVariavel_e = ((Variavel*)esquerda)->obterTipoDaTabela(tabelaDeSimbolos);

            if(operacao == Tipo::atribuicao) {
                if(e != d) {
                    imprimirErroDeOperacao(operacao, e, d, linha);
                }
		else if(analisador && (tipoDeVariavel_e == Tipo::arranjo || tipoDeVariavel_e == Tipo::arranjo_duplo 
			|| tipoDeVariavel_e == Tipo::hash)){ 
 			  esquerda = tabelaDeSimbolos->recuperar(esquerda->id, linha, true);
		       if(direita->tipo == Tipo::funcao_cha){
 			   direita = ((Retorno*)((Chamada*)direita)->retornoEstruturaDados);
		       }
		       else{
 			  direita = tabelaDeSimbolos->recuperar(direita->id, linha, true);
			}

			if(tipoDeVariavel_e == Tipo::arranjo){
			 memcpy(((Arranjo*)esquerda)->inteiro_a, ((Arranjo*)direita)->inteiro_a, ((Arranjo*)direita)->tamanho->inteiro*sizeof(int));   
                         memcpy(((Arranjo*)esquerda)->boolean_a, ((Arranjo*)direita)->real_a, ((Arranjo*)direita)->tamanho->inteiro*sizeof(bool));
 			 memcpy(((Arranjo*)esquerda)->real_a, ((Arranjo*)direita)->real_a, ((Arranjo*)direita)->tamanho->inteiro*sizeof(double));
			  tabelaDeSimbolos->modificar(esquerda, esquerda->id); 
			   return e;
			}

			if(tipoDeVariavel_e == Tipo::arranjo_duplo){
			 memcpy(((Arranjo*)esquerda)->inteiro_a, ((Arranjo*)direita)->inteiro_a, ((Arranjo*)direita)->tamanho->inteiro*((ArranjoDuplo*)direita)->tamanho2->inteiro*sizeof(int));
			 memcpy(((Arranjo*)esquerda)->boolean_a, ((Arranjo*)direita)->real_a, ((Arranjo*)direita)->tamanho->inteiro*((ArranjoDuplo*)direita)->tamanho2->inteiro*sizeof(bool));
 			 memcpy(((Arranjo*)esquerda)->real_a, ((Arranjo*)direita)->real_a, ((Arranjo*)direita)->tamanho->inteiro*((ArranjoDuplo*)direita)->tamanho2->inteiro*sizeof(double));
			 tabelaDeSimbolos->modificar(esquerda, esquerda->id); 
			 return e;
			}

			if(tipoDeVariavel_e == Tipo::hash){

			   if (((Hash*)direita)->int_int.size() > 0)
		     	   	((Hash*)esquerda)->int_int = ((Hash*) direita)->int_int;
			   if (((Hash*)direita)->int_bool.size() > 0)
		     	   	((Hash*)esquerda)->int_bool = ((Hash*) direita)->int_bool;
			   if (((Hash*)direita)->int_real.size() > 0)
		     	   	((Hash*)esquerda)->int_real = ((Hash*) direita)->int_real;
			   if (((Hash*)direita)->bool_bool.size() > 0)
		     	   	((Hash*)esquerda)->bool_bool = ((Hash*) direita)->bool_bool;
			   if (((Hash*)direita)->bool_int.size() > 0)
		     	   	((Hash*)esquerda)->bool_int = ((Hash*) direita)->bool_int;
			   if (((Hash*)direita)->bool_real.size() > 0)
		     	   	((Hash*)esquerda)->bool_real = ((Hash*) direita)->bool_real;
			   if (((Hash*)direita)->real_real.size() > 0)
		     	   	((Hash*)esquerda)->real_real = ((Hash*) direita)->real_real;
			   if (((Hash*)direita)->real_int.size() > 0)
		     	   	((Hash*)esquerda)->real_int = ((Hash*) direita)->real_int;
			   if (((Hash*)direita)->real_bool.size() > 0)
		     	   	((Hash*)esquerda)->real_bool = ((Hash*) direita)->real_bool;
                           tabelaDeSimbolos->modificar(esquerda, esquerda->id); 
			   return e;
			}
			
		}

            } else {
		    std::cerr << "[Line " << linha << "] semantic error: arrays or hashes can only be part of a simple attribution" <<"\n";

            }
            return Tipo::nulo;
    }
    
    else if (esquerda->tipo == Tipo::funcao_cha){
	if (analisador && (e == Tipo::arranjo_2_f ||e == Tipo::arranjo_2_i || e == Tipo::arranjo_2_b || e == Tipo::arranjo_f ||e == Tipo::arranjo_i || e == Tipo::arranjo_b || e == hash_bb || e == hash_bi ||  e == hash_bf ||  e == hash_ib ||  e == hash_ii ||  e == hash_if ||  e == hash_fb ||  e == hash_fi || e == hash_ff )){
	       std::cerr << "[Line " << linha << "] semantic error: arrays or hashes can only be part of a simple attribution" <<"\n";
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

  // Gambiarra para conservar os valores originais que são danificados pela recursão
    esquerda->boolean = esquerda_boolean;
    esquerda->inteiro = esquerda_inteiro;
    esquerda->real = esquerda_real;

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

            else { //não faz sentido realizar coercao, se há erro acima
                coercao(this, e, d, operacao, linha, analisador);
		if(e == Tipo::real || d == Tipo::real) {
                   tipoDoRetorno = Tipo::real;
                }
            } 

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
	     		    d->inteiro_a[i*d->tamanho2->inteiro + j] = direita->inteiro;
			case Tipo::boolean:
	     		    d->boolean_a[i*d->tamanho2->inteiro + j]  = direita->boolean;
			case Tipo::real:
	     		    d->real_a[i*d->tamanho2->inteiro + j]  = direita->real;
			default: break;
		     }
                    tabelaDeSimbolos->modificar(d, esquerda->id); 
                 } break;

		case Tipo::hash: {
                     Hash *h = (Hash*) tabelaDeSimbolos->recuperar(esquerda->id, linha, true);
		     int chave_i = ((Parametro*)((Chamada*)esquerda)->parametros)->parametro->inteiro;
		     bool chave_b = ((Parametro*)((Chamada*)esquerda)->parametros)->parametro->boolean;
		     double chave_r = ((Parametro*)((Chamada*)esquerda)->parametros)->parametro->real;
		     switch (tabelaDeSimbolos->tipoDeHash(h->tipoDeChave, h->tipoDeVariavel)){
		    
			    case hash_bb:
			    h->bool_bool[chave_b] = direita->boolean;
			    break;
			    
			    case hash_bf:
			    h->bool_real[chave_b] = direita->real;
			    break;

			    case hash_bi:
			    h->bool_int[chave_b] = direita->inteiro;
			    break;

			    case hash_ib:
			    h->int_bool[chave_i] = direita->boolean;
			    break;
			    
			    case hash_if:
			    h->int_real[chave_i] = direita->real;
			    break;

			    case hash_ii:
			    h->int_int[chave_i] = direita->inteiro;
			    break;

			    case hash_fb:
			    h->real_bool[chave_r] = direita->boolean;
			    break;
			    
			    case hash_ff:
			    h->real_real[chave_r] = direita->real;
			    break;

			    case hash_fi:
			    h->real_int[chave_r] = direita->inteiro;
			    break;

			    default: break;

			  }
                    tabelaDeSimbolos->modificar(h, esquerda->id); 
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
