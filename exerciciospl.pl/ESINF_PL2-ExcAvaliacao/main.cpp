/* 
 * File:   main.cpp
 * Author: dnamorim
 *
 * Created on 16 de Outubro de 2014, 17:24
 */

#include <iostream>
#include <cstdlib>
#include <list>
#include <cmath>
#include <stdlib.h>
#include <time.h>  

using namespace std;

/*
 * Considere as temperaturas ocorridas a cada hora durante um dia completo são registadas numa lista STL.
 * Exemplo: list<int> dia1 = {37, 30, 7, ...}
 * 
 * Implemente função que recebe a lista por argumento e determine:
 * - imprimir a temperatura a cada hora e o respectivo desvio padrão.
 * - Devolva os desvios das temperaturas através de uma lista.
 */
double desvioPadrao(double media, int x, int n) {
    return sqrt(pow((x-media), 2) / n-1);
}

double desvio(double media, int x) {
    return abs(x - media);
}

double media(const list<int>& lst) {
    int s = 0;
    for(int t : lst) {
        s+= t;
    }
    return (double) s/lst.size();
}

list<double> printDesvioPadrao(const list<int>& lst) {
    list<double> dp;
    list<int>::const_iterator it;
    
    int i = 0;
    double med = media(lst);
    cout << "Média: " << med << endl;
    
    
    for (it = lst.begin(); it != lst.end(); ++it) {
        double d = desvio(med, *it); 
        dp.push_back(d);
        cout << "Hora: " << i << "h - Temperatura: " << *it << "ºC - Desvio: " << d << endl;
        i++;
    }
    
    return dp;
}

int main(int argc, char** argv) {
    list<int> tmp;
    srand(time(NULL));
    int trand;
    
    for (int i = 0; i < 24; i++) {
        int trand = rand() % 50 -10; 
        tmp.push_back(trand);
    }
    
    printDesvioPadrao(tmp);

    return 0;
}

