#ifndef TRATADORARITIMETICO_H
#define TRATADORARITIMETICO_H

#include "estruturas.h"
#include <map>
#include <string>

class tratadorAritmetico {
    public:
        int operarNumeros(int a, int b, char signal);
        double operarNumeros(double a, double b, char signal);
	bool operarBooleanos(bool a, bool b, char signal);
	bool operarBooleanos(int a, int b, char signal);
        bool operarBooleanos(double a, double b, char signal);
    private:
        //
};

#endif /* TRATADORARITIMETICO_H */
