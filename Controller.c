#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Vuelos.h"
#include "Pilotos.h"
#include "parser.h"
#include "myGets.h"

int controller_Reynoso_loadFromTextVuelos(char* path, LinkedList* pListadoVuelos)
{
    FILE* pArchivo;
    int retorno = 0;

    pArchivo=fopen(path,"r");

    if(pArchivo!=NULL)
    {
        parser_VueloFromText(pArchivo,pListadoVuelos);
        retorno = 1;
    }
    fclose(pArchivo);

    return retorno;
}

int controller_Reynoso_loadFromTextPilotos(char* path, LinkedList* pListadoPilotos)
{
    FILE* pArchivo;
    int retorno = 0;

    pArchivo = fopen(path,"r");

    if(pArchivo!=NULL)
    {
        parser_PilotoFromText(pArchivo,pListadoPilotos);
        retorno = 1;
    }
    fclose(pArchivo);

    return retorno;
}

int controller_Reynoso_listVuelos(LinkedList* pListadoVuelos, LinkedList* pListadoPilotos)
{
    Vuelo* pVuelo;
    Piloto* pPiloto;

    int auxIdVuelo;
    int auxIdAvion;
    int auxIdPiloto;
    char auxNombrePiloto[100];
    char auxFecha[100];
    char auxDestino[100];
    int auxCantPasajeros;
    int auxHoraDespegue;
    int auxHoraLlegada;

    int i;
    int size;
    int retorno = 0;

    if(pListadoVuelos != NULL && pListadoPilotos != NULL)
    {
        size = ll_len(pListadoVuelos);

        printf("\n idVuelo: idAvion:\t nombrePiloto:\t     fecha:\tdestino:\t cantPasajeros:\t horaDespegue:\t horaLlegada:");

        for(i=0; i<size; i++)
        {
            pVuelo = ll_get(pListadoVuelos, i);

            vuelo_getIdVuelo(pVuelo,&auxIdVuelo);
            vuelo_getIdAvion(pVuelo,&auxIdAvion);
            vuelo_getIdPiloto(pVuelo,&auxIdPiloto);

            pPiloto = piloto_getPilotoById(pListadoPilotos,auxIdPiloto);
            piloto_getNombre(pPiloto,auxNombrePiloto);

            vuelo_getFecha(pVuelo,auxFecha);
            vuelo_getDestino(pVuelo,auxDestino);
            vuelo_getCantPasajeros(pVuelo,&auxCantPasajeros);
            vuelo_getHoraDespegue(pVuelo,&auxHoraDespegue);
            vuelo_getHoraLlegada(pVuelo,&auxHoraLlegada);

            printf("\n%8d %8d %20s %12s %12s %21d %14d %14d",auxIdVuelo,auxIdAvion,auxNombrePiloto,auxFecha,auxDestino,auxCantPasajeros,auxHoraDespegue,auxHoraLlegada);

        }

        retorno = 1;
    }

    return retorno;
}

int controller_Reynoso_countCantPasajerosTotales(LinkedList* pListadoVuelos)
{
    int cantPasajerosTotales;
    int retorno = 0;

    cantPasajerosTotales = ll_count(pListadoVuelos,vuelo_cantPasajerosParaContar);

    if(cantPasajerosTotales > 0)
    {
        printf("\nLa cantidad total de pasajeros es : %d.\n",cantPasajerosTotales);
        retorno = 1;
    }
    else if(cantPasajerosTotales == 0)
    {
        printf("\n No hay pasajeros registrados en ningun vuelo.\n");
        retorno = 1;
    }

    return retorno;
}

int controller_Reynoso_countDestinoIrlanda(LinkedList* pListadoVuelos)
{
    LinkedList* listadoVuelosDestinoIrlanda = ll_newLinkedList();

    int cantPasajerosDestinoIrlanda;

    int retorno = 0;


    if(listadoVuelosDestinoIrlanda!=NULL)
    {
        listadoVuelosDestinoIrlanda = ll_filter(pListadoVuelos,vuelo_filterIrlanda);

        cantPasajerosDestinoIrlanda = ll_count(listadoVuelosDestinoIrlanda,vuelo_cantPasajerosParaContar);

        if(cantPasajerosDestinoIrlanda > 0)
        {
            printf("\nLa cantidad de pasajeros con destino a Irlanda es: %d.\n", cantPasajerosDestinoIrlanda);
            retorno = 1;
        }
        else if(cantPasajerosDestinoIrlanda == 0)
        {
            printf("\nNo hay pasajeros registrados en ningun vuelo con destino a Irlanda\n");
            retorno = 1;
        }

        ll_deleteLinkedList(listadoVuelosDestinoIrlanda);
    }

    return retorno;
}

int controller_Reynoso_saveAsTextVuelos(char* path, LinkedList* pListadoVuelos)
{
    FILE* pArchivo;
    Vuelo* pVuelo;

    int* auxIdVuelo;
    int* auxIdAvion;
    int* auxIdPiloto;
    char* auxFecha;
    char* auxDestino;
    int* auxCantPasajeros;
    int* auxHoraDespegue;
    int* auxHoraLlegada;

    int i;
    int size;
    int retorno = 0;

    if(path != NULL && pListadoVuelos != NULL)
    {
        auxIdVuelo = malloc(sizeof(int));
        auxIdAvion = malloc(sizeof(int));
        auxIdPiloto = malloc(sizeof(int));
        auxFecha = malloc(sizeof(char)*100);
        auxDestino = malloc(sizeof(char)*100);
        auxCantPasajeros = malloc(sizeof(int));
        auxHoraDespegue = malloc(sizeof(int));
        auxHoraLlegada = malloc(sizeof(int));

        size = ll_len(pListadoVuelos);

        pArchivo = fopen(path, "w");
        fprintf(pArchivo, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");

        for(i=0; i < size; i++)
        {
            pVuelo = ll_get(pListadoVuelos, i);

            vuelo_getIdVuelo(pVuelo, auxIdVuelo);
            vuelo_getIdAvion(pVuelo, auxIdAvion);
            vuelo_getIdPiloto(pVuelo, auxIdPiloto);
            vuelo_getFecha(pVuelo, auxFecha);
            vuelo_getDestino(pVuelo, auxDestino);
            vuelo_getCantPasajeros(pVuelo, auxCantPasajeros);
            vuelo_getHoraDespegue(pVuelo, auxHoraDespegue);
            vuelo_getHoraLlegada(pVuelo, auxHoraLlegada);

            fprintf(pArchivo, "%d,%d,%d,%s,%s,%d,%d,%d\n", *auxIdVuelo, *auxIdAvion, *auxIdPiloto, auxFecha, auxDestino, *auxCantPasajeros, *auxHoraDespegue, *auxHoraLlegada);
        }

        free(auxIdVuelo);
        free(auxIdAvion);
        free(auxIdPiloto);
        free(auxFecha);
        free(auxDestino);
        free(auxCantPasajeros);
        free(auxHoraDespegue);
        free(auxHoraLlegada);

        fclose(pArchivo);

        retorno = 1;
    }

    return retorno;
}

int controller_Reynoso_saveVuelosCortos(LinkedList* pListadoVuelos)
{
    LinkedList* listadoVuelosCortos = ll_newLinkedList();
    int retornoSave = 0;
    int retorno = 0;

    listadoVuelosCortos = ll_filter(pListadoVuelos, vuelo_filterCortos);

    if(listadoVuelosCortos != NULL)
    {
        retornoSave = controller_Reynoso_saveAsTextVuelos("VuelosCortos.csv", listadoVuelosCortos);

        if(retornoSave == 1)
        {
            printf("\nArchivo guardado exitosamente.\n\n");
        }
        else
        {
            printf("\nError al guardar archivo.\n\n");
        }

        retorno = 1;
    }

    ll_deleteLinkedList(listadoVuelosCortos);

    return retorno;
}

int controller_Reynoso_listVuelosDestinoPortugal(LinkedList* pListadoVuelos, LinkedList* pListadoPilotos)
{
    LinkedList* listadoVuelosDestinoPortugal = ll_newLinkedList();

    int retorno = 0;

    listadoVuelosDestinoPortugal = ll_filter(pListadoVuelos,vuelo_filterPortugal);

    if(listadoVuelosDestinoPortugal!=NULL && ll_len(listadoVuelosDestinoPortugal)>0)
    {
        controller_Reynoso_listVuelos(listadoVuelosDestinoPortugal,pListadoPilotos);
        retorno = 1;
    }

    ll_deleteLinkedList(listadoVuelosDestinoPortugal);

    return retorno;
}

int controller_Reynoso_listVuelosWithoutAlexLifeson(LinkedList* pListadoVuelos, LinkedList* pListadoPilotos)
{
    LinkedList* listadoVuelosSinAlexLifeson = ll_newLinkedList();

    int retorno = 0;

    listadoVuelosSinAlexLifeson = ll_filter(pListadoVuelos,vuelo_filterAlexLifeson);

    if(listadoVuelosSinAlexLifeson != NULL && ll_len(listadoVuelosSinAlexLifeson)>0)
    {
        controller_Reynoso_listVuelos(listadoVuelosSinAlexLifeson,pListadoPilotos);
        retorno = 1;
    }

    ll_deleteLinkedList(listadoVuelosSinAlexLifeson);

    return retorno;
}

int controller_Reynoso_listPilotos(LinkedList* pListadoPilotos)
{
    Piloto* pPiloto;

    int auxIdPiloto;
    char auxNombre[100];

    int i;
    int size;
    int retorno = 0;

    if(pListadoPilotos!=NULL)
    {
        size = ll_len(pListadoPilotos);

        printf("\nidPiloto:\t      nombre: ");

        for(i=0; i<size; i++)
        {
            pPiloto = ll_get(pListadoPilotos,i);

            piloto_getIdPiloto(pPiloto,&auxIdPiloto);
            piloto_getNombre(pPiloto,auxNombre);

            printf("\n%8d %20s",auxIdPiloto,auxNombre);
        }

        retorno = 1;
    }

    return retorno;
}

int controller_Reynoso_listPilotosFilter(LinkedList* pListadoPilotos)
{
    LinkedList* listadoPilotosSinPiloto = ll_newLinkedList();

    char auxNombre[100];
    int retorno = 0;

    if(pListadoPilotos != NULL && ll_len(pListadoPilotos)>0 &&listadoPilotosSinPiloto != NULL)
    {
        controller_Reynoso_listPilotos(pListadoPilotos);

        do
        {
            getString("\nIngrese nombre de piloto a filtrar: ",auxNombre);
        }
        while(isOnlyLetters(auxNombre)==0);

        listadoPilotosSinPiloto = ll_filter_parametro(pListadoPilotos,piloto_filterPiloto,auxNombre);

        if((ll_len(pListadoPilotos) == ll_len(listadoPilotosSinPiloto)))
        {
            printf("\nNo se ha filtrado ningun piloto, nombre inexistente.\n");
        }
        else
        {
            controller_Reynoso_listPilotos(listadoPilotosSinPiloto);
        }
        retorno = 1;
    }

    ll_deleteLinkedList(listadoPilotosSinPiloto);

    return retorno;
}

int controller_Reynoso_listVuelosPilotoFilter(LinkedList* pListadoVuelos, LinkedList* pListadoPilotos)
{
    LinkedList* listadoVuelosPiloto = ll_newLinkedList();

    int auxId;
    char auxNombre[100];

    int retorno = 0;

    if(pListadoVuelos!=NULL && pListadoPilotos != NULL && ll_len(pListadoPilotos) > 0 && listadoVuelosPiloto!=NULL)
    {

    controller_Reynoso_listPilotos(pListadoPilotos);

    do
    {
        getString("\nIngrese nombre de piloto a filtrar: ",auxNombre);
    }
    while(isOnlyLetters(auxNombre)==0);

    auxId = piloto_getIdByNombre(pListadoPilotos,auxNombre);

    if(auxId >= 0 && auxId <= 5)
    {
        listadoVuelosPiloto = ll_filter_parametroInt(pListadoVuelos, vuelo_filterPiloto, auxId);
        controller_Reynoso_listVuelos(listadoVuelosPiloto,pListadoPilotos);
    }
    else
    {
        printf("\nNo se ha filtrado ningun piloto, nombre inexistente o no asignado a ningun vuelo\n");
    }
    retorno = 1;
    }
    ll_deleteLinkedList(listadoVuelosPiloto);

    return retorno;
}
