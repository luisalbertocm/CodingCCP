#include<iostream>

using namespace std;
int comprar();
int usuarios();
int estudiantes();
	
	struct biblioteca{
		int libro[5]{};
		int costo;
	};
	usuarios(){
		
		return 0;
	}
	estudiantes(){
		int numero;
		static biblioteca estudian;
		cout<<"Felicidades usted tendra un 20% de descuento en su compra."<<endl;
		cout<<"Porfavor seleccione el liro que desea comprar"<<endl;
		cin>>numero;
		
		return 0;
	}
	comprar(){
		int opcion;
	cout<<"\nUsted decidio comprar."<<endl;
	cout<<"\nsi usted es un estudiante presione 1"<<endl;
	cout<<"\nsi usted es un usuario presione 2."<<endl;	
	switch(opcion){
		case 1:
			estudiantes();
			break;
		case 2:
			usuarios();
			break;
		default:
			cout<<"Seleccione una opcion corrrecta.";
			break;
	}
		return 0;
	}
	


	
int main(){
	int opcion;
	
	cout<<"\nBienvenido a la libreria."<<endl;
	cout<<"si usted quiere comprar un libro presione 1"<<endl;
	cin>>opcion;
	switch(opcion){
		case 1:
			comprar();
			break;
			
		default:
			cout<<"gracias por visitarnos.";
			break;
	}
	
	return 0;
}

int main(){
	for(int i=100;i>0;i--){
		cout<<i;
	}
}