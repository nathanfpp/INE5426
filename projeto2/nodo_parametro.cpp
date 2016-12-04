#include "arvoreSintatica.h"

using namespace AST;


Tipo Parametro::analisar(TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // O Hash possui tratamento diferente das demais variáveis
    if(parametro != NULL) {
        switch(parametro->tipo) {
            case Tipo::variavel:
            case Tipo::arranjo:
            case Tipo::arranjo_duplo:
                ((Variavel*)parametro)->tipoDeVariavel = tipoDoParametro; 
                break;
            case Tipo::hash:
                ((Hash*)parametro)->tipoDeVariavel = tipoDoParametro; 
                ((Hash*)parametro)->tipoDeChave = tipoReserva;
                break;
	   default: break;
        }
    }

  // Analisa o próximo parâmetro, caso ele exista
    if(proximo != NULL) {
        proximo->analisar(tabelaDeSimbolos, linha, analisador);
    }

  // Retorna o tipo
    return tipoDoParametro;
}


void Parametro::comparar(TabelaDeSimbolos *tabelaDeSimbolos, Parametro *comparado, int linha, bool definicao, bool analisador) {

  // Se o tipoReserva não for nulo, ele representa a chave do parâmetro de HASH //
    if(tipoReserva != Tipo::nulo) {

      // Definição de Função acrescenta os parâmetros à tabela de símbolos
        if(definicao) {
            Tipo tipoValor = comparado->tipoDoParametro;
            Tipo tipoChave = comparado->tipoReserva;
            tabelaDeSimbolos->adicionar(parametro, linha, true);

	        // Compara as Chaves dos Hashes
	       if(tipoChave == tipoReserva) {
	    
		  // Compara os Valores do Hashes
		    if(tipoValor == tipoDoParametro) {
			  // Captura-se os nomes dos parâmetros
			    std::string nomeEsperado = ((Variavel*) parametro)->id;
			    std::string nomeRecebido = ((Variavel*) comparado->parametro)->id;

			  // Compara-se os nomes dos parâmetros, se forem diferentes um erro é emitido
			    if(nomeEsperado.compare(nomeRecebido) != 0) {
			        std::string id = ((Variavel*) parametro)->id;
			        std::cerr << "[Line " << linha << "] semantic error: hash parameter " << nomeEsperado;
			        std::cerr << " expected to be called " << nomeEsperado << " but was named " << nomeRecebido << "\n"; 
			    }            
		    }

		  // Se os Valores forem de tipos diferentes
		    else {              
			std::cerr << "[Line " << linha << "] semantic error: hash parameter " << parametro->id;
			std::cerr << " expected value of type " << imprimirTipoPorExtenso(tipoDoParametro);
			std::cerr << " but received " << imprimirTipoPorExtenso(tipoValor) << "\n";              
		    }
		}

	       // Se as Chaves forem de tipos diferentes
		else {
		    std::cerr << "[Line " << linha << "] semantic error: hash parameter " << parametro->id;
		    std::cerr << " expected key of type " << imprimirTipoPorExtenso(tipoReserva);
		    std::cerr << " but received " << imprimirTipoPorExtenso(tipoChave) << "\n";              
		}
        }

      // Chamada de Função: argumentos (qualquer expressao ou até mesmo um hash simples) vs Parametro (hash)
        else {
	  //Recupera nodo se for variavel
	    Tipo tipoArgumento = comparado->parametro->analisar(tabelaDeSimbolos, linha, analisador); 
	    Tipo tipoParametroAjustado = tabelaDeSimbolos->tipoDeHash(tipoReserva, tipoDoParametro);//chave,valor->retorna tipo chave_Valor
	    if(tipoParametroAjustado != tipoArgumento) {
	     //Parametro recebido é alguma coisa qualquer, menos um hash
	        std::cerr <<"[Line " << linha << "]"<<" semantic error: expected hash "<<imprimirTipoPorExtenso(tipoParametroAjustado);
                std::cerr << " but received " << imprimirTipoPorExtenso(tipoArgumento) << "\n";              			
	    }
        }	 
    }

// Variáveis Simples
    else {

      // Coleta os tipos dos parâmetros
        Tipo tipoComparado = Tipo::nulo;

      // Definição de Função acrescenta os parâmetros à tabela de símbolos
        if(definicao) {
            tipoComparado = comparado->tipoDoParametro;
            tabelaDeSimbolos->adicionar(parametro,linha, true);
        }

      // Chamada de Função analisa o parâmetro 
        else {
            // Nodo *n = tabelaDeSimbolos->recuperar(comparado->parametro->id, linha, true);
            tipoComparado = comparado->parametro->analisar(tabelaDeSimbolos, linha, analisador);
        }

      // Ajusta o tipoDoParametro caso se trate de um arranjo ou arrranjo duplo
	Tipo tipoDoParametroAjustado = tipoDoParametro;
        if(parametro->tipo == Tipo::arranjo) {
            tipoDoParametroAjustado = tabelaDeSimbolos->tipoDeArranjo(((Variavel*)parametro)->tipoDeVariavel);
        } else if (parametro->tipo == Tipo::arranjo_duplo) {
            tipoDoParametroAjustado = tabelaDeSimbolos->tipoDeArranjoDuplo(((Variavel*)parametro)->tipoDeVariavel);
        }

      // Se os parâmetros forem do mesmo tipo
        if(tipoDoParametroAjustado == tipoComparado) {
    
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
            std::cerr << " expected " << imprimirTipoPorExtenso(tipoDoParametroAjustado);
            std::cerr << " but received " << imprimirTipoPorExtenso(tipoComparado) << "\n";              
        }   
    }

  // Se os parâmetros atuais forem igual e os próximos forem nulos, então todos os Parâmetro são iguais
    if(proximo != NULL && comparado->proximo != NULL) {           

      // Caso contrário, compara-se os próximos parâmetros
        ((Parametro*)proximo)->comparar(tabelaDeSimbolos, ((Parametro*)((Parametro*)comparado->proximo)), linha, definicao, analisador);
    }
}


void Parametro::acrescentarAoEscopo(TabelaDeSimbolos *tabelaDeSimbolos, int linha) {

  // Enquanto houver parametros acrescento-os recursivamente ao escopo
    if(parametro != NULL) {
        ((Variavel*)parametro)->tipoDeVariavel = tipoDoParametro; 
        if(parametro->tipo == Tipo::hash) { // Hashes por ter um tipo chave, tem tratamento diferencial
            ((Hash*)parametro)->tipoDeChave = tipoReserva;
        }
    }
    tabelaDeSimbolos->adicionar(parametro, linha, variavel);
    if(proximo != NULL) {
        return ((Parametro*)proximo)->acrescentarAoEscopo(tabelaDeSimbolos, linha);
    }
}


void Parametro::acrescentarComValoresAoEscopo(TabelaDeSimbolos *tabelaDeSimbolos, Parametro *valores, int linha) {

  // Semelhante ao método acima só que para o interpretador.
  // Enquanto houver parametros acrescento-os recursivamente ao escopo copiando os seus valores

    if(parametro != NULL && valores != NULL) {
	valores->parametro->analisar(tabelaDeSimbolos, linha, true);

      // Copia-se o tipo do parâmetro
        ((Variavel*)parametro)->tipoDeVariavel = tipoDoParametro;

// Hash
        if(parametro->tipo == Tipo::hash && valores->parametro->tipo == Tipo::hash) {
            ((Hash*)parametro)->tipoDeChave = tipoReserva;
            
           if (((Hash*)(valores->parametro))->int_int.size() > 0)
               ((Hash*)parametro)->int_int = ((Hash*)(valores->parametro))->int_int;
           if (((Hash*)(valores->parametro))->int_bool.size() > 0)
               ((Hash*)parametro)->int_bool = ((Hash*)(valores->parametro))->int_bool;
           if (((Hash*)(valores->parametro))->int_real.size() > 0)
              ((Hash*)parametro)->int_real = ((Hash*)(valores->parametro))->int_real;
           if (((Hash*)(valores->parametro))->bool_bool.size() > 0)
   	      ((Hash*)parametro)->bool_bool = ((Hash*)(valores->parametro))->bool_bool;
           if (((Hash*)(valores->parametro))->bool_int.size() > 0)
   	      ((Hash*)parametro)->bool_int = ((Hash*)(valores->parametro))->bool_int;          
           if (((Hash*)(valores->parametro))->bool_real.size() > 0)
   	      ((Hash*)parametro)->bool_real = ((Hash*)(valores->parametro))->bool_real;          
           if (((Hash*)(valores->parametro))->real_real.size() > 0)
   	      ((Hash*)parametro)->real_real = ((Hash*)(valores->parametro))->real_real;          
           if (((Hash*)(valores->parametro))->real_int.size() > 0)
   	      ((Hash*)parametro)->real_int = ((Hash*)(valores->parametro))->real_int;          
           if (((Hash*)(valores->parametro))->real_bool.size() > 0)
   	      ((Hash*)parametro)->real_bool = ((Hash*)(valores->parametro))->real_bool;          
           
        }

// Arranjo
	if(parametro->tipo == Tipo::arranjo && valores->parametro->tipo == Tipo::arranjo){ // copia valores de arranjo simples
	
	 memcpy(((Arranjo*)parametro)->inteiro_a, ((Arranjo*)valores->parametro)->inteiro_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*sizeof(int));   
         memcpy(((Arranjo*)parametro)->boolean_a, ((Arranjo*)valores->parametro)->real_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*sizeof(bool));
	 memcpy(((Arranjo*)parametro)->real_a, ((Arranjo*)valores->parametro)->real_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*sizeof(double));
           
	}

// Arranjo Duplo
	if(parametro->tipo == Tipo::arranjo_duplo && valores->parametro->tipo == Tipo::arranjo_duplo){ // copia valores de arranjo duplo

	memcpy(((Arranjo*)parametro)->inteiro_a, ((Arranjo*)valores->parametro)->inteiro_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*((ArranjoDuplo*)valores->parametro)->tamanho2->inteiro*sizeof(int));
	memcpy(((Arranjo*)parametro)->boolean_a, ((Arranjo*)valores->parametro)->real_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*((ArranjoDuplo*)valores->parametro)->tamanho2->inteiro*sizeof(bool));
 	memcpy(((Arranjo*)parametro)->real_a, ((Arranjo*)valores->parametro)->real_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*((ArranjoDuplo*)valores->parametro)->tamanho2->inteiro*sizeof(double));
	
	}
	
// Default
        parametro->boolean = valores->parametro->boolean;
        parametro->inteiro = valores->parametro->inteiro;
        parametro->real    = valores->parametro->real;   
        tabelaDeSimbolos->adicionar(parametro, linha, variavel);

    }

  // Caso exista um próximo parâmetro, prossegue-se acrescentando
    if(proximo != NULL) {
        return ((Parametro*)proximo)->acrescentarComValoresAoEscopo(tabelaDeSimbolos, ((Parametro*)valores->proximo), linha);
    }
}


void Parametro::recuperarEstruturaDeDados(TabelaDeSimbolos *tabelaDeSimbolos, Parametro *p, int linha){

   // Recupera-se a estrutura de dados passada como parâmetro 
     if (p->parametro->tipo == Tipo::variavel){
	 Nodo *ed = tabelaDeSimbolos->recuperar(p->parametro->id, linha, true);
	 if (ed != NULL){
	    if(ed->tipo == arranjo || ed->tipo == arranjo_duplo || ed->tipo == hash){
	 	p->parametro = ed;
	    }
         }
     }
    
  // Se houverem mais parâmetros, segue-se recuperando as estruturas de dados
     if ( ((Parametro*)(p->proximo)) != NULL)
	p->recuperarEstruturaDeDados(tabelaDeSimbolos, ((Parametro*)(p->proximo)), linha);	
}


int Parametro::contar() {
  // Conta a quantidade de parâmetros
    if(proximo == NULL) {
        return 1;
    } else {
        return (((Parametro*)proximo)->contar() + 1);
    }    
}


void Parametro::ajustarPonteiroImpressao(Parametro *p) {
    if(((Variavel*)(p->parametro))->ponteiros > 0)    
      // Ativa uma flag para impressão do parâmetro caso seja um ponteiro
        ((Variavel*)(p->parametro))->ponteiroParametro = true;

  // Segue-se para o próximo, caso exista
    if ( ((Parametro*)(p->proximo)) != NULL)
        p->ajustarPonteiroImpressao(((Parametro*)(p->proximo)));	
}    


void Parametro::imprimir(int espaco, bool naoArgumento) {
    imprimirEspaco(espaco);
    if(naoArgumento) { 

      // Tratamento especial para impressao do parâmetro Hash
	if (parametro->tipo == hash) {
	    Tipo tipoHashImpressao = Tipo::nulo;
            switch(tipoReserva) {
                case Tipo::boolean:
                    switch(tipoDoParametro) {
                        case Tipo::boolean: tipoHashImpressao = Tipo::hash_bb; break;
                        case Tipo::inteiro: tipoHashImpressao = Tipo::hash_bi; break;
                        case Tipo::real:    tipoHashImpressao = Tipo::hash_bf; break;
                        default: break;
                    } break;
                case AST::Tipo::inteiro:
                    switch(tipoDoParametro) {
                        case Tipo::boolean: tipoHashImpressao = Tipo::hash_ib; break;
                        case Tipo::inteiro: tipoHashImpressao = Tipo::hash_ii; break;
                        case Tipo::real:    tipoHashImpressao = Tipo::hash_if; break;
                        default: break;
                    } break;
                case AST::Tipo::real:
                    switch(tipoDoParametro) {
                        case Tipo::boolean: tipoHashImpressao = Tipo::hash_fb; break;
                        case Tipo::inteiro: tipoHashImpressao = Tipo::hash_fi; break;
                        case Tipo::real:    tipoHashImpressao = Tipo::hash_ff; break;
                        default: break;
                    } break;
                default: break;
            }	
            imprimirTipo(tipoHashImpressao);
        }

      // Impressão default para tipos inteiros, booleanos, floats e arranjos
        else
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

