#include "arvoreSintatica.h"


using namespace AST;

Tipo Parametro::analisar(TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Tipos de parâmetros diferentes possuem tratamento diferenciado
    if(parametro != NULL) {
        switch(parametro->tipo) {
            case Tipo::variavel:
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
//std::cout << "@parametro : " << imprimirTipoPorExtenso(tipoComparado) << "\n";
        }

      // Ajusta o tipoDoParametro caso se trate de um arranjo ou arrranjo duplo
        if(parametro->tipo == Tipo::arranjo) {
            tipoDoParametro = tabelaDeSimbolos->tipoDeArranjo(((Variavel*)parametro)->tipoDeVariavel);
        } else if (parametro->tipo == Tipo::arranjo_duplo) {
            tipoDoParametro = tabelaDeSimbolos->tipoDeArranjoDuplo(((Variavel*)parametro)->tipoDeVariavel);
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
    }


  // Se os parâmetros atuais forem igual e os próximos forem nulos, então todos os Parâmetro são iguais
    if(proximo != NULL && comparado->proximo != NULL) {           
      // Caso contrário, compara os próximos parâmetros
        ((Parametro*)proximo)->comparar(tabelaDeSimbolos, ((Parametro*)comparado->proximo), linha, definicao, analisador);
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
  // Enquanto houver parametros acrescento-os recursivamente ao escopo e copiando os seus valores

    if(parametro != NULL && valores != NULL) {
        ((Variavel*)parametro)->tipoDeVariavel = tipoDoParametro; //copio o tipo do parametro
        if(parametro->tipo == Tipo::hash) { //recebe tipo chave e copia de valores para hash
            ((Hash*)parametro)->tipoDeChave = tipoReserva;
            
           if (((Hash*)(valores->parametro))->int_int.size() > 0)
     	   ((Hash*)parametro)->int_int.insert(((Hash*)(valores->parametro))->int_int.begin(),((Hash*)(valores->parametro))->int_int.end());

	   if (((Hash*)(valores->parametro))->int_bool.size() > 0)
           ((Hash*)parametro)->int_bool.insert(((Hash*)(valores->parametro))->int_bool.begin(),((Hash*)(valores->parametro))->int_bool.end());
           if (((Hash*)(valores->parametro))->int_real.size() > 0)
           ((Hash*)parametro)->int_real.insert(((Hash*)(valores->parametro))->int_real.begin(),((Hash*)(valores->parametro))->int_real.end());
           if (((Hash*)(valores->parametro))->bool_bool.size() > 0)
   	   ((Hash*)parametro)->bool_bool.insert(((Hash*)(valores->parametro))->bool_bool.begin(),((Hash*)(valores->parametro))->bool_bool.end());
           if (((Hash*)(valores->parametro))->bool_int.size() > 0)
           ((Hash*)parametro)->bool_int.insert(((Hash*)(valores->parametro))->bool_int.begin(),((Hash*)(valores->parametro))->bool_int.end());
           if (((Hash*)(valores->parametro))->bool_real.size() > 0)
           ((Hash*)parametro)->bool_real.insert(((Hash*)(valores->parametro))->bool_real.begin(),((Hash*)(valores->parametro))->bool_real.end());
           if (((Hash*)(valores->parametro))->real_real.size() > 0)
   	   ((Hash*)parametro)->real_real.insert(((Hash*)(valores->parametro))->real_int.begin(),((Hash*)(valores->parametro))->real_int.end());
           if (((Hash*)(valores->parametro))->real_int.size() > 0)
           ((Hash*)parametro)->real_int.insert(((Hash*)(valores->parametro))->real_bool.begin(),((Hash*)(valores->parametro))->real_bool.end());
           if (((Hash*)(valores->parametro))->real_bool.size() > 0)
           ((Hash*)parametro)->real_bool.insert(((Hash*)(valores->parametro))->real_real.begin(),((Hash*)(valores->parametro))->real_real.end());
           
        }

	if(parametro->tipo == Tipo::arranjo){ // copia valores de arranjo simples
	
	 memcpy(((Arranjo*)parametro)->inteiro_a, ((Arranjo*)valores->parametro)->inteiro_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*sizeof(int));   
         memcpy(((Arranjo*)parametro)->boolean_a, ((Arranjo*)valores->parametro)->real_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*sizeof(bool));
	 memcpy(((Arranjo*)parametro)->real_a, ((Arranjo*)valores->parametro)->real_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*sizeof(double));
           
	}

	if(parametro->tipo == Tipo::arranjo_duplo){ // copia valores de arranjo duplo

	memcpy(((Arranjo*)parametro)->inteiro_a, ((Arranjo*)valores->parametro)->inteiro_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*((ArranjoDuplo*)valores->parametro)->tamanho2->inteiro*sizeof(int));
	memcpy(((Arranjo*)parametro)->boolean_a, ((Arranjo*)valores->parametro)->real_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*((ArranjoDuplo*)valores->parametro)->tamanho2->inteiro*sizeof(bool));
 	memcpy(((Arranjo*)parametro)->real_a, ((Arranjo*)valores->parametro)->real_a, ((Arranjo*)valores->parametro)->tamanho->inteiro*((ArranjoDuplo*)valores->parametro)->tamanho2->inteiro*sizeof(double));
	
	}
	
	// tratamento default, copio valores booleanos, inteiros e floats.

        parametro->boolean = valores->parametro->boolean;
        parametro->inteiro = valores->parametro->inteiro;
        parametro->real    = valores->parametro->real;   
        tabelaDeSimbolos->adicionar(parametro, linha, variavel);
    }
    if(proximo != NULL) { //navego recursivamente para o proximo parametro se houver
        return ((Parametro*)proximo)->acrescentarComValoresAoEscopo(tabelaDeSimbolos, ((Parametro*)valores->proximo), linha);
    }
}


void Parametro::recuperarEstruturaDeDados(TabelaDeSimbolos *tabelaDeSimbolos, Parametro *p, int linha){

     // Quando estou interpretando o codigo preciso recuperar a estrutura de dados passada por parametro e armazenar no mesmo. 

     if (p->parametro->tipo == Tipo::variavel){
	 Nodo *ed = tabelaDeSimbolos->recuperar(p->parametro->id, linha, true);
	 if (ed != NULL){
	   if(ed->tipo == arranjo || ed->tipo == arranjo_duplo || ed->tipo == hash){
	 	p->parametro = ed;
	   }
        }
     }
    
     if ( ((Parametro*)(p->proximo)) != NULL) //navego recursivamente a cada parametro, enquanto houver um proximo
	p->recuperarEstruturaDeDados(tabelaDeSimbolos, ((Parametro*)(p->proximo)), linha);	
}


int Parametro::contar() { //conta o numero de parametros.
    if(proximo == NULL) {
        return 1;
    } else {
        return (((Parametro*)proximo)->contar() + 1);
    }    
}

void Parametro::ajustarPonteiroImpressao(Parametro *p) {

	if(((Variavel*)(p->parametro))->ponteiros > 0)    
	((Variavel*)(p->parametro))->ponteiroParametro = true; //insiro no parametro uma flag para impressao, caso seja um ponteiro.
	if ( ((Parametro*)(p->proximo)) != NULL) //navego recursivamente entre os parametros.
	p->ajustarPonteiroImpressao(((Parametro*)(p->proximo)));	
}    



void Parametro::imprimir(int espaco, bool naoArgumento) {
    imprimirEspaco(espaco);
    if(naoArgumento) { 

	if (parametro->tipo == hash){ // tratamento especial para impressao, caso tipo do parametro seja um hash
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
	else  //impressao default para tipos inteiros, booleanos, floats e arranjos
        imprimirTipo(tipoDoParametro);
    }
    
    std::cout << " ";
    parametro->imprimir(0,false);
    if(proximo != NULL) { //Se houver um proximo parametro, ele será imprimimido.
       if(naoArgumento) {
           std::cout << ", ";
       }
       proximo->imprimir(espaco, naoArgumento);
    }
}


