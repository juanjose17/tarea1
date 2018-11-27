#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;
//class .h
class persona{
    public:
        string nombre;
        string apellido;
        string email;

        persona();
        string get_name();
        string get_apellido();
        string get_email();
        void set_name(string x);
        void set_apellido(string x);
        void set_email(string x);

        virtual string get_materia();
        virtual ~persona();

};

class estudiante:public persona{
    protected:
        string grado;
        string materia;
    public:
        estudiante();
        virtual ~estudiante();
        string get_grado();
        void set_grado(string x);
        string get_materia();
}studentData;

class profesor:public persona{
    public:
        string materia;
        profesor();
        virtual ~profesor();
        string get_materia();
}tech;

class Materia{
protected:
        char nombre[30];
    public:
        Materia();
        virtual ~Materia();
        char* get_nombre();
        void set_nombre(char t[30]);
};
//class   .cpp
persona::persona(){}
persona::~persona(){}
string persona::get_name(){return nombre;}
string persona::get_apellido(){return apellido;}
string persona::get_email(){return email;}

void persona::set_name(string x){
    nombre=x;
}
void persona::set_email(string x){
    email=x;
}
void persona::set_apellido(string x){
    apellido=x;
}

string persona::get_materia(){
    cout<<"materias de colegio que cualquier persona hace"<<endl;
}



estudiante::estudiante(){}
estudiante::~estudiante(){
    //dtor
}
string estudiante::get_grado(){
    return grado;
}
void estudiante::set_grado(string x){
    grado=x;
}
string estudiante::get_materia(){
    return materia;
}
ostream& operator<<(ostream &output, estudiante &o){
    output<<"nombre: "<<o.get_name()<<"\n email: "<<o.get_email()<<
    "\n grado"<<o.get_grado()<<"\n\n";
    return output;
}

profesor::profesor(){
    //ctor
}
profesor::~profesor(){
    //dtor
}
string profesor::get_materia(){
    std::cout<<"el curso del profe es: "<<std::endl;
    return materia;
}

Materia::Materia(){
    //ctor
}
Materia::~Materia(){
    //dtor
}
char* Materia::get_nombre(){
    return nombre;
}
void Materia::set_nombre(char x[30]){
    strcpy(nombre,x);
}

///////////////////////////////////////////////////
/////////////función principal/////////////////////
///////////////////////////////////////////////////

int main(){
    system ("color 4A");
	int i=0,j; // para el uso de procesamiento
	char choice;// para elegir  "choice"
	string find;// para clasificar
	string srch;

	while(1){// bucle externo

		system("cls");// borrar pantalla

		// Nivel 1-Proceso de visualización
		cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
		cout<<"\n\n\t\t\tDATABASE SCHOOL\n\n";
		cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
		cout<<"\n\n\t\t\tMENU PRINICPAL\n\n";
		cout<<" Ingrese su eleccion: "<<endl;
		cout<<"1. Informacion de los estudiantes"<<endl;
		cout<<"2. Informacion del profesor"<<endl;
		cout<<"3.Exit program"<<endl;
		cin>>choice;//espera a que elige, que opcion quiero estudiante,profesor,salir

		system("cls");// borrar pantalla


		switch(choice)// Primer interruptor
		{
			// Estudiante
		case '1': {

			while(1){ //inner loop-1
				system("cls");// borrar pantalla
				// Pantalla de nivel 2
				cout<<"\t\t\tINFORMACION DE ESTUDIANTES\n\n\n";
				cout<<"Enter your choice: "<<endl;
				cout<<"1.Crear nueva entrada\n";
				cout<<"2.Encuentre y visualice la entrada \n";
				cout<<"3.Jump to main\n";
				cin>>choice;

				switch (choice){
				case '1':{// Insertar datos
					ofstream f1("student.txt",ios::app);


					for( i=0;choice!='N';i++){

						if((choice=='y')||(choice=='Y')||(choice=='1')){
							cout<<" Ingrese Nombre: ";
							cin>>studentData.nombre;
							cout<<" Ingrese edad:  ";
							cin>>studentData.apellido;
							cout<<"Introduzca el correo: ";
							cin>>studentData.email;



						f1<<studentData.nombre<<endl<<
							studentData.apellido<<endl<<
							studentData.email<<endl<<

						cout<<"¿Desea introducir datos:  ";
						cout<<"Presione Y para Continuar y N para finalizar: ";
						cin>>choice;
						}
					}
					f1.close();
				}
				continue;// control de vuelta al -1

				case '2':{// Mostrar datos
				  ifstream f2("student.txt");

				cout<<"Ingrese el nombre que se mostrará: ";
				cin>>find;
				cout<<endl;
				int notFound = 0;
				for( j=0;(j<i)||(!f2.eof());j++){

					getline(f2,studentData.nombre);

					if(studentData.nombre==find){
						notFound = 1;
						cout<<" Nombre: "<<studentData.nombre<<endl;
						cout<<" apellido: "<<studentData.apellido<<endl;

						getline(f2,studentData.email);
						cout<<"Número de email: "<<studentData.email<<endl;
					}
				}

				if(notFound == 0){

					cout<<"No se encontraron registros"<<endl;
				}
				f2.close();
				cout<<"Presione cualquier tecla dos veces para continuar";
				getch();//Para mantener los datos en pantalla
				getch();//Para mantener los datos en pantalla

				}
				continue;// control de vuelta al bucle interno -1

				case '3':// Jump to main
				{
					break;// interruptor interno rompiendo
				}
				}

				break;//ruptura del bucle interno 1
			}
			continue;// Pase de control al 1er bucle

		case '2':// Biodata de profesores
		{
			while(1){// loop interno-2

				system("cls");// borrar pantalla
				// Proceso de visualización de nivel 2
				cout<<"\t\t\tINFORMACION DE PROFESORES\n\n\n";
				cout<<"Ingrese su elección: "<<endl;
				cout<<"1.Crear nueva entrada\n";
				cout<<"2.Encuentre y muestre\n";
				cout<<"3.Jump to main\n";
				cin>>choice;

				switch (choice)// Tercer interruptor
				{
				case '1':// Insertar dato
				{
					ofstream t1("teacher.txt",ios::app);

					for(i=0;choice!='N';i++){

						if((choice=='y')||(choice=='Y')||(choice=='1'))
						{
							cout<<" Ingrese Nombre: ";
							cin>>tech.nombre;
							cout<<"Ingrese Apellido :: ";
							cin>>tech.apellido;
							cout<<" Ingresar correo: ";
							cin>>tech.email;
							cout<<" Ingresar materia que enseña: ";
							cin>>tech.materia;


							t1<<tech.nombre<<endl<<tech.nombre<<endl
                            <<tech.apellido<<endl<<tech.email<<endl<<
                            tech.materia<<endl;
							cout<<"¿Desea introducir datos: ";
							cout<<"Presione Y para Continuar y N para finalizar: ";
							cin>>choice;
						} // si
					}// for bucle
					//fpara encontrar a través del nombre
					system("cls");
					t1.close();
				}// caso 1

				continue;// Control de pase al bucle interno-2

				case '2': // Mostrar datos
				{
					ifstream t2("teacher.txt");

					cout<<" Introduzca el nombre que se mostrará: ";
					cin>>find;
					cout<<endl;
					int notFound = 0;
					for( j=0;((j<i)||(!t2.eof()));j++){
						getline(t2,tech.nombre);
						if(tech.nombre==find)
						{
							notFound = 1;
							cout<<"Nombre: "<<tech.nombre<<endl;
							getline(t2,tech.apellido);
							cout<<"Apellido: "<<tech.apellido<<endl;
							getline(t2,tech.email);
							cout<<"Correo: "<<tech.email<<endl;
							getline(t2,tech.materia);
							cout<<"El sujeto que enseña:"<<tech.materia<<endl;

						}//if

					}//for bucle
					if(notFound == 0){

						cout<<"No se encontraron registros"<<endl;
					}
					t2.close();
					cout<<"Presione cualquier tecla dos veces para continuar ";
					getch();// Para mantener los datos en pantalla
					getch();// Para mantener los datos en pantalla
				}//case 2

				continue;// Control de pase al bucle interno-2

				case '3':// Jump to main
				{
					break;//inner switch
				}//caso 3

				}//inner switch

				break;//inner while
			}//inner loop

			continue;//control pass to 1st loop
		}//outer case 2

		case '3':{
			break;//outer case 3
		}//outer case 3
		}
		break;//outer loop
		}
	}//del bucle
}//del main
