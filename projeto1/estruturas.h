#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include <string>
//Todas as estruturas utilizadas no union, colocar aqui permite que outras classes possam tratar essas estruturas.

typedef struct  {
       char *var;   // Nome da variável
       int integer; // Valor inteiro
       double real; // Valor em float
       char *type;  // Tipo da variavel
} atributo;   

#endif
