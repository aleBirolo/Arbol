#include "main.h"

#define lote_1 {100,50,190,25,75,125,175,10,30,60,110,130,160,200,55,70,70} /// inicio
#define lote_2 {100,50,150,25,75,125,175,10,30,60,90,110,130,160,200} /// Completo
#define lote_3 {100,50,150,25,75,125,175,10,30,90,110} /// Balanceado
#define lote_4 {100,50,150,25,75,175,10,30} /// AVL
#define lote_5 {100,50,150,110,170,160,180} /// rotacion antihorario
#define lote_6 {100,50,150,40,70,30,45} /// rotacion horario
#define lote_7 {10,20,30,40,50,60,70,80,90,100} /// Balanceo 1
#define lote_8 {50,40,30,20,10} /// Balanceo 2
#define lote_9 {15,20,17,30,19,25,40,32,50} /// Balanceo 3 (complejo)
#define lote_10 {5,7,10,15 } /// Balanceo

int main()
{
    t_arbol arbol,
            arbolAux;
    t_nodo **nodo;
    FILE *fp,
         *fpAux;
    int i,
        clave,
        opc,
        ret,
        retTotal,
        nivel,
        altura,
        cantNodos,
        *vecAux,
        vec[]=lote_2;

    ret = TODO_OK;
    opc = menu();

    while(opc != e_salir)
    {
        switch(opc)
        {
            case e_reiniciar:

                vaciarArbol(&arbol);
                vaciarArbol(&arbolAux);
                fp=NULL;
                fpAux=NULL;
                nodo=NULL;
                vecAux=NULL;
                i=clave=nivel=altura=cantNodos=0;
                main();
                break;

            case e_crearArbol:

                crearArbol(&arbol);
                printf ("\n Arbol creado");
                break;

            case e_esArbolVacio:

                printf ("\n El arbol %s vacio.", esArbolVacio(&arbol) ? "esta": "no esta");
                break;

            case e_esArbolLleno:

                printf ("\n El arbol %s lleno.", esArbolLleno(&arbol, sizeof(int)) ? "esta": "no esta");
                break;

            case e_mostrarArbol:

                printf ("\n Arbol: \n\n");
                inOrdenMostrar(&arbol, mostrarConFormato,0, ' ');
                break;

            case e_preOrdenMostrar:

                printf ("\n Arbol en PreOrden: \n\n");
                preOrdenMostrar(&arbol, mostrar, 0, ' ');
                break;

            case e_inOrdenMostrar:

                printf ("\n Arbol en InOrden: \n\n");
                inOrdenMostrar(&arbol, mostrar, 0, ' ');
                break;

            case e_postOrdenMostrar:

                printf ("\n Arbol en PostOrden: \n\n");
                postOrdenMostrar(&arbol, mostrar,0, ' ');
                break;

            case e_insertarEnArbolBinarioBusqueda:

                for (i=0; i<sizeof(vec)/sizeof(int) ;i++)
                {
                    ret = insertarEnArbolBinarioBusqueda(&arbol, &vec[i], sizeof(int),comparar);
                    retTotal = ((ret == TODO_OK) ? ret : ERROR);
                }

                printf ("\n Datos %s en el arbol", retTotal==TODO_OK ? "cargados": "cargados parcialmente (hubo rechazados)");
                break;

            case e_alturaArbol:

                printf ("\n La altura del arbol es: %d", alturaArbol(&arbol));
                break;

            case e_contarNodosHastaNivel:

                printf("\n Ingrese nivel: ");
                scanf("%d", &nivel);

                if (nivel > alturaArbol(&arbol))
                    printf ("\n El nivel es superior a la altura del arbol");
                else
                    printf("\n Cantidad de nodos es: %d", contarNodosHastaNivel(&arbol, nivel));
                break;

            case e_esArbolCompleto:

                printf ("\n El arbol %s completo.\n", esArbolCompleto(&arbol) ? "esta": "no esta");
                break;

            case e_esArbolBalanceado:

                printf ("\n El arbol %s balanceado.\n", esArbolBalanceado(&arbol) ? "esta": "no esta");
                break;

            case e_esArbolAVL:

                printf ("\n El arbol %s AVL.\n", esArbolAVL(&arbol)? "es": "no es");
                break;

            case e_buscarClaveArbol:

                printf ("\n Ingrese clave a buscar: ");
                scanf("%d", &clave);
                nodo = buscarClaveArbol(&arbol, &clave, comparar);
                mostrar((*nodo)->info, 0, ' ');
                break;

            case e_mayorNodo:

                nodo = mayorNodo(&arbol);
                mostrar((*nodo)->info, 0, ' ');
                break;

            case e_menorNodo:
                nodo = menorNodo(&arbol);
                mostrar((*nodo)->info, 0, ' ');
                break;

            case e_eliminarRaizArbol:

                ret=eliminarRaizArbol(&arbol);

                // no se si quiero informar cual era la raiz
                //printf("\n El dato %d %s del arbol.", clave, (ret==verdadero ? "fue eliminado": "no pudo eliminarse"));
                printf("\n La raiz del arbol %s.", (ret==verdadero ? "fue eliminado": "no pudo eliminarse"));
                break;

            case e_eliminarNodoPorClaveDeArbol:

                printf ("\n Ingrese clave a buscar: ");
                scanf("%d", &clave);
                ret=eliminarNodoPorClaveDeArbol(&arbol, &clave,sizeof(int),comparar);

                printf("\n El dato %d %s del arbol.", clave, (ret==verdadero ? "fue eliminado": "no pudo eliminarse"));
                break;

            case e_contarNodos:

                printf("\n Cantidad de nodos es: %d", contarNodos(&arbol));
                break;

            case e_vaciarArbol:

                printf ("\n El arbol fue vaciado. Cantidad de nodos eliminados: %d",
                        vaciarArbol(&arbol));
                break;

            case e_deArbolAVectorYANuevoArbol:

                cantNodos = contarNodos(&arbol);
                vecAux= malloc(sizeof(arbol->info) * cantNodos );

                if (!*vecAux)
                {
                    printf ("\n Error no hay suficiente memoria para bajar la informacion a un vector.");
                }
                else
                {
                    recorrerEnInOrdenYAccion(&arbol,vecAux, pasarInfoAVectorOrd);
                    printf ("\n Accion ejecutada correctamente. ");

                   // vecAux-=cantNodos; /// por si desplazo el puntero y necesito reposicionarlo
                    crearArbol(&arbolAux);
                    cargarArbolDesdeVectorOrdenado(&arbolAux, vecAux, 0 , cantNodos-1, sizeof(int), comparar);

                    printf ("\n Arbol Original: \n\n");
                    inOrdenMostrar(&arbol, mostrarConFormato,0, ' ');

                    printf ("\n\n Arbol bajado a un vector dinamico ordenado: ");
                    for (i=0; i< cantNodos ;i++, vecAux++)
                        printf (" |%d|", *vecAux);

                    printf ("\n\n Arbol Nuevo: \n\n");
                    inOrdenMostrar(&arbolAux, mostrarConFormato,0, ' ');
                }
                break;

            case e_recrearArbolDesdeVector:

                    cantNodos = contarNodos(&arbol);
                    vecAux= malloc(sizeof(arbol->info) * cantNodos );

                    if (!*vecAux)
                    {
                        printf ("\n Error no hay suficiente memoria para bajar la informacion a un vector.");
                    }
                    else
                    {
                        recorrerEnPostOrdenYAccion(&arbol,vecAux, pasarInfoAVectorOrd);
                        printf ("\n Accion ejecutada correctamente. ");

                        crearArbol(&arbolAux);

                        recrearArbolDesdeVector(&arbolAux, vecAux, 0 , cantNodos-1, sizeof(int), comparar);

                        printf ("\n Arbol Original: \n\n");
                        inOrdenMostrar(&arbol, mostrarConFormato,0, ' ');

                        printf ("\n\n Arbol bajado a un vector dinamico: ");
                        for (i=0; i< cantNodos ;i++, vecAux++)
                            printf (" |%d|", *vecAux);

                        printf ("\n\n Arbol Nuevo: \n\n");
                        inOrdenMostrar(&arbolAux, mostrarConFormato,0, ' ');
                    }
                break;
            case e_rotarArbolEnSentidoAntihorario:

                printf ("\n Arbol Original: \n\n");
                inOrdenMostrar(&arbol, mostrarConFormato,0, ' ');

                rotarArbolEnSentidoAntihorario_doble(&arbol);

                printf ("\n\n Arbol rotado en sentido antihorario: \n\n");
                inOrdenMostrar(&arbol, mostrarConFormato,0, ' ');
                break;

            case e_rotarArbolEnSentidoHorario:

                printf ("\n Arbol Original: \n\n");
                inOrdenMostrar(&arbol, mostrarConFormato,0, ' ');

                rotarArbolEnSentidoHorario_doble(&arbol);

                printf ("\n\n Arbol rotado en sentido horario: \n\n");
                inOrdenMostrar(&arbol, mostrarConFormato,0, ' ');
                break;

            case e_balancearArbol:

                printf ("\n Arbol Original: \n\n");
                inOrdenMostrar(&arbol, mostrarConFormato,0, ' ');
                cantNodos = contarNodos(&arbol);


                balancearArbol_DSW(&arbol);
                balancearArbol(&arbol,cantNodos/2);

                printf ("\n\n Arbol Balanceado: \n\n");
                inOrdenMostrar(&arbol, mostrarConFormato,0, ' ');
                break;

            case e_contarHojas:

                printf ("\n Cantidad de hojas: %d", contarHojas(&arbol));
                break;

            case e_contarSoloNoHojas:

                printf ("\n Cantidad de nodos no hojas: %d", contarSoloNoHojas(&arbol));
                break;

            case e_contarHijosPorIzquierda:

                printf("\n Cantidad de hijos por izquierda: %d", contarHijosPorIzquierda(&arbol));
                break;

            case e_contarHijosPorDerecha:

                printf("\n Cantidad de hijos por derecha: %d", contarHijosPorDerecha(&arbol));
                break;

            case e_podarArbol:

                printf("\n Ingrese nivel: ");
                scanf("%d", &nivel);
                printf ("\n Arbol podado hasta nivel, cantidad de nodos eliminados: %d", podarArbol(&arbol, nivel));
                break;

            case e_cortarHojas:

                printf ("\n Cantidad de hojas cortadas: %d", cortarHojas(&arbol));
                break;

            case e_cantidadRamas:

                printf ("\n Cantidad de ramas : %d", cantidadRamas(&arbol));
                break;

            case e_promedioValorDeLosNodos:

                printf("\n Promedio de los valores de los nodos del arbol: %.2f", promedioValorDeLosNodos(&arbol, acumularValores));
                break;

            case e_verLosNodosDeUnaAlturaDada:

                printf("\n Ingrese altura: ");
                scanf("%d", &altura);
                verLosNodosDeUnaAlturaDada(&arbol,altura, mostrar);
                break;

            case e_verLosNodosHastaUnaAlturaDada_Exc:

                printf("\n Ingrese altura: ");
                scanf("%d", &altura);
                verLosNodosHastaUnaAlturaDada_Exc(&arbol,altura, mostrar);
                break;

            case e_verLosNodosHastaUnaAlturaDada_Inc:

                printf("\n Ingrese altura: ");
                scanf("%d", &altura);
                verLosNodosHastaUnaAlturaDada_Inc(&arbol,altura, mostrar);
                break;

            case e_verNodosHastaNivel:

                printf("\n Ingrese nivel: ");
                scanf("%d", &nivel);
                verNodosHastaNivel(&arbol,nivel, mostrar);
                break;

            case e_verNodosDeUnNivel:

                printf("\n Ingrese nivel: ");
                scanf("%d", &nivel);
                verNodosDeUnNivel(&arbol,nivel, mostrar);
                break;

            case e_verNodosAPartirDeUnNivel:

                printf("\n Ingrese nivel: ");
                scanf("%d", &nivel);
                verNodosAPartirDeUnNivel(&arbol,nivel, mostrar);
                break;

            case e_profundidadArbol:

                printf ("\n La profundidad del arbol es: %d", profundidadArbol(&arbol));
                break;

            case e_grabarArbolEnArhivoTxt:

                abrirArhivo(&fp, FILE_NAME_TXT, "w");
                recorrerEnInOrdenYAccion(&arbol, fp, grabarArchivoTxt);
                fclose(fp);
                printf ("\n Archivo guardado.");
                break;

            case e_grabarArbolEnArhivoBin :

                abrirArhivo(&fp, FILE_NAME_BIN, "wb");
                recorrerEnInOrdenYAccion(&arbol, fp, grabarArchivoBin);
                fclose(fp);
                printf ("\n Archivo guardado.");
                break;

            case e_cargarArbolDesdeArchivoBin_inicio:

                abrirArhivo(&fpAux, FILE_NAME_BIN, "rb");
                vaciarArbol(&arbolAux);
                crearArbol(&arbolAux);
                cargarArbolDesdeArchivoBin_inicio(&arbolAux, &fpAux, sizeof(int), comparar);
                inOrdenMostrar(&arbolAux, mostrarConFormato,0,' ');
                fclose(fpAux);
                break;

            default:
                printf ("\n Error de sistema");
                break;
        }

        printf ("\n ");
        system("pause");
        system("cls");
        opc=menu();
    }

    printf ("\n La ejecucion se realizo %s.\n", retTotal==TODO_OK ? "exitosamente": "con errores");

    return 0;
}

int comparar(const void *d1, const void *d2)
{
    int *n1=(int *)d1;
    int *n2=(int *)d2;

    return *n1 - *n2;
}

void mostrar(const void *d, int espacios, char flecha)
{

    int *n=(int *)d;

    printf ("|%3d| \n", *n );
    //printf ("%*c|%3d|%c \n", espacios,' ',*n, flecha );
}

void mostrarConFormato(const void *d, int espacios, char flecha)
{
    int i;
    int *n=(int *)d;

    for( i=0;   i<espacios; i++)
        printf("      ");

    printf ("|%3d|%c \n", *n, flecha );
}

void pasarInfoAVectorOrd (void *info, void *vec)
{
    int *inf=(int *)info;
    static int *vector = NULL;

    if (!vector)
        vector=(int *)vec;

    *vector=*inf;
    vector++;
}

/*
unsigned leerDesdeArchivoBin(void **d, void *pf, unsigned pos, void *params)
{
    unsigned tam = *( (int *) params );
    *d= malloc(tam);

    if(!*d)
        return 0;

    fseek((FILE *)pf, pos*tam, SEEK_SET);

    return fread(*d, tam, 1, (FILE *)pf);
}
*/

void acumularValores (void *info, void *acum)
{
    int *valor=(int *)info,
        *tot = (int *)acum;

    *tot+=*valor;
}

booleano abrirArhivo(FILE **fp, const char *nom, const char *modo)
{
    *fp= fopen(nom, modo);

    if(!*fp)
        return falso;
    return verdadero;
}

void grabarArchivoTxt (void *dato, void *ptrFile)
{
    int *valor=(int *)dato;
    FILE *fp = (FILE *)ptrFile;

    fprintf(fp,"%d\n", *valor);
}

void grabarArchivoBin (void *dato, void *ptrFile)
{
    int *valor=(int *)dato;
    FILE *fp = (FILE *)ptrFile;

    fwrite(valor,1, sizeof(int), fp);
}
