#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;

        for(i=0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;///Por cada iteraci�n, pNode se convierte en pNextNode, por lo que se va recorriendo la lista de nodos
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev = NULL;
    Node* next = NULL;


    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        int size = ll_len(this);
        Node* nuevoNodo = (Node*)malloc(sizeof(Node));///Se crea luego de entrar en el if
        nuevoNodo->pElement = pElement;

        if(nodeIndex == 0) ///Caso donde se quiere enlazar el nodo como primer elemento de la lista
        {
            this -> pFirstNode = nuevoNodo;

            if(size == 0)///Caso donde el nodo a enlazar es el primer elemento existente en la lista
            {
                nuevoNodo->pNextNode = NULL;
            }
            else ///Caso donde la lista ya pose�a nodos enlazados
            {
                next = getNode(this, nodeIndex+1);
                nuevoNodo->pNextNode = next;
            }
        }

        if(nodeIndex > 0) ///Caso donde el nodo se quiere enlazar al medio o al final
        {
            next = getNode(this, nodeIndex+1);
            prev = getNode(this, nodeIndex-1);
            prev->pNextNode = nuevoNodo;
            if(nodeIndex == size)///Caso donde el nodo se enlaza al final
            {
                nuevoNodo->pNextNode = NULL;
            }
            else ///Caso donde el nodo se quiere enlazar al medio
            {
                nuevoNodo->pNextNode = next;
            }
        }
        returnAux = 0;
        this->size++;
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        addNode(this, size, pElement); ///Al pasarle size, estoy agregando el elemento al final

        returnAux = 0;
    }

    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        pNodo = getNode(this, index);

        if(pNodo != NULL)
        {
            returnAux = pNodo->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodo;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        pNodo = getNode(this, index);

        if(pNodo != NULL)
        {
            pNodo->pElement = pElement;

            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* prev;
    Node* pNodo;
    Node* next;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        pNodo = getNode(this, index);

        if(pNodo != NULL)
        {
            next = getNode(this, index+1);

            if(next != NULL && index != 0)
            {
                prev = getNode(this, index-1);
                prev->pNextNode = next;

            }
            else
            {
                this->pFirstNode = next;

            }

            free(pNodo);

        }

        this->size--;
        returnAux = 0;

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
        for(i=0; i < ll_len(this); i++)
        {
            ll_remove(this, i);
        }

        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        ll_clear(this);
        free(this);

        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
        for(i=0; i < ll_len(this); i++)
        {
            if(ll_get(this, i) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 1;

        if(ll_len(this) > 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        addNode(this, index, pElement);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL)
    {
        returnAux = ll_get(this, index);
        ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;

        if(ll_indexOf(this, pElement) >= 0)
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pElement;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 0;

        if(ll_len(this) >= ll_len(this2))
        {
            returnAux = 1;

            for(i=0; i<ll_len(this2); i++)
            {
                pElement = ll_get(this2, i);

                if(ll_contains(this, pElement) == 0)
                {
                    returnAux = 0;
                    break;
                }
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;

    if(this != NULL && from >= 0 && to > from && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();

        if(cloneArray != NULL)
        {
            for(i=from; i<to; i++)
            {
                ll_add(cloneArray, ll_get(this, i));
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    void* pElementAux;
    void* pElement1;
    void* pElement2;
    int i;
    int j;
    int size;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        size = ll_len(this);

        if(size > 0)
        {
            if(order == 1)
            {
                for(i=0; i<size-1; i++)
                {
                    for(j=i+1; j<size; j++)
                    {
                        pElement1 = ll_get(this, i);
                        pElement2 = ll_get(this, j);

                        if(pFunc(pElement1, pElement2) > 0)
                        {
                            pElementAux = pElement1;
                            ll_set(this, i, pElement2);
                            ll_set(this, j, pElementAux);
                        }
                    }
                }
            }
            else
            {
                for(i=0; i<size-1; i++)
                {
                    for(j=i+1; j<size; j++)
                    {
                        pElement1 = ll_get(this, i);
                        pElement2 = ll_get(this, j);

                        if(pFunc(pElement1, pElement2) < 0)
                        {
                            pElementAux = pElement1;
                            ll_set(this, i, pElement2);
                            ll_set(this, j, pElementAux);
                        }
                    }
                }
            }

            returnAux = 0;
        }
    }

    return returnAux;
}

int ll_count(LinkedList* this, int (*fn)(void* element))
{
    int i;
    int size;
    void* pElement;
    int auxCantPasajeros;
    int acumulador = 0;
    int retorno = -1;

    if(this != NULL && (!ll_isEmpty(this)) && fn != NULL)
    {
        size = ll_len(this);

        for(i=0; i<size; i++)
        {
            pElement = ll_get(this,i);

            auxCantPasajeros = fn(pElement);

            if(auxCantPasajeros > -1)
            {
                acumulador = acumulador + auxCantPasajeros;
            }
        }

        retorno = acumulador;
    }

    return retorno;
}

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
    int i;
    int size;
    int retornoFn;

    void* pElement;
    LinkedList* listadoFilter = ll_newLinkedList();

    if(this != NULL && (!ll_isEmpty(this)) && listadoFilter!=NULL && fn != NULL )
    {
        size = ll_len(this);

        for(i=0; i<size; i++)
        {
            pElement = ll_get(this,i);

            retornoFn = fn(pElement);

            if(pElement!=NULL && retornoFn == 1)
            {
                ll_add(listadoFilter,pElement);
            }
        }
    }

    return listadoFilter;
}

LinkedList* ll_filter_parametro(LinkedList* this, int (*fn)(void* element, char* str), char* str)
{
    int i;
    int size;
    int retornoFn;

    void* pElement;
    LinkedList* listadoFilter = ll_newLinkedList();

    if(this != NULL && (!ll_isEmpty(this)) && listadoFilter!=NULL && fn != NULL )
    {
        size = ll_len(this);

        for(i=0; i<size; i++)
        {
            pElement = ll_get(this,i);

            retornoFn = fn(pElement,str);

            if(pElement!=NULL && retornoFn == 1)
            {
                ll_add(listadoFilter,pElement);
            }
        }
    }

    return listadoFilter;
}

LinkedList* ll_filter_parametroInt(LinkedList* this, int (*fn)(void* element, int numero), int numero)
{
    int i;
    int size;
    int retornoFn;

    void* pElement;
    LinkedList* listadoFilter = ll_newLinkedList();

    if(this != NULL && (!ll_isEmpty(this)) && listadoFilter!=NULL && fn != NULL )
    {
        size = ll_len(this);

        for(i=0; i<size; i++)
        {
            pElement = ll_get(this,i);

            retornoFn = fn(pElement,numero);

            if(pElement!=NULL && retornoFn == 1)
            {
                ll_add(listadoFilter,pElement);
            }
        }
    }

    return listadoFilter;
}

LinkedList* ll_map (LinkedList* this, void*(*pFunc)(void* element))
{
    int i;
    int size;

    void* pElement;
    LinkedList* listadoMap = ll_newLinkedList();

    if(this!=NULL && (!ll_isEmpty(this)) && listadoMap!=NULL && pFunc !=NULL)
    {
        size = ll_len(this);

        for(i=0; i<size; i++)
        {
            pElement = ll_get(this,i);

            pElement = pFunc(pElement);

            ll_add(listadoMap,pElement);
        }
    }

    return listadoMap;
}
