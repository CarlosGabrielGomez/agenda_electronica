#ifndef CONTACTO_H_INCLUDED
#define CONTACTO_H_INCLUDED
#include "funcionescadenas.h"/**/
#include "carteles.h"/**/
#include "restricciones.h"/**/
#include "telefono.h"
////#############################################################################
// ARCHIVO : contacto.h
// AUTOR : Gomez Carlos
// FECHA DE CREACION :2/5/2018.
// ULTIMA ACTUALIZACION: 19/05/2018.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE : Code::Blocks - 8.02 / 10.05
// COMPILADOR : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// funciones con struct contacto
/////////////////////////////////////////////////////////////////////////////////
struct Contacto
{
    char nombre[20],apellido[20],apodo[20],domicilio[20],email[20];
    bool eliminado;
    int id;
};

using namespace std;
const char CONTACTO[]="Contactos.dat";
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Duplicado_Contacto(Contacto *reg)
// ACCION : esta funcion verifica que el contacto cargado no esté repetido
// PARAMETROS:direccion de memoria de una struct contacto
// DEVUELVE : valor booleano.
// -----------------------------------------------------------------------------

bool Duplicado_Contacto(Contacto *reg)
{



    FILE *archivo;
    Contacto aux;
    archivo=fopen(CONTACTO,"rb");
    if(archivo==NULL)
    {
        /*el caso NULL indica que es el primer contacto que se va a guardar*/
        return false;
    }
    while(fread(&aux,sizeof(Contacto),1,archivo))
    {
        /*comparamos todos los campos del registro*/
        if(strcmp(aux.nombre,reg->nombre)==0 && strcmp(aux.apellido,reg->apellido)==0 &&
                strcmp(aux.apodo,reg->apodo)==0 && strcmp(aux.domicilio,reg->domicilio)==0 &&
                strcmp(aux.email,reg->email)==0)
        {
            Yaexiste_Contacto();
            system("pause");
            return true;
        }

    }

    fclose(archivo);
    return false;/* si el existe el archivo y no esta repetido devolvemos false*/


}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Contacto Cargar_Contacto()
// ACCION : esta funcion carga un  contacto
// PARAMETROS:ninguno
// DEVUELVE : struct contacto
// -----------------------------------------------------------------------------


Contacto Cargar_Contacto()
{
    sys::cls();
    Contacto reg;char aux [20];/**/

    do
    {

        Completar_Campos();/*saca por pantalla el cartel de completar */
        cout<<"\t"<<" INGRESE EL NOMBRE:"<<endl;
        Ingreso_Letras(aux);
        strcpy(reg.nombre,aux);/*validamos el ingreso de letras y despues guardamos el contenido*/
        cout<<"\t"<<" INGRESE EL APELLIDO:"<<endl;/*esto tiene que ser un cartel */
        Ingreso_Letras(aux);
        strcpy(reg.apellido,aux);/*validamos el ingreso de letras y despues guardamos el contenido*/
        cout<<"\t"<<" INGRESE EL APODO O NICK:"<<endl;/*esto tiene que ser un cartel */
        Ingreso_Apodo(aux);
        strcpy(reg.apodo,aux);/*esto tiene que ser un cartel */
        cout<<"\t"<<" INGRESE EL DOMICILIO:"<<endl;/*esto tiene que ser un cartel */
        Ingreso_Direccion(aux);
        strcpy(reg.domicilio,aux);/*esto tiene que ser un cartel */
        cout<<"\t"<<" INGRESE EL MAIL:"<<endl;/*esto tiene que ser un cartel */
        Ingreso_Apodo(aux);
        strcpy(reg.email,aux);


    }
    while(Duplicado_Contacto(&reg));
    return reg;


}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Guardar_Contacto(Contacto reg)
// ACCION : esta funcion escribe en un archivo un struct contacto
// PARAMETROS: struct contacto
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Guardar_Contacto(Contacto reg)
{
    /*funcion */

    FILE *archivo;
    archivo=fopen(CONTACTO,"ab");
    if(archivo==NULL)
    {
        Error_Archivo();
        exit(1);
    }
    fwrite(&reg,sizeof(Contacto),1,archivo);
    fclose(archivo);



}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Total_Contacto()
// ACCION : esta funcion devuelve el total de registros contacto de un archivo
// PARAMETROS: ninguno
// DEVUELVE : un valor entero
// -----------------------------------------------------------------------------

int Total_Contacto()
{

    FILE *archivo;
    int tam;
    archivo=fopen(CONTACTO,"rb");
    if(archivo==NULL)
    {
        Error_Archivo();
        return -1;
    }
    fseek(archivo,0,2);
    tam=ftell(archivo)/sizeof(Contacto);
    fclose(archivo);
    return tam;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : GenerarID_Contacto()
// ACCION : esta funcion graba en un archivo el total de registros contacto
// PARAMETROS: ninguno
// DEVUELVE : un valor entero
// -----------------------------------------------------------------------------


void GenerarID_Contacto()
{
    FILE *archivo;
    Contacto reg;
    int tam=Total_Contacto();
    archivo=fopen(CONTACTO,"rb+");
    if(archivo==NULL)
    {
        Error_Archivo();
        exit(1);
    }

    while(fread(&reg,sizeof(Contacto),1,archivo)) {}
    fseek(archivo,-sizeof(Contacto),1);
    reg.id=tam;
    fwrite(&reg,sizeof(Contacto),1,archivo);
    fclose(archivo);

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Mostrar_Contacto(Contacto *usuario,bool id)
// ACCION : esta funcion saca por pantalla un struct contacto
// PARAMETROS: direccion de memoria de un struct contacto, un valor booleano
// DEVUELVE : nada
// -----------------------------------------------------------------------------



void Mostrar_Contacto(Contacto *usuario,bool id)
{

    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"| NOMBRE: "<<usuario->nombre<<"\t"<<" APELLIDO: "<<usuario->apellido<<"\t"<<" APODO/NICK: "<<usuario->apodo<<endl;
    cout<<"\t"<<"| DOMICILIO:"<<usuario->domicilio<<"\t"<<" E-MAIL: "<<usuario->email;

    if(id==true)
    {
        cout<<"\t"<<"| ID: "<<usuario->id;
    }
    cout<<endl;

}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Leer_Contacto(int pos,Contacto *reg)
// ACCION : esta funcion lee de un archivo la informacion de un struct contacto
// PARAMETROS: direccion de memoria de un struct contacto, un valor entero
// DEVUELVE : nada
// -----------------------------------------------------------------------------


void Leer_Contacto(int pos,Contacto *reg)
{

    FILE *archivo;
    archivo=fopen(CONTACTO,"rb");
    if(archivo==NULL)
    {
        Error_Archivo();
        exit(1);
    }
    fseek(archivo,sizeof(Contacto)*pos,0);
    fread(reg,sizeof(Contacto),1,archivo);
    fclose(archivo);



}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Listar_Contacto()
// ACCION : esta funcion muestra todos los contactos y sus telefonos
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Listar_Contacto()
{

    int tam,cant;
    Contacto reg;
    cant=0;
    tam=Total_Contacto();
    if(tam==-1)return;

    Datos_Contacto();
    for(int x=0; x<tam; x++)
    {
        Leer_Contacto(x,&reg);
        if(reg.eliminado==false&&cant<5)
        {
            /* el parametro true o false es para mostrar el ID*/
            Mostrar_Contacto(&reg,false);
            Listar_Telefono(reg.id);
        }
        cant++;/**/

        if(cant>=5)
        {
            cant=0;
            system("pause");
            sys::cls();
        }
    }
    system("pause");


}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Coincidencias_Contacto(char *cadena)
// ACCION : esta funcion cuenta la cantidad de veces que una substring aparece
// PARAMETROS: una cadena de caracteres
// DEVUELVE : un valor entero
// -----------------------------------------------------------------------------

/*esta funcion devuelve la cantidad de coincidencias segun la subcadena ingresada
 , pensando en los casos que haya mas de una coincidencia */
int Coincidencias_Contacto(char *cadena)
{
    int cant=0;int tam=Total_Contacto();
    Contacto reg;
    for(int x=0;x<tam;x++)
    {
        Leer_Contacto(x,&reg);
        if(strSub(reg.nombre,cadena)>=0||strSub(reg.apellido,cadena)>=0)
        {
            cant++;
        }
    }

    return cant;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Existe_ID_Contacto(int val,int *vec, int tam)
// ACCION : esta funcion verifica que el id ingresado por el usuario coincida
// con alguno almacenado en el vector.
// PARAMETROS: dos valores enteros, un vector de enteros
// DEVUELVE : un valor booleano
// -----------------------------------------------------------------------------

/*esta funcion verifica que el id ingresado por el usuario exista*/
bool Existe_ID_Contacto(int val,int *vec, int tam)
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
// FUNCION : Vec_cargarID_Contacto(int *vec,char *cadena)
// ACCION : esta funcion verifica que el id ingresado por el usuario coincida
// con alguno almacenado en el vector.
// PARAMETROS: dos valores enteros, un vector de enteros
// DEVUELVE : un valor booleano
// -----------------------------------------------------------------------------

void Vec_cargarID_Contacto(int *vec,char *cadena)
{
    int tam;tam=Total_Contacto();Contacto reg;

    for(int x=0; x<tam; x++)
    {
        Leer_Contacto(x,&reg);
        if(strSub(reg.nombre,cadena)>=0||strSub(reg.apellido,cadena)>=0)
        {
            Mostrar_Contacto(&reg,true);/*mostramos el contacto con sus correspondientes ID*/
            *vec=reg.id;vec++;/*guardamos en el vector los valores id de los contactos*/
        }

    }




}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Buscar_XID_Contacto(int val)
// ACCION : esta funcion busca la posicion del contacto a través del id
// PARAMETROS: un valor entero
// DEVUELVE : un valor entero
// -----------------------------------------------------------------------------

int Buscar_XID_Contacto(int val)
{
    Contacto reg;
    int tam=Total_Contacto();
    for(int x=0;x<tam;x++)
    {
        Leer_Contacto(x,&reg);
        if(reg.id==val)
        {
            return x ;
        }
    }
    return -1;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Seleccion_Contacto(char *cadena)
// ACCION : esta funcion devuelve  la posicion del contacto
// PARAMETROS: una cadena de caracteres
// DEVUELVE : un valor entero
// -----------------------------------------------------------------------------

int Seleccion_Contacto(char *cadena)
{
    int id_opc,cant;int *vec;bool repetir;
    int pos;/*guardamos la posicion del registro a modificar*/
    cant=Coincidencias_Contacto(cadena);

    vec=(int *)malloc(sizeof(int)*cant);/*vector que almacena los id de los registros con coincidencias*/
    if(vec==NULL)/*verificamos la asignacion de memoria */
    {
        cout<<"error de memoria";
        return -1;/*retornamos a la anterior funcion en caso negativo*/
    }

    /*cargo el vector con los ID  de los registros*/
   Vec_cargarID_Contacto(vec,cadena);

    do
    {
         Cartel_id_Contacto();
         Ingreso_Numeros(&id_opc);
         repetir=Existe_ID_Contacto(id_opc,vec,cant);


    }
    while(repetir==false);/*si el id ingresado y el id del vector no coinciden, se repite el ciclo */
    pos=Buscar_XID_Contacto(id_opc);/*guardamos la posicon del del contacto en pos*/

    return pos;/*devolvemos la posicion del contacto*/
    free(vec);/*libero la memoria asignada*/


}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Posicion_Contacto(char *cadena)
// ACCION : esta funcion devuelve  la posicion del contacto, sino existe
// devuelve un -1
// PARAMETROS: una cadena de caracteres
// DEVUELVE : un valor entero
// -----------------------------------------------------------------------------

int Posicion_Contacto(char *cadena)
{

    int tam;
    tam=Total_Contacto();
    Contacto reg;

    for(int x=0; x<tam; x++)
    {
        Leer_Contacto(x,&reg);
        if(strSub(reg.nombre,cadena)>=0||strSub(reg.apellido,cadena)>=0)
        {
            return x;
        }
    }
    /*en caso de no encontrar la subcadena en el regsitro*/
    return -1;

}


//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Reescribir_Contacto(Contacto *reg,int pos)
// ACCION : esta funcion modifica un struct contacto
// PARAMETROS: la direccion de memoria de un struct contacto, un valor entero
// DEVUELVE : nada
// -----------------------------------------------------------------------------


void Reescribir_Contacto(Contacto *reg,int pos)
{


    FILE *archivo;
    archivo=fopen(CONTACTO,"rb+");
    if(archivo==NULL)
    {
        Error_Archivo();
        exit(1);
    }
    fseek(archivo,sizeof(Contacto)*pos,0);
    fwrite(reg,sizeof(Contacto),1,archivo);
    fclose(archivo);
    Mostrar_Contacto(reg,true);
    system("pause");



}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Modificar_Atributos_Contacto(int val)
// ACCION : esta funcion modifica los atributos de un struct contacto
// PARAMETROS: una valor entero
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Modificar_Atributos_Contacto(int val)
{

     sys::cls();
    /*primero verificamos que haya ingresado ,solo letras*/
    int pos;
    char cadena[20];
    Contacto reg;

    menu_buscar();
    Ingreso_Letras(cadena);
     sys::cls();

    pos=Posicion_Contacto(cadena);

    if(pos==-1) /*me da la posicion dentro del archivo*/
    {
        Error_Contacto();
        return;
    }

     pos=Seleccion_Contacto(cadena); sys::cls();/*MODIFACION AGREGADA*/
    Leer_Contacto(pos,&reg);
    Mostrar_Contacto(&reg,true);


    switch(val)
    {
    case 1:
    {
        Cartel_nueva_nombre_contacto();
        Ingreso_Letras(cadena);
        strcpy(reg.nombre,cadena);
    }
    break;
    case 2:
    {
        Cartel_nueva_apellido_contacto();
        Ingreso_Letras(cadena);
        strcpy(reg.apellido,cadena);
    }
    break;
    case 3:
    {
        Cartel_nueva_apodo_contacto();
        Ingreso_Apodo(cadena);
        strcpy(reg.apodo,cadena);
    }
    break;
    case 4:
    {
        Cartel_nueva_direccion_contacto();
        Ingreso_Direccion(cadena);
        strcpy(reg.domicilio,cadena);
    }
    break;
    case 5:
    {

        Cartel_nuevO_email_contacto();
        Ingreso_Apodo(cadena);
        strcpy(reg.email,cadena);
    }
    break;
    case 6:
    {
        Eliminar(&reg.eliminado);
    }
    break;
    case 7:
        {
            int auxID;/*variables auxiliar para guardar el ID*/
            auxID=reg.id;/*salvamos el id del contacto*/
            system("pause");
            reg=Cargar_Contacto();/*cargamos y guardamos un nuevo contacto*/
            reg.id=auxID;/*asignamos el id al nuevo registro*/

        }break;


    }
    /*guardamos las modifiaciones en el archivo*/
    Reescribir_Contacto(&reg,pos);




}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Opciones_Contacto()
// ACCION : esta funcion abre un menu de opciones para modificar un contacto
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Opciones_Contacto()
{
    int op;
    bool ingresar=true;
    while(ingresar)
    {
        Menu_Contacto();
        Ingreso_Numeros(&op);
        switch(op)
        {
        case 1:
        {
            /* el caso 1 modifica solamente el nombre*/
            Modificar_Atributos_Contacto(1);
        }
        break;
        case 2:
        {
            /* el caso 2 modifica solamente el apellido*/
            Modificar_Atributos_Contacto(2);
        }
        break;
        case 3:
        {
            /* el caso 3 modifica solamente la direccion */
            Modificar_Atributos_Contacto(3);
        }
        break;
        case 4:
        {
            /* el caso 4 modifica solamente el apodo*/
            Modificar_Atributos_Contacto(4);

        }
        break;

        case 5:
        {
            /* el caso 5 modifica solamente el email*/
            Modificar_Atributos_Contacto(5);
        }
        break;
        case 6:
        {
            /* el caso 6 modifica el atributo eliminado*/
            Modificar_Atributos_Contacto(6);
        }
        break;
        case 7:
        {
           Modificar_Atributos_Contacto(7);
        }
        break;
        case 0:
        {
            volver(&ingresar);
        }
        break;
        }
    }

}

///===========================FUNCIONES TELEFONO/CONTACTO=================================================///
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Guardar_TelefonoContacto()
// ACCION : esta funcion asigna telefonos a un contacto
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------


void Guardar_TelefonoContacto()
{

    int pos;
    char cadena[20];
    Contacto reg;
    int opc;
   sys::cls();
    menu_buscar();
    Ingreso_Letras(cadena);


    pos=Posicion_Contacto(cadena);
    if(pos==-1) /*me da la posicion dentro del archivo*/
    {
        Error_Contacto();
        return;
    }

    pos=Seleccion_Contacto(cadena);
    Leer_Contacto(pos,&reg);

    do
    {

        Guardar_Telefono(Cargar_Telefono(reg.id));GenerarID_Telefono();
        //incluir id_telefono
        otro_Telefono();
        Ingreso_Numeros(&opc);
        if(opc!=1)opc=0;/*forzamos la salida en caso de que ingrese un numero distinto de 1*/

    }
    while(opc!=0);

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Modificar_Atributos_Telefono(int val)
// ACCION : esta funcion modifica los atributos de un struct telefono
// PARAMETROS: una valor entero
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Modificar_Atributos_Telefono(int val)
{


    int pos;char cadena[20];Contacto reg;Telefono dat;
    sys::cls();
    menu_buscar();
    Ingreso_Letras(cadena);
    pos=Posicion_Contacto(cadena);

    if(pos==-1) /*verifico que exista al menos una vez*/
    {
        Error_Contacto();
        return;
    }

    pos=Seleccion_Contacto(cadena); sys::cls();/*MODIFACION AGREGADA*/
    Leer_Contacto(pos,&reg);
    Mostrar_Contacto(&reg,true);
    sys::cls();
    pos=Coincidencias_XID_Telefono(reg.id);
    if(pos==0)
    {   /*no se encontraron coincidencias para el contacto*/
        Error_Telefono();
        return;
    }
    pos=Seleccion_Telefono(reg.id);
    Leer_Telefono(pos,&dat);
     sys::cls();
    Mostrar_Telefono(&dat,true);

    switch(val)
    {
    case 1:
    {
        /* modifica el tipo de telefono*/

        Cartel_nueva_tipo_telefono();
        Ingreso_Letras(cadena);
        strcpy(dat.descripcion,cadena);
    }
    break;
    case 2:
    {
        /* modifica el numero de telefono*/
        Cartel_nuevo_numero_telefono();
        Cadena_numero(cadena);
        strcpy(dat.descripcion,cadena);

    }
    break;
    case 3:
    {
        /* el caso 3 seria eliminar telefono */

        Eliminar(&dat.borrado);
    }
    break;
    case 4:
    {
        /*el caso 4 carga todo el telefono de nuevo*/
        int idaux;/*salvamos el ID Contacto y ID telefono*/
        idaux=dat.id_Telefono;
        dat=Cargar_Telefono(reg.id);
        dat.id_Telefono=idaux;

    }
    break;
    }
    Reescribir_Telefono(&dat,pos);

}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION :Opciones_Telefono()
// ACCION : esta funcion abre un menu para modificar un struct telefono
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------


void Opciones_Telefono()
{

    int op;
    bool ingresar=true;
    while(ingresar)
    {
        Menu_Telefono();
        Ingreso_Numeros(&op);
        switch(op)
        {
        case 1:
        {
            /* modifica el tipo de telefono*/

            Modificar_Atributos_Telefono(1);
        }
        break;
        case 2:
        {
            /* modifica el numero de telefono*/

            Modificar_Atributos_Telefono(2);
        }
        break;
        case 3:
        {
            /* el caso 3 seria eliminar telefono */

            Modificar_Atributos_Telefono(3);
        }
        break;
        case 4:
        {
            /*carga nuevamente el telefono*/

            Modificar_Atributos_Telefono(4);
        }
        break;
        case 0:
        {
            volver(&ingresar);
        }
        break;
        }
    }

}


#endif // CONTACTO_H_INCLUDED
