#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*---------  problema3  ---------
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
	
	if(a>b)
	{
		if(a>c){ if(b>c){cout<<m<<a<<"    "<<n<<c<<"    "<<p<<(a+c)/2<<endl;}
				 else{cout<<m<<a<<"    "<<n<<b<<"    "<<p<<(a+b)/2<<endl;}
				}
		
		else{cout<<m<<c<<"    "<<n<<b<<"    "<<p<<(b+c)/2<<endl;}///////////
	}
	if(b>c)
	{
		if(b>a){ if(a>c){cout<<m<<b<<"    "<<n<<c<<"    "<<p<<(b+c)/2<<endl;}
				else{cout<<m<<a<<"    "<<n<<b<<"    "<<p<<(a+b)/2<<endl;}
		}
		
		else{cout<<m<<a<<"    "<<n<<c<<"    "<<p<<(a+c)/2<<endl;}///////////
	}	
	if(c>a)
	{
		if(c>b){  if(b>a){cout<<m<<c<<"    "<<n<<a<<"    "<<p<<(a+c)/2<<endl;}
				else{cout<<m<<a<<"    "<<n<<b<<"    "<<p<<(a+b)/2<<endl;}
		}
		
		else{cout<<m<<b<<"    "<<n<<a<<"    "<<p<<(a+b)/2<<endl;}////////////
		}-----------  problema 3  ---------*/
	
	
	
	
	
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
	
	
	
	/*---------  problema 8  ---------
	
	int n,b,d,n1,n2,n4,n5;
	
	cout<<"ingrese 1 numero de 5 cifras"<<endl;
	cin>>n;
	
	//numero      n1.n2.n3.n4.n5    5 cifras , n3 es espejo
	n1=n/10000;  //
	
	b=n/1000;
	n2=b%10;		//
	
	d=n/10;
	n4=d%10;			  //
		
	n5=n%10;				  //
	
	if(n1==n5 and n2==n4){cout<<"si es palindromo";}
	else{cout<<"no es palindromo";}
	
	----------  problema 8  ---------*/
	
	
	return 0;
	
}







