#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

TabelaDeSimbolos* TabelaDeSimbolos::novoEscopo(TabelaDeSimbolos *a) {
  // Cria o novo escopo, ajustando os ponteiros de *anterior e *proximo
    TabelaDeSimbolos *novoEscopo = new TabelaDeSimbolos(); 
    novoEscopo->anterior = a;
    novoEscopo->proximo = NULL;
    a->proximo = novoEscopo;
    return novoEscopo;
}


bool TabelaDeSimbolos::retornarEscopo(int linha) {
 // Procura-se entre as funções declaradas...
    typedef std::map<std::string, Nodo*>::iterator it;
    for(it iterator = simbolos.begin(); iterator != simbolos.end(); iterator++) {
        if(iterator->second->tipo == Tipo::funcao_dec) {
            Funcao *f = ((Funcao*)iterator->second);

          // ... aquelas que não foram definidas
            if(!f->definida) {
                std::cerr << "[Line " << linha << "] semantic error: function "; 
                std::cerr << f->id << " is declared but never defined\n"; 
            }
        }
    }

  // Se este for o último escopo, ele retorna <true>
    if(anterior == NULL) {
        return false;
    } 

  // Senão, ele pode remover o último escopo, caso ele retorne <true>
    else {
      // Isto só é viável pois cada Nodo::Bloco possui uma referência para a TabelDeSimbolos de seu escopo
        simbolos.clear();
        anterior->proximo = NULL;
        anterior = NULL;
//std::cout << "<-\n";
        return true;
    }    
}


bool TabelaDeSimbolos::escopoPrincipal(){
    return (anterior == NULL);
}


bool TabelaDeSimbolos::adicionar(AST::Nodo *v, int linha, bool variavel) {

//std::cerr << "\n@ " << v->id<<"\n";
  
// Se a Variável ou Função não foi declarada, ela é adicionada ao map
    std::map<std::string, AST::Nodo*>::const_iterator it;
    it = simbolos.find(v->id);
    if (it == simbolos.end()) {
        simbolos.insert ( std::pair< std::string, AST::Nodo*> (v->id,v) );
        return true;

  // Caso a Variável ou Função já tenha sido declarada, ocorre um erro semântico
    } else if (variavel) {
        std::cerr << "[Line " << linha << "] semantic error: re-declaration of variable " << v->id << "\n";         
    }
      else {
        std::cerr << "[Line " << linha << "] semantic error: re-declaration of function " << v->id << "\n"; 
    }
    return false;
}


Nodo* TabelaDeSimbolos::recuperar(std::string id, int linha, bool variavel) {

  // Variável ou Função encontrada no escopo atual
    std::map<std::string, AST::Nodo*>::const_iterator it;
    it = simbolos.find(id);
    if (it != simbolos.end()) {

//std::cout << "@tabelaDeSimbolos::recuperar " << id << " " << it->second->inteiro << "\n";

        return it->second;
    }

  // Variavel ou Função não encontrada, procurar no escopo anterior
    else if (anterior != NULL) {
        return anterior->recuperar(id, linha, variavel);
    }

  // Variável ou Função não encontrada em nenhum escopo
   else if (linha >= 0) {
        if(variavel) {
            std::cerr << "[Line " << linha << "] semantic error: undeclared variable " << id << "\n";
        } else {
            std::cerr << "[Line " << linha << "] semantic error: undeclared function " << id << "\n";
        }
    }
    return NULL;
}

void TabelaDeSimbolos::modificar(Nodo *novoValor, std::string id) {
//std::cout<<".";
  // Variável ou Função encontrada no escopo atual
    std::map<std::string, AST::Nodo*>::iterator it;
    it = simbolos.find(id);
    if (it != simbolos.end()) {
        it->second = novoValor;
        return;
    }

  // Variavel ou Função não encontrada, procurar no escopo anterior
    else if (anterior != NULL) {
        return anterior->modificar(novoValor, id);
    }
}

void TabelaDeSimbolos::remover(std::string id) {
    simbolos.erase(id);
}

Tipo TabelaDeSimbolos::tipoDeArranjo(Tipo tipo) {
    Tipo array = Tipo::nulo;
    switch(tipo) {
        case Tipo::boolean: array = Tipo::arranjo_b; break;
        case Tipo::inteiro: array = Tipo::arranjo_i; break;
        case Tipo::real:    array = Tipo::arranjo_f; break;
        default: break;
    }
    return array;
}


Tipo TabelaDeSimbolos::tipoDeArranjoDuplo(Tipo tipo) {
    Tipo array = Tipo::nulo;
    switch(tipo) {
        case Tipo::boolean: array = Tipo::arranjo_2_b; break;
        case Tipo::inteiro: array = Tipo::arranjo_2_i; break;
        case Tipo::real:    array = Tipo::arranjo_2_f; break;
        default: break;
    }
    return array;
}

Tipo TabelaDeSimbolos::tipoDeHash(Tipo chave, Tipo valor) {
    Tipo tipo = Tipo::nulo;
    switch(chave) {
        case Tipo::boolean:
            switch(valor) {
                case Tipo::boolean: tipo = Tipo::hash_bb; break;
                case Tipo::inteiro: tipo = Tipo::hash_bi; break;
                case Tipo::real:    tipo = Tipo::hash_bf; break;
                default: break;
            } break;
        case AST::Tipo::inteiro:
            switch(valor) {
                case Tipo::boolean: tipo = Tipo::hash_ib; break;
                case Tipo::inteiro: tipo = Tipo::hash_ii; break;
                case Tipo::real:    tipo = Tipo::hash_if; break;
                default: break;
            } break;
        case AST::Tipo::real:
            switch(valor) {
                case Tipo::boolean: tipo = Tipo::hash_fb; break;
                case Tipo::inteiro: tipo = Tipo::hash_fi; break;
                case Tipo::real:    tipo = Tipo::hash_ff; break;
                default: break;
            } break;
        default: break;
    }
    return tipo;
}
