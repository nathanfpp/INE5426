#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include <string>

// Estruturas utilizadas na Union, presentes aqui para que outras classes possam também operá-las

typedef struct  {
       char   *var;     // Nome
       char   *type;    // Tipo
       int    integer;  // Valor inteiro
       double real;     // Valor ponto flutuante
       bool   boolean;  // Valor booleano
} atributo;   

#endif
