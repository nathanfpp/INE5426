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

<<<<<<< HEAD
class Variavel : public NodoBase {
=======
class Variavel : public Nodo {
>>>>>>> 87ade1c4dda2f74821bf776e4bc02de0b2ef19af
     public:
         std::string id;
         Variavel(std::string id) : id(id) { }
         void imprimir();
         void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos);
         void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos);
         //int computar();
};

<<<<<<< HEAD
class Inteiro : public NodoBase {
=======
class Inteiro : public Nodo {
>>>>>>> 87ade1c4dda2f74821bf776e4bc02de0b2ef19af
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

<<<<<<< HEAD
=======

/* Definição de Variáveis */

class Atribuicao : public Nodo {
     public:
         Variavel *esquerda;
         Nodo *direita;
         Atribuicao *proximo;
         Atribuicao(Variavel *esq, Nodo *dir, Atribuicao *prox) : esquerda(esq), direita(dir), proximo(prox) { }
         void imprimir();
         void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
         void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
         //int computar();
};

class Declaracao : public Nodo {
    public:
        TipoDeVariavel tipo;
        Nodo *direita;
        Declaracao(TipoDeVariavel tipo, Nodo *direita) : tipo(tipo), direita(direita) { }
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
        void imprimir();
        //int computar();
};


/* Operações */

class OperacaoBinaria : public Nodo {
    public:
        Nodo *esquerda;        
        Operacao operacao;
        Nodo *direita;
        OperacaoBinaria(Nodo *esq, Operacao op, Nodo *dir) : esquerda(esq), operacao(op), direita(dir) { }
        void imprimir();
        //int computar();
};
>>>>>>> 87ade1c4dda2f74821bf776e4bc02de0b2ef19af

class Nodo : public NodoBase {
    public:
<<<<<<< HEAD
        NodoBase *esquerda;
        NodoBase *direita;
        NodoBase *proximo;
        ClasseDeNodo classe;
        TipoDeNodo tipo;
        Nodo(NodoBase *e,NodoBase *d,NodoBase *p, ClasseDeNodo c, TipoDeNodo t) : esquerda(e), direita(d), proximo(p), classe(c), tipo(t) { }
=======
        Operacao operacao;
        Nodo *direita;
        OperacaoUnaria(Operacao op, Nodo *dir) : operacao(op), direita(dir) { }
>>>>>>> 87ade1c4dda2f74821bf776e4bc02de0b2ef19af
        void imprimir();
        void imprimirDireita();
        void imprimirEsquerda();
        void imprimirProximo();
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
};


<<<<<<< HEAD
// Bloco ou Linha

class Bloco : public NodoBase {
=======
/* Bloco ou Linha */

class Bloco : public Nodo {
>>>>>>> 87ade1c4dda2f74821bf776e4bc02de0b2ef19af
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
