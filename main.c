#include <stdio.h>
#include "vector.h"
#include "fraction.h"
#include "operaciones.h"

int main(void) {
    vector* v = vector_new(3);

    vector_add(v, fraction_new(99, 5));
    vector_add(v, fraction_new(67, 13));
    vector_add(v, fraction_new(13, 54));

    printf("Mostrar elementos:\n");
    mostrar_fracciones(v);

    printf("\nMostrar elementos inverso:\n");
    mostrar_fracciones_inverso(v);

    fraction* max = calcular_maximo_fraccion(v);
    if (max != NULL) {
        printf("\nMaximo: ");
        fraction_print(max);
    }

    fraction* min = calcular_minimo_fraccion(v);
    if (min != NULL) {
        printf("Minimo: ");
        fraction_print(min);
    }

    fraction* suma = calcular_suma_fracciones(v);
    if (suma != NULL) {
        printf("Suma: ");
        fraction_print(suma);
        fraction_destroy(suma); // Resultado dinamico: responsabilidad del main
    }

    fraction* prom = calcular_promedio_vector_fracciones(v);
    if (prom != NULL) {
        printf("Promedio: ");
        fraction_print(prom);
        fraction_destroy(prom); // Resultado dinamico: responsabilidad del main
    }

    // Liberar las fracciones contenidas y el vector
    for (int i = 0; i < vector_size(v); i++) {
        fraction_destroy((fraction*)vector_get(v, i));
    }
    vector_free(v);
    return 0;
}
