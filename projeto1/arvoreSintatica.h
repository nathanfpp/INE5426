// Adaptado de https://github.com/llpilla/compiler_examples/blob/master/simple_ast/ast.h

#ifndef ARVORESINTATICA_H
#define ARVORESINTATICA_H

#pragma once

#include "arvoreSintatica.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <map>

extern void yyerror(const char *s, ...);

namespace AST {

enum Tipo { inteiro, real, boolean, variavel, declaracao, definicao, opUnaria, opBinaria, condicao, laco, funcao, bloco,
            negacao, inversao, conversao_int, conversao_float, conversao_bool, parenteses,
            atribuicao, adicao, subtracao, multiplicacao, divisao, e, ou, igual, diferente, maior, maior_igual, menor, menor_igual,
            teste, nulo };

class Nodo;
class Variavel;
class Bloco;
class TabelaDeSimbolos;
class Definicao;
class OperacaoBinaria;

typedef std::vector<Nodo*> listaDeNodos;

class Nodo {
    public:
        Tipo tipo;
        virtual ~Nodo() {}
        virtual void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha) {}
        virtual Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) { return Tipo::nulo; }
                bool coercaoDaDefinicao(Definicao *coagido, Tipo esperado, Tipo recebido, int linha);
                bool coercao(OperacaoBinaria *coeagido, Tipo e, Tipo d, int linha);
                void imprimirEspaco(int espaco);
                void imprimirTipo(Tipo t);
                std::string imprimirTipoPorExtenso(Tipo t);
                void imprimirErroDeOperacao(Tipo operacao, Tipo esperava, Tipo recebeu, int linha);
	//virtual void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};
	
/* Variáveis */

class Variavel : public Nodo {
     public:
         Tipo tipo;
         std::string id;                 
     //
         Variavel(Tipo t, std::string id) : tipo(t), id(id) { };
         void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool atribuicao);
         Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha);
};

class Inteiro : public Nodo {
    public:
        Tipo tipo;
        const char *valor;
    //
        Inteiro(const char *valor) : valor(valor) { tipo = Tipo::inteiro; };
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
	Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) { return Tipo::inteiro; }
};

class Real : public Nodo {
    public:
        Tipo tipo;
        const char *valor;
    //
        Real(const char *valor) : valor(valor) { tipo = Tipo::real; };
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
        Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) { return Tipo::real; }
};

class Boolean : public Nodo {
    public:
        Tipo tipo;
        const char *valor;
    //
        Boolean(const char *valor) : valor(valor) { tipo = Tipo::boolean; };
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
	Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha) { return Tipo::boolean; }
};

class Declaracao : public Nodo {
    public:
        Tipo tipo;
        Tipo tipoDeVariavel;
        Nodo *variaveis;
    //
        Declaracao(Tipo t, Tipo v, Nodo *d) : tipo(t), tipoDeVariavel(v), variaveis(d) { };
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
        Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha);
};

class Definicao : public Nodo {
    public:
        Tipo tipo;
        Variavel *variavel;
        Nodo *valor;
        Definicao *proxima;
    //
        Definicao(Tipo t, Variavel *v, Nodo *c, Definicao *p) : tipo(t), variavel(v), valor(c), proxima(p) { };
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
        void ajustarProxima(Definicao *p);
        Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha);
};

class OperacaoUnaria : public Nodo {
    public:
        Tipo tipo;
        Tipo operacao;
        Tipo retorno;
        Nodo *filho;
    //
        OperacaoUnaria(Tipo t, Tipo o, Nodo *f) : tipo(t), operacao(o), retorno(Tipo::nulo), filho(f) { };
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
	Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha);
};

class OperacaoBinaria : public Nodo {
    public:
        Tipo tipo;
        Tipo operacao;
        Tipo retorno;
        Nodo *esquerda;
        Nodo *direita;
    //
        OperacaoBinaria(Tipo t, Tipo o, Nodo *e, Nodo *d) : tipo(t), operacao(o), retorno(Tipo::nulo), esquerda(e), direita(d) { };
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
	Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha);
};

class Condicao : public Nodo {
    public:
        Tipo tipo;
        Nodo *teste;
        Bloco *se;
        Bloco *senao;
    //
        Condicao(Tipo t, Nodo *a,  Bloco *b,  Bloco *c) : tipo(t), teste(a), se(b), senao(c) {  };
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
	Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha);
};

class Laco : public Nodo {
    public:
        Tipo tipo;
        Nodo *inicializacao;
        Nodo *teste;
        Nodo *iteracao;
        Bloco *laco;
    //
        Laco(Tipo t, Nodo *a, Nodo *b, Nodo *c, Bloco *d) : tipo(t), inicializacao(a), teste(b), iteracao(c), laco(d) { };
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
	Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha);
};

class Funcao : public Nodo {
    public:
        Tipo tipo;
        Tipo retorno;
        std::string id;
        Nodo *parametros;
        Bloco *corpo;
    //
        Funcao(Tipo t, Tipo r, std::string i, Nodo *p, Bloco *c) : tipo(t), retorno(r), id(i), parametros(p), corpo(c) { };
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
        Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha);
};

// Bloco ou Linha
class Bloco : public Nodo {
    public:
        Tipo tipo;
        listaDeNodos linhas;
        TabelaDeSimbolos *escopo;
    //
        Bloco(Tipo t) : tipo(t) {} ; // Construtor para um Bloco de linhas comum
        Bloco(Tipo t, TabelaDeSimbolos *s) : tipo(t), escopo(s) { }; // Construtor para o Bloco principal, a Árvore Sintática
        void imprimir(AST::TabelaDeSimbolos *tabelaSimbolos, int espaco, int linha, bool novaLinha);
        void novaLinha(Nodo *linha);
	Tipo verificarTipo(AST::TabelaDeSimbolos *tabelaSimbolos, Tipo t, Tipo operador, int linha);
};

class TabelaDeSimbolos {
    public:
        bool principal;
        std::map<std::string, AST::Variavel*> variaveis;    
        //std::map<std::string, AST::Funcao*> funcoes;    
        TabelaDeSimbolos *anterior;
    //
        TabelaDeSimbolos() { principal = true; }
        ~TabelaDeSimbolos() { }
        TabelaDeSimbolos* novoEscopo();
        bool retornarEscopo();
        void adicionarVariavel(AST::Variavel *v, int linha);
        Variavel* recuperarVariavel(std::string id, int linha);
        //void novaFuncao(Funcao *f);
        //bool funcaoDeclarada(std::string id);
};


}

#endif 
