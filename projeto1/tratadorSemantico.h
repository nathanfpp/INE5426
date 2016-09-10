#ifndef TRATADORSEMANTICO_H
#define TRATADORSEMANTICO_H

#include "estruturas.h"
#include <map>
#include <string>

class tratadorSemantico {
public:
    bool   avaliarDeclaracao(std::map<std::string, atributo> tabela_simbolos, atributo value);
    bool   avaliarRepeticaoDeclaracao(std::map<std::string, atributo> tabela_simbolos, atributo value);
    bool   avaliarTipo(atributo value_1, atributo value_2);
private:

};

#endif /* TRATADORSEMANTICO_H */
