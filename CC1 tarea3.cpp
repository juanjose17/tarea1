#include <iostream>
using namespace std;
/*
Arreglo de enteros:
suma				retun int
mayor				return int
contar primos		return int
ordenar asc			return int
ordenar desc		return int
invertir			return int 

tamaño de caracteres    return int
contarcaracteresxveces  return int
siespalindrome		    return bool
*/

int suma(int x[],int tamano){
	int suma=0;
	for(int y=0;y<tamano;y++){
		suma+=x[y];
	}
	return suma;
}
int mayor(int x[],int tamano){
	int mayor=0;
	for(int y=0;y<tamano-1;y++){
		if(x[y]<x[y+1])
			mayor=x[y+1];
	}
	return mayor;
}
bool esprimo(int x,bool esprimo_x=false){
	int primo=0;
	for(int y=1;y<=x;y++)
		(x%y==0)?primo++:primo;
	esprimo_x=(primo<3)?true:false;
	return esprimo_x;
}
int nprimosarreglo(int x[],int tamano){
	int nprimos=0;
	for(int y=0;y<tamano;y++){
		if(esprimo(x[y]))
			nprimos++;
	}
	return nprimos;
}
void ord_dsc(int x[],int tamano){
	int numero=0;
	for(int y=0;y<tamano;y++){
		for(int z=0;z<tamano-1;z++){
			if(x[z]<x[z+1]){
				numero=x[z];
				x[z]=x[z+1];
				x[z+1]=numero;
			}
		}
	}
	for(int y=0;y<tamano;y++){
		cout<<x[y];
		if(y<tamano-1)
			cout<<",";
	}
	cout<<endl;
}
void ord_asc(int x[],int tamano){
	int numero=0;
	for(int y=0;y<tamano;y++){
		for(int z=0;z<tamano-1;z++){
			if(x[z]>x[z+1]){
				numero=x[z];
				x[z]=x[z+1];
				x[z+1]=numero;
			}
		}
	}
	for(int y=0;y<tamano;y++){
		cout<<x[y];
		if(y<tamano-1)
			cout<<",";
	}
	cout<<endl;
}
void invertirarreglo(int x[],int tamano){
	int invertir;
	for(int y=0;y<=tamano/2;y++){
		invertir=x[y];
		x[y]=x[tamano-y-1];
		x[tamano-y-1]=invertir;
	}
	for(int y=0;y<tamano;y++){
		cout<<x[y];
		if(y<tamano-1)
			cout<<",";
	}
	cout<<endl;
}
int tamanoarreglo(char x[]){
	int y;
	for(y=0;x[y]!='\0';y++)
		continue;
	return y;
}
int contarcaracteresxveces(char x[],char xchar){
	int xveces=0;
	for(int y=0;x[y]!='\0';y++){
		if(x[y]==xchar)
			xveces++;
	}
	return xveces;
}
bool siespalindrome(char x[]){
	int tamano=tamanoarreglo(x);
	for(int y=0;y<tamano/2;y++){
		if(x[y]!=x[tamano-1-y])
			return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	/*/
	int x[5]={1,9,5,4,2};
	cout<<suma(x,5)<<endl;
	cout<<mayor(x,5)<<endl;
	cout<<nprimosarreglo(x,5)<<endl;
	ord_dsc(x,5);
	ord_asc(x,5);
	invertirarreglo(x,5);
	//*/
	
	/*
	char xx[]="abcdedcba";
	cout<<tamanoarreglo(xx)<<endl;
	cout<<contarcaracteresxveces(xx,'a')<<endl;
	cout<<siespalindrome(xx)<<endl;
	//*/
	
	return 0;
}


