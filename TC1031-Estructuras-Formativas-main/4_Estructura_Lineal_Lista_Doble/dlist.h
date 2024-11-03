/*
Yumee Chung
A01712059

Fecha: lunes, 23 de septiembre de 2024

Materia: Programación de estructuras de datos y algoritmos fundamentales
 
Tarea4: Lista doblemente encadenada 
*/

#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class DList;

template <class T> class DLink{
    private:
        DLink(T);
        DLink(T, DLink<T>*, DLink<T>*);
        DLink(const DLink<T>&);

        T value;
        DLink<T> *previous;
        DLink<T> *next;

        friend class DList<T>;
};

template <class T> 
DLink<T>::DLink(T val):value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
    private:

        DLink<T> *head;
        DLink<T> *tail;
        int size;
        void clear();

    public:
        DList();
        ~DList();

        void insertion (T);
        int search(T) const;
        void update(int, T);
        void deleteAt(int);

        string toStringBackward() const;
        string toStringForward() const;
};

template <class T>
DList<T>::DList():head(0),tail(0),size(0) {}

template <class T>
DList<T>::~DList(){
    clear();
}

template <class T>
void DList<T>::clear(){
    DLink<T> *p, *q;
    p = head;
    while(p != 0){
        q = p->next;
        delete p;
        p = q;
    }
    head = 0;
    tail = 0;
    size = 0;
}

template <class T>
void DList<T>::insertion(T val){
    DLink<T> *newLink = new DLink<T>(val);
    if (head == 0){
        head = tail = newLink;
    } else {
        tail->next = newLink;
        newLink->previous = tail;
        tail = newLink;
    }
    size++;
}

template <class T>
int DList<T>::search(T val) const {
    DLink<T> *p = head;
    int index = 0;
    while(p != 0){
        if(p->value == val){
            return index;
        }
        p = p->next;
        index++;
    }
    return -1;
}

template <class T>
void DList<T>::update(int index, T val){
    DLink<T> *p = head;
    int i = 0;
    while (p != 0 && i < index) {
        p = p->next;
        i++;
    }
    if(p != 0){
        p->value = val;
    }
}

template <class T>
void DList<T>::deleteAt(int index){

    int pos = 0;
    DLink<T> *p, *q;

    p = head; 

    if(index == 0){ //cuando quiere eliminar en la lista 0
        
        p = p->next;
        p->previous = 0;
        delete head;
        head = p;

    } else if(index == size){
        p = tail;
        q = p->previous;
        q->next = 0;
        delete p;
        tail = q;
    }
    
    else {
        while (pos != index){
            p = p->next;
            pos++;
        }
        q = p->next;
        q->previous = p->previous;
        p->previous->next = q;
        delete p;
    }
    size --;
}

template <class T>
string DList<T>::toStringForward() const {
	stringstream aux;
	DLink<T> *p;

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

template <class T>
string DList<T>::toStringBackward() const {
    stringstream aux;
    DLink<T> *p;

    p = tail;
    aux << "[";
    while (p != 0){
        aux << p->value;
        if (p->previous != 0){
            aux << ", ";
        }
        p = p->previous;
    }
    aux << "]";
    return aux.str();
}
#endif