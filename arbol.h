#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <memory.h>
#include <math.h>
#include "utilitarios.h"

typedef struct s_nodo
{
    void *info;
    unsigned tamInfo;
    struct s_nodo *izq,
                  *der;
}t_nodo;

typedef t_nodo *t_arbol;

void crearArbol (t_arbol *pa);
booleano esArbolVacio (t_arbol *pa);
booleano esArbolLleno (t_arbol *pa, unsigned tamDato);
void preOrdenMostrar (t_arbol *pa, Mostrar mostrar, int espacios, char flecha);
void inOrdenMostrar (t_arbol *pa, Mostrar mostrar, int espacios, char flecha);
void postOrdenMostrar (t_arbol *pa, Mostrar mostrar, int espacios, char flecha);
booleano insertarEnArbolBinarioBusqueda (t_arbol *pa, void *dato, unsigned tamDato, Cmp cmp);
int alturaArbol (t_arbol *pa);
int contarNodosHastaNivel(t_arbol *pa, int nivel);
booleano esArbolCompleto(t_arbol *pa);
booleano esArbolBalanceado(t_arbol *pa);
booleano esArbolAVL(t_arbol *pa);

t_nodo **buscarClaveArbol (t_arbol *pa, const void *dato, Cmp cmp);
t_nodo **mayorNodo(t_arbol *pa);
t_nodo **menorNodo(t_arbol *pa);

booleano eliminarRaizArbol(t_arbol *pa);
booleano eliminarNodoPorClaveDeArbol(t_arbol *pa, void *dato, unsigned tamDato, Cmp cmp);
int contarNodos(t_arbol *pa);
int vaciarArbol (t_arbol *pa);

void recorrerEnPreOrdenYAccion(t_arbol *pa, void *dato, Accion accion);
void recorrerEnInOrdenYAccion(t_arbol *pa, void *dato, Accion accion);
void recorrerEnPostOrdenYAccion(t_arbol *pa, void *dato, Accion accion);

void cargarArbolDesdeVectorOrdenado (t_arbol *pa, void *dato, int li, int ls, unsigned tamDato, Cmp cmp);
void recrearArbolDesdeVector (t_arbol *pa, void *dato, int li, int ls, unsigned tamDato, Cmp cmp);

void rotarArbolEnSentidoAntihorario(t_arbol *pa );
void rotarArbolEnSentidoAntihorario_doble(t_arbol *pa );
void rotarArbolEnSentidoHorario(t_arbol *pa );
void rotarArbolEnSentidoHorario_doble(t_arbol *pa );

void balancearArbol(t_arbol *pa, int cantRot);
void balancearArbol_DSW(t_arbol *pa);

int esAVL2CalculoArbol(t_arbol *pa);
booleano esAVL2ArbolBin( t_arbol *pa);


/// Nodos
int contarHojas(const t_arbol *pa);
int contarSoloNoHojas(const t_arbol *pa);
int contarHijosPorIzquierda(const t_arbol *pa);
int contarHijosPorDerecha(const t_arbol *pa);

int podarArbol(t_arbol *pa, int nivel);
int cortarHojas(t_arbol *pa);

int cantidadRamas( t_arbol *pa);
float promedioValorDeLosNodos (t_arbol *pa, Accion accion );

void verLosNodosDeUnaAlturaDada (t_arbol *pa, int altura, Mostrar mostrar);
void verLosNodosHastaUnaAlturaDada_Exc (t_arbol *pa, int altura, Mostrar mostrar);
void verLosNodosHastaUnaAlturaDada_Inc (t_arbol *pa, int altura, Mostrar mostrar);
void verNodosHastaNivel (t_arbol *pa, int nivel, Mostrar mostrar);
void verNodosDeUnNivel (t_arbol *pa, int nivel, Mostrar mostrar);
void verNodosAPartirDeUnNivel (t_arbol *pa, int nivel, Mostrar mostrar);
int profundidadArbol (t_arbol *pa);

//booleano cargarArbolDesdeArchivoTxt(t_arbol *pa);

void cargarArbolDesdeArchivoBin(t_arbol *pa, FILE **archivo, size_t tamElem, int li, int ls, Cmp cmp);
booleano cargarArbolDesdeArchivoBin_inicio(t_arbol *pa, FILE **archivo, size_t tamElem, Cmp cmp);

#endif // ARBOL_H_INCLUDED
