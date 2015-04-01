/* 
 * File:   main.cpp
 * Author: dnamorim
 *
 * Created on 27 de Outubro de 2014, 16:12
 */

#include <iostream>

using namespace std;

#include "Mapa.h"


int main(int argc, char** argv) {
    Mapa m;
    
    //Adicionar Vértices ao grafo (Não-Dirigido, por isso duplica-se ligações)
    m.addGraphEdge(500, "Faro", "Aveiro"); m.addGraphEdge(500, "Aveiro", "Faro");
    m.addGraphEdge(300, "Faro", "Lisboa"); m.addGraphEdge(300, "Lisboa", "Faro");
    m.addGraphEdge(300, "Lisboa", "Porto"); m.addGraphEdge(300, "Porto", "Lisboa");
    m.addGraphEdge(100, "Aveiro", "Braga"); m.addGraphEdge(100, "Braga", "Aveiro");
    m.addGraphEdge(220, "Aveiro", "Estoril"); m.addGraphEdge(220, "Estoril", "Aveiro");
    m.addGraphEdge(380, "Estoril", "Porto"); m.addGraphEdge(220, "Porto", "Estoril");
    m.addGraphEdge(350, "Braga", "Estoril"); m.addGraphEdge(350, "Estoril", "Braga");
    m.addGraphEdge(200, "Aveiro", "Lisboa"); m.addGraphEdge(200, "Lisboa", "Aveiro");

    //Imprimir Graph
    cout << m << endl;
    
    //Apresente o caminho mínimo entre duas cidades
    m.menorCaminhoDistancia("Faro", "Porto");
    cout << endl;
    
    //Apresenta o(s) caminho(s) com mais km entre eles
    m.maiorLigacao();
    cout << endl;
    
    return 0;
}

