#include<iostream>

using namespace std;

void imprimirnumeros(int A[], int tam);
void imprimirletras(char B[], int tam);
void quicksortnumeros(int array[], int inicio, int fin);
void quicksortletras(char letras[], int inicio, int fin);


void quicksortletras(char letras[], int inicio, int fin){
	int izq,der,pivote,aux;
	
	izq=inicio;
	der=fin;
	pivote=letras[(izq+der)/2];
	
	
do{
	while(letras[izq]<pivote){
		izq++;
	}
	
	while(letras[der]>pivote){
		der--;
	}
	
	if(izq<=der){
		aux=letras[izq];
		letras[izq]=letras[der];
		letras[der]=aux;
		izq++;
		der--;
	}

}while(izq<=der);

	if(inicio<=der){
		quicksortletras(letras,inicio,der);
	}
	
	if(izq<fin){
		quicksortletras(letras,izq,fin);
	}
	return;
}
void quicksortnumeros(int array[], int inicio, int fin){
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
		quicksortnumeros(array,inicio,der);
	}
	
	if(izq<fin){
		quicksortnumeros(array,izq,fin);
	}
	return;
}
 
int main()
{
	system("cls");
	int opc,tam,o=1;
	char letras[13];
	int *array=nullptr;
	
do{                                 
	cout<<"\n	Bienvendo, porfavor ingrese su opcion que desea realizar.";
	cout<<"\n	[1] Agregar array Numerico";
	cout<<"\n	[2] Agregar array Alfabetico";
	cout<<"\n	[3] Impirmir array Numerico";
	cout<<"\n	[4] Imprimir array Alfabetico";
	cout<<"\n	[5] Ordenar array Numerico";
	cout<<"\n	[6] Ordenar array Alfabetico";
	
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
			cout<<"\n	Ingrese su texto:";
			cin>>letras;

			cout<<"\n	Texto insertado!";
			break;

		case 3:
		if(array!= nullptr){
				imprimirnumeros(array,tam);
		}else{
			cout<<"\n	Debe ingresar un arreglo primero\n\n";
			system("pause");
			main();
		}
			
			break;
		case 4:
				imprimirletras(letras,13);
			break;

		case 5:
		if(array!= nullptr){
				quicksortnumeros(array,0,tam-1);
				cout<<"\n	Arreglo ordenado!\n\n";
				system("pause");
		}else{
			cout<<"\n	Debe ingresar un arreglo primero\n\n";
			system("pause");
			main();
		}	
			break;

		case 6:
		if(letras!= nullptr){
				quicksortletras(letras,0,13);
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

void imprimirnumeros(int A[], int tam){
	cout<<"\n	Su arreglo: ";
	for(int i=0;i<tam;i++){
		cout<<" "<<A[i];
	}
	cout<<"\n\n";
	system("pause");system("cls");
}

void imprimirletras(char B[], int tam){
	cout<<"\n	Su arreglo: ";
	for(int i=0;i<tam;i++){
		cout<<" "<<B[i];
	}
	cout<<"\n\n";
	system("pause");system("cls");
}