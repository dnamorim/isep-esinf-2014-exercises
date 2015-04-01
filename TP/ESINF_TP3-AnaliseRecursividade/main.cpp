/* 
 * File:   main.cpp
 * Author: dnamorim
 *
 * Created on 20 de Outubro de 2014, 15:18
 */
#include <iostream>
#include <cstdlib>

using namespace std;

void printVec(int a[], int ls, const string txt) {
    cout << txt << ": ";
    for (int i = 0; i < ls; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

}

/**
 * Inverter um segmento de um vector
 * 
 * Complexidade BigOh: linear (varia de 8 a 2)
 * @param a
 * @param liminf
 * @param limsup
 */
void processa(int a[], int liminf, int limsup) {
    int i=liminf;
    int j=limsup-1;
    
    while(i < j) {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
    
}

/**
 * Subdivide a meio um vector, gerando segmentos.
 * Para cada segmento, inverte os valores
 * Método Recursivo.
 * 
 * Complexidade BigOh: log^2(n) - logarítmica
 * @param a
 * @param li
 * @param ls
 */
void exemplo(int a[], int li, int ls) {
    if(li < ls) {
        printVec(a, ls, "Inicial");
        processa(a, li, ls);
        printVec(a, ls, "Final");
        cout << endl;
        ls=ls/2;
        exemplo(a, li, ls);
    }
}

int main(int argc, char** argv) {
    int a[8] = {6, 1, 4, 2, 7, 3, 1, 5};
    int li=0, ls=8;
    
    exemplo(a, li, ls);
    
    return 0;
}

