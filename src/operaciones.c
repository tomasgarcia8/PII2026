#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"


// Incluí funciones auxiliares unicamente visibles en este .c

void mostrar_vector_fracciones_auxiliar(vector* vector_fracciones, int indice){
    if (indice == vector_size(vector_fracciones)){
        return;
    }
    else {
        fraction_print((fraction*)vector_get(vector_fracciones,indice));
        mostrar_vector_fracciones_auxiliar(vector_fracciones,indice+1);
    }
}

void mostrar_fracciones(vector* fracciones){
    if (fracciones==NULL){
        return;
    }
    else{
        mostrar_vector_fracciones_auxiliar(fracciones,0);
    }
}

void mostrar_vector_fracciones_inverso_auxiliar(vector* vector_fracciones, int indice){
   if (indice == vector_size(vector_fracciones)){
        return;
    }
    else {
        mostrar_vector_fracciones_inverso_auxiliar(vector_fracciones,indice+1);
        fraction_print((fraction*)vector_get(vector_fracciones,indice));
    }
}

void mostrar_fracciones_inverso(vector* fracciones){
    if (fracciones==NULL){
        return;
    }
    else{
        mostrar_vector_fracciones_inverso_auxiliar(fracciones,0);
    }
}

fraction* calcular_maximo_fraccion_auxiliar(vector* fracciones, int indice){
    if (indice==vector_size(fracciones)-1){
        return vector_get(fracciones,indice);
    }
    else {
        fraction* maximo_del_resto_de_fracciones=calcular_maximo_fraccion_auxiliar(fracciones, indice+1);
        fraction* fraccion_actual=(fraction*)vector_get(fracciones,indice);
        if (fraction_cmp(fraccion_actual,maximo_del_resto_de_fracciones)>0){
            return fraccion_actual;
        }
        else {
            return maximo_del_resto_de_fracciones;
        }
    }
}


fraction* calcular_maximo_fraccion(vector* fracciones){
   if (fracciones != NULL && vector_isempty(fracciones)==0){
    return calcular_maximo_fraccion_auxiliar(fracciones,0);
   }
   return NULL;
}

fraction* calcular_minimo_fraccion_auxiliar(vector *fracciones, int indice){
    if (indice==vector_size(fracciones)-1){
        return vector_get(fracciones,indice);
    }
    else {
        fraction* minimo_del_resto_de_fracciones=calcular_minimo_fraccion_auxiliar(fracciones, indice+1);
        fraction* fraccion_actual=(fraction*)vector_get(fracciones,indice);
        if (fraction_cmp(fraccion_actual,minimo_del_resto_de_fracciones)<0){
            return fraccion_actual;
        }
        else {
            return minimo_del_resto_de_fracciones;
        }
    }
}

fraction* calcular_minimo_fraccion(vector* fracciones){
    if (fracciones!=NULL && vector_isempty(fracciones)==0){
        return calcular_minimo_fraccion_auxiliar(fracciones,0);
    }
    return NULL;
}

fraction* calcular_suma_vector_fracciones_aux (vector* fracciones, int indice){
    fraction* actual = (fraction*) vector_get(fracciones,indice);
    if (indice==vector_size(fracciones)-1){
        return fraction_new(fraction_get_num(actual), fraction_get_den(actual));
    }
    else {
        fraction* suma_del_resto= calcular_suma_vector_fracciones_aux(fracciones,indice+1);
        fraction* acumulador_total= fraction_add(actual,suma_del_resto);
        fraction_destroy(suma_del_resto);
        return acumulador_total;
    }
}

fraction* calcular_suma_fracciones (vector* fracciones) {
    if (fracciones != NULL && vector_isempty(fracciones) == 0) {
        return calcular_suma_vector_fracciones_aux(fracciones, 0);
    }
    return NULL;
}

fraction* calcular_promedio_vector_fracciones(vector* fracciones){
    if (fracciones!=NULL && vector_isempty(fracciones)==0){
      fraction* suma_vector = calcular_suma_fracciones(fracciones);
      if (suma_vector!=NULL){
        int tamanio_vector = vector_size(fracciones);
        fraction* divisor = fraction_new(1,tamanio_vector);
        fraction* promedio = fraction_mul(suma_vector,divisor);
        fraction_destroy(suma_vector);
        fraction_destroy(divisor);
        return promedio;
      }
    }
    return NULL;
}
