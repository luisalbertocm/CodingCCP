#include <iostream> //biblioteca funciones de cin y cout
#include <fstream> //biblioteca para funciones de txt
#define TXT ".txt" //constante para crear el nombre del archivo

using namespace std; //permite usar cin y cout

class Nodo{
	public:
	struct libros{
	string nombre;
    string autor;
    string editorial;
    int precio;
    int stock;
	}libro;
	Nodo *sig;
	Nodo *ant;

	Nodo(){ //Constructor sin datos
	libro.nombre="vacio";
	libro.autor="vacio";
	libro.editorial="vacio";
	libro.precio=0000;
	libro.stock=00;
	sig=NULL;
	ant=NULL;
	}

	Nodo(string nombre, string autor, string editorial,int precio, int stock){//en caso de pasar datos
        this->libro.nombre=nombre;
        this->libro.autor=autor;
		this->libro.editorial=editorial;
        this->libro.precio=precio;
		this->libro.stock=stock;
        this->sig = NULL;//siguiente apunta a null
        this->ant = NULL;//anterior apunta a null
	}
};

class Libreria{
	private:
	Nodo *head;//nodo inicial de la lista

	public:
	Libreria(){//constructor
	head = NULL; //en un inicio siempre apunta a null
	}

	void insertar(string nombre, string autor, string editorial,int precio, int stock){ //funcion para insertar un contacto
	Nodo *nuevoNodo= new Nodo(nombre,autor,editorial,precio,stock);
		if (head == NULL) { //si head == NULL entonces la lista esta vacia
            head = nuevoNodo; //el nodo creado ahora esta en el inicio
            head->ant=head;//apuntador anterior apunta a si mismo
            head->sig=head;//apuntador anterior apunta a si mismo
			return; //Salimos de la funcion
        }
		nuevoNodo->sig=head; //de nuestro nuevo nodo ->sig va apuntar a head
		head->ant->sig=nuevoNodo;//lo que head apunta a ->ant es el utimo nodo(viejo), de ese nodo(viejo)->sig es head, pero ahora ->sig va apuntar a nuevoNodo
        nuevoNodo->ant = head->ant;//el apuntador ->ant del nuevoNodo= lo que apuntaba nuestro head ->ant que era el nodo(viejo)
        head->ant=nuevoNodo;//nuestro ->ant de nuestro head= nuevoNodo
	}

	void buscar(int &contindice, int &busc){//funcion buscar por nombre

	Nodo *temp=head;//crea un nodo temporal apuntando a head
	string nomb;//variable local para solicitar nombre a buscar

	if (head == NULL) { //Si head apunta a NULL la lista esta vacia
            busc = 0; //asigna 0 para indicar vacia
            return;//sale de la funcion
        }
	cout<<"Ingresa el nombre del libro a buscar: ";//solicita nombre
		cin>>nomb;//lee nombre

		do{
			if(temp->libro.nombre==nomb){//si nuestro nombre ingresado es igual al nombre registrado en nuestros nodos
				busc=1;//asignamos 1 para indicar que se encontro
				return;//sale de la funcion
			}
			else if(temp->libro.nombre!=nomb){
				temp=temp->sig;//Avanza hacia el siguiente nodo hasta 
				contindice++;//incrementa el contador de posicion
			}
		}while(temp!=head);
		busc = 2;//asigna 2 para indicar que no se encontro
	}


	void eliminar(){//funcion para eliminar algun libro
	int indice;//variable local para solicitar la posicion
	Nodo *temp = head, *temp2 = NULL; //Creamos dos nuevos apuntadores, 
        //uno a head y otroa NULL
	
	int tamanoLista=0; //Creamos un contador para el tamaño de la lista

	if (head == NULL) { //Si head apunta a NULL la lista esta vacia
            cout << "La lista esta vacia."<<endl;//imprime error
            return;//sale de la funcion
        }
		cout << "Ingresa la posicion en la que se encuentra el contacto a eliminar: ";//solicita la posicion del contacto en la lista
        cin >> indice;//lee la posicion

	do{
		temp=temp->sig;
		tamanoLista++;
	}while(temp!=head);// se detiene cuando ya le dimos la vuelta a la lista

	 if (tamanoLista < indice) { //si la posicion indicada es mayor al total de datos en la lista
            cout << "Posicion fuera de rango o no valida"<<endl; //error fuera de rango
            return; //sale de la funcion
        }

	temp=head; //Volvemos a hacer que temp apunte a head (inicio)
	
	if(tamanoLista==1 && indice == 1){
			delete temp;
			head=NULL;
			return;
		}
	if (indice == 1) {//condicional si se elimina el inicio
			temp2 = head->sig; //posicionamos temp2(nuevoinicio) en el nodo siguiente a inicio
            temp2->ant = temp->ant; //remplazamos el enlaze anterior de temp2(nuevoinicio) con el de temp1(borrar)
			temp->ant->sig=temp2;//el nodo anterior a temp1(borrar) su siguiente ahora apunta a temp2(nuevoinicio)
			head = temp2;//inicio empieza en temp2 ahora
			delete temp; //borramos el apuntador que daba a inicio
            return;//retorna al inicio
        }

	while(indice-->1){ //en caso de que no sea el nodo inicial       	
        	temp=temp->sig;//recorremos la lista hasta encontrar el nodo a borrar = temp1
        }
        	temp2 = temp->sig; //temp2 apunta al nodo sigiente de temp1(borrar)
            temp2->ant = temp->ant; //salvamos el enlace de temp1(borrar) anterior en temp2
			temp->ant->sig=temp2;//conectamos el nodo anterior a temp1(borrar) con temp2
			delete temp; //borramos el nodo que queriamos
		cout<<"Libro eliminado"<<endl;//mensaje de exito
	}

	void ordenarQuicksort(){
		cout<<"OrdenarQuicksort";
	}

	void imprimir(){
		int pos=1;

		Nodo *temp = head; //Creamos un nodo temporal que apunta al 
        //nodo head (inicio)
        if (head == NULL) { //Si head es igual NULL la lista esta vacia
            cout << "La lista esta vacia."<<endl; //mensaje de error
            return;//sale de la funcion
        }
		
		do{ //Mientras temporal sea diferente de NULL (no es el final)
            cout <<pos<<" - Nombre: "<<temp->libro.nombre << "\tAutor: " << temp->libro.autor<<"\nEditorial: "<<temp->libro.editorial;
			cout<<"\nPrecio: "<<temp->libro.precio<<"\nStock: "<<temp->libro.stock; //Imprimimos el contenido de nodo actual	
            temp = temp->sig; //Y avanzamos al siguiente
            pos++;//incrementa la variable para mostrar posicion
        }while(temp!= head);// se detiene cuando ya le dimos la vuelta a la lista

	}

	void ingresarLibros(string &usuario){
	int opc;
	//datos del libro
	string nombre,autor,editorial;
	int precio, stock;
	cout<<"\n	";
	do{
	system("cls");//limpia pantalla
	cout<<"\n	Ingrese el nombre del libro: ";
	cin>>nombre;
	cout<<"\n	Ingrese el autor del libro: ";
	cin>>autor;
	cout<<"\n	Ingrese la editorial del libro: ";
	cin>>editorial;
	cout<<"\n	Ingrese el precio del libro: ";
	cin>>precio;
	cout<<"\n	Ingrese el stock: ";
	cin>>stock;
	system("cls");
	cout<<"\n	Aqui estan los datos del libro ingresado:";
	cout<<"\n	Libro: "<<nombre;
	cout<<"\n	Autor: "<<autor;
	cout<<"\n	Editorial: "<<editorial;
	cout<<"\n	Precio: "<<precio;
	cout<<"\n	Stock: "<<stock;
	libreria1.insertar(nombre,autor,editorial,precio,stock);
	cout<<"\n\n	Quiere ingresar otro libro? Presione 1";
	cout<<"\n	Su opcion: ";
	cin>>opc;
	system("cls");
	}while(opc==1);


	cout<<"\n	A registrado los libros de manera exitosa!\n\n";
	system("pause"); system("cls");
	personal(usuario);

}


	void personal(string &usuario){
		int opc;
	
		cout<<"\n	Bienvenido "<<usuario<<"!";
		cout<<"\n	Porfavor ingresar la opcion que desea realizar";
		cout<<"\n	Opcion 1. Ingresar libros a la biblioteca";
		cout<<"\n	Opcion 2. Imprimir el stock de libros";
		cout<<"\n	Opcione 3. Cerrar seccion";
		cout<<"\n\n	Su opcion: ";cin>>opc;
		switch(opc){
			case 1:
				system("cls");
				ingresarLibros(usuario);
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
				system("pause");
				personal(usuario);
				break;					
			
		}
	return;
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
		return;
	}
	return;	
	}

	void cliente(){

	}


};

	Libreria libreria1;//creacion del objeto universal

int main(){
	int opc;	

	do{
	system("cls");//limpia pantalla
	cout<<"\n	-----------------------------------------------------------------------------------------------------------------";
	cout<<"						BIENVENIDO A LA LIBRERIA!";
	cout<<"\n	-----------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n	Porfavor seleccionar si usted es personal o cliente";
	cout<<"\n\n	Presione 1. Si usted es personal.";
	cout<<"\n	Presione 2. Si usted es cliente.";
	cout<<"\n\n	Su opcion: ";
	cin>>opc;

	switch(opc){
		
		case 1: 
		system("cls");
		libreria1.seccion();
		break;

		case 2:
			system("cls");
			libreria1.cliente();
			break;
			
		default:
			cout<<"\n	Ingrese una opcion correcta\n\n";
			system("pause"); system("cls");	
			break;
	}

	}while(opc!=0);//ciclo para repetir menu

	return 0;
}