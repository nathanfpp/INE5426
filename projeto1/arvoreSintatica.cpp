// Adaptado de: https://github.com/llpilla/compiler_examples/blob/master/simple_ast/ast.cpp
// Passar map como parâmetro: http://stackoverflow.com/questions/7763397/c-pass-a-map-by-reference-into-function

#include "arvoreSintatica.h"
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace AST;


//////////////
// Variavel//

Tipo Variavel::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Busca a variável na tabela de símbolos e, caso ele seja encontrado, retorna o tipo da variável, 
    Variavel *v = ((Variavel*) tabelaSimbolos->recuperar(id, linha, true));
    if(v != NULL) {
        return v->tipoDeVariavel;
    }

  // Caso contrário retorna o tipoDeVariavel deste nodo
    return tipoDeVariavel;
}



/////////////////
// Declaracao //

Tipo Declaracao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Atribui o tipoDeVariavel da Declaração à primeira variável da declaração
    variaveis->tipoDeVariavel = tipoDeVariavel;

  // Inicia a análise das variáveis declaradas
    Tipo valida;
    if(variaveis->tipo == Tipo::declaracao){
        valida = variaveis->analisar(tabelaSimbolos, linha);
    } else {
        valida = ((DefinicaoArranjo*) variaveis)->analisar(tabelaSimbolos, linha);
    }

  // Caso todas as variáveis já tenham sido declaradas, troca o tipo da Declaração para não ser impressa
    if(valida == Tipo::nulo) {
        tipo = Tipo::nulo;
    }

  // Retorna o tipo do nodo
    return tipo;
}


void Declaracao::imprimir(int espaco, bool novaLinha) {

  // Imprime apenas se a declaração for válida
    if(tipo == Tipo::declaracao) {
        imprimirEspaco(espaco);
        imprimirTipo(tipoDeVariavel);
        if(variaveis != NULL) {
            variaveis->imprimir(0, true);
        }
        std::cout << "\n";
    }
}



////////////////
// Definicao //

Tipo Definicao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Atribui tipoDeVariavel, recebido da Declaração, à Variável
    variavel->tipoDeVariavel = tipoDeVariavel;

  // O tipo da próxima Definição que caso não exista será Tipo::nulo
    Tipo tipoDoProximo = Tipo::nulo;

  // Salva a Variável na Tabela de Símbolos
    if(!tabelaSimbolos->adicionar(variavel, linha, true)) {

      // Porém, caso a variável já tenha sido declarada, além da impressão do erro, a definição é marcada
        tipo = Tipo::nulo;
    }

  // Caso a Definição atribua um valor à Variável, realizando coerção se necessário
    if(valor != NULL) {
        Tipo tipoDoValor = valor->analisar(tabelaSimbolos, linha); // anteriormente após a coerção
        coercaoDaDefinicao(this, tipoDeVariavel, tipoDoValor, linha);        
    }

  // Se outra Variável foi declarada, atribui o tipo da Declaração e inicia sua análise 
    if(proxima != NULL) {
        proxima->tipoDeVariavel = tipoDeVariavel;
        proxima->analisar(tabelaSimbolos, linha);

      // E também registra-se seu Tipo de Nodo
        tipoDoProximo = proxima->tipoDeVariavel;
    }

  // Caso o tipo desta Definição seja nulo, assim como o da próxima Definição...
    if(tipo == Tipo::nulo && tipoDoProximo == Tipo::nulo) {

      // ... isto significa que ambas as Variáveis já foram declaradas anteriormente
        return Tipo::nulo;
    }

  // Retorna o tipo do Nodo
    return Tipo::definicao;
}


void Definicao::imprimir(int espaco, bool imprimirVar) {

  // Caso esta seja a primeira definição após a declaração, ela imprime "var:"
    if(imprimirVar) {
        std::cout << " var: ";
    }

  // Imprime a definição apenas se ela for válida
    if(tipo == Tipo::definicao) {
        variavel->imprimir(0, false);
        if(valor != NULL) {
            std::cout << " = ";
            valor->imprimir(0, false);
        }        
        if(proxima != NULL) std::cout << ", ";  
    }

  // Imprime a próxima definição
    if(proxima != NULL) {              
        proxima->imprimir(0, false);
    }
}


void Definicao::ajustarProxima(Definicao *p) {

 // Acrescenta a definição à ultima definição até então definida
    if(proxima != NULL) {
        proxima->ajustarProxima(p);
    } else {
      proxima = p;
    }
}



///////////////////////
// DefinicaoArranjo //

Tipo DefinicaoArranjo::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Atribui tipoDeVariavel, recebido da Declaração, ao Nodo Variável (neste caso um Arranjo)
    variavel->tipoDeVariavel = tipoDeVariavel;

  // O tipo da próxima Definição que caso não exista será Tipo::nulo
    Tipo tipoDoProximo = Tipo::nulo;

  // Salva a Variável na Tabela de Símbolos
    if(!tabelaSimbolos->adicionar(variavel, linha, true)) {

      // Porém, caso a variável já tenha sido declarada, além da impressão do erro, a definição é marcada
        tipo = Tipo::nulo;
    }

  // Se outra Variável foi declarada, atribui o tipo da Declaração e inicia sua análise 
    if(proxima != NULL) {
        proxima->tipoDeVariavel = tipoDeVariavel;
        proxima->analisar(tabelaSimbolos, linha);

      // E também registra-se seu Tipo de Nodo
        tipoDoProximo = proxima->tipoDeVariavel;
    }

  // Caso o tipo desta Definição seja nulo, assim como o da próxima Definição...
    if(tipo == Tipo::nulo && tipoDoProximo == Tipo::nulo) {

      // ... isto significa que todas as Variáveis já foram declaradas anteriormente
        return Tipo::nulo;
    }

  // Retorna o tipo do Nodo
    return Tipo::definicao_arranjo;
}


void DefinicaoArranjo::imprimir(int espaco, bool imprimirArray) {

  // A primeira definição após a declaraçãp imprime "array:"
    if(imprimirArray) {
        std::cout << " array: ";
    }
    variavel->imprimir(0, true);
    if(proxima != NULL) {
        std::cout << ", ";        
        proxima->imprimir(0, false);
    }
}


void DefinicaoArranjo::ajustarProxima(DefinicaoArranjo *p) {
    if(proxima != NULL) {
        proxima->ajustarProxima(p);
    } else {
      proxima = p;
    }
}



//////////////
// Arranjo //

Tipo Arranjo::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // O tipo usado como índice é válido?
    Tipo indice = tamanho->analisar(tabelaSimbolos, linha);
    if(indice != Tipo::inteiro) {
        std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received ";
        std::cerr << imprimirTipoPorExtenso(indice) << "\n"; 
    }

  // O arranjo foi declarado? Senão o erro é imprimido pela tabela
    Arranjo *v = ((Arranjo*) tabelaSimbolos->recuperar(id, linha, true));
    if(v != NULL) {
        return v->tipoDeVariavel;
    }

  // Retorna o tipo
    return tipoDeVariavel;
}


void Arranjo::imprimir(int espaco, bool declaracao) {    

 // Impressão para declaração de arranjo
    if(declaracao) {
        std::cout << id << " (size: ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
        std::cout << ")";
    }

  // Impressão para uso comum
    else {
        std::cout << "[index] " << id << " ";
        if(tamanho != NULL) {        
            tamanho->imprimir(0, false);
        }
    }
}



/////////////////////
// OperacaoUnaria //

Tipo OperacaoUnaria::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {
 
  // Captura o tipo do filho
    Tipo d = filho->analisar(tabelaSimbolos, linha);

  // Operações Unárias possuem tratamento diferenciado
    switch(operacao) {

      // Operação de Negação recebe um "int" ou "float" e devolve "int" ou "float"
        case Tipo::negacao:
            if(d == Tipo::boolean) {
                imprimirErroDeOperacao(tipo, Tipo::inteiro, d, linha);
            }
            return d;

      // Operação Inversão (Negação Lógica) recebe "bool" e devolve "bool"
        case Tipo::inversao:
            if( d != Tipo::boolean) {
                imprimirErroDeOperacao(tipo, Tipo::boolean, d, linha);
            }              
            return Tipo::boolean;

      // Conversões retornam o tipo convertido, independente da entrada
        case Tipo::conversao_int:    return Tipo::inteiro;
        case Tipo::conversao_float:  return Tipo::real;   
        case Tipo::conversao_bool:   return Tipo::boolean;

      // Parênteses apenas retornam o tipo contido
        case Tipo::parenteses:  return d;

      // Por padrão, retorna o tipo do nodo
        default:  return Tipo::nulo;
    }
}


void OperacaoUnaria::imprimir(int espaco, bool novaLinha) {
    imprimirTipo(operacao);
    filho->imprimir(0, false);
}



//////////////////////
// OperacaoBinaria //

Tipo OperacaoBinaria::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {  

  // Captura os tipos dos filhos esquerda e direita
    Tipo e = esquerda->analisar(tabelaSimbolos, linha);
    Tipo d = direita->analisar(tabelaSimbolos, linha);

  // Operações Binárias possuem comportamentos diferentes
    switch(operacao) {

  // A Atribuição recebe "int","float" ou "bool" e retorna "int", "float" ou "bool"
        case Tipo::atribuicao:
            coercao(this, e, d, linha);
            return e;

  // Operaçãos Aritméticas recebem "int" ou "float" e devolvem "int" ou "float"
        case Tipo::adicao:
        case Tipo::subtracao:
        case Tipo::multiplicacao:
        case Tipo::divisao:
            
          // O tipo da esquerda é inválido?
            if(e == Tipo::boolean) {
                imprimirErroDeOperacao(operacao, Tipo::inteiro, e, linha);
            }

          // O tipo da direita é inválido?
            else if (d == Tipo::boolean) {
                imprimirErroDeOperacao(operacao, e, d, linha);
            }
   
          // A coerção de tipos é necessária?
            if(coercao(this, e, d, linha)) {

              // Se a coerção ocorre, é garantido que a operação binária retorna um tipo float
                return Tipo::real;
            } 

          // Caso não ocorra coerção, os tipos da esquerda e direita são iguais
            return e;
            

  // Operações Lógicas recebem "bool" e devolvem "bool"
         case Tipo::e:
         case Tipo::ou:

          // O tipo da esquerda é válido?
            if(e != Tipo::boolean) {
                imprimirErroDeOperacao(operacao, Tipo::boolean, e, linha);
            }

          // O tipo da direita é válido?
             else if (d != Tipo::boolean) {
              imprimirErroDeOperacao(operacao, Tipo::boolean, d, linha);
            }

          // Retorna o tipo boolean
           return Tipo::boolean;
           break;

  // Comparadores recebem "int" ou "float" e devolvem "bool"
         case Tipo::igual:
         case Tipo::diferente:
         case Tipo::maior:
         case Tipo::maior_igual:
         case Tipo::menor:
         case Tipo::menor_igual:

          // O tipo da esquerda é válido?
            if(e == Tipo::boolean) {
                imprimirErroDeOperacao(operacao, Tipo::inteiro, e, linha);
            }

          // O tipo da direita é válido?
            else if (d == Tipo::boolean) {
                imprimirErroDeOperacao(operacao, e, d, linha);
            }

          // Realiza-se coerção, se necessário
            coercao(this, e, d, linha);

          // Independente do retorno da coerção, retorna-se um valor booleano
            return Tipo::boolean;
            break;

      // Caso ocorra uma operação inválida, retorna-se Tipo::nulo
        default:
            return Tipo::nulo;
            break;               
      }
}


void OperacaoBinaria::imprimir(int espaco, bool novaLinha) {  
    imprimirEspaco(espaco);
    imprimirTipo(operacao);
    std::cout << " ";
    esquerda->imprimir(0, false);
    std::cout << " ";
    direita->imprimir(0, false);
    if(novaLinha) std::cout << "\n";
}



///////////////
// Condicao //

Tipo Condicao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // O teste de uma Condição deve ser Booleano
    Tipo esperado = teste->analisar(tabelaSimbolos, linha);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado, linha);
    }   

  // Caso "se" não seja nulo, cria um escopo próprio e é avaliado
    if(se != NULL) {
        TabelaDeSimbolos *novoEscopo = tabelaSimbolos->novoEscopo(tabelaSimbolos);
        se->analisar(novoEscopo, linha);
        novoEscopo->retornarEscopo(linha);
    }

  // Caso "senão" não seja nulo, cria um escopo próprio e é avaliado
    if(senao != NULL) {
        TabelaDeSimbolos *novoEscopo = tabelaSimbolos->novoEscopo(tabelaSimbolos);
        senao->analisar(novoEscopo, linha);
        novoEscopo->retornarEscopo(linha);  
    }

  // Retorna o tipo do nodo
    return tipo;
}


void Condicao::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    std::cout << "if: ";
    teste->imprimir(0, false);
    if(se != NULL) {
        std::cout << "\n";
        imprimirEspaco(espaco);
        std::cout << "then:\n";
        se->imprimir(espaco+2, false);
    }
    if(senao != NULL) {        
        imprimirEspaco(espaco);
        std::cout << "else:\n";
        senao->imprimir(espaco+2, false);
    }
    if(se == NULL && senao == NULL) std::cout << "\n";
}



///////////
// Laco //

Tipo Laco::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Analisa-se a inicialização do Laço, caso ela exista
    if(inicializacao != NULL) {
        inicializacao->analisar(tabelaSimbolos, linha);
    }

  // O teste de um Laço deve ser Booleano
    Tipo esperado = teste->analisar(tabelaSimbolos, linha);
    if(esperado != Tipo::boolean) {
        imprimirErroDeOperacao(Tipo::teste, Tipo::boolean, esperado, linha);
    }

  // Analisa-se a iteração do Laço, caso ela exista
    if(iteracao != NULL) {
        iteracao->analisar(tabelaSimbolos, linha);
    }

  // Se o conteúdo do laço não for vazio, também deve ser verificado
    TabelaDeSimbolos *novoEscopo;
    if(laco != NULL) {
        novoEscopo = tabelaSimbolos->novoEscopo(tabelaSimbolos);
        laco->analisar(novoEscopo, linha);
        novoEscopo->retornarEscopo(linha);
    }

  // Retorna o tipo do nodo
    return tipo;
}


void Laco::imprimir(int espaco, bool novaLinha) {
    imprimirEspaco(espaco);
    std::cout << "for: ";
    if(inicializacao != NULL) {
        inicializacao->imprimir(0, false);
    }
    std::cout << ", ";   
    teste->imprimir(0, false);
    std::cout << ", ";
    if(iteracao != NULL) {
        iteracao->imprimir(0, false);
    }
    std::cout << "\n";
    imprimirEspaco(espaco);
    std::cout << "do:";
    if(laco != NULL) {
        std::cout << "\n";
        laco->imprimir(espaco+2, true);
    } else {
        std::cout << "\n";
    }
}



/////////////
// Funcao //

Tipo Funcao::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

  // Conta a quantidade de parâmetros: se não houver parâmetros a quantidade é 0
    contarParametros();

  // Declaração de Nova Função
    if(tipo == Tipo::funcao_dec) {
  
      // Adiciona-se a função à tabela de funções
        tabelaSimbolos->adicionar(this, linha, false);

      // Retorna-se o tipo
        return tipo;
    } 

  // Definição ou Chamada de Função
    else {

      // Instancia o novo escopo
        TabelaDeSimbolos *novoEscopo; 
        novoEscopo = tabelaSimbolos->novoEscopo(tabelaSimbolos);

      // Recupera a Função, caso contrário um erro semântico é lançado pela Tabela de Símbolos
        Funcao *f = ((Funcao*) tabelaSimbolos->recuperar(id, linha, false));
        if(f != NULL) {
          
          // Obtém a quantidade de parâmetros da Função encontrada na Tabela de Símbolos
            int quantidadeEsperada = f->contarParametros();

          // Se a quantidade de parâmetros for diferente, ocorre um erro semântico
            if(quantidadeDeParametros != quantidadeEsperada) {
                std::cerr << "[Line " << linha << "] semantic error: function " << id;
                std::cerr << " expects " << quantidadeEsperada << " parameters";
                std::cerr << " but received " << quantidadeDeParametros << "\n";
            }

          // Se os parâmetros não foram nulos, eles podem ser comparados
            else if(parametros != NULL) {                
                ((Parametro*)f->parametros)->comparar(novoEscopo, ((Parametro*)parametros), linha, (tipo == Tipo::funcao_def));
            }

          // Atribui o tipo da função definida à declaração ou chamada
            tipoDoRetorno = f->tipoDoRetorno;

 // Definições de Função acrescentam à Declaração na Tabela de Símbolos
            if(tipo == Tipo::funcao_def) {

              // Caso a função já tenha sido definida, erro semântico
                if(f->definida) {
                    std::cerr << "[Line " << linha << "] semantic error: re-definition of function " << id << "\n";
                    return f->tipoDoRetorno;
                }

              // Se o corpo da Função não for nulo, ele deve ser analisado
                if(corpo != NULL) {                  
                    corpo->analisar(novoEscopo, linha);                    
                    f->corpo = corpo;
                }

              // Marca a função como já definida
                f->definida = true;
            }
        }
      // Retorna ao escopo anterior a Função
        novoEscopo->retornarEscopo(linha);    
    }
  // Retorna o tipo da variável retornada pela função
    return tipoDoRetorno;
}


void Funcao::imprimir(int espaco, bool novaLinha) {
    if(tipo == Tipo::funcao_def) {
        imprimirEspaco(espaco);
        imprimirTipo(tipoDoRetorno);
        std::cout << " fun: " << id << " (params: ";
        if(parametros != NULL) {
            parametros->imprimir(0, true);
        }
        std::cout << ")\n";
        if(corpo != NULL) {
            corpo->imprimir(espaco+2, true);
        }
        imprimirEspaco(espaco);        
        std::cout << "  ret ";
        retorno->imprimir(espaco+2, false);
        std::cout << "\n";
    } else if (tipo == Tipo::funcao_cha) {
        std::cout << id << "["<< quantidadeDeParametros << " params]";
        if(parametros != NULL) {
            parametros->imprimir(0, false);
        }
    }
}


int Funcao::contarParametros() {
    if(parametros == NULL) {
        quantidadeDeParametros = 0;
    } else {
        quantidadeDeParametros = ((Parametro*)parametros)->contar();
    }    
    return quantidadeDeParametros;
}



////////////////
// Parametro //

Tipo Parametro::analisar(TabelaDeSimbolos *tabelaSimbolos, int linha) {
    if(parametro != NULL) {
        tabelaSimbolos->adicionar(parametro, linha, true);
    }
    if(proximo != NULL) {
        proximo->analisar(tabelaSimbolos, linha);
    }
    return tipo;
}


void Parametro::imprimir(int espaco, bool naoArgumento) {
    imprimirEspaco(espaco);
    if(naoArgumento) {
        imprimirTipo(tipoDoParametro);
    }
    std::cout << " ";
    parametro->imprimir(0,false);
    if(proximo != NULL) {
       if(naoArgumento) {
           std::cout << ", ";
       }
       proximo->imprimir(espaco, naoArgumento);
    }
}


void Parametro::comparar(TabelaDeSimbolos *tabelaSimbolos, Parametro *comparado, int linha, bool naoArgumento) {

      // Adiciona o parâmetro ao escopo da função
        ((Variavel*)parametro)->tipoDeVariavel = tipoDoParametro;
        tabelaSimbolos->adicionar(parametro,linha, true);

      // Coleta os tipos dos parâmetros
        Tipo tipoComparado;
        if(naoArgumento) {
            tipoComparado = comparado->tipoDoParametro;
        } else {
            tipoComparado = comparado->parametro->analisar(tabelaSimbolos, linha);
        } 

      // Se os parâmetros forem do mesmo tipo
        if(tipoDoParametro == tipoComparado) {

          // Caso se trate de um parâmetro, não um argumento de uma chamada de função...
            if(naoArgumento) {

              // Captura-se os nomes dos parâmetros
                std::string nomeEsperado = ((Variavel*) parametro)->id;
                std::string nomeRecebido = ((Variavel*) comparado->parametro)->id;

              // Compara-se os nomes dos parâmetros, se forem diferentes um erro é emitido
                if(nomeEsperado.compare(nomeRecebido) != 0) {
                    std::string id = ((Variavel*) parametro)->id;
                    std::cerr << "[Line " << linha << "] semantic error: parameter " << nomeEsperado;
                    std::cerr << " expected to be called " << nomeEsperado << " but was named " << nomeRecebido << "\n"; 
                }
            }            
        }

      // Se o Parâmetro atual for diferente do Parâmetro comparado, erro 
        else {
            std::string id = ((Variavel*) parametro)->id;
            std::cerr << "[Line " << linha << "] semantic error: parameter " << id;
            std::cerr << " expected " << imprimirTipoPorExtenso(tipoDoParametro);
            std::cerr << " but received " << imprimirTipoPorExtenso(tipoComparado) << "\n";              
        }   

      // Se os parâmetros atuais forem igual e os próximos forem nulos, então todos os Parâmetro são iguais
        if(proximo != NULL && comparado->proximo != NULL) {           
        // Caso contrário, compara os próximos parâmetros
            ((Parametro*)proximo)->comparar(tabelaSimbolos, ((Parametro*)comparado->proximo), linha, naoArgumento);
        }
}


int Parametro::contar() {
    if(proximo == NULL) {
        return 1;
    } else {
        return (((Parametro*)proximo)->contar() + 1);
    }    
}



////////////
// Bloco //

Tipo Bloco::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

// Associa o escopo ao Bloco
  escopo = tabelaSimbolos;  

  // Verificar os Tipos de todas as linhas do Bloco   
    for (Nodo* l: linhas) {
        if(l != NULL) {
            linha++;
            l->analisar(escopo, linha);
        }
    }

  // Desempilha-se este escopo, removendo seu endereçamento da tabela de símbolos ...
  // ... sendo o ponteiro para o escopo guardado apenas no Nodo::Bloco
    escopo->retornarEscopo(linha);

  // O Bloco não possui um Tipo a ser retornado
    return Tipo::nulo;
}


void Bloco::imprimir(int espaco, bool novaLinha) {
    for (Nodo* l: linhas) {
        if(l != NULL) {
            l->imprimir(espaco, true);
        }
    }
}


void Bloco::novaLinha(Nodo *linha) {
    linhas.push_back(linha);
}



///////////
// Nodo //

bool Nodo::coercaoDaDefinicao(Definicao *coagido, Tipo esperado, Tipo recebido, int linha) {

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
        case Tipo::inteiro:          std::cout << "int";       break;
        case Tipo::real:             std::cout << "float";     break;
        case Tipo::boolean:          std::cout << "bool";      break;
        case Tipo::atribuicao:       std::cout << "=";         break; //
        case Tipo::adicao:           std::cout << "+";         break;
        case Tipo::subtracao:        std::cout << "-";         break;
        case Tipo::multiplicacao:    std::cout << "*";         break;
        case Tipo::divisao:          std::cout << "/";         break;
        case Tipo::e:                std::cout << "&";         break;
        case Tipo::ou:               std::cout << "|";         break;
        case Tipo::igual:            std::cout << "==";        break; //
        case Tipo::diferente:        std::cout << "!=";        break;
        case Tipo::maior:            std::cout << ">";         break;
        case Tipo::maior_igual:      std::cout << ">=";        break;
        case Tipo::menor:            std::cout << "<";         break;
        case Tipo::menor_igual:      std::cout << "<=";        break;
        case Tipo::negacao:          std::cout << "-u ";       break; //
        case Tipo::inversao:         std::cout << "! ";        break;
        case Tipo::conversao_int:    std::cout << "[int] ";    break;
        case Tipo::conversao_float:  std::cout << "[float] ";  break;
        case Tipo::conversao_bool:   std::cout << "[bool] ";   break;
        case Tipo::parenteses:       std::cout << "";          break; //
        default:                     std::cout << "";          break;
    }
}


std::string Nodo::imprimirTipoPorExtenso(Tipo t) {
  // One switch to rule them all
    switch(t) {
        case Tipo::inteiro:          return "integer";         
        case Tipo::real:             return "float";           
        case Tipo::boolean:          return "bool";            
        case Tipo::atribuicao:       return "attribution";     
        case Tipo::adicao:           return "addition";        
        case Tipo::subtracao:        return "subtraction";     
        case Tipo::multiplicacao:    return "multiplication";  
        case Tipo::divisao:          return "division";        
        case Tipo::e:                return "and";             
        case Tipo::ou:               return "or";              
        case Tipo::negacao:          return "- ";        
        case Tipo::inversao:         return "! ";              
        case Tipo::igual:            return "==";              
        case Tipo::diferente:        return "!= ";             
        case Tipo::maior:            return "> ";              
        case Tipo::maior_igual:      return ">= ";             
        case Tipo::menor:            return "< ";              
        case Tipo::menor_igual:      return "<= ";             
        case Tipo::conversao_int:    return "[int] ";          
        case Tipo::conversao_float:  return "[float] ";        
        case Tipo::conversao_bool:   return "[bool] ";         
        case Tipo::parenteses:       return "()";
        case Tipo::teste:            return "test";    
        case Tipo::nulo:             return "null";          
        default:                     return " ";            
    }
}


void Nodo::imprimirErroDeOperacao(Tipo operacao, Tipo esperava, Tipo recebeu, int linha) {
    std::cerr << "[Line " << linha << "] semantic error:" << " operation " << imprimirTipoPorExtenso(operacao);
    std::cerr << " expected " << imprimirTipoPorExtenso(esperava);
    std::cerr << " but received " <<  imprimirTipoPorExtenso(recebeu);
    std::cerr << "\n";

}



///////////////////////
// TabelaDeSimbolos //

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
        if(iterator->second->tipo == Tipo::funcao_def) {
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
        return true;
    }    
}


bool TabelaDeSimbolos::adicionar(AST::Nodo *v, int linha, bool variavel) {

  // Se a Variável ou Função não foi declarada, ela é adicionada ao map
    std::string id;
    std::map<std::string, AST::Nodo*>::const_iterator it;
    it = simbolos.find(id);
    if (it == simbolos.end()) {
        simbolos.insert ( std::pair< std::string, AST::Nodo*> (v->id,v) );
        return true;

  // Caso a Variável ou Função já tenha sido declarada, ocorre um erro semântico
    } else if (variavel) {
        std::cerr << "[Line " << linha << "] semantic error: re-declaration of variable " << v->id << "\n";         
    } else {
        std::cerr << "[Line " << linha << "] semantic error: re-declaration of function " << v->id << "\n"; 
    }
    return false;
}


Nodo* TabelaDeSimbolos::recuperar(std::string id, int linha, bool variavel) {

  // Variável ou Função encontrada no escopo atual
    std::map<std::string, AST::Nodo*>::const_iterator it;
    it = simbolos.find(id);
    if (it != simbolos.end()) {
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

/*

bool TabelaDeSimbolos::funcaoOuArranjo(std::string nome) {

 No parser.y havia:
arranjo :
          T_VAR T_OPEN expressao T_CLOSE 
          { if(escopoPrincipal->funcaoOuArranjo($1)) {
                $$ = new AST::Arranjo( AST::Tipo::nulo , $1, $3 ); std::cerr << "arranjo: arranjo\n";
            } else {
                $$ = new AST::Funcao( AST::Tipo::funcao_cha, AST::Tipo::nulo , $1 , new AST::Parametro( AST::Tipo::nulo, $3, NULL ) , NULL , NULL ); std::cerr << "arranjo: funcao\n";
            }
          }
        ;


  // Alcança o último escopo definido
    if(proximo != NULL) {
        return proximo->funcaoOuArranjo(nome);
    }

  // Tenta encontrar o nome na tabela de símbolos
    Nodo *n = recuperar(nome, -1, false);
    if(n != NULL) {

      // Caso uma função já tenha sido definida com o nome, retorna-se true
        switch(n->tipo) {
            case Tipo::funcao_dec:
            case Tipo::funcao_def:
            case Tipo::funcao_cha:
                std::cerr << "found function!\n";
                return false;
            case Tipo::arranjo:
                std::cerr << "found array!\n";
                return true;      
            default:
                break;      
        }
    }
    std::cerr << "found nothing!\n";
  // Se o nome estiver livre, retorna-se true
    return true;
}
*/


///////////////////////
// ChamadaOuArranjo //

Tipo ChamadaOuArranjo::analisar(AST::TabelaDeSimbolos *tabelaSimbolos, int linha) {

    Nodo *n = tabelaSimbolos->recuperar(id, -1, false);
    if(n != NULL) {

//std::cerr <<"@@@ chamadaOuArranjo " << id << " / " << n->tipo << "\n";
        id = n->id;
        switch(n->tipo) {
            case Tipo::funcao_dec:
            case Tipo::funcao_def: {
            //case Tipo::funcao_cha:
//std::cerr <<"@@@ chamadaOuArranjo - chamada de " << n->id << "\n";

              // Define o tipo desta ChamadaOuArranjo como Chamada de Função
                tipo = Tipo::funcao_cha;

              // Conta a quantidade de parâmetros: se não houver parâmetros a quantidade é 0
                contarParametros();              
              
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
                    ((Parametro*)f->parametros)->comparar(tabelaSimbolos, ((Parametro*)parametros), linha, (tipo == Tipo::funcao_def));
                } 

             // Atribui o tipo da função definida à declaração ou chamada
                tipoDoRetorno = f->tipoDoRetorno;

            //std::cerr << "@@@ chamadaOuArranjo - " << tipoDoRetorno <<"\n";

             // Retorna o tipo da variável retornada pela função
               return tipoDoRetorno;

            }
            case Tipo::arranjo: {
//std::cerr <<"@@@ chamadaOuArranjo - arranjo " << n->id << ", this: " << id << "\n";
              // Define o tipo desta ChamadaOuArranjo como Arranjo
                tipo = Tipo::arranjo;
                
              // Recupera o Arranjo 
                Arranjo *v = ((Arranjo*) n);

//              std::cerr << "@@@ retorno=tamanho : " << parametros->id << "\n";

              // O tipo usado como índice é válido? parametros = tamanho
                Tipo indice = parametros->analisar(tabelaSimbolos, linha);
                if(indice != Tipo::inteiro) {
                    std::cerr << "[Line " << linha << "] semantic error: index operator expects integer but received ";
                }
                return v->tipoDeVariavel;
            }
            default: 
                break;
        }
    }
    std::cerr << "Não declarado\n";
    return tipo;
}


void ChamadaOuArranjo::imprimir(int espaco, bool declaracao) {    
    if(tipo == funcao_cha) {
        std::cout << id << "["<< quantidadeDeParametros << " params]";        
    } else {
        std::cout << "[index] " << id << "";        
    }
    if(parametros != NULL) {
        parametros->imprimir(0, false);
    }
}


int ChamadaOuArranjo::contarParametros() {
    if(parametros == NULL) {
        quantidadeDeParametros = 0;
    } else {
        quantidadeDeParametros = ((Parametro*)parametros)->contar();
    }    
    return quantidadeDeParametros;
}

