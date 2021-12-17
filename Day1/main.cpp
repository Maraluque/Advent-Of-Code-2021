/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

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

    
    int contador=0;
    ifstream entrada("datos.txt");

    vector<int> vector_datos;
    string dato="";
    int num;

    while (getline(entrada, dato)) {

        vector_datos.push_back(stoi(dato));

    }
    entrada.close();
    
    for (int i=1; i< vector_datos.size(); i++){
        if(vector_datos[i]>vector_datos[i-1]){
            contador++;
        }
    }
    
    cout << "El número total de medidas que han incrementado es de: " << contador << " medidas." << endl;
    
    return 0;
}

