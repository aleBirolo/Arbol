#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "arbol.h"

#define FILE_NAME_BIN "archivoArbol_b.bin"
#define FILE_NAME_TXT "archivoArbol.txt"

int comparar(const void *d1, const void *d2);
void mostrar(const void *d, int espacios, char flecha);
void mostrarConFormato(const void *d, int espacios, char flecha);

void pasarInfoAVectorOrd (void *info, void *vec);
void acumularValores (void *info, void *acum);
booleano abrirArhivo(FILE **fp, const char *nom, const char *modo);
void grabarArchivoTxt (void *dato, void *ptrFile);
void grabarArchivoBin (void *dato, void *ptrFile);
//void cargarArbolDesdeArchivoTXT (void *dato, void *ptrArbol);

#endif // MAIN_H_INCLUDED
