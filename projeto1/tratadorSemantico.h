#ifndef TRATADORSEMANTICO_H
#define TRATADORSEMANTICO_H

#include "estruturas.h"
#include <map>
#include <string>

class tratadorSemantico {
public:
    bool   avaliarDeclaracao(std::map<std::string, atributo> tabela_simbolos, atributo value);
private:

};

#endif /* TRATADORSEMANTICO_H */
