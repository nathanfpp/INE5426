// Função retornando tipo errado : a(0) é detectado como variávei "a"
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

enum Tipo { inteiro, real, boolean, variavel, hash, arranjo_b, arranjo_i, arranjo_f, arranjo_2_b, arranjo_2_i, arranjo_2_f,
            hash_bb, hash_bi, hash_bf, hash_ib, hash_ii, hash_if, hash_fb, hash_fi, hash_ff,
            declaracao, declaracao_hash, definicao, definicao_arranjo, definicao_hash,
            opUnaria, opBinaria, opTernaria, condicao, retorno,
            for_laco, do_while_laco, while_laco,
            funcao_dec, funcao_def, funcao_cha, bloco, arranjo, arranjo_duplo, parametro,
            negacao, inversao, conversao_int, conversao_float, conversao_bool, parenteses, referencia, endereco,
            atribuicao, adicao, subtracao, multiplicacao, divisao, e, ou, igual, diferente, maior, maior_igual, menor, menor_igual,
            teste, condicao_atribuicao, atribuicao_condicional, nulo };

class Nodo;
class Variavel;
class Bloco;
class TabelaDeSimbolos;
class Definicao;
class OperacaoBinaria;
class Funcao;
class Parametro;
class Arranjo;
class Retorno;

typedef std::vector<Nodo*> listaDeNodos;

class Nodo {
    public:
        Tipo tipo;
        std::string id;
        Nodo(Tipo t, std::string i) : tipo(t), id(i) { };
        virtual ~Nodo() {};
        virtual Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) { return Tipo::nulo; };
	virtual int recuperarPonteiros(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {return 0;}
        virtual void imprimir(int espaco, bool novaLinha) { std::cout << id << ""; }
                bool coercaoDaDefinicao(Definicao *coagido, Tipo esperado, Tipo recebido, int linha);
                bool coercao(OperacaoBinaria *coagido, Tipo e, Tipo d, int linha);
                void imprimirEspaco(int espaco);
                void imprimirTipo(Tipo t);
                std::string imprimirTipoPorExtenso(Tipo t);
                void imprimirErroDeOperacao(Tipo operacao, Tipo esperava, Tipo recebeu, int linha);

};
	
/* Variáveis */

class Variavel : public Nodo {
    public:
        Tipo tipoDeVariavel;
	int ponteiros;  //0 nao é referenciado, > 1 n referencias
	bool ponteiroEsqAtribuicao = false;
    Variavel(Tipo t, Tipo v, std::string i, int p) : Nodo(t,i), tipoDeVariavel(v), ponteiros(p) {};
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    Tipo obterTipoDaTabela(TabelaDeSimbolos *tabelaDeSimbolos);
    int recuperarPonteiros(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class Inteiro : public Nodo {
    public:
        const char *valor;
    Inteiro(const char *valor) : Nodo(Tipo::inteiro, ""), valor(valor) { }; 
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha)        { return Tipo::inteiro;     };
    void imprimir(int espaco, bool novaLinha)                              { std::cout << valor << ""; };
};

class Real : public Nodo {
    public:
        const char *valor;
    Real(const char *valor) : Nodo(Tipo::real, ""), valor(valor) {  };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha)        { return Tipo::real;        }
    void imprimir(int espaco, bool novaLinha)                              { std::cout << valor << ""; };
};

class Boolean : public Nodo {
    public:
        const char *valor;
    Boolean(const char *valor) : Nodo(Tipo::boolean, ""), valor(valor) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha)        { return Tipo::boolean;                       };  
    void imprimir(int espaco, bool novaLinha)                              { std::cout << std::boolalpha << valor << ""; };
};

class Declaracao : public Nodo {
    public:
        Tipo tipoDeVariavel;
        Definicao *variaveis;
    Declaracao(Tipo t, Tipo v, Definicao *d) : Nodo(t,""), tipoDeVariavel(v), variaveis(d) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class DeclaracaoDeHash : public Declaracao {
    public:
        Tipo tipoDeChave;
    DeclaracaoDeHash(Tipo t, Tipo k, Tipo v, Definicao *d) : Declaracao(t,v,d), tipoDeChave(k) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class Definicao : public Nodo {
    public:
        Tipo tipoDeVariavel;
        Variavel *variavel;
        Nodo *valor;
        Definicao *proxima;
    Definicao(Tipo t, Variavel *v, Nodo *c, Definicao *p) : Nodo(t,""), variavel(v), valor(c), proxima(p) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
    void ajustarProxima(Definicao *p);
};

class DefinicaoDeArranjo : public Definicao {
    public:
    DefinicaoDeArranjo(Tipo t, Variavel *a, Nodo *c, DefinicaoDeArranjo *p) : Definicao(t,a,c,p) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class DefinicaoDeHash : public Definicao {
    public:
        Tipo tipoDeChave;
    DefinicaoDeHash(Tipo t, Variavel *a, Nodo *c, DefinicaoDeArranjo *p) : Definicao(t,a,c,p) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class OperacaoUnaria : public Nodo {
    public:
        Tipo operacao;
        Tipo retorno;
        Nodo *filho;
	int ponteiros; //uma operacao unaria pode conter uma referencia ao lado direito, portanto deve ser passado para cima
    OperacaoUnaria(Tipo t, Tipo o, Nodo *f) : Nodo(t,""), operacao(o), retorno(Tipo::nulo), filho(f) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    int recuperarPonteiros(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha){return ponteiros;}
    void imprimir(int espaco, bool novaLinha);
};

class OperacaoBinaria : public Nodo {
    public:
        Tipo operacao;
        Tipo retorno;
        Nodo *esquerda;
        Nodo *direita;
    OperacaoBinaria(Tipo t, Tipo o, Nodo *e, Nodo *d) : Nodo(t,""), operacao(o), retorno(Tipo::nulo), esquerda(e), direita(d) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class OperacaoTernaria : public Nodo {
    public:
        OperacaoUnaria *esquerda; 
        OperacaoBinaria *direita;
    OperacaoTernaria(Tipo t, OperacaoUnaria *e, OperacaoBinaria *d) : Nodo(t,""), esquerda(e), direita(d) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class Condicao : public Nodo {
    public:
        Nodo *teste;
        Bloco *se;
        Bloco *senao;
    Condicao(Tipo t, Nodo *a,  Bloco *b,  Bloco *c) : Nodo(t,""), teste(a), se(b), senao(c) {  };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class Laco : public Nodo {
    public:
        Nodo *inicializacao;
        Nodo *teste;
        Nodo *iteracao;
        Bloco *laco;
    Laco(Tipo t, Nodo *a, Nodo *b, Nodo *c, Bloco *d) : Nodo(t,""), inicializacao(a), teste(b), iteracao(c), laco(d) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class Funcao : public Variavel {
    public:
        Tipo tipoDoRetorno;
        Nodo *parametros;
        int quantidadeDeParametros;
        bool definida;
    Funcao(Tipo t, Tipo d, std::string i, Nodo *p) : Variavel(t,d,i,0), tipoDoRetorno(d), parametros(p) { definida = false; };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha) { };
    int contarParametros();
};

class Retorno : public Nodo {
    public:
        Nodo *retorno;
    Retorno(Tipo t, Nodo *r) : Nodo(t,""), retorno(r) {};
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class DefinicaoDeFuncao : public Funcao {
    public:
        Bloco *corpo;
	Nodo *retorno;
    DefinicaoDeFuncao(Tipo t, Tipo d, std::string i, Nodo *p, Bloco *c, Nodo *r) : Funcao(t,d,i,p), corpo(c), retorno(r) { definida = false; };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
    int contarParametros();
};

class Arranjo : public Variavel {
    public:
        Nodo *tamanho;
    Arranjo(Tipo t, Tipo v, std::string i, Nodo *p, int ponteiros) : Variavel(t, v, i, ponteiros), tamanho(p) {};
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class ArranjoDuplo : public Arranjo {
    public:
        Nodo *tamanho2;
    ArranjoDuplo(Tipo t, Tipo v, std::string i, Nodo *p, Nodo *q, int ponteiros) : Arranjo(t, v, i, p, ponteiros), tamanho2(q) {};
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class Hash : public Variavel {
    public:
        Tipo tipoDeChave;
    Hash(Tipo t, Tipo v, std::string i, int ponteiros) : Variavel(t, v, i, ponteiros), tipoDeChave(Tipo::nulo) {};
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    Tipo tipoDeHash(AST::TabelaDeSimbolos *tabelaDeSimbolos);
    void imprimir(int espaco, bool novaLinha);
};

class Chamada : public Funcao {
    public:
    Chamada(Tipo t, Tipo d, std::string i, Nodo *p, Bloco *c) : Funcao(t,d,i,p) { definida = false; };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
    int contarParametros();
};


class Parametro : public Nodo {
    public:
        Tipo tipoDoParametro;
        Tipo tipoReserva;
        Nodo *parametro;
        Nodo* proximo;
    Parametro(Tipo t, Tipo k, Tipo v, Nodo *p, Nodo *r) : Nodo(t,""), tipoDoParametro(k), tipoReserva(v), parametro(p), proximo(r) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool naoArgumento);
    void comparar(TabelaDeSimbolos *tabelaDeSimbolos, Parametro *comparado, int linha, bool definicao);
    void acrescentarAoEscopo(TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    int contar();
};

class Bloco : public Nodo {
    public:
        listaDeNodos linhas;
        TabelaDeSimbolos *escopo;
    Bloco(Tipo t) : Nodo(t,"") {} ; // Construtor para um Bloco de linhas comum
    Bloco(Tipo t, TabelaDeSimbolos *s) : Nodo(t,""), escopo(s) { }; // Construtor para o Bloco principal, a Árvore Sintática
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
    void novaLinha(Nodo *linha);
};

class TabelaDeSimbolos {
    public:
        std::map<std::string, AST::Nodo*> simbolos;
        TabelaDeSimbolos *anterior, *proximo;
    TabelaDeSimbolos() {}
    ~TabelaDeSimbolos() { }
    TabelaDeSimbolos* novoEscopo(TabelaDeSimbolos *a);
    bool retornarEscopo(int linha);
    bool adicionar(AST::Nodo *v, int linha, bool variavel);
    Nodo* recuperar(std::string id, int linha, bool variavel);
    Tipo tipoDeArranjo(Tipo tipo);
    Tipo tipoDeArranjoDuplo(Tipo tipo);
    Tipo tipoDeHash(Tipo chave, Tipo valor);
};

}
#endif 
