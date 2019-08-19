#ifndef RESTRICCIONES_H_INCLUDED
#define RESTRICCIONES_H_INCLUDED
#include "carteles.h"
////#############################################################################
// ARCHIVO : restricciones.h
// AUTOR : Gomez Carlos
// FECHA DE CREACION :2/05/2018.
// ULTIMA ACTUALIZACION: 19/05/2018.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE : Code::Blocks - 8.02 / 10.05
// COMPILADOR : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// Funciones de validaciones
/////////////////////////////////////////////////////////////////////////////////
using namespace std;
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : validar_numero(char *cad1)
// ACCION : esta funcion valida que el usuario ingrese numeros y no letras
// PARAMETROS: char cad1: recibe el numero transformado en ascii
// DEVUELVE : bool -- > devuelde True si ingreso un valor <48 y >57
// -----------------------------------------------------------------------------

bool validar_numero(char *cad1)/* valida numero entre 0 y 9*/
{
    int x=0;

    while(cad1[x]!='\0')
    {
        if (cad1[x]<48||cad1[x]>57)
        {
            return true;/*es TRUE si no ingreso numeros*/
        }
        x++;
    }
   return false;
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :void val_ingreso(int *opc)
// ACCION : verifica que el usuario no ingrese caracteres alfabeticos
// PARAMETROS: variable booleana
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Ingreso_Numeros(int *opc)
{
    char cad1[3];
    bool a;
    do
    {
        cout << "Ingrese una opcion: ";
        sys::getline(cad1,3);/* guaro el ingreso en lava riable cad1*/
        a= validar_numero(cad1);/*guardo el valor en una variable boolean */
    }
    while(a!=false);/*ciclo que finaliza si la cadena solo contine numeros*/
    *opc=atoi(cad1);/*conversion de char a entero*/
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Cadena_numero(char *cad)
// ACCION : verifica que el usuario no ingrese caracteres alfabeticos y copia
// el contenido en la direccion de memoria de cad
// PARAMETROS: direccion de memoria de un arreglo
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Cadena_numero(char *cad)
{
    char cad1[20];
    bool a;
    do
    {
        cout << " Ingrese solo numero: ";
        sys::getline(cad1,20);
        a = validar_numero(cad1);
    }
    while(a!=false);
    strcpy(cad,cad1);
}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :todoMinus(char *cad1)
// ACCION : convierte unca cadena a minuscula
// PARAMETROS: direccion de memoria de un arreglo
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void todoMinus(char *cad1)
{

    int x=0;
    while(cad1[x]!='\0')
    {
        if (cad1[x]<97||cad1[x]>122)/* rango de las letras MAYUSCULAS*/
        {   /*el espacio en blanco provisoriamente cambia a @(arroba)*/
            cad1[x]+=32;
        }
        if(cad1[x]==64)
        {   /*convierto el '@ 'en espacio en blanco*/
            cad1[x]-=32;
        }
        x++;
    }
}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :validarLetras(char *cad1)
// ACCION : verifica que el usuario no ingrese caracteres numericos
// PARAMETROS: direccion de memoria de un arreglo
// DEVUELVE : variable booleana
// -----------------------------------------------------------------------------
bool validar_Letras(char *cad1)
{
    todoMinus(cad1);int x=0;

    while(cad1[x]!='\0')
    {

        if ((cad1[x]<97||cad1[x]>122)&&cad1[x]!=32)
        {   /*el valor ascii del espacio es 32 */
                return true;
        }
        x++;
    }
    return false;
}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Ingreso_Letras(char *cad)
// ACCION : verifica que el usuario no ingrese caracteres numericos
// PARAMETROS: direccion de memoria de un arreglo
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Ingreso_Letras(char *cad)
{
    char cad1[20];int tam;
    bool a;
    do
    {
        cout << "Ingrese solo letras: ";/*debe ser un cartel*/
        sys::getline(cad1,20);/* guardo el ingreso en la variable cad1*/
        tam=strLen(cad1);/*guardo el tamaño de la cadena*/
        a= validar_Letras(cad1);/*guardo el valor en una variable boolean */
    }
    while(a==true||tam<3);/*si a es true se repite el ciclo o la cadena es menor a 3, caso contrario termina*/
    strcpy(cad,cad1);


}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :validar_LetYNum(char *cad1)
// ACCION : verifica que el usuario no ingrese caracteres diferentes a numeros,
// letras,o el signo @
// PARAMETROS: direccion de memoria de un arreglo
// DEVUELVE : un valor booleano
// -----------------------------------------------------------------------------

bool validar_LetYNum(char *cad1)
{
    int x=0;int a=1;
    while(cad1[x]!='\0')
    {
            /*rango de numeros*/    /*rango de letras mayus*/
        if((cad1[x]<48||cad1[x]>57)&&(cad1[x]<97||cad1[x]>122))
        {
                /*rango de letras minus*/
            if((cad1[x]<65||cad1[x]>90)&&cad1[x]!=32&&a==2)

            {
                    return true;
            }
            /*si esta en el rango de las letras mayus lo pasamos a minuscula*/
            cad1[x]+=32;

            if(cad1[x]==64||cad1[x]==96||cad1[x]==78)
            {
                cad1[x]-=32;
            }
            if(cad1[x]==64)
            {
                a++;
            }
        }
        x++;
    }
    return false;

}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Ingreso_Apodo(char *cad)
// ACCION : verificar que el usuario no ingrese valores distintos a letras o numeros
// PARAMETROS: direccion de memoria de un arreglo
// DEVUELVE : valor booleano
// -----------------------------------------------------------------------------

void Ingreso_Apodo(char *cad)
{

    char cad1[20];int tam;
    bool a;
    do
    {
        cout << "Ingrese letras o numeros: ";/*aca debe ir un cartel*/
        sys::getline(cad1,20);/* guaro el ingreso en lava riable cad1*/
        tam=strLen(cad1);/*guardo el tamaño de la cadena*/
        a=validar_LetYNum(cad1);
    }
    while(a==true||tam<3);/*si a es true se repite el ciclo , caso contrario termina*/
    strcpy(cad,cad1);


}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Ingreso_Direccion(char *cad)
// ACCION : verifica que el usuario no ingrese caracteres distintos a letras o
//numeros
// PARAMETROS: direccion de memoria de un arreglo
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Ingreso_Direccion(char *cad)
{

    char cad1[20];int tam;
    bool a;
    do
    {
        cout << "Ingrese la calle y la altura: ";/*aca debe ir un cartel*/
        sys::getline(cad1,20);/* guaro el ingreso en lava riable cad1*/
        tam=strLen(cad1);/*guardo el tamaño de la cadena*/
        a=validar_LetYNum(cad1);
    }
    while(a==true||tam<3);/*si a es true se repite el ciclo , caso contrario termina*/
    strcpy(cad,cad1);


}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Eliminar(bool *val)
// ACCION :marca como eliminado un valor booleano
// PARAMETROS: direccion de memoria de un valor booleano
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Eliminar(bool *val)
{
    int op;
    cartel_Borrar_Registro();Ingreso_Numeros(&op);
    if(op==1)
    {
        *val=true;mensaje_borrado();
    }

}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void salir(bool *entrar)
// ACCION : modifica el contenido de una variable booleana
// PARAMETROS: variable booleana
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void salir(bool *entrar)
{
    sys::cls();/*borro la pantalla*/
    *entrar=false;/*cambio el valor por puntero*/
    despedida();
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void volver(bool *entrar)
// ACCION : modifica el contenido de una variable booleana
// PARAMETROS: variable booleana
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void volver(bool *ingresar)
{
    sys::cls();/*borro la pantalla*/
    *ingresar=false;/*cambio el valor por puntero*/
}



#endif // RESTRICCIONES_H_INCLUDED
