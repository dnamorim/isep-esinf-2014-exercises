/* 
 * File:   main.cpp
 * Author: dnamorim
 *
 * Created on 16 de Setembro de 2014, 14:41
 */

#include <iostream>
#include <string>
using namespace std;

#include "Data.h"
#include "Pessoa.h"
#include "Aluno.h"
#include "Professor.h"
#include "Escola.h"

/*
 * 
 */


void pause() {
    cout << "Pressione qualquer tecla para continuar" << endl; 
    cin.get(); 
}

int main(int argc, char** argv) {

    //Cria o Objecto Escola - vai guardar as pessoas
    Escola e (8);
    Escola e2 (3);
    Escola e3 (3);
    
    Data dt1 (1995, 2, 8);
    Data dt2 (1974, 4, 25);
    
    //Criação dos Objectos Alunos
    Aluno a1 ("Duarte", dt1, 1.75, 1130674, "Informática");
    Aluno a2 ("Ricardo", dt1, 1.72, 1120703, "Informática");
    Aluno a3 ("Joana", dt1, 1.70, 1001, "Mecânica");
    Aluno a4 ("Pedro", dt1, 1.75, 1003, "Electrónica");
    
    //Criação de um objecto Professor
    Professor p("Fernando", dt2, 1.70, "Informática");
    Professor p2("António", dt2, 1.80, "Mecânica");
    
    //Insere as Pessoas no Array de Apontadores em Escola
    e.insElem(&a1);
    e.insElem(&a2);
    e.insElem(&a3);
    e.insElem(&a4);
    e.insElem(&p);
    
    e2.insElem(&p);
    
    e3.insElem(&p);
    e3.insElem(&p2);
    
    
    //Escrever listagem de todas as pessoas em Escola
    cout << e;
    
    pause();
    
    //Idade Média dos Alunos
    cout << "Idade Média dos Alunos: " << e.idadeMed() << "\n"<< endl;
    
    pause();
    
    //Listagem de alunos ordenados por cursos
    e.listarAlunos();
    
    pause();
    //Alterar Cursos
    //e.alterCurso(1000, 1004);
    
    //pause();
    //Listagem de alunos ordenados por cursos
    e.listarAlunos();
    
    //-- Teste Exercício Avaliação 1 ESINF --
    if(e != e2) {
        cout << "Os Departamentos das Escolas 1 e 2 são diferentes." << endl;
    } else {
        cout << "Os Departamentos das Escolas 1 e 2 são iguais." << endl;
    }
    
    if(e != e3) {
        cout << "Os Departamentos das Escolas 1 e 3 são diferentes." << endl;
    } else {
        cout << "Os Departamentos das Escolas 1 e 3 são iguais." << endl;
    }
    
    if(e2 != e3) {
        cout << "Os Departamentos das Escolas 2 e 3 são diferentes." << endl;
    } else {
        cout << "Os Departamentos das Escolas 2 e 3 são iguais." << endl;
    }
    
    return 0;
}


