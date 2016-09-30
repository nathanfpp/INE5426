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

enum Tipo { inteiro, real, boolean, variavel, declaracao, definicao, opUnaria, opBinaria, condicao, laco, 
            funcao_dec, funcao_def, funcao_cha, bloco, arranjo, 
            negacao, inversao, conversao_int, conversao_float, conversao_bool, parenteses,
            atribuicao, adicao, subtracao, multiplicacao, divisao, e, ou, igual, diferente, maior, maior_igual, menor, menor_igual,
            teste, nulo };

class Nodo;
class Variavel;
class Bloco;
class TabelaDeSimbolos;
class Definicao;
class OperacaoBinaria;
class Funcao;
class Parametro;

typedef std::vector<Nodo*> listaDeNodos;

class Nodo {
    public:
        Tipo tipo;
        virtual ~Nodo() {};
        virtual Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) { return Tipo::nulo; };
        virtual void imprimir(int espaco, bool novaLinha) { };
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
         Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
         void imprimir(int espaco, bool novaLinha)                             { std::cout << id << "";    };
};

class Inteiro : public Nodo {
    public:
        Tipo tipo;
        const char *valor;
    //
        Inteiro(const char *valor) : valor(valor) { tipo = Tipo::inteiro; }; 
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha)        { return Tipo::inteiro;     };
        void imprimir(int espaco, bool novaLinha)                              { std::cout << valor << ""; };
};

class Real : public Nodo {
    public:
        Tipo tipo;
        const char *valor;
    //
        Real(const char *valor) : valor(valor) { tipo = Tipo::real; };
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha)        { return Tipo::real;        }
        void imprimir(int espaco, bool novaLinha)                              { std::cout << valor << ""; };
};

class Boolean : public Nodo {
    public:
        Tipo tipo;
        const char *valor;
    //
        Boolean(const char *valor) : valor(valor) { tipo = Tipo::boolean; };
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha)        { return Tipo::boolean;                       };  
        void imprimir(int espaco, bool novaLinha)                              { std::cout << std::boolalpha << valor << ""; };
};

class Declaracao : public Nodo {
    public:
        Tipo tipo;
        Tipo tipoDeVariavel;
        Definicao *variaveis;
    //
        Declaracao(Tipo t, Tipo v, Definicao *d) : tipo(t), tipoDeVariavel(v), variaveis(d) { };
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
        void imprimir(int espaco, bool novaLinha);
};

class Definicao : public Nodo {
    public:
        Tipo tipo;
        Tipo tipoDeVariavel;
        Variavel *variavel;
        Nodo *valor;
        Definicao *proxima;
    //
        Definicao(Tipo t, Variavel *v, Nodo *c, Definicao *p) : tipo(t), variavel(v), valor(c), proxima(p) { tipoDeVariavel = Tipo::nulo; };
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
        void imprimir(int espaco, bool novaLinha);
        void ajustarProxima(Definicao *p);
};

class OperacaoUnaria : public Nodo {
    public:
        Tipo tipo;
        Tipo operacao;
        Tipo retorno;
        Nodo *filho;
    //
        OperacaoUnaria(Tipo t, Tipo o, Nodo *f) : tipo(t), operacao(o), retorno(Tipo::nulo), filho(f) { };
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
        void imprimir(int espaco, bool novaLinha);
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
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
        void imprimir(int espaco, bool novaLinha);
};

class Condicao : public Nodo {
    public:
        Tipo tipo;
        Nodo *teste;
        Bloco *se;
        Bloco *senao;
    //
        Condicao(Tipo t, Nodo *a,  Bloco *b,  Bloco *c) : tipo(t), teste(a), se(b), senao(c) {  };
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
        void imprimir(int espaco, bool novaLinha);
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
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
        void imprimir(int espaco, bool novaLinha);
};

class Funcao : public Nodo {
    public:
        Tipo tipo;
        Tipo tipoDoRetorno;
        std::string id;
        Parametro *parametros;
        Bloco *corpo;
        Nodo *retorno;
        int quantidadeDeParametros;
    //
        Funcao(Tipo t, Tipo d, std::string i, Parametro *p, Bloco *c, Nodo *r) : 
            tipo(t), tipoDoRetorno(d), id(i), parametros(p), corpo(c), retorno(r) { };
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
        void imprimir(int espaco, bool novaLinha);
        int contarParametros();
};

class Parametro : public Nodo {
    public:
        Tipo tipoDoParametro;
        Nodo *parametro;
        Parametro* proximo;
    //
      Parametro(Tipo t, Nodo *p, Parametro *r) : tipoDoParametro(t), parametro(p), proximo(r) { };
      Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
      void imprimir(int espaco, bool naoArgumento);
      bool comparar(TabelaDeSimbolos *tabelaSimbolos, Parametro *comparado, int linha);
      int contar();
};

class Arranjo : public Nodo {
    public:
        Tipo tipo;
        Tipo tipoDeVariavel;
        std::string id;
        Nodo *tamanho;
    //
        Arranjo(Tipo t, Tipo v, std::string i, Nodo *p) : tipo(t), tipoDeVariavel(v), id(i), tamanho(p) { };
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
        void imprimir(int espaco, bool novaLinha);
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
        Tipo analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha);
        void imprimir(int espaco, bool novaLinha);
        void novaLinha(Nodo *linha);
};

class TabelaDeSimbolos {
    public:
        std::map<std::string, AST::Variavel*> variaveis;    
        std::map<std::string, AST::Funcao*> funcoes;    
        TabelaDeSimbolos *anterior;
        int count;
    //
        TabelaDeSimbolos() {}
        ~TabelaDeSimbolos() { }
        TabelaDeSimbolos* novoEscopo(TabelaDeSimbolos *a);
        bool retornarEscopo();
        bool adicionarVariavel(AST::Variavel *v, int linha);
        Variavel* recuperarVariavel(std::string id, int linha);
        bool declararFuncao(AST::Funcao *f, int linha);
        Funcao* recuperarFuncao(std::string id, int linha);
};

}
#endif 
