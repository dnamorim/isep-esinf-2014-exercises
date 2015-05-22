/* 
 * File:   main_sc.cpp
 * Author: dnamorim
 * ESINF: Exercício 1a - PL2
 * 
 * Created on 30 de Setembro de 2014, 15:07
 */

#include <iostream>
#include <string>

#include <list>
#include <vector>

using namespace std;

#define MAX 5

void showList(list<string> lst, string s) {
    cout << s << endl;
    //VII. Mostre a list no ecrã usando iteradores.
    for (list<string>::iterator it=lst.begin(); it!=lst.end(); it++) {
        cout << *it << " " ;
    }
    cout << "\n" << endl;
    
}

void mainSC() {
    cout << "--- PL2 - Exercício 1a ---\n" << endl;
    //Vector fornecido
    string sve[MAX] = {	"Primeiro", "Segundo", "Terceiro", "Quarto", "Quinto" };
    
    //II. Definir Vector STL de string
    vector<string> vec;
    
    //III. Preencher o Vector STL com valores de sve
    for (int i = 0; i < MAX; i++) {
        vec.push_back(sve[i]);
    }
    
    cout << "-- Vector STL --\n" << endl;
    
    //IV. Mostre o vector no ecrã usando a iteração “for each”.
    cout << "Listagem com foreach:" << endl;
    for (string s : vec) {
        cout << s << " ";
    }
    cout << "\n" << endl;
    
    cout << "Pressione qualquer tecla...";
    cin.get();
    
    cout << "\n-- List STL --" << endl;
    
    //V. Defina uma list (STL) de “string”.
    list<string> lst;
    
    //VI. Preencha a list (STL) de “string” usando o vector sve.
    for (int i = 0; i < MAX; i++) {
        lst.push_back(sve[i]);
    }
    
    //VI. Apresentar list com iteradores no ecrã
    showList(lst, "\nLista apresentada com Iteradores:");
    cout << "Pressione qualquer tecla...";
    cin.get();
    
    //VIII. Inverta a list.
    lst.reverse();
    showList(lst, "\nLista Invertida:");
    cout << "Pressione qualquer tecla...";
    cin.get();
    
    //IX. Ordenar a list.
    lst.sort();
    showList(lst, "\nLista Ordenada:");
    cout << "Pressione qualquer tecla...";
    cin.get();
    
    //X. Crie uma segunda list (STL) de “string” só com o elemento “Sexto”.
    list<string> lst2;
    lst2.push_back("Sexto");
    
    //XI. Junte esta segunda list à primeira.
    lst.insert(lst.end(), lst2.begin(), lst2.end());
            
    //XII. Mostre a list no ecrã usando a iteração “for each”.
    showList(lst, "\nDuas Listas numa só");
    cout << "Pressione qualquer tecla...";
    cin.get();
}

