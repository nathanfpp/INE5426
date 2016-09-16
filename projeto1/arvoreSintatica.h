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

enum TipoDeVariavel { inteiro, real, boolean };
enum Operacao       { atribuicao, adicao, subtracao, multiplicacao, divisao, e, ou, negacao, inversao, parenteses };

class Nodo;

typedef std::vector<Nodo*> listaDeNodos;

class Nodo {
    public:
        virtual ~Nodo() {}
        virtual void imprimir(){}
        virtual int computar(){return 0;}
};

/* Variáveis */

class Variavel : public Nodo {
     public:
         std::string id;
         Variavel(std::string id) : id(id) { }
         void imprimir();
         //int computar();
};

class Inteiro : public Nodo {
    public:
        const char *valor;
        //int valor;        
        Inteiro(const char *valor) : valor(valor) {  }
        void imprimir();
        //int computeTree();
};

class Real : public Nodo {
    public:
        const char *valor;
        //float valor;
        Real(const char *valor) : valor(valor) {  }
        void imprimir();
        //int computar();
};

class Boolean : public Nodo {
    public:
        const char *valor;
        //bool valor;
        Boolean(const char *valor) : valor(valor) {  }
        void imprimir();
        //int computar();
};


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

class OperacaoUnaria : public Nodo {
    public:
        Operacao operacao;
        Nodo *direita;
        OperacaoUnaria(Operacao op, Nodo *dir) : operacao(op), direita(dir) { }
        void imprimir();
        //int computar();
};


/* Bloco ou Linha */

class Bloco : public Nodo {
    public:
        listaDeNodos linhas;
        Bloco() { }
        void imprimir();
        void novaLinha(Nodo *linha);
        //int computar();
};

}

#endif 
