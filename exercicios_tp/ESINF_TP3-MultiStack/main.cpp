/* 
 * File:   main.cpp
 * Author: dnamorim
 *
 * Created on 13 de Outubro de 2014, 15:19
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

#include "Peca.h"
#include "PecaIndividual.h"
#include "PecaMontagem.h"
#include "MultiStack.h"

/*
 * 
 */
int main(int argc, char** argv) {
    MultiStack ms;        
    
    ms.empilhar(new PecaIndividual("p1","1"));    
    ms.empilhar(new PecaIndividual("p2","2"));
    ms.empilhar(new PecaIndividual("p3","3"));
    
    ms.empilhar(new PecaMontagem("p2",2.5));
    ms.empilhar(new PecaMontagem("p3",3.5));    
    
    ms.empilhar(new PecaIndividual("p4","4"));    
    ms.empilhar(new PecaIndividual("p5","5"));
    ms.empilhar(new PecaIndividual("p1","6"));
    
    ms.empilhar(new PecaMontagem("p1",1.2));    
    ms.empilhar(new PecaMontagem("p4",4.4));
    
    ms.empilhar(new PecaMontagem("p5",5.5));    
    ms.empilhar(new PecaMontagem("p1",6.9));
    
    cout << ms;
    
    ms.desempilhar("p3");
    
    cout << ms;
    return 0;
}

