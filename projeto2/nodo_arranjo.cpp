#include "arvoreSintatica.h"

using namespace AST;


Tipo Arranjo::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // O tipo usado como índice é válido?
    Tipo indice = tamanho->analisar(tabelaDeSimbolos, linha, analisador);
    if(indice != Tipo::inteiro) {
        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received ";
        std::cerr << imprimirTipoPorExtenso(indice) << "\n"; 
    }

  // O arranjo foi declarado?
    Arranjo *v = ((Arranjo*) tabelaDeSimbolos->recuperar(id, linha, true));
    if(v != NULL) {

/* Cópia dos valores dos arranjos. Não utilizado.
	memcpy(inteiro_a, v->inteiro_a,sizeof(v->inteiro_a));
	memcpy(boolean_a, v->boolean_a,sizeof(v->boolean_a));
	memcpy(real_a, v->real_a,sizeof((v->real_a));
	tamanho = v->tamanho;
        tipoDeVariavel = v->tipoDeVariavel;
        boolean = v->boolean;
        inteiro = v->inteiro;
        real = v->real;        
*/

      // Retorna-se ao tipo da variável da tabela
        return v->tipoDeVariavel;
    }

  // Caso contrário, erro semântico
    else {
        std::cerr << "[Line " << linha << "] semantic error: undeclared variable " << id << "\n";
    }

  // Retorna o tipo
    return tipoDeVariavel;
}


void Arranjo::imprimir(int espaco, bool declaracao) {    

  // Impressão para declaração de arranjo
    if(declaracao) {	
        std::cout << id << " (size: ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
        std::cout << ")";
    }

  // Impressão para uso comum
    else {
	if (ponteiros > 0 && ponteiroParametro == true){
	std::cout << "ref ";
        ponteiroParametro = false; 
        }
        std::cout << "[index] " << id << " ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
    }
}

