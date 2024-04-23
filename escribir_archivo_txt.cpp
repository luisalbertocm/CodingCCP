#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

//definimos una funcion vacia para escribir
void escribir();

int main(){
	escribir();
	
	system("pause");
	return 0;
}


void escribir(){
	ofstream archivo;
				//si no existe un archivo lo crea, y si existe lo reemplaza
	archivo.open("d:archivo.txt",ios::out);
	
	if(archivo.fail()){
		cout<<"NO SE CREO EL ARCHIVO"<<endl;
		exit(1);
	}
	
	archivo<<"Hola como estan";
	
	archivo.close();//cerramos 
}