#include "arvoreSintatica.h"


using namespace AST;

Tipo Variavel::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Busca a variável na tabela de símbolos 
    Variavel *v = ((Variavel*) tabelaDeSimbolos->recuperar(id, linha, true));

  // Caso a variável seja encontrada, ela pode ser de diferentes tipos
    if(v != NULL) {
       //tipo = v->tipo;
        tipoDeVariavel = v->tipoDeVariavel;
        boolean = v->boolean;
        inteiro = v->inteiro;
        real = v->real;        

        switch(v->tipo) {
            case Tipo::arranjo:       return tabelaDeSimbolos->tipoDeArranjo(v->tipoDeVariavel);
            case Tipo::arranjo_duplo: return tabelaDeSimbolos->tipoDeArranjoDuplo(v->tipoDeVariavel);
            case Tipo::hash:          return tabelaDeSimbolos->tipoDeHash(v->tipoDeVariavel,((Hash*)v)->tipoDeChave);
            case Tipo::variavel:      return v->tipoDeVariavel;
            default:break;
        }
    }


  // Caso a variável não tenha sido declarada, retorna-se o tipoDeVariavel
    return tipoDeVariavel;
}

Tipo Variavel::obterTipoDaTabela(TabelaDeSimbolos *tabelaDeSimbolos) {
    Variavel *v = ((Variavel*) tabelaDeSimbolos->recuperar(id, -1, true));
    if(v != NULL) {
        return v->tipo;
    }
    return Tipo::nulo;
}


int Variavel::recuperarPonteiros(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {

  // Busca a variável na tabela de símbolos e, caso ele seja encontrado, retorna o número de referencias, 
    Variavel *v = ((Variavel*) tabelaDeSimbolos->recuperar(id, linha, true));
    if(v != NULL) {
        return v->ponteiros;
    }

  // Caso contrário, a variável não está na tabela de simbolos e por padrão, retorna 0
    return 0;
}


void Variavel::imprimir(int espaco, bool analisador) {

  // Impressão do analisador
    if(analisador) {
        std::cout << id << " = ";

        switch(tipo) {
            case Tipo::arranjo:
                std::cout << "array";
                return;

            case Tipo::arranjo_duplo: 
                std::cout << "double array";
                return;

            case Tipo::hash:
                std::cout << "hash";
                return;

            default: 
                switch(tipoDeVariavel) {
                    case Tipo::boolean:  std::cout << boolean << "";  return;
                    case Tipo::inteiro:  std::cout << inteiro << "";  return;
                    case Tipo::real:     std::cout << real    << "";  return;
                    default:             std::cout << "@";            return;
                }
        }    
    }

  // Impressão comum
    else {
        if(ponteiroEsqAtribuicao == true && ponteiros > 0) {
            std::cout << "[ref] "; 
        }
        if (ponteiros > 0 && ponteiroParametro == true){
	    std::cout << "ref ";
            ponteiroParametro = false; 
        }
        std::cout << id << "";
    }
}
