#include <iostream>
using namespace std;

int sumaptr(int * ptr,int tam){
	
	
	
	int suma=0;
	for(int i=0;i<tam;i++){
		suma+=*ptr++;}
	return suma;
}
void inviertaptr(int * const ptr,int tam){
	
	
	
	int cont;
	for(int i=0;i<tam/2;i++){
		
		cont=*(ptr+i);//----
		//cout<<cont<<"contador"<<endl;////
		*(ptr+i)=*(ptr+tam-i-1);//----
		//cout<<*(ptr+i)<<endl;////
		*(ptr+tam-i-1)=cont;//------
		//cout<<*(ptr+tam-i-1)<<endl;////
	}
}


/*void invierte(int *s,int tam){

	int cont;
	int *ptr;
	ptr=s+tam-1;
	for(int i=0;ptr>=s;ptr--,s++){
		cont=*s;
		*s=*ptr;
		*ptr=cont;
		//tambien s++
	}
}	*/


int tamano(char *ptr,int cont=0){
	
	while(*ptr != '\0'){
		ptr++;
		cont++;
	}
	return  cont;
}

void copia(char * s,char * t){
	
	for(int i=0;*(t+i)!='\0';i++){
		*(s+i)=*(t+i);
		
	}
	
}

void unir(char * const s,char * const t){
	
	int cont=0;
	
	for(int i=0;*(s+i)!='\0';i++){
		cont++;}
	for(int i=0;*(t+i)!='\0';i++){
		*(s+cont+i)=*(t+i);	
	}

}

int main(int argc, char *argv[]) {
	
	int n[]={1,2,3,4,5,6,7,8,9,10};
	cout<<"la suma es "<<sumaptr(n,10)<<endl;//1
	
	inviertaptr(n,10);//2
	for(int i=0;i<10;i++){
		cout<<n[i];}
	
	cout<<endl;
	
	
	char s[30]={'h', 'o', 'l', 'a', 's','a','\0'};
	char t[30]={'m','a','n','o','v','i','s','t','e','s','\0'};
	cout<<tamano(s)<<endl;

	copia(s,t);
	for(int i=0;s[i]!='\0';i++){
		cout<<s[i];}cout<<endl;

	unir(s,t);
	for(int i=0;s[i]!='\0';i++){
		cout<<s[i];}cout<<endl;

	
	return 0;
}

