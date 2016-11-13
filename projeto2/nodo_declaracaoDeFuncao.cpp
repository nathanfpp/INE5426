#include "arvoreSintatica.h"

using namespace AST;

Tipo Funcao::analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) {

  // Conta a quantidade de parâmetros: se não houver parâmetros a quantidade é 0
    contarParametros();

  // Analisa parâmetros
    if(parametros != NULL) {
        parametros->analisar(tabelaDeSimbolos, linha, analisador);
    }

  // Adiciona-se a função à tabela de funções, caso já não tenha sido definida anteriormente
    definida = false;
    Funcao *f = ((Funcao*) tabelaDeSimbolos->recuperar(id, -1, false));
    if(f == NULL) {
        tabelaDeSimbolos->adicionar(this, linha, false);
    } else {
        std::cerr << "[Line " << linha << "] semantic error: re-declaration of function " << f->id << "\n"; 
    }        

  // Retorna-se o tipo
    return tipo;

}



int Funcao::contarParametros() {
    if(parametros == NULL) {
        quantidadeDeParametros = 0;
    } else {
        quantidadeDeParametros = ((Parametro*)parametros)->contar();
    }    
    return quantidadeDeParametros;
}

