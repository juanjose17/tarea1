#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

	/*/problema 1
	int x,a=0;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	for(int y=1;y<x;y++){
		if(y%3==0){
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
	int x;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	if(x%2==0)
		x/=2;
	else
		x=(x+1)/2;
	for(int y=0;y<x;y++){
		cout<<(y*2)+1;
		if(y<x-1)
			cout<<" ; ";
	}
	*/

	/*/problema 3
	int x;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	for(int yy=1;yy<x;yy++){
	int z=0;
	bool b=false;
	for(int y=1;y<=yy;y++){
		yy%y?yy:z++;
	}
	if(z<3)
		b=true;
	else
		b=false;
	if(b){
		cout<<yy;
		if(yy<x-1)
			cout<<" ; ";
	}
	}
	*/

	/*/problema 4
	int x,a=0;
	cout<<"ingresa 1 numero"<<endl;
	cin>>x;
	bool b=false;
	for(int y=1;y<x;y++){
		if(x%y==0)
			a+=y;
	}
	if(a==x)
		cout<<"es perfecto";
	else
		cout<<"no es perfecto";

	*/


	//problema 5
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
				cout<<mprimo<<" ; ";}
		}
	}
	cout<<"el mayor primo es "<<mprimo;



	return 0;
}

