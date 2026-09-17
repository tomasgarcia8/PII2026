#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef struct _vector
{
    VECTOR_ELEMENT* a;
    int size;
    int max_size;
} vector;


/**

 * @brief Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño Máximo = ini_size.

 *

 * @param ini_size

 * @return vector*

 */

vector* vector_new(int ini_size)
{
    if (ini_size<=0)
    {
        return NULL;
    }
    vector* result=(vector*)malloc(sizeof(vector));
    if (result==NULL)
    {
        return NULL;
    }

    result->a=(VECTOR_ELEMENT*)malloc(ini_size*sizeof(VECTOR_ELEMENT));
    if (result->a == NULL)
    {
        free(result);
        return NULL;
    }
    result->size=0;
    result->max_size=ini_size;
    return result;
}


/**

 * @brief Eliminar el vector

 *

 * @param v

 */

void vector_free(vector* v)
{
    if (v==NULL)
    {
        return;
    }
    if (v->a != NULL)
    {
        free(v->a);
    }
    free(v);
}



/**

 * @brief Permite obtener el tamaño actual del vector

 *

 * @param v

 * @return int

 */

int vector_size(vector* v)
{
    if (v==NULL)
    {
        return 0;
    }
    return (v->size);
}



/**

 * @brief Devuelve 0 si no está lleno y 1 si está lleno.

 *

 * @param v

 * @return int

 */

int vector_isfull(vector* v)
{
    if (v==NULL)
    {
        return -1;
    }
    if (v->size==v->max_size)
    {
        return 1;
    }
    else return 0;

}



/**

 * @brief Devuelve 0 si no está vacío y 1 si está vacío.

 *

 * @param v

 * @return int

 */

int vector_isempty(vector* v){
    if (v==NULL)
    {
        return -1;
    }
    if (v->size==0)
    {
        return 1;
    }
    else return 0;
}

/**

 * @brief Permite obtener el valor de una posición del vector

 *

 * @param v

 * @param index

 * @return VECTOR_ELEMENT

 */

VECTOR_ELEMENT vector_get(vector* v, int index)
{
    if (v==NULL)
    {
        return NULL;
    }
    if(index>=0 && index<v->size)
    {
        return v->a[index];
    }
    else return NULL;

}


/**

 * @brief Permite reemplazar el valor de una posición del vector

 *

 * @param v

 * @param index

 * @return VECTOR_ELEMENT

 */

VECTOR_ELEMENT vector_set(vector* v, int index, VECTOR_ELEMENT value)
{
    if (v==NULL)
    {
        return NULL;
    }
    if (index>=0 && index<v->size)
    {
        v->a[index]=value;
        return v->a[index];
    }
    else return NULL;
}



/**

 * @brief Permite agregar un elemento al final

 *

 * @param v

 * @param value

 */

int vector_add(vector* v, VECTOR_ELEMENT value){
    if (v==NULL || vector_isfull(v)==1)
    {
        return 0;
    }
    v->a[v->size]=value;
    v->size++;
    return 1;
}


/**

 * @brief Permite agregar un elemento en una posición determinada.

 *

 * @param v

 * @param index

 * @param value

 */

int vector_insert(vector* v, int index, VECTOR_ELEMENT value){
    if (v == NULL || vector_isfull(v) == 1 || index < 0 || index > v->size)
    {
        return 0;
    }
    for (int i=v->size; i>index; i--)
    {
        v->a[i]=v->a[i-1];
    }
    v->a[index]=value;
    v->size++;
    return 1;
}


/**

 * @brief Permite eliminar un elemento del vector

 *

 * @param v

 * @param index

 */

VECTOR_ELEMENT vector_remove(vector* v, int index)
{
    if (v==NULL || vector_isempty(v)==1 || index<0 || index>v->size-1)
    {
        return NULL;
    }
    VECTOR_ELEMENT result=v->a[index];
    v->size--;
    for(int i=index; i<v->size; i++)
    {
        v->a[i]=v->a[i+1];
    }
    return result;
}


/**

 * @brief print the vector

 *

 */

void vector_print(vector* v, void (*print)(VECTOR_ELEMENT))
{
    if (v==NULL || print==NULL)
    {
        return;
    }
    for (int i=0; i<v->size; i++)
    {
        print(v->a[i]);
    }
    return;
}


