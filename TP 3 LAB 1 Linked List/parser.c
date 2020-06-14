#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "Employee.h"
#include "LinkedList.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pArchivo;
    char ID[50];
    int reto = -1;
    char Horas[50];
    char Nombre[50];
    char Sueldo[50];
    int vandera = 1;

    if(pFile!= NULL)
    {
        while(!feof(pFile))
        {
            if(vandera)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", ID, Nombre, Horas, Sueldo);
                vandera = 0;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", ID, Nombre, Horas, Sueldo);
            pArchivo = employee_newParametros(ID, Nombre, Horas, Sueldo);
            if(pArchivo !=NULL)
            {
                ll_add(pArrayListEmployee,pArchivo);
                reto = 0;
            }
        }
    }
    return reto;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;

    int i;
    int ID;
    int Horas;
    int sueldo;
    int ultimaID;
    int reto = -1;
    char Nombre[50];

    if(pFile!=NULL)
    {
        reto = 0;
        while(!feof(pFile))
        {
            pEmpleado = employee_new();

            fread(pEmpleado,sizeof(Employee),1,pFile);

            employee_getId(pEmpleado,&ID);
            employee_getNombre(pEmpleado,Nombre);
            employee_getSueldo(pEmpleado,&sueldo);
            employee_getHorasTrabajadas(pEmpleado,&Horas);
            if( ID >= 0 && strlen(Nombre) > 0 && Horas > 0 && sueldo > 0)
            {
                ll_add(pArrayListEmployee, pEmpleado);
                ultimaID = ID;
            }
        }
        for(i=0; i<=ultimaID; i++)
        {
            dameLaProximaID();
        }
    }
    return reto;
}

int guardarFormatoTexto(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* Empleado;

    int i;
    int ID;
    int horas;
    int sueldo;
    int tamanio;
    int reto = -1;
    char nombre[1000];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        tamanio = ll_len(pArrayListEmployee);

        for(i=0; i<tamanio; i++)
        {
            Empleado = ll_get(pArrayListEmployee,i);
            dameTodo(Empleado,nombre,&horas,&sueldo,&ID);
            fprintf(pFile,"%d,%s,%d,%d\n",ID,nombre,horas,sueldo);
            reto = 0;
        }
    }
    return reto;
}

int guardarFormatoBinario(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int reto = -1;
    int i = 0;
    int ID;
    char nombre[51];
    int horas;
    int sueldo;
    Employee* Empleado;

    if(pFile != NULL)
    {
        reto = 0;
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            Empleado = ll_get(pArrayListEmployee,i);

            employee_getId(Empleado,&ID);
            employee_getNombre(Empleado,nombre);
            employee_getSueldo(Empleado,&sueldo);
            employee_getHorasTrabajadas(Empleado,&horas);

            if( ID > 0 && strlen(nombre) > 0 && horas > 0 && sueldo > 0)
            {
                fwrite(Empleado,sizeof(Employee),1,pFile);
            }
        }
    }
    return reto;
}
