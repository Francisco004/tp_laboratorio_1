#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "Validacion.h"

int dameNombre(char* pNombre, int limite, char* mensaje, char* error, int reintentos)
{
    int reto=-1;
    char buffNombre[4096];

    if(pNombre != NULL && limite > 0 && mensaje != NULL && error != NULL && reintentos >= 0)
    {
        printf("%s",mensaje);
        do
        {
            reintentos--;
            if(getString(buffNombre,limite) == 0 && validarNombre(buffNombre,limite))
            {
                strncpy(pNombre,buffNombre,limite);
                reto = 0;
                break;
            }
            else
            {
                printf("%s",error);
            }
        }
        while(reintentos >= 0);
    }
    return reto;
}

int dameTexto(char *pTexto, int limite, char *mensaje,char *error, int reintentos)
{
    int reto=-1;
    char buffer[4096];
    if(pTexto != NULL && limite > 0 && mensaje != NULL && error != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if(getString(buffer, limite) == 0 && validacionDeTexto(buffer, limite))
            {
                strncpy(pTexto, buffer, limite);
                reto = 0;
                break;
            }
            else
            {
                printf("\n%s", error);
            }
        }
        while(reintentos>=0);
    }
    return reto;
}

int validacionDeTexto(char *pBuffer, int limite)
{
    int i;
    int reto = 0;

    if(pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        reto = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(!((pBuffer[i] >= ' ' && pBuffer[i] <= '"') || pBuffer[i] == '(' || pBuffer[i] == ')' || (pBuffer[i] >= ',' && pBuffer[i] <= '.') || (pBuffer[i] >= '0' && pBuffer[i] <= ';') || (pBuffer[i] >= '?' && pBuffer[i] <= 'Z') || (pBuffer[i] >= 'a' && pBuffer[i] <= 'z')))
            {
                reto = 0;
                break;
            }
        }
    }
    return reto;
}

int getString(char* pBuffer, int limite)
{
    int tamanio;
    int reto = -1;
    char buffer[4096];

    if(pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(buffer,limite,stdin);
        fflush(stdin);
        tamanio = strlen(buffer);
        if(tamanio != limite-1 ||  buffer[limite-2] == '\n')
        {
            buffer[tamanio-1] = '\0';
        }
        reto = 0;
        strncpy(pBuffer,buffer,limite);
    }
    return reto;
}

int getInt(int* pResultado, char mensaje[], char error[], int  min, int  max, int  reintentos)
{
    int i;
    int j;
    int numero;
    int menos = 0;
    int validado = 1;
    char string[1000];

    printf("%s",mensaje);

    for(i = 0; i<reintentos; i++)
    {
        validado = 1;
        fflush(stdin);
        fgets(string, 1000, stdin);

        for (j=0; j<strlen(string)-1; j++)
        {
            if (string[j] < '0' || string[j] > '9')
            {
                if(j > 0 || string[j] != 45)
                {
                    validado = 0;
                    printf("%s",error);
                    break;
                }
                menos = 1;
            }
        }
        if(menos == 1 && strlen(string)-1 == 1)
        {
            validado = 0;
        }
        if (validado)
        {
            numero = atoi(string);
            if(numero >= min && numero <= max)
            {
                *pResultado = numero;
                return 0;
            }
            if(numero < min || numero > max)
            {
                printf("%s",error);
            }
        }
    }

    return -1;
}

int validarNombre(char* pBuffer,int limite)
{
    int i;
    int reto = 0;

    if(pBuffer != NULL && limite > 0)
    {
        reto = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if((tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z') && pBuffer[i]!= ' ')
            {
                reto = 0;
                break;
            }
        }
    }
    return reto;
}

int esEntero(char* pBuffer)
{
    int i = 0;
    int reto = 0;

    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            reto=-1;
            break;
        }
        i++;
    }
    return reto;
}
