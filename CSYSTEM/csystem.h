//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//#############################################################################
//
//  **************************************************************************
//  * El software libre no es una cuestion economica sino una cuestion etica *
//  **************************************************************************
//
// Avis Software es marca registrada.
//
// Este programa es software libre; puede redistribuirlo o modificarlo bajo los
// terminos de la Licencia Publica General de GNU tal como se publica por la
// Free Software Foundation; ya sea la version 3 de la Licencia, o (a su
// eleccion) cualquier version posterior.
//
// Este programa se distribuye con la esperanza de que le sea util, pero SIN
// NINGUNA GARANTIA; sin incluso la garantia implicita de MERCANTILIDAD o
// IDONEIDAD PARA UN PROPOSITO PARTICULAR.
//
// Vea la Licencia Publica General GNU para mas detalles.
//
// Deberia haber recibido una copia de la Licencia Publica General de GNU
// junto con este programa, si no es asi, escriba a la Free Software Foundation,
// Inc, 59 Temple Place - Suite 330, Boston, MA 02111-1307, EE.UU.
//
//#############################################################################
// ARCHIVO             : csystem.h
// AUTOR               : Ruben Alberto Calabuig.
// COLABORADORES       : Sebastian Florin y Fernando Calabuig
// VERSION             : 6.00 estable.
// FECHA DE CREACION   : 08/11/2011.
// ULTIMA ACTUALIZACION: 24/04/2014.
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows XP / Windows 7
// IDE                 : Code::Blocks - 8.02 / 10.05 / 12.11 / 13.12
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DEDICATORIA: A mi Padre Amadeo Calabuig (28/12/1924 - 10/03/1995).
//=============================================================================
// DESCRIPCION:
//             Este archivo incluye la definicion de la libreria csystem
//
//             Las funciones csystem permiten compatibilidad entre Linux y
//             Windows en algunas funciones basicas del modo consola como:
//             cls() getch() , pause() y msleep(), y agrega otras como getch(),
//             randomize() y random(), generando una interfaz que permita
//             realizar codigos verdaderamente portables.
//
//-------------------------------------------------------------------------------
// ARCHIVO DE CABECERA: #include csystem.h
//
// FUNCIONES DEFINIDAS:
//==============================================================================|
//     NOMBRE     |  TIPO  |                    ACCION                          |
//================+========+====================================================|
// cls()          |  void  | Limpia la pantalla en modo consola.                |
//----------------+--------+----------------------------------------------------|
// getch()        |  char  | Lee un caracter por teclado.                       |
//----------------+--------+----------------------------------------------------|
// msleep(s)      |  void  | Detiene el proceso durante una cantidad dada de    |
//                |        | segundos.                                          |
//----------------+--------+----------------------------------------------------|
// pause()        |  void  | Realiza una pausa hasta que se presione la tecla   |
//                |        | ENTER.                                             |
//----------------+--------+----------------------------------------------------|
// randomize()    |  void  | Inicializa la secuencia de numeros aleatorios.     |
//----------------+--------+----------------------------------------------------|
// random(n)      |  int   | Devuelve un numero aleatorio entero entre 0 y n-1. |
//================+========+====================================================|
//
//-------------------------------------------------------------------------------
// MODIFICACIONES DE LA VERSION 5.03 estable (06/06/2012)
// AUTOR DE LA MODIFICACION: Sebastian Florin.//
// * Se ha incluido la libreria "ctime" para un correcto funcionamiento de las
//   funciones randomize() y random().
//
//-------------------------------------------------------------------------------
// MODIFICACIONES DE LA VERSION 6.0 estable (23/04/2014)
// AUTORES: Fernando Calabuig y Ruben Calabuig.
//
// * Se elimino la funcion gotoxy() por depender demasiado del sistema operativo,
//   e impedir la portabilidad.
//
// * Se incluyeron las librerias windows.h (para Windows) y unistd.h (para Linux)
//   con el fin desarrolar la funcion multiplataforma sleep().
//
// * Se agrego la funcion multiplataforma msleep().
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef CSYSTEM_H
#define CSYSTEM_H

//*****************************************************************************
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria que incluye los flujos de entrada y salida para
                    // el lenguaje C++.
                    //
                    // En esta libreria se desarrollan las definiciones de las
                    // clases "cin" y "cout".

#include <cstdlib>  // Libreria que incluye funciones relacionadas con el
                    // sistema estandar para el lenguaje C++.
                    //
                    // En esta libreria se desarrolla, entre otras, a las
                    // funciones "system()" y "time()", utilizadas para el
                    // desarrollo de algunas de las funciones de este espacio
                    // de nombres, tales como: cls(), randomize() y random().

#include <cstdio>   // Libreria que incluye funciones relacionadas con el
                    // sistema de entrada/salida estandar par el lenguaje C++.
                    //
                    // En esta libreria se desarrolla, entre otras, la funcion
                    // "printf()", utilizada en la funcion gotoxy().

#include <ctime>   // Libreria que incluye funciones relacionadas con el
                   // tiempo.


//*****************************************************************************
//                             INCLUSIONES PARA WINDOWS
//=============================================================================
#ifdef _WIN32
  #include <windows.h>  // Libreria que incluye la funcion sleep para Windows
#endif // _WIN32

//*****************************************************************************
//                             INCLUSIONES PARA LINUX
//=============================================================================
#ifdef _LINUX
  #include <unistd.h>  // Libreria que incluye la funcion sleep para Linux
#endif


//*****************************************************************************
//               ESPACIO DE NOMBRES DE LA LIBRERIA sys csystem.h
//=============================================================================
namespace sys
{
#ifdef _WIN32
//***************************************************************************
//                        FUNCIONES PARA WINDOWS
//===========================================================================
// FUNCION   : void cls().
// ACCION    : Borra la pantalla en modo consola.
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void cls()
{
  system("cls");
}

//---------------------------------------------------------------------------
// FUNCION   : void msleep(int s).
// ACCION    : Detiene la ejecucion durante una cantidad dada de segundos.
// PARAMETROS: int s --> cantidad de segundos.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void msleep(int s)
{
  Sleep(s * 1000);
}

#endif // _WIN32 - Fin de version para Windows.

#ifdef _LINUX
//***************************************************************************
//                        FUNCIONES PARA LINUX
//===========================================================================
// FUNCION   : void cls().
// ACCION    : Borra la pantalla en modo consola.
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void cls()
{
  system("clear");
}

//---------------------------------------------------------------------------
// FUNCION   : void msleep(int s).
// ACCION    : Detiene la ejecucion durante una cantidad dada de segundos.
// PARAMETROS: int s --> cantidad de segundos.
// DEVUELVE  : NADA
//---------------------------------------------------------------------------
void msleep(int s)
{
  sleep(s);
}

#endif // _LINUX - Fin de version para Linux.

//***************************************************************************
//                        FUNCIONES GENERALES
//===========================================================================
// FUNCION   : char getch().
// ACCION    : Lee un caracter por teclado.
// PARAMETROS: NADA.
// DEVUELVE  : char --> el caracter leido.
//---------------------------------------------------------------------------
char getch()
{
  const char LF=10; // LINEFID --> ASCII del caracter de salto de linea.
  char aux;

  aux = std::cin.get();
  if(aux==LF) // Si quedo un LF en el buffer, vuelve a leer.
  {
      aux=std::cin.get();
  }

  return aux;
}

//===========================================================================
// FUNCION   : void pause().
// ACCION    : Realiza una pausa hasta que se presione ENTER.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
void pause()
{
const char LF=10; // LINEFID --> ASCII del caracter de salto de linea.
char aux;
aux = std::cin.get();
if(aux==LF) // Si quedo un LF en el buffer, vuelve a leer.
{
  std::cin.get();
}
}

//===========================================================================
// FUNCION   : void randomize()
// ACCION    : Inicializa la secuencia de numeros aleatorios.
// PARAMETROInicializa la secuencia de numeros aleatorios.S: NADA.
// DEVUELVE  : NADA.
//...........................................................................
// NOTA: Esta funcion utiliza la funcion time() y debe ser utilizada por
//       unica vez al comenzar la funcion main() del programa.
//---------------------------------------------------------------------------
void randomize()
{
time_t t;
srand((unsigned) time(&t));
}

//===========================================================================
// FUNCION   : int random(int n)
// ACCION    : Devuelve un numero aleatorio entero entre 0 y n-1.
// PARAMETROS: int n -> numero tope del rango aleatorio.
// DEVUELVE  : int n -> numero aleatorio generado entre 0 y n-1.
//----------------------------------------------------------------------
int random(int n)
{
return rand() % n;
}

//===========================================================================
// FUNCION   : void getLine(char *cadena,int cantidad)
// ACCION    : Guarda el texto ingresado por el usuario
// PARAMETROS: char *cadena: cadena donde se guarda el texto
//             int cantidad: cantidad de caracteres a guardar
// DEVUELVE  : NADA.
//----------------------------------------------------------------------
void getline(char *cadena,int cantidad)
{
    int contador =0;
    char caracter ='\0';
    while(caracter!=10)
    {
        caracter = std::cin.get();
        if(contador != cantidad && caracter!=10)
        {
            cadena[contador] = caracter;
            contador++;
        }
    }
    cadena[contador]='\0';
}
} // Fin namespace sys

#endif // CSYSTEM_H
//### FIN DE ARCHIVO ##########################################################
