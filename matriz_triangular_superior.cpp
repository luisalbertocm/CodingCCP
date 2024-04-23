#include<iostream>

using namespace std;

int main(){
	int matriz[3][3];
	int numero;
	
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<"Ingrese los numeros de su matriz"<<endl;
			cin>>numero;
			matriz[i][j]=numero;
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			
			cout<<matriz[i][j];
		}
		cout<<"\n";
	}
	
	if (matriz[1][0]==0 && matriz[2][0]==0 && matriz[2][1]==0){
		cout<<"Matriz triangular."<<endl;
	}else{
		cout<<"Matriz no triangular";
	}
	
	
	return 0;
}