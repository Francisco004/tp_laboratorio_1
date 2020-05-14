#include "ArrayEmployees.h"

int main()
{
    char continuee[10];
    int optionFour;
    int Flag = 1;

    sEmployee List[TAM];

    initEmployees(List, TAM);

    do
    {
        system("cls");
        switch (menu())
        {
        case 1:
            ////////////////////////////////////////////////////ALTA EMPLEADO
            system("cls");
            addEmployees(List, TAM);
            Flag++;
            break;

        case 2:
            ////////////////////////////////////////////////////MODIFICAR EMPLEADO
            if(Flag > 0)
            {
                system("cls");
                modifyEmployee(List, TAM);
                system("pasue");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta un empleado...\n");
                system("pause");
            }

            break;

        case 3:
            ////////////////////////////////////////////////////BORRAR EMPLEADO
            if(Flag > 0)
            {
                system("cls");
                removeEmployee(List, TAM);
                system("pasue");
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta un empleado...\n");
                system("pause");
            }

            break;

        case 4:
            ////////////////////////////////////////////////////LISTAR EMPLEADO
            if(Flag > 0)
            {
                system("cls");
                printf("1- Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n2- Total y promedio de los salarios, y cuantos empleados superan el salario promedio. \nElija una opcion: ");
                scanf(" %d",&optionFour);

                switch(optionFour)
                {
                case 1:
                    system("cls");
                    sortEmployees(List, TAM);
                    printf("   ID             APELLIDO               NOMBRE         SALARIO     SECTOR    \n");
                    printEmployees(List, TAM);
                    printf("\n");
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    printAverageSalaries(List, TAM);
                    system("pause");
                    break;
                default:
                    system("cls");
                    printf("Esta opcion no existe...\n");
                    system("pause");
                    break;
                }
            }
            else
            {
                system("cls");
                printf("Primero se debe dar de alta un empleado...\n");
                system("pause");
            }

            break;

        case 5:
                ////////////////////////////////////////////////////SALIR
                system("cls");
                printf("Seguro que desea salir? 'S' = si: ");
                fflush(stdin);
                scanf(" %s",continuee);

                strupr(continuee);

                if (strcmp(continuee,"S") == 0)
                {
                    printf("Cerrando consola...\n");
                }

            break;

        default:
            system("cls");
            printf("Esta opcion no existe...\n");
            system("pause");
            break;
        }

    }
    while (strcmp(continuee,"S") != 0);

    return 0;
}
