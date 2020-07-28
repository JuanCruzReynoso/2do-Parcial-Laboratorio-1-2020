#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myGets.h"


///---------- GETS SIMPLES ----------

int getInt(char mensaje[])
{
    int auxInt;

    printf("%s", mensaje);
    scanf("%d", &auxInt);

    return auxInt;
}

float getFloat(char mensaje[])
{
    float auxFloat;

    printf("%s", mensaje);
    scanf("%f", &auxFloat);

    return auxFloat;
}

char getChar(char mensaje[])
{
    char auxChar;

    printf("%s", mensaje);
    scanf("%c", &auxChar);

    return auxChar;
}

void getString(char mensaje[], char auxString[])
{
    printf(mensaje);
    fflush(stdin);
    gets(auxString);
}


///---------- VALIDACIONES ----------


void stringToUpper(char str[])
{
    int i;
    int len;

    str[0]=toupper(str[0]);
    len=strlen(str);

    for(i=0; i<len; i++)
    {
        if(str[i]==' ')
        {
            i=i+1;
            str[i]=toupper(str[i]);
        }
    }
}

int isOnlyNumbers(char str[])
{
    int i;
    int retorno;

    for(i=0; str[i] != '\0'; i++)
    {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.'))
            retorno=1;
        else
        {
            retorno=0;
            break;
        }
    }

    return retorno;
}

int isOnlyLetters(char str[])
{
    int i;
    int retorno;

    for(i=0; str[i] != '\0'; i++)
    {
        if((str[i] == ' ')||(str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z'))
            retorno=1;
        else
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int isAlphaNumeric(char str[])
{
    int i;
    int retorno;

    for(i=0; str[i] != '\0'; i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
            retorno=1;
        else
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

///---------- GETS VALIDADOS ----------

void getStringOnlyLetters(char mensaje[], char str[])
{
    char auxString[100];
    int flag = 0;

    do
    {
        getString(mensaje, auxString);
        flag=isOnlyLetters(auxString);
        if(flag==1)
        {
            strcpy(str, auxString);
        }
    }
    while(flag==0);

}

void getStringOnlyNumbers(char mensaje[], char str[])
{
    char auxString[100];
    int flag = 0;

    do
    {
        getString(mensaje, auxString);
        flag = isOnlyNumbers(auxString);
        if(flag==1)
        {
            strcpy(str, auxString);
        }
    }
    while(flag==0);

}

void getStringAlphaNumeric(char mensaje[], char str[])
{
    char auxString[100];
    int flag = 0;

    do
    {
        getString(mensaje, auxString);
        flag = isAlphaNumeric(auxString);
        if(flag==1)
        {
            strcpy(str, auxString);
        }
    }
    while(flag==0);

}
