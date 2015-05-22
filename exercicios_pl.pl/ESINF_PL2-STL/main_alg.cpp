/* 
 * File:   main_alg.cpp
 * Author: dnamorim
 * ESINF: PL2 - Exercício 1d
 * 
 * Created on 7 de Outubro de 2014, 15:33
 */

#include <iostream>
#include <string>

// Sequence containers
#include <list>
#include <algorithm>

using namespace std;

#define MAX 5


void mainALG() {
    char sve[MAX] = { '1', '2', '3', '4', '5' };
    
    cout << "-- PL2 - Exercício 1d --" << endl;
    
    //II. Defina uma list (STL) de “char”.
    list<char> lst;
    
    //III. Preencha a list (STL) de “char” usando o vector sve.
    for (int i = 0; i < MAX; i++) {
        lst.push_back(sve[i]);
    }
    
    //IV. Verifique se a list tem o 3o elemento usando o algoritmo genérico find.
    list<char>::iterator it;
    it = find(lst.begin(), lst.end(), '3');
    
    if (lst.end() == it) {
        cout << "3º Elemento Não Encontrado." << endl;
    }
    else {
        cout << "3º Elemento Encontrado." << endl;
    }
    
    cout << "\nPressione qualquer tecla...";
    cin.get();
    
    //V. Verifique qual o máximo da list usando o algoritmo genérico max_element.
    it = max_element(lst.begin(), lst.end());
    cout << "\nElemento Máximo: " << *it << endl;
}