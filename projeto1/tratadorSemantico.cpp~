#include "tratadorSemantico.h"
#include <iostream>
#include <string>


bool tratadorSemantico::avaliarDeclaracao(std::map<std::string, atributo> tabela_simbolos, atributo value){

 //SE o nome da variável não for vazio, é porque é uma variável, e se ela não estiver na tabela de símbolos é porque não foi declarada.
         if (std::string(value.var) != "" && tabela_simbolos.find(std::string(value.var)) == tabela_simbolos.end()){
              std::cout<<"semantic error: undeclared variable  "<<value.var<<"\n";
              exit(0);
	      return false;					   
         }
         return true;
}

bool tratadorSemantico::avaliarRepeticaoDeclaracao(std::map<std::string, atributo> tabela_simbolos, atributo value){

 //SE o nome da variável já existe na tabela de simbolos, é porque já foi declarado.
         if (tabela_simbolos.find(std::string(value.var)) != tabela_simbolos.end()){
              std::cout<<"semantic error: re-declaration of variable  "<<value.var<<"\n";
	      return false;					   
         }
         return true;
}

