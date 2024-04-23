#include<iostream>
#include<time.h>
#include <cstring> 

using namespace std;
int destin;
int compraBoleto();
int primeraClase();
int segundaClase();
int usa();
int canada();
int europa();
int disponible();


	struct datos{
	char destino[20];
	char clase[20];
	char seccion;
	int seccion_num;
	int fila;
    int asientos[5][4]{};
    int asientosSegunda[25][6]{};
    char nombre[21];
    char apellido[21];
    char apellido2[30];
	};

void imprimir(datos informacion) {

    system("cls");
	cout<<"\n			VIVA AEROBUS!"<<endl;
    cout << "________________________________________________________________" << endl;
    cout << "\n	DESTINO "<<informacion.destino<< endl;
    cout << "	CLASE: " <<informacion.clase<< endl;
    cout << "	Cliente: " << informacion.apellido << " " << informacion.apellido2 << " " << informacion.nombre << endl;
    cout << "	Asiento: " <<informacion.seccion << informacion.fila << endl;
    cout << "________________________________________________________________" << endl;
    system("Pause");
}

	primeraClase(){
	system("cls");
	if(destin==1){
		int opcion;
	//se debe crear uns instancia para poder acceder a los datos de la estructura y solo usarla en esta seccion
	//static para que no se nos borren los datos de la matriz cada que entramos a la funcion
	static datos datos_ins_1c_usa;
	strcpy(datos_ins_1c_usa.destino, "ESTADOS UNIDOS");
	strcpy(datos_ins_1c_usa.clase, "PRIMERA CLASE");

	cout<<"\n	PRIMERA CLASE DESTINO ESTADOS UNIDOS"<<endl;		
	cout<<"\n	Los asientos disponibles estan marcados con 0 "<<endl;
	
	//Estamos mostrando los lugares disponibles
	cout<<"\nSeccion:A		B		C		D";
	cout<<"\n							   Fila:"<<endl; 	
    for (int i=0; i< 5; ++i) {
        for (int j=0; j<4; ++j) {
        	cout<<"	";
            cout <<datos_ins_1c_usa.asientos[i][j]<< "\t";
        }
        cout <<i+1<< endl;
    }
    cout << "\n Necesitamos que nos ayude a elegir el asiento que desea ocupar." << endl;
	cout<<"\n Ingrese la seccion ( A, B, C o D ) "<<endl;
	cout<<" Seccion: ";
	cin>>datos_ins_1c_usa.seccion;
	//Estamos convirtiendo la letra ingresada en un valor numerico para poder hacer la comparacion
	datos_ins_1c_usa.seccion_num =datos_ins_1c_usa.seccion - 'A';
	//estamos comparando que la letra ingresada este fuera de nuestro, regresamos a la funcion si esta fuera
	if(datos_ins_1c_usa.seccion_num<0||datos_ins_1c_usa.seccion_num>3){
		cout<<"\n	Seccion invalida."<<endl;
		system("Pause");
		primeraClase();	
	}
	
	cout<<"\n Ingrese la fila ( 1-5 ) "<<endl;
	cout<<" Fila: ";
	cin>>datos_ins_1c_usa.fila;
	//restamos 1 a la fila porque en nuestra matriz esta en el rango de 0-4, no de 1-5
	datos_ins_1c_usa.fila--;
	//igual si la fila esta fuera del rango nos va a regresar a la funcion
	if(datos_ins_1c_usa.fila<0||datos_ins_1c_usa.fila>4){
		cout<<"\n	Fila invalida."<<endl;
		system("Pause");
		primeraClase();	
	}
	//Si el asiento asignado es valido, ahora comparamos que el asiento este libre
	//Si el asiento es=0 esta libre, si tenemoos un 1, esta ocupado
	if(datos_ins_1c_usa.asientos[datos_ins_1c_usa.fila][datos_ins_1c_usa.seccion_num]==0){
		//entrando aqui es porque el asiento esta libre, le asignamos un 1 para considerarlo apartado
		datos_ins_1c_usa.asientos[datos_ins_1c_usa.fila][datos_ins_1c_usa.seccion_num]=1;
		//incrementamos la fila para que le podamos mostrar al usuario la fila en el rango de 1-5, no de 0-4
		datos_ins_1c_usa.fila++;
		cout<<"\n Su asiento "<<datos_ins_1c_usa.seccion<<datos_ins_1c_usa.fila<<" quedo reservado. "<<endl;
		//imprimir el asiento ya reservado para que el cliente vea que se reservo el asiento que el quizo
		cout<<"\nSeccion:A		B		C		D";
		cout<<"\n							   Fila:"<<endl;
		for (int i=0; i< 5; ++i) {
        for (int j=0; j<4; ++j) {
        	cout<<"	";
            cout <<datos_ins_1c_usa.asientos[i][j]<< "\t";
        }
        cout <<i+1<< endl;
    }
    cout<<""<<endl;
		system("Pause");		
		//en caso que el asiento que el usuario haya ingresado, lo regresaremos a la funcion para que elija otro
	}else{
		cout<<"\n El asiento esta ocupado, debe escoger otro asiento. "<<endl;
		system("Pause");
		primeraClase();
	}
	//pedimos datos al usuario
	system("cls");
	cout<<"\n	Por favor, ayudanos a ingresar unos datos."<<endl;
	cout<<"\n	Ingresa tu primer apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_1c_usa.apellido;
	cout<<"\n	Ingresa tu segundo apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_1c_usa.apellido2;
	cout<<"\n	Ingresa tu nombre: "<<endl;
	cout<<"	";
	cin>>datos_ins_1c_usa.nombre;
	
	cout<<"\n	Quedo listo su vuelo, estamos imprimiendo su boleto."<<endl;
	system("Pause");
	system("cls");
	//lo mandamos a imprimir el boleto para que pueda ver sus datos
	imprimir(datos_ins_1c_usa);
	//le preguntamos si desea comprar otro boleto o quiere salir al menu principal
	system("cls");
	cout<<"\n	Desea comprar otro boleto con destino hacia ESTADOS UNIDOS?"<<endl;
	cout<<"\n	Presiona 1 si desea comprar otro boleto en primera clase";
	cout<<"\n	Presione 2 si desea comprar otro boleto en segunda clase";
	cout<<"\n	Ingrese otra tecla si desea salir al menu principal."<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1:
			destin=1;
			primeraClase();
			break;
		case 2:
			destin=1;
			segundaClase();
			break;
		default:
			destin=0;
			cout<<"\n	Gracias por su compra!"<<endl;
			break;
	}
}
if(destin==2){
	int opcion;
	//se debe crear uns instancia para poder acceder a los datos de la estructura y solo usarla en esta seccion
	//static para que no se nos borren los datos de la matriz cada que entramos a la funcion
	static datos datos_ins_1c_can;
	strcpy(datos_ins_1c_can.destino, "CANADA");
	strcpy(datos_ins_1c_can.clase, "PRIMERA CLASE");

	cout<<"\n	PRIMERA CLASE DESTINO CANADA"<<endl;		
	cout<<"\n	Los asientos disponibles estan marcados con 0 "<<endl;
	
	//Estamos mostrando los lugares disponibles
	cout<<"\nSeccion:A		B		C		D";
	cout<<"\n							   Fila:"<<endl; 	
    for (int i=0; i< 5; ++i) {
        for (int j=0; j<4; ++j) {
        	cout<<"	";
            cout <<datos_ins_1c_can.asientos[i][j]<< "\t";
        }
        cout <<i+1<< endl;
    }
    cout << "\n Necesitamos que nos ayude a elegir el asiento que desea ocupar." << endl;
	cout<<"\n Ingrese la seccion ( A, B, C o D ) "<<endl;
	cout<<" Seccion: ";
	cin>>datos_ins_1c_can.seccion;
	//Estamos convirtiendo la letra ingresada en un valor numerico para poder hacer la comparacion
	datos_ins_1c_can.seccion_num =datos_ins_1c_can.seccion - 'A';
	//estamos comparando que la letra ingresada este fuera de nuestro, regresamos a la funcion si esta fuera
	if(datos_ins_1c_can.seccion_num<0||datos_ins_1c_can.seccion_num>3){
		cout<<"\n	Seccion invalida."<<endl;
		system("Pause");
		primeraClase();	
	}
	
	cout<<"\n Ingrese la fila ( 1-5 ) "<<endl;
	cout<<" Fila: ";
	cin>>datos_ins_1c_can.fila;
	//restamos 1 a la fila porque en nuestra matriz esta en el rango de 0-4, no de 1-5
	datos_ins_1c_can.fila--;
	//igual si la fila esta fuera del rango nos va a regresar a la funcion
	if(datos_ins_1c_can.fila<0||datos_ins_1c_can.fila>4){
		cout<<"\n	Fila invalida."<<endl;
		system("Pause");
		primeraClase();	
	}
	//Si el asiento asignado es valido, ahora comparamos que el asiento este libre
	//Si el asiento es=0 esta libre, si tenemoos un 1, esta ocupado
	if(datos_ins_1c_can.asientos[datos_ins_1c_can.fila][datos_ins_1c_can.seccion_num]==0){
		//entrando aqui es porque el asiento esta libre, le asignamos un 1 para considerarlo apartado
		datos_ins_1c_can.asientos[datos_ins_1c_can.fila][datos_ins_1c_can.seccion_num]=1;
		//incrementamos la fila para que le podamos mostrar al usuario la fila en el rango de 1-5, no de 0-4
		datos_ins_1c_can.fila++;
		cout<<"\n Su asiento "<<datos_ins_1c_can.seccion<<datos_ins_1c_can.fila<<" quedo reservado. "<<endl;
		//imprimir el asiento ya reservado para que el cliente vea que se reservo el asiento que el quizo
		cout<<"\nSeccion:A		B		C		D";
		cout<<"\n							   Fila:"<<endl;
		for (int i=0; i< 5; ++i) {
        for (int j=0; j<4; ++j) {
        	cout<<"	";
            cout <<datos_ins_1c_can.asientos[i][j]<< "\t";
        }
        cout <<i+1<< endl;
    }
    cout<<""<<endl;
		system("Pause");		
		//en caso que el asiento que el usuario haya ingresado, lo regresaremos a la funcion para que elija otro
	}else{
		cout<<"\n El asiento esta ocupado, debe escoger otro asiento. "<<endl;
		system("Pause");
		primeraClase();
	}
	//pedimos datos al usuario
	system("cls");
	cout<<"\n	Por favor, ayudanos a ingresar unos datos."<<endl;
	cout<<"\n	Ingresa tu primer apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_1c_can.apellido;
	cout<<"\n	Ingresa tu segundo apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_1c_can.apellido2;
	cout<<"\n	Ingresa tu nombre: "<<endl;
	cout<<"	";
	cin>>datos_ins_1c_can.nombre;
	
	cout<<"\n	Quedo listo su vuelo, estamos imprimiendo su boleto."<<endl;
	system("Pause");
	system("cls");
	//lo mandamos a imprimir el boleto para que pueda ver sus datos
	imprimir(datos_ins_1c_can);
	//le preguntamos si desea comprar otro boleto o quiere salir al menu principal
	system("cls");
	cout<<"\n	Desea comprar otro boleto con destino hacia CANADA?"<<endl;
	cout<<"\n	Presiona 1 si desea comprar otro boleto en primera clase";
	cout<<"\n	Presione 2 si desea comprar otro boleto en segunda clase";
	cout<<"\n	Ingrese otra tecla si desea salir al menu principal."<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1:
			destin=2;
			primeraClase();
			break;
		case 2:
			destin=2;
			segundaClase();
			break;
		default:
			destin=0;
			cout<<"\n	Gracias por su compra!"<<endl;
			break;
	}
}
if(destin==3){
	int opcion;
	//se debe crear uns instancia para poder acceder a los datos de la estructura y solo usarla en esta seccion
	//static para que no se nos borren los datos de la matriz cada que entramos a la funcion
	static datos datos_ins_1c_eu;
	strcpy(datos_ins_1c_eu.destino, "EUROPA");
	strcpy(datos_ins_1c_eu.clase, "PRIMERA CLASE");

	cout<<"\n	PRIMERA CLASE DESTINO EUROPA"<<endl;		
	cout<<"\n	Los asientos disponibles estan marcados con 0 "<<endl;
	
	//Estamos mostrando los lugares disponibles
	cout<<"\nSeccion:A		B		C		D";
	cout<<"\n							   Fila:"<<endl; 	
    for (int i=0; i< 5; ++i) {
        for (int j=0; j<4; ++j) {
        	cout<<"	";
            cout <<datos_ins_1c_eu.asientos[i][j]<< "\t";
        }
        cout <<i+1<< endl;
    }
    cout << "\n Necesitamos que nos ayude a elegir el asiento que desea ocupar." << endl;
	cout<<"\n Ingrese la seccion ( A, B, C o D ) "<<endl;
	cout<<" Seccion: ";
	cin>>datos_ins_1c_eu.seccion;
	//Estamos convirtiendo la letra ingresada en un valor numerico para poder hacer la comparacion
	datos_ins_1c_eu.seccion_num =datos_ins_1c_eu.seccion - 'A';
	//estamos comparando que la letra ingresada este fuera de nuestro, regresamos a la funcion si esta fuera
	if(datos_ins_1c_eu.seccion_num<0||datos_ins_1c_eu.seccion_num>3){
		cout<<"\n	Seccion invalida."<<endl;
		system("Pause");
		primeraClase();	
	}
	
	cout<<"\n Ingrese la fila ( 1-5 ) "<<endl;
	cout<<" Fila: ";
	cin>>datos_ins_1c_eu.fila;
	//restamos 1 a la fila porque en nuestra matriz esta en el rango de 0-4, no de 1-5
	datos_ins_1c_eu.fila--;
	//igual si la fila esta fuera del rango nos va a regresar a la funcion
	if(datos_ins_1c_eu.fila<0||datos_ins_1c_eu.fila>4){
		cout<<"\n	Fila invalida."<<endl;
		system("Pause");
		primeraClase();	
	}
	//Si el asiento asignado es valido, ahora comparamos que el asiento este libre
	//Si el asiento es=0 esta libre, si tenemoos un 1, esta ocupado
	if(datos_ins_1c_eu.asientos[datos_ins_1c_eu.fila][datos_ins_1c_eu.seccion_num]==0){
		//entrando aqui es porque el asiento esta libre, le asignamos un 1 para considerarlo apartado
		datos_ins_1c_eu.asientos[datos_ins_1c_eu.fila][datos_ins_1c_eu.seccion_num]=1;
		//incrementamos la fila para que le podamos mostrar al usuario la fila en el rango de 1-5, no de 0-4
		datos_ins_1c_eu.fila++;
		cout<<"\n Su asiento "<<datos_ins_1c_eu.seccion<<datos_ins_1c_eu.fila<<" quedo reservado. "<<endl;
		//imprimir el asiento ya reservado para que el cliente vea que se reservo el asiento que el quizo
		cout<<"\nSeccion:A		B		C		D";
		cout<<"\n							   Fila:"<<endl;
		for (int i=0; i< 5; ++i) {
        for (int j=0; j<4; ++j) {
        	cout<<"	";
            cout <<datos_ins_1c_eu.asientos[i][j]<< "\t";
        }
        cout <<i+1<< endl;
    }
    cout<<""<<endl;
		system("Pause");		
		//en caso que el asiento que el usuario haya ingresado, lo regresaremos a la funcion para que elija otro
	}else{
		cout<<"\n El asiento esta ocupado, debe escoger otro asiento. "<<endl;
		system("Pause");
		primeraClase();
	}
	//pedimos datos al usuario
	system("cls");
	cout<<"\n	Por favor, ayudanos a ingresar unos datos."<<endl;
	cout<<"\n	Ingresa tu primer apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_1c_eu.apellido;
	cout<<"\n	Ingresa tu segundo apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_1c_eu.apellido2;
	cout<<"\n	Ingresa tu nombre: "<<endl;
	cout<<"	";
	cin>>datos_ins_1c_eu.nombre;
	
	cout<<"\n	Quedo listo su vuelo, estamos imprimiendo su boleto."<<endl;
	system("Pause");
	system("cls");
	//lo mandamos a imprimir el boleto para que pueda ver sus datos
	imprimir(datos_ins_1c_eu);
	//le preguntamos si desea comprar otro boleto o quiere salir al menu principal
	system("cls");
	cout<<"\n	Desea comprar otro boleto con destino hacia EUROPA?"<<endl;
	cout<<"\n	Presiona 1 si desea comprar otro boleto en primera clase";
	cout<<"\n	Presione 2 si desea comprar otro boleto en segunda clase";
	cout<<"\n	Ingrese otra tecla si desea salir al menu principal."<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1:
			destin=3;
			primeraClase();
			break;
		case 2:
			destin=3;
			segundaClase();
			break;
		default:
			destin=0;
			cout<<"\n	Gracias por su compra!"<<endl;
			break;
	}
}
		
return 0;	
}

	segundaClase(){
	int opcion;
	system("cls");
if(destin==1){
	//se debe crear uns instancia para poder acceder a los datos de la estructura y no tener que crear otra estructura nueva
	//static para que no se nos borren los datos de la matriz cada que entramos a la funcion
	static datos datos_ins_2c_usa;
	strcpy(datos_ins_2c_usa.destino, "ESTADOS UNIDOS");
	strcpy(datos_ins_2c_usa.clase, "CLASE ECONOMICA");

	cout<<"\n		   CLASE ECONOMICA "<<endl;		
	cout<<"\n	Los asientos disponibles estan marcados con 0 "<<endl;
	
	cout<<"\nSeccion:A	B	C	D	E	F";
	cout<<"\n						   Fila:"<<endl;
   	//imprimimos los asientos para que el usuario pueda ver disponibilidad
    for (int i=0; i< 25; ++i) {
    	cout<<"	";
        for (int j=0; j<6; ++j) {
            cout <<datos_ins_2c_usa.asientosSegunda[i][j]<< "\t";
        }
        
        cout <<i+1<< endl;
    }
    //el usuario ingresa el asiento deseado
    cout << "\n Necesitamos que nos ayude a elegir el asiento que desea ocupar." << endl;
	cout<<"\n Ingrese la seccion ( A, B, C, D, E o F ) "<<endl;
	cout<<" Seccion: ";
	cin>>datos_ins_2c_usa.seccion;
	//convertimos la seccion a valor entero para poder hacer las comparaciones
	datos_ins_2c_usa.seccion_num =datos_ins_2c_usa.seccion - 'A';
	//si la seccion ingresada es invalida y esta fuera de la matriz lo regresamos a la funcion principal
	if(datos_ins_2c_usa.seccion_num<0||datos_ins_2c_usa.seccion_num>5){
		cout<<"\n	Seccion invalida."<<endl;
		system("Pause");
		segundaClase();	
	}
	//ingresamos fila
	cout<<"\n Ingrese la fila ( 1-25 ) "<<endl;
	cout<<" Fila: ";
	cin>>datos_ins_2c_usa.fila;
	//restamos 1 a la fila para que este dentro de los parametros 0-24
	datos_ins_2c_usa.fila--;
	//checamos que la fila este dentro de nuestra matriz
	if(datos_ins_2c_usa.fila<0||datos_ins_2c_usa.fila>24){
		cout<<"\n	Fila invalida."<<endl;
		system("Pause");
		segundaClase();	
	}
	cout<<"\n	Asiento libre, puede continuar!"<<endl<<endl;
	system("Pause"); system("cls");
	//si el asiento esta libre, queda reservado y le asignamos un 1 para que se vea ocupado
	if(datos_ins_2c_usa.asientosSegunda[datos_ins_2c_usa.fila][datos_ins_2c_usa.seccion_num]==0){
		datos_ins_2c_usa.asientosSegunda[datos_ins_2c_usa.fila][datos_ins_2c_usa.seccion_num]=1;
		datos_ins_2c_usa.fila++;
		cout<<"\n Su asiento "<<datos_ins_2c_usa.seccion<<datos_ins_2c_usa.fila<<" quedo reservado. "<<endl;
		//imprimir el asiento ya ocupado para que vea el usuario que el boleto que selecciono es el correcto   
		cout<<"\nSeccion:A	B	C	D	E	F";
		cout<<"\n						   Fila:"<<endl;
		for (int i=0; i< 25; ++i) {
    	cout<<"	";
        for (int j=0; j<6; ++j) {
            cout <<datos_ins_2c_usa.asientosSegunda[i][j]<< "\t";
        }
        
        cout <<i+1<< endl;
    }		
    cout<<""<<endl;
		system("Pause");		
		//si el boleto esta ocupado, el usuario debera elegir otro asiento y no podra continuar
	}else{
		cout<<"\n El asiento esta ocupado, debe escoger otro asiento. "<<endl;
		system("Pause");
		segundaClase();
	}
	
	system("cls");
	//ya que el usuario selcciono un asiento desocupado, puede ingresar sus datos
	cout<<"\n	Por favor, ayudanos a ingresar unos datos."<<endl;
	cout<<"\n	Ingresa tu primer apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_2c_usa.apellido;
	cout<<"\n	Ingresa tu segundo apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_2c_usa.apellido2;
	cout<<"\n	Ingresa tu nombre: "<<endl;
	cout<<"	";
	cin>>datos_ins_2c_usa.nombre;
	
	cout<<"\n	Quedo listo su vuelo, estamos imprimiendo su boleto."<<endl;
	system("Pause");
	system("cls");
	//mandamos a imprimir el boleto para que lo pueda ver el usuario
	imprimir(datos_ins_2c_usa);
	
	system("cls");
	//le preguntamos l usuario si desea comprar otro boleto del mismo destino
	destin=0;
	cout<<"\n	Desea comprar otro boleto con destino hacia ESTADOS UNIDOS?"<<endl;
	cout<<"\n	Presiona 1 si desea comprar otro boleto en primera clase";
	cout<<"\n	Presione 2 si desea comprar otro boleto en segunda clase";
	cout<<"\n	Ingrese otra tecla si desea salir al menu principal."<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1:
			destin=1;
			primeraClase();
			break;
		case 2:
			destin=1;
			segundaClase();
			break;
		default:
			destin=0;
			cout<<"\n	Gracias por su compra!"<<endl;
			break;
	}
}
if(destin==2){
	
	//se debe crear uns instancia para poder acceder a los datos de la estructura y no tener que crear otra estructura nueva
	//static para que no se nos borren los datos de la matriz cada que entramos a la funcion
	static datos datos_ins_2c_can;
	strcpy(datos_ins_2c_can.destino, "CANADA");
	strcpy(datos_ins_2c_can.clase, "CLASE ECONOMICA");

	cout<<"\n		   CLASE ECONOMICA CON DESTINO CANADA"<<endl;		
	cout<<"\n	Los asientos disponibles estan marcados con 0 "<<endl;
	
	cout<<"\nSeccion:A	B	C	D	E	F";
	cout<<"\n						   Fila:"<<endl;
   	//imprimimos los asientos para que el usuario pueda ver disponibilidad
    for (int i=0; i< 25; ++i) {
    	cout<<"	";
        for (int j=0; j<6; ++j) {
            cout <<datos_ins_2c_can.asientosSegunda[i][j]<< "\t";
        }
        
        cout <<i+1<< endl;
    }
    //el usuario ingresa el asiento deseado
    cout << "\n Necesitamos que nos ayude a elegir el asiento que desea ocupar." << endl;
	cout<<"\n Ingrese la seccion ( A, B, C, D, E o F ) "<<endl;
	cout<<" Seccion: ";
	cin>>datos_ins_2c_can.seccion;
	//convertimos la seccion a valor entero para poder hacer las comparaciones
	datos_ins_2c_can.seccion_num =datos_ins_2c_can.seccion - 'A';
	//si la seccion ingresada es invalida y esta fuera de la matriz lo regresamos a la funcion principal
	if(datos_ins_2c_can.seccion_num<0||datos_ins_2c_can.seccion_num>5){
		cout<<"\n	Seccion invalida."<<endl;
		system("Pause");
		segundaClase();	
	}
	//ingresamos fila
	cout<<"\n Ingrese la fila ( 1-25 ) "<<endl;
	cout<<" Fila: ";
	cin>>datos_ins_2c_can.fila;
	//restamos 1 a la fila para que este dentro de los parametros 0-24
	datos_ins_2c_can.fila--;
	//checamos que la fila este dentro de nuestra matriz
	if(datos_ins_2c_can.fila<0||datos_ins_2c_can.fila>24){
		cout<<"\n	Fila invalida."<<endl;
		system("Pause");
		segundaClase();	
	}
	cout<<"\n	Asiento libre, puede continuar!"<<endl<<endl;
	system("Pause"); system("cls");
	//si el asiento esta libre, queda reservado y le asignamos un 1 para que se vea ocupado
	if(datos_ins_2c_can.asientosSegunda[datos_ins_2c_can.fila][datos_ins_2c_can.seccion_num]==0){
		datos_ins_2c_can.asientosSegunda[datos_ins_2c_can.fila][datos_ins_2c_can.seccion_num]=1;
		datos_ins_2c_can.fila++;
		cout<<"\n Su asiento "<<datos_ins_2c_can.seccion<<datos_ins_2c_can.fila<<" quedo reservado. "<<endl;
		//imprimir el asiento ya ocupado para que vea el usuario que el boleto que selecciono es el correcto   
		cout<<"\nSeccion:A	B	C	D	E	F";
		cout<<"\n						   Fila:"<<endl;
		for (int i=0; i< 25; ++i) {
    	cout<<"	";
        for (int j=0; j<6; ++j) {
            cout <<datos_ins_2c_can.asientosSegunda[i][j]<< "\t";
        }
        
        cout <<i+1<< endl;
    }		
    cout<<""<<endl;
		system("Pause");		
		//si el boleto esta ocupado, el usuario debera elegir otro asiento y no podra continuar
	}else{
		cout<<"\n El asiento esta ocupado, debe escoger otro asiento. "<<endl;
		system("Pause");
		segundaClase();
	}
	
	system("cls");
	//ya que el usuario selcciono un asiento desocupado, puede ingresar sus datos
	cout<<"\n	Por favor, ayudanos a ingresar unos datos."<<endl;
	cout<<"\n	Ingresa tu primer apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_2c_can.apellido;
	cout<<"\n	Ingresa tu segundo apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_2c_can.apellido2;
	cout<<"\n	Ingresa tu nombre: "<<endl;
	cout<<"	";
	cin>>datos_ins_2c_can.nombre;
	
	cout<<"\n	Quedo listo su vuelo, estamos imprimiendo su boleto."<<endl;
	system("Pause");
	system("cls");
	//mandamos a imprimir el boleto para que lo pueda ver el usuario
	imprimir(datos_ins_2c_can);
	
	system("cls");
	//le preguntamos l usuario si desea comprar otro boleto del mismo destino
	destin=0;
	cout<<"\n	Desea comprar otro boleto con destino hacia CANADA?"<<endl;
	cout<<"\n	Presiona 1 si desea comprar otro boleto en primera clase";
	cout<<"\n	Presione 2 si desea comprar otro boleto en segunda clase";
	cout<<"\n	Ingrese otra tecla si desea salir al menu principal."<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1:
			destin=2;
			primeraClase();
			break;
		case 2:
			destin=2;
			segundaClase();
			break;
		default:
			destin=0;
			cout<<"\n	Gracias por su compra!"<<endl;
			break;
	}
}
if(destin==3){
	//se debe crear uns instancia para poder acceder a los datos de la estructura y no tener que crear otra estructura nueva
	//static para que no se nos borren los datos de la matriz cada que entramos a la funcion
	static datos datos_ins_2c_eu;
	strcpy(datos_ins_2c_eu.destino, "EUROPA");
	strcpy(datos_ins_2c_eu.clase, "CLASE ECONOMICA");

	cout<<"\n		   CLASE ECONOMICA CON DESTINO EUROPA"<<endl;		
	cout<<"\n	Los asientos disponibles estan marcados con 0 "<<endl;
	
	cout<<"\nSeccion:A	B	C	D	E	F";
	cout<<"\n						   Fila:"<<endl;
   	//imprimimos los asientos para que el usuario pueda ver disponibilidad
    for (int i=0; i< 25; ++i) {
    	cout<<"	";
        for (int j=0; j<6; ++j) {
            cout <<datos_ins_2c_eu.asientosSegunda[i][j]<< "\t";
        }
        
        cout <<i+1<< endl;
    }
    //el usuario ingresa el asiento deseado
    cout << "\n Necesitamos que nos ayude a elegir el asiento que desea ocupar." << endl;
	cout<<"\n Ingrese la seccion ( A, B, C, D, E o F ) "<<endl;
	cout<<" Seccion: ";
	cin>>datos_ins_2c_eu.seccion;
	//convertimos la seccion a valor entero para poder hacer las comparaciones
	datos_ins_2c_eu.seccion_num =datos_ins_2c_eu.seccion - 'A';
	//si la seccion ingresada es invalida y esta fuera de la matriz lo regresamos a la funcion principal
	if(datos_ins_2c_eu.seccion_num<0||datos_ins_2c_eu.seccion_num>5){
		cout<<"\n	Seccion invalida."<<endl;
		system("Pause");
		segundaClase();	
	}
	//ingresamos fila
	cout<<"\n Ingrese la fila ( 1-25 ) "<<endl;
	cout<<" Fila: ";
	cin>>datos_ins_2c_eu.fila;
	//restamos 1 a la fila para que este dentro de los parametros 0-24
	datos_ins_2c_eu.fila--;
	//checamos que la fila este dentro de nuestra matriz
	if(datos_ins_2c_eu.fila<0||datos_ins_2c_eu.fila>24){
		cout<<"\n	Fila invalida."<<endl;
		system("Pause");
		segundaClase();	
	}
	cout<<"\n	Asiento libre, puede continuar!"<<endl<<endl;
	system("Pause"); system("cls");
	//si el asiento esta libre, queda reservado y le asignamos un 1 para que se vea ocupado
	if(datos_ins_2c_eu.asientosSegunda[datos_ins_2c_eu.fila][datos_ins_2c_eu.seccion_num]==0){
		datos_ins_2c_eu.asientosSegunda[datos_ins_2c_eu.fila][datos_ins_2c_eu.seccion_num]=1;
		datos_ins_2c_eu.fila++;
		cout<<"\n Su asiento "<<datos_ins_2c_eu.seccion<<datos_ins_2c_eu.fila<<" quedo reservado. "<<endl;
		//imprimir el asiento ya ocupado para que vea el usuario que el boleto que selecciono es el correcto   
		cout<<"\nSeccion:A	B	C	D	E	F";
		cout<<"\n						   Fila:"<<endl;
		for (int i=0; i< 25; ++i) {
    	cout<<"	";
        for (int j=0; j<6; ++j) {
            cout <<datos_ins_2c_eu.asientosSegunda[i][j]<< "\t";
        }
        
        cout <<i+1<< endl;
    }		
    cout<<""<<endl;
		system("Pause");		
		//si el boleto esta ocupado, el usuario debera elegir otro asiento y no podra continuar
	}else{
		cout<<"\n El asiento esta ocupado, debe escoger otro asiento. "<<endl;
		system("Pause");
		segundaClase();
	}
	
	system("cls");
	//ya que el usuario selcciono un asiento desocupado, puede ingresar sus datos
	cout<<"\n	Por favor, ayudanos a ingresar unos datos."<<endl;
	cout<<"\n	Ingresa tu primer apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_2c_eu.apellido;
	cout<<"\n	Ingresa tu segundo apellido: "<<endl;
	cout<<"	";
	cin>>datos_ins_2c_eu.apellido2;
	cout<<"\n	Ingresa tu nombre: "<<endl;
	cout<<"	";
	cin>>datos_ins_2c_eu.nombre;
	
	cout<<"\n	Quedo listo su vuelo, estamos imprimiendo su boleto."<<endl;
	system("Pause");
	system("cls");
	//mandamos a imprimir el boleto para que lo pueda ver el usuario
	imprimir(datos_ins_2c_eu);
	
	system("cls");
	//le preguntamos l usuario si desea comprar otro boleto del mismo destino
	destin=0;
	cout<<"\n	Desea comprar otro boleto con destino hacia EUROPA?"<<endl;
	cout<<"\n	Presiona 1 si desea comprar otro boleto en primera clase";
	cout<<"\n	Presione 2 si desea comprar otro boleto en segunda clase";
	cout<<"\n	Ingrese otra tecla si desea salir al menu principal."<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1:
			destin=3;
			primeraClase();
			break;
		case 2:
			destin=3;
			segundaClase();
			break;
		default:
			destin=0;
			cout<<"\n	Gracias por su compra!"<<endl;
			break;
	}
}
return 0;	
}
//Aqui inicia el codigo con destino a europa
europa(){
system("cls");
	int opcion;
	//se le pregunta al usuario si desea voolar en primera o segunda clase 
	cout<<"\n	USTED ELIGIO VOLAR A EUROPA"<<endl;
	cout<<"\n	Presione 1 si desea volar en primera clase"<<endl;
	cout<<"	Presione 2 si desea volar en clase economica"<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opcion;
	//se manda al usuario a la seccion de primera o segunda clase, dependiendo que haya elegido
	switch(opcion){
		case 1: 
			primeraClase();
			break;
			
		case 2:
			segundaClase();
			break;	
		default:
		cout<<"\n	Ingrese una opcion correcta"<<endl<<endl;
		system("pause"); system("cls");	
		canada();
		break;	
	}	
	return 0;
}
	//Aqui inicia el codigo con destino a canada
canada(){
	system("cls");
	int opcion;
	//se le pregunta al usuario si desea voolar en primera o segunda clase 
	cout<<"\n	USTED ELIGIO VOLAR A CANADA"<<endl;
	cout<<"\n	Presione 1 si desea volar en primera clase"<<endl;
	cout<<"	Presione 2 si desea volar en clase economica"<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opcion;
	//se manda al usuario a la seccion de primera o segunda clase, dependiendo que haya elegido
	switch(opcion){
		case 1: 
			primeraClase();
			break;
			
		case 2:
			segundaClase();
			break;	
		default:
		cout<<"\n	Ingrese una opcion correcta"<<endl<<endl;
		system("pause"); system("cls");	
		canada();
		break;	
	}
	
	return 0;
}
//aqui inicia el codigo para el usuario que eligio volar a estados unidos
	usa(){
	system("cls");
	int opcion;
	cout<<"\n	USTED ELIGIO VOLAR A ESTADOS UNIDOS"<<endl;
	cout<<"\n	Presione 1 si desea volar en primera clase"<<endl;
	cout<<"	Presione 2 si desea volar en clase economica"<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opcion;
	//se le manda a la funcion de primera o segunda clase, dependiento que haya elegido
	switch(opcion){
		case 1: 
			primeraClase();
			break;
			
		case 2:
			segundaClase();
			break;
		default:
		cout<<"\n	Ingrese una opcion correcta"<<endl<<endl;
		system("pause"); system("cls");	
		usa();
		break;		
	}
	return 0;
}
//si el usuario decide comprar un boleto se pregunta hacia donde desea vajar
	compraBoleto(){
	system("cls");
	cout<<"\n	USTED ELIGIO COMPRAR UN BOLETO!."<<endl;
	cout<<"\n	Presione 1 si desea viajar a Estados Unidos.";
	cout<<"\n	Presione 2 si desea viajar a Canada.";
	cout<<"\n	Presione 3 si desea viajar a Europa."<<endl;
	cout<<"\n	Su opcion: ";
	cin>>destin;
	switch(destin){
		case 1:
			usa();
			break;
		case 2:
			canada();
			break;
		case 3:
			europa();
			break;
			
		default: 
		cout<<"\n	Ingrese una opcion correcta."<<endl<<endl;
		system("pause");
		compraBoleto();		
	}
	return 0;
}


int main(){
	int opcion;
	//este do nos sirve como ciclo para que el usuario desee cuando salir del programa
	do{
	if(opcion==1){
		//inicio del programa con una presentacion
	//-------------------------------------------------------------------------------
	cout<<"\n	BIENVENDIDO A LA AEROLINEA VIVA AEROBUS!"<<endl;
	cout<<"	Usted volara desde la Ciudad de Mexico"<<endl;
	cout<<"\n	Si desea comprar un boleto presione 1."<<endl;
	cout<<"	Si desea ver los asientos ocupados presione 2."<<endl;
	cout<<"\n	Su opcion: ";
	cin>>opcion;
	//si el usuario desea comprar un boleto se le envia a la funcion correspondiente
	switch(opcion){
		case 1: 
			compraBoleto();
			break;	
			
		default:
		cout<<"\n	Ingrese una opcion correcta"<<endl<<endl;
			system("pause"); system("cls");	
			main();
			break;		
	}
	
	system("pause");	system("cls");
	}	
	//este es el primer mensaje que ve el usuario al ingresar al programa
	cout<<""<<endl;
		cout<<"	DESEA INGRESAR A LA AEROLINEA?"<<endl<<endl;
		cout<<"	Presione 1	"<<endl;
		cout<<"	De lo contrario presione otra tecla si desea salir del programa."<<endl;
		cout<<"\n	Su opcion: ";
		cin>>opcion;	system("cls");
		}while(opcion==1);
}
