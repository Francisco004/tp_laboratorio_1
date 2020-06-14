#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "string.h"

int main()
{
    int opcion=0;
    int vanderaUno=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");
        printf("                           Trabajo practico Numero 3                     \n");
        printf("                              Francisco Rocha 1-B                          ");
        printf("\nMenu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados alfabeticamente\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n10. Salir");

        printf("\n\nIngrese una opcion del menu: ");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            vanderaUno = 1;
            break;
        case 2:
            controller_loadFromBinary("data.bin", listaEmpleados);
            vanderaUno = 1;
            break;
        case 3:
            system("cls");
            if(vanderaUno==1)
            {
                aniadirEmpleadoTexto(listaEmpleados);
            }else
            {
                printf("Primero debe cargar los datos de texto o binario\n\n");
                system("pause");
            }
            break;
        case 4:
            system("cls");
            if(vanderaUno!=0)
            {
                controller_editEmployee(listaEmpleados);
            }else
            {
                printf("Primero debe cargar los datos de texto o binario\n\n");
                system("pause");
            }
            break;
        case 5:
            system("cls");
            if(vanderaUno!=0)
            {
                controller_removeEmployee(listaEmpleados);
            }else
            {
                printf("Primero debe cargar los datos de texto o binario\n\n");
                system("pause");
            }
            break;
        case 6:
            system("cls");
            if(vanderaUno!=0)
            {
                controller_ListEmployee(listaEmpleados);
            }else
            {
                printf("Primero debe cargar los datos de texto o binario\n\n");
                system("pause");
            }
            break;
        case 7:
            system("cls");
            if(vanderaUno!=0)
            {
                controller_sortEmployee(listaEmpleados);
            }else
            {
                printf("Primero debe cargar los datos de texto o binario\n\n");
                system("pause");
            }
            break;
        case 8:
            system("cls");
            if(vanderaUno!=0)
            {
                controller_saveAsText("data.csv",listaEmpleados);
                {
                    system("pause");
                }
            }else{printf("Primero debe cargar los datos de texto o binario\n\n");}
                break;
            case 9:
                system("cls");
                if(vanderaUno!=0)
                {
                    controller_saveAsBinary("data.dat",listaEmpleados);
                    {
                        system("pause");
                    }
                }else{printf("Primero debe cargar los datos de texto o binario\n\n");}
                    break;
                case 10:
                    printf("Cerrando consola...\n\n");
                    //system("Pause");
                    break;
                default:
                    printf("Ingrese una opcion valida \n");
                    system("pause");
                }
            }
    while(opcion != 10);
    return 0;
}
