/* 
 * File:   main_ac.cpp
 * Author: dnamorim
 * ESINF: PL2 - Exercício 1c
 * 
 * Created on 7 de Outubro de 2014, 15:03
 */

#include <iostream>
#include <string>

// Container Adapters
#include <set>
#include <map>

using namespace std;

#define MAX 5
/*
 * 
 */
void mainAC() {
    string sve[MAX] = {	"Primeiro", "Segundo", "Terceiro", "Quarto", "Quinto" };
    char key[MAX] = { '1', '2', '3', '4', '5' };
    
    cout << "--- PL2 - Exercício 1c ---\n" << endl;
    
    //II. Defina um set (STL) de “string”.
    set<string> myset;
    
    //III. Preencha o set(STL) de “string” usando o vector sve.
    for (int i = 0; i < MAX; i++) {
        myset.insert(sve[i]);
    }
    
    //IV. Mostre o set no ecrã usando a iteração “for each”.
    cout << "Listagem do Set armazenado" << endl;
    for(string s : myset) {
        cout << s << ", ";
    }
    cout << endl;
    
    cout << "\nPressione uma tecla...";
    cin.get();
    
    //V. Defina um map (STL) com chave “char” e informação “string”.
    map<char, string> mymap;
    for (int i = 0; i < MAX; i++) {
        mymap[key[i]] = sve[i];
    }
    
    //VI. Mostre no ecrã a informação do map respeitante à 3a chave
    cout << "\nInformação Respeitante à 3ª Chave do Map" << endl;
    cout << mymap['3'] << endl;
    
    cout << "\nPressione uma tecla...";
    cin.get();
    
    //VII. Mostre o map no ecrã usando iteradores de ordem inversa.
    map<char,string>::reverse_iterator it;
    
    cout << "\nMap Apresentado por ordem Inversa" << endl;
    for(it = mymap.rbegin(); it != mymap.rend(); it++) {
        cout << "(" << it->first << ", " << it->second << "), " ;
    }
    cout << endl;
    
    
}

