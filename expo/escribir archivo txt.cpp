#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

//definimos una funcion para escribir
void escribir();

int main(){
	escribir();
	
	system("pause");
	return 0;
}


void escribir(){
	
    //int hola;
    //ifstream
	ofstream archivo;
	string nombre_archivo,texto_archivo;
	
	
	cout<<"ingrese el nombre desu archivo";
	getline(cin,nombre_archivo);

				//si no existe un archivo lo crea, y si existe lo reemplaza
				//d://						in
	archivo.open(nombre_archivo.c_str(),ios::out);

	//condicion	
	if(archivo.fail()){
		cout<<"NO SE CREO EL ARCHIVO"<<endl;
		exit(1);
	}
	

	cout<<"Ingrese su texto:	";
	getline(cin,texto_archivo);
	archivo<<texto_archivo;
	
	
	
	archivo.close();//cerramos 
}