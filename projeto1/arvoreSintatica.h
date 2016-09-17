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
enum TipoDeNodo     { inteiro, real, boolean, atomica, adicao, subtracao, multiplicacao, divisao, e, ou, negacao, inversao, x };

class NodoBase;
class Variavel;

typedef std::vector<NodoBase*> listaDeNodos;

class NodoBase {
    public:
        virtual ~NodoBase() {}
        virtual void imprimir() {}
        virtual void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        virtual void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
};

/* Variáveis */

class Variavel : public NodoBase {
     public:
         std::string id;
         Variavel(std::string id) : id(id) { }
         void imprimir();
         void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos);
         void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos);
         //int computar();
};

class Inteiro : public NodoBase {
    public:
        const char *valor;
        //int valor;        
        Inteiro(const char *valor) : valor(valor) {  }
        void imprimir();
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        //int computeTree();
};

class Real : public NodoBase {
    public:
        const char *valor;
        //float valor;
        Real(const char *valor) : valor(valor) {  }
        void imprimir();
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        //int computar();
};

class Boolean : public NodoBase {
    public:
        const char *valor;
        //bool valor;
        Boolean(const char *valor) : valor(valor) {  }
        void imprimir();
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        //int computar();
};


class Nodo : public NodoBase {
    public:
        NodoBase *esquerda;
        NodoBase *direita;
        NodoBase *proximo;
        ClasseDeNodo classe;
        TipoDeNodo tipo;
        Nodo(NodoBase *e,NodoBase *d,NodoBase *p, ClasseDeNodo c, TipoDeNodo t) : esquerda(e), direita(d), proximo(p), classe(c), tipo(t) { }
        void imprimir();
        void imprimirDireita();
        void imprimirEsquerda();
        void imprimirProximo();
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
};


// Bloco ou Linha

class Bloco : public NodoBase {
    public:
        listaDeNodos linhas;
        Bloco() { }
        void imprimir();
        void novaLinha(NodoBase *linha);
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos) {}
        //int computar();
};

}

#endif 
