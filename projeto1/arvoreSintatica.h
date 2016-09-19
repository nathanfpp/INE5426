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
enum TipoDeNodo     { inteiro, real, boolean, atomica, adicao, subtracao, multiplicacao, divisao, e, ou, negacao, inversao, x, semTipo };

class NodoBase;
class Variavel;

typedef std::vector<NodoBase*> listaDeNodos;

class NodoBase {
    public:

        virtual ~NodoBase() {}
        virtual void imprimir() {}
        virtual void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        virtual void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {}
        virtual void verificarTipo(TipoDeNodo t, TipoDeNodo operador){}
        virtual void adicionarTipo(TipoDeNodo t){}

};

/* Variáveis */

class Variavel : public NodoBase {
     public:
         TipoDeNodo tipo; //o tipo de nodo da variavel será equivalente ao aquilo lhe foi atribuído e posteriormente comparado com o tipo declarados
         std::string id;
         Variavel(std::string id, TipoDeNodo t) : id(id), tipo(t) { }
         void imprimir();
         void verificarTipo(TipoDeNodo t, TipoDeNodo operador);
         void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos);
         void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo);
	 void adicionarTipo(TipoDeNodo t);
         //int computar();
};

class Inteiro : public NodoBase {
    public:
        TipoDeNodo tipo;
        const char *valor;
        //int valor;        
        Inteiro(const char *valor, TipoDeNodo t) : valor(valor), tipo(t) {  }
        void imprimir();
	void verificarTipo(TipoDeNodo t, TipoDeNodo operador);
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {}
	void adicionarTipo(TipoDeNodo t) {}
        //int computeTree();
};

class Real : public NodoBase {
    public:
        TipoDeNodo tipo;
        const char *valor;
        //float valor;
        Real(const char *valor, TipoDeNodo t) : valor(valor), tipo(t) {  }
        void imprimir();
	void verificarTipo(TipoDeNodo t, TipoDeNodo operador);
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {}
	void adicionarTipo(TipoDeNodo t) {}
        //int computar();
};

class Boolean : public NodoBase {
    public:
        TipoDeNodo tipo;
        const char *valor;
        //bool valor;
        Boolean(const char *valor,TipoDeNodo t) : valor(valor), tipo(t){  }
        void imprimir();
	void verificarTipo(TipoDeNodo t, TipoDeNodo operador);
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {}
	void adicionarTipo(TipoDeNodo t) {}
        //int computar();
};


class Nodo : public NodoBase {
    public:
        TipoDeNodo tipo;
        NodoBase *esquerda;
        NodoBase *direita;
        NodoBase *proximo;
        ClasseDeNodo classe;
        Nodo(NodoBase *e,NodoBase *d,NodoBase *p, ClasseDeNodo c, TipoDeNodo t) : esquerda(e), direita(d), proximo(p), classe(c), tipo(t) { }
        void imprimir();
        void imprimirDireita();
        void imprimirEsquerda();
        void imprimirProximo();
	void verificarTipo(TipoDeNodo t, TipoDeNodo operador);
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo);
	void adicionarTipo(TipoDeNodo t) {}
};


// Bloco ou Linha

class Bloco : public NodoBase {
    public:
        listaDeNodos linhas;
        Bloco() { }
        void imprimir();
        void novaLinha(NodoBase *linha);
	void verificarTipo(TipoDeNodo t, TipoDeNodo operador) {}
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {}
	void adicionarTipo(TipoDeNodo t) {}
        //int computar();
};

}

#endif 
