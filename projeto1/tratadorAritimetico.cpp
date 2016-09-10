#include <iostream>
#include <string>
#include "tratadorAritimetico.h"

int tratadorAritimetico::operarNumeros(int num1, int num2, char signal){

		     switch(signal)
                     {
                      case '+': 
		      return num1 + num2;
		      break;

		      case '-': 
                      return num1 - num2;
		      break;

		      case '*': 
                      return num1 * num2;
		      break;

		      case '/': 
                      return num1 / num2;
		      break;
                     }

}

double tratadorAritimetico::operarNumeros(double num1, double num2, char signal){

		     switch(signal)
                     {
                      case '+': 
		      return num1 + num2;
		      break;

		      case '-': 
                      return num1 - num2;
		      break;

		      case '*': 
                      return num1 * num2;
		      break;

		      case '/': 
                      return num1 / num2;
		      break;
                     }

}
