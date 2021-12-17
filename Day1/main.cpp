/* 
 * File:   main.cpp
 * Author: maral
 *
 * Created on 17 de diciembre de 2021, 12:39
 */

#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //Contador para el primer problema
    int contador = 0;
    
    //Contador para el segundo problema
    int contador2 = 0;
    
    //Vector de datos iniciales del fichero
    vector<int> vector_datos;
    
    //Vector para la suma de grupos de tres datos del problema dos
    vector<int> suma_vector;
    
    //Variable en la que se almacenará el dato leído
    string dato = "";
    
    //Volcado de datos en el vector
    ifstream entrada("datos.txt");

    while (getline(entrada, dato)) {
        
        //Se introducen los datos leídos en el vector
        vector_datos.push_back(stoi(dato));

    }
    entrada.close();

    //Contador para el primer problema, cuenta el número de veces que las medidas
    //superan a las anteriores
    for (int i = 1; i < vector_datos.size(); i++) {
        if (vector_datos[i] > vector_datos[i - 1]) {
            contador++;
        }
    }
    
    //Variable para almacenar la suma parcial a meter en el vector
    int suma_parcial=0;
    
    
    for (int i = 0; i < vector_datos.size(); i++) {
        //Inicialmente se asigna el primer valor a la suma
        suma_parcial=vector_datos[i];
        
        //En el caso en el que el siguiente dato sea distinto del último
        if(vector_datos[i+1]!=vector_datos[vector_datos.size()]){
            suma_parcial+=vector_datos[i+1];
        }
        
        //En el caso en el que el siguiente dato del siguiente dato sea distinto del último
        if(vector_datos[i+2]!=vector_datos[vector_datos.size()]){
            suma_parcial+=vector_datos[i+2];
        }
        
        //Se introduce en el vector la suma total para almacenarla
        suma_vector.push_back(suma_parcial);
    }

    //Contador para el segundo problema, cuenta el número de veces que las sumas
    //superan a las anteriores
    for (int i = 1; i < suma_vector.size(); i++) {
        if (suma_vector[i] > suma_vector[i - 1]) {
            contador2++;
        }
    }
    
    //Soluciones a los problemas mostrados en pantalla
    cout << "El número total de medidas que han incrementado es de: " << contador << " medidas." << endl;
    cout << "El número total de sumas de medidas que han incrementado es de: " << contador2 << " medidas." << endl;

    return 0;
}

