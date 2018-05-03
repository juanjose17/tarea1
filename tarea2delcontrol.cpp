#include <iostream>
using namespace std;



int tamano(char t[]){
	int cont=0;
	while(t[cont]!='\0'){
		cont++;}
	return cont;}

int substring(char s[],char t[]){
	char *s1,*t1,cont=0;
	s1=s;
	t1=t;
	for(;*s1!='\0';s1++){
		if(*s1==*t1){
			cont++;
			t1++;
			if(tamano(t1)-1<cont)
				return 1;} }
	return 0;}
	
int main(int argc, char *argv[]) {
	char t[]={'h','o','l','a','s','a','\0'};
	char s[]={'m','a','h','o','l','a','s','a','e','s','\0'};
	cout<<substring(s,t);
	return 0;
}
