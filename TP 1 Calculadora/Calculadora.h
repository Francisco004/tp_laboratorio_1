#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void menu_Calculadora(void);

float primer_Numero(void);
float segundo_Numero(void);

int validar_Numeros(char []);

float operacion_Suma(float ,float );
float operacion_Resta(float ,float );
float operacion_Division(float ,float );
float operacion_Multiplicacion(float ,float );
unsigned operacion_Factorial_Primero(float);
float operacion_Factorial_Segundo(float ,float );


#endif // CALCULADORA_H_INCLUDED
