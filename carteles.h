#ifndef CARTELES_H_INCLUDED
#define CARTELES_H_INCLUDED
////#############################################################################
// ARCHIVO : carteles.h
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
// muestra carteles por pantalla
/////////////////////////////////////////////////////////////////////////////////
using namespace std;
//=============================================================================
// FUNCION : void menu_principal()
// ACCION : esta funcion devuelve el menu principal
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void menu_principal()
{
    sys::cls();
    cout<<"\t"<<"+================================================+"<<endl;
    cout<<"\t"<<"|                AGENDA ELECTRONICA              |"<<endl;
    cout<<"\t"<<"+-------------------+----------------------------+"<<endl;
    cout<<"\t"<<"|    OPCION...1     |         Agregar Contacto   |"<<endl;
    cout<<"\t"<<"|    OPCION...2     |        Modificar Contacto  |"<<endl;
    cout<<"\t"<<"|    OPCION...3     |         Agregar Telefono   |"<<endl;
    cout<<"\t"<<"|    OPCION...4     |        Modificar Telefono  |"<<endl;
    cout<<"\t"<<"|    OPCION...5     |         Imprimir listado   |"<<endl;
    cout<<"\t"<<"|    OPCION...6     |           Menu Ayuda       |"<<endl;
    cout<<"\t"<<"|    OPCION...0     |              SALIR         |"<<endl;
    cout<<"\t"<<"+-------------------+----------------------------+"<<endl;

}
//=============================================================================
// FUNCION :Menu_Contacto()
// ACCION : esta funcion devuelve el menu contacto
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void Menu_Contacto()
{
    sys::cls();
    cout<<"\t"<<"+================================================+"<<endl;
    cout<<"\t"<<"|                 MODIFICAR CONTACTO             |"<<endl;
    cout<<"\t"<<"+-------------------+----------------------------+"<<endl;
    cout<<"\t"<<"|    OPCION...1     |         Modificar Nombre   |"<<endl;
    cout<<"\t"<<"|    OPCION...2     |         Modificar Apellido |"<<endl;
    cout<<"\t"<<"|    OPCION...3     |         Modificar Apodo    |"<<endl;
    cout<<"\t"<<"|    OPCION...4     |        Modificar Domicilio |"<<endl;
    cout<<"\t"<<"|    OPCION...5     |         Modificar E-mail   |"<<endl;
    cout<<"\t"<<"|    OPCION...6     |             ELIMINAR       |"<<endl;
    cout<<"\t"<<"|    OPCION...7     |         Modificar TODO     |"<<endl;
    cout<<"\t"<<"|    OPCION...0     |              ATRAS         |"<<endl;
    cout<<"\t"<<"+-------------------+----------------------------+"<<endl;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Descripcion_Telefono()
// ACCION : muestra el menu con los tipos de descripciones de un telefono
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------



void Descripcion_Telefono()
{
    sys::cls();
    cout<<"\t"<<"+================================================+"<<endl;
    cout<<"\t"<<"|                  TIPO DE TELEFONO              |"<<endl;
    cout<<"\t"<<"+-------------------+----------------------------+"<<endl;
    cout<<"\t"<<"|    OPCION...1     |           PERSONAL         |"<<endl;
    cout<<"\t"<<"|    OPCION...2     |           LABORAL          |"<<endl;
    cout<<"\t"<<"|    OPCION...3     |            OTRO            |"<<endl;
    cout<<"\t"<<"+-------------------+----------------------------+"<<endl;

}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Menu_Telefono()
// ACCION : muestra el menu para modificar un telefono
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Menu_Telefono()
{
    sys::cls();
    cout<<"\t"<<"+================================================+"<<endl;
    cout<<"\t"<<"|                  MODIFICAR TELEFONO            |"<<endl;
    cout<<"\t"<<"+-------------------+----------------------------+"<<endl;
    cout<<"\t"<<"|    OPCION...1     |    Modificar descripcion   |"<<endl;
    cout<<"\t"<<"|    OPCION...2     |      Modificar Numero      |"<<endl;
    cout<<"\t"<<"|    OPCION...3     |      Eliminar Telefono     |"<<endl;
    cout<<"\t"<<"|    OPCION...4     |      Modificar TODO        |"<<endl;
    cout<<"\t"<<"|    OPCION...0     |          ATRAS             |"<<endl;
    cout<<"\t"<<"+-------------------+----------------------------+"<<endl;

}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Menu_ayuda()
// ACCION : muestra el menu para modificar un telefono
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Menu_ayuda()
{
    sys::cls();
    cout<<"\t"<<"+================================================+"<<endl;
    cout<<"\t"<<"|                     MENU AYUDA                 |"<<endl;
    cout<<"\t"<<"+-------------------+----------------------------+"<<endl;
    cout<<"\t"<<"|    OPCION...1     |        BUSCAR CONTACTO     |"<<endl;
    cout<<"\t"<<"|    OPCION...2     |  ELIMINAR CONTACTO/TELEFONO|"<<endl;
    cout<<"\t"<<"|    OPCION...3     |       SIGNIFICADO DEL ID   |"<<endl;
    cout<<"\t"<<"|    OPCION...0     |          ATRAS             |"<<endl;
    cout<<"\t"<<"+-------------------+----------------------------+"<<endl;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : explicaion_a()
// ACCION : muestra la explicacion para buscar un contacto
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------



void explicaion_a()
{

    sys::cls();
    cout<<"\t"<<"+---------------------------------------------------------+"<<endl;
    cout<<"\t"<<"|                      BUSCAR CONTACTO                    |"<<endl;
    cout<<"\t"<<"+---------------------------------------------------------+"<<endl;
    cout<<"+------------------------------------------------------------------------+"<<endl;
    cout<<"|  La busqueda del contacto debe resalizarse a partir de una cadena      |" << endl;
    cout<<"|  compuesta por al menos 3 caracteres alfabeticos.Si el contacto existe |" << endl;
    cout<<"|  se mostrara por pantalla todos los datos del mismo, en caso contrario |" << endl;
    cout<<"|  el programa retornara al menu anterior                                |" << endl;
    cout<<"+------------------------------------------------------------------------+"<<endl;
    system("pause");

}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : explicaion_a()
// ACCION : muestra la explicacion para eliminar un contacto o telefono
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void explicaion_b()
{


    sys::cls();
    cout<<"\t"<<"+---------------------------------------------------------+"<<endl;
    cout<<"\t"<<"|                ELIMINAR CONTACTO/TELEFONO               |"<<endl;
    cout<<"\t"<<"+---------------------------------------------------------+"<<endl;
    cout<<"+------------------------------------------------------------------------+"<<endl;
    cout<<"| Para eliminar un contacto o un telefono, se requiere la busqueda del   |" << endl;
    cout<<"|  del primero. Una vez encontrado se mostrara por pantalla todos sus    |" << endl;
    cout<<"|  telefonos.En caso contrario se mostrará un mensaje advirtiendo que el |" << endl;
    cout<<"|  contato no posee telefonos.                                           |" << endl;
    cout<<"+------------------------------------------------------------------------+"<<endl;
system("pause");


}


//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : explicaion_c()
// ACCION : muestra la explicacion del ID
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void explicaion_c()
{


    sys::cls();
    cout<<"\t"<<"+---------------------------------------------------------+"<<endl;
    cout<<"\t"<<"|                         SIGNIFICADO DEL ID              |"<<endl;
    cout<<"\t"<<"+---------------------------------------------------------+"<<endl;
    cout<<"+------------------------------------------------------------------------+"<<endl;
    cout<<"| El ID  es un numero identificar ,unico e irrepetible para cada contacto|" << endl;
    cout<<"| y/o telefono. el valor del ID solo sera visible a traves de la busqueda|" << endl;
    cout<<"|  del contacto                                                          |" << endl;
    cout<<"+------------------------------------------------------------------------+"<<endl;

system("pause");

}











//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : menu_buscar()
// ACCION : esta funcion devuelve el menu de busqueda de contacto
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------


void menu_buscar()
{
    cout<<"\t"<<"+================================================+"<<endl;
    cout<<"\t"<<"|         INGRESE UN NOMBRE O APELLIDO           |"<<endl;
    cout<<"\t"<<"|     DEBE INGRESAR UN MINIMO DE 3 LETRAS        |"<<endl;
    cout<<"\t"<<"+================================================+"<<endl;
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : cambiar_Telefono()
// ACCION : esta funcion devuelve un cartel de modificacion del telefono
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void cambiar_Telefono()
{

    cout<<"\t"<<"+------------------------------------------------+"<<endl;
    cout<<"\t"<<"|   INGRESE EL ID DEL TELEFONO A MODIFICAR       |"<<endl;
    cout<<"\t"<<"+------------------------------------------------+"<<endl;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : eliminar_Telefono()
// ACCION : esta funcion devuelve el mensaje de eliminar un telefono
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void eliminar_Telefono()
{

    cout<<"\t"<<"+------------------------------------------------+"<<endl;
    cout<<"\t"<<"|     INGRESE EL TIPO DE TELEFONO A ELIMINAR     |"<<endl;
    cout<<"\t"<<"+------------------------------------------------+"<<endl;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : incorrecto()
// ACCION : esta funcion devuelve un mensaje de aviso
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void incorrecto()
{
    sys::cls();
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"\t"<<"INGRESE UNA OPCION VALIDA"<<"\t"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo

    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) <<endl; //borde inferior derecho
    sys::msleep(2);
    sys::cls();

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : saludo()
// ACCION : esta funcion devuelve el mensaje de bienvenida
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void saludo()
{
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"\t"<<"BIENVENIDO"<<"\t"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo

    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) <<endl; //borde inferior derecho
    sys::msleep(1);
    sys::cls();

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : despedida()
// ACCION : esta funcion un saludo de despedida
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void despedida()
{
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"\t"<<"ADIOS"<<"\t"<<"\t"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo

    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) << endl; //borde inferior derecho
    sys::msleep(1);
    sys::cls();
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void mensaje_guardado()
// ACCION : esta funcion devuelve un mensaje de advertencia
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void mensaje_guardado()
{
    sys::cls();
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"\t"<<"CONTACTO GUARDADO"<<"\t"<<"\t"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo

    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) << endl; //borde inferior derecho
    sys::msleep(2);
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void mensaje_borrado()
// ACCION : esta funcion devuelve un mensaje de advertencia
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void mensaje_borrado()
{
    sys::cls();
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"REGISTRO ELIMINADO"<<"\t"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo

    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) <<endl; //borde inferior derecho
    sys::msleep(1);
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void otro_Telefono()
// ACCION : esta funcion pregunta si desa guardar otro telefono
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void otro_Telefono()
{
    sys::cls();
    cout<<"\t"<<"+-----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|              DESEA AGREGAR UN TELEFONO              |"<<endl;
    cout<<"\t"<<"|             SI.........1           NO.......0       |"<<endl;
    cout<<"\t"<<"+-----------------------------------------------------+"<<endl;
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void noexiste_contacto())
// ACCION : esta funcion advierte que no se pudo hallar el contacto
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void Error_Contacto()
{
sys::cls();
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"NO EXISTE EL CONTACTO."<<"\t"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo

    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) <<endl; //borde inferior derecho
    sys::msleep(1);
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : fallo()
// ACCION : esta funcion advierte que no se pudo acceder al archivo
// PARAMETROS:ninguno
// DEVUELVE : nada.
// -----------------------------------------------------------------------------

void Error_Telefono()
{
//sys::cls();
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"EL CONTACTO NO TIENE TELEFONOS"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo

    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) <<endl; //borde inferior derecho
    sys::msleep(1);
}


//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Error_Archivo()
// ACCION : muestra por pantalla un mensaje de advertencia
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Error_Archivo()
{
sys::cls();
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"EL ARCHIVO NO EXISTE"<<"\t"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo

    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) <<endl; //borde inferior derecho
    sys::msleep(1);
}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Completar_Campos()
// ACCION : muestra por pantalla un mensaje
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Completar_Campos()
{
sys::cls();
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"COMPLETE LOS SIGUIENTES CAMPOS"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo

    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) <<endl; //borde inferior derecho
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Datos_Contacto()
// ACCION : muestra por pantalla un mensaje
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Datos_Contacto()
{
sys::cls();
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"DATOS DEL CONTACTO"<<"\t"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo
///ESTO ESTABA COMENTADO
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) <<endl; //borde inferior derecho

    sys::msleep(1);
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Datos_Telefono()
// ACCION : muestra por pantalla
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Datos_Telefono()
{
sys::cls();
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"DATOS DEL TELEFONO"<<"\t"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo
///ESTO ESTABA COMENTADO
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) <<endl; //borde inferior derecho
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Nuevo_Valor()
// ACCION : saca por pantalla un cartel
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Nuevo_Valor()
{
    //sys::cls();
    int i;
    cout <<"\t"<<"\t"<< char(201); //borde superior izquierdo
    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout <<char(187); // borde superior derecho
    cout << endl;

    cout<<"\t"<<"\t"<<char(186)<<"\t"<<"\t"<<"INGRESE UN NUEVO VALOR"<<"\t"<<"\t"<<"\t"<<char(186)<<endl;
    cout <<"\t"<<"\t"<< char(200); //borde inferior izquierdo

    for (i=0; i<=54; i++)
    {
        cout << char(205); // linea recta
    }
    cout << char(188) <<endl; //borde inferior derecho
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : cartel_Borrar_Registro()
// ACCION : saca por pantalla un cartel
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void cartel_Borrar_Registro()
{
    //sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|        ¿ESTA SEGURO DE ELIMINAR EL REGISTRO?       |"<<endl;
    cout<<"\t"<<"|             SI.........1           NO.......0      |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Yaexiste_Contacto()
// ACCION : saca por pantalla un cartel
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Yaexiste_Contacto()
{
    sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|             EL CONTACTO INGRESADO YA EXISTE        |"<<endl;
    cout<<"\t"<<"|         DEBE INGRESAR VALORES PARA EL CONTACTO     |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;

}

//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Cartel_id_Contacto()
// ACCION : saca por pantalla un cartel
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Cartel_id_Contacto()
{
     //sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|         INGRESE EL ID DEL CONTACTO A MODIFICAR     |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Cartel_id_Telefono()
// ACCION : saca por pantalla un cartel
// PARAMETROS:nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Cartel_id_Telefono()
{
     //sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|         INGRESE EL ID DEL TELEFONO A MODIFICAR     |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Cartel_nuevo_numero_telefono()
// ACCION : saca por pantalla un cartel
// PARAMETROS:nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Cartel_nuevo_numero_telefono()
{
     //sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|         INGRESE EL NUEVO NUMERO DE TELEFONO        |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Cartel_nueva_tipo_telefono()
// ACCION : saca por pantalla un cartel
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Cartel_nueva_tipo_telefono()
{
     //sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|          INGRESE EL NUEVO TIPO DE TELEFONO         |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Cartel_nueva_nombre_contacto()
// ACCION : saca por pantalla un cartel
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Cartel_nueva_nombre_contacto()
{
     //sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|        INGRESE EL NUEVO NOMBRE DEL CONTACTO        |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Cartel_nueva_apellido_contacto()
// ACCION : saca por pantalla un cartel
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Cartel_nueva_apellido_contacto()
{
     //sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|        INGRESE EL NUEVO APELLIDO DEL CONTACTO      |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Cartel_nueva_apodo_contacto()
// ACCION : saca por pantalla un cartel
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------

void Cartel_nueva_apodo_contacto()
{
     //sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|       INGRESE EL NUEVO APODO/NICK DEL CONTACTO     |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Cartel_nueva_direccion_contacto()
// ACCION : saca por pantalla un cartel
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Cartel_nueva_direccion_contacto()
{
     //sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|        INGRESE LA NUEVA DIRECCION DEL CONTACTO     |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;

}
//*****************************************************************************
// DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : Cartel_nuevO_email_contacto()
// ACCION : saca por pantalla un cartel
// PARAMETROS: nada
// DEVUELVE : nada
// -----------------------------------------------------------------------------
void Cartel_nuevO_email_contacto()
{
     //sys::cls();
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;
    cout<<"\t"<<"|         INGRESE EL  NUEVO E-MAIL DEL CONTACTO      |"<<endl;
    cout<<"\t"<<"+----------------------------------------------------+"<<endl;

}

#endif // CARTELES_H_INCLUDED
