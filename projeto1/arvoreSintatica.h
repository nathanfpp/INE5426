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

enum Tipo { inteiro, real, boolean ,
            negacao, inversao, conversao_int, conversao_float, conversao_bool, parenteses,
            atribuicao, adicao, subtracao, multiplicacao, divisao, e, ou, igual, diferente, maior, maior_igual, menor, menor_igual,
            teste, nulo };

class NodoBase;
class Variavel;
class Bloco;


typedef std::vector<NodoBase*> listaDeNodos;

class NodoBase {
    public:
        virtual ~NodoBase() {}
        virtual void imprimir(int espaco, bool linha) {}
        virtual Tipo verificarTipo(Tipo t, Tipo operador) { return Tipo::nulo; }
        virtual void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        virtual void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo) {}
                void imprimirEspaco(int espaco);
                void imprimirTipo(Tipo t);
                void imprimirTipoPorExtenso(Tipo t);
                void imprimirErroDeOperacao(Tipo operacao, Tipo esperava, Tipo recebeu);
	//virtual void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};
	
/* Variáveis */

class Variavel : public NodoBase {
     public:
         Tipo tipo;
         std::string id;                 
     //
         Variavel(Tipo t, std::string id) : tipo(t), id(id) { };
         void imprimir(int espaco, bool linha);
         Tipo verificarTipo(Tipo t, Tipo operador) { return tipo; }
         void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos);
         void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo);
	 //void adicionarTipo(TipoDeNodo t);
	 //void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};

class Inteiro : public NodoBase {
    public:
        Tipo tipo;
        const char *valor;
    //
        Inteiro(Tipo t, const char *valor) : tipo(t), valor(valor) { };
        void imprimir(int espaco, bool linha);
	Tipo verificarTipo(Tipo t, Tipo operador) { return tipo; }
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo) {}
	//void adicionarTipo(TipoDeNodo t) {};
	//void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};

class Real : public NodoBase {
    public:
        Tipo tipo;
        const char *valor;
    //
        Real(Tipo t, const char *valor) : tipo(t), valor(valor) { };
        void imprimir(int espaco, bool inha);
        Tipo verificarTipo(Tipo t, Tipo operador) { return tipo; }
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo) {}
	//void adicionarTipo(TipoDeNodo t) {}
	//void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};

class Boolean : public NodoBase {
    public:
        Tipo tipo;
        const char *valor;
    //
        Boolean(Tipo t, const char *valor) : tipo(t), valor(valor) { };
        void imprimir(int espaco, bool linha);
	Tipo verificarTipo(Tipo t, Tipo operador) { return tipo; }
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {}
        void acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo) {}
	//void adicionarTipo(TipoDeNodo t) {}
	//void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};

class Declaracao : public NodoBase {
    public:
        Tipo tipo;
        NodoBase *variaveis;
    //
        Declaracao(Tipo t, NodoBase *d) : tipo(t), variaveis(d) { };
        void imprimir(int espaco, bool linha);
        Tipo verificarTipo(Tipo t, Tipo operador);
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo);
};

class Definicao : public NodoBase {
    public:
        Variavel *variavel;
        NodoBase *valor;
        Definicao *proxima;
    //
        Definicao(Variavel *v, NodoBase *c, Definicao *p) : variavel(v), valor(c), proxima(p) { };
        void imprimir(int espaco, bool linha);
        void ajustarProxima(Definicao *p);
        Tipo verificarTipo(Tipo t, Tipo operador);
        void verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo);
};

class OperacaoUnaria : public NodoBase {
    public:
        Tipo tipo;
        NodoBase *filho;
    //
        OperacaoUnaria(Tipo t, NodoBase *f) : tipo(t), filho(f) { };
        void imprimir(int espaco, bool linha);
	Tipo verificarTipo(Tipo t, Tipo operador);
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo);
	//void adicionarTipo(TipoDeNodo t) {}
	//void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita);        
};

class OperacaoBinaria : public NodoBase {
    public:
        Tipo tipo;
        NodoBase *esquerda;
        NodoBase *direita;
    //
        OperacaoBinaria(Tipo t, NodoBase *e, NodoBase *d) : tipo(t), esquerda(e), direita(d) { };
        void imprimir(int espaco, bool linha);
	Tipo verificarTipo(Tipo t, Tipo operador);
        bool coercaoIntParaFloat(Tipo e, Tipo d);
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo);
	//void adicionarTipo(TipoDeNodo t) {}
	//void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita); 
};

class Condicao : public NodoBase {
    public:
        NodoBase *teste;
        Bloco *se;
        Bloco *senao;
    //
        Condicao(NodoBase *a,  Bloco *b,  Bloco *c) : teste(a), se(b), senao(c) { };
        void imprimir(int espaco, bool linha);
	Tipo verificarTipo(Tipo t, Tipo operador);
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo);
	//void adicionarTipo(TipoDeNodo t) {}		
};

class Laco : public NodoBase {
    public:
        NodoBase *inicializacao;
        NodoBase *teste;
        NodoBase *iteracao;
        Bloco *laco;
    //
        Laco(NodoBase *a, NodoBase *b, NodoBase *c, Bloco *d) : inicializacao(a), teste(b), iteracao(c), laco(d) { };
        void imprimir(int espaco, bool linha);
	Tipo verificarTipo(Tipo t, Tipo operador);
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo);
	//void adicionarTipo(TipoDeNodo t) {}		
};

// Bloco ou Linha
class Bloco : public NodoBase {
    public:
        listaDeNodos linhas;
        Bloco() { }
    //
        void imprimir(int espaco, bool linha);
        void novaLinha(NodoBase *linha);
	Tipo verificarTipo(Tipo t, Tipo operador);
        void verificarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos);
        void acrescentarSimbolos(std::map<std::string, Variavel*> &tabela_simbolos, AST::Tipo ultimoTipo);
	//void adicionarTipo(TipoDeNodo t) {}
	//void verificarTipoRaiz(TipoDeNodo esquerda, TipoDeNodo direita){}		
};


}

#endif 
