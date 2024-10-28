/*
Yumee Chung
A01712059

Fecha: miércoles, 4 de septiembre de 2024

Materia: Programación de estructuras de datos y algoritmos fundamentales
 
Tarea2: Algoritmos_Busqueda_Ordenamiento 
*/

#ifndef SORTS_H
#define SORTS_H

template <class T>
class Sorts {
private:
    void swap(std::vector<T> &v, int i, int j);
    void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
public:
    void ordenaSeleccion(std::vector<T> &v); //No salida
    void ordenaBurbuja(std::vector<T> &v); //No salida
    void ordenaMerge(std::vector<T> &v); //No salida
    int busqSecuencial(const std::vector<T> &v, int);
    int busqBinaria(const std::vector<T> &v, int);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

/*complejidad: O(n^2)
porque necesita que correr todos los arreglos para comparar y ordenar y hacer swap
*/
template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &v) {
    int size = v.size();

    //Encontrando el mínimo
    for(int i = 0; i < size - 1; i++) {
        int min = i;
        for(int j = i + 1; j < size; j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(v, i, min);
        }
    }
}

/*complejidad: O(n^2)
porque como selectionsort corre todos los arreglos hasta que encontre su lugar. Pero,
para comparar el valor necesita que comparar cada valor hasta al final y regresar otra vez 
hacia el inicio para comprar todos los valores y encontrar su lugar correspondiente.
Burbuja = intercambiar el orden cuando no está en lugar correcto
*/
template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &v) {
    int size = v.size() - 1;
    for (int i = size; i > 0; i--) {
        for (int j = 0; j < i; j++) { 
            if (v[j] > v[j + 1]) { //checar si el orden está correcto
                swap(v, j, j + 1);
            }
        }
    }
}

//copiar arreglo para realizar el ordenamiento en B y guardar el arreglo ordenado en A
template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high){
    for (int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high){
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while( i <= mid &&j <= high){
        if (A[i] < A[j]){
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if ( i > mid){
        for(; j <= high; j++){
            B[k++] = A[j];
        }
    } else {
        for (; i <= mid; i++){
            B[k++] = A[i];
        }
    }
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high){
    int mid;

    if( (high - low) < 1){
        return;
    }
    mid = (high + low) / 2;
    mergeSplit(A, B, low, mid); //split right side
    mergeSplit(A, B, mid + 1, high); //split left side
    mergeArray(A, B, low, mid, high); //order 
    copyArray(A, B, low, high); //copy ordered array B to A
}

/* complejidad: O(n log(n))
porque ordenaMerge es como árbol, se divide a mitad hasta que llegue solo un objeto.
*/
template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &v){
    std::vector<T> tmp(v.size());

    mergeSplit(v, tmp, 0, v.size() - 1);
}

/*O(n) o O(log (n))
porque dependiendo del valor que estas buscando va variar los pasos que necesita
que correr.
*/
//Va regresar valor tipo int
template <class T>
int Sorts<T>::busqSecuencial(const std::vector<T> &v, int num){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == num){ //if the value located in i is equal to num
            return i; //return the location
        }
    }
    return -1; //if not return -1
}

/* complejidad: O(log(n))
porque divide el arreglo low, mid, high y dependiendo del num, si es mayor que mid
cambia a mid+1 y cuando num es menor mid high cambia a mid-1. Entonces no toma
todos los pasos de arreglo. 
*/
//Va regresar valor tipo int
template <class T>
int Sorts<T>::busqBinaria(const std::vector<T> &v, int num){
    int low = 0; //first value of array
    int high = v.size() - 1; 
    int mid;

    while (low < high){
        mid = (high + low)/2;
        if(num == v[mid]){ 
            return mid;
        } else if(num < v[mid]){ 
            high = mid - 1;
        } else if(num > v[mid]){
            low = mid + 1;
        }
    }
    return -1;
}

#endif