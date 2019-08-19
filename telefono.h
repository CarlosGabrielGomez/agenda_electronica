#ifndef TELEFONO_H_INCLUDED
#define TELEFONO_H_INCLUDED
#include "carteles.h"
////#############################################################################
// ARCHIVO : telefono.h
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
// Funciones de struct telefono
/////////////////////////////////////////////////////////////////////////////////

struct Telefono
{
    char descripcion [20],numero [20];
    bool borrado;
    int id_contacto;int id_Telefono;
};

using namespace std;
const char TELEFONO[]="Telefonos.dat";

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Duplicado_Telefono(Telefono *reg)
// ACCION : verifica que un struct telefono no se repita
// PARAMETROS: direccion de memoria de un struct telefono
// DEVUELVE :valor booleano
//-----------------------------------------------------------------------------

bool Duplicado_Telefono(Telefono *reg)
{

    FILE *archivo;Telefono aux;
    archivo=fopen(TELEFONO,"rb");
    if(archivo==NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof(Telefono),1,archivo))
    {

        if(strcmp(aux.descripcion,(*reg).descripcion)==0&&
           strcmp(aux.numero,(*reg).numero)==0)
        {
            return true;
        }
    }
    return false;

}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Total_Telefono()
// ACCION : devuelve el total de registros
// PARAMETROS: ninguno
// DEVUELVE :valor entero
//-----------------------------------------------------------------------------


int Total_Telefono()
{

    FILE *archivo;int tam;
    archivo=fopen(TELEFONO,"rb");
    if(archivo==NULL)
    {
        return -1;
    }
    fseek(archivo,0,2);
    tam=ftell(archivo)/sizeof(Telefono);
    fclose(archivo);
    return tam;


}


//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Leer_Telefono(int pos, Telefono *reg)
// ACCION : esta funcion lee de un archivo la informacion de un struct telefono
// PARAMETROS: una valor entero, la direccion de memoria de un struct telefono
// DEVUELVE :nada
//-----------------------------------------------------------------------------

void Leer_Telefono(int pos, Telefono *reg)
{

    FILE *archivo;
    archivo=fopen(TELEFONO,"rb");
    if(archivo==NULL)
    {
        Error_Archivo();return;
    }
    fseek(archivo,sizeof(Telefono)*pos,0);
    fread(reg,sizeof(Telefono),1,archivo);
    fclose(archivo);


}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :  Mostrar_Telefono(Telefono *reg, bool val)
// ACCION : muestra por pantalla un struct telefono
// PARAMETROS: direccion de memoria de un struct telefono, un valor booleano
// DEVUELVE :valor booleano
//-----------------------------------------------------------------------------

void Mostrar_Telefono(Telefono *reg, bool val)
{

    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"| TIPO DE TELEFONO: "<< reg->descripcion<<"\t"<<"NUMERO: "<<reg->numero<<endl;

    if(val==true)
    {
        cout<<"\t"<<"| ID Contacto: "<<reg->id_contacto<<"\t"<<"ID Telefono: "<<reg->id_Telefono<<endl;

    }

}


//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Tipos_Telefono(Telefono *reg)
// ACCION : carga una cadena de caracteres en un struct telefono
// PARAMETROS: direccion de memoria de un struct telefono
// DEVUELVE :nada
//-----------------------------------------------------------------------------

void Tipos_Telefono(Telefono *reg)
{
    int op;
    char cadena[20];
    bool ingresar=true;
    while(ingresar)
    {
        Descripcion_Telefono();
        Ingreso_Numeros(&op);
        switch(op)
        {
        case 1:
        {
            /* el caso 1 tipo personal*/
            strcpy(reg->descripcion,"personal");
            volver(&ingresar);
        }
        break;
        case 2:
        {
            /* el caso 2  tipo personañ*/
            strcpy(reg->descripcion,"laboral");
            volver(&ingresar);
        }
        break;
        case 3:
        {
            /* el caso 3 seria otro */
           Cartel_nueva_tipo_telefono();
            Ingreso_Letras(cadena);
            strcpy(reg->descripcion,cadena);
            volver(&ingresar);
        }
        break;
        case 0:
            {
                volver(&ingresar);
            }break;
        default:
        {
            incorrecto();
        }
        break;

        }
    }




}



//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Duplicado_Telefono(Telefono *reg)
// ACCION : permite cargar un struct telefono
// PARAMETROS: un valor entero
// DEVUELVE :struct telefono
//-----------------------------------------------------------------------------

Telefono Cargar_Telefono(int id)
{
    Telefono reg;/**/char aux [20];/**/

     do
    {

        Completar_Campos();/*saca por pantalla el cartel de completar */Tipos_Telefono(&reg);/*carga el tipo de telefono*/
        cout<<"\t"<<" INGRESE EL NUMERO DE TELEFONO: "<<endl;/*esto tiene que ser un cartel */
        Cadena_numero(aux);strcpy(reg.numero,aux);reg.id_contacto=id;


    }
    while(Duplicado_Telefono(&reg));

    return reg;

}




//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Guardar_Telefono(Telefono reg)
// ACCION : guarda en un archivo un struct telefono
// PARAMETROS: un struct telefono
// DEVUELVE :nada
//-----------------------------------------------------------------------------



void Guardar_Telefono(Telefono reg)
{

    FILE *archivo;
    archivo=fopen(TELEFONO,"ab");
    if(archivo==NULL)
    {
        Error_Archivo();return;
    }
    fwrite(&reg,sizeof(Telefono),1,archivo);
    fclose(archivo);
}



//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : GenerarID_Telefono()
// ACCION : guarda el valor id de un struct telefono
// PARAMETROS: ninguno
// DEVUELVE :ninguno
//-----------------------------------------------------------------------------

void GenerarID_Telefono()
{
    FILE *archivo;
    Telefono reg;
    int tam=Total_Telefono();
    archivo=fopen(TELEFONO,"rb+");
    if(archivo==NULL)
    {
        //Error_Archivo();/**/
        return;
    }

    while(fread(&reg,sizeof(Telefono),1,archivo)) {}
    fseek(archivo,-sizeof(Telefono),1);
    reg.id_Telefono=tam;
    fwrite(&reg,sizeof(Telefono),1,archivo);
    fclose(archivo);

}



//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Posicion_Telefono(int id)
// ACCION : devuelve la poscion de un struct telefono
// PARAMETROS: un valor entero
// DEVUELVE :un valor entero
//-----------------------------------------------------------------------------

int Posicion_Telefono(int id)
{
    int tam;tam=Total_Telefono();Telefono reg;

    for(int x=0;x<tam;x++)
    {
        Leer_Telefono(x,&reg);
        if(reg.id_Telefono==id)
        {
            return x;
        }

    }
    return -1;

}



//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :  Listar_Telefono(int id)
// ACCION : saca por pantalla los telefonos de un contacto
// PARAMETROS: un valor entero
// DEVUELVE :nada
//-----------------------------------------------------------------------------
void Listar_Telefono(int id)
{
    int tam;tam=Total_Telefono();Telefono reg;

    for(int x=0;x<tam;x++)
    {

        Leer_Telefono(x,&reg);
        if(reg.id_contacto==id&&reg.borrado==false)
        {
            Mostrar_Telefono(&reg,false);
        }

    }

}


//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Coincidencias_XID_Telefono(int id)
// ACCION : devuelve las cantidad de telfonos  de un struct contacto
// PARAMETROS: un valor entero
// DEVUELVE :un valor entero
//-----------------------------------------------------------------------------

/*esta funcIion retorna la cantidad de telefonos del contacto*/
int Coincidencias_XID_Telefono(int id)
{
    int cant=0;

    int tam;tam=Total_Telefono();Telefono reg;

    for(int x=0;x<tam;x++)
    {

        Leer_Telefono(x,&reg);
        if(reg.id_contacto==id&&reg.borrado==false)
        {
            cant++;
        }

    }

        return cant;
}


//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Vec_CargarID_Telefono(int *vec,int id)
// ACCION : carga en un vector de enteros los id de los struct telefonos
// PARAMETROS: la direccion de un vector de enteros, un valor entero
// DEVUELVE :nada
//-----------------------------------------------------------------------------

void Vec_CargarID_Telefono(int *vec,int id)
{

    int tam;tam=Total_Telefono();Telefono reg;

    for(int x=0; x<tam; x++)
    {
        Leer_Telefono(x,&reg);
        if(reg.id_contacto==id)
        {
            Mostrar_Telefono(&reg,true);/*mostramos el contacto con sus correspondientes ID*/
            *vec=reg.id_Telefono;vec++;/*guardamos en el vector los valores id de los contactos*/
            /*el puntero vec se desplazará dependideno la cantidad de coincidencias*/
        }

    }


}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Existe_ID_Telefono(int val,int *vec, int tam)
// ACCION : verifica que un struct telefono no se repita
// PARAMETROS: direccion de memoria de un struct telefono
// DEVUELVE :valor booleano
//-----------------------------------------------------------------------------

bool Existe_ID_Telefono(int val,int *vec, int tam)
{
    for(int x=0;x<tam;x++)
    {
        if(*(vec+x)==val)
        {
            return true;
        }
    }
    return false;



}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Buscar_XID_Telefono(int val)
// ACCION : busca la posicion de un struct telefono
// PARAMETROS: un valor entero
// DEVUELVE :un valor entero
//-----------------------------------------------------------------------------
int Buscar_XID_Telefono(int val)
{

    Telefono reg;
    int tam=Total_Telefono();
    for(int x=0;x<tam;x++)
    {
        Leer_Telefono(x,&reg);
        if(reg.id_Telefono==val)
        {
            return x ;
        }
    }
    return -1;



}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Seleccion_Telefono(int id)
// ACCION : devuelve la posicion de un struct telefono
// PARAMETROS: un valor entero
// DEVUELVE :un valor entero
//-----------------------------------------------------------------------------

int Seleccion_Telefono(int id)
{

    int id_opc,cant;
    int *vec;/*puntero vec para asignar memoria dinamica*/
    bool repetir;/*determina la continuidad o fin del ciclo do while*/
    int pos;/*guardamos la posicion del registro a modificar*/
    cant=Coincidencias_XID_Telefono(id);

    vec=(int *)malloc(sizeof(int)*cant);/*vector que almacena los id de los registros con coincidencias*/
    if(vec==NULL)/*verificamos la asignacion de memoria */
    {
        cout<<"error de memoria";
        return -1;/*retornamos a la anterior funcion en caso negativo*/
    }

    /*cargo el vector con los ID  de los telefonos*/
   Vec_CargarID_Telefono(vec,id);

    do
    {
         Cartel_id_Telefono();
         Ingreso_Numeros(&id_opc);
         repetir=Existe_ID_Telefono(id_opc,vec,cant);


    }
    while(repetir==false);/*si el id ingresado y el id */
    pos=Buscar_XID_Telefono(id_opc);


    return pos;
    free(vec);/*libero la memoria asignada*/





}



//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Reescribir_Telefono(Telefono *reg, int pos)
// ACCION : modifica un struct telefono
// PARAMETROS: direccion de memoria de un struct telefono, un valor entero
// DEVUELVE :nada
//-----------------------------------------------------------------------------
void Reescribir_Telefono(Telefono *reg, int pos)
{


    FILE *archivo;
    archivo=fopen(TELEFONO,"rb+");
    if(archivo==NULL)
    {
        Error_Archivo();
        exit(1);
    }
    fseek(archivo,sizeof(Telefono)*pos,0);
    fwrite(reg,sizeof(Telefono),1,archivo);
    fclose(archivo);
    Mostrar_Telefono(reg,false);
    system("pause");


}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Ayuda()
// ACCION : inicia el menu ayuda
// PARAMETROS:nada
// DEVUELVE :nada
//-----------------------------------------------------------------------------
void Ayuda()
{

     int op;bool entrar=true;
        while(entrar)
    {
        Menu_ayuda();
        Ingreso_Numeros(&op);
        switch(op)
        {
        case 1:
        {
           explicaion_a();
        }
        break;
        case 2:
        {
           explicaion_b();
        }
        break;
        case 3:
        {
           explicaion_c();
        }
        break;
        case 0:
        {
            volver(&entrar);
        }
        break;
        default:
        {
            incorrecto();
        }
        break;
        }


}





















}





#endif // TELEFONO_H_INCLUDED
