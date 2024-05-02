#include<iostream>

using namespace std;

void imprimir(int A[], int tam);
void quicksort(int array[], int inicio, int fin);

void quicksort(int array[], int inicio, int fin){
	int izq,der,pivote,aux;
	
	izq=inicio;
	der=fin;
	pivote=array[(izq+der)/2];
	
	
do{
	while(array[izq]<pivote){
		izq++;
	}
	
	while(array[der]>pivote){
		der--;
	}
	
	if(izq<=der){
		aux=array[izq];
		array[izq]=array[der];
		array[der]=aux;
		izq++;
		der--;
	}

}while(izq<=der);

	if(inicio<=der){
		quicksort(array,inicio,der);
	}
	
	if(izq<fin){
		quicksort(array,izq,fin);
	}
	return;
}
 
int main()
{
	system("cls");
	int opc,tam,o=1;
	int *array=nullptr;
	
do{                                 
	cout<<"\n	Bienvendo, porfavor ingrese su opcion que desea realizar.";
	cout<<"\n	[1] Agregar array numerico";
	cout<<"\n	[2] Impirmir array";
	cout<<"\n	[3] Ordenar array";
	cout<<"\n	Su opcion: ";
	cin>>opc;
		switch(opc){
		case 1:
			cout<<"\n	Ingrese el tamanio de su arreglo: ";
			cin>>tam;
			array= new int[tam]; 
			cout<<"\n	Ingrese los datos de su arreglo: \n";
			for(int i=0; i<tam;i++){
				cout<<"	";
				cin>>array[i];
			}
			cout<<"\n	Arreglo Creado con exito!";

			break;
		case 2:
		if(array!= nullptr){
				imprimir(array,tam);
		}else{
			cout<<"\n	Debe ingresar un arreglo primero\n\n";
			system("pause");
			main();
		}
			
			break;
		case 3:
		if(array!= nullptr){
				quicksort(array,0,tam-1);
				cout<<"\n	Arreglo ordenado!\n\n";
				system("pause");
		}else{
			cout<<"\n	Debe ingresar un arreglo primero\n\n";
			system("pause");
			main();
		}	
			break;
		}
}while(o==1);

}

void imprimir(int A[], int tam){
	cout<<"\n	Su arreglo: ";
	for(int i=0;i<tam;i++){
		cout<<" "<<A[i];
	}
	cout<<"\n\n";
	system("pause");system("cls");
}