#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	/*//pregunta 1
	cout<<"ingrese por favor su n°de edad"<<endl;
	int x;
	cin>>x;
	if(x>18){
		cout<<"es mayor de edad"<<endl;
	}
	else{
		cout<<"es menor de edad"<<endl;
	}
	*/
	
	/*//pregunta 2
	cout<<"ingrese un numero n"<<endl;
	int x;
	cin>>x;
	if(x%2)
		x/=2;
	else
		x=(x+1)/2;
	for(int y=0;y<x;y++){
		cout<<(y*2)+1;
		if(y<x-1){
			cout<<";";
		}
	}
	*/
	
	
	/*//pregunta 3
	cout<<"ingrese 3 numeros"<<endl;
	int x,y,z;
	cin>>x;
	cin>>y;
	cin>>z;
	int a=0;
	cout<<"el mayor ";
	if(x>y){
		if(x>z){
			cout<<x;
			a+=x;
		}
	}
	else if(y>z){
		cout<<y;
		a+=y;
	}
	else{
		cout<<z;
		a+=z;
	}
	cout<<" el menor ";
	if(x<y){
		if(x<z){
			cout<<x;
			a+=x;
		}
	}
	else if(y<z){
		cout<<y;
		a+=y;
	}
	else{
		cout<<z;
		a+=z;
	}
	cout<<" promedio "<<a/2<<endl;
	*/
	
	
	/*//pregunta 4
	cout<<"ingrese 2 numeros"<<endl;
	int x,y;
	cin>>x;
	cin>>y;
	if(x%2==0 and y%2==0)
		cout<<"a) son multiplos de 2"<<endl;
	else
		cout<<"no son "<<endl;
	if(x%y==0)
		cout<<"b) es multiplos x de y"<<endl;
	else
		cout<<"no es "<<endl;
	if(x*x==y)
		cout<<"c) es elevado al cuadrado x de y"<<endl;
	else
		cout<<"no es elevado "<<endl;
	*/
	
	/*/pregunta 5

	cout<<"ingrese 1 numero sera primo"<<endl;
	int x,y,z=0;
	cin>>x;
	for(y=1;y<x;y++)
		if(x%y==0)
		z++;
	if(z<3)
		cout<<"es primo";
	else
		cout<<"no es primo";
	*/
	
	/*pregunta 6
	
	cout<<"ingrese 1 numero para imprimir numeros primero menores a ese"<<endl;
	int x,y;
	cin>>x;
	for(y=1;y<x;y++){
	int a=0;
		for(int z=1;z<=y;z++)
		if(y%z==0)
		a++;
	if(a<=2)
		cout<<y<<";";
	}
	if(y==x)
		cout<<x<<"n primos menores a x";
	*/
	
	
	/*pregunta 7
	cout<<"ingrese 1 numero "<<endl;
	int x,a;
	cin>>x;
	int y=10000;
	for(int z=0;z<5;z++){
		a=x/y;
		x=x%y;
		cout<<a;
		if(z<4)
			cout<<"  ;  ";
		y/=10;
	}
	*/
	
	/*pregunta 7 mas versatil
	cout<<"de cuantos digitos es el numero"<<endl;
	int x,a,y=1,b;
	cin>>a;
	cout<<"ingrese 1 numero "<<endl;
	cin>>x;
	for(int z=a;1<z;z--)
		y=y*10;
	//cout<<y<<endl;
	for(int z=0;z<a;z++){
	b=x/y;
	x=x%y;
	cout<<b;
	if(z<a-1)
		cout<<"  ;  ";
	y=y/10;
}
	*/
	
	//12321

	/*pregunta 8 
	cout<<"ingrese un numero palindrome"<<endl;
	int x,a,y=1,b,bb;
	cin>>x;
	cout<<"cuantos digitos el numero "<<endl;
	cin>>a;
	for(int z=a;1<z;z--)
		y=y*10;
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
		cout<<"si es palindrome"<<endl;
	else
		cout<<"no es palindrome"<<endl;
	*/
	
	/*pregunta 9 
	int x;
	cout<<"ingrese un numero de año"<<endl;
	cin>>x;
	bool result;
	result= !(x%4)?!(x%100)?!(x%400)?true:false:true:false;
	cout<<"es "<<result;
	*/
	
	/*pregunta 10
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
	}*/
	
	
	
	
	
	/*/pregunta 11
	cout<<"ingrese 1 numero"<<endl;
	int x,a=1;
	cin>>x;
	for(int y=0;y<x;x--)
	a*=x;
	cout<<"factorial de x es "<<a;
	*/
	
	
	
	/*/pregunta 12
	cout<<"ingrese 1 numero"<<endl;
	int x;
	cin>>x;
	for(int yy=1;yy<x;yy++){
	int a=0;
	bool b=false;
	for(int y=1;y<yy;y++){
		if(yy%y==0)
			a+=y;
		if(a==yy)
			b=true;
		else
			b=false;
	}
	if(b){
		cout<<yy;
		if(yy<x-1)
			cout<<"  ";
	}
}*/
	
	
	/*/pregunta 12 versatil a n numeros
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
	
	return 0;
}
