#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "Validacion.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int reto = -1;

    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo, pArrayListEmployee))
    {
        printf("\nLos datos se cargaron correctamente.\n\n");
        reto = 0;
    }
    else
    {
        printf("\nError archivo no existente o ya se cargo.\n\n");
    }
    fclose(pArchivo);
    system("pause");
    return reto;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path, "rb");
    if(!parser_EmployeeFromBinary(pArchivo, pArrayListEmployee))
    {
        printf("\nLos datos en binario se cargaron correctamente\n\n");
        retorno = 0;
    }
    else
    {
        printf("\nError archivo no existente o ya se cargo.\n\n");
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int id;
    int idAux;
    int codigo;
    int reto = -1;
    char verificacion;
    Employee* empleado;

    if(pArrayListEmployee !=NULL)
    {
            printf("Seguro que quiere borrar algun empleado? 's' = si / otro caracter = no: ");
            fflush(stdin);
            scanf("%c",&verificacion);

        if(verificacion == 's')
        {
            if(getInt(&id,"Ingrese el ID del empleado a borrar: ","\nError ID inexistente: ",0,10000,5)==0)
            {
            codigo = id - 1;
            buscarEmpleadoEspecifico(pArrayListEmployee,codigo);

            if(verificacion == 's')
            {
                for(i = 0; i< ll_len(pArrayListEmployee); i++)
                {
                empleado = ll_get(pArrayListEmployee,i);
                employee_getId(empleado,&idAux);

                    if(idAux == id)
                        {
                            employee_delete(empleado);
                            ll_remove(pArrayListEmployee,i);
                            printf("\nLa id que ingreso a sido borrada...\n\n");
                            system("pause");
                            reto = 0;
                            break;
                        }
                }
            }
            }
        }

    }
    return reto;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int id;
    int horas;
    int sueldo;
    int reto = -1;
    char nombre[128];
    Employee* pEmpleado;

    if(pArrayListEmployee !=NULL)
    {
        reto = 0;
        for(i=0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&id);
            employee_getNombre(pEmpleado,nombre);
            employee_getHorasTrabajadas(pEmpleado,&horas);
            employee_getSueldo(pEmpleado,&sueldo);

            printf("\nID: %d",id);
            printf("\nNombre: %s",nombre);
            printf("\nSueldo: %d",sueldo);
            printf("\nHoras trabajadas: %d",horas);
            printf("\n");
        }
    }
    system("pause");
    return reto;
}

void buscarEmpleadoEspecifico(LinkedList* pArrayListEmployee, int codigo)
{
    int i;
    int id;
    int horas;
    int sueldo;
    char nombre[128];
    Employee* pEmpleado;

    if(pArrayListEmployee != NULL)
    {
        for(i=0; i < 10000; i++)
        {

                pEmpleado = ll_get(pArrayListEmployee,i);
                employee_getId(pEmpleado,&id);
                employee_getNombre(pEmpleado,nombre);
                employee_getHorasTrabajadas(pEmpleado,&horas);
                employee_getSueldo(pEmpleado,&sueldo);

                if (i == codigo)
                {
                printf("\nID: %d",id);
                printf("\nNombre: %s",nombre);
                printf("\nSueldo: %d",sueldo);
                printf("\nHoras trabajadas: %d",horas);
                printf("\n");
                break;
                }

        }
    }
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int reto = -1;

    if(pArrayListEmployee !=NULL)
    {
        printf("Ordenamiento alfabeticamente, esto puede demorar unos segundos\n");
        if(!ll_sort(pArrayListEmployee,ordenamientoPorNombre,1))
        {
            controller_ListEmployee(pArrayListEmployee);
            reto = 0;
        }
    }

    return reto;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int reto = -1;
    FILE* pArchivo = fopen(path,"w");

    if(pArchivo !=NULL && !guardarFormatoTexto(pArchivo,pArrayListEmployee))
    {
        printf("Los datos en formato texto se guardaron correctamente.\n\n");
        reto = 0;
    }
    fclose(pArchivo);
    system("pause");
    return reto;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int reto = -1;
    FILE* pArchivo = fopen(path,"wb");

    if(pArchivo !=NULL && !guardarFormatoBinario(pArchivo,pArrayListEmployee))
    {
        printf("Los datos en formato binario se guardaron correctamente.\n\n");
        reto = 0;
    }
    fclose(pArchivo);
    system("pause");
    return reto;
}

int aniadirEmpleadoTexto(LinkedList* pArrayListEmployee)
{
    int horas;
    int sueldo;
    int reto = -1;
    char nombre[51];

    if(!dameNombre(nombre,51,"Ingrese el nombre: ","Reingrese el nombre: ",5)&&!getInt(&horas,"\nIngrese las horas: ","Reingrese las horas: ",0,1000,5)&&!getInt(&sueldo,"\nIngrese el sueldo: ","Reingrese el sueldo: ",0,100000,5))
    {
        Employee* empleado = generadorDeID(nombre,horas,sueldo);

        if(empleado !=NULL)
        {
            reto = ll_add(pArrayListEmployee,empleado);
        }
    }

    return reto;
}

int aniadirEmpleadoBinario(LinkedList* pArrayListEmployee)
{
    int ID;
    int reto = -1;
    char Horas[5];
    char Nombre[50];
    char Sueldo[10];
    char ID_String[5];
    Employee* pEmpleado;

    if(pArrayListEmployee !=NULL && !dameTexto(Nombre,51,"Ingrese nombre: ","Reingrese el nombre\n",0) && !dameTexto(Horas,20,"Ingrese las horas: ", "Reingrese las horas:",0) && !dameTexto(Sueldo,20,"Ingrese sueldo: ","Reingrese el sueldo:",0))
    {
        ID = dameLaProximaID();
        snprintf(ID_String, 20*sizeof(char), "%d", ID);
        pEmpleado = employee_newParametros(ID_String,Nombre,Horas,Sueldo);
        if(pEmpleado !=NULL)
        {
            ll_add(pArrayListEmployee, pEmpleado);
            reto = 0;
        }
    }
    return reto;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int id;
    int idAux;
    int sueldo;
    int seguir=0;
    char pregunta;
    int reto = -1;
    char nombre[51];
    Employee* empleado;
    int horasTrabajadas;
    int opcionAModificar=0;


    if(pArrayListEmployee !=NULL)
    {

        if(!getInt(&id,"Ingrese el ID del empleado a modificar: ","\nError ID inexistente: ",0,10000,5))
        {
            buscarEmpleadoEspecifico(pArrayListEmployee,id-1);

            for(i = 0; i< ll_len(pArrayListEmployee); i++)
            {
                empleado = ll_get(pArrayListEmployee,i);
                employee_getId(empleado,&idAux);
                if(idAux == id)
                {
                    do
                    {
                        seguir=0;
                        printf("\nElija que campo desea modificar:\n 1- Nombre \n 2- Horas de trabajo \n 3- Sueldo \n 4- Nada");
                        printf("\nOpcion: ");
                        scanf("%d", &opcionAModificar);
                        printf("\n");
                        switch(opcionAModificar)
                        {
                        case 1:
                            if(!dameNombre(nombre,51,"\nIngrese el nombre: ","\nNombre invalido pruebe nuevamente: ",2))
                            {
                                if(!employee_setNombre(empleado, nombre))
                                {
                                    printf("Dato modificado con exito\n");
                                    reto = 0;
                                    printf("\nQuire seguir modificando este empleado ? 's' = SI / otro caractero = NO\nOpcion: ");
                                    scanf("%c",&pregunta);
                                    if(pregunta=='s')
                                    {
                                        system("cls");
                                        seguir=1;
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                break;
                            }
                        case 2:
                            if(!getInt(&horasTrabajadas,"Ingrese las horas trabajadas: ","Horas invalidas pruebe nuevamente: ",0,1000,2))
                            {
                                if(!employee_setHorasTrabajadas(empleado, horasTrabajadas))
                                {
                                    printf("Dato modificado con exito\n");
                                    reto=0;
                                    printf("\nQuire seguir modificando este empleado ? 's' = SI / otro caractero = NO\nOpcion: ");
                                    scanf("%c",&pregunta);
                                    if(pregunta=='s')
                                    {
                                        seguir=1;
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                    break;
                                }
                            }
                            else
                            {
                                break;
                            }
                        case 3:
                            if(!getInt(&sueldo,"Ingrese el sueldo: ","Sueldo invalido pruebe nuevamente: ",0,1000000,2))
                            {
                                if(!employee_setSueldo(empleado, sueldo))
                                {
                                    printf("Dato modificado con exito\n");
                                    reto=0;
                                    printf("\nQuire seguir modificando este empleado ? 's' = SI / otro caractero = NO\nOpcion: ");
                                    scanf("%c",&pregunta);
                                    if(pregunta=='s')
                                    {
                                        seguir=1;
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                    break;
                                }
                            }
                            else
                            {
                                break;
                            }
                         case 4:
                            seguir = 0;
                            break;
                        default:
                            printf("Opcion no existente\n");
                            system("pause");
                        }
                    }
                    while(seguir==1);
                }
            }
        }
    }
    return reto;
}
