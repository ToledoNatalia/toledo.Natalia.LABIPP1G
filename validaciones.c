
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int getInt(char message[],char errorMessage[])
{
    char strNumber[32];
    int number;

    puts(message);
    fflush(stdin);
    fgets(strNumber,sizeof(strNumber),stdin);
    strNumber[strlen(strNumber)-1]='\0';

    while(!validarEnteroPositivo(strNumber))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(strNumber,sizeof(strNumber),stdin);
        strNumber[strlen(strNumber)-1]='\0';
    }

    number=atoi(strNumber);

    return number;
}


int validarEnteroPositivo(char number[])
{
    int returnValue =1;

    for(int i=0; number[i]!='\0'; i++)
    {
        if(number[i]<'0'||number[i]>'9')
        {
            returnValue=0;
            break;
        }
    }

    return returnValue;
}


char getCharTwoOptions(char message[],char errorMessage[],char option1,char option2)
{
    char aux;

    puts(message);
    fflush(stdin);
    scanf("%c",&aux);
    aux=tolower(aux);

    while(aux!=option1&&aux!=option2)
    {
        puts(errorMessage);
        fflush(stdin);
        scanf("%c",&aux);
        aux=tolower(aux);
    }

    return aux;

}
char getChar(char message[],char errorMessage[])
{
    char aux;

    puts(message);
    fflush(stdin);
    scanf("%c",&aux);

    while((aux<'a'||aux>'z')&&(aux<'A'||aux>'Z'))
    {
        puts(errorMessage);
        fflush(stdin);
        scanf("%c",&aux);
    }

    return aux;
}
