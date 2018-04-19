#include <iostream>
using namespace std;

bool esmayor(int x){//                                    1
	
	
	if(x>=18)
		return 1;
	return 0;
}
void imprimirnumeros(int n, int cont=1){//                2
	
	
	
	if(cont>n)
		return;
	if (n>=cont){
		cout<<cont;
		if(n<cont)
			cout<<",";
		imprimirnumeros(n,cont+1);}
}

void mayormenorpromedio(int a,int b,int c){//             3
	

	
	string m ="mayor  ";
	string n ="menor  ";
	string p ="promedio  ";
	(a>b and a>c)?cout<<"a es mayor":((b>a and b>c)?cout<<"b es mayor":cout<<"c es mayor");
	(a<b and a<c)?cout<<" a es menor":((b<a and b<c)?cout<<" b es menor":cout<<" c es menor");	
}

bool accion_a(int x,int y){//                             4 
	
	if (not(x%2) and not(y%2))
	{
		return 1;
	}
	return 0;
}
bool accion_b(int x,int y){
	
	if ((y%x)==0)
	{
		return 1;
	}
	return 0;
}
bool accion_c(int x,int y){
	
	if((x*x)==y){
		return 1;
	}
	return 0;
}
bool esprimo(int x,int cont=0){//                         5
	
	for(int i=1;x>=i;i++){
		if(x%i==0)
			cont++;
	}
	if(cont==2  or cont==1)
		return 1;
	return 0;
}

void imprimirprimos(int x,int n=1){//                     6
	
	
	if (x==n){
		cout<<"numeros primos menores de "<<x;
		return;}
	if (esprimo(n)){
		cout<<n<<",";
		imprimirprimos(x,++n);}
	else{
		imprimirprimos(x,++n);}
	
}


























void imprimir5digitosseparados(int n){//                  7
	
	int s=0;
	while(n>0)
	{
		s=s+n%10;
		cout<<s;
		cout<<"\t";
		n=n/10;
		s=0;}
	
}


bool espalindrome(int n){//                               8
	
	int b,d,n1,n2,n4,n5;
	//numero      n1.n2.n3.n4.n5    5 cifras , n3 es espejo
	n1=n/10000;  //
	
	b=n/1000;
	n2=b%10;		//
	
	d=n/10;
	n4=d%10;			  //
	
	n5=n%10;				  //
	
	if(n1==n5 and n2==n4){return 1;}
	else{return 0;}
}



bool esbisiesto(int f){//                                 9
	
	if(f%4!=0 or (f%100==0 and f%400!=0))
	{return 1;}
	return 0;
}


int fibon(int n){//                                      10
	
	
	if (n==0 or n==1)
	{return n;}
	else{
		return (fibon(n-1)+fibon(n-2));
	}
}



int factorial(int n){//                                  11
	
	if(n==0){
		n=1;
	}
	else{
		n=n*factorial(n-1);
	}
	return n;
}



int main(int argc, char *argv[]) {
	/*//----------problem 1---------//
	cout<<"ingrese su edad"<<endl;
	int y;
	cin>>y;
	esmayor(y);
	return 0;
}*/
	
	
	/*----------problem 2---------
	cout<<"escriba un numero"<<endl;
	int x;
	cin >>x;
	imprimirnumeros(x);
	return 0 ;
}*/




	/*---------  problema3  ---------//
	cout<<"ingrese tres numeros"<<endl;
	int a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	mayormenorpromedio(a,b,c);
	return 0;
	}
*/

	//----------problem 4 ---------
	/*
	cout<<"ingrese 2 numeros"<<endl;
	int x;
	cin>>x;
	int y;
	cin>>y;
	cout<<accion_a(x,y)<<endl;
	cout<<accion_b(x,y)<<endl;
	cout<<accion_c(x,y)<<endl;
	return 0;
	}
*/


	//----------problem 5 y 6 ---------
/*
	int x;
	cin>>x;
	cout<<esprimo(x)<<endl;
	int y;
	cin>>y;
	imprimirprimos(y);
	return 0;
	}   
*/

	/*//----------problem 7 ---------
	int n;
	cin>>n;
	imprimir5digitosseparados(n);
	return 0;
}*/
	
	/*//---------  problema 8  ---------
	
	int n;
	
	cout<<"ingrese 1 numero de 5 cifras"<<endl;
	cin>>n;
	cout<<espalindrome(n)<<endl;
	return 0;
}*/
	
	/*//----------problem 9 ---------
	cout<<"ingrese numero de año"<<endl;
	int f;
	cin>>f;
	cout<<esbisiesto(f)<<endl;
	return 0;
}*/
	
	/*//----------problem 10 ---------
	
	int	n;
	cin>>n;
	cout<<fibon(n)<<endl;
	return 0;
}*/
	

	/*----------problem EXTRA ---------
	cout<<"ingrese un numero factorial"<<endl;
	int a;
	cin>>a;
	cout<<factorial(a)<<endl;
	return 0;
}*/
