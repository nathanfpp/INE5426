#include "arvoreSintatica.h"


using namespace AST;

Tipo Interpretador::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {
    if (analisador)
        raiz->analisar(tabelaDeSimbolos, linha, true);
    inteiro = raiz->inteiro;
    real = raiz->real;
    boolean = raiz->boolean;
    return Tipo::interpretador;
}


void Interpretador::imprimir(int espaco, bool novaLinha) { 

  // Preparo...
    imprimirEspaco(espaco);
    std::cout << "$ R: ";
    Tipo tipoDeVariavel;

  // Coleta o tipoDeVariavel da raiz
    switch(raiz->tipo) {
        case Tipo::opUnaria:
            tipoDeVariavel = ((OperacaoUnaria*)raiz)->tipoDoRetorno;
            break;
        case Tipo::opBinaria:
            tipoDeVariavel = ((OperacaoBinaria*)raiz)->tipoDoRetorno;
            break;
        case Tipo::funcao_cha:
            tipoDeVariavel = ((Chamada*)raiz)->tipoDoRetorno;
            break;
        case Tipo::arranjo:        
        case Tipo::hash:
	    switch(((Parametro*)((Chamada*)raiz)->parametros)->parametro->tipo){
	       case Tipo::inteiro:
            	    std::cout << raiz-> id << "(" << ((Parametro*)((Chamada*)raiz)->parametros)->parametro->inteiro << ") = ";
	       break;
	       case Tipo::boolean:
            	    std::cout << raiz-> id << "(" <<std::boolalpha<< ((Parametro*)((Chamada*)raiz)->parametros)->parametro->boolean << ") = ";
	       break;
	       case Tipo::real:
                    std::cout << raiz-> id << "(" << ((Parametro*)((Chamada*)raiz)->parametros)->parametro->real << ") = ";
	       break;
	       default: break;
	    }
            tipoDeVariavel = ((Chamada*)raiz)->tipoDoRetorno;
            break;
        case Tipo::arranjo_duplo:
            std::cout << raiz-> id << "(" << ((Parametro*)((Chamada*)raiz)->parametros)->parametro->inteiro << ",";
            std::cout << ((Parametro*)((Parametro*)((Chamada*)raiz)->parametros)->proximo)->parametro->inteiro << ") = ";
            tipoDeVariavel = ((Chamada*)raiz)->tipoDoRetorno;
            break;
        case Tipo::variavel:       tipoDeVariavel = ((Variavel*)raiz)->tipoDeVariavel;       
                                   std::cout << raiz->id << " = ";                            break;
        default:                   tipoDeVariavel = Tipo::nulo;                               break;
    }

  // Imprime o valor do tipo apropriado
    switch(tipoDeVariavel) {
        case Tipo::inteiro:  std::cout                    << inteiro << "";  break;
        case Tipo::real:     std::cout                    << real    << "";  break;
        case Tipo::boolean:  std::cout << std::boolalpha  << boolean << "";  break;
        default:             std::cout                              << "?";  break;        
    }

  // Término
    std::cout << "\n";    
}
