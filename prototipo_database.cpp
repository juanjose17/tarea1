
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

class student
{
	public:
	string fname;
	string lname;
	string Registration;
	string classes;
}studentData;


class teacher
{
	public:
	string fst_name;
	string lst_name;
	string qualification;
	string exp;
	string pay;
	string subj;
	string lec;
	string addrs;
	string cel_no;
	string blod_grp;
	string serves;

}tech[50];

int main()
{

	int i=0,j;
	char choice;
	string find;
	string srch;

	while(1)
	{
		system("cls");//Clear screen

		cout<<"\n\n\t\t\t       SCHOOL DATABASE\n\n";
		cout<<"                         ";
		cout<<"\n\n\t\t\t       MAIN PRINCIPAL \n\n";
		cout<<"Ingrese su eleccion: "<<endl;
		cout<<"1.Informacion de los estudiantes"<<endl;
		cout<<"2.Informacion del maestro"<<endl;
		cout<<"3.Salir programa"<<endl;
		cin>>choice;

		system("cls");


		switch(choice)//First switch
		{

		case '1': //Student
		{
			while(1)
			{
				system("cls");

				cout<<"\t\t\tINFORMACION DE ESTUDIANTES Y SECCIÓN DE DATOS \n\n\n";
				cout<<"Enter your choice: "<<endl;
				cout<<"1.Crear nueva entrada\n";
				cout<<"2.Buscar y mostrar entrada\n";
				cout<<"3.Saltar al main principal\n";
				cin>>choice;

				switch (choice)//Second switch

				{
				case '1'://Insert data
				{  ofstream f1("student.txt",ios::app);

				for( i=0;choice!='n';i++)
				{

					if((choice=='y')||(choice=='Y')||(choice=='1'))
					{
						cout<<"Escribe tu nombre: ";
						cin>>studentData.fname;
						cout<<"Introduzca el apellido: ";
						cin>>studentData.lname;
						cout<<"Introduzca el número de registro:";
						cin>>studentData.Registration;
						cout<<"Entrar en clase: ";
						cin>>studentData.classes;

						f1<<studentData.fname<<endl<<studentData.lname<<endl<<studentData.Registration<<endl<<studentData.classes<<endl;
						cout<<"Quieres seguir introduciendo datos?: ";
						cout<<"Presione Y para Continuar y N para Terminar:  ";
						cin>>choice;
					}
				}
				f1.close();
				}
				continue;

				case '2':
				{  ifstream f2("student.txt");

				cout<<"Introduzca el nombre que se mostrará: ";
				cin>>find;
				cout<<endl;
				int notFound = 0;
				for( j=0;(j<i)||(!f2.eof());j++)
				{

					getline(f2,studentData.fname);

					if(studentData.fname==find)
					{
						notFound = 1;
						cout<<"nombre: "<<studentData.fname<<endl;
						cout<<"apellido: "<<studentData.lname<<endl;

						getline(f2,studentData.Registration);
						cout<<"Número de registro: "<<studentData.Registration<<endl;
						getline(f2,studentData.classes);
						cout<<"Clase: "<<studentData.classes<<endl<<endl;
					}

				}

				if(notFound == 0){

					cout<<"ningún record fue encontrado"<<endl;
				}
				f2.close();
				cout<<"Presiona cualquier tecla dos veces para continuar";
				getch();
				getch();

				}
				continue;

				case '3':
				{
					break;
				}
				}

				break;
			}
			continue;
		}

		case '2'://Teachers biodata
		{
			while(1){
				system("cls");
				cout<<"\t\t\tINFORMACION DE MAESTROS Y SECCION DE DATOS.\n\n\n";
				cout<<"Ingrese su elección: "<<endl;
				cout<<"1.Crear nueva entrada\n";
				cout<<"2.Encontrar y mostrar\n";
				cout<<"3.MAIN PINCIPAL\n";
				cin>>choice;

				switch (choice)
				{
				case '1'://Insert data
				{
					ofstream t1("teacher.txt",ios::app);

					for(i=0;choice!='n'&& choice!='N';i++)
					{

						if((choice=='y')||(choice=='Y')||(choice=='1'))
						{
							cout<<"Escribe tu nombre: ";
							cin>>tech[i].fst_name;
							cout<<"Introduzca el apellido:";
							cin>>tech[i].lst_name;
							cout<<"Ingresar calificaciOn: ";
							cin>>tech[i].qualification;
							cout<<"Introduzca experiencia (aNo): ";
							cin>>tech[i].exp;
							cout<<"Ingrese el número de año en esta escuela: ";
							cin>>tech[i].serves;
							cout<<"Ingrese el tema que enseñan: ";
							cin>>tech[i].subj;
							cout<<"Entrar en clase (por semana): ";
							cin>>tech[i].lec;
							cout<<"Ingrese pago: ";
							cin>>tech[i].pay;
							cout<<"Ingresa número telefónico: ";
							cin>>tech[i].cel_no;
							cout<<"Entrar en el grupo sanguíneo: ";
							cin>>tech[i].blod_grp;


							t1<<tech[i].fst_name<<endl<<tech[i].lst_name<<endl
								<<tech[i].qualification<<endl<<tech[i].exp<<endl
								<<tech[i].serves<<endl<<tech[i].subj<<endl<<tech[i].lec
								<<endl<<tech[i].pay<<endl<<tech[i].cel_no<<endl<<tech[i].blod_grp<<endl;
							cout<<"Desea introducir datos: ";
							cin>>choice;
						}
					}

					system("cls");



					t1.close();
				}

				continue;

				case '2':
				{
					ifstream t2("teacher.txt");

					cout<<"Introduzca el nombre que se mostrará: ";
					cin>>find;

					cout<<endl;
					int notFound = 0;
					for( j=0;((j<i)||(!t2.eof()));j++){

						getline(t2,tech[j].fst_name);

						if(tech[j].fst_name==find)
						{
							notFound = 1;
							cout<<"nombre: "<<tech[j].fst_name<<endl;
							getline(t2,tech[j].lst_name);
							cout<<"apellido: "<<tech[j].lst_name<<endl;
							getline(t2,tech[j].qualification);
							cout<<"calificacion: "<<tech[j].qualification<<endl;
							getline(t2,tech[j].exp);
							cout<<"experiencia: "<<tech[j].exp<<endl;

							getline(t2,tech[j].serves);
							cout<<" Número de años en esta escuela: "<<tech[j].serves<<endl;

							getline(t2,tech[j].subj);
							cout<<"Asunto que enseñan: "<<tech[j].subj<<endl;

							getline(t2,tech[j].lec);
							cout<<"Entrar en clase (por semana): "<<tech[j].lec<<endl;
							getline(t2,tech[j].pay);
							cout<<"pago: "<<tech[j].pay<<endl;

							getline(t2,tech[j].addrs);
							cout<<"direccion: "<<tech[j].addrs<<endl;

							getline(t2,tech[j].cel_no);
							cout<<"numero telefonico: "<<tech[j].cel_no<<endl;

							getline(t2,tech[j].blod_grp);
							cout<<"grupo sanguineo: "<<tech[j].blod_grp<<endl;
						}//if

					}//for loop
					t2.close();
					if(notFound == 0){

						cout<<"ningún record fue encontrado"<<endl;
					}
					cout<<"Presiona cualquier tecla dos veces para continuar";
					getch();//To hold data on screen
					getch();//To hold data on screen
				}//case 2

				continue;//Control pass to inner loop-2

				case '3':{
					break;//inner switch
				}
				}
				break;
				}
			continue;
		}
		case '3':{
		    break;
        }
		}
		break;
	}


}
