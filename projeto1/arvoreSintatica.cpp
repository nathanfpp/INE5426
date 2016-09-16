// Adaptado de https://github.com/llpilla/compiler_examples/blob/master/simple_ast/ast.cpp

#include "arvoreSintatica.h"

//extern ST::SymbolTable symtab;

/* Imprimir() */

using namespace AST;

void Variavel::imprimir() {
    std::cout << id << " ";
    if(proximo != NULL)
       proximo->imprimir();
    return;
}

void Atribuicao::imprimir() {
    esquerda->imprimir();
    if(proximo != NULL)
       proximo->imprimir();
    return;
}

void Declaracao::imprimir() {

switch (tipo)
 {
   case TipoDeVariavel::inteiro:
    std::cout << "int:";
    break;

   case TipoDeVariavel::real:
    std::cout << "float:";
    break;
   
   case TipoDeVariavel::boolean:
    std::cout << "bool:";
    break;
 }

    direita->imprimir();
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

void OperacaoBinaria::imprimir(){
    esquerda->imprimir();
    switch(op){
    
    case Operacao::atribuicao: 
   
     std::cout << " = ";
     break;

    
    case Operacao::adicao: 
   
     std::cout << " + ";
     break;

    case Operacao::subtracao: 
   
     std::cout << " - ";
     break;

    case Operacao::multiplicacao: 
   
     std::cout << " * ";
     break;

    case Operacao::divisao: 
   
     std::cout << " / ";
     break;

    case Operacao::e: 
   
     std::cout << " & ";
     break;

    case Operacao::ou: 
   
     std::cout << " | ";
     break;
    
}

    if(direita != NULL) {
      direita->imprimir();
    }
    return;

}

void OperacaoUnaria::imprimir(){

switch(op){
    
    case Operacao::negacao: 
   
     std::cout << " - ";
     direita->imprimir();
     return;

    case Operacao::inversao: 
   
     std::cout << " ! ";
     direita->imprimir();
     return;

    case Operacao::parenteses: 
   
     std::cout << " ( ";
     direita->imprimir();
     std::cout << " ) ";
     return;


    }


}

void Bloco::imprimir(){
    for (Nodo* linha: linhas) {
        linha->imprimir();
        std::cout << std::endl;
    }
}

/* Outras */

void Bloco::novaLinha(Nodo *linha) {
    linhas.push_back(linha);
}

/* */

