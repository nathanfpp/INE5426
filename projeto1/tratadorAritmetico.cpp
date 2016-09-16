#include <iostream>
#include <string>
#include "tratadorAritmetico.h"

int tratadorAritmetico::operarNumeros(int a, int b, char signal) {
	switch(signal) {
		case '+': 
		      return a + b;

		case '-': 
                      return a - b;

		case '*': 
                      return a * b;

		case '/': 
                      return a / b;
	}
	return 0;
}

double tratadorAritmetico::operarNumeros(double a, double b, char signal) {
	switch(signal) {
		case '+': 
		      return a + b;
		case '-': 
                      return a - b;
		case '*': 
                      return a * b;
		case '/': 
                      return a / b;
	}
	return 0.0;
}

bool tratadorAritmetico::operarBooleanos(bool a, bool b, char signal) {
	switch(signal) {
		case '&': // AND
			return (a && b);
		case '|': // OR
			return (a || b);
		case 'e': // ==
			return (a == b);
		case 'd': // !=
			return (a != b);
	}
	return false;
}

bool tratadorAritmetico::operarBooleanos(int a, int b, char signal) {
	switch(signal) {
		case 'e': // ==
			return a == b;
		case 'n': // !=
			return a != b;
		case 'm': // >
			return a > b;
		case 'h': // >=
			return a >= b;
		case 'r': // <
			return a < b;
		case 'l': // <=
			return a <= b;
	}
	return false;
}

bool tratadorAritmetico::operarBooleanos(double a, double b, char signal) {
	switch(signal) {
		case 'e': // ==
			return a == b;
		case 'n': // !=
			return a != b;
		case 'm': // >
			return a > b;
		case 'h': // >=
			return a >= b;
		case 'r': // <
			return a < b;
		case 'l': // <=
			return a <= b;
	}
	return false;
}
