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
	 //cout << "\n\tizq: " << izq << ", der: " << der;
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
	int opc;
	int array[10]={2,13,5,7,4,8,10,6,3,9};
	int  tam=sizeof(array)/sizeof(array[0]);
do{
	                                        

	cout<<"\n	Bienvendo, porfavor ingrese su opcion que desea realizar.";
	cout<<"\n	[1] Impirmir array";
	cout<<"\n	[2] Ordenar array";
	cout<<"\n	Su opcion: ";
	cin>>opc;
		switch(opc){
		case 1:
			imprimir(array,tam);
			break;
		case 2:
			quicksort(array,0,tam-1);
			break;
		}
	cout<<"\n	Ingrese 1 si desea ingresar al programa."<<endl;
	cin>>opc;
}while(opc==1);

}


void imprimir(int A[], int tam){
	cout<<"\n	";
	for(int i=0;i<tam;i++){
		cout<<" "<<A[i];
	}
	cout<<"\n\n";
	system("pause");system("cls");
}