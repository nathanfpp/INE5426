// Adaptado de: https://github.com/llpilla/compiler_examples/blob/master/simple_ast/ast.cpp
// Passar map como parâmetro: http://stackoverflow.com/questions/7763397/c-pass-a-map-by-reference-into-function

#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>

//extern ST::SymbolTable symtab;

using namespace AST;

/* Variáveis */

void Variavel::imprimir() {
    std::cout << id << " ";
    return;
}

void Inteiro::imprimir() {
    std::cout << valor << " ";
    return;
}

void Real::imprimir() {
    std::cout << valor << " ";
    return;
}

void Boolean::imprimir() {
    std::cout << std::boolalpha << valor << " ";
    return;
}


/* Atribuição */

void Atribuicao::imprimir() {
    esquerda->imprimir();
    if(proximo != NULL) {
       std::cout << ", ";
       proximo->imprimir();
    }
    return;
}

void Atribuicao::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {

    std::string id = esquerda->id;

    std::map<std::string, AST::Variavel*>::iterator it;
    it = tabela_simbolos.find(id);

    if (it == tabela_simbolos.end()){
        std::cout << "semantic error: undeclared variable " << id << "\n";
        exit(0);

    } else {
        std::cout << "semantic ok: declared variable " << id << "\n";
        tabela_simbolos[std::string(id)] = ((Variavel*) ((OperacaoBinaria*)esquerda)->esquerda);
        if(proximo != NULL) {
            proximo->verificarSimbolos(tabela_simbolos);
        }
    }
}


void Atribuicao::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
    std::string id = esquerda->id;
    std::map<std::string, AST::Variavel*>::iterator it;
    it = tabela_simbolos.find(id);
    if (it != tabela_simbolos.end()){
        std::cout << "semantic error: re-declaration of variable " << id << "\n";
    } else {
        std::cout << "semantic ok: declaration of variable " << id << "\n";
        tabela_simbolos[std::string(id)] = ((Variavel*) ((OperacaoBinaria*)esquerda)->esquerda);
        if(proximo != NULL) {
            proximo->acrescentarSimbolos(tabela_simbolos);
        }
    }
}


/* Declaração */

void Declaracao::imprimir() {
    switch (tipo) {
        case TipoDeVariavel::inteiro:
            std::cout << "int ";
            break;
        case TipoDeVariavel::real:
            std::cout << "float ";
            break;
        case TipoDeVariavel::boolean:
            std::cout << "bool ";
            break;
        default:
            break;
    }
    direita->imprimir();
    return;
}

void Declaracao::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
    /*
       Também pode ser utilizado para verificar os tipos
    */
    ((Atribuicao*)direita)->acrescentarSimbolos(tabela_simbolos);
}


/* Operações */

void OperacaoBinaria::imprimir(){
    esquerda->imprimir();
    switch(operacao){
        case Operacao::atribuicao:
            std::cout << "= ";
            break;
        case Operacao::adicao:  
            std::cout << "+ ";
            break;
        case Operacao::subtracao: 
            std::cout << "- ";
            break;
        case Operacao::multiplicacao: 
            std::cout << "* ";
            break;
        case Operacao::divisao: 
            std::cout << "/ ";
            break;
        case Operacao::e: 
            std::cout << "& ";
            break;
        case Operacao::ou: 
            std::cout << "| ";
            break;
        default:
            std::cout << "error ";
            break;
    }
    if(direita != NULL) {
      direita->imprimir();
    }
    return;
}

void OperacaoUnaria::imprimir(){
    switch(operacao){
        case Operacao::negacao: 
            std::cout << "- ";
            direita->imprimir();
            return;
        case Operacao::inversao: 
            std::cout << "! ";
            direita->imprimir();
            return;
        case Operacao::parenteses: 
            std::cout << "( ";
            direita->imprimir();
            std::cout << ") ";
            return;
        default:
            std::cout << " error ";
            break;
    }
}


/* Bloco ou Linha */

void Bloco::imprimir(){
    for (Nodo* linha: linhas) {
        linha->imprimir();
        std::cout << std::endl;
    }
}
void Bloco::novaLinha(Nodo *linha) {
    linhas.push_back(linha);
}

/* */

