#include "menu.h"

void opcionesMenu()
{
    printf ("\n Menu\n"
            "  %d: Reiniciar\n"
            "  %d: Crear Arbol\n"
            "  %d: Es Arbol Vacio\n"
            "  %d: Es Arbol Lleno\n"
            "  %d: Mostrar Arbol\n"
            "  %d: Mostrar Arbol en PreOrden\n"
            "  %d: Mostrar Arbol en InOrden\n"
            "  %d: Mostrar Arbol En PostOrden\n"
            "  %d: Insertar En Arbol Binario Busqueda\n"
            "  %d: Altura Arbol\n"
            "  %d: Contar Nodos Hasta Nivel\n"
            " %d: Es Arbol Completo\n"
            " %d: Es Arbol Balanceado\n"
            " %d: Es Arbol AVL\n"
            " %d: Buscar Clave Arbol\n"
            " %d: Mayor Nodo\n"
            " %d: Menor Nodo\n"
            " %d: Eliminar Raiz De Arbol\n"
            " %d: Eliminar Nodo Por Clave en Arbol\n"
            " %d: Contar Nodos\n"
            " %d: Vaciar Arbol\n"
            " %d: De Arbol a Vector Ordenado y a Nuevo Arbol\n"
            " %d: Recrear Arbol Desde Vector\n"
            " %d: Rotar Arbol en sentido Antihorario\n"
            " %d: Rotar Arbol En Sentido Horario\n"
            " %d: Balancear Arbol\n"
            " %d: Contar Hojas\n"
            " %d: Contar Solo No Hojas\n"
            " %d: Contar Hijos Por Izquierda\n"
            " %d: Contar Hijos Por Derecha\n"
            " %d: Podar Arbol\n"
            " %d: Cortar Hojas\n"
            " %d: Cantidad Ramas\n"
            " %d: Promedio Valor De Los Nodos\n"
            " %d: Ver Los Nodos De Una Altura Dada\n"
            " %d: Ver Los Nodos Hasta Una AlturaDada Excluida\n"
            " %d: Ver Los Nodos Hasta Una AlturaDada Incluida\n"
            " %d: Ver Nodos Hasta Nivel\n"
            " %d: Ver Nodos De Un Nivel\n"
            " %d: Ver Nodos A Partir De UnNivel\n"
            " %d: Profundidad Arbol\n"
            " %d: Grabar Arbol En Arhivo Txt\n"
            " %d: Grabar Arbol En Arhivo Bin\n"
            " %d: Cargar Arbol Desde Archivo Bin\n"
            //" %d:\n"
            //" %d:\n"
            //" %d:\n"
            //" %d:\n"
            "  %d: Salir\n"
            ,e_reiniciar
            ,e_crearArbol
            ,e_esArbolVacio
            ,e_esArbolLleno
            ,e_mostrarArbol
            ,e_preOrdenMostrar
            ,e_inOrdenMostrar
            ,e_postOrdenMostrar
            ,e_insertarEnArbolBinarioBusqueda
            ,e_alturaArbol
            ,e_contarNodosHastaNivel
            ,e_esArbolCompleto
            ,e_esArbolBalanceado
            ,e_esArbolAVL
            ,e_buscarClaveArbol
            ,e_mayorNodo
            ,e_menorNodo
            ,e_eliminarRaizArbol
            ,e_eliminarNodoPorClaveDeArbol
            ,e_contarNodos
            ,e_vaciarArbol
            ,e_deArbolAVectorYANuevoArbol
            ,e_recrearArbolDesdeVector
            ,e_rotarArbolEnSentidoAntihorario
            ,e_rotarArbolEnSentidoHorario
            ,e_balancearArbol
            ,e_contarHojas
            ,e_contarSoloNoHojas
            ,e_contarHijosPorIzquierda
            ,e_contarHijosPorDerecha
            ,e_podarArbol
            ,e_cortarHojas
            ,e_cantidadRamas
            ,e_promedioValorDeLosNodos
            ,e_verLosNodosDeUnaAlturaDada
            ,e_verLosNodosHastaUnaAlturaDada_Exc
            ,e_verLosNodosHastaUnaAlturaDada_Inc
            ,e_verNodosHastaNivel
            ,e_verNodosDeUnNivel
            ,e_verNodosAPartirDeUnNivel
            ,e_profundidadArbol
            ,e_grabarArbolEnArhivoTxt
            ,e_grabarArbolEnArhivoBin
            ,e_cargarArbolDesdeArchivoBin_inicio
            ,e_salir);
}

int menu()
{
    int opc;

    do
    {
        opcionesMenu();
        printf ("\n Ingrese opcion: ");
        scanf("%d", &opc);
        if (opc< OPC_VAL_MENU_INF || OPC_VAL_MENU_SUP < opc)
        {
            printf ("\n Opcion invalida. Vuelva a ingresar opcion. \n ");
            system ("pause");
            system("cls");
            fflush(stdin);
        }
    }while ( opc< OPC_VAL_MENU_INF || OPC_VAL_MENU_SUP < opc );

    return opc;
}
