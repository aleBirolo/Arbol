#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define OPC_VAL_MENU_INF -1
#define OPC_VAL_MENU_SUP 43

typedef enum
{
     e_reiniciar = -1
    ,e_salir = 0
    ,e_crearArbol = 1
    ,e_esArbolVacio = 2
    ,e_esArbolLleno = 3
    ,e_mostrarArbol = 4
    ,e_preOrdenMostrar = 5
    ,e_inOrdenMostrar = 6
    ,e_postOrdenMostrar = 7
    ,e_insertarEnArbolBinarioBusqueda = 8
    ,e_alturaArbol = 9
    ,e_contarNodosHastaNivel = 10
    ,e_esArbolCompleto = 11
    ,e_esArbolBalanceado = 12
    ,e_esArbolAVL = 13
    ,e_buscarClaveArbol = 14
    ,e_mayorNodo = 15
    ,e_menorNodo = 16
    ,e_eliminarRaizArbol = 17
    ,e_eliminarNodoPorClaveDeArbol = 18
    ,e_contarNodos = 19
    ,e_vaciarArbol = 20
    ,e_deArbolAVectorYANuevoArbol = 21
    ,e_recrearArbolDesdeVector = 22
    ,e_rotarArbolEnSentidoAntihorario = 23
    ,e_rotarArbolEnSentidoHorario = 24
    ,e_balancearArbol = 25
    ,e_contarHojas = 26
    ,e_contarSoloNoHojas = 27
    ,e_contarHijosPorIzquierda = 28
    ,e_contarHijosPorDerecha = 29
    ,e_podarArbol = 30
    ,e_cortarHojas = 31
    ,e_cantidadRamas = 32
    ,e_promedioValorDeLosNodos = 33
    ,e_verLosNodosDeUnaAlturaDada =34
    ,e_verLosNodosHastaUnaAlturaDada_Exc = 35
    ,e_verLosNodosHastaUnaAlturaDada_Inc = 36
    ,e_verNodosHastaNivel = 37
    ,e_verNodosDeUnNivel = 38
    ,e_verNodosAPartirDeUnNivel = 39
    ,e_profundidadArbol = 40
    ,e_grabarArbolEnArhivoTxt = 41
    ,e_grabarArbolEnArhivoBin = 42
    ,e_cargarArbolDesdeArchivoBin_inicio = 43

}e_opciones;

void opcionesMenu();
int menu();

#endif // MENU_H_INCLUDED
