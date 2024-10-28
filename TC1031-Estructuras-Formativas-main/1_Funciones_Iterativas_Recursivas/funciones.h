/*
Yumee Chung
A01712059

Fecha: miércoles, 21 de agosto de 2024

Materia: Programación de estructuras de datos y algoritmos fundamentales
 
Tarea1: Funciones_Iterativas_Recursivas
*/

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <iostream>

class Funciones {
    protected:
        int n;
    public:
        //O(n)
        /*
        Es una iterativa con una complejidad de algoritmo lineal ya que la función sigue
        hasta que llegue el valor 'i' a 'n'. Se puede tardar dependiendo del tamaño de 'n',
        pero la función sólo hace suma de los valores hasta n. 
        */
        int sumaIterativa (int n){
            int acum = 0;
            for (int i = 1; i <= n; i++)
                acum = acum + i;
            return acum;
        }

        //O(n)
        /*
        La recursión tiene una complejidad de O(n) porque dependiendo de valor de n la función va realizar n pasos. Sin embargo,
        se puede observar que este recusión deja pendiente (+ n), entonces puede tomar más tiempo porque el código va ejecutar 
        primero la función (sumaRecursiva) y despues calcular todo el pendiente. 
        */
        int sumaRecursiva (int n){
            if (n == 0){
                return 0;
            }
            else {
                return sumaRecursiva(n - 1) + n;
            }
        }

        //O(1)
        /*
        La función de sumaDirecta tiene una complejidad de O(1) porque va tomar solo un paso para calcular
        el valor sum. La programa va calcular el sum a través de la fórmula y sólo necesita que sustituir 
        el valor n indicada. 
        */
        int sumaDirecta (int n){
            int sum = n*(n+1)/2;
            return sum;
        }
};

/*
CASOS DE PRUEBA:
- sumatoria n = 15 es 120
- sumatoria n = 10 es 55
*/
#endif 