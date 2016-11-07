#include "arvoreSintatica.h"


using namespace AST;

Tipo Interpretador::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {
    raiz->analisar(tabelaDeSimbolos, linha, true);
    inteiro = raiz->inteiro;
    real = raiz->real;
    boolean = raiz->boolean;
    return Tipo::interpretador;
}


void Interpretador::imprimir(int espaco, bool novaLinha) { 

  // Preparo...
    std::cout << "$ R: ";
    Tipo tipoDeVariavel;

  // Coleta o tipoDeVariavel da raiz
    switch(raiz->tipo) {
        case Tipo::opUnaria:   tipoDeVariavel = ((OperacaoUnaria*)raiz)->tipoDoRetorno;  break;
        case Tipo::opBinaria:  tipoDeVariavel = ((OperacaoBinaria*)raiz)->tipoDoRetorno; break;
        case Tipo::funcao_cha: tipoDeVariavel = ((Funcao*)raiz)->tipoDoRetorno;          break;
        case Tipo::arranjo:    
        case Tipo::arranjo_duplo:
        case Tipo::hash:
        case Tipo::variavel:   tipoDeVariavel = ((Variavel*)raiz)->tipoDeVariavel;       
                               std::cout << raiz->id << " = ";                           break;
        default:               tipoDeVariavel = Tipo::nulo;                              break;
    }

  // Imprime o valor do tipo apropriado
    switch(tipoDeVariavel) {
        case Tipo::inteiro:  std::cout                   << inteiro << "";  break;
        case Tipo::real:     std::cout                   << real    << "";  break;
        case Tipo::boolean:  std::cout << std::boolalpha << boolean << "";  break;
        default:             std::cout <<                             "?";  break;        
    }

  // Término
    std::cout << "\n";    
}
