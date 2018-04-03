#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*----------problem 1---------
	cout<<"ingrese su edad"<<endl;
	int x;
	cin>>x;
	if(x>=18)
	{
		cout<<"eres una persona mayor"<<endl;
	}
	else
	{
		cout<<"eres una persona menor"<<endl;
	}
	----------problem 1---------*/
	
	
	
	/*----------problem 2---------
	cout<<"escriba un numero"<<endl;
	int x;
	cin >>x;
	int y=1;
	while(y<=x)
	{
		cout<<y;
		y=y+1;
		if(y<=x){
			cout<<",";
				}
	}
	----------problem 2---------*/
	
	
	
	/*----------problem 3 incompleto---------
	cout<<"ingrese tres numeros"<<endl;
	int a;
	cin>>a;
	int b;
	cin>>b;
	int c;
	cin>>c;
	
	string m ="mayor  ";
	string n ="menor  ";
	string p ="promedio  ";
	
	if(a>b and b>c){
				cout<<m<<a<<"    "<<n<<c<<"    "<<p<<(a+c)/2<<endl;
			}
	else if(b>a and a>c){
		cout<<m<<b<<"    "<<n<<c<<"    "<<p<<(a+c)/2<<endl;
	}
	else if(a>b and b>c){
		cout<<m<<a<<"    "<<n<<c<<"    "<<p<<(a+c)/2<<endl;
	}
	else if(b>a and a>c){
		cout<<m<<b<<"    "<<n<<c<<"    "<<p<<(a+c)/2<<endl;
	}	
	----------problem 3 incompleto---------*/
	
	
	/*----------problem 4 ---------
	
	cout<<"ingrese 2 numeros"<<endl;
	int x;
	cin>>x;
	int y;
	cin>>y;
	
	cout<<"enunciado a"<<endl;
	if (not(x%2) and not(y%2))
	{
		cout<<"son multiplos de dos"<<endl;
	}
	else{
		cout<<"no son multiplos de dos"<<endl;
	}
	
	cout<<"enunciado b"<<endl;
	if ((y%x)==0)
	{
		cout<<y<<" es multiplo de "<<x<<endl;
	}
	else{
		cout<<y<<" no es multiplo de "<<x<<endl;
	}
	
	cout<<"enunciado c"<<endl;
	if((x*x)==y)
	{
		cout<<x*x<<" es igual a "<<y<<endl;
	}
	else{
		cout<<x*x<<" no es igual a "<<y<<endl;
	}
	----------problem 4 ---------*/
	
	
	/*----------problem 5 ---------
	cout<<"ingrese 1 numero"<<endl;
	int x;
	cin>>x;
	int y=1;
	int v=x;//contador para primo el 1 y el mismo numero solo lo debe dividir
	while (y<=x)
	{
		
		if((x%y)!=0)
		{
			v=v-1;
			if(v==2)
			{
				cout<<"es primo  "<<x<<endl;
				return 0;
			}
			
		}
		//----borrar ------ if ((x%y==0)and (x<=2))
		//{
		//	v=v-1;
		//	if((y=x)and (v==0)) 
		//	{
		//		cout<<"es primo  "<<x<<endl;
		//		return 0;
		//	}
		//}----borrar ------
		
		y=y+1;
		
	}
	cout<<"no es primo     "<<x<<endl;
	----------problem 5 ---------*/
	
	/*----------problem 7 ---------
	int n;
	int s=0;
	cin>>n;
	while(n>0)
	{
	s=s+n%10;
	cout<<s;
	cout<<"\t";
	n=n/10;
	s=0;
	
}----------problem 7 ---------*/
	
	/*----------problem 9 ---------
	cout<<"ingrese numero de año"<<endl;
	int f;
	cin>>f;
	if(f%4!=0 or (f%100==0 and f%400!=0))
		{
		cout<<"no es bisiesto"<<endl;
		}
	else
		{
		cout<<"es bisiesto"<<endl;
		}
	----------problem 9 ---------*/
	
	
	
	/*----------problem 10 ---------
	int f=0;
	int	f1=0;
	int	f2=1;
	int	n;
	int c=1;
	cout<<"serie de fibonnaci"<<endl;
	cout<<"numero de fibonacci"<<endl;
	cin>>n;
	while(c<=n)
	{
	f1=f2;
	f2=f;
	f=f1+f2;
	c=c+1;
	cout<<f<<" ";
	
}----------problem 10 ---------*/
	

	
	
	
	
	/*----------problem EXTRA ---------
	cout<<"ingrese un numero factorial"<<endl;
	int a;
	cin>>a;
	int b=a;
	while(b>1)
	{
		b=b-1;
		a=a*b;
	}
	cout<<"factorial de numero es    "<<a<<endl;
	----------problem EXTRA ---------*/	  
		  
		  
	return 0;
}

