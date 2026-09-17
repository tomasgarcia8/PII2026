#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fraction.h"

static int mcd(int a, int b)
{
    while (b!=0)
    {
        int resto = a % b;
        a=b;
        b=resto;
    }
    return a;
}


typedef struct _fraction
{
    int num;
    int den;
} fraction;



fraction* fraction_new(int num, int den){
    fraction* result;
    if (den==0)
    {
        return NULL;
    }

    result=(fraction*)malloc(sizeof(fraction));
    if (result==NULL)
    {
        return NULL;
    }
    result->num=num;
    result->den=den;
    return result;
}



void fraction_destroy(fraction* f){
    free(f);
}



void fraction_print(fraction* f){
    if (f==NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d/%d\n",f->num,f->den);
}



int fraction_get_num(fraction* f){
    if (f==NULL)
    {
        return 0;
    }
    return f->num;
}


int fraction_get_den(fraction* f){
    if (f==NULL)
    {
        return 0;
    }
    return f->den;
}



void fraction_simplify(fraction* f){
    if (f==NULL)
    {
        return;
    }
    int result_mcd= mcd(abs(f->num),abs(f->den));
    if (result_mcd!=0){
        f->num=(f->num / result_mcd);
        f->den=(f->den / result_mcd);

    }
}



fraction* fraction_add (fraction* f1, fraction* f2){
    if(f1==NULL || f2==NULL)
    {
        return NULL;
    }
    int nuevo_num= (f1->num * f2->den) + (f1->den) * (f2->num);
    int nuevo_den= f1->den * f2->den;
    fraction* result=fraction_new(nuevo_num,nuevo_den);
    fraction_simplify(result);
    return result;
}


fraction* fraction_sub (fraction* f1, fraction* f2){
    if(f1==NULL || f2==NULL)
    {
        return NULL;
    }
    int nuevo_num= (f1->num * f2->den) - (f1->den) * (f2->num);
    int nuevo_den= f1->den * f2->den;
    fraction* result=fraction_new(nuevo_num,nuevo_den);
    fraction_simplify(result);
    return result;
}



fraction* fraction_mul (fraction* f1, fraction* f2){
    if(f1==NULL || f2==NULL)
    {
        return NULL;
    }
    int nuevo_num= f1->num * f2->num;
    int nuevo_den= f1->den * f2->den;
    fraction* result=fraction_new(nuevo_num,nuevo_den);
    fraction_simplify(result);
    return result;
}



fraction* fraction_div (fraction* f1, fraction* f2){
    if(f1==NULL || f2==NULL)
    {
        return NULL;
    }
    int nuevo_num= f1->num * f2->den;
    int nuevo_den= f1->den * f2->num;
    fraction* result=fraction_new(nuevo_num,nuevo_den);
    fraction_simplify(result);
    return result;
}


int fraction_cmp(fraction* f1, fraction* f2){
    int valor1= f1->num * f2-> den;
    int valor2= f2->num * f1->den;
    return valor1-valor2;

}

