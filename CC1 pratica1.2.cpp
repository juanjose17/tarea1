#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*/problema 1
	int x;
	cout<<"ingrese un numero de año"<<endl;
	cin>>x;
	bool result;
	result= !(x%4)?!(x%100)?!(x%400)?true:false:true:false;
	if(result)
		cout<<"es bisiesto";
	else
		cout<<"no es bisiesto";
	*/
	
	/*/problema 2
	int x;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	if(x%2==0)
	x/=2;
	else
	x=x/2;
	for(int y=0;y<x;y++){
	cout<<(y+1)*2;
	if(y<x-1)
	cout<<" ; ";
}
	*/
	
	/*/pregunta 3
	cout<<"ingrese 1 numero"<<endl;
	int x,a=0,b=1,f=1;
	cin>>x;
	for(int y=0;y<x;y++){
	cout<<f;
	f=a+b;
	if(y<x-1)
	cout<<";";
	a=b;
	b=f;
}
	*/
	
	/*/problema 4
	cout<<"ingrese 1 numero"<<endl;
	int x,xx=1;
	cin>>x;
	for(int y=0;y<x;xx++){
		int a=0;
		bool b=false;
		for(int yy=1;yy<xx;yy++){//comprobar si es perfecto
			if(xx%yy==0)
				a+=yy;
			if(a==xx)
				b=true;
			else
				b=false;
		}
		if(b){
			cout<<a;
			if(y<x-1)
				cout<<" ; ";
			y++;
		}
		
	}
	*/
	
	/*/problema 5
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
