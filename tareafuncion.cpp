#include <iostream>
using namespace std;

void esmayor(int x){
	if(x>=18){cout<<"eres una persona mayor"<<endl;}
	else{cout<<"eres una persona menor"<<endl;}
	return;
}
void imprimirnumeros(int x){
	int y=1;
	while(y<=x)
	{
		cout<<y;
		y=y+1;
		if(y<=x){
			cout<<",";}
	}	
}

void mayormenorpromedio(int a,int b,int c){
	string m ="mayor  ";
	string n ="menor  ";
	string p ="promedio  ";
	
	(a>b and a>c)?cout<<"a es mayor":((b>a and b>c)?cout<<"b es mayor":cout<<"c es mayor");
	(a<b and a<c)?cout<<" a es menor":((b<a and b<c)?cout<<" b es menor":cout<<" c es menor");
	
}

//////////////////////////////////////problema 4
bool accion_a(int x,int y){
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
////////////////////////////////////
	
///////////////////////////////////5
	bool esprimo(int x){
		int y=1;
		int v=x;//contador para primo el 1 y el mismo numero solo lo debe dividir
		while (y<=x)
		{
		if((x%y)!=0)
		{
			v=v-1;
			if(v==2)
			{
			return 1;
			}
				
			}	
			
			y=y+1;
			
		}
		return 0;
	}
	
//////////////////////////////////////6
	
//////////////////////////////////////7
	void imprimir5digitosseparados(int n){
		int s=0;
		while(n>0)
		{
			s=s+n%10;
			cout<<s;
			cout<<"\t";
			n=n/10;
			s=0;}
		
	}
//////////////////////////////////////8
	
	bool espalindrome(int n){	
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
	
////////////////////////////////////////9
	
	bool esbisiesto(int f){
		if(f%4!=0 or (f%100==0 and f%400!=0))
			{return 1;}
		return 0;
	}
	
////////////////////////////////////////10
	int fibon(int n){
	    if (n==0 or n==1)
		{return n;}
		else{
			return (fibon(n-1)+fibon(n-2));
			}
	}
		
	
///////////////////////////////////////11
	int factorial(int n){
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
	
	
	
	
	/*//---------  problema3  ---------//
	cout<<"ingrese tres numeros"<<endl;
	int a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	mayormenorpromedio(a,b,c);
	return 0;
}*/

	
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
}*/
	
	
	//----------problem 5 ---------
	/*
	
	cout<<"ingrese 1 numero"<<endl;
	int x;
	cin>>x;
	
	cout<<esprimo(x)<<endl;
	return 0;
}   */

	
	/*---------  problema 6  ---------
	
	cout<<"ingrese 1 numero"<<endl;
	int numero;
	cin>>numero;
	int n=1;//para el while
	int i;
	int c;
	string a;
	while(n<numero){
	c=0;//para el for(contador)
	
	for(i=1;i<=n;i++)
	{
	if(n%i==0){c=c+1;}
}
	if(c>2){a="no";}
	else{a="si";}
	if(a=="si"){cout<<n<<"   ";}
	n=n+1;
}----------  problema 6  ---------*/
	
	
	
	
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
	
	
	
	
