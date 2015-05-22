/* 
 * File:   main.cpp
 * Author: Nuno
 *
 * Created on 14 de Novembro de 2014, 16:16
 */

#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

#include "bst.h"
#include "bstIteratorPreOrder.h"
#include "tree.h"

/*
 * 
 */

void listarFila(queue <int> fila, const string &msg ) {
    cout << msg << endl; 
    while (!fila.empty())
    {
        cout << fila.front() << " ; ";
        fila.pop();    
    }
    cout << endl;
}


int main(int argc, char** argv) {
    
    tree <int> arvore;
    arvore.push(80);
    arvore.push(70);  arvore.push(90);
    arvore.push(60); arvore.push(75); arvore.push(85); arvore.push(95);
    arvore.push(65);
    
    // Exemplo de iteração fora da classe
    cout << "PRE ORDEM ITERADO FORA DA CLASSE" << endl;
    for (bstIteratorPreOrder<int> itpr= arvore.begin(); 
            itpr!=arvore.end(); itpr++)
        cout << *itpr << " ; ";
    cout << endl;
    
    queue <int> fila1, fila2;
    
    fila1 = arvore.preOrder();
    fila2 = arvore.preOrderItera();
    if (fila1!=fila2)  cout << "ERRO!!!" << endl; else listarFila(fila1,"PRE ORDEM");
    

    
    fila1 = arvore.inOrder();
    fila2 = arvore.inOrderItera();
    if (fila1!=fila2)  cout << "ERRO!!!" << endl; else listarFila(fila1,"EM ORDEM");    
    
    fila1 = arvore.posOrder();
    fila2 = arvore.posOrderItera();
    if (fila1!=fila2)  cout << "ERRO!!!" << endl; else listarFila(fila1,"POS ORDEM");    
    
    fila1 = arvore.ordemEsqDirItera();
    listarFila(fila1,"ESQUERDA E DIREITA");
    
    tree <int> arvore_sem_folhas(arvore.arvoreSemFolhas());
    
    cout << "ARVORE SEM FOLHAS EM PRE ORDEM" << endl;
    for (bstIteratorPreOrder<int> itpr= arvore_sem_folhas.begin(); itpr!=arvore_sem_folhas.end(); itpr++)
        cout << *itpr << " ; ";
    cout << endl;    
    
    return 0;
}

