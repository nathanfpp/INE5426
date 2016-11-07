#include "arvoreSintatica.h"


using namespace AST;

Tipo ArranjoDuplo::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // O tipo do primeiro índice é válido?
    Tipo indice = tamanho->analisar(tabelaDeSimbolos, linha, analisador);
    if(indice != Tipo::inteiro) {
        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received ";
        std::cerr << imprimirTipoPorExtenso(indice) << "\n"; 
    }

  // O tipo do segundo índice é valido?
    indice = tamanho2->analisar(tabelaDeSimbolos, linha, analisador);
    if(indice != Tipo::inteiro) {
        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received ";
        std::cerr << imprimirTipoPorExtenso(indice) << "\n"; 
    }

  // O arranjo foi declarado?

    ArranjoDuplo *v = ((ArranjoDuplo*) tabelaDeSimbolos->recuperar(id, linha, true));
    if(v != NULL) {
/*
	memcpy(inteiro_d, v->inteiro_d,sizeof(int)*1000);
	memcpy(boolean_d, v->boolean_d,sizeof(bool)*1000);
	memcpy(real_d, v->real_d,sizeof(double)*1000);
	tamanho = v->tamanho;
	tamanho2 = v->tamanho2;
        tipoDeVariavel = v->tipoDeVariavel;
        boolean = v->boolean;
        inteiro = v->inteiro;
        real = v->real;     
*/
        return v->tipoDeVariavel;
    } else {
        std::cerr << "[Line " << linha << "] semantic error: undeclared variable " << id << "\n";
    }

  // Retorna-se o tipo
    return tipoDeVariavel;
}


void ArranjoDuplo::imprimir(int espaco, bool declaracao) {    

 // Impressão para declaração de arranjo
    if(declaracao) {
        std::cout << id << " (size: ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
        std::cout << ", ";
        if(tamanho2 != NULL) {        
            tamanho2->imprimir(0, false);
        }
        std::cout << ")";
    }

  // Impressão para uso comum
    else {
        if (ponteiros > 0 && ponteiroParametro == true){
	std::cout << "ref ";
        ponteiroParametro = false; 
    	}

        std::cout << "[index][index] " << id << " ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
        std::cout << " ";
        if(tamanho2 != NULL) {        
            tamanho2->imprimir(0, false);
        }
    }
}
