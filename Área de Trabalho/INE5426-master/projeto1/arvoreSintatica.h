// Adaptado de https://github.com/llpilla/compiler_examples/blob/master/simple_ast/ast.h

#ifndef ARVORESINTATICA_H
#define ARVORESINTATICA_H

#pragma once

#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <map>

extern void yyerror(const char *s, ...);

namespace AST {

enum ClasseDeNodo   { declaracao, atribuicao, operacaoBinaria, operacaoUnaria, parenteses };
enum TipoDeNodo     { inteiro, real, boolean, atomica, adicao, subtracao, multiplicacao, divisao, e, ou, negacao, inversao, igual, diferente, maior, maior_igual, menor, menor_igual, x, semTipo };

class NodoBase;
class Variavel;

typedef std::vector<NodoBase*> listaDeNodos;

class NodoBase {
    public:
        virtual ~NodoBase() {}
        virtual void imprimir() {}
        virtual void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        virtual void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {}
        virtual TipoDeNodo verificarTipo(TipoDeNodo t, TipoDeNodo operador){ return TipoDeNodo::x;}
        virtual void adicionarTipo(TipoDeNodo t){}
                void imprimirTipo(TipoDeNodo t);
	virtual void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};
	
/* Variáveis */

class Variavel : public NodoBase {
     public:
         TipoDeNodo tipo; // o tipo de cariável que for atribuido ao Nodo
         std::string id;
     //
         Variavel(std::string id, TipoDeNodo t) : id(id), tipo(t) { }
         void imprimir();
         TipoDeNodo verificarTipo(TipoDeNodo t, TipoDeNodo operador);
         void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos);
         void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo);
	 void adicionarTipo(TipoDeNodo t);
	 void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};

class Inteiro : public NodoBase {
    public:
        TipoDeNodo tipo;
        const char *valor;
        Inteiro(const char *valor, TipoDeNodo t) : valor(valor), tipo(t) {  }
    //
        void imprimir();
	TipoDeNodo verificarTipo(TipoDeNodo t, TipoDeNodo operador);
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {}
	void adicionarTipo(TipoDeNodo t) {};
	void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};

class Real : public NodoBase {
    public:
        TipoDeNodo tipo;
        const char *valor;
    //
        Real(const char *valor, TipoDeNodo t) : valor(valor), tipo(t) {  }
        void imprimir();
        TipoDeNodo verificarTipo(TipoDeNodo t, TipoDeNodo operador);
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {}
	void adicionarTipo(TipoDeNodo t) {}
	void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};

class Boolean : public NodoBase {
    public:
        TipoDeNodo tipo;
        const char *valor;
    //
        Boolean(const char *valor,TipoDeNodo t) : valor(valor), tipo(t){  }
        void imprimir();
	TipoDeNodo verificarTipo(TipoDeNodo t, TipoDeNodo operador);
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {}
	void adicionarTipo(TipoDeNodo t) {}
	void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};


class Nodo : public NodoBase {
    public:
        TipoDeNodo tipo;
        NodoBase *esquerda;
        NodoBase *direita;
        NodoBase *proximo;
        ClasseDeNodo classe;
    //
        Nodo(NodoBase *e,NodoBase *d,NodoBase *p, ClasseDeNodo c, TipoDeNodo t) : esquerda(e), direita(d), proximo(p), classe(c), tipo(t) { }
        void imprimir();
        void imprimirDireita();
        void imprimirEsquerda();
        void imprimirProximo();
	TipoDeNodo verificarTipo(TipoDeNodo t, TipoDeNodo operador);
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo);
	void adicionarTipo(TipoDeNodo t) {}
	void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita);		
};


// Bloco ou Linha
class Bloco : public NodoBase {
    public:
        listaDeNodos linhas;
        Bloco() { }
    //
        void imprimir();
        void novaLinha(NodoBase *linha);
	TipoDeNodo verificarTipo(TipoDeNodo t, TipoDeNodo operador) { return TipoDeNodo::x;}
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {}
	void adicionarTipo(TipoDeNodo t) {}
	void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
        //int computar();
};

}

#endif 
