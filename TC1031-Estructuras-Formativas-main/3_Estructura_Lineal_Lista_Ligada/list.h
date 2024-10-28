/*
Yumee Chung
A01712059

Fecha: lunes, 23 de septiembre de 2024

Materia: Programación de estructuras de datos y algoritmos fundamentales
 
Tarea3: Estructura Lineal Lista Ligada 
*/

#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class List; 

template <class T>
class Link {
private:
    T value;
    Link<T>* next; //node *next

    Link(T);
    Link(T, Link<T>*);

    friend class List<T>; //friend class para acceder a privagte de List
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link<T>* nxt) : value(val), next(nxt) {}

template <class T>
class List {
private:
    Link<T>* head;
    int size;

public:
    List();
    ~List();

	void clear();

    void insertion(T);
    int search(T) const;
    void update(int, T);
    void deleteAt(int);
    string toString() const;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

/* agregar nuevo valor en la lista*/
template <class T>
void List<T>::insertion(T val) {
    Link<T>* newLink = new Link<T>(val);
    if (head == 0) { //si no hay valor en head
        head = newLink; //agrega el valor nuevo como head
    } else { 
        Link<T>* p = head;
        while (p->next != 0) {
            p = p->next;
        }
        p->next = newLink;
    }
    size++;
}

/* buscar posición y devuelve la posición*/
template <class T>
int List<T>::search(T val) const {
    Link<T>* p = head;
    int index = 0;
    while (p != 0) {
        if (p->value == val) {
            return index;
        }
        p = p->next;
        index++;
    }
    return -1;
}

/* actualizar el valor en una posición dada */
template <class T>
void List<T>::update(int index, T val) {
    if (index < 0 || index >= size) {
        throw out_of_range("Índice inválido");
    }
    Link<T>* p = head;
    for (int i = 0; i < index; i++) { //ciclo para alcanzar a la posición 
        p = p->next; //p apunta a siguiente valor
    }
    p->value = val; //el valor se cambia al valor que usuario quiere cambiar
}

/* Eliminar el elemento en una posición dada */
template <class T>
void List<T>::deleteAt(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Índice inválido");
    }

    Link<T>* p = head;
    if (index == 0) { 
        head = head->next; //el head se cambia a siguiente valor, que está a lado
        delete p; //eliminar head 
    } else {
        Link<T>* q = 0;
        for (int i = 0; i < index; i++) { //ciclo para alcanzar a la posición
            q = p; //el nodo q se mueve a posición del p
            p = p->next; //p avanza y guarda el siguiente valor
        } //cuando el ciclo ya llega en la posición que el usuario quiere eliminar
        q->next = p->next; //el nodo q apunta el siguiente nodo (nodo apuntado por p) para que no deje el apuntador no apunte el valor eliminado
        delete p; 
    }
    size--; //tamaño de la lista reduce
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

/*
Iterator

- objeto secundario para poder recorrer una estructura de datos
*/
#endif
