#include "ArrayEmployees.h"

int main()
{
    char seguir[10];
    int opcionCuatro;
    int banderaAlta = 1;

    eEmpleado unEmpleado[TAM];

    inicializarEmpleados(unEmpleado, TAM);
    hardcodearEmpelados(unEmpleado);

    do
    {
        system("cls");
        switch (menu())
        {
        case 1:
            ////////////////////////////////////////////////////ALTA EMPLEADO
            system("cls");
            altaDeUnEmpleado(unEmpleado, TAM);
            banderaAlta++;
            break;

        case 2:
            ////////////////////////////////////////////////////MODIFICAR EMPLEADO
            if(banderaAlta > 0)
            {
                system("cls");
                modificarUnEmpleado(unEmpleado, TAM);
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
            if(banderaAlta > 0)
            {
                system("cls");
                darDeBajaUnEmpleado(unEmpleado, TAM);
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
            if(banderaAlta > 0)
            {
                system("cls");
                printf("1- Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n2- Total y promedio de los salarios, y cuantos empleados superan el salario promedio. \nElija una opcion: ");
                scanf(" %d",&opcionCuatro);

                switch(opcionCuatro)
                {
                case 1:
                    system("cls");
                    ordenarEmpleados(unEmpleado, TAM);
                    printf("   ID             APELLIDO               NOMBRE         SALARIO     SECTOR    \n");
                    mostrarUnEmpleados(unEmpleado, TAM);
                    printf("\n");
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    informarPromedioSalarios(unEmpleado, TAM);
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
                scanf(" %s",seguir);

                strupr(seguir);

                if (strcmp(seguir,"S") == 0)
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
    while (strcmp(seguir,"S") != 0);

    return 0;
}
