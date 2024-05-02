#include<iostream>

using namespace std;

class Biblioteca{
    //atributos de los libros
    private:
    struct Libreria{
        string nombre;
		string autor;
		string editorial;
		int precio;
		int stock;    
    };

    public:
    //metodos
    void crearArchivo();
    void cliente();
    void seccion();
    void personal();
    void ingresarLibros();
};

void Biblioteca::personal(){
    int opc;
	cout<<"\n	Bienvenido "<<"!";
		cout<<"\n	Porfavor ingresar la opcion que desea realizar";
		cout<<"\n	Opcion 1. Ingresar libros a la biblioteca";
		cout<<"\n	Opcion 2. Imprimir el stock de libros";
		cout<<"\n	Opcione 3. Cerrar seccion";
		cout<<"\n\n	Su opcion: ";
		cin>>opc;
		
		switch(opc){
			case 1:
				system("cls");
				cout<<"hola";
				break;
				
			case 2:
				cout<<"hola";
				break;
			
			case 3:
				cout<<"\n	Usted a cerrado seccion de manera exitosa!";
				system("pause");system("cls");
				
				break;
				
			default:
				cout<<"\n	Ingrese una opcion correcta.\n\n";
				//personal(userref);
				break;					
			
		}
}

int main(){
    int opc;
    string usuario;
	int contrasenia;

    Biblioteca open;
    
	//este do nos sirve como ciclo para que el usuario desee cuando salir del programa	
	do{
	
	if(opc==1){
	cout<<"\n\n	Porfavor seleccionar si usted es personal o cliente";
	cout<<"\n\n	Presione 1. Si usted es personal.";
	cout<<"\n	Presione 2. Si usted es cliente.";
	cout<<"\n\n	Su opcion: ";
	cin>>opc;
	
	switch(opc){
		
		case 1: 
			system("cls");
			
	        cout<<"\n	Usted es personal de la libreria";
	        cout<<"\n	Porfavor inicie seccion";
	        cout<<"\n\n	Usuario: ";
            cin>>usuario;
	        cout<<"	Contrasenia: ";
            cin>>contrasenia;

	        if(usuario=="luis"&&contrasenia==1234){
		    system("cls");
	    	open.personal();
		
	        }else{
		    cout<<"\n	Usuario incorrecto\n\n";
		    system("pause");system("cls");
		    //return 0;
	        }
	        //return 0;	
			break;
		
		case 2:
			system("cls");
            cout<<"hola";
			//cliente();
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
    cout<<"\n	Presione 1 si desea continuar, de lo contrario presione otra tecla para salir del programa."<<endl;
    cout<<"\n	Su opcion: ";
    cin>>opc;	
	system("cls");
			
	}while(opc==1);
	return 0;
}