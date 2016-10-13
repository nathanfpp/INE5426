#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;

Tipo ChamadaOuArranjo::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Caso a função (ou arranjo) não tenha sido definida/declarada, ocorre um erro semântico
    Nodo *n = tabelaSimbolos->recuperar(id, -1, false);
    if(n != NULL) {

      // Caso este Nodo seja uma Chamada de Funcao
        if(n->tipo == Tipo::funcao_dec || n->tipo == Tipo::funcao_def) {

          tipo = Tipo::funcao_cha;

          // Conta a quantidade de parâmetros: se não houver parâmetros a quantidade é 0
            Funcao::contarParametros();              
              
          // Recupera a Função
            Funcao *f = ((Funcao*) n);
                       
          // Obtém a quantidade de parâmetros da Função encontrada na Tabela de Símbolos
            int quantidadeEsperada = f->contarParametros();

          // Se de parâmetros for diferente, ocorre um erro semântico
            if(quantidadeDeParametros != quantidadeEsperada) {
                std::cerr << "[Line " << linha << "] semantic error: function " << id;
                std::cerr << " expects " << quantidadeEsperada << " parameters";
                std::cerr << " but received " << quantidadeDeParametros << "\n";
            }

          // Se os parâmetros não foram nulos, eles podem ser comparados
            else if(parametros != NULL) {                
              ((Parametro*)f->parametros)->comparar(tabelaSimbolos, ((Parametro*)parametros), linha, false);
            }

          // Atribui o tipo da função definida à declaração ou chamada
            tipoDoRetorno = f->tipoDoRetorno;
 
          // Retorna o tipo da variável retornada pela função
            return tipoDoRetorno;
        }
    
      // Senão, este Nodo é uma "Chamada" de Arranjo
        else {

          // Define o tipo desta ChamadaOuArranjo como Arranjo
            tipo = Tipo::arranjo;
                
          // Recupera o Arranjo 
            Arranjo *v = ((Arranjo*) n);

          // O tipo usado como índice é válido? parametros = tamanho
            Tipo indice = v->tamanho->analisar(tabelaSimbolos, linha);
            if(indice != Tipo::inteiro) {
                std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received " << indice << "\n";
            }

          //
            return v->tipoDeVariavel;
        }
    }

  // A Chamada de Função ou Arranjo não foi declarada
    return tipo;
}

void ChamadaOuArranjo::imprimir(int espaco, bool declaracao) {  
    if( tipo == funcao_cha) {
        std::cout << id << "["<< quantidadeDeParametros << " params]";        
    } else {
        std::cout << "[index] " << id << "";        
    }
    if(parametros != NULL) {
        parametros->imprimir(0, false);
    }
};

