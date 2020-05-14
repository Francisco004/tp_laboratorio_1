#ifndef BIBLIOTECAEMPLEADO_H_INCLUDED
#define BIBLIOTECAEMPLEADO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000
#define VACIO -1
#define LLENO 0

typedef struct
{
    int id;
    int sector;
    int isEmpty;
    float salary;
    char name[51];
    char lastName[51];

} sEmployee;



/** \brief Muestra el menu de opciones
 *
 * \return int Retorna la opcion seleccionada
 *
 */
int menu();


/** \brief Valida si lo que se ingreso es una cadena de caracteres
 *
 * \param [] char la cadena de caracteres
 * \return int retorna 0 si es correcto o 1 si es incorrecto
 *
 */
int validarString(char []);


/** \brief Busca la id para un empleado verificando el estado de los empleados
 *
 * \param List[] sEmployee el empleado
 * \param int tamanio a recorrer
 * \return int retorna el lugar libre para la id
 *
 */
int findEmployeeById(sEmployee List[], int);





/** \brief inicializa a todos los empleados con datos en 0
 *
 * \param List[] sEmployee lista de empleados
 * \param int tamanio a recorrer
 * \return void
 *
 */
int initEmployees(sEmployee* empleados, int);


/** \brief Da de alta un empleado calculando el id automaticamente
 *
 * \param List[] sEmployee un empleado
 * \param int tamanio de iteraciones
 * \return void
 *
 */
void addEmployees(sEmployee List[], int);


/** \brief Da de baja un empleado ingresando la id
 *
 * \param List[] sEmployee un empleado
 * \param int tamanio de iteraciones
 * \return void
 *
 */
void removeEmployee(sEmployee List[], int);


/** \brief Modifica un empleado ingresando la id
 *
 * \param List[] sEmployee un empleado
 * \param int tamanio de iteraciones
 * \return void
 *
 */
void modifyEmployee(sEmployee List[], int);





/** \brief Muestra un empleado
 *
 * \param empleado sEmployee un empleado
 * \return void
 *
 */
void printOneEmployee(sEmployee empleado);

/** \brief Muestra todos los empleados
 *
 * \param empleado[] sEmployee un empleado
 * \param int tamanio de iteraciones
 * \return void
 *
 */
void printEmployees(sEmployee List[], int);

/** \brief Calcula y muestra el promedio de los salarios
 *
 * \param List[] sEmployee un empleado
 * \param int tamanio de iteraciones
 * \return void
 *
 */
void printAverageSalaries(sEmployee List[], int);


/** \brief Ordena los empleados
 *
 * \param empleado[] sEmployee listado de empleados
 * \param int tamanio de iteraciones
 * \return void
 *
 */
void sortEmployees(sEmployee empleado[], int);

#endif // BIBLIOTECAEMPLEADO_H_INCLUDED
