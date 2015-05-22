/* 
 * File:   main_ca.cpp
 * Author: dnamorim
 * ESINF: Exercício 1b - PL2
 *
 * Created on 7 de Outubro de 2014, 14:32
 */

#include <iostream>
#include <string>

// Container Adapters
#include <stack>
#include <queue>

using namespace std;

#define MAX 5

void mainCA() {
    string sve[MAX] = {	"Primeiro","Segundo", "Terceiro", "Quarto", "Quinto" }, str = "";
    
    cout << "\n--- PL2 - Exercício 1b ---" << endl;
    //II. Defina um vector (STL) de “string”.
    stack<string> stk;
    
    //III. Preencha o vector (STL) de “string” usando o vector sve.
    for (int i = 0; i < MAX; i++) {
        stk.push(sve[i]);
    }

    //IV. Defina uma queue (STL) de “string”.
    queue<string> que;
    
    //V. Preencha a queue (STL) de “string” usando o vector sve.
    for (int i = 0; i < MAX; i++) {
        que.push(sve[i]);
    }

    //VI. Remova todos os elementos da stack, mostrando-os no ecrã (FILO).
    cout << "\nElementos da Stack (Pilha) - FILO" << endl;
    while(!stk.empty()) {
        str = stk.top();
        stk.pop();
        cout << str << ", ";
    }
    cout << endl;
    cout << "\nPressione qualquer tecla...";
    cin.get();
    
    //VII. Remova todos os elementos da queue, mostrando-os no ecrã (FIFO).
    cout << "\nElementos da Queue - FIFO" << endl;
    while(!que.empty()) {
        str = que.front();
        que.pop();
        cout << str << ", ";
    }
    cout << endl;
}

