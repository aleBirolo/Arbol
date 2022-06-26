#ifndef UTILITARIOS_H_INCLUDED
#define UTILITARIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TODO_OK verdadero
#define ERROR 2

#define MINIMO(x,y) (x<=y ? x: y)

typedef enum
{
    verdadero=1,
    falso=0
}booleano;

typedef int (*Cmp)(const void *, const void *);
typedef void(*Mostrar)(const void *, int, char);
typedef booleano (*Acum)(void *, const void *);
typedef void (*Accion)(void *, void *);

#endif // UTILITARIOS_H_INCLUDED
