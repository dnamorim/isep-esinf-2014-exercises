/* 
 * File:   main.cpp
 * Author: dnamorim
 *
 * Created on 6 de Outubro de 2014, 15:20
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

#include "Document.h"
#include "BufferPrinter.h"

/*
 * 
 */

void pause() {
    cout << "\nPressionar qualuqer tecla para Continuar";
    cin.get();
    cout << endl;
}

int main(int argc, char** argv) {
    Document d1("ESINF", "Fátima Rodrigues", 80);
    Document d2("ARQCP", "Alexandre Bragança", 80);
    Document d3("BDDAD", "Rosa Reis", 80);
    Document d4("FSIAP", "Carlos Ramos", 160);
    Document d5("LAPR3", "Ângelo Martins", 480);
    Document d6("PPROG", "Luiz Faria", 500);
    
    BufferPrinter buf;
    
    cout << "Adicionar 6 Documentos ao Buffer\n" << endl;
    buf.AddsDoc(d1);
    buf.AddsDoc(d2);
    buf.AddsDoc(d3);
    buf.AddsDoc(d4);
    buf.AddsDoc(d5);
    buf.AddsDoc(d6);
    cout << endl;
    
    cout << buf;
    pause();
    
    
    cout << "Eliminar Documento LAPR3\n" << endl;
    buf.ElimDoc(d5.getNome(), d5.getAutor());
    
    cout << buf;
    pause();
    
    cout << "Adicionar Elemento e Apagar todos os que possuem tamanho 80\n" << endl;
    
    buf.AddsDoc(d5);
    cout << endl;
    
    buf.ElimDocsT(80);
    cout << buf;
    
    return 0;
}

