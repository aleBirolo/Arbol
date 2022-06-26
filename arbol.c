#include "arbol.h"

void crearArbol (t_arbol *pa)
{
    *pa=NULL;
}

booleano esArbolVacio (t_arbol *pa)
{
    return *pa==NULL;
}

booleano esArbolLleno (t_arbol *pa, unsigned tamDato)
{
    void *aux = malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
}

void preOrdenMostrar (t_arbol *pa, Mostrar mostrar, int espacios,char flecha)
{
    if (!*pa)
        return ;

    mostrar((*pa)->info, espacios, '-');
    preOrdenMostrar (&(*pa)->izq, mostrar, espacios +1, '-');
    preOrdenMostrar (&(*pa)->der, mostrar,espacios +1, '-');

}

void inOrdenMostrar (t_arbol *pa, Mostrar mostrar, int espacios,char flecha)
{
    if (!*pa)
        return ;

    if ((*pa)->izq != NULL && (*pa)->der != NULL)
        flecha = '<';
    else
    {
        if ((*pa)->izq != NULL)
            flecha = '/';
        else
            if((*pa)->der != NULL)
                flecha = 92;
            else
                flecha=' ';
    }

    inOrdenMostrar (&(*pa)->izq, mostrar,espacios +1, flecha);
    mostrar((*pa)->info, espacios,flecha);
    inOrdenMostrar (&(*pa)->der, mostrar,espacios +1, flecha);

}

void postOrdenMostrar (t_arbol *pa, Mostrar mostrar, int espacios, char flecha)
{
    if (!*pa)
        return ;

    postOrdenMostrar (&(*pa)->izq, mostrar, espacios +1, '-');
    postOrdenMostrar (&(*pa)->der, mostrar, espacios +1, '-');
    mostrar((*pa)->info, espacios,'-');

}

booleano insertarEnArbolBinarioBusqueda (t_arbol *pa, void *dato, unsigned tamDato, Cmp cmp)
{
    t_nodo *nue;
    int compa;


    if(*pa)
    {
        compa= cmp(dato,(*pa)->info);

        if (compa < 0)
            return insertarEnArbolBinarioBusqueda(&(*pa)->izq, dato, tamDato, cmp);

        if (compa > 0)
            return insertarEnArbolBinarioBusqueda(&(*pa)->der, dato, tamDato, cmp);

        return falso;
    }

    nue = malloc(sizeof(t_nodo));

    if (!nue)
        return falso;

    nue->info= malloc(tamDato);

    if (!nue->info)
    {
        free(nue);
        return falso;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->izq = NULL;
    nue->der = NULL;
    *pa = nue;

    return verdadero;
}

int alturaArbol (t_arbol *pa)
{
    int hi=0,
        hd=0;

    if (!*pa)
        return 0;

    hi = alturaArbol(&(*pa)->izq) + 1;
    hd = alturaArbol(&(*pa)->der) + 1;

    return hi >= hd ? hi : hd;
}

int contarNodosHastaNivel(t_arbol *pa, int nivel)
{
    if (!*pa)
        return 0;

    if (nivel==0)
        return 1;

    return  contarNodosHastaNivel(&(*pa)->izq, nivel-1) +
            contarNodosHastaNivel(&(*pa)->der, nivel-1) + 1;
}

booleano esArbolCompleto(t_arbol *pa)
{
    int h = alturaArbol(pa),
        cantNodos = contarNodos(pa);

    return pow(2,h)-1 == cantNodos;
}

booleano esArbolBalanceado(t_arbol *pa)
{
    int h = alturaArbol(pa),
        cantNodos = contarNodosHastaNivel(pa, h-2);

    return pow(2,h-1)-1 == cantNodos;
}

booleano esArbolAVL(t_arbol *pa)
{
    int hIzq=0,
        hDer=0;

    if(!*pa)
        return verdadero;

    hIzq = alturaArbol( &(*pa)->izq);
    hDer = alturaArbol( &(*pa)->der );
    if (abs( hIzq - hDer ) > 1)
        return falso;

    return  esArbolAVL(&(*pa)->izq) && esArbolAVL(&(*pa)->der);
}

int esAVL2CalculoArbol(t_arbol *pa)
{
    int hIzq,
        hDer;

    if(!*pa)
        return 0;

    hIzq = esAVL2CalculoArbol( &(*pa)->izq);
    hDer = esAVL2CalculoArbol( &(*pa)->der );

    if ( hIzq<0 || hDer<0 || abs( hIzq- hDer ) > 1)
        return -1;

    return  (hIzq >hDer ? hIzq: hDer) + 1;
}

booleano esAVL2ArbolBin( t_arbol *pa)
{
    return esAVL2CalculoArbol(pa)>=0;
}

t_nodo **buscarClaveArbol (t_arbol *pa, const void *dato, Cmp cmp)
{
    int compa;

    if (*pa)
    {
        compa=cmp(dato, (*pa)->info);

        if (compa < 0)
           return buscarClaveArbol(&(*pa)->izq, dato, cmp);
        else
            if (compa > 0)
              return  buscarClaveArbol(&(*pa)->der, dato, cmp);
            else
                return pa;
    }
    return pa;
}

t_nodo ** mayorNodo(t_arbol *pa)
{
    if(!(*pa) || !(*pa)->der)
        return pa;

    return mayorNodo( &(*pa)->der );

}

t_nodo ** menorNodo(t_arbol *pa)
{
    if(!(*pa) || !(*pa)->izq)
        return pa;

   return menorNodo( &(*pa)->izq );
}

booleano eliminarRaizArbol(t_arbol *pa)
{
    t_nodo *elim,
           **remp;

    if(!(*pa))
        return falso;

    free((*pa)->info);

    if (!(*pa)->izq && !(*pa)->der)
    {
        free((*pa));
        *pa=NULL;
        return verdadero;
    }

    remp = alturaArbol(&(*pa)->izq) > alturaArbol(&(*pa)->der) ?
                                                   mayorNodo(&(*pa)->izq) :
                                                   menorNodo(&(*pa)->der);

    elim = *remp;
    (*pa)->info = elim->info;
    (*pa)->tamInfo = elim->tamInfo;

    *remp = elim->izq ? elim->izq : elim->der;

    free(elim);

    return verdadero;
}

booleano eliminarNodoPorClaveDeArbol(t_arbol *pa, void *dato, unsigned tamDato, Cmp cmp)
{
    pa = buscarClaveArbol(pa, dato, cmp);
    if (!pa)
        return falso;
    memcpy(dato, (*pa)->info, MINIMO(tamDato,(*pa)->tamInfo));

    return eliminarRaizArbol(pa);
}

int contarNodos(t_arbol *pa)
{
    int cant=0;

    if (!*pa)
        return 0;

    cant = contarNodos(&(*pa)->izq) +
           contarNodos(&(*pa)->der) + 1;

    return cant;
}

/*
int vaciarArbol (t_arbol *pa)
{
    int cantNodos= 0;

    if (*pa)
    {
        cantNodos = vaciarArbol(&(*pa)->izq) + vaciarArbol(&(*pa)->der) + 1;
        free((*pa)->info);
        free(*pa);
    }
    *pa=NULL;
    return cantNodos;
}
*/

int vaciarArbol (t_arbol *pa)
{
    int cni,
        cnd;

    if (!*pa)
        return 0;

    cni=vaciarArbol(&(*pa)->izq);
    cnd=vaciarArbol(&(*pa)->der);
    free((*pa)->info);
    free(*pa);
    *pa=NULL;

    return cni + cnd + 1;
}

void recorrerEnPreOrdenYAccion(t_arbol *pa, void *dato, Accion accion)
{
    if(!*pa)
        return ;

    accion((*pa)->info, dato);
    recorrerEnPreOrdenYAccion(&(*pa)->izq, dato, accion);
    recorrerEnPreOrdenYAccion(&(*pa)->der, dato, accion);
}

void recorrerEnInOrdenYAccion(t_arbol *pa, void *dato, Accion accion)
{
    if(!*pa)
        return ;

    recorrerEnInOrdenYAccion(&(*pa)->izq, dato, accion);
    accion((*pa)->info, dato);
    recorrerEnInOrdenYAccion(&(*pa)->der, dato, accion);
}

void recorrerEnPostOrdenYAccion(t_arbol *pa, void *dato, Accion accion)
{
    if(!*pa)
        return ;

    recorrerEnPostOrdenYAccion(&(*pa)->izq, dato, accion);
    recorrerEnPostOrdenYAccion(&(*pa)->der, dato, accion);
    accion((*pa)->info, dato);
}

/*
booleano leerDesdeVector (void *vec, void *dato, unsigned pos, unsigned tamDato)
{
    if (!vec)
        return falso;

    memcpy(dato, vec + pos, tamDato);
    return verdadero;
}
*/

void cargarArbolDesdeVectorOrdenado (t_arbol *pa, void *dato, int li, int ls, unsigned tamDato, Cmp cmp)
{
    if (li > ls)
        return;

    int m=(li+ls)/2;

    insertarEnArbolBinarioBusqueda(pa, dato+(m*tamDato), tamDato, cmp);
    cargarArbolDesdeVectorOrdenado(pa, dato, li, m-1,tamDato, cmp);
    cargarArbolDesdeVectorOrdenado(pa, dato, m+1, ls,tamDato, cmp);
}

void recrearArbolDesdeVector (t_arbol *pa, void *dato, int li, int ls, unsigned tamDato, Cmp cmp)
{
    if (li == ls)
        return;

    insertarEnArbolBinarioBusqueda(pa, dato+(ls*tamDato), tamDato, cmp);
    recrearArbolDesdeVector(pa, dato, li, ls-1,tamDato, cmp);
}

void rotarArbolEnSentidoAntihorario(t_arbol *pa )
{
    t_nodo *remp;

    /// Si no hay raiz o nodo sobre el que rotar
    if (!*pa || !(*pa)->der )
        return ;

    /// Seleccino el nuevo nodo raiz
    remp =(*pa)->der;

    /// El hijo izq del nodo en rotacion pasa a ser hijo derecho de la antigua raiz
    //if (remp->izq)
        (*pa)->der = remp->izq;

    /// El nodo en rotacion pasa a tener como hijo izquierdo a la antigua raiz
    remp->izq = *pa;

    /// Remplazo raiz
    *pa=remp;

}

/// sin implementar
void rotarArbolEnSentidoAntihorario_doble(t_arbol *pa )
{
 ///
}

void rotarArbolEnSentidoHorario(t_arbol *pa )
{
    t_nodo *remp;

    /// Si no hay raiz o nodo sobre el que rotar
    if (!*pa ||!(*pa)->izq)
        return ;

    /// Seleccino el nuevo nodo raiz
    remp =(*pa)->izq;

    /// El hijo der del nodo en rotacion pasa a ser hijo izquierdo de la antigua raiz
   // if (remp->der)
        (*pa)->izq = remp->der;

    /// El nodo en rotacion pasa a tener como hijo derecho a la antigua raiz
    remp->der = *pa;

    /// Remplazo raiz
    *pa=remp;

}

/// sin implementar
void rotarArbolEnSentidoHorario_doble(t_arbol *pa )
{
    ///
}

void balancearArbol(t_arbol *pa, int cantRot)
{
    int hIzq,
        hDer;

    if (!*pa)
        return;

    if (esArbolAVL(pa))
        return;

    hIzq=alturaArbol(&(*pa)->izq);
    hDer=alturaArbol(&(*pa)->der);

    if (hIzq > hDer)
        while(cantRot >0)
        {
            rotarArbolEnSentidoHorario_doble(pa);
            cantRot--;
        }

    else
        while(cantRot >0)
        {
            rotarArbolEnSentidoAntihorario_doble(pa);
            cantRot--;
        }

}

/// faltan implementaciones
void balancearArbol_DSW(t_arbol *pa)
{
    if(!*pa)
        return ;

    balancearArbol_DSW(&(*pa)->izq);
    rotarArbolEnSentidoHorario(pa);
    balancearArbol_DSW(&(*pa)->der);
}

int contarHojas(const t_arbol *pa)
{
    if (!*pa)
        return 0;

    if( !(*pa)->izq && !(*pa)->der )
        return  1;

    return contarHojas(&(*pa)->izq) + contarHojas(&(*pa)->der);
}

int contarSoloNoHojas(const t_arbol *pa)
{
    if (!*pa)
        return 0;

    if( (*pa)->izq || (*pa)->der )
        return contarSoloNoHojas(&(*pa)->izq) + contarSoloNoHojas(&(*pa)->der) + 1;

    //return contarSoloNoHojas(&(*pa)->izq) + contarSoloNoHojas(&(*pa)->der);
    return 0;
}

int contarHijosPorIzquierda(const t_arbol *pa)
{
    if(!*pa)
        return 0;

    if(!(*pa)->izq)
        return 0;

    return contarHijosPorIzquierda(&(*pa)->izq) + contarHijosPorIzquierda(&(*pa)->der) + 1;
}

int contarHijosPorDerecha(const t_arbol *pa)
{
    if(!*pa)
        return 0;

    if(!(*pa)->der)
        return 0;

    return contarHijosPorDerecha(&(*pa)->izq)+contarHijosPorDerecha(&(*pa)->der)+1;
}

int podarArbol(t_arbol *pa, int nivel)
{
    if (!*pa)
        return 0;

    if( nivel == 0 )
        return vaciarArbol(pa);

    return podarArbol(&(*pa)->izq, nivel-1) + podarArbol(&(*pa)->der, nivel -1);
}

int cortarHojas(t_arbol *pa)
{
    if (!*pa)
        return 0;


    if( !(*pa)->izq && !(*pa)->der )
    {
        /*
        free((*pa)->info);
        free(*pa);
        *pa=NULL;
        return  1;
        */
        return vaciarArbol(pa);

    }

    return cortarHojas(&(*pa)->izq) + cortarHojas(&(*pa)->der);
}

int cantidadRamas( t_arbol *pa)
{
    return contarNodos(pa)-1;
}

float promedioValorDeLosNodos (t_arbol *pa, Accion accion )
{
    int cantNodos,
        acum=0;

    if (!*pa)
        return 0;

    cantNodos = contarNodos(pa);
    recorrerEnInOrdenYAccion(pa, &acum, accion);

    return ((float)acum/(float)cantNodos);
}

void verLosNodosDeUnaAlturaDada (t_arbol *pa, int altura, Mostrar mostrar)
{
    if(!*pa)
        return;

    if (altura == 1)
    {
        return mostrar((*pa)->info,0 ,' ');
    }

    verLosNodosDeUnaAlturaDada(&(*pa)->izq, altura -1 , mostrar);
    verLosNodosDeUnaAlturaDada(&(*pa)->der, altura -1 , mostrar);
}

void verLosNodosHastaUnaAlturaDada_Exc (t_arbol *pa, int altura, Mostrar mostrar)
{
    if(!*pa)
        return;

    if (altura == 1)
        return ;

    verLosNodosHastaUnaAlturaDada_Exc(&(*pa)->izq, altura -1 , mostrar);
    verLosNodosHastaUnaAlturaDada_Exc(&(*pa)->der, altura -1 , mostrar);

    return mostrar((*pa)->info,0 ,' ');
}

void verLosNodosHastaUnaAlturaDada_Inc (t_arbol *pa, int altura, Mostrar mostrar)
{
    if(!*pa)
        return;

    if (altura == 0)
        return ;

    verLosNodosHastaUnaAlturaDada_Inc(&(*pa)->izq, altura -1 , mostrar);
    verLosNodosHastaUnaAlturaDada_Inc(&(*pa)->der, altura -1 , mostrar);

    return mostrar((*pa)->info,0 ,' ');
}

void verNodosHastaNivel (t_arbol *pa, int nivel, Mostrar mostrar)
{
    if(!*pa)
        return;

    if (nivel == -1)
    {
        return ;
    }

    verNodosHastaNivel(&(*pa)->izq, nivel -1 , mostrar);
    verNodosHastaNivel(&(*pa)->der, nivel -1 , mostrar);

    return mostrar((*pa)->info,0 ,' ');
}

void verNodosDeUnNivel (t_arbol *pa, int nivel, Mostrar mostrar)
{
    if(!*pa)
        return;

    if (nivel == 0)
    {
        return mostrar((*pa)->info,0 ,' ');
    }

    verNodosDeUnNivel(&(*pa)->izq, nivel -1 , mostrar);
    verNodosDeUnNivel(&(*pa)->der, nivel -1 , mostrar);
}

void verNodosAPartirDeUnNivel (t_arbol *pa, int nivel, Mostrar mostrar)
{
    if(!*pa)
        return;

    if (nivel < 1)
         mostrar((*pa)->info,0 ,' ');

    verNodosAPartirDeUnNivel(&(*pa)->izq, nivel -1 , mostrar);
    verNodosAPartirDeUnNivel(&(*pa)->der, nivel -1 , mostrar);

    return ;
}

int profundidadArbol (t_arbol *pa)
{
    return !(*pa) ? 0 : alturaArbol(pa)-1;
}

void cargarArbolDesdeArchivoBin(t_arbol *pa, FILE **archivo, size_t tamElem, int li, int ls, Cmp cmp)
{
    if (li > ls)
        return;

    int m=(li+ls)/2;
    void *elem=malloc(tamElem);

    if (!elem)
    {
        free(elem);
        return;
    }

    fseek(*archivo, m * tamElem, SEEK_SET);
    fread(elem, tamElem, 1, *archivo);

    insertarEnArbolBinarioBusqueda(pa, elem, tamElem, cmp);

    cargarArbolDesdeArchivoBin(pa, archivo, tamElem, li, m-1, cmp);
    cargarArbolDesdeArchivoBin(pa, archivo, tamElem, m+1, ls, cmp);
}

booleano cargarArbolDesdeArchivoBin_inicio(t_arbol *pa, FILE **archivo, size_t tamElem, Cmp cmp)
{
    fseek (*archivo, 0L, SEEK_END);

    int cantReg=ftell(*archivo)/ tamElem;

    int li=0;
    int ls=cantReg-1;

    fseek (*archivo, 0L, SEEK_SET);
    cargarArbolDesdeArchivoBin(pa, archivo, tamElem, li, ls, cmp);

    return verdadero;
}

