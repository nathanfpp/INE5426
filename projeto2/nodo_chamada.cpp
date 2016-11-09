#include "arvoreSintatica.h"

using namespace AST;

Tipo Chamada::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Caso a função/arranjo/hash não tenha sido definida/declarada, ocorre um erro semântico
    Nodo *n = tabelaDeSimbolos->recuperar(id, -1, false);

    if(n != NULL) {

      // Uma chamada pode ser...
        switch(n->tipo) {

// Função
            case Tipo::funcao_dec:
            case Tipo::funcao_def: {

              // Define o tipo desta Chamada como Chamada de Função
                tipo = Tipo::funcao_cha;

              // Conta a quantidade de parâmetros (0 caso não hajam parâmetros)
                Funcao::contarParametros();              
              
              // Recupera a Função a partir do Nodo
                Funcao *f = ((Funcao*) n);
     
              // Analisa os parâmetros, caso existam  
                if(parametros!=NULL) {           
                    parametros->analisar(tabelaDeSimbolos, linha, analisador);
                }

              // Compara a quantidade parâmetros da Função retornada e da Chamada
                int quantidadeEsperada = f->contarParametros();
                if(quantidadeDeParametros != quantidadeEsperada) {
                    std::cerr << "[Line " << linha << "] semantic error: function " << id;
                    std::cerr << " expects " << quantidadeEsperada << " parameters";
                    std::cerr << " but received " << quantidadeDeParametros << "\n";
                }          

              // Se os parâmetros não foram nulos, eles podem ser comparados
                else if(parametros != NULL) {
                    ((Parametro*)f->parametros)->comparar(tabelaDeSimbolos, ((Parametro*)parametros), linha, false, analisador);
                }

              // Atribui o tipo da função definida à declaração ou chamada
                tipoDoRetorno = f->tipoDoRetorno;

              // Executa a função e armazena o retorno na Chamada, caso ela tenha sido definida
                if(analisador) {
                    if(f->definida) {
                        ((DefinicaoDeFuncao*)f)->executar(tabelaDeSimbolos, ((Parametro*)parametros), linha, analisador);
                        boolean = f->boolean;
                        inteiro = f->inteiro;
                        real    = f->real;
//std::cout << "@chamada: " << id << " " << inteiro << "\n";
                    }

                  // Caso a função não tenha sido definida, e o analisador estiver ativo, uma mensagem de erro é emitida
                    else {
                        std::cerr <<"[Line "<<linha<<"]"<< " $ Undefined function " << f->id << ", the result below should not be trusted\n";                        
                    }
                }

              // Retorna o tipo da variável retornada pela função
                return tipoDoRetorno;
            }

// Arranjo Duplo
            case Tipo::arranjo_duplo: {

              // Define o tipo desta Chamada como ArranjoDuplo
                tipo = Tipo::arranjo_duplo;
		
              // Recupera o Arranjo 
                ArranjoDuplo *d = ((ArranjoDuplo*) n);

              // Caso a quantidade de "parâmetros" do arranjo duplo seja diferente de 2, erro!
                if(((Parametro*)parametros)->contar() != 2) {
                    std::cerr << "[Line " << linha << "] semantic error: array double requires exactly two parameters\n";
                } else {

                  // O tipo usado como índice é válido? parametros = tamanho
                    Tipo indice1 = (((Parametro*)parametros)->parametro)->analisar(tabelaDeSimbolos, linha, analisador);
                    Tipo indice2 = (((Parametro*)((Parametro*)parametros)->proximo)->parametro)->analisar(tabelaDeSimbolos, linha, analisador);
                    if(indice1 != Tipo::inteiro) {
                        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received " << imprimirTipoPorExtenso(indice1) << "\n";
                    } else if(indice2 != Tipo::inteiro) {
                        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received " << imprimirTipoPorExtenso(indice2) << "\n";
                    }
		
		     else if (analisador){
			int i = (((Parametro*)parametros)->parametro)->inteiro; //não é com o parametro o problema
			int j = (((Parametro*)((Parametro*)parametros)->proximo)->parametro)->inteiro;

			   if(i >= 0 && i < d->tamanho->inteiro && j >= 0 && j < d->tamanho2->inteiro ){
                               inteiro = d->inteiro_d[i][j];
			       boolean = d->boolean_d[i][j];
			       real = d->real_d[i][j];
			      }
			   else {
	                      std::cerr << "[Line " << linha << "] $ intepreter error:  index-out of bounds"<< "\n";
			   }
			}
	           }
        
              // Retorna-se o tipo da variável do arranjo
                tipoDoRetorno = d->tipoDeVariavel;
                return tipoDoRetorno;
            }

// Arranjo Simples
            case Tipo::arranjo: {

              // Define o tipo desta Chamada como Arranjo
                tipo = Tipo::arranjo;

              // Recupera o Arranjo 
                Arranjo *a = ((Arranjo*) n);

              // Caso a quantidade de "parâmetros" do arranjo simples seja diferente de 1, erro!
                if(((Parametro*)parametros)->contar() != 1) {
                    std::cerr << "[Line " << linha << "] semantic error: array requires exactly one parameter\n";
                } else {

                  // O tipo usado como índice é válido? parametros = tamanho
                    Tipo indice = (((Parametro*)parametros)->parametro)->analisar(tabelaDeSimbolos, linha, analisador);
                    if(indice != Tipo::inteiro) {
                      std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received " << imprimirTipoPorExtenso(indice) << "\n";
                    }
                    else if (analisador){
			int i = ((Parametro*)((Parametro*)parametros)->parametro)->inteiro; //não é com o parametro o problema
		 	if(i>= 0 && i <= a->tamanho->inteiro){
                           inteiro = a->inteiro_a[i];
			   boolean = a->boolean_a[i];
			   real = a->real_a[i];
			}
			else{
	                   std::cerr << "[Line " << linha << "] $ intepreter error:  index-out of bounds"<< "\n";
			}

		    }

                }

              // Retorna o tipo da variável do arranjo
                 tipoDoRetorno = a->tipoDeVariavel;

                 return tipoDoRetorno;
            }

// Hash
            case Tipo::hash: {

              // Define o tipo
                tipo = Tipo::hash;

              // Recupera o Arranjo 
                Hash *h = ((Hash*) n);

              // Caso a quantidade de "parâmetros" do hash seja diferente de 1, erro!
                if(((Parametro*)parametros)->contar() != 1) {
                    std::cerr << "[Line " << linha << "] semantic error: hash requires exactly one key\n";
                } else {
                  
                  // O tipo usado como índice é válido? parametros = tamanho
                    Tipo recebido = ((Parametro*)parametros)->parametro->analisar(tabelaDeSimbolos,linha, analisador);
                    Tipo chave = h->tipoDeChave;
                    if(chave != recebido) {
                        std::cerr << "[Line " << linha << "] semantic error: key operator expects ";
                        std::cerr << imprimirTipoPorExtenso(chave) << " but received " << imprimirTipoPorExtenso(recebido) << "\n";
                    }
		   
 		    else if(analisador){

		     int chave_i = ((Parametro*)((Parametro*)parametros)->parametro)->inteiro;	
		     bool chave_b = ((Parametro*)((Parametro*)parametros)->parametro)->boolean;
		     double chave_r = ((Parametro*)((Parametro*)parametros)->parametro)->real;

		     switch (h->tipoDeHash(tabelaDeSimbolos)){
		    
			    case hash_bb:
				if(h->bool_bool[chave_b] != NULL)   
			    	boolean = h->bool_bool[chave_b];
				else std::cerr << "[Line " << linha << "] $ intepreter error: the key doesn't exist"<< "\n";
			    break;
			    
			    case hash_bf:
				if(h->bool_real[chave_b] != NULL)   
			  	real = h->bool_real[chave_b];
				else std::cerr << "[Line " << linha << "] $ intepreter error: the key doesn't exist"<< "\n";
			    break;

			    case hash_bi:
				if(h->bool_int[chave_b] != NULL)   
			  	inteiro = h->bool_int[chave_b];
				else std::cerr << "[Line " << linha << "] $ intepreter error: the key doesn't exist"<< "\n";
			    break;

			    case hash_ib:
				if(h->int_bool[chave_i] != NULL)   
			  	boolean = h->int_bool[chave_i];
				else std::cerr << "[Line " << linha << "] $ intepreter error: the key doesn't exist"<< "\n";
			    break;
			    
			    case hash_if:
				if(h->int_real[chave_i] != NULL)   
			    	real = h->int_real[chave_i];
				else std::cerr << "[Line " << linha << "] $ intepreter error: the key doesn't exist"<< "\n";
			    break;

			    case hash_ii:
			//	if(h->int_int[chave_i] != NULL)   
			    	inteiro = h->int_int[chave_i]+0;
			//	else std::cerr << "[Line " << linha << "] $ intepreter error: the key doesn't exist"<< "\n";
			    break;

			    case hash_fb:
				if(h->real_bool[chave_r] != NULL)   
			    	boolean = h->real_bool[chave_r];
				else std::cerr << "[Line " << linha << "] $ intepreter error: the key doesn't exist"<< "\n";
			    break;
			    
			    case hash_ff:
				if(h->real_real[chave_r] != NULL)   
			    	real = h->real_real[chave_r];
				else std::cerr << "[Line " << linha << "] $ intepreter error: the key doesn't exist"<< "\n";

			    break;

			    case hash_fi:
				if(h->real_int[chave_r] != NULL)   
			    	inteiro = h->real_int[chave_r];
				else std::cerr << "[Line " << linha << "] $ intepreter error: the key doesn't exist"<< "\n";
			    break;

			    default: break;

			  }
		       }


                }                     

              // Retorna o "tipo da variável", o valor do hash
                tipoDoRetorno = h->tipoDeVariavel;
                 return tipoDoRetorno;
            }

// Evitando warnings
            default:
                break;
        }
    }
    

  // A Chamada de Função ou Arranjo não foi declarada
    std::cerr << "[Line " << linha << "] semantic error: undeclared array, function or hash " << id << "\n";

    return tipo;
}

void Chamada::imprimir(int espaco, bool novaLinha) {

    switch(tipo) {
        case Tipo::funcao_cha:
            std::cout << id << "["<< quantidadeDeParametros << " params]";
            if(parametros != NULL) {
                parametros->imprimir(0, false);
            }
            break;

        case Tipo::arranjo_duplo:
	    if(ponteiroEsqAtribuicao == true && ponteiros > 0) {
	    std::cout << "[ref] "; 
 	    }
            std::cout << "[index][index] " << id << "";
            if(parametros != NULL) {
                parametros->imprimir(0, false);
            }
            break;
        case Tipo::arranjo:
	    if(ponteiroEsqAtribuicao == true && ponteiros > 0) {
	    std::cout << "[ref] "; 
 	    }
            std::cout << "[index] " << id << "";
            if(parametros != NULL) {
                parametros->imprimir(0, false);
            }
            break;
        case Tipo::hash:
	    if(ponteiroEsqAtribuicao == true && ponteiros > 0) {
	    std::cout << "[ref] "; 
 	    }
            std::cout << "[key] " << id << "";
            if(parametros != NULL) {
                parametros->imprimir(0, false);
            }
            break;
        default:
	    if(ponteiroEsqAtribuicao == true && ponteiros > 0) {
	    std::cout << "[ref] "; 
 	    }
           std::cout << "[" << imprimirTipoPorExtenso(tipo) << "] "<< id << "";
           if(parametros != NULL) {
                parametros->imprimir(0, false);
            }
           break;
break;
    }
};

