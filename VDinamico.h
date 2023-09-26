#include <iostream>
#include <stdexcept>
#include <algorithm>

#ifndef PRACTICA_1_VDINAMICO_H
#define PRACTICA_1_VDINAMICO_H

template<typename T>
class VDinamico {
private:
    T *vector;
    unsigned long int tam;

public:

    VDinamico(unsigned long int n);
    VDinamico(VDinamico &orig);
    VDinamico (const VDinamico &orig, unsigned int posicionInicial, unsigned int numElementos);
    T &operator[](unsigned long int pos);
    virtual ~VDinamico();
    VDinamico<T> &operator=(VDinamico &orig);
    void ordena();
    void ordenaRev();
};

/**
 * @brief Ordena el vector de menor a mayor con la funcion sort
 * @tparam T
 */

template<typename T>
void VDinamico<T>::ordena() {
    std::sort(vector,vector+tam);
}

/**
 * @brief Ordena el vector de mayor a menor
 * @tparam T
 * @param aux Variable auxiliar que nos ayuda a hacer la permutacion en el vector
 */

template<typename T>
void VDinamico<T>::ordenaRev() {
    std::sort(vector,vector+tam);
    T aux;
    for(int i=0;i<tam/2;i++){
        aux=vector[i];
        vector[i]=vector[tam-i-1];
        vector[tam-i-1]=aux;
    }
}

/**
 * @brief Constructor de copia parcial
 * @tparam T
 * @param origen Direccion de memoria del vector que vamos a copiar
 * @param posicioninicial   Posicion inicial del vector dinamico
 * @param numElementos      Le pasamos el numero de elementos que va a tener nuestro nuevo vector
 */

template<typename T>
VDinamico<T>::VDinamico(const VDinamico<T> &orig, unsigned int posicionInicial, unsigned int numElementos) {
    if(posicionInicial>orig.tam)
        throw std::out_of_range("La posicion inicial no puede ser mayor que el numero de elementos");

    delete [] vector;
    vector = new T [tam=numElementos] ;
    for(int i=0;i<tam;i++){
        vector[i]=orig.vector[posicionInicial+i];
    }
}

/**
 * @brief Operator igual para copiar la informacion de un vector en otro
 * @tparam T
 * @param orig vector del cual vamos a copiar las cosas
 * @return puntero con el nuevo vector
 */

template<typename T>
VDinamico<T> &VDinamico<T>::operator=(VDinamico<T> &orig) {
    if (this!=&orig){
        delete [] vector;
        tam=orig.tam;
        vector =new T [tam];
        for (int i=0;i<orig.tam;i++){
            vector[i]=orig.vector[i];
        }
        return *this;
    }
}

/**
 * @brief Constructor parametrizado
 * @tparam T tipo de elemento
 * @param n tam del vector
 */

template<typename T>
VDinamico<T>::VDinamico(unsigned long int n) {
    tam=n;
    vector =new int[tam];
}

/**
 * @brief Operator[] devuelve el contenido de la posicion del vector que se indica
 * @tparam T
 * @param pos Parametro en el que le pasamos la posicion que queremos de dicho vector
 * @return
 */

template<typename T>
T &VDinamico<T>::operator[](unsigned long pos)  {
    if(pos>=tam) {
        throw std::out_of_range("La posicion del vector no puede ser mayor que el tamaño");
    }
    return vector[pos];
}

/**
 * @brief Destructor del vector dinamico
 * @tparam T
 */

template<typename T>
VDinamico<T>::~VDinamico(){
    delete [] vector;
}

/**
 * @brief Constructor copia
 * @tparam T
 * @param origen Direccion de memoria del vector que vamos a copiar
 */
template<typename T>
VDinamico<T>::VDinamico(VDinamico<T> &orig) {
    delete [] vector;
    tam=orig.tam;
    vector =new T [tam];
    for (int i=0;i<orig.tam;i++){
        vector[i]=orig.vector[i];
    }
}



#endif //PRACTICA_1_VDINAMICO_H
