#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

	struct Libreria{
		string nombre;
		string autor;
		string editorial;
		int precio;
		int stock;
	};
//definimos una funcion para escribir
void crearArchivo();
int cliente();
void seccion();
void personal(string& userref);
void ingresarLibros();
	




void ingresarLibros(){
	string usuario;
	int cantidad;
	cout<<"\n	Porfavor ingrese la cantidad de libros que desea dar de alta: ";cin>>cantidad;
	struct Libreria estante[cantidad];
	

	
	
	for(int i=0; i<cantidad; i++){
	cout<<"\n	Ingrese el nombre de su libro "<<i+1<<": ";cin>>estante[i].nombre;
	cout<<"\n	Ingrese el autor de su libro "<<i+1<<": ";cin>>estante[i].autor;
	cout<<"\n	Ingrese el editorial de su libro "<<i+1<<": ";cin>>estante[i].editorial;
	cout<<"\n	Ingrese el precio de su libro "<<i+1<<": $";cin>>estante[i].precio;
	cout<<"\n	Ingrese el stock disponible: ";cin>>estante[i].stock;	
	cout<<"\n";
	
	system("pause"); system("cls");		
	}
	system("cls");
	cout<<"\n	A registrado los libros de manera exitosa!\n\n";
	system("pause"); system("cls");
    cout<<"\nIngrese su usuario nuevamente: ";
    cin>>usuario;
	personal(usuario);
//	return estante;
}

void personal(string& userref){
	int opc;

	cout<<"\n	Bienvenido "<<userref<<"!";
		cout<<"\n	Porfavor ingresar la opcion que desea realizar";
		cout<<"\n	Opcion 1. Ingresar libros a la biblioteca";
		cout<<"\n	Opcion 2. Imprimir el stock de libros";
		cout<<"\n	Opcione 3. Cerrar seccion";
		cout<<"\n\n	Su opcion: ";cin>>opc;
		switch(opc){
			case 1:
				system("cls");
				ingresarLibros();
				break;
				
			case 2:
				
				break;
			
			case 3:
				cout<<"\n	Usted a cerrado seccion de manera exitosa!";
				system("pause");system("cls");
				
				break;
			default:
				cout<<"\n	Ingrese una opcion correcta.\n\n";
				personal(userref);
				break;					
			
		}
	//return 0;
}

void seccion(){
	string usuario;
	int contrasenia;
	cout<<"\n	Usted es personal de la libreria";
	cout<<"\n	Porfavor inicie seccion";
	cout<<"\n\n	Usuario: ";cin>>usuario;
	cout<<"	Contrasenia: ";cin>>contrasenia;
	
	if(usuario=="luis"&&contrasenia==1234){
		system("cls");
		personal(usuario);
		
	}else{
		cout<<"\n	Usuario incorrecto\n\n";
		system("pause");system("cls");
		//return 0;
	}
	//return 0;	
}

/*cliente(){
	//int opc;
	
	cout<<"\n	Bienvenido a la biblioteca!";
	cout<<"\n	Le mostraremos los libros que tenemos disponibles a la venta";
	
	//mostrar libros
	
	
	return 0;	
}*/
void crearArchivo(){
	    
	ofstream archivo;
	string nombre_archivo;
	
	
	cout<<"\n	Ingrese el nombre de su archivo: ";
	getline(cin,nombre_archivo);

				//si no existe un archivo lo crea, y si existe lo reemplaza
				//d://						in
	archivo.open(nombre_archivo.c_str(),ios::out);

	//condicion	
	if(archivo.fail()){
		cout<<"\n	NO SE CREO EL ARCHIVO"<<endl;
		exit(1);
	}
	cout<<"\n	Archivo .txt creado con exito!";
	archivo.close();//cerramos 
}


int main(){
	int opc;
	//este do nos sirve como ciclo para que el usuario desee cuando salir del programa	
	do{
	if(opc==1){
	cout<<"\n\n	Porfavor seleccionar si usted es personal o cliente";
	cout<<"\n\n	Presione 1. Si usted es personal.";
	cout<<"\n	Presione 2. Si usted es cliente.";
	cout<<"\n\n	Su opcion: ";cin>>opc;
	
	switch(opc){
		
		case 1: 
			system("cls");
			seccion();
			break;
		
		case 2:
			system("cls");
			cliente();
			break;
			
		default:
			cout<<"\n	Ingrese una opcion correcta\n\n";
			system("pause"); system("cls");	
			main();
			break;
	}
	}
	//este es el primer mensaje que ve el usuario al ingresar al programa
	cout<<"\n	__________________________________________________________________________________";
	cout<<"\n	BIENVENIDOS A LA BIBLIOTECA!";
	cout<<"\n	__________________________________________________________________________________";
	cout<<"\n\n	Desea ingresar a la Biblioteca?";
	cout<<"\n	Presione 1	"<<endl;
	cout<<"	De lo contrario presione otra tecla si desea salir del programa."<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opc;	system("cls");
		
	}while(opc==1);
}