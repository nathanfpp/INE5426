#include <iostream>
#include <fstream>

extern int yyparse();
//extern int yydebug;

int main(int argc, char **argv)
{

  // Limpa o arquivo de erros antes de cada execução
    //yydebug = 1;              // remove comment to have verbose debug messages
    yyparse();                  //parses whole input
    return 0;
}
