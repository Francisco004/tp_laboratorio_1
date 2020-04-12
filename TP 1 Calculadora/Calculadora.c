#include "Calculadora.h"

void menu_Calculadora()
{
    int opcion;
    float primero;
    float segundo;
    int banderaUno;
    int banderaDos;
    int banderaTres;
    int convertirAEntero;

    float suma;
    float resta;
    float division;
    float multiplicacion;
    unsigned long long factorialUno;
    unsigned long long factorialDos;

    primero = 0;
    segundo = 0;

    do
    {
        system("cls");
        printf("***********************************************\n");
        printf("******  Calculadora Francisco Rocha 1-A  ******\n");
        printf("***********************************************\n");
        printf("* 1-Ingresar 1er operando (A = %.2f)          \n",primero);
        printf("*                                             \n");
        printf("* 2-Ingresar 2do operando (B = %.2f)          \n",segundo);
        printf("*                                             \n");
        printf("* 3-Calcular todas las operaciones            \n");
        printf("*   *Calcula la suma (%.2f + %.2f)            \n",primero,segundo);
        printf("*   *Calcula la resta (%.2f + %.2f)           \n",primero,segundo);
        printf("*   *Calcula la division (%.2f + %.2f)        \n",primero,segundo);
        printf("*   *Calcula la multiplicacion (%.2f + %.2f)  \n",primero,segundo);
        printf("*   *Calcula el factorial de !%.0f y !%.0f    \n",primero,segundo);
        printf("*                                             \n");
        printf("* 4-Informar resultados                       \n");
        printf("*                                             \n");
        printf("* 5-Salir                                     \n");
        printf("***********************************************\n");
        printf("***********************************************\n");
        printf("***********************************************\n\n");

        printf("Que opcion desea seleccionar: ");
        scanf(" %d",&opcion);

        switch (opcion)
        {
            //////////////////////////////////////////////////////////////////////Ingreso del primer numero.
            case 1:
            system("cls");
            banderaUno = 1;
            banderaTres = 0;
            primero = primer_Numero();
            break;

            //////////////////////////////////////////////////////////////////////Ingreso del segundo numero.
            case 2:
            system("cls");
            banderaDos = 1;
            banderaTres = 0;
            segundo = segundo_Numero();
            break;

            //////////////////////////////////////////////////////////////////////Calculo las operaciones.
            case 3:
            system("cls");
            if(banderaUno == 1 && banderaDos == 1)
            {
                banderaTres = 1;
                system("cls");
                printf("Calculando todas las operaciones.....\n");

                suma = operacion_Suma(primero,segundo);
                resta = operacion_Resta(primero,segundo);
                multiplicacion = operacion_Multiplicacion(primero,segundo);
                division = operacion_Division(primero,segundo);
                convertirAEntero = (int)primero;
                factorialUno = operacion_Factorial(convertirAEntero);
                convertirAEntero = (int)segundo;
                factorialDos = operacion_Factorial(convertirAEntero);
                system("pause");

            }
            else
                {
                    printf("Primero debe ingresar los dos operadores....\n\n");
                    system("pause");
                }
            break;

            //////////////////////////////////////////////////////////////////////Muestro los resultados.
            case 4:
            system("cls");
            if(banderaUno == 1 && banderaDos == 1)
            {
                if(banderaTres == 1)
                {
                    mostrarResultados(primero,segundo,suma,resta,division,multiplicacion);

                    if(primero < 0)
                    {
                    printf("* Error, no se puede hacer factorial negativo...\n");
                    }else if (primero > 20)
                    {
                        printf("* Error, no se puede hacer factorial de este numero tan grande, lo maximo es 20...\n");
                    }else
                    {
                        printf("* El resultado de el factorial de %.0f es: %llu \n",primero,factorialUno);
                    }
                    printf("*                                             \n");


                    if(segundo < 0)
                    {
                    printf("* Error, no se puede hacer factorial negativo...\n");
                    }else if (segundo > 20)
                    {
                        printf("* Error, no se puede hacer factorial de este numero tan grande, lo maximo es 20...\n");
                    }else
                    {
                        printf("* El resultado de el factorial de %.0f es: %llu \n",segundo,factorialDos);
                    }
                    printf("*****************************************************\n");
                    printf("*****************************************************\n");
                    printf("*****************************************************\n\n");
                    system("pause");
                }else
                    {
                        printf("Primero debe calcular los resultados usando la opcion 3...\n");
                        system("pause");
                    }
            }
            else
                {
                    printf("Primero debe ingresar los dos operadores....\n\n");
                    system("pause");
                }
            break;

            //////////////////////////////////////////////////////////////////////Cierro la consola.
            case 5:
            system("cls");
            printf("Cerrando consola...\n");
            break;

            //////////////////////////////////////////////////////////////////////Ingreso opcion erronea.
            default:
            system("cls");
            printf("Esta opcion no existe\n\n");
            system("pause");
            break;
        }

    }while (opcion != 5);
}

float primer_Numero()
{
    char cadenaNumero[20];
    int valido = 1;

    do
    {
        system("cls");
        printf("Ingrese un numero: ");
        scanf(" %s",cadenaNumero);
        valido = validar_Numeros(cadenaNumero);
    }while(valido == 1);

    return valido;
}

float segundo_Numero()
{
    char cadenaNumero[20];
    int valido = 1;

    do
    {
        system("cls");
        printf("Ingrese un numero: ");
        scanf(" %s",cadenaNumero);
        valido = validar_Numeros(cadenaNumero);
    }while(valido == 1);

    return valido;
}

int validar_Numeros(char numero[])
{
    int i;
    int numeroFinal;

    for(i = 0; i < strlen(numero); i++)
    {
        if(! (numero[i] >= 45 && numero[i] <= 57))
        {
            system("cls");
            printf("SOLO INGRESE NUMEROS...\n\n\n");
            system("pause");
            return 1;
        }
    }

    numeroFinal = atof(numero);

    return numeroFinal;
}

float operacion_Suma(float primero,float segundo)
{
    float resultado;
    resultado = primero + segundo;
    return resultado;
}

float operacion_Resta(float primero,float segundo)
{
    float resultado;
    resultado = primero - segundo;
    return resultado;
}

float operacion_Multiplicacion(float primero,float segundo)
{
    float resultado;
    resultado = primero * segundo;
    return resultado;
}

float operacion_Division(float primero,float segundo)
{
    float resultado;
    resultado = primero / segundo;
    return resultado;
}

long long int operacion_Factorial(int numero)
{
    unsigned long long fact = 1;

    if (numero < 0)
    {
        return 0;
    }
    else
    {
        for (int i = 1; i <= numero; ++i)
        {
            fact *= i;
        }
    }

    return fact;
}

void mostrarResultados(float numA, float numB, float sum, float res, float div, float mult)
{
    system("cls");
                    printf("*****************************************************\n");
                    printf("*********  Calculadora Francisco Rocha 1-A  *********\n");
                    printf("*****************************************************\n");
                    printf("* El resultado de %.2f + %.2f es: %.2f             \n",numA,numB,sum);
                    printf("*                                             \n");
                    printf("* El resultado de %.2f - %.2f es: %.2f              \n",numA,numB,res);
                    printf("*                                             \n");
                    printf("* El resultado de %.2f * %.2f es: %.2f              \n",numA,numB,mult);
                    printf("*                                             \n");
                    if(numB == 0)
                    {
                    printf("* Error, no se puede dividir por 0...\n");
                    }else
                    {
                        printf("* El resultado de %.2f / %.2f es: %.2f            \n",numA,numB,div);
                    }
                    printf("*                                             \n");
}
