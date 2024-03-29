#include "ArrayEmployees.h"

/////////////////////////////////////////////////////////////////////////Mostrar Empleado
void printOneEmployee(sEmployee List)
{
    printf( "%5d %20s %20s %15.2f %10d\n",List.id,List.lastName,List.name,List.salary,List.sector );
}






/////////////////////////////////////////////////////////////////////////Mostrar Empleados
void printEmployees(sEmployee List[], int len)
{
    int vandera = VACIO;

    for (int i = 0; i < len; i++)
    {
        if(List[i].isEmpty == LLENO)
        {
            printOneEmployee(List[i]);
            vandera = LLENO;
        }
    }

    if(vandera == VACIO)
    {
        printf("No hay empleados que listar...\n\n");
    }
}






/////////////////////////////////////////////////////////////////////////Ordenar Empleado
void sortEmployees(sEmployee List[], int len)
{
    sEmployee auxempleado;

    for (int i = 0; i < len - 1; i++)
    {
        if(List[i].isEmpty == LLENO)
        {
            for(int j = i+1; j < len; j++)
            {
                if(List[j].isEmpty == LLENO)
                {
                    if (strcmp(List[i].lastName, List[j].lastName) == 0)
                    {
                        if(List[i].sector > List[j].sector)
                        {
                            auxempleado = List[i];
                            List[i] = List[j];
                            List[j] = auxempleado;
                        }
                    }
                    else if (strcmp(List[i].lastName, List[j].lastName) > 0)
                    {
                        auxempleado = List[i];
                        List[i] = List[j];
                        List[j] = auxempleado;
                    }
                }
            }
        }
    }
}






/////////////////////////////////////////////////////////////////////////Inicializar Empleados
int initEmployees(sEmployee* List, int len)
{
    int retorno = -1;
    int i;
    if(len > 0 && List != NULL)
    {
        for(i = 0; i < len; i++)
        {
            List[i].isEmpty = VACIO;
            retorno = 0;
        }
    }

    return retorno;
}






/////////////////////////////////////////////////////////////////////////Mostrar Menu
int menu()
{
    int opcion;

    printf("****************************************************************************\n");
    printf("**********      TP EMPRESA FRANCISCO ROCHA      CURSO: 1-A      ************\n");
    printf("****************************************************************************\n");
    printf("*********** 1- ALTA de empleado                                 ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 2- MODIFICAR nombre / apellido / salario / sector   ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 3- BAJA ingresando ID                               ************\n");
    printf("***********                                                     ************\n");
    printf("*********** 4- INFORMAR                                         ************\n");
    printf("***********                                                     ************\n");
    printf("***********                     5- Salir                        ************\n");
    printf("****************************************************************************\n");
    printf("****************************************************************************\n");

    printf("Ingrese una opcion: ");
    scanf(" %d",&opcion);

    return opcion;
}






/////////////////////////////////////////////////////////////////////////Alta Empleado
void addEmployees(sEmployee List[],int len)
{
    int lugar;
    int entero;
    int validacion;
    char texto[51];

    lugar = findEmployeeById(List, len);

    if(lugar != -1)
    {
        List[lugar].id = lugar + 1;

        ////////////////////////////////////////////////////Alta nombre
        do
        {
            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(texto);
            validacion = validarString(texto);
        }
        while(validacion == 1);

        strcpy(List[lugar].name, texto);

        ////////////////////////////////////////////////////Alta apellido
        do
        {
            printf("Ingrese el apellido: ");
            fflush(stdin);
            gets(texto);
            validacion = validarString(texto);
        }
        while(validacion == 1);

        strcpy(List[lugar].lastName, texto);

        ////////////////////////////////////////////////////Alta salario
        do
        {
            printf("Ingrese el salario: ");
            entero = scanf(" %f", &List[lugar].salary);
            fflush(stdin);
        }
        while(entero==0);

        ////////////////////////////////////////////////////Alta sector
        do
        {
            printf("Ingrese el sector: ");
            entero = scanf(" %d", &List[lugar].sector);
            fflush(stdin);
        }
        while(entero==0);

        List[lugar].isEmpty = LLENO;

    }
    else
    {
        printf("No queda mas espacio...\n");
        system("pause");
    }
}






/////////////////////////////////////////////////////////////////////////Validar String
int validarString(char texto[])
{
    int retorno = 0;

    for (int i = 0; i < strlen(texto); i++)
    {
        if (!((texto[i]>=65 && texto[i]<=90) || (texto[i]>=97 && texto[i]<=122)))
        {
            printf("Solo ingrese letras....\n\n");
            retorno = 1;
            system("pause");
            break;
        }
    }


    return retorno;
}






/////////////////////////////////////////////////////////////////////////Buscar Espacio Libre
int findEmployeeById(sEmployee List[], int len)
{
    int indice = -1;

    for (int i = 0; i < len; i++)
    {
        if (List[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}






/////////////////////////////////////////////////////////////////////////Baja Empleado
void removeEmployee(sEmployee List[], int len)
{
    int id;
    char confirmar;

    printf("Ingrese la id del empleado a dar de baja: ");
    scanf(" %d",&id);

    for(int i = 0; i < len; i++)
    {
        if (List[i].isEmpty == LLENO && List[i].id == id)
        {
            printf("\nEl empleado que selecciono es: \n");
            printf("   ID              APELLIDO             NOMBRE         SALARIO     SECTOR    \n");
            printOneEmployee(List[i]);

            printf("\n\nDesea dar de baja a ese empleado? S = SI: ");
            scanf(" %c",&confirmar);

            confirmar = toupper(confirmar);

            if(confirmar == 'S')
            {
                List[i].isEmpty = VACIO;
                system("cls");
                printf("Se dio de baja...\n");
                system("pause");
            }
            else
            {
                printf("No se dio de baja...\n");
                system("pause");
            }
            break;
        }
        else if (i == 999)
        {
            printf("No hay un empleado con esta id...\n");
            system("pause");
        }
    }
}






/////////////////////////////////////////////////////////////////////////Informar Promedios
void printAverageSalaries(sEmployee List[], int len)
{
    int i;
    int j;
    float suma = 0;
    int bandera = 0;
    int contador = 0;
    float promedio = 0;


    for(i = 0; i < len; i++)
    {
        if(List[i].isEmpty == LLENO)
        {
            suma = suma + List[i].salary;
            contador++;
        }
    }




    promedio=suma/contador;




    if(contador == 1)
    {
        printf("La SUMA de el salario es de: %.2f\n\n",suma);
    }
    else
    {
        printf("La SUMA de los salarios es de: %.2f\n\n",suma);
    }

    printf("El PROMEDIO de los %d salarios es de: %.2f\n\n",contador,promedio);


    for(j = 0; j < len; j++)
    {
        if(List[j].salary > promedio && List[j].isEmpty == LLENO)
        {
            if(contador == 1)
            {
                printf("\nEl salario que supera el PROMEDIO es: \n\n");
            }
            else
            {
                printf("\nLos salarios que superan el PROMEDIO son: \n\n");
            }
            printf("   ID              APELLIDO             NOMBRE         SALARIO     SECTOR    \n");
            bandera = 1;
            break;
        }
    }

    if(bandera == 0)
    {
        printf("No hay salarios que superen el promedio...\n");
    }

    for(j = 0; j < len; j++)
    {
        if(List[j].salary > promedio && List[j].isEmpty == LLENO)
        {
            printOneEmployee(List[j]);
        }
    }




    printf("\n");
}






/////////////////////////////////////////////////////////////////////////Modificar Empleado
void modifyEmployee(sEmployee List[], int len)
{
    int i;
    int entero;
    char seguir;
    int modificar;
    int validacion;
    int encontro = 0;
    char verificar = 'N';


    int id;
    int sector;
    float salario;
    char nombre[51];
    char apellido[51];


    printf("Ingrese la id del empleado a modificar: ");
    scanf(" %d",&id);

    for(i = 0; i < len; i++)
    {
        if(id == List[i].id && List[i].isEmpty == LLENO)
        {
            encontro = 1;
            printf("\nEL EMPLEADO INGRESADO ES:\n");
            printf("   ID              APELLIDO             NOMBRE         SALARIO     SECTOR    \n");
            printOneEmployee(List[i]);

            printf("\n\nQuiere modificar este empleado? 'S' = SI: ");
            scanf(" %c",&verificar);

            verificar = toupper(verificar);

            if(verificar == 'S')
            {
                do
                {
                    system("cls");
                    printf("1) Nombre\n2) Apellido\n3) Salario\n4) Sector\nQue desea modificar ?: ");
                    scanf(" %d",&modificar);

                    switch(modificar)
                    {
                    case 1:
                        do
                        {
                            system("cls");
                            printf("Ingrese el nuevo nombre: ");
                            fflush(stdin);
                            gets(nombre);
                            validacion = validarString(nombre);
                        }
                        while(validacion == 1);

                        if (strlen(nombre) > 51)
                        {
                            printf("El nombre es demasiado largo, no se puede modificar...\n");
                            system("pause");
                        }
                        else
                        {
                            strcpy(List[i].name,nombre);

                            printf("Se modifico el nombre...\n");
                            system("pause");
                        }
                        break;

                    case 2:
                        do
                        {
                            system("cls");
                            printf("Ingrese el nuevo apellido: ");
                            fflush(stdin);
                            gets(apellido);
                            validacion = validarString(apellido);
                        }
                        while(validacion == 1);

                        if (strlen(apellido) > 51)
                        {
                            printf("El apellido es demasiado largo, no se puede modificar...\n");
                            system("pause");
                        }
                        else
                        {
                            strcpy(List[i].lastName,apellido);

                            printf("Se modifico el apellido...\n");
                            system("pause");
                        }
                        break;

                    case 3:
                        do
                        {
                            system("cls");
                            printf("Ingrese el nuevo salario: ");
                            entero = scanf("%f", &salario);
                            fflush(stdin);
                        }
                        while(entero == 0);

                        List[i].salary = salario;

                        printf("Se modifico el salario...\n");
                        system("pause");
                        break;

                    case 4:
                        do
                        {
                            system("cls");
                            printf("Ingrese el nuevo sector: ");
                            entero = scanf(" %d",&sector);
                            fflush(stdin);
                        }
                        while(entero == 0);

                        List[i].sector = sector;

                        printf("Se modifico el sector...\n");
                        system("pause");
                        break;
                    default:
                        system("cls");
                        printf("Esta opcion no existe...\n");
                        system("pause");
                        break;
                    }

                    system("cls");
                    printf("Desea seguir modificando al empleado? 'S' = SI: ");
                    scanf(" %c",&seguir);

                    seguir = toupper(seguir);

                }
                while(seguir == 'S');
            }
        }
    }

    if(encontro == 0)
    {
        system("cls");
        printf("No se encontro un empleado con esta id...\n");
        system("pause");
    }
}
