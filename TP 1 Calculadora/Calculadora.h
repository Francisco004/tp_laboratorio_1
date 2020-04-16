#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/** \brief Muestra el menu de la calculadora
 *
 * \param void
 * \return void
 *
 */
void menu_Calculadora(void);

/** \brief pide el primer numero
 *
 * \param void
 * \return retorna el primer numero ingresado
 *
 */
float primer_Numero(void);

/** \brief pide el segundo numero
 *
 * \param void
 * \return retorna el segundo numero ingresado
 *
 */
float segundo_Numero(void);

/** \brief valida si solo se ingresaron numeros
 *
 * \param [] char pide el numero en tipo char para recorrerlo carcter por caracter
 * \return int retorna un 1 si tiene letras o retorna el numero si esta bien ingresado
 *
 */
float validar_Numeros(char []);

/** \brief suma los dos numeros ingresador
 *
 * \param float primer numero
 * \param float segundo numero
 * \return float retorna la suma de los dos numeros
 *
 */
float operacion_Suma(float ,float );

/** \brief resta los dos numeros ingresador
 *
 * \param float primer numero
 * \param float segundo numero
 * \return float retorna la resta de los dos numeros
 *
 */
float operacion_Resta(float ,float );

/** \brief realiza el factorial
 *
 * \param int el numero a factorear
 * \return long long int retorna el numero factorizado
 *
 */
long long int operacion_Factorial(int);

/** \brief divide los dos numeros ingresador
 *
 * \param float primer numero
 * \param float segundo numero
 * \return float retorna la division de los dos numeros
 *
 */
float operacion_Division(float ,float );

/** \brief multiplica los dos numeros ingresador
 *
 * \param float primer numero
 * \param float segundo numero
 * \return float retorna la multiplicacion de los dos numeros
 *
 */
float operacion_Multiplicacion(float ,float );

/** \brief muestra los resultados de las operaciones
 *
 * \param float primer numero ingresado
 * \param float segundo numero ingresado
 * \param float suma
 * \param float resta
 * \param float division
 * \param float multiplicacion
 * \return void
 *
 */
void mostrarResultados(float, float, float, float, float, float);



#endif // CALCULADORA_H_INCLUDED
