#include "arvoreSintatica.h"

using namespace AST;


Tipo Switch::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // O Tipo do switch deve ser igual para todas os casos.
    Tipo esperado = casoTratado->analisar(tabelaDeSimbolos, linha, analisador);
      if (esperado != Tipo::inteiro && esperado != Tipo::boolean && esperado != Tipo::real)
          std::cerr << "[" <<linha<<"] Semantic error: switch type needs to be an integer or boolean or float"<<"\n";
     
      Condicao *atual = casos;

    //Para cada caso analiso se o tipo do caso corresponde ao tipo esperado pelo switch
      while (atual != NULL){

	   if(atual->teste != NULL){
	   	Tipo esperado_caso = atual->teste->analisar(tabelaDeSimbolos, linha, analisador); 
 	   	if (esperado != esperado_caso){
           		imprimirErroDeOperacao(Tipo::seleciona, esperado, esperado_caso, linha);
	   	}
                else {		
		    int i = atual->teste->inteiro;
		    bool b = atual->teste->boolean;
		    double r = atual->teste->real;

                  // Se tipo do switch == tipo do caso e valor for igual do switch, então executo
		    switch (esperado){
 		        case Tipo::inteiro:
		            if (casoTratado->inteiro == i) { 
			        match = true;
			        atual->analisar(tabelaDeSimbolos, linha, analisador); 
		            }
			    break;

 		        case Tipo::boolean:
 		            if (casoTratado->boolean == b){
			        match = true;
			        atual->analisar(tabelaDeSimbolos, linha, analisador); 
		            }
		            break;

		        case Tipo::real:
		            if (casoTratado->real == r){
			        match = true;
			        atual->analisar(tabelaDeSimbolos, linha, analisador); 
		            }
		            break;

		   default: break;
		 }
	      }
	   }

      // Caso não ocorra "match" em nenhum caso, a análise default éexecutada.
	else if(match == false) 
	     atual->analisar(tabelaDeSimbolos, linha, analisador);

      // Mesmo após a execução de um caso, deve-se compilar os demais sem executá-los
        atual = atual->proximo;
    }
     
  // Retorna o tipo do nodo
    return tipo;
}


void Switch::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    std::cout << "switch: ";
    casoTratado->imprimir(espaco+2, false);  
    std::cout << "\n";
    Condicao *atual = casos;
    while (atual != NULL){
	atual->imprimir(espaco+2,false);	
	atual = atual->proximo;
    }
    imprimirEspaco(espaco);
    std::cout << "end switch \n";
}

