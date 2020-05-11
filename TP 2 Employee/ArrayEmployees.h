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



int menu();
int validarString(char []);
int buscarLibre(eEmpleado unEmpleado[], int);
int buscarID(eEmpleado unEmpleado[], int, int);
void inicializarEmpleados(eEmpleado empleados[], int);



void mostrarUnEmpleado(eEmpleado empleado);
void ordenarEmpleados(eEmpleado empleado[], int);
void altaDeUnEmpleado(eEmpleado unEmpleado[], int);
void mostrarUnEmpleados(eEmpleado empleado[], int);
void darDeBajaUnEmpleado(eEmpleado unEmpleado[], int);
void modificarUnEmpleado(eEmpleado unEmpleado[], int);
void informarPromedioSalarios(eEmpleado unEmpleado[], int);

#endif // BIBLIOTECAEMPLEADO_H_INCLUDED
