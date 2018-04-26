#include <iostream>
using namespace std;

void suma1(int n[]){
	
	int suma=0;
	for(int i=0;i<5;i++){
		suma+=n[i];}
	cout<<suma<<endl;
}

int suma1r(int n[],int i=0){
	
	if (i==4){
		return n[i];}
	return  n[i]+suma1r(n,++i);
}

void invierten(int n[]){
	
	int inverso=0;
	for(int i=0;i<=4/2;i++){
		//cout<<n[i];
		inverso=n[i];
		n[i]=n[4-i];
		n[4-i]=inverso;
	}
	for(int i=0;i<5;i++){
		cout<<n[i];}
}



int tamano(char s[],int cont=0){
	
	
	while(s[cont]!='\0'){
		cont++;
	}
	return cont;
}	

void copianc(char s[],char t[]){
	
	
	for(int i=0;t[i]!='\0';i++){
		s[i]=t[i];}
	for(int i=0;s[i]!='\0';i++){
		cout<<s[i];}
	cout<<endl;
}


void unirnc(char s[],char t[],int cont=0){
	
	

	while(s[cont]!='\0'){
		cont++;
	}
	for(int i=0;t[i]!='\0';i++){
		s[cont]=t[i];
		cont++;
	}
	for(int i=0;s[i]!='\0';i++){
		cout<<s[i];}
	cout<<endl;
}
	


int main(int argc, char *argv[]) {
	char s[]={'h', 'o', 'l', 'a', 's','a','\0'};
	char t[]={'m','a','n','o','s','v','i','s','t','e','s','\0'};
	
	cout<<tamano(s)<<endl;
	copianc(s,t);
	unirnc(s,t);
	
	int n[]={1,2,3,4,5};
	/*
	suma1(n);
	cout<<suma1r(n)<<endl;
	invierten(n);
	*/
	
	return 0;
}
