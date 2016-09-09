#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

//Todas as estruturas utilizadas no union, colocar aqui permite que outras classes possam tratar essas estruturas.

typedef struct  {
       char *var;   // Nome da variável
       int integer; // Valor inteiro
       double real; // Valor em float
       char *type;  // Tipo da variavel
       //char *linha;  //a linha do programa que servirá de print
} atributo;   

#endif
