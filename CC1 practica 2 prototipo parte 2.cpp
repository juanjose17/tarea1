/*--------universidad.h---------*/


#ifndef INSTITUCION_H
#define INSTITUCION_H
#include <conio.h> // getch
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Estudiante.h"
#include "Profesor.h"
#include "Curso.h"

using namespace std;
class Institucion{
    private:
        int numEst;
        int numProf;
        vector<Profesor*> profes;
        vector<Estudiante*> students;
        Curso cursos[15];
    public:
        void menuPrincipal();
        void crearEstudiante();
        void crearProfesor();
        void modificarEstudiante();
        void modificarProfesor();
        void eliminarEstudiante();
        void eliminarProfesor();
        void ordenarPorCarreras();
        void mostrarTodo();
        void mostrarRegistro(char t[10]);
        void buscarEstudiante();
        void buscarProfesor(Profesor* x);

        Institucion();
        virtual ~Institucion();
        void ascendenteEstudiantes();
        void descendenteEstudiantes();
        void ascendenteProfesores();
        void descendenteProfesores();

};

#endif // INSTITUCION_H



/*--------universidad.h---------*/






/*--------universidad.cpp---------*/


#include "Institucion.h"
#include "Estudiante.h"
#include "Profesor.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

Institucion::Institucion(){
    //students.clear();
    //profes.clear();

    ifstream lectura1;
    lectura1.open("Estudiantes.txt",ios::in);

    if(lectura1.is_open()){
        //int i=0;
        numEst=0;
        while(!lectura1.eof()){

            //Estudiante test;
            Estudiante* test;
            test = new Estudiante();

            string aux1;
            getline(lectura1,aux1);
            char t[10];
            strcpy(t,aux1.c_str());
            cout<<t;
            test->setID(t);
            //cout<<students[i].getID();

            string a2;
            getline(lectura1,a2);
            char x[40];
            strcpy(x,a2.c_str());
            test->setNombre(x);

            string a3;
            getline(lectura1,a3);
            char y[3];
            strcpy(y,a3.c_str());
            test->setEdad(y);

            string a4;
            getline(lectura1,a4);
            char z[30];
            strcpy(z,a4.c_str());
            test->setEmail(z);

            string a5;
            getline(lectura1,a5);
            char w[50];
            strcpy(w,a5.c_str());
            test->setCarrera(w);

            //i++;
            numEst++;
            students.push_back(test);
        }
    }
    ifstream lectura2;
    lectura2.open("Profesores.txt",ios::in);
    if(lectura2.is_open()){
        //int i=0;
        numProf=0;
        while(!lectura2.eof()){

            //Profesor test;
            Profesor* test;
            test = new Profesor();

            string aux1;
            getline(lectura2,aux1);
            char t[10];
            strcpy(t,aux1.c_str());
            cout<<t;
            test->setID(t);
//            cout<<profes[i].getID();

            string a2;
            getline(lectura2,a2);
            char x[40];
            strcpy(x,a2.c_str());
            test->setNombre(x);

            string a3;
            getline(lectura2,a3);
            char y[3];
            strcpy(y,a3.c_str());
            test->setEdad(y);

            string a4;
            getline(lectura2,a4);
            char z[30];
            strcpy(z,a4.c_str());
            test->setEmail(z);

            string a5;
            getline(lectura2,a5);
            char w[50];
            strcpy(w,a5.c_str());
            test->setCursos(w);

            //i++;
            numProf++;
            profes.push_back(test);
        }
    }
    string con[15]={"Matematica","Comunicacion","Quimica","Historia","Filosofia","Gestion","Programacion","Topografia","Metodologia del Estudio","Estadística","Macroeconomia","Psicologia del Aprendizaje","Personalidad","Arquitectura de Computadoras","Derecho Procesal Penal"};
    char temp[30];
    for (int i=0;i<2;i++){
        strcpy(temp,con[i].c_str());
        cursos[i].setNombre(temp);
    }

}

Institucion::~Institucion()
{
  for (int i=0;i<students.size();i++){
        delete students[i];
    }
    for (int i=0;i<profes.size();i++){
        delete profes[i];
    }
}
void pausa(){
    cout<<"Presiona Enter para continuar...";
    getch();
    system("cls");
}

void error(){
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicacion que el programa y que se llame ComunidadEducativa.txt: \n";
}
bool substring(char a[],char b[]){
    int contadordeb=0;
    bool ans;
    int tamdeb=0;
    for (int j=0;b[j]!='\0';j++){
        tamdeb++;
    }
	for(int i=0;a[i]!='\0';i++)
	{
	    if (b[contadordeb]==a[i]){
            ans=true;
            contadordeb++;
            if (contadordeb==tamdeb)
                break;
	    }
	    else
            ans=false;
	}
    return ans;
}

void Institucion::buscarEstudiante(){
    char x[40];
    cout<<"Ingrese el nombre del estudiante que desea buscar: ";
    cin>>x;
    for (int i=0;i<students.size();i++){
        char r[40];
        strcpy(r,students[i]->getNombre());
        if (substring(r,x)){
            cout<<endl<<endl;
            cout<<"Nombre: "<<students[i]->getNombre()<<endl;
            cout<<"Edad: "<<students[i]->getEdad()<<endl;
            cout<<"Email: "<<students[i]->getEmail()<<endl;
            cout<<"Carrera: "<<students[i]->getCarrera()<<endl;
            cout<<endl<<endl;
        }
    }
    pausa();
}

/*void Institucion::crearCursos(){
    string con[15]={"Matematica","Comunicacion","Quimica","Historia","Filosofia","Gestion","Programacion","Topografia","Metodologia del Estudio","Estadística","Macroeconomia","Psicologia del Aprendizaje","Personalidad","Arquitectura de Computadoras","Derecho Procesal Penal"};
    char temp[30];
    for (int i=0;i<2;i++){
        strcpy(temp,con[i].c_str());
        cursos[i].setNombre(temp);
    }
}*/
void Institucion::menuPrincipal(){
    int opcion;
    do
    {
        cout<<endl<<"REGISTRO DE COMUNIDAD EDUCATIVA:"<<endl;
        cout<<"_______________________________________________________________________________________________"<<endl<<endl<<endl;
        cout<<"1. Matricula\n\n";
        cout<<"2. Modificacion\n\n";
        cout<<"3. Eliminar\n\n";
        cout<<"4. Visualizar\n\n";
        cout<<"5. Buscar\n\n";
        cout<<"6. Salir\n\n";
        cout<<"Opcion: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opcion no valida!\n\n";
            break;
        case 1:
            int aux;
            cout<<endl<<"ELIJA A QUIEN DESEA MATRICULAR:"<<endl<<endl;
            cout<<"1. Estudiante"<<endl<<endl;
            cout<<"2. Profesor"<<endl<<endl;
            cout<<"3. Salir"<<endl<<endl;
            cout<<"Opcion: ";
            cin>>aux;
            system("cls");
            switch (aux){
            default:
                cout<<"Ha ingresado una opcion no valida!\n\n";
            case 1:
                crearEstudiante();
                break;
            case 2:
                crearProfesor();
                break;
            }
            break;
        case 2:
            int aux2;
            cout<<endl<<"ELIJA A QUIEN DESEA MODIFICAR:"<<endl<<endl;
            cout<<"1. Estudiante"<<endl<<endl;
            cout<<"2. Profesor"<<endl<<endl;
            cout<<"3. Salir"<<endl<<endl;
            cout<<"Opcion: ";
            cin>>aux2;
            system("cls");
            switch (aux2){
            default:
                cout<<"Ha ingresado una opcion no valida!\n\n";
            case 1:
                modificarEstudiante();
                break;
            case 2:
                modificarProfesor();
                break;
            }
            break;
        case 3:
            int aux3;
            cout<<endl<<"ELIJA A QUIEN DESEA ELIMINAR:"<<endl<<endl;
            cout<<"1. Estudiante"<<endl<<endl;
            cout<<"2. Profesor"<<endl<<endl;
            cout<<"3. Salir"<<endl<<endl;
            cout<<"Opcion: ";
            cin>>aux3;
            system("cls");
            switch (aux3){
            default:
                cout<<"Ha ingresado una opcion no valida!\n\n";
            case 1:
                eliminarEstudiante();
                break;
            case 2:
                eliminarProfesor();
                break;
            }
            break;
        case 4:
            int aux4;
            cout<<endl<<"OPCIONES DE VISUALIZACION:"<<endl<<endl;
            cout<<"1. Ver lista de Todos"<<endl<<endl;
            cout<<"2. Ver lista de Alumnos de A-Z"<<endl<<endl;
            cout<<"3. Ver lista de Alumnos de Z-A"<<endl<<endl;
            cout<<"4. Ver lista de Profesores de A-Z"<<endl<<endl;
            cout<<"5. Ver lista de Profesores de Z-A"<<endl<<endl;
            cout<<"6. Ver lista de Alumnos POR CARRERAS"<<endl<<endl;
            cout<<"Opcion: ";
            cin>>aux4;
            system("cls");
            switch (aux4){
            default:
                cout<<"Ha ingresado una opcion no valida!\n\n";
            case 1:
                mostrarTodo();
                break;
            case 2:
                ascendenteEstudiantes();
                break;
            case 3:
                descendenteEstudiantes();
                break;
            case 4:
                ascendenteProfesores();
                break;
            case 5:
                descendenteProfesores();
                break;
            case 6:
                ordenarPorCarreras();
            }
            //matricular estudiantes
            break;
        case 5:
            int aux5;
            cout<<endl<<"ELIJA A QUIEN DESEA BUSCAR:"<<endl<<endl;
            cout<<"1. Estudiante"<<endl<<endl;
            cout<<"2. Profesor"<<endl<<endl;
            cout<<"3. Salir"<<endl<<endl;
            cout<<"Opcion: ";
            cin>>aux5;
            system("cls");
            switch (aux5){
            default:
                cout<<"Ha ingresado una opcion no valida!\n\n";
            case 1:
                buscarEstudiante();
                break;
            case 2:
                system("cls");
                char y[40];
                cout<<"Ingrese el nombre del profesor que desea buscar: ";
                cin>>y;
                for (int i=0;i<profes.size();i++){
                    if (substring(profes[i]->getNombre(),y)==1){
                        buscarProfesor(profes[i]);
                    }
                    else
                        cout<<"No se encontró a nadie con ese nombre"<<endl;
                }
                break;
            }
            break;
        case 6:
            break;
        }
    }
    while(opcion!=6);
}
void Institucion::ascendenteEstudiantes(){
    vector <string> lista;
    char t[40];
    for (int i=0;i<students.size();i++){
        strcpy(t,students[i]->getNombre());
        lista.push_back(t);
    }
    sort(lista.begin(), lista.end());
    for (string &s : lista)
        cout<<s<<"\n";
    cout<<endl<<endl;
    pausa();
}
void Institucion::descendenteEstudiantes(){
    vector <string> lista;
    char t[40];
    for (int i=0;i<students.size();i++){
        strcpy(t,students[i]->getNombre());
        lista.push_back(t);
    }
    sort(lista.begin(), lista.end());
    reverse(lista.begin(),lista.end());
    for (string &s: lista)
        cout<<s<<"\n";
    cout<<endl<<endl;
    pausa();
}
void Institucion::ascendenteProfesores(){
    vector <string> lista;
    char t[40];
    for (int i=0;i<profes.size();i++){
        strcpy(t,profes[i]->getNombre());
        lista.push_back(t);
    }
    sort(lista.begin(), lista.end());
    for (string &s : lista)
        cout<<s<<"\n";
    cout<<endl<<endl;
    pausa();
}
void Institucion::descendenteProfesores(){
    vector <string> lista;
    char t[40];
    for (int i=0;i<profes.size();i++){
        strcpy(t,profes[i]->getNombre());
        lista.push_back(t);
    }
    sort(lista.begin(), lista.end());
    reverse(lista.begin(),lista.end());
    for (string &s: lista)
        cout<<s<<"\n";
    cout<<endl<<endl;
    pausa();
}
void Institucion::ordenarPorCarreras(){
    cout<<"Ciencia de la Computacion: "<<endl;
    cout<<"________________________________________________"<<endl<<endl;
    for (int i=0;i<students.size();i++){
        char b[50]="Ciencia de la Computacion";
        char a[50];
        strcpy(a,students[i]->getCarrera());
        if (substring(a,b)){
            cout<<students[i]->getNombre()<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    cout<<"Ingenieria Industrial:"<<endl;
    cout<<"________________________________________________"<<endl<<endl;
    for (int i=0;i<students.size();i++){
        char b[50]="Ingenieria Industrial";
        char a[50];
        strcpy(a,students[i]->getCarrera());
        if (substring(a,b)){
            cout<<students[i]->getNombre()<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    cout<<"Ingenieria Civil"<<endl;
    cout<<"________________________________________________"<<endl<<endl;
    for (int i=0;i<students.size();i++){
        char b[50]="Ingenieria Civil";
        char a[50];
        strcpy(a,students[i]->getCarrera());
        if (substring(a,b)){
            cout<<students[i]->getNombre()<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    cout<<"Psicologia"<<endl;
    cout<<"________________________________________________"<<endl<<endl;
    for (int i=0;i<students.size();i++){
        char b[50]="Psicologia";
        char a[50];
        strcpy(a,students[i]->getCarrera());
        if (substring(a,b)){
            cout<<students[i]->getNombre()<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    cout<<"Educacion"<<endl;
    cout<<"________________________________________________"<<endl<<endl;
    for (int i=0;i<students.size();i++){
        char b[50]="Educacion";
        char a[50];
        strcpy(a,students[i]->getCarrera());
        if (substring(a,b)){
            cout<<students[i]->getNombre()<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    cout<<"Derecho"<<endl;
    cout<<"________________________________________________"<<endl<<endl;
    for (int i=0;i<students.size();i++){
        char b[50]="Derecho";
        char a[50];
        strcpy(a,students[i]->getCarrera());
        if (substring(a,b)){
            cout<<students[i]->getNombre()<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    cout<<"Contabilidad"<<endl;
    cout<<"________________________________________________"<<endl<<endl;
    for (int i=0;i<students.size();i++){
        char b[50]="Contabilidad";
        char a[50];
        strcpy(a,students[i]->getCarrera());
        if (substring(b,a)){
            cout<<students[i]->getNombre()<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    cout<<"Administracion de Negocios"<<endl;
    cout<<"________________________________________________"<<endl<<endl;
    for (int i=0;i<students.size();i++){
        char b[50]="Administracion de Negocios";
        char a[50];
        strcpy(a,students[i]->getCarrera());
        if (substring(a,b)){
            cout<<students[i]->getNombre()<<endl;
        }
    }

    cout<<"Ingenieria Electronica y de Telecomunicaciones"<<endl;
    cout<<"________________________________________________"<<endl<<endl;
    for (int i=0;i<students.size();i++){
        char b[50]="Ingenieria Electronica y de Telecomunicaciones";
        char a[50];
        strcpy(a,students[i]->getCarrera());
        if (substring(a,b)){
            cout<<students[i]->getNombre()<<endl;
        }
    }
    cout<<endl<<endl<<endl;
    pausa();
}
void Institucion::mostrarTodo(){

    cout<<"Estudiantes matriculados en la Institucion:"<<endl<<endl;
    for (int i=0;i<students.size();i++){
        cout<<students[i]->getNombre()<<endl;
        cout<<students[i]->getEmail()<<endl;
        cout<<students[i]->getCarrera()<<endl;
        cout<<endl<<endl;
    }
    cout<<endl<<endl;
    cout<<"Profesores pertenecientes a la Institucion:"<<endl<<endl;
    for (int i=0;i<profes.size();i++){
        cout<<profes[i]->getNombre()<<endl;
        cout<<profes[i]->getEmail()<<endl;
        cout<<profes[i]->getCursos()<<endl;
        cout<<endl<<endl;
    }
    pausa();
}

void Institucion::crearEstudiante(){
    ofstream escritura;
    ifstream verificador;
    char auxID[10];
    Estudiante* test;
    bool coincidencia=false;
    verificador.open("Estudiantes.txt",ios::in);
    escritura.open("Estudiantes.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<endl<<"Matricular Estudiante"<<endl<<endl;
        cout<<"______________________________________________________________________________________________"<<endl<<endl<<endl;
        fflush(stdin);
        cout<<"Ingresa el ID del estudiante: ";
        cin.getline(auxID,10);
        if(strcmp(auxID,"")==0)
            do{
                cout<<"ID de estudiante invalido, intentalo nuevamente: ";
                cin.getline(auxID,10);
            }
            while(strcmp(auxID,"")==0);
        do{
            verificador.seekg(0);
            verificador>>test->getID();
            while(!verificador.eof())
            {
                verificador>>test->getNombre()>>test->getEdad()>>test->getEmail()>>test->getCarrera();

                if(strcmp(test->getID(),auxID)==0)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un estudiante con ese ID!\n\n";
                    cout<<"El estudiante con ese ID es: "<<test->getNombre()<<"\n\n";
                    cout<<"Ingresa un ID valido!: ";
                    cin.getline(auxID,10);
                    if(strcmp(auxID,"")==0)
                        do{
                            cout<<"\nID de estudiante no valido!, intentalo nuevamente: ";
                            cin.getline(auxID,10);
                        }
                        while(strcmp(auxID,"")==0);

                    break;
                }
                verificador>>test->getID();
            }
            if(verificador.eof()&&strcmp(auxID,test->getID())!=0)
                coincidencia=false;
        }
        while(coincidencia==true);
        system("cls");
        strcpy(test->getID(),auxID);
        cout<<endl<<"Matricular Estudiante"<<endl<<endl;
        cout<<"_______________________________________________________________________________________"<<endl<<endl;

        cout<<"Ingresa el ID del estudiante: ";
        cout<<test->getID();
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre completo del estudiante empezando por el apellido: ";
        char auxNombre[40];
        cin.getline(auxNombre,40);
        test->setNombre(auxNombre);
        cout<<"\n";
        fflush(stdin);
        cout<<"Ingresa la edad del estudiante: ";
        char auxEdad[3];
        cin.getline(auxEdad,3);
        test->setEdad(auxEdad);
        cout<<"\n";
        fflush(stdin);
        cout<<"Ingresa el correo electronico del estudiante: ";
        char auxEmail[30];
        cin.getline(auxEmail,30);
        test->setEmail(auxEmail);
        cout<<"\n\n";
        fflush(stdin);
        int aux;
        cout<<"Elija la carrera del estudiante: "<<endl;
        cout<<"________________________________________________________"<<endl<<endl;
        cout<<"\t1. Ciencia de la Computacion"<<endl<<endl;
        cout<<"\t2. Ingenieria Industrial"<<endl<<endl;
        cout<<"\t3. Ingenieria Civil"<<endl<<endl;
        cout<<"\t4. Psicologia"<<endl<<endl;
        cout<<"\t5. Derecho"<<endl<<endl;
        cout<<"\t6. Educacion"<<endl<<endl;
        cout<<"\t7. Contabilidad"<<endl<<endl;
        cout<<"\t8. Ingenieria Electronica y de Telecomunicaciones"<<endl<<endl;
        cout<<"\t9. Administracion de Negocios"<<endl<<endl;
        cout<<"________________________________________________________"<<endl<<endl;

        cout<<"Opcion: ";
        cin>>aux;
        switch(aux)
        {
        default:
            cout<<"Ha ingresado una opcion no valida!\n\n";
            break;
        case 1:
            test->setCarrera("Ciencia de la Computacion");

            break;
        case 2:
            test->setCarrera("Ingenieria Industrial");

            break;
        case 3:
            test->setCarrera("Ingenieria Civil");

            break;
        case 4:
            test->setCarrera("Psicologia");

            break;
        case 5:
            test->setCarrera("Derecho");

            break;
        case 6:
            test->setCarrera("Educacion");

            break;
        case 7:
            test->setCarrera("Contabilidad");

            break;
        case 8:
            test->setCarrera("Ingenieria Electronica y de Telecomunicaciones");

            break;
        case 9:
            test->setCarrera("Administracion de Negocios");

            break;
        }
        students.push_back(test);
        numEst++;
        escritura<<test->getID()<<"\n\n"<<test->getNombre()<<"\n\n"<<test->getEdad()<<"\n\n"<<test->getEmail()<<"\n\n"<<test->getCarrera()<<"\n\n";
        cout<<endl<<endl<<"La matricula se ha completado correctamente.\n\n";
    }

    else
    {
        error();
    }
    escritura.close();
    verificador.close();
    pausa();
}
void Institucion::crearProfesor(){
    ofstream escritura;
    ifstream verificador;
    char auxID[10];
    Profesor* test;
    bool coincidencia=false;
    verificador.open("Profesores.txt",ios::in);
    escritura.open("Profesores.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"Ingresar Profesor"<<endl<<endl;
        cout<<"______________________________________________________________________________________________"<<endl<<endl<<endl;
        fflush(stdin);
        cout<<"Ingresa el ID del profesor: ";
        cin.getline(auxID,10);
        if(strcmp(auxID,"")==0)
            do{
                cout<<"ID de profesor invalido, intentalo nuevamente: ";
                cin.getline(auxID,10);
            }
            while(strcmp(auxID,"")==0);
        do{
            verificador.seekg(0);
            verificador>>test->getID();
            while(!verificador.eof())
            {
                verificador>>test->getNombre()>>test->getEdad()>>test->getEmail()>>test->getCursos();
                if(strcmp(test->getID(),auxID)==0)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un profesor con ese ID!\n\n";
                    cout<<"El profesor con ese ID es: "<<test->getNombre()<<"\n\n";
                    cout<<"Ingresa un ID valido!: ";
                    cin.getline(auxID,10);
                    if(strcmp(auxID,"")==0)
                        do{
                            cout<<"\nID de profesor no valido!, intentalo nuevamente: ";
                            cin.getline(auxID,10);
                        }
                        while(strcmp(auxID,"")==0);

                    break;
                }
                verificador>>test->getID();
            }
            if(verificador.eof()&&strcmp(auxID,test->getID())!=0)
                coincidencia=false;
        }
        while(coincidencia==true);
        system("cls");
        strcpy(test->getID(),auxID);
        cout<<endl<<"Ingresar Profesor"<<endl<<endl;
        cout<<"______________________________________________________________________________________________"<<endl<<endl<<endl;

        cout<<"Ingresa el ID del estudiante: ";
        cout<<test->getID();
        cout<<"\n\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre completo del profesor empezando por el apellido: ";
        char auxNombre[40];
        cin.getline(auxNombre,40);
        test->setNombre(auxNombre);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la edad del profesor: ";
        char auxEdad[3];
        cin.getline(auxEdad,3);
        test->setEdad(auxEdad);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el correo electronico del profesor: ";
        char auxEmail[30];
        cin.getline(auxEmail,30);
        test->setEmail(auxEmail);
        cout<<"\n\n";
        fflush(stdin);
        int aux;
        cout<<"Elija el curso que dictara el profesor: "<<endl<<endl;

        cout<<"________________________________________________________"<<endl<<endl;
        cout<<"\t1. Matematica"<<endl<<endl;
        cout<<"\t2. Comunicacion"<<endl<<endl;
        cout<<"\t3. Quimica"<<endl<<endl;
        cout<<"\t4. Historia"<<endl<<endl;
        cout<<"\t5. Filosofia"<<endl<<endl;
        cout<<"\t6. Gestion"<<endl<<endl;
        cout<<"\t7. Programacion"<<endl<<endl;
        cout<<"\t8. Topografia"<<endl<<endl;
        cout<<"\t9. Metodologia del Estudio"<<endl<<endl;
        cout<<"\t10. Estadística"<<endl<<endl;
        cout<<"\t11. Macroeconomia"<<endl<<endl;
        cout<<"\t12. Psicologia del Aprendizaje"<<endl<<endl;
        cout<<"\t13. Personalidad"<<endl<<endl;
        cout<<"\t14. Arquitectura de Computadoras"<<endl<<endl;
        cout<<"\t15. Derecho Procesal Penal"<<endl<<endl;
        cout<<"________________________________________________________"<<endl<<endl;

        cout<<"Opcion: ";
        cin>>aux;

        //setcurso del profe switch simple
        //del los alumnos es un getline y buscas numeros y vas asignando con el switch

        switch(aux)
        {
        default:
            cout<<"Ha ingresado una opcion no valida!\n\n";
            break;
        case 1:
            test->setCursos("Matematica");
            break;
        case 2:
            test->setCursos("Comunicacion");
            break;
        case 3:
            test->setCursos("Quimica");
            break;
        case 4:
            test->setCursos("Historia");
            break;
        case 5:
            test->setCursos("Filosofia");
            break;
        case 6:
            test->setCursos("Gestion");
            break;
        case 7:
            test->setCursos("Programacion");
            break;
        case 8:
            test->setCursos("Topografia");
            break;
        case 9:
            test->setCursos("Metodologia del Estudio");
            break;
        case 10:
            test->setCursos("Estadística");
            break;
        case 11:
            test->setCursos("Macroeconomia");
            break;
        case 12:
            test->setCursos("Psicologia del Aprendizaje");
            break;
        case 13:
            test->setCursos("Personalidad");
            break;
        case 14:
            test->setCursos("Arquitectura de Computadoras");
            break;
        case 15:
            test->setCursos("Derecho Procesal Penal");
            break;
        }

        profes.push_back(test);
        numProf++;
        escritura<<test->getID()<<"\n\n"<<test->getNombre()<<"\n\n"<<test->getEdad()<<"\n\n"<<test->getEmail()<<"\n\n"<<test->getCursos();
        cout<<endl<<endl<<"Se ha ingresado correctamente al profesor.\n\n";
    }
    else
    {
        error();
    }
    escritura.close();
    verificador.close();
    pausa();
}
void Institucion::modificarEstudiante(){
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    Estudiante *test;
    char auxID[10];
    char IDMod[10];
    char auxNombre[40];
    char auxEdad[3];
    char auxEmail[30];
    char auxCarrera[50];
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    char bu[10];
    strcpy(bu,test->getID());
    lectura.open("Estudiantes.txt",ios::in);
    verificador.open("Estudiantes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"Modificar datos de un Estudiante"<<endl<<endl;
    cout<<"______________________________________________________________________________________________"<<endl<<endl<<endl;

    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el ID del estudiante que deseas modificar: ";
        cin.getline(auxID,10);
        for (int i=0;i<students.size();i++){
            if (auxID==students[i]->getNombre())
                test=students[i];
        }
        if(strcmp(auxID,"")==0){
            do{
                cout<<"ID de estudiante no valido!, intentalo nuevamente: ";
                cin.getline(auxID,3);
            }
            while(strcmp(auxID,"")==0);
        }
        strcpy(IDMod,auxID);
        lectura>>test->getID();
        while(!lectura.eof())
        {
            lectura>>test->getNombre()>>test->getEdad()>>test->getEmail()>>test->getCarrera();
            if(strcmp(auxID,test->getID())==0)
            {
                encontrado=true;
                mostrarRegistro(IDMod);

                cout<<"\n\n";
                cout<<"Ingresa la nueva informacion para el Estudiante\n\n";
                fflush(stdin);
                cout<<"Ingresa el ID del Estudiante: ";
                cin.getline(auxID,10);
                if(strcmp(auxID,IDMod)==0){
                    mismoCodigo=true;
                }
                if(mismoCodigo==false){
                    do
                    {
                        if(strcmp(auxID,IDMod)==0){
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        verificador>>test->getID();
                        while(!verificador.eof())
                        {
                            verificador>>test->getNombre()>>test->getEdad()>>test->getEmail()>>test->getCarrera();
                            if(strcmp(bu,auxID)==0)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un estudiante con ese ID!\n\n";
                                cout<<"El estudiante con ese ID es: "<<test->getNombre()<<"\n\n";
                                cout<<"Ingresa un ID valido!: ";
                                cin.getline(auxID,10);

                                if(strcmp(auxID,"")==0){
                                    do{
                                        cout<<"ID de estudiante no valido!, intentalo nuevamente: ";
                                        cin.getline(auxID,10);
                                    }
                                    while(strcmp(auxID,"")==0);
                                }
                                break;
                            }
                            verificador>>test->getID();
                        }
                        if(verificador.eof()&&strcmp(auxID,test->getID())!=0){
                            coincidencia=false;
                        }
                    }
                    while(coincidencia==true);
                }
                system("cls");
                cout<<"Modificar datos de un Estudiante"<<endl<<endl;
                cout<<"______________________________________________________________________________________________"<<endl<<endl<<endl;
                cout<<"Ingresa el ID del estudiante que deseas modificar: ";
                cout<<IDMod;
                mostrarRegistro(IDMod);
                cout<<endl<<endl;
                cout<<"Ingresa la nueva informacion para el Estudiante\n\n";

                cout<<"Ingresa el ID del Estudiante: ";
                cout<<auxID;
                fflush(stdin);
                cout<<endl<<endl<<"Ingresa el nombre completo del estudiante empezando por el apellido: ";
                cin.getline(auxNombre,40);
                test->setNombre(auxNombre);
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa la edad del estudiante: ";
                cin.getline(auxEdad,3);
                test->setEdad(auxEdad);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el email del estudiante: ";
                cin.getline(auxEmail,30);
                test->setEmail(auxEmail);
                cout<<"\n\n";
                fflush(stdin);

                int aux;
                cout<<"Elija la carrera del estudiante: "<<endl;
                cout<<"________________________________________________________"<<endl<<endl;
                cout<<"\t1. Ciencia de la Computacion"<<endl<<endl;
                cout<<"\t2. Ingenieria Industrial"<<endl<<endl;
                cout<<"\t3. Ingenieria Civil"<<endl<<endl;
                cout<<"\t4. Psicologia"<<endl<<endl;
                cout<<"\t5. Derecho"<<endl<<endl;
                cout<<"\t6. Educacion"<<endl<<endl;
                cout<<"\t7. Contabilidad"<<endl<<endl;
                cout<<"\t8. Ingenieria Electronica y de Telecomunicaciones"<<endl<<endl;
                cout<<"\t9. Administracion de Negocios"<<endl<<endl;
                cout<<"________________________________________________________"<<endl<<endl;

                cout<<"Opcion: ";
                cin>>aux;
                switch(aux)
                {
                default:
                    cout<<"Ha ingresado una opcion no valida!\n\n";
                    break;
                case 1:
                    test->setCarrera("Ciencia de la Computacion");

                    break;
                case 2:
                    test->setCarrera("Ingenieria Industrial");

                    break;
                case 3:
                    test->setCarrera("Ingenieria Civil");
                    break;
                case 4:
                    test->setCarrera("Psicologia");
                    break;
                case 5:
                    test->setCarrera("Derecho");
                    break;
                case 6:
                    test->setCarrera("Educacion");
                    break;
                case 7:
                    test->setCarrera("Contabilidad");
                    break;
                case 8:
                    test->setCarrera("Ingenieria Electronica y de Telecomunicaciones");
                    break;
                case 9:
                    test->setCarrera("Administracion de Negocios");
                    break;
                }
                auxiliar<<auxID<<"\n\n"<<auxNombre<<"\n\n"<<auxEdad<<"\n\n"<<auxEmail<<"\n\n"<<auxCarrera<<"\n\n";
                cout<<"El estudiante se ha modificado correctamente.\n\n";

            }
            else
            {
                auxiliar<<test->getID()<<"\n\n"<<test->getNombre()<<"\n\n"<<test->getEdad()<<"\n\n"<<test->getEmail()<<"\n\n"<<test->getCarrera()<<"\n\n";
            }
            lectura>>test->getID();
        }
    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontro ningun estudiante con ese ID!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("Estudiantes.txt");
    rename("auxiliar.txt","Estudiantes.txt");
    pausa();
}
void Institucion::modificarProfesor(){
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    Profesor *test;
//
    char auxID[10];
    char IDMod[10];
    char auxNombre[40];
    char auxEdad[3];
    char auxEmail[30];
    char auxCurso[50];
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    char bu[10];
    strcpy(bu,test->getID());
    lectura.open("Profesores.txt",ios::in);
    verificador.open("Profesores.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"Modificar datos de un Profesor"<<endl<<endl;
    cout<<"______________________________________________________________________________________________"<<endl<<endl<<endl;

    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el ID del profesor que deseas modificar: ";
        cin.getline(auxID,10);
        for (int i=0;i<profes.size();i++){
            if (auxID==profes[i]->getNombre())
                test=profes[i];
        }
        if(strcmp(auxID,"")==0){
            do{
                cout<<"ID de profesor no valido!, intentalo nuevamente: ";
                cin.getline(auxID,30);
            }
            while(strcmp(auxID,"")==0);
        }
        strcpy(IDMod,auxID);
        lectura>>test->getID();
        while(!lectura.eof())
        {
            lectura>>test->getNombre()>>test->getEdad()>>test->getEmail()>>test->getCursos();
            if(strcmp(auxID,test->getID())==0)
            {
                encontrado=true;
                mostrarRegistro(IDMod);

                cout<<"\n\n";
                cout<<"Ingresa la nueva informacion para el Profesor\n\n";
                fflush(stdin);
                cout<<"Ingresa el ID del Profesor: ";
                cin.getline(auxID,10);
                if(strcmp(auxID,IDMod)==0){
                    mismoCodigo=true;
                }
                if(mismoCodigo==false){
                    do
                    {
                        if(strcmp(auxID,IDMod)==0){
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        verificador>>test->getID();
                        while(!verificador.eof())
                        {
                            verificador>>test->getNombre()>>test->getEdad()>>test->getEmail()>>test->getCursos();
                            if(strcmp(bu,auxID)==0)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un profesor con ese ID!\n\n";
                                cout<<"El profesor con ese ID es: "<<test->getNombre()<<"\n\n";
                                cout<<"Ingresa un ID valido!: ";
                                cin.getline(auxID,10);

                                if(strcmp(auxID,"")==0){
                                    do{
                                        cout<<"ID de profesor no valido!, intentalo nuevamente: ";
                                        cin.getline(auxID,10);
                                    }
                                    while(strcmp(auxID,"")==0);
                                }
                                break;
                            }
                            verificador>>test->getID();
                        }
                        if(verificador.eof()&&strcmp(auxID,test->getID())!=0){
                            coincidencia=false;
                        }
                    }
                    while(coincidencia==true);
                }
                system("cls");
                cout<<"Modificar datos de un Profesor"<<endl<<endl;
                cout<<"______________________________________________________________________________________________"<<endl<<endl<<endl;
                cout<<"Ingresa el ID del profesor que deseas modificar: ";
                cout<<IDMod;
                mostrarRegistro(IDMod);
                cout<<endl<<endl;
                cout<<"Ingresa la nueva informacion para el Profesor\n\n";

                cout<<"Ingresa el ID del Profesor: ";
                cout<<auxID;
                fflush(stdin);
                cout<<endl<<endl<<"Ingresa el nombre completo del profesor empezando por el apellido: ";
                cin.getline(auxNombre,40);
                test->setNombre(auxNombre);
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa la edad del Profesor: ";
                cin.getline(auxEdad,3);
                test->setEdad(auxEdad);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el email del Profesor: ";
                cin.getline(auxEmail,30);
                test->setEmail(auxEmail);
                cout<<"\n\n";
                fflush(stdin);

                int aux;
                cout<<"Elija el curso que dictara el profesor: "<<endl<<endl;
                cout<<"________________________________________________________"<<endl<<endl;
                cout<<"\t1. Matematica"<<endl<<endl;
                cout<<"\t2. Comunicacion"<<endl<<endl;
                cout<<"\t3. Quimica"<<endl<<endl;
                cout<<"\t4. Historia"<<endl<<endl;
                cout<<"\t5. Filosofia"<<endl<<endl;
                cout<<"\t6. Gestion"<<endl<<endl;
                cout<<"\t7. Programacion"<<endl<<endl;
                cout<<"\t8. Topografia"<<endl<<endl;
                cout<<"\t9. Metodologia del Estudio"<<endl<<endl;
                cout<<"\t10. Estadística"<<endl<<endl;
                cout<<"\t11. Macroeconomia"<<endl<<endl;
                cout<<"\t12. Psicologia del Aprendizaje"<<endl<<endl;
                cout<<"\t13. Personalidad"<<endl<<endl;
                cout<<"\t14. Arquitectura de Computadoras"<<endl<<endl;
                cout<<"\t15. Derecho Procesal Penal"<<endl<<endl;
                cout<<"________________________________________________________"<<endl<<endl;

                cout<<"Opcion: ";
                cin>>aux;
                switch(aux)
                {
                default:
                    cout<<"Ha ingresado una opcion no valida!\n\n";
                    break;
                case 1:
                    test->setCursos("Matematica");
                    break;
                case 2:
                    test->setCursos("Comunicacion");
                    break;
                case 3:
                    test->setCursos("Quimica");
                    break;
                case 4:
                    test->setCursos("Historia");
                    break;
                case 5:
                    test->setCursos("Filosofia");
                    break;
                case 6:
                    test->setCursos("Gestion");
                    break;
                case 7:
                    test->setCursos("Programacion");
                    break;
                case 8:
                    test->setCursos("Topografia");
                    break;
                case 9:
                    test->setCursos("Metodologia del Estudio");
                    break;
                case 10:
                    test->setCursos("Estadística");
                    break;
                case 11:
                    test->setCursos("Macroeconomia");
                    break;
                case 12:
                    test->setCursos("Psicologia del Aprendizaje");
                    break;
                case 13:
                    test->setCursos("Personalidad");
                    break;
                case 14:
                    test->setCursos("Arquitectura de Computadoras");
                    break;
                case 15:
                    test->setCursos("Derecho Procesal Penal");
                    break;
                }
                auxiliar<<auxID<<"\n\n"<<auxNombre<<"\n\n"<<auxEdad<<"\n\n"<<auxEmail<<"\n\n"<<auxCurso<<"\n\n";
                cout<<"El profesor se ha modificado correctamente.\n\n";
            }
            else
            {
                auxiliar<<test->getID()<<"\n\n"<<test->getNombre()<<"\n\n"<<test->getEdad()<<"\n\n"<<test->getEmail()<<"\n\n"<<test->getCursos()<<"\n\n";
            }
            lectura>>test->getID();
        }
    }
    else{
        error();
    }

    if(encontrado==false){
        cout<<"\n\nNo se encontro ningun profesor con ese ID!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("Profesores.txt");
    rename("auxiliar.txt","Profesores.txt");
    pausa();
}
void Institucion::eliminarEstudiante(){
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    char auxID[10];
    char respuesta[5];
    Estudiante* test;
    lectura.open("Estudiantes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"Eliminar a un estudiante de la Institucion";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el ID del estudiante que deseas eliminar: ";
        cin.getline(auxID,10);
        lectura>>test->getID();
        while(!lectura.eof())
        {
            lectura>>test->getNombre()>>test->getEdad()>>test->getEmail()>>test->getCarrera();
            if(strcmp(auxID,test->getID())==0)
            {

                encontrado=true;
                cout<<"\n\Estudiante Encontrado\n\n";
                cout<<"ID: "<<test->getID()<<endl;
                cout<<"Nombre: "<<test->getNombre()<<endl;
                cout<<"Edad: "<<test->getEdad()<<endl;
                cout<<"Email: "<<test->getEmail()<<endl;
                cout<<"Carrera: "<<test->getCarrera()<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas eliminar a: "<<test->getNombre()<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0|| strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0|| strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0){
                    cout<<"\n\nEl estudiante se ha eliminado correctamente\n\n";
                    numEst--;
                    for (int i=0;i<students.size();i++){
                        if (students[i]->getNombre()==auxID)
                            students.erase(students.begin()+i);
                    }
                }
                else{
                    cout<<"\n\nEstudiante conservado\n\n";
                    auxiliar<<test->getID()<<"\n\n"<<test->getNombre()<<"\n\n"<<test->getEdad()<<"\n\n"<<test->getEmail()<<"\n\n"<<test->getCarrera()<<"\n\n";
                }
            }
            else{
                auxiliar<<test->getID()<<"\n\n"<<test->getNombre()<<"\n\n"<<test->getEdad()<<"\n\n"<<test->getEmail()<<"\n\n"<<test->getCarrera()<<"\n\n";
            }
            lectura>>test->getID();
        }
        if(encontrado==false){
            cout<<"\n\nNo se encontro el ID: "<<test->getID()<<"\n\n";
        }
    }
    else{
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Estudiantes.txt");
    rename("auxiliar.txt","Estudiantes.txt");
    pausa();
}
void Institucion::eliminarProfesor(){
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    char auxID[10];
    char respuesta[5];
    Profesor* test;
    lectura.open("Profesores.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"Eliminar a un profesor de la Institucion"<<endl<<endl;
    if(lectura.is_open()&&auxiliar.is_open()){
        fflush(stdin);
        cout<<"Ingresa el ID del profesor que deseas eliminar: ";
        cin.getline(auxID,10);
        lectura>>test->getID();
        while(!lectura.eof())
        {
            lectura>>test->getNombre()>>test->getEdad()>>test->getEmail()>>test->getCursos();
            if(strcmp(auxID,test->getID())==0)
            {
                encontrado=true;
                cout<<"\n\Profesor Encontrado\n\n";
                cout<<"ID: "<<test->getID()<<endl;
                cout<<"Nombre: "<<test->getNombre()<<endl;
                cout<<"Edad: "<<test->getEdad()<<endl;
                cout<<"Email: "<<test->getEmail()<<endl;
                cout<<"Carrera: "<<test->getCursos()<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas eliminar a: "<<test->getNombre()<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0|| strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0|| strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0){
                    cout<<"\n\nEl profesor se ha eliminado correctamente\n\n";
                    numProf--;
                    for (int i=0;i<profes.size();i++){
                        if (profes[i]->getNombre()==auxID)
                            profes.erase(profes.begin()+i);
                    }
                }
                else{
                    cout<<"\n\nProfesor conservado\n\n";
                    auxiliar<<test->getID()<<"\n\n"<<test->getNombre()<<"\n\n"<<test->getEdad()<<"\n\n"<<test->getEmail()<<"\n\n"<<test->getCursos()<<"\n\n";
                }
            }
            else{
                auxiliar<<test->getID()<<"\n\n"<<test->getNombre()<<"\n\n"<<test->getEdad()<<"\n\n"<<test->getEmail()<<"\n\n"<<test->getCursos()<<"\n\n";
            }
            lectura>>test->getID();
        }
        if(encontrado==false){
            cout<<"\n\nNo se encontro el ID: "<<test->getID()<<"\n\n";
        }
    }
    else{
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("Profesores.txt");
    rename("auxiliar.txt","Profesores.txt");
    pausa();
}
void Institucion::buscarProfesor(Profesor* x){
    cout<<"Se encontró a los siguientes profesores: "<<endl<<endl;
    cout<<"Nombre: "<<x->getNombre()<<endl;
    cout<<"Edad: "<<x->getEdad()<<endl;
    cout<<"Email: "<<x->getEmail()<<endl;
    cout<<"Curso: "<<x->getCursos()<<endl;
    cout<<endl<<endl;
}
void Institucion::mostrarRegistro(char t[10])
{
    ifstream mostrar;
    for (int i=0;i<students.size();i++){
        if(students[i]->getID() == t){
            mostrar.open("Estudiantes.txt",ios::in);
            mostrar>>students[i]->getID();
            while(!mostrar.eof())
            {
                mostrar>>students[i]->getNombre()>>students[i]->getEdad()>>students[i]->getEmail()>>students[i]->getCarrera();
                if(strcmp(t,students[i]->getID())==0)
                {
                    cout<<"\n\nRegistro Encontrado\n\n";
                    cout<<"ID: "<<students[i]->getID()<<endl;
                    cout<<"Nombre: "<<students[i]->getNombre()<<endl;
                    cout<<"Edad: "<<students[i]->getEdad()<<endl;
                    cout<<"Email: "<<students[i]->getEmail()<<endl;
                    cout<<"Carrera: "<<students[i]->getCarrera()<<endl;
                    cout<<"\n\n";
                }
                mostrar>>students[i]->getID();
            }
            mostrar.close();
        }
    }
}






/*--------universidad.cpp---------*/









