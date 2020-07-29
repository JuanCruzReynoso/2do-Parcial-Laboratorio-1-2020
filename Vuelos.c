#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vuelos.h"

Vuelo* vuelo_new()
{
    Vuelo* newVuelo;

    return newVuelo = (Vuelo*)malloc(sizeof(Vuelo));
}

Vuelo* vuelo_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr)
{
    Vuelo* newVuelo;
    newVuelo = vuelo_new();

    int auxIdVuelo;
    int auxIdAvion;
    int auxIdPiloto;
    int auxCantPasajeros;
    int auxHoraDespegue;
    int auxHoraLlegada;

    auxIdVuelo = atoi(idVueloStr);
    auxIdAvion = atoi(idAvionStr);
    auxIdPiloto = atoi(idPilotoStr);
    auxCantPasajeros = atoi(cantPasajerosStr);
    auxHoraDespegue = atoi(horaDespegueStr);
    auxHoraLlegada = atoi(horaLlegadaStr);

    if(newVuelo!=NULL && idVueloStr!=NULL && idAvionStr!=NULL && idPilotoStr!=NULL && fechaStr!=NULL && destinoStr!=NULL && cantPasajerosStr!=NULL && horaDespegueStr!=NULL && horaLlegadaStr!=NULL)
    {
        vuelo_setIdVuelo(newVuelo,auxIdVuelo);
        vuelo_setIdAvion(newVuelo,auxIdAvion);
        vuelo_setIdPiloto(newVuelo,auxIdPiloto);
        vuelo_setFecha(newVuelo,fechaStr);
        vuelo_setDestino(newVuelo,destinoStr);
        vuelo_setCantPasajeros(newVuelo,auxCantPasajeros);
        vuelo_setHoraDespegue(newVuelo,auxHoraDespegue);
        vuelo_setHoraLlegada(newVuelo,auxHoraLlegada);
    }

    return newVuelo;
}

void vuelo_delete(Vuelo* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int vuelo_setIdVuelo(Vuelo* this,int idVuelo)
{
    int retorno = 0;

    if(this != NULL)
    {
        if(idVuelo > 0)
        {
            this->idVuelo = idVuelo;
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_getIdVuelo(Vuelo* this,int* idVuelo)
{
    int retorno = 0;

    if(this != NULL && idVuelo!= NULL)
    {
        *idVuelo = this->idVuelo;
        retorno = 1;
    }

    return retorno;
}

int vuelo_setIdAvion(Vuelo* this,int idAvion)
{
    int retorno = 0;

    if(this != NULL)
    {
        if(idAvion > 0)
        {
            this->idAvion = idAvion;
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_getIdAvion(Vuelo* this,int* idAvion)
{
    int retorno = 0;

    if(this != NULL && idAvion!= NULL)
    {
        *idAvion = this->idAvion;
        retorno = 1;
    }

    return retorno;
}

int vuelo_setIdPiloto(Vuelo* this,int idPiloto)
{
    int retorno = 0;

    if(this != NULL)
    {
        if(idPiloto > 0)
        {
            this->idPiloto = idPiloto;
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_getIdPiloto(Vuelo* this,int* idPiloto)
{
    int retorno = 0;

    if(this != NULL && idPiloto!= NULL)
    {
        *idPiloto = this->idPiloto;
        retorno = 1;
    }

    return retorno;
}

int vuelo_setFecha(Vuelo* this,char* fecha)
{
    int retorno = 0;

    if(this != NULL && fecha != NULL)
    {
        strcpy(this->fecha,fecha);
        retorno = 1;
    }

    return retorno;
}

int vuelo_getFecha(Vuelo* this,char* fecha)
{
    int retorno = 0;

    if(this != NULL && fecha != NULL)
    {
        strcpy(fecha,this->fecha);
        retorno = 1;
    }

    return retorno;
}

int vuelo_setDestino(Vuelo* this,char* destino)
{
    int retorno = 0;

    if(this != NULL && destino != NULL)
    {
        strcpy(this->destino,destino);
        retorno = 1;
    }

    return retorno;
}

int vuelo_getDestino(Vuelo* this,char* destino)
{
    int retorno = 0;

    if(this != NULL && destino != NULL)
    {
        strcpy(destino,this->destino);
        retorno = 1;
    }

    return retorno;
}


int vuelo_setCantPasajeros(Vuelo* this,int cantPasajeros)
{
    int retorno = 0;

    if(this != NULL)
    {
        this->cantPasajeros = cantPasajeros;
        retorno = 1;
    }

    return retorno;
}

int vuelo_getCantPasajeros(Vuelo* this,int* cantPasajeros)
{
    int retorno = 0;

    if(this != NULL && cantPasajeros!= NULL)
    {
        *cantPasajeros = this->cantPasajeros;
        retorno = 1;
    }

    return retorno;
}

int vuelo_setHoraDespegue(Vuelo* this,int horaDespegue)
{
    int retorno = 0;

    if(this != NULL)
    {
        this->horaDespegue = horaDespegue;
        retorno = 1;
    }

    return retorno;
}

int vuelo_getHoraDespegue(Vuelo* this,int* horaDespegue)
{
    int retorno = 0;

    if(this != NULL && horaDespegue!= NULL)
    {
        *horaDespegue = this->horaDespegue;
        retorno = 1;
    }

    return retorno;
}

int vuelo_setHoraLlegada(Vuelo* this,int horaLlegada)
{
    int retorno = 0;

    if(this != NULL)
    {
        this->horaLlegada = horaLlegada;
        retorno = 1;
    }

    return retorno;
}

int vuelo_getHoraLlegada(Vuelo* this,int* horaLlegada)
{
    int retorno = 0;

    if(this != NULL && horaLlegada!= NULL)
    {
        *horaLlegada = this->horaLlegada;
        retorno = 1;
    }

    return retorno;
}

int vuelo_cantPasajerosParaContar(void* pElement)
{
    int cantidad = 0;

    if(pElement != NULL)
    {
        vuelo_getCantPasajeros(pElement, &cantidad);
    }

    return cantidad;
}

int vuelo_filterIrlanda(void* pElement)
{
    char auxDestino[100];
    int retorno = 0;

    if(pElement != NULL)
    {
        vuelo_getDestino(pElement, auxDestino);
        if(strcmpi(auxDestino, "Irlanda") == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int vuelo_filterCortos(void* pElement)
{
    int auxHoraDespegue;
    int auxHoraLlegada;
    int demora;
    int retorno = 0;

    if(pElement != NULL)
    {
        vuelo_getHoraDespegue(pElement, &auxHoraDespegue);
        vuelo_getHoraLlegada(pElement, &auxHoraLlegada);

        demora = auxHoraLlegada-auxHoraDespegue;

        if(demora < 3)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filterPortugal(void* pElement)
{
    char auxDestino[100];
    int retorno = 0;

    if(pElement != NULL)
    {
        vuelo_getDestino(pElement, auxDestino);
        if(strcmpi(auxDestino, "Portugal") == 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filterAlexLifeson(void* pElement)
{
    int auxId;
    int retorno = 0;

    if(pElement != NULL)
    {
        vuelo_getIdPiloto(pElement, &auxId);

        if(auxId != 1)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filterPiloto(void* pElement, int idPiloto)
{
    int auxId;
    int retorno = 0;

    if(pElement != NULL)
    {
        vuelo_getIdPiloto(pElement, &auxId);

        if(auxId == idPiloto)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int vuelo_setImporteTotal(Vuelo* this,int importeTotal)
{
    int retorno = 0;

    if(this != NULL)
    {
        this->importeTotal = importeTotal;
        retorno = 1;
    }

    return retorno;
}
int vuelo_getImporteTotal(Vuelo* this,int* importeTotal)
{
    int retorno = 0;

    if(this!=NULL)
    {
        *importeTotal = this->importeTotal;
        retorno = 1;
    }

    return retorno;
}

void* vuelo_criterioImporteFinal(void* pElemento)
{
    int auxImporteTotal;
    char auxDestino[100];
    int auxCantPasajeros;


    if(pElemento!=NULL)
    {
        vuelo_getDestino(pElemento,auxDestino);
        vuelo_getCantPasajeros(pElemento,&auxCantPasajeros);

        if(strcmpi(auxDestino, "Portugal") == 0)
        {
            auxImporteTotal = auxCantPasajeros * 1000;
        }
        else
        {
            auxImporteTotal = auxCantPasajeros * 1500;
        }

        vuelo_setImporteTotal(pElemento,auxImporteTotal);
    }

    return pElemento;
}
