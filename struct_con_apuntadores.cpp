#include<iostream>

using namespace std;

struct Persona{
	char nombre[15];
	int edad;
};

struct Persona pers={"Juan",20};
struct Persona pers2;

int suma (struct Persona *);
void solicitar_datos();
int main(){
	solicitar_datos();
	cout<<pers.nombre<<" tienes "<<pers.edad<<" anios";
	cout<<" y dentro de 20 anios tendras "<<suma(&pers);
	cout<<"\n	"<<pers2.nombre<<" tu tienes: "<<pers2.edad<<" anios";
}

int suma (struct Persona *yo){
	return yo->edad+20;
}

void solicitar_datos(){
	cout<<"Ingrese su nombre: 	";cin>>pers2.nombre;
	cout<<"Ingrese su edad:	";cin>>pers2.edad;
}