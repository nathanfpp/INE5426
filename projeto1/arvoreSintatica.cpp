// Adaptado de: https://github.com/llpilla/compiler_examples/blob/master/simple_ast/ast.cpp
// Passar map como parâmetro: http://stackoverflow.com/questions/7763397/c-pass-a-map-by-reference-into-function

#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>


using namespace AST;

// Variavel //

void Variavel::imprimir() {
    std::cout << id << " ";
    return;
}

void Variavel::adicionarTipo(TipoDeNodo t) {

    if(tipo == semTipo) 
    {
      tipo = t;
    }
    //else: nesse caso se o tipo já tiver sido atribuído cairá no erro de declaração duplicada preservando a variável original.

    return;  
}

void Variavel::verificarTipo(TipoDeNodo t, TipoDeNodo operador) {

  
     if(t != tipo) 
    {
    switch(t) {
              case TipoDeNodo::inteiro:  std::cout << "expected int ";    break;
              case TipoDeNodo::real:     std::cout << "expected float ";  break;
              case TipoDeNodo::boolean:  std::cout << "expected bool ";   break;                
            }
     switch(tipo) {
              case TipoDeNodo::inteiro:  std::cout << "recieved int \n";    break;
              case TipoDeNodo::real:     std::cout << "recieved float \n";  break;
              case TipoDeNodo::boolean:  std::cout << "recieved bool \n";   break;                
            }
     exit(0);
    }
    
    if ((tipo == real || tipo == inteiro)&& (!(operador == adicao | operador == subtracao | operador == multiplicacao | operador == divisao | operador == x)))
	{
	  std::cout << "Semantic error, expected a numeric operator \n";
    	  exit(0);
        }
     else if ((tipo == boolean) && (!(operador == e | operador == ou | operador == inversao | operador == x )))
	{
	  std::cout << "Semantic error, expected a boolean operator \n";
    	  exit(0);
        }


    return;   
}

void Variavel::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
    std::map<std::string, AST::Variavel*>::iterator it;
    it = tabela_simbolos.find(id);
    if (it == tabela_simbolos.end()){
        std::cout << "semantic error: undeclared variable " << id << "\n";
        exit(0);
    } else {
        //std::cout << "semantic ok: declared variable " << id << "\n";
        //tabela_simbolos[std::string(id)] = this;
        tipo = tabela_simbolos[std::string(id)]-> tipo; //como cada nodo variavel começa por default sem tipo, reatribuo o tipo original
    }
    return;
}

void Variavel::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos,  AST::TipoDeNodo ultimoTipo) {
    std::map<std::string, AST::Variavel*>::iterator it;
    it = tabela_simbolos.find(id);
    if (it != tabela_simbolos.end()) {
        std::cout << "semantic error: re-declaration of variable " << id << "\n";
    } else {
        //std::cout << "semantic ok: declaration of variable " << id << "\n";
	adicionarTipo(ultimoTipo);
        tabela_simbolos[std::string(id)] = this;
    }
}

// Inteiro

void Inteiro::imprimir() {
    std::cout << valor << " ";
    return;
}

void Inteiro::verificarTipo(TipoDeNodo t, TipoDeNodo operador)
{
     if(t != tipo) 
    {
    switch(t) {
              case TipoDeNodo::inteiro:  std::cout << "expected int ";    break;
              case TipoDeNodo::real:     std::cout << "expected float ";  break;
              case TipoDeNodo::boolean:  std::cout << "expected bool ";   break;                
            }

     std::cout << "recieved int \n";
     exit(0);
    }

if (!(operador == adicao | operador == subtracao | operador == multiplicacao | operador == divisao | operador == negacao | operador == x))
	{
	  std::cout << "Semantic error, expected a numeric operator \n";
    	  exit(0);
        }
}

// Real

void Real::imprimir() {
    std::cout << valor << " ";
    return;
}

void Real::verificarTipo(TipoDeNodo t, TipoDeNodo operador)
{

     if(t != tipo) 
    {
    switch(t) {
              case TipoDeNodo::inteiro:  std::cout << "expected int ";    break;
              case TipoDeNodo::real:     std::cout << "expected float ";  break;
              case TipoDeNodo::boolean:  std::cout << "expected bool ";   break;                
            }

     std::cout << "recieved float \n";
     exit(0);
    }

     if (!(operador == adicao | operador == subtracao | operador == multiplicacao | operador == divisao | operador == negacao | operador == x))
	{
	  std::cout << "Semantic error, expected a numeric operator \n";
    	  exit(0);
        }
}


// Boolean

void Boolean::imprimir() {
    std::cout << std::boolalpha << valor << " ";
    return;
}

void Boolean::verificarTipo(TipoDeNodo t, TipoDeNodo operador)
{
     if(t != tipo) 
    {
    switch(t) {
              case TipoDeNodo::inteiro:  std::cout << "expected int ";    break;
              case TipoDeNodo::real:     std::cout << "expected float ";  break;
              case TipoDeNodo::boolean:  std::cout << "expected bool ";   break;                
            }

     std::cout << "recieved boolean \n";
     exit(0);
    }

   if (!(operador == e | operador == ou | operador == inversao | operador == x))
	{
	  std::cout << "Semantic error, expected a boolean operator \n"<<operador;
    	  exit(0);
        }
}


// Nodo Genérico

void Nodo::imprimir() {
    switch(classe) {
        case ClasseDeNodo::declaracao:
            switch(tipo) {
                case TipoDeNodo::inteiro:  std::cout << "int ";    break;
                case TipoDeNodo::real:     std::cout << "float ";  break;
                case TipoDeNodo::boolean:  std::cout << "bool ";   break;                
            }
            imprimirDireita();
            break;
        case ClasseDeNodo::atribuicao:
            imprimirEsquerda();
            if(tipo != TipoDeNodo::atomica){
                std::cout << "= ";
                imprimirDireita();
            }
            if(proximo != NULL) {
                std::cout << ", ";
                imprimirProximo();
            }
            break;
        case ClasseDeNodo::operacaoBinaria:
            imprimirEsquerda();
            switch(tipo) {
                case TipoDeNodo::adicao:         std::cout << "+ ";  break;
                case TipoDeNodo::subtracao:      std::cout << "- ";  break;
                case TipoDeNodo::multiplicacao:  std::cout << "* ";  break;
                case TipoDeNodo::divisao:        std::cout << "/ ";  break;                
            }
            imprimirDireita();
            break;
        case ClasseDeNodo::operacaoUnaria:
            switch(tipo){
                case TipoDeNodo::negacao:   std::cout << "- ";  break;
                case TipoDeNodo::inversao:    std::cout << "! ";  break;
           }
           imprimirDireita();
           break;
        case ClasseDeNodo::parenteses:
            std::cout << "( ";
            direita->imprimir();
            std::cout << ") ";
            return;
    }
    return;
}

void Nodo::imprimirEsquerda() {
    if(esquerda != NULL) {
        esquerda->imprimir();
    }
}

void Nodo::imprimirDireita() {
    if(direita != NULL) {
        direita->imprimir();
    }
}

void Nodo::imprimirProximo() {
    if(proximo != NULL) {
        proximo->imprimir();
    }
}

void Nodo::verificarTipo(TipoDeNodo t, TipoDeNodo operador) {
    if(esquerda != NULL)  esquerda->verificarTipo(t, tipo);
    if(direita != NULL)   direita->verificarTipo(t, tipo);  
    if(proximo != NULL)   proximo->verificarTipo(t, tipo);
    return;    
}

void Nodo::verificarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos) {
    if(esquerda != NULL)  esquerda->verificarSimbolos(tabela_simbolos);
    if(direita != NULL)   direita->verificarSimbolos(tabela_simbolos);  
    if(proximo != NULL)   proximo->verificarSimbolos(tabela_simbolos);
    return;    
}

void Nodo::acrescentarSimbolos(std::map<std::string, AST::Variavel*> &tabela_simbolos, AST::TipoDeNodo ultimoTipo) {
    if(esquerda != NULL)  esquerda->acrescentarSimbolos(tabela_simbolos,ultimoTipo);
    if(direita != NULL)   direita->acrescentarSimbolos(tabela_simbolos, ultimoTipo);  
    if(proximo != NULL)   proximo->acrescentarSimbolos(tabela_simbolos, ultimoTipo);
    return;
}


// Bloco ou Linha

void Bloco::imprimir(){
    for (NodoBase* linha: linhas) {
        linha->imprimir();
        std::cout << std::endl;
    }
}

void Bloco::novaLinha(NodoBase *linha) {
    linhas.push_back(linha);
}


