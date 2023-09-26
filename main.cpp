#include <iostream>
#include "VDinamico.h"
#include <cstdlib>

/**
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @return 0
 */

int main() {
    int tam=1000;
    VDinamico<int> vector(tam);
    int i=0;

    try {
        while (i<tam){
            bool encontrado=false;
            int numero = rand()%100000+67700;
            
            for (int j = 0; j < i && !encontrado; j++) {
                if (vector[j] == numero){
                    encontrado= true;
                }
            }

            if(!encontrado){
                vector[i]=numero;
                std::cout<<std::endl<< "i ="<< i;
                std::cout<<" ,numero: "<<vector[i]<<std::endl;
                i++;
            }

        }

        vector.ordena();
        std::cout<<std::endl<<"Vector ordenado de menor a mayor:"<<std::endl;
        for (int j = 0; j <20; j++) {
            std::cout<<"Numero "<<j+1<<" : ";
            std::cout << vector[j] << std::endl;
        }

        vector.ordenaRev();
        std::cout<<"Vector ordenado de mayor a menor:"<<std::endl;
        for (int j = 0; j <20; j++) {
            std::cout<<"Numero "<<j+1<<" : ";
            std::cout << vector[j] << std::endl;
        }

    } catch (std::invalid_argument &error) {
        std::cerr<<error.what()<<std::endl;
    } catch (std::out_of_range &error) {
        std::cerr << error.what() << std::endl;
    } catch (std::bad_alloc &error) {
        std::cerr << error.what() << std::endl;
    }

    return 0;
}
