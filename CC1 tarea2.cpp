#include <iostream>
using namespace std;

//problema 4 funciones
int ndigito(int x){
	
	
	int y=1;
	for(bool a=0;a==0;){
		y*=10;
		if(x%y==x){
			y=y/10;
			a=1;
		}
	}
	return y;
}
int ndc(int x){
	
	
	int y=1;
	for(;x-1;y++){
		x/=10;
	}
	return y;
}
bool espalindrome(int x){

	int a,y=1,b,bb;
	y=ndigito(x);
	a=ndc(y);
	int xx=x,zz=a,z;
	for(z=0;z<zz/2;){
		b=x/y;
		bb=xx%10;
		x=x%y;
		xx=xx/10;
		if(b==bb)
			z++;
		else
			z=zz;
		y=y/10;
	}
	if(z<=a/2)
		return 1;
	else
		return 0;
}

int main(int argc, char *argv[]) {
	
	/*/problema 1
	int x,a=0;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	for(int y=1;y<x;y++){
	if(y%3==0 or y%5==0){
	cout<<y;
		if(y<x-1)
		cout<<" ; ";
	a+=y;
	}
	if(y%5==0){
	cout<<y;
		if(y<x-1)
		cout<<" ; ";
	a+=y;
	}
	}
	cout<<"la suma es "<<a;
	*/
	
	
	/*/problema 2
	cout<<"ingresa 1 numero"<<endl;
	int x,a=0,b=1,f=1,snumero=0;
	cin>>x;
	for(int y=1;y<=x;y++){
		f=a+b;
		cout<<f;
		if(y<x)
			cout<<";";
		a=b;
		b=f;
		if(f%2==0)
			snumero+=f;
	}
	cout<<"la suma es "<<snumero;
	*/
	
	
	
	/*/problema 3
	long long x,xx=0,mprimo=0;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	for(int yy=1;yy<x;yy++){
	int z=0;
	bool b=false;
		for(int y=1;y<yy;y++){
		yy%y?yy:z++;
		}
	if(z<3)
		b=true;
	else
		b=false;
	if(b){
	xx=yy;
		if(x%xx==0){
		mprimo=xx;
		cout<<mprimo<<" ; ";
		}
	}
	}
	cout<<"el mayor primo es "<<mprimo;
	*/
	
	
	/*/problema 4
	cout<<"ingrese 1 numero de  digitos 2=100 o 3=1000"<<endl;
	int x;
	cin>>x;
	int numero,mnpalindromo;
	for(int y=1;y<x;y++){
	bool siesp=false;
		for(int yy=1;yy<x;yy++){
		numero=y*yy;
		siesp=espalindrome(numero);
		if(siesp)
			mnpalindromo=numero;
		}
	}
	cout<<"mayor numero palindromo es "<<mnpalindromo;
	//*/
	
	/*/problema 5
	int x,numero;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	for(int y=1;true;y++){
	int c=0;
		for(int z=1;z<=x;z++){
			if(y%z==0){
				c++;
			}
		}
	if(c==x){
		numero=y;
		break;
	}
	}
	cout<<"menor numero divisible es "<<numero;
	//*/
	
	
	/*/problema 6
	int x,sc=0,cs=0,result;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	for(int y=1;y<=x;y++){
		sc+=(y*y);
		cs+=y;
	}
	result=(cs*cs)-sc;
	cout<<"la diferencia de sc y cs es "<<result;
	//*/
	
	
	/*/problema 7
	int x,uprimo;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	int xx=x;
	for(int y=1;0<x;y++){
	int z=0;
	for(int yy=1;yy<=y;yy++){
		if(y%yy==0)
			z++;
	}
	if(z==2){
		uprimo=y;
		//cout<<y;
		//if(0<x-1)
		//	cout<<";";
		x--;
	}
	}
	
	cout<<"\nnumero primo "<<xx<<" es "<<uprimo;
	//*/
	
	
	/*/problema 9
	int x,result;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	for(int a=1;a<x;a++){
		for(int b=a+1;b<x;b++){
			int c=x-a-b;
			if(a*a+b*b==c*c){
				cout<<a<<" "<<b<<" "<<c<<endl;
				result=a*b*c;
			}
		}
	}
	cout<<"el pitagorico producto abc es "<<result;
	//*/
	
	
	/*/problema 10
	int x,sprimo=0;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	for(int yy=1;yy<x;yy++){
	int z=0;
	bool b=false;
		for(int y=1;y<=yy;y++){
		yy%y?yy:z++;
		}
	if(1<z and z<3)
		b=true;
	else
		b=false;
	if(b){
	cout<<yy;
	sprimo+=yy;
		if(yy<x-1)
		cout<<" ; ";
	}
	}
	
	cout<<"la suma de los n primos menores es "<<sprimo;
	*/
	
	
	return 0;
}
