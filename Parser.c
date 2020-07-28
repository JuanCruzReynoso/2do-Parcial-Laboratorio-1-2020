#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Vuelos.h"
#include "Pilotos.h"
#include "parser.h"

int parser_VueloFromText(FILE* pArchivo,LinkedList* pListadoVuelos)
{
    Vuelo* pVuelo;

    char auxIdVuelo[100];
    char auxIdAvion[100];
    char auxIdPiloto[100];
    char auxFecha[100];
    char auxDestino[100];
    char auxCantPasajeros[100];
    char auxHoraDespegue[100];
    char auxHoraLlegada[100];

    int retorno = 0;
    int flag = 0;

    if (pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            if (flag == 0)
            {
                fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxIdVuelo, auxIdAvion, auxIdPiloto, auxFecha, auxDestino, auxCantPasajeros, auxHoraDespegue, auxHoraLlegada);
                flag = 1;
            }

            fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxIdVuelo, auxIdAvion, auxIdPiloto, auxFecha, auxDestino, auxCantPasajeros, auxHoraDespegue, auxHoraLlegada);
            printf("%s - %s - %s - %s - %s - %s - %s - %s\n",auxIdVuelo,auxIdAvion,auxIdPiloto,auxFecha,auxDestino,auxCantPasajeros,auxHoraDespegue,auxHoraLlegada);

            pVuelo = vuelo_newParametros(auxIdVuelo,auxIdAvion,auxIdPiloto,auxFecha,auxDestino,auxCantPasajeros,auxHoraDespegue,auxHoraLlegada);

            if(pVuelo!=NULL)
            {
                ll_add(pListadoVuelos,pVuelo);
                retorno = 1;
            }
        }
    }

    return retorno;
}

int parser_PilotoFromText(FILE* pArchivo,LinkedList* pListadoPilotos)
{
    Piloto* pPiloto;

    char auxId[100];
    char auxNombre[100];

    int retorno = 0;
    int flag = 0;

    if (pArchivo!=NULL)
    {

        while(!feof(pArchivo))
        {
            if(flag == 0)
            {
                fscanf(pArchivo,"%[^,],%[^\n]\n",auxId,auxNombre);
                flag = 1;
            }

            fscanf(pArchivo,"%[^,],%[^\n]\n",auxId,auxNombre);
            printf("%s - %s\n",auxId,auxNombre);

            pPiloto = piloto_newParametros(auxId,auxNombre);

            if(pPiloto!=NULL)
            {
                ll_add(pListadoPilotos,pPiloto);
                retorno = 1;
            }
        }
    }

    return retorno;
}
