/******************************************************************************

  Taller Estructura de Datos
  Cesar Andres Morales Hincapie
  14474751
  
  Realice un programa que permita registrar clientes.
  De cada cliente se debe registrar, nombre, el cupo de
  crédito y el cupo usado.
  El programa debe permitir mostrar todos los clientes.
  El programa permite mostrar los clientes cuyo cupo
  usado sea superior al 80%.
  El programa permite calcular el total de créditos por
  cobrar.
  Realizar una segunda lista en orden ascendente siendo la
  cabeza el menor cupo de crédito y así sucesivamente hasta
  el mayor cupo de crédito.

 ******************************************************************************/




#include <iostream>
#include <stdlib.h>

using namespace std;

struct cliente{

	char nombre[30];
	int cupo;
	int cupoUsado;
	cliente *sig;
};
cliente *cabeza, *aux, *aux2;


void registrar(){
    //Entra aqui cuando no existe la cabeza o sea el primer elemento
    if(!cabeza){
        cabeza = (struct cliente *)malloc(sizeof(struct cliente));
        cout<<"Registre nombre: ";
        cin>>cabeza->nombre;
        cout<<"Valor del Cupo: ";
        cin>>cabeza->cupo;
        cout<<"Valor del Cupo Usado: ";
        cin>>cabeza->cupoUsado;
        cabeza->sig = NULL;
    }  else {
        aux = cabeza;
        while(aux->sig != NULL) {
            aux = aux->sig;
        }

        aux2 = (struct cliente *)malloc(sizeof(struct cliente));
        cout<<"Registre nombre: ";
        cin>>aux2->nombre;
        cout<<"Valor del cupo: ";
        cin>>aux2->cupo;
        cout<<"Valor del cupo Usado: ";
        cin>>aux2->cupoUsado;
        aux2->sig = NULL;
        aux->sig = aux2;
        aux = aux2 = NULL;
        free(aux);
        free(aux2);
    }

};

int sobregiro(){
    for(aux=cabeza;aux !=NULL;aux=aux->sig){
        float sobregiro1 =((aux->cupoUsado*100)/aux->cupo);
        cout<<"nombre cliente: " <<aux-> nombre <<sobregiro1<<endl;
                if (sobregiro1>80){
                    cout<<"nombre cliente: " <<aux-> nombre << " su cupo a excedido el tope permitido: "<<sobregiro1<<endl;
                }
    }

};

void mostrar(){
    for(aux = cabeza; aux!=NULL; aux=aux->sig){
        cout<<"----------------------------------------"<<endl;
        cout<<"Nombre: "<<aux->nombre<<endl;
        cout<<"Cupo Aprovado: "<<aux->cupo<<endl;
	cout<<"Cupo usado: "<<aux->cupoUsado<<endl;
	//cout<<"cupo Alcanzado: "<<aux->cupoUsado<<endl;

    }
    free(aux);
};

int main(){
    int opcion=0;
    do{
        cout<<"Menu "<< endl<<"1. Registrar Cliente"<<endl<<"2. Mostrar Cliente" <<endl<<"3. Consultar Cupo"<<endl<<"5. Salir"<<endl;
        cin>>opcion;
        switch(opcion) {
            case 1: registrar(); break;
            case 2: mostrar(); break;
            case 3: sobregiro(); break;
        }

    } while(opcion != 5);

    return 0;
}


