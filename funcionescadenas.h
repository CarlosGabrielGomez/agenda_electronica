#ifndef FUNCIONESCADENAS_H_INCLUDED
#define FUNCIONESCADENAS_H_INCLUDED
////#############################################################################
// ARCHIVO : funcionescadenas.h
// AUTOR : Gomez Carlos
// FECHA DE CREACION :20/05/2017.
// ULTIMA ACTUALIZACION: 20/05/2017.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE : Code::Blocks - 8.02 / 10.05
// COMPILADOR : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// Funciones de cadenas
/////////////////////////////////////////////////////////////////////////////////

using namespace std;

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : strLen (cadena de caracteres)
// ACCION :  cuenta la cantidad de caracteres que integran una cadena.
// PARAMETROS: char cad1
// DEVUELVE : variable de tipo ENTERO.
//-----------------------------------------------------------------------------
int strLen(char *cad1)
{
    //int tam=0;//variable utilizada como indice;
    int x=0;
    while(cad1[x]!='\0')
    {

        x++;
    }
    return x;
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : strCpy(cadena fuente, cadena destino)
// ACCION : Acción: copia una cadena en otra
// PARAMETROS: char cadena destino,char  cadena fuente
// DEVUELVE : nada
//-----------------------------------------------------------------------------
void strCpy(char *fuente, char *destino)
{
    int x=0;//variable utilizada como indice
    while(fuente[x]!='\0')
    {

        destino[x]=fuente[x];
        x++;

    }
    destino[x]='\0';
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : strCat(2 cadenas de caracteres)
// ACCION : concatena dos cadenas dejando el resultado en la cadena inicial
// PARAMETROS: char cadena inicial, char cadena final.
// DEVUELVE : Nada
//-----------------------------------------------------------------------------
void strCat(char *cad1, char *cad2)//cad1 es fuente,cad2 es destino
{
    int x;//sirve como indice de la primera cadena;
    int y; //indice de la segunda cadena;


    x=strLen(cad1);//saco la cant. de lugares antes del \0;
    //pero tambien me da la posicion del \0
    //me ubico en el '\0',o final de la cadena;


    y=strLen(cad2);//saco la cant. de lugares antes del \0;
    //pero tambien me da la posicion del \0
    //me ubico en el '\0',o final de la cadena;

     for(int a=0;a<y;a++)
     {
        cad1[x]=cad2[a];//z tiene la posicion del '\0'
        x++;
     }
     cad1[x]='\0';/**/

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : strCmp (2 cadenas de caracteres)
// ACCION : : compara dos cadenas.
// PARAMETROS:  char  cadena 1,  char cadena 2.
// DEVUELVE : variable de tipo ENTERO.
//-----------------------------------------------------------------------------
int strCmp(char *cad1, char *cad2)
{
    int tam1,tam2;
    tam1=strLen(cad1);//saco la cant. de lugares antes del \0;
    tam2=strLen(cad2);//saco la cant. de lugares antes del \0;
    int x=0;/* indice para las dos cadenas*/
    int bandera=0;/* */
    int valor;
    while(cad1[x]!='\0'&&cad2[x]!='\0')
    {

        if((cad1[x]-cad2[x])>0)
        {
           valor=1;
            bandera++;

        }
        if((cad1[x]-cad2[x])<0)
        {
            valor=-1;
            bandera++;
        }
       x++;
    }
    if (bandera==0)
    {
        if(tam1>tam2)
        {
            valor=1;
        }
        else if(tam1<tam2)
        {
            valor=-1;
        }
        else
        {
            valor=0;
        }
    }
    return valor;
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : strFind(2 cadenas de caracteres)
// ACCION :  busca un carácter dentro de una cadena.
// PARAMETROS: char cadena, char carácter
// DEVUELVE : La posición donde se produce la primera ocurrencia
//-----------------------------------------------------------------------------
int strFind(char *cad1,char *letra)
{
   int pos,tam,cont=0;
   int y=0;
   tam=strLen(cad1);//guardo el tamaño dela cadena;
   for(int x=0;x<tam;x++)
   {

       if(cad1[x]==letra[y])
       {
           pos=x;
           cont++;
       }
   }
   if(cont!=0)
   {
       return pos+1;
   }
   else
   {
       return -1;
   }
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :strCnt(char cadena, char letra)
// ACCION :cuenta cuántas de veces que aparece un carácter dentro de una cadena
// PARAMETROS:char cadena, char carácter.
// DEVUELVE :la cantidad de veces que aparece el carácter en la cadena
//-----------------------------------------------------------------------------

int strCnt(char *cad1,char *letra)
{
    int tam,cont=0;
    int y=0;
   tam=strLen(cad1);//guardo el tamaño de la cadena;
   for(int x=0;x<tam;x++)
   {

       if(cad1[x]==letra[y])
       {
           cont++;
       }
   }
   return cont;
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :strInv(cadena de caracteres)
// ACCION :invierte los caracteres de una cadena.
// PARAMETROS:char cadena
// DEVUELVE :Nada
//-----------------------------------------------------------------------------

void strInv(char *cad1)
{
    int tam;//tamaño de la cadena
    int aux;//variable auxiliar que me permite guardar valores;
    tam=strLen(cad1);
    /*esta forma funciona con cadenas pares*/
   for(int x=0;x<=tam/2;x++)/* el ciclo for va desde cero hasta la mitad*/
   {
       aux=cad1[x];
       cad1[x]=cad1[tam-1];
       cad1[tam-1]=aux;
       tam--;
   }
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :strRpl  (2 cadenas de caracteres , un numero entero)
// ACCION : reemplaza el carácter de una posición dada de una cadena por otro.
// PARAMETROS: char cadena, char carácter,  int posición
// DEVUELVE :Nada
//-----------------------------------------------------------------------------
void strRpl(char *cad1,char *letra,int Posicion)
{
  int tam;
  int y=0;
  tam=strLen(cad1);/**/
  for(int x=0;x<tam;x++)
  {

      if(x+1==Posicion)/**/
      {
          cad1[x]=letra[y];/**/
      }
  }
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : strTrunc (char cadena, int posicion)
// ACCION :trunca una cadena en una posición dada
// PARAMETROS:char cadena,int  posición.
// DEVUELVE :Nada
//-----------------------------------------------------------------------------
void strTrunc(char *cad1,int Posicion)
{

    int tam;/**/
    tam=strLen(cad1);/**/
    for(int x=0; x<tam; x++)/**/
    {

        if(x+1==Posicion)/**/
        {
            cad1[x]='\0';/**/
        }
    }

}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :strSub(2 cadenas de caracteres)
// ACCION :busca una subcadena dentro de una cadena.
// PARAMETROS:char cadena,  char subcadena.
// DEVUELVE :La posición inicial de la subcadena
//-----------------------------------------------------------------------------
int strSub(char *cad1,char *cad2)
{
    int tam1;///**/
    int tam2; ///**/
    tam1=strLen(cad1);//tamaño de la primera cadena;
    tam2=strLen(cad2);//tamaño de la segunda cadena;

    int bandera=0;//variable bandera;
    int y=0;/*variable entera que sirve como indice
    para la segunda cadena;*/
    int pos;/*variable entera para guardar la poscicion;*/
    int contador=0;/*variable utilizada como contador*/
    for(int x=0; x<tam1; x++)
    {
        if (y<tam2)/*"<" y no "<="*/
        {         /*XQ estaria dando una vuelta mas*/
            if(cad1[x]==cad2[y])/**/
        {
            if(bandera==0)/* en la primera coincidencia */
                {
                    bandera++;/* incremento la bandera una vez*/
                    y++;/* incremento el indice de la segunda cadena*/
                    pos=x;/*guaro la posicion de la segunda cadena*/
                    contador++;/* incremento una vez el contador*/
                }
                else/**/
                {
                    y++;/**/
                    contador++;/**/
                }
            }
            else/* esta parte sirve para reinicar todo */
            {
                bandera=0;/*reinicio la bandera*/
                y=0;/*reinicio el indice*/
                contador=0;/*reinicio el contador de ocincidencias*/
            }
        }

    }

    if(contador==tam2)/**/
    {
        return pos+1;/*  devuelvo la posicion +1*/
    }                /* ya que el vector va de 0 a TAM*/
    else
    {
        return -1;/*no se encontró la subcadena*/
    }
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :strToUpper(cadena de caracteres)
// ACCION :convierte una cadena a mayúsculas
// PARAMETROS:char cadena
// DEVUELVE :Nada
//-----------------------------------------------------------------------------
void strToUpper(char *cad1)
{
    int a=0;/*indice de la cadena*/
    while (cad1[a]!='\0')
    {
        cad1[a]-=32;/**/
        a++;/**/
    }
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :strToLowe
// ACCION :convierte una cadena a minúsculas
// PARAMETROS:char cadena
// DEVUELVE :nada
//-----------------------------------------------------------------------------

void strToLower(char *cad1)
{

    int a=0;/**/
    while (cad1[a]!='\0')
    {
        cad1[a]+=32;/**/
        a++;/**/
    }
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :strToInt
// ACCION :convierte una cadena de caracteres a un número entero.
// PARAMETROS: char cadena
// DEVUELVE : numero entero
//-----------------------------------------------------------------------------
int strToInt(char *cad1)
{
    int tam1;//
    int acu=0;/* variable acumuladora*/
    tam1=strLen(cad1);//tamaño de la primera cadena;
    int unidad=1;/*variable entera que se incrementa en 1,10,100,etc;*/
    for(int x=tam1-1;x>=0;x--)/* el ciclo va de atras para adeante*/
    {
        acu+=(cad1[x]-=48)*unidad;/* restamos 48 y lo multiplicamos por unidad */
        unidad*=10;/* unidad se incrementa X 10 en cada ciclo*/
    }
    return acu;/*devuelvo la suma de todos los ciclos*/
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : intToStr
// ACCION : convierte un número entero a cadena.
// PARAMETROS: número, cadena
// DEVUELVE : Nada
//-----------------------------------------------------------------------------

void intToStr(char *cad1,int numero)
{
  int y=0;/* variable entera que sirve como indice*/
  int resto;/*variable entera donde almaceno el resto una division*/


    if(numero==0)/*si ingreso el  '0' no iniciamos ninguna accion*/
    {
        cad1[y]=numero+48;/*solo lo convertimos en numero entero  */
        y++;/* incrementamos una psocion*/
        cad1[y]='\0';/*e insertamos el fin de cadena*/
    }
    else
    {
        while(numero!=0)/*si el caracter es distinot de '0'*/
        {
            resto=numero%10;/*sacamos el resto del numero /en 10*/
            cad1[y]=resto+48;/* guardamos el en la cadena*/
            numero=numero/10;/*divimos el numero para movernos de posicion*/
            y++;/*incrementamos el indice*/
        }
        cad1[y]='\0';/* ingreso el \0 para marcar el
                     final de la cadena*/
        strInv(cad1);/*invertimos la cadena*/

    }
}




#endif // FUNCIONESCADENAS_H_INCLUDED
