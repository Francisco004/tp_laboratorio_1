#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Employee.h"
#include "LinkedList.h"
#include "Validacion.h"

Employee* employee_new()
{
    Employee* nuevoEmp;
    nuevoEmp=malloc(sizeof(Employee));
    if(nuevoEmp!=NULL)
    {
        return nuevoEmp;
    }
    else
    {
        return NULL;
    }
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoParametro;
    nuevoParametro = employee_new();

    int idCliente = atoi(idStr);
    int horasTrabajadas = atoi(horasTrabajadasStr);
    int sueldo = atoi(sueldoStr);

    if(!employee_setId(nuevoParametro,idCliente)&&!employee_setNombre(nuevoParametro,nombreStr)&&!employee_setHorasTrabajadas(nuevoParametro,horasTrabajadas)&& !employee_setSueldo(nuevoParametro,sueldo))
    return nuevoParametro;

    employee_delete(nuevoParametro);

    return NULL;
}

int dameTodo(Employee* this,char* nombre,int* horas,int* sueldo,int* id)
{
    int reto = -1;

    if(this != NULL)
    {
        employee_getNombre(this,nombre);
        employee_getHorasTrabajadas(this,horas);
        employee_getSueldo(this,sueldo);
        employee_getId(this,id);
        reto = 0;
    }
    return reto;
}

int employee_delete(Employee* borrarEmpleado)
{
   int reto = -1;
    if(borrarEmpleado != NULL)
    {
        free(borrarEmpleado);
        reto = 0;
    }
    return reto;
}

int dameLaProximaID()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}

int employee_setId(Employee* setID,int id)
{
 int reto=-1;
    static int proximoId=-1;

    if(setID!=NULL && id==-1)
    {
        proximoId++;
        setID->id=proximoId;
        reto=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        setID->id=proximoId;
        reto=0;
    }
    return reto;
}

int employee_setNombre(Employee* setNombre, char* nombre)
{
    int reto=-1;
    if(setNombre!=NULL && nombre!=NULL)
    {
        strcpy(setNombre->nombre,nombre);
        reto=0;
    }
    return reto;
}

int employee_getNombre(Employee* dameNombre, char* nombre)
{
   int reto=-1;
    if(dameNombre!=NULL && nombre!=NULL)
    {
        strcpy(nombre,dameNombre->nombre);
        reto=0;
    }
    return reto;
}

int employee_setHorasTrabajadas(Employee* setHoras,int horasTrabajadas)
{
    int reto=-1;
    if(setHoras!=NULL)
    {
        setHoras->horasTrabajadas=horasTrabajadas;
        reto=0;
    }
    return reto;
}

int employee_getHorasTrabajadas(Employee* dameHoras, int* horasTrabajadas)
{
    int reto=-1;
    if(dameHoras!=NULL)
    {
        *horasTrabajadas=dameHoras->horasTrabajadas;
        reto=0;
    }
    return reto;
}

int employee_setSueldo(Employee* setSalario, int sueldo)
{
     int reto=-1;
    if(setSalario!=NULL)
    {
        setSalario->sueldo=sueldo;
        reto=0;
    }
    return reto;
}

int employee_getSueldo(Employee* dameSalario, int* sueldo)
{
     int reto=-1;
    if(dameSalario!=NULL)
    {
        *sueldo=dameSalario->sueldo;
        reto=0;
    }
    return reto;
}

int employee_getId(Employee* dameID, int* id)
{
     int reto=-1;
    if(dameID!=NULL)
    {
        *id=dameID->id;
        reto=0;
    }
    return reto;
}

Employee* generadorDeID(char* nombre,int horasTrabajadas,int sueldo)
{
    Employee* nuevoEmpleado;
    nuevoEmpleado = employee_new();
    if(!employee_setId(nuevoEmpleado,-1)&&!employee_setNombre(nuevoEmpleado,nombre)&&!employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajadas)&&!employee_setSueldo(nuevoEmpleado,sueldo))
    return nuevoEmpleado;

    employee_delete(nuevoEmpleado);

    return NULL;
}

int ordenamientoPorNombre(void* x,void* y)
{
    int reto = 0;
    char nombreUno[50];
    char nombreDos[50];

   employee_getNombre(x,nombreUno);
   employee_getNombre(y,nombreDos);

   if(strcmp(nombreUno,nombreDos)>0)
   {
    reto = 1;
   }
   else if(strcmp(nombreUno,nombreDos)< 0)
   {
    reto = -1;
   }
    return reto;
}
