#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Pilotos.h"


Piloto* piloto_new()
{
    Piloto* newPiloto;
    newPiloto = (Piloto*) malloc(sizeof(Piloto));

    if(newPiloto!=NULL)
    {
        piloto_setIdPiloto(newPiloto,0);
        piloto_setNombre(newPiloto," ");
    }

    return newPiloto;
}

Piloto* piloto_newParametros(char* idPilotoStr, char* nombreStr)
{
    Piloto* newPiloto;
    newPiloto = piloto_new();

    int auxIdPiloto;

    auxIdPiloto = atoi(idPilotoStr);

    if(newPiloto!=NULL)
    {
        piloto_setIdPiloto(newPiloto,auxIdPiloto);
        piloto_setNombre(newPiloto,nombreStr);
    }

    return newPiloto;
}

void piloto_delete(Piloto* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int piloto_setIdPiloto(Piloto* this,int idPiloto)
{
    int retorno = 0;

    if(this!=NULL)
    {
        if(idPiloto > 0)
        {
            this->idPiloto = idPiloto;
            retorno = 1;
        }
    }

    return retorno;
}

int piloto_getIdPiloto(Piloto* this,int* idPiloto)
{
    int retorno = 0;

    if(this!=NULL && idPiloto!=NULL)
    {
        *idPiloto = this->idPiloto;
        retorno = 1;
    }

    return retorno;
}

int piloto_setNombre(Piloto* this,char* nombre)
{
    int retorno = 0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 1;
    }

    return retorno;
}

int piloto_getNombre(Piloto* this,char* nombre)
{
    int retorno = 0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 1;
    }

    return retorno;
}

Piloto* piloto_getPilotoById(LinkedList* pListadoPilotos,int id)
{
    Piloto* pPiloto;

    int auxId;

    int i;
    int size;

    if(pListadoPilotos != NULL && id > 0)
    {
        size = ll_len(pListadoPilotos);

        for(i=0; i<size; i++)
        {
            pPiloto = ll_get(pListadoPilotos,i);
            piloto_getIdPiloto(pPiloto,&auxId);

            if(auxId == id)
            {
               break;
            }
        }
    }

    return pPiloto;
}

int piloto_getIdByNombre(LinkedList* pListadoPilotos, char* nombre)
{
    Piloto* pPiloto;
    char auxNombre[100];
    int auxId;

    int i;
    int size;
    int retorno = -1;

    if(pListadoPilotos != NULL)
    {
        size = ll_len(pListadoPilotos);

        for(i=0; i<size; i++)
        {
            pPiloto = ll_get(pListadoPilotos, i);

            piloto_getNombre(pPiloto, auxNombre);

            if(strcmpi(auxNombre, nombre) == 0)
            {
                piloto_getIdPiloto(pPiloto, &auxId);

                retorno = auxId;
                break;
            }
        }
    }
    return retorno;
}

int piloto_filterPiloto(void* pElement, char* nombre)
{
    char auxNombre[100];
    int retorno = 0;

    if(pElement != NULL)
    {
        piloto_getNombre(pElement, auxNombre);

        if(strcmpi(auxNombre, nombre) != 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
