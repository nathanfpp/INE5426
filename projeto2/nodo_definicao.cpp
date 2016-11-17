#include "arvoreSintatica.h"

using namespace AST;

Tipo Definicao::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Atribui tipoDeVariavel, recebido da Declaração, à Variável
    variavel->tipoDeVariavel = tipoDeVariavel;

  // O tipo da próxima Definição que caso não exista será Tipo::nulo
    Tipo tipoDoProximo = Tipo::nulo;

  // Caso a Definição atribua um valor à Variável, realizando coerção se necessário
    if(valor != NULL) {
        Tipo tipoDoValor = valor->analisar(tabelaDeSimbolos, linha, analisador); // anteriormente após a coerção
	if((variavel->ponteiros > 0 && tipoDoValor == Tipo::endereco)==false)
             coercaoDaDefinicao(this, tipoDeVariavel, tipoDoValor, linha);        
        variavel->boolean = valor->boolean; variavel->inteiro = valor->inteiro; variavel->real = valor->real;
        boolean = valor->boolean; inteiro = valor->inteiro; real = valor->real;
    } else {
        variavel->boolean = false; variavel->inteiro = 0; variavel->real = 0.0;
        boolean = false; inteiro = 0; real = 0.0;
    }

  // Salva a Variável na Tabela de Símbolos
    if(!tabelaDeSimbolos->adicionar(variavel, linha, true)) {
      // Porém, caso a variável já tenha sido declarada, além da impressão do erro, a definição é marcada
        tipo = Tipo::nulo;
    }

  // Se outra Variável foi declarada, atribui o tipo da Declaração e inicia sua análise 
    if(proxima != NULL) {
        proxima->tipoDeVariavel = tipoDeVariavel;
	proxima->variavel->ponteiros = variavel->ponteiros;
        proxima->analisar(tabelaDeSimbolos, linha, analisador);

      // E também registra-se seu Tipo de Nodo
        tipoDoProximo = proxima->tipoDeVariavel;
    }

  // Caso o tipo desta Definição seja nulo, assim como o da próxima Definição...
    if(tipo == Tipo::nulo && tipoDoProximo == Tipo::nulo) {

      // ... isto significa que ambas as Variáveis já foram declaradas anteriormente
        return Tipo::nulo;
    }

  // Retorna o tipo do Nodo
    return Tipo::definicao;
}


void Definicao::imprimir(int espaco, bool imprimir) {

    if(tipo == definicao){
      // Caso esta seja a primeira definição após a declaração, ela imprime "var:"
        if(imprimir) {
            for(int i = 0; i < variavel->ponteiros; i++)
    	    std::cout << " ref";    
            std::cout << " var: ";
        }     

      // Imprime a definição apenas se ela for válida
        variavel->imprimir(0, false);
        if(valor != NULL) {
            std::cout << " = ";
            valor->imprimir(0, false);
        }                   
        if(proxima != NULL) std::cout << ", ";   
    }

  // Imprime a próxima definição
    if(proxima != NULL) {
        proxima->imprimir(0, false);
    }
}


void Definicao::ajustarProxima(Definicao *p) {

 // Acrescenta a definição à ultima definição até então definida
    if(proxima != NULL) {
        proxima->ajustarProxima(p);
    } else {
      proxima = p;
    }
}


