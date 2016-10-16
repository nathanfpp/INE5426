#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

bool Nodo::coercaoDaDefinicao(Definicao *coagido, Tipo esperado, Tipo recebido, int linha) {

if(recebido == Tipo::nulo) return true;

 // Se o tipo esperado e o recebido forem diferentes, ocorreu um erro...
    if(esperado != recebido) {

      // ... a não ser que possa ocorrer coerção de int para float
        if(esperado == Tipo::real && recebido == Tipo::inteiro) {
            OperacaoUnaria *coercao = new OperacaoUnaria(Tipo::opUnaria, Tipo::conversao_float, coagido->valor);
            coagido->valor = ((Nodo*) coercao);
        }

      // Caso contrário, ocorreu um erro na operação
        else {
            imprimirErroDeOperacao(Tipo::atribuicao, esperado, recebido, linha);
            return false;
        }
    }

 // Se os tipos são compatíveis, com ou sem coerção, o retorno é <true>
    return true;
}


bool Nodo::coercao(OperacaoBinaria *coagido, Tipo e, Tipo d, int linha) {

// Segundo a descrição da versão 0.3, apenas tipo int pode sofrer coerção para float, logo:

  // Se o tipo da esquerda for float e o da direita int, o da direita sofre coerção e retorna-se Tipo::real
    if (e == Tipo::real && d == Tipo::inteiro) {       

      // Acrescenta-se um nodo com a operação de coerção entre o filho da esquerda e a operação binária
        OperacaoUnaria *coercao = new OperacaoUnaria(Tipo::opUnaria, Tipo::conversao_float, coagido->direita);
        coagido->direita = ((Nodo*) coercao);
        return true;
    }

  // Se o tipo da esquerda for int e o da direita float, o da esquerda sofre coerção e retorna-se Tipo::real
    else if (e == Tipo::inteiro && d == Tipo::real) {

      // Acrescenta-se um nodo com a operação de coerção entre o filho da esquerda e a operação binária
        OperacaoUnaria *coercao = new OperacaoUnaria(Tipo::opUnaria, Tipo::conversao_float, coagido->esquerda);
        coagido->esquerda = ((Nodo*) coercao);
        return true;
    }   

  // Se não ocorreu coerção, retorna-se false
    return false;  
}


void Nodo::imprimirEspaco(int espaco) {
    for(int i = 0; i < espaco; i++) {
        std::cout << " "; 
    }
}


void Nodo::imprimirTipo(Tipo t) {
  // One switch to rule them all
    switch(t) {
        case Tipo::inteiro:          	   std::cout << "int";       break;
        case Tipo::real:             	   std::cout << "float";     break;
        case Tipo::boolean:          	   std::cout << "bool";      break;
        case Tipo::atribuicao:       	   std::cout << "=";         break; //
        case Tipo::adicao:           	   std::cout << "+";         break;
        case Tipo::subtracao:        	   std::cout << "-";         break;
        case Tipo::multiplicacao:    	   std::cout << "*";         break;
        case Tipo::divisao:          	   std::cout << "/";         break;
        case Tipo::e:                	   std::cout << "&";         break;
        case Tipo::ou:               	   std::cout << "|";         break;
        case Tipo::igual:            	   std::cout << "==";        break; //
        case Tipo::diferente:        	   std::cout << "!=";        break;
        case Tipo::maior:                  std::cout << ">";         break;
        case Tipo::maior_igual:      	   std::cout << ">=";        break;
        case Tipo::menor:            	   std::cout << "<";         break;
        case Tipo::menor_igual:      	   std::cout << "<=";        break;
        case Tipo::negacao:          	   std::cout << "-u ";       break; //
        case Tipo::inversao:         	   std::cout << "! ";        break;
        case Tipo::conversao_int:    	   std::cout << "[int] ";    break;
        case Tipo::conversao_float:  	   std::cout << "[float] ";  break;
        case Tipo::conversao_bool:   	   std::cout << "[bool] ";   break;
        case Tipo::parenteses:        	   std::cout << "";          break; //
        case Tipo::endereco:      	   std::cout << "[addr] ";   break;
        case Tipo::referencia:      	   std::cout << "[ref] ";    break;
        case Tipo::condicao_atribuicao:    std::cout << "? ";       break;
        case Tipo::atribuicao_condicional: std::cout << ": ";       break;
        default:                     	   std::cout << "";          break;
    }
}


std::string Nodo::imprimirTipoPorExtenso(Tipo t) {
  // One switch to rule them all
    switch(t) {
        case Tipo::inteiro:         	   return "integer";         
        case Tipo::real:            	   return "float";           
        case Tipo::boolean:         	   return "bool";            
        case Tipo::atribuicao:      	   return "attribution";     
        case Tipo::adicao:         	   return "addition";        
        case Tipo::subtracao:       	   return "subtraction";     
        case Tipo::multiplicacao:   	   return "multiplication";  
        case Tipo::divisao:         	   return "division";        
        case Tipo::e:               	   return "and";             
        case Tipo::ou:              	   return "or";              
        case Tipo::negacao:         	   return "- ";        
        case Tipo::inversao:        	   return "! ";              
        case Tipo::igual:           	   return "==";              
        case Tipo::diferente:        	   return "!= ";             
        case Tipo::maior:           	   return "> ";              
        case Tipo::maior_igual:     	   return ">= ";             
        case Tipo::menor:            	   return "< ";              
        case Tipo::menor_igual:      	   return "<= ";             
        case Tipo::conversao_int:    	   return "[int] ";          
        case Tipo::conversao_float:  	   return "[float] ";        
        case Tipo::conversao_bool:   	   return "[bool] ";         
        case Tipo::parenteses:             return "()";
        case Tipo::teste:                  return "test";    
        case Tipo::nulo:                   return "null";          
        case Tipo::endereco:               return "address";
        case Tipo::referencia: 		   return "reference";
        case Tipo::condicao_atribuicao:    return "? ";   
        case Tipo::atribuicao_condicional: return ": ";
        default:                	   return " ";            
    }
}


void Nodo::imprimirErroDeOperacao(Tipo operacao, Tipo esperava, Tipo recebeu, int linha) {
    std::cerr << "[Line " << linha << "] semantic error:" << " operation " << imprimirTipoPorExtenso(operacao);
    std::cerr << " expected " << imprimirTipoPorExtenso(esperava);
    std::cerr << " but received " <<  imprimirTipoPorExtenso(recebeu);
    std::cerr << "\n";

}
