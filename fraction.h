#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

typedef struct _fraction fraction;



// crear una fraccion

fraction* fraction_new(int num,int den);



//destruir una fracción

void fraction_destroy (fraction* f);



//imprimir una fracción

void fraction_print (fraction* f);



//obtener numerador

int fraction_get_num (fraction* f);



//obtener denominador

int fraction_get_den (fraction* f);



//sumar 2 fracciones

fraction* fraction_add (fraction* f1, fraction* f2);



//restar 2 fracciones

fraction* fraction_sub (fraction* f1, fraction* f2);



//multiplicar 2 fracciones

fraction* fraction_mul (fraction* f1, fraction* f2);



//dividir 2 fracciones

fraction* fraction_div (fraction* f1, fraction* f2);



//simplificar una fracción

void fraction_simplify (fraction* f);



//comparar 2 fracciones

int fraction_cmp (fraction* f1, fraction* f2);

#endif // FRACTION_H_INCLUDED
