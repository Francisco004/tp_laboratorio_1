#ifndef BIBLIOTECAEMPLEADO_H_INCLUDED
#define BIBLIOTECAEMPLEADO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000
#define VACIO 0
#define LLENO 1

typedef struct
{
    int id;
    int sector;
    int isEmpty;
    float salary;
    char name[51];
    char lastName[51];

} eEmpleado;



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
 * \param unEmpleado[] eEmpleado el empleado
 * \param int tamaño a recorrer
 * \return int retorna el lugar libre para la id
 *
 */
int buscarLibre(eEmpleado unEmpleado[], int);


/** \brief inicializa a todos los empleados con datos en 0
 *
 * \param empleados[] eEmpleado lista de empleados
 * \param int tamaño a recorrer
 * \return void
 *
 */
void inicializarEmpleados(eEmpleado empleados[], int);


/** \brief Hardcodea los empleados
 *
 * \param empleados[] eEmpleado lista de los empleados
 * \return void
 *
 */
void hardcodearEmpelados(eEmpleado empleados[]);



/** \brief Muestra un empleado
 *
 * \param empleado eEmpleado un empleado
 * \return void
 *
 */
void mostrarUnEmpleado(eEmpleado empleado);


/** \brief Ordena los empleados
 *
 * \param empleado[] eEmpleado listado de empleados
 * \param int tamaño de iteraciones
 * \return void
 *
 */
void ordenarEmpleados(eEmpleado empleado[], int);


/** \brief Da de alta un empleado calculando el id automaticamente
 *
 * \param unEmpleado[] eEmpleado un empleado
 * \param int tamaño de iteraciones
 * \return void
 *
 */
void altaDeUnEmpleado(eEmpleado unEmpleado[], int);


/** \brief Muestra todos los empleados
 *
 * \param empleado[] eEmpleado un empleado
 * \param int tamaño de iteraciones
 * \return void
 *
 */
void mostrarUnEmpleados(eEmpleado empleado[], int);


/** \brief Da de baja un empleado ingresando la id
 *
 * \param unEmpleado[] eEmpleado un empleado
 * \param int tamaño de iteraciones
 * \return void
 *
 */
void darDeBajaUnEmpleado(eEmpleado unEmpleado[], int);


/** \brief Modifica un empleado ingresando la id
 *
 * \param unEmpleado[] eEmpleado un empleado
 * \param int tamaño de iteraciones
 * \return void
 *
 */
void modificarUnEmpleado(eEmpleado unEmpleado[], int);


/** \brief Calcula y muestra el promedio de los salarios
 *
 * \param unEmpleado[] eEmpleado un empleado
 * \param int tamaño de iteraciones
 * \return void
 *
 */
void informarPromedioSalarios(eEmpleado unEmpleado[], int);

#endif // BIBLIOTECAEMPLEADO_H_INCLUDED
