// Função retornando tipo errado : a(0) é detectado como variávei "a"
// Adaptado de https://github.com/llpilla/compiler_examples/blob/master/simple_ast/ast.h

#ifndef ARVORESINTATICA_H
#define ARVORESINTATICA_H
#pragma once
#include "arvoreSintatica.h"
#include <iostream>
#include <vector>
#include <string>
#include "string.h"
#include <map>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <cstdio>


extern void yyerror(const char *s, ...);

namespace AST {

enum Tipo { inteiro, real, boolean, variavel, hash, arranjo_b, arranjo_i, arranjo_f, arranjo_2_b, arranjo_2_i, arranjo_2_f,
            hash_bb, hash_bi, hash_bf, hash_ib, hash_ii, hash_if, hash_fb, hash_fi, hash_ff,
            declaracao, declaracao_hash, definicao, definicao_arranjo, definicao_hash,
            opUnaria, opBinaria, opTernaria, condicao, retorno, chamada,
            for_laco, do_while_laco, while_laco,
            funcao_dec, funcao_def, funcao_cha, bloco, arranjo, arranjo_duplo, parametro,
            negacao, inversao, conversao_int, conversao_float, conversao_bool, parenteses, referencia, endereco,
            atribuicao, adicao, subtracao, multiplicacao, divisao, e, ou, igual, diferente, maior, maior_igual, menor, menor_igual,
            teste, seleciona, caso, padrao,condicao_atribuicao, atribuicao_condicional, interpretador, nulo };

typedef struct {       
    int i;
    double f;
    bool b;
    char *valor;
} atributo_nodo;

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
class Switch;

typedef std::vector<Nodo*> listaDeNodos;

class Nodo {
    public:
	atributo_nodo vazio; //garante que o programa não dê pau
        Tipo tipo;
        std::string id;
        int inteiro;
        double real;
        bool boolean;
  

        Nodo(Tipo t, atributo_nodo an) : tipo(t), id( an.valor == NULL ? "" : std::string(an.valor)), inteiro(an.i), real(an.f), boolean(an.b) {};
     	Nodo(Tipo t, std::string i) : tipo(t), id(i) {};
        virtual ~Nodo() {};
        virtual Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) { return Tipo::nulo; };
	virtual int recuperarPonteiros(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha) {return 0;}
        virtual void imprimir(int espaco, bool novaLinha) { std::cout << id << ""; }
                bool coercaoDaDefinicao(Definicao *coagido, Tipo esperado, Tipo recebido, int linha);
                bool coercao(OperacaoBinaria *coagido, Tipo e, Tipo d, Tipo operacao, int linha, bool analisador);
                void imprimirEspaco(int espaco);
                void imprimirTipo(Tipo t);
                std::string imprimirTipoPorExtenso(Tipo t);
                void imprimirErroDeOperacao(Tipo operacao, Tipo esperava, Tipo recebeu, int linha);

};

class Variavel : public Nodo {
    public:
        Tipo tipoDeVariavel;
	int ponteiros;  //0 nao é referenciado, > 1 n referencias
	bool ponteiroEsqAtribuicao = false;
        bool ponteiroParametro = false;
    Variavel(Tipo t, Tipo v, atributo_nodo an, int p) : Nodo(t,an), tipoDeVariavel(v), ponteiros(p) {};
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    Tipo obterTipoDaTabela(TabelaDeSimbolos *tabelaDeSimbolos);
    int recuperarPonteiros(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void imprimir(int espaco, bool novaLinha);
};

class Inteiro : public Nodo {
    public:
    	std::string valor;
    Inteiro(atributo_nodo an) : Nodo(Tipo::inteiro,""), valor(an.valor)                { inteiro = an.i;           }; 
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) { return Tipo::inteiro;     };
    void imprimir(int espaco, bool novaLinha)                                          { std::cout << valor << ""; };
};

class Real : public Nodo {
    public:
    	std::string valor;
    Real(atributo_nodo an) : Nodo(Tipo::real,""), valor(an.valor)                      { real = an.f;              };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) { return Tipo::real;        }
    void imprimir(int espaco, bool novaLinha)                                          { std::cout << valor << ""; };
};

class Boolean : public Nodo {
    public:
    	std::string valor;
    Boolean(atributo_nodo an) : Nodo(Tipo::boolean,""), valor(an.valor)                 { boolean = an.b;                             };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador) { return Tipo::boolean;                       };  
    void imprimir(int espaco, bool novaLinha)                                          { std::cout << std::boolalpha << valor << ""; };
};

class Declaracao : public Nodo {
    public:
        Tipo tipoDeVariavel;
        Definicao *variaveis;
    Declaracao(Tipo t, Tipo v, Definicao *d) : Nodo(t,""), tipoDeVariavel(v), variaveis(d) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class DeclaracaoDeHash : public Declaracao {
    public:
        Tipo tipoDeChave;
    DeclaracaoDeHash(Tipo t, Tipo k, Tipo v, Definicao *d) : Declaracao(t,v,d), tipoDeChave(k) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class Definicao : public Nodo {
    public:
        Tipo tipoDeVariavel;
        Variavel *variavel;
        Nodo *valor;
        Definicao *proxima;
    Definicao(Tipo t, Variavel *v, Nodo *c, Definicao *p) : Nodo(t,""), variavel(v), valor(c), proxima(p) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
    void ajustarProxima(Definicao *p);
};

class DefinicaoDeArranjo : public Definicao {
    public:
    DefinicaoDeArranjo(Tipo t, Variavel *a, Nodo *c, DefinicaoDeArranjo *p) : Definicao(t,a,c,p) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class DefinicaoDeHash : public Definicao {
    public:
        Tipo tipoDeChave;
    DefinicaoDeHash(Tipo t, Variavel *a, Nodo *c, DefinicaoDeArranjo *p) : Definicao(t,a,c,p) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class OperacaoUnaria : public Nodo {
    public:
        Tipo operacao;
        Tipo tipoDoRetorno;
        Nodo *filho;
	int ponteiros; //uma operacao unaria pode conter uma referencia ao lado direito, portanto deve ser passado para cima
    OperacaoUnaria(Tipo t, Tipo o, Nodo *f) : Nodo(t,""), operacao(o), tipoDoRetorno(Tipo::nulo), filho(f) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    int recuperarPonteiros(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha){return ponteiros;}
    void imprimir(int espaco, bool novaLinha);
};

class OperacaoBinaria : public Nodo {
    public:
        Tipo operacao;
        Tipo tipoDoRetorno;
        Nodo *esquerda;
        Nodo *direita;
    OperacaoBinaria(Tipo t, Tipo o, Nodo *e, Nodo *d) : Nodo(t,""), operacao(o), tipoDoRetorno(Tipo::nulo), esquerda(e), direita(d) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class OperacaoTernaria : public Nodo {
    public:
        OperacaoUnaria *esquerda; 
        OperacaoBinaria *direita;
    OperacaoTernaria(Tipo t, OperacaoUnaria *e, OperacaoBinaria *d) : Nodo(t,""), esquerda(e), direita(d) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class Condicao : public Nodo {
    public:
        Nodo *teste;
        Bloco *se;
        Bloco *senao;
	Condicao *proximo; //usado no switch
    Condicao(Tipo t, Nodo *a,  Bloco *b,  Bloco *c) : Nodo(t,""), teste(a), se(b), senao(c) {  };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class Switch : public Nodo{
    public :
        Nodo* casoTratado;
        Condicao *casos;
	bool match = false;
    Switch(Tipo t, Nodo *ct, Condicao *cs) : Nodo(t, ""), casoTratado(ct), casos(cs) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};


class Laco : public Nodo {
    public:
        Nodo *inicializacao;
        Nodo *teste;
        Nodo *iteracao;
        Bloco *laco;
    Laco(Tipo t, Nodo *a, Nodo *b, Nodo *c, Bloco *d) : Nodo(t,""), inicializacao(a), teste(b), iteracao(c), laco(d) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class Funcao : public Variavel {
    public:
        Tipo tipoDoRetorno;
        Nodo *parametros;
        int quantidadeDeParametros;
        bool definida;
    Funcao(Tipo t, Tipo d, atributo_nodo an, Nodo *p) : Variavel(t,d,an,0), tipoDoRetorno(d), parametros(p) { definida = false; };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha) { };
    int contarParametros();
};

class Retorno : public Nodo {
    public:
        Nodo *retorno;
    Retorno(Tipo t, Nodo *r) : Nodo(t,""), retorno(r) {};
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class DefinicaoDeFuncao : public Funcao {
    public:
        Bloco *corpo;
	Nodo *retorno;
    DefinicaoDeFuncao(Tipo t, Tipo d, atributo_nodo an, Nodo *p, Bloco *c, Nodo *r) : Funcao(t,d,an,p), corpo(c), retorno(r) { definida = false; };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    Tipo executar(AST::TabelaDeSimbolos *tabelaDeSimbolos, Parametro *valores, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
    int contarParametros();
};

class Arranjo : public Variavel {
    public:
	int inteiro_a[100]  = {};
        double real_a[100]  = {};
        bool boolean_a[100] = {};
        Nodo *tamanho;
    Arranjo(Tipo t, Tipo v, atributo_nodo an, Nodo *p, int ponteiros) : Variavel(t, v, an, ponteiros), tamanho(p) {};
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class ArranjoDuplo : public Arranjo {
    public:
	int inteiro_d[100][100]  = {};
        double real_d[100][100]  = {};
        bool boolean_d[100][100] = {};
        Nodo *tamanho2;
    ArranjoDuplo(Tipo t, Tipo v, atributo_nodo an, Nodo *p, Nodo *q, int ponteiros) : Arranjo(t, v, an, p, ponteiros), tamanho2(q) {};
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class Hash : public Variavel {
    public:
        std::vector<int> inteiro_a;
        std::vector<bool> boolean_a;
        std::vector<double> real_a;
	std::map<int, int> int_int;
	std::map<int, bool> int_bool;
	std::map<int, double> int_real;
	std::map<bool, bool> bool_bool;
	std::map<bool, int> bool_int;
	std::map<bool, double> bool_real;
	std::map<double, double> real_real;
	std::map<double, int> real_int;
	std::map<double, bool> real_bool;
        Tipo tipoDeChave;
    Hash(Tipo t, Tipo v, atributo_nodo an, int ponteiros) : Variavel(t, v, an, ponteiros), tipoDeChave(Tipo::nulo) {};
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    Tipo tipoDeHash(AST::TabelaDeSimbolos *tabelaDeSimbolos);
    void imprimir(int espaco, bool novaLinha);
};

class Chamada : public Funcao {
    public:

    Nodo *retornoEstruturaDados;
    bool read_hash = true;
    Chamada(Tipo t, Tipo d, atributo_nodo an, Nodo *p, Bloco *c, int ref) : Funcao(t,d,an,p) {ponteiros = ref; definida = false; };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
    int contarParametros();
};

class Parametro : public Nodo {
    public:
        Tipo tipoDoParametro;
        Tipo tipoReserva;
        Nodo *parametro;
        Nodo *proximo;
    Parametro(Tipo t, Tipo k, Tipo v, Nodo *p, Nodo *r) : Nodo(t,""), tipoDoParametro(k), tipoReserva(v), parametro(p), proximo(r) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool naoArgumento);
    void comparar(TabelaDeSimbolos *tabelaDeSimbolos, Parametro *comparado, int linha, bool definicao, bool analisador);
    void acrescentarAoEscopo(TabelaDeSimbolos *tabelaDeSimbolos, int linha);
    void acrescentarComValoresAoEscopo(TabelaDeSimbolos *tabelaDeSimbolos, Parametro *valores, int linha);
    void recuperarEstruturaDeDados(TabelaDeSimbolos *tabelaDeSimbolos, Parametro *p, int linha);
    void ajustarPonteiroImpressao(Parametro *p);
    int contar();
};

class Bloco : public Nodo {
    public:
        listaDeNodos linhas;
        TabelaDeSimbolos *escopo;
    Bloco(Tipo t) : Nodo(t,"") { } ; // Construtor para um Bloco de linhas comum
    Bloco(Tipo t, TabelaDeSimbolos *s) : Nodo(t,""), escopo(s) { }; // Construtor para o Bloco principal, a Árvore Sintática
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
    void novaLinha(Nodo *linha);
};

class Interpretador : public Nodo {
    public:
        Nodo* raiz;
    Interpretador(Tipo t, Nodo* r) : Nodo(t,""), raiz(r) { };
    Tipo analisar(AST::TabelaDeSimbolos *tabelaDeSimbolos, int linha, bool analisador);
    void imprimir(int espaco, bool novaLinha);
};

class TabelaDeSimbolos {
    public:
        std::map<std::string, AST::Nodo*> simbolos;
        std::vector<atributo_nodo*> parametros;
        TabelaDeSimbolos *anterior, *proximo;
    TabelaDeSimbolos() {}
    ~TabelaDeSimbolos() {}
    TabelaDeSimbolos* novoEscopo(TabelaDeSimbolos *a);
    bool retornarEscopo(int linha);
    bool escopoPrincipal();
    bool adicionar(AST::Nodo *v, int linha, bool variavel);
    Nodo* recuperar(std::string id, int linha, bool variavel);
    void modificar(Nodo *novoValor, std::string id);
    void remover(std::string id);
    void adicionarParametro();
    atributo_nodo coletarParametro();
    Tipo tipoDeArranjo(Tipo tipo);
    Tipo tipoDeArranjoDuplo(Tipo tipo);
    Tipo tipoDeHash(Tipo chave, Tipo valor);
};

}
#endif 
