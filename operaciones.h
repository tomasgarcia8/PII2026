#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED
#include "vector.h"
#include "fraction.h"

void mostrar_fracciones(vector* fracciones);
void mostrar_fracciones_inverso(vector* fracciones);
fraction* calcular_maximo_fraccion(vector* fracciones);
fraction* calcular_minimo_fraccion(vector* fracciones);
fraction* calcular_suma_fracciones(vector* fracciones);
fraction* calcular_promedio_vector_fracciones(vector* fracciones);


#endif // OPERACIONES_H_INCLUDED
