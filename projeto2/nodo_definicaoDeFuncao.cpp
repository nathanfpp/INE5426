#include "arvoreSintatica.h"


using namespace AST;

Tipo DefinicaoDeFuncao::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Conta a quantidade de parâmetros: se não houver parâmetros a quantidade é 0
    definida = true;
    Funcao::contarParametros();

  // Definição ou Chamada de Função
    TabelaDeSimbolos *novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);

// Caso a função já tenha sido declarada, deve-se comparar os parâmetros da definição com a declaração //
    Funcao *f = ((Funcao*) tabelaDeSimbolos->recuperar(id, -1, false));

// Definição de Função após Declaração
    if(f != NULL) {

    // Caso a função já tenha sido DEFINIDA anterioremente, imprime-se um erro
        if(f->definida) {
            tipo = Tipo::nulo;
            std::cerr << "[Line " << linha << "] semantic error: re-definition of function " << f->id << "\n"; 
            return f->tipoDoRetorno;
        }

      // Define a função DECLARADA como DEFINIDA
        f->definida = true;

      // Compara tipo de retorno declarado com tipo de retorno definido.
	if(tipoDoRetorno != f->tipoDoRetorno) {
            std::cerr << "[Line " << linha << "] semantic error: function " << id;
            std::cerr << " definition return type expects " << imprimirTipoPorExtenso(f->tipoDoRetorno);
            std::cerr << " but received " << imprimirTipoPorExtenso(tipoDoRetorno) << "\n";
        }

      // Obtem a quantidade de parametros da Funcao encontrada na Tabela de Símbolos
        int quantidadeEsperada = f->contarParametros();

      // Se a quantidade de parametros for diferente, ocorre um erro semantico
        if(quantidadeDeParametros != quantidadeEsperada) {
            std::cerr << "[Line " << linha << "] semantic error: function " << id;
            std::cerr << " expects " << quantidadeEsperada << " parameters";
            std::cerr << " but received " << quantidadeDeParametros << "\n";
        }

      // Se os parametros nao forem nulos, eles podem ser comparados
        else if(parametros != NULL) {     
            ((Parametro*)f->parametros)->comparar(novoEscopo, ((Parametro*)parametros), linha, true, analisador);
        }

      // Instancia o tipo a ser retornado pela função
        Tipo tipoRetornado;

      // Se o corpo da Funcao nao for nulo, ele deve ser analisado
        if(corpo != NULL) {                  
            tipoRetornado = corpo->analisar(novoEscopo, linha, false);
        }
	else{
	    tipoRetornado = retorno->analisar(novoEscopo, linha, false);
	}

      // Compara o retorno do bloco com o tipo do retorno da Função
        if(tipoDoRetorno != tipoRetornado) {
            std::cerr << "[Line " << linha << "] semantic error: return of function " << id;
            std::cerr << " expected " << imprimirTipoPorExtenso(tipoDoRetorno);
            std::cerr << " but received " << imprimirTipoPorExtenso(tipoRetornado) << "\n";
        }

      // Atribui o tipo da funcao definida a� declaracao ou chamada
        tipoDoRetorno = f->tipoDoRetorno;

      // Retorna ao escopo anterior a Funcao
        novoEscopo->retornarEscopo(linha);    
    
      // Substitui a declaração pela definicao na tabela de símbolos
        tabelaDeSimbolos->remover(id);
        tabelaDeSimbolos->adicionar(this, linha, false);

      // Retorna o tipo da variável retornada pela função
        return tipoDoRetorno;
    }

//
// Caso a funcaoo nao tenha sido declarada, não há necessidade de comparar os parametros //
    if(parametros != NULL) {                
        ((Parametro*) parametros)->acrescentarAoEscopo(novoEscopo, linha);
    }

  // Se o corpo da Função não for nulo, ele deve ser analisado
    Tipo tipoRetornado;
    if(corpo != NULL) {                  
        tipoRetornado = corpo->analisar(novoEscopo, linha, false);
     }
    else{
	tipoRetornado = retorno->analisar(novoEscopo, linha, false);
     }

        
  // Compara o retorno do bloco com o tipo do retorno da Função
    if(tipoDoRetorno != tipoRetornado) {
        std::cerr << "[Line " << linha << "] semantic error: return of function " << id;
        std::cerr << " expected " << imprimirTipoPorExtenso(tipoDoRetorno);
        std::cerr << " but received " << imprimirTipoPorExtenso(tipoRetornado) << "\n";
    }

   // Retorna ao escopo anterior a Função
    novoEscopo->retornarEscopo(linha);    

  // Adiciona a função à tabela de símbolos
    tabelaDeSimbolos->adicionar(this, linha, false);
    return tipo;    
};


Tipo DefinicaoDeFuncao::executar(AST::TabelaDeSimbolos *tabelaDeSimbolos, Parametro *valores, int linha, bool analisador) {

// nao e possivel executar funcao que nao foi definida
    if(definida) {

      // Cria um novo escopo para a execucao da funcao
        TabelaDeSimbolos *novoEscopo = tabelaDeSimbolos->novoEscopo(tabelaDeSimbolos);

      // Acrescenta os valores dos parametros a� chamada da funcao
        if(parametros != NULL) {
            ((Parametro*)parametros)->acrescentarComValoresAoEscopo(novoEscopo, valores, linha);
        }

      // Obtém o retorno da função
        if(corpo != NULL) {
            corpo->analisar(novoEscopo, linha, true);
        } else {
            retorno->analisar(novoEscopo, linha, true); 
	}

	// Recupero estrutura de dados se for o caso
	if((((Retorno*)retorno)->retorno)->tipo == Tipo::variavel){
	    Nodo *ed = novoEscopo->recuperar((((Retorno*)retorno)->retorno)->id,linha,true);
	    if (ed != NULL) {
	        ((Retorno*)retorno)->retorno = ed;
            }
	}
        boolean = retorno->boolean;
        inteiro = retorno->inteiro;
        real    = retorno->real;             

//std::cerr << "@DefinicaoDeFuncao::executar : retorno->inteiro " << retorno->inteiro << "\n";


      // Retorna ao escopo anterior a Função
        novoEscopo->retornarEscopo(linha);

    }

 // Retorna o tipo da variável retornada pela função
  return tipoDoRetorno;

};




void DefinicaoDeFuncao::imprimir(int espaco, bool novaLinha) {
    if(tipo == Tipo::funcao_def){
        imprimirEspaco(espaco);
        imprimirTipo(tipoDoRetorno);
        std::cout << " fun: " << id << " (params: ";
        if(parametros != NULL) { // se parametro for ponteiro, sofre ajuste para imprimi-lo
            ((Parametro*)parametros)->ajustarPonteiroImpressao(((Parametro*)parametros));
            parametros->imprimir(0, true);
        }
        std::cout << ")\n";
        if(corpo != NULL) {
                corpo->imprimir(espaco+2, true);
        }
        std::cout << "\n";
    }
};

