#ifndef TRATADORSEMANTICO_H
#define TRATADORSEMANTICO_H

#include "estruturas.h"
#include <map>
#include <string>

class tratadorSemantico {
public:
    bool   avaliarDeclaracao(std::map<std::string, atributo> tabela_simbolos, atributo value); //Confere se variável não foi declarada
    bool   avaliarRepeticaoDeclaracao(std::map<std::string, atributo> tabela_simbolos, atributo value);
    bool   avaliarTipoDefinido(atributo value); //Confere se variável já possui algum tipo
    bool   avaliarOperacao(atributo value_1, atributo value_2, char sinal); //Avalia se os operandos são do mesmo tipo
    bool   avaliarOperacao(std::string tipo, atributo value_2, char sinal); //Avalia se os operandos são do mesmo tipo
    std::string nomeDaOperacaoBinaria(char operacao);
private:

};

#endif /* TRATADORSEMANTICO_H */
