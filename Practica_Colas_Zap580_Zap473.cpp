#include <iostream>
#include<conio.h>
using namespace std;

//Inicializamos variable global para comparar ultimo numero
int ultimoValor = 0;

//Inicializamos nodo 
struct nodo
{
    int data;
    nodo* next;
};

//creamos lista
class cola
{
    nodo* rear, * front;
public:
    cola()
    {
        rear = NULL; front = NULL;
    }
    void qinsert();
    void autoInsert(int);
    void qdelete();
    void qdisplay();
    void obtainLastNumber();
    ~cola();
};

//Metodo para insertar datos
void cola::qinsert()
{
    nodo* temp;
    temp = new nodo;
    cout << "Inserta valor numerico: " << endl;
    cin >> temp->data;
    temp->next = NULL;
    if (rear == NULL)
    {
        rear = temp;
        front = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

//Metodo automatico para insertar datos
void cola::autoInsert(int newData)
{
    nodo* temp;
    temp = new nodo;
    temp->data = newData;
    temp->next = NULL;
    if (rear == NULL)
    {
        rear = temp;
        front = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

//Metodo para borar datos
void cola::qdelete()
{
    if (front != NULL)
    {
        nodo* temp = front;
        cout << front->data << "Dato Borrado \n";
        front = front->next;
        delete temp;
        if (front == NULL)
            rear = NULL;
    }
    else
        cout << "cola Empty..";
}

//Metodo para mostrar datos
void cola::qdisplay()
{
    nodo* temp = front;
    cout << "+++++++DATOS ALMACENADOS+++++++" << endl;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << "++++++++++++++++++++++++++" << endl;
}

//Metodo para obtener el ultimo numero
void cola::obtainLastNumber() {
    nodo* temp = front;
    while (temp != NULL)
    {
        //Asignamos el ultimo valor a la variable global
        ultimoValor = temp->data;
        temp = temp->next;
    }
}

//Destructor, borra dato por dato
cola::~cola()
{
    while (front != NULL)
    {
        nodo* temp = front;
        front = front->next;
        delete temp;
    }
}

void main()
{
    //Inicializamos primera cola
    cola colaPrincipal; int op;
    do
    {
        cout << "--------------" << endl;
        cout << "1. Insertar Dato\n2. Borrar\n3. Mostrar datos\n4. Continuar" << endl;
        cout << "--------------" << endl;
        cin >> op;
        switch (op)
        {
        case 1: colaPrincipal.qinsert(); break;
        case 2: colaPrincipal.qdelete(); break;
        case 3: colaPrincipal.qdisplay();
        }
    } while (op != 4);

    //Inicializamos las colas extras
    cola numerosMayores;
    cola numerosMenores;

    //Inicializamos variables para el siguiente codigo
    int numeroNuevo = 0;
    bool esPrimo = false;
    string continuarCiclo = "";
    bool continuando = true;

	while (continuando == true) {

		cout << "Si ingresas un numero mayor al ultimo valor de la cola, se agregara en una cola de numeros mayores, debe ser primo" << endl;
		cout << "Si ingresas un numero menor al ultimo valor de la cola, se agregara en una cola de numeros menores, debe ser primo" << endl;
		cout << "Ingrese un valor numerico entero: " << endl;
		cin >> numeroNuevo;

		//Recorre la cola hasta encontrar el ultimo dato y lo guarda en una variable global
		colaPrincipal.obtainLastNumber();

		//Creamos un arreglo de numeros primos para comparar
		int arregloNumerosPrimos[25] = { 2,3,5,7,11,13,17,19,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };

		//Comprueba si es primo
		for (int i = 0; i <= 25; i++)
		{
			if (numeroNuevo == arregloNumerosPrimos[i]) {
				esPrimo = true;
			}
		}

		//Compara valores

		//En caso de que sea numero mayor
		if (esPrimo == true && numeroNuevo > ultimoValor) {
			numerosMayores.autoInsert(numeroNuevo);
		}

		//En caso de que sea numero menor
		if (esPrimo == true && numeroNuevo < ultimoValor) {
			numerosMenores.autoInsert(numeroNuevo);
		}

		//Imprime los 3 objetos
		cout << endl << endl << endl << endl << endl;
		if (esPrimo == false) {
			cout << "El valor ingresado no es un numero primo." << endl;
		}
		cout << "----------------------------------------------" << endl;
		cout << "Cola Oiriginal: " << endl;
		colaPrincipal.qdisplay();
		cout << "----------------------------------------------" << endl;
		cout << "Cola de Numeros Mayores: " << endl;
		numerosMayores.qdisplay();
		cout << "----------------------------------------------" << endl;
		cout << "Cola de Numeros Menores: " << endl;
		numerosMenores.qdisplay();
		cout << "----------------------------------------------" << endl;
		cout << endl << endl;

		cout << "Deseas continuar?(Si/No)" << endl;
		cin >> continuarCiclo;

		if (continuarCiclo == "No" || continuarCiclo == "no" || continuarCiclo == "NO") {
			continuando = false;
		}
	}
}
