#include "Menu.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <Persona.h>
using namespace std;

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}
void Menu::menuPrincipal()
{
    int opcion;
    do
    {
        cout<<"\t\t\t\tBase de Datos de Alumnos\t\t\t\t\n\n";
        cout<<"1. Ingresar nuevo alumno\n\n";
        cout<<"2. Modificar alumno\n\n";
        cout<<"3. Eliminar alumno\n\n";
        cout<<"4. Visualizar alumnos\n\n";
        cout<<"5. Buscar alumno\n\n";
        cout<<"6. Salir\n\n";
        cout<<"Opcion: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opcion invalida!\n\n";
            break;

        case 1:
            crearAlumno();
            break;

        case 2:
            modificarAlumno();
            break;

        case 3:
            eliminarAlumno();
            break;

        /*case 4:
            visualizarAlumno(); //ordenamiento ascendente, descendente,por carrera
            break;

        case 5:
            buscarAlumno();
            break;*/

        case 6:
            break;
        }
    }
    while(opcion!=6);
}
void Menu::crearAlumno(){
    ofstream escritura;
    ifstream verificador;
    char auxCodigo[30];
    bool coincidencia=false;
    verificador.open("base.txt",ios::in);
    escritura.open("base.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\tCrear nuevo alumno\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el ID del alumno: ";
        cin.getline(auxCodigo,30);
        if(strcmp(auxCodigo,"")==0)
            do{
                cout<<"ID de alumno no valido!, intentalo nuevamente: ";
                cin.getline(auxCodigo,30);
            }
            while(strcmp(auxCodigo,"")==0);
        do{
            verificador.seekg(0);
            verificador>>ID;
            while(!verificador.eof()){
                verificador>>nombre>>apellido>>edad>>email;

                if(strcmp(ID,auxCodigo)==0){
                    coincidencia=true;
                    cout<<"\n\nYa existe un alumno con ese ID!\n\n";
                    cout<<"El alumno con ese ID es: "<<nombre<<"\n\n";
                    cout<<"Ingresa un ID valido!: ";
                    cin.getline(auxCodigo,30);
                    if(strcmp(auxCodigo,"")==0)
                        do{
                            cout<<"\nID de alumno no valido!, intentalo nuevamente: ";
                            cin.getline(auxCodigo,30);
                        }
                        while(strcmp(auxCodigo,"")==0);

                    break;
                }

                verificador>>ID;
            }

            if(verificador.eof()&&strcmp(auxCodigo,ID)!=0)
                coincidencia=false;
        }
        while(coincidencia==true);
        system("cls");
        strcpy(ID,auxCodigo);
        cout<<"\t\t\t\tCrear alumno nuevo\t\t\t\t\n\n";
        cout<<"Ingresa el ID del alumno: ";
        cout<<ID;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre del alumno: ";
        cin.getline(nombre,30);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el apellido del alumno: ";
        cin.getline(apellido,30);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la edad del alumno: ";
        cin>>edad;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el email del alumno: ";
        cin.getline(email,30);
        cout<<"\n\n";

        escritura<<ID<<"\n\n"<<nombre<<"\n\n"<<apellido<<"\n\n"<<edad<<"\n\n"<<email<<"\n\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }
}
void Menu::visualizarAlumno(char codigo[30])
{

    ifstream mostrar;
    mostrar.open("base.txt",ios::in);
    mostrar>>ID;
    while(!mostrar.eof())
    {
        mostrar>>nombre>>apellido>>edad>>email;
        if(strcmp(codigo,ID)==0)
        {
            cout<<"\n\nDatos del alumno:\n\n";
            cout<<"ID: "<<ID<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Apellido: "<<apellido<<endl;
            cout<<"Edad: "<<edad<<endl;
            cout<<"Email: "<<email<<endl;
            cout<<"\n\n";
        }

        mostrar>>ID;
    }

    mostrar.close();
}
void error(){
    cout<<"No se pudo abrir el archivo de registros";
}
void pausa(){
    cout<<"Presiona Enter para continuar...";
    getch();
    system("cls");
}
void Menu::modificarAlumno()
{
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    char auxCodigo[30];
    char codigoModif[30];
    char auxNombre[30];
    char auxApellido[30];
    int auxEdad;
    char auxEmail[30];
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("base.txt",ios::in);
    verificador.open("base.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\tModificar los datos de un alumno\t\t\t\t\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el ID del alumno que deseas modificar: ";
        cin.getline(auxCodigo,30);

        if(strcmp(auxCodigo,"")==0)
        {
            do
            {
                cout<<"ID de alumno no valido!, intentalo nuevamente: ";
                cin.getline(auxCodigo,30);
            }
            while(strcmp(auxCodigo,"")==0);
        }

        strcpy(codigoModif,auxCodigo);

        lectura>>ID;
        while(!lectura.eof())
        {
            lectura>>nombre>>apellido>>edad>>email;
            if(strcmp(auxCodigo,ID)==0)
            {
                encontrado=true;
                visualizarAlumno(codigoModif);
                cout<<"\n\n";
                cout<<"Ingresa la nueva informacion para el alumno\n\n";
                fflush(stdin);
                cout<<"Ingresa el nuevo ID: ";
                cin.getline(auxCodigo,30);
                if(strcmp(auxCodigo,codigoModif)==0)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(strcmp(auxCodigo,codigoModif)==0)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        verificador>>ID;
                        while(!verificador.eof())
                        {
                            verificador>>nombre>>apellido>>edad>>email;

                            if(strcmp(ID,auxCodigo)==0)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un cliente con ese c\242digo!\n\n";
                                cout<<"El cliente con ese c\242digo es: "<<nombre<<"\n\n";
                                cout<<"Ingresa un c\242digo v\240lido!: ";
                                cin.getline(auxCodigo,30);

                                if(strcmp(auxCodigo,"")==0)
                                {
                                    do
                                    {
                                        cout<<"\nc\242digo de cliente no v\240lido!, ";
                                        cout<<"intentalo nuevamente: ";
                                        cin.getline(auxCodigo,30);
                                    }
                                    while(strcmp(auxCodigo,"")==0);
                                }
                                break;
                            }

                            verificador>>ID;
                        }

                        if(verificador.eof()&&strcmp(auxCodigo,ID)!=0)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system("cls");
                cout<<"Modificar los datos de un alumno\n\n";
                cout<<"Ingresa el ID del alumno que deseas modificar: ";
                cout<<codigoModif;
                visualizarAlumno(codigoModif);
                cout<<"____________________________________________________";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informacion para el alumno\n\n";
                cout<<"Ingresa el ID del alumno: ";
                cout<<auxCodigo;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el nombre del alumno: ";
                cin.getline(auxNombre,30);
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa el apellido del cliente: ";
                cin.getline(auxApellido,30);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la edad del alumno: ";
                cin>>auxEdad;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el email del alumno: ";
                cin.getline(auxEmail,30);
                cout<<"\n\n";
                auxiliar<<auxCodigo<<"\n\n"<<auxNombre<<"\n\n"<<auxApellido<<"\n\n"<<auxEdad<<"\n\n"<<auxEmail<<"\n\n";
                cout<<"El Registro se ha modificado correctamente :)\n\n";
            }
            else{
                auxiliar<<ID<<"\n\n"<<nombre<<"\n\n"<<apellido<<"\n\n"<<edad<<"\n\n"<<email<<"\n\n";
            }
            lectura>>ID;
        }
    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontro ningun alumno con ese ID!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("base.txt");
    rename("auxiliar.txt","base.txt");
    pausa();
}
void Menu::eliminarAlumno()
{
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    char auxCodigo[30];
    char respuesta[5];
    lectura.open("base.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\tEliminar un alumno\t\t\t\t\n\n";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el ID del alumno que deseas eliminar: ";
        cin.getline(auxCodigo,30);
        lectura>>ID;
        while(!lectura.eof())
        {
            lectura>>nombre>>apellido>>edad>>email;
            if(strcmp(auxCodigo,ID)==0)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"ID: "<<ID<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Apellido: "<<apellido<<endl;
                cout<<"Edad: "<<edad<<endl;
                cout<<"Email: "<<email<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas eliminar de la base a: "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    cout<<"\n\nEl alumno se ha eliminado correctamente\n\n";
                }
                else{
                    cout<<"\n\nAlumno conservado\n\n";
                    auxiliar<<ID<<"\n\n"<<nombre<<"\n\n"<<apellido<<"\n\n"<<edad<<"\n\n"<<email<<"\n\n";
                }

            }
            else{
                auxiliar<<ID<<"\n\n"<<nombre<<"\n\n"<<apellido<<"\n\n"<<edad<<"\n\n"<<email<<"\n\n";
            }
            lectura>>ID;
        }
        if(encontrado==false){
            cout<<"\n\nNo se encontro el ID: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("base.txt");
    rename("auxiliar.txt","base.txt");
    pausa();
}
