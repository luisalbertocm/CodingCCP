#include<iostream>

using namespace std;

const int MAX = 10;

int cuadromagico(int max);
int mostrarcuadro(int cuadro[][MAX], int max);

mostrarcuadro(int cuadro[][MAX], int max){
	
	// Mostramos el cuadrado magico
    cout << "\n Su cuadrado magico:" << endl;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            cout << cuadro[i][j] << "\t";
        }
        cout << endl;
    }
	return 0;
}

cuadromagico(int max){
	
	int cont=1;
	//INICIALIZAMOS EN 0ROS PARA PODER HACER LA COMPARACION SI A POSICION ESTA OCUPADA
	int cuadro[MAX][MAX]{}; //{} sirve para inicializar todo en 0ros
	
	int i=0,j=max/2;
		//ASIGNAMOS EL 1 A LA POSICION DEL MEDIO DE HASTA ARRIBA
		cuadro[i][j]=cont;
	
	//CUANDO EL CONTADOR SEA MAYOR AL MAX*MAX EL CUADRO YA ESTARARA LLENO, Y CERRAMOS EL BUCLE
	while(cont<max*max){
		cont++;
		
		//nos sirven para hacer el movimiento de las posiciones
		int ii=i-1;
		int jj=j+1;
		
		//Condicion de si se pasa de ariba del cuadro lo mandamos hasta abajo
		if(ii<0){
			ii=max-1;
		}
		
		//condicion de si se pasa del lado derecho del cuadro lo mandamos a la izquierda
		if(jj>=max){
			jj=0;
		}
		
		//si nuestra posicion esta ocupada
		if(cuadro[ii][jj]!=0){
			//aumentamos i para movernos abajo %max nos sirve para que no nos salgamos de la matriz
			i=(i+1)%max;
			//si la celda esta libre
		}else{
			//los valores ii jj los pasamos a i j 
			i=ii;
			j=jj;	
		}
		//asignamos el valor a la posiocion
		cuadro[i][j]=cont;		
}
//cuando ya esta lleno el cuadro nos vamos a la funcion que nos mostrara este
	mostrarcuadro(cuadro,max);
	return 0;
}

int main(){
	int max;
	
	cout<<"\nIngrese el tamanio del cuadrado: "<<endl;
	cin>>max;
	//SI NUESTRO MAX ES NUMERO PAR, REGRESAMOS AL MAIN PARA INGRESAR UN NUMERO IMPAR
	if(max%2==0){
		cout<<"Debe ingresar un numero impar."<<endl;
		return main();	
	}
	if(max==1){
		cout<<"\nDebe ingresar un numero mayor a 1"<<endl<<endl;
		system("pause");system("cls");
		return main();
	}
	//SI EL NUMERO ES CORRECTO, PASAMOS A A SIGUIENTE FUNCION
	cuadromagico(max);
	
}