/* 
 * File:   main.cpp
 * Author: dnamorim
 *
 * Created on 14 de Outubro de 2014, 15:11
 */

#include <iostream>
#include <cstdlib>
#include <deque>
#include <string>

using namespace std;

#include "RingBuffer.h"

/*
 * 
 */

void pause() {
    cout << "Pressionar qualquer tecla para continuar...";
    cin.get();
}
int main(int argc, char** argv) {
    RingBuffer<string> rb(4);

    string obj[6] = {"1", "2", "3", "4", "5", "6"};
    for (int i = 0; i < 6; i++) {
        cout << "\nInserir Elemento " << obj[i] << ":" << endl;
        rb.insert(obj[i]);
        cout << rb;
        pause();
    }
    cout << endl;
    cout << "Objecto removido do Ringbuffer: " << rb.remove() << endl;
    return 0;
}

