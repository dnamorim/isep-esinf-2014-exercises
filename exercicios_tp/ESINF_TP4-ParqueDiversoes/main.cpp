//
//  main.cpp
//  ESINF_TP4-ParqueDiversoes
//
//  Created by Duarte Nuno Amorim on 03/11/14.
//  Copyright (c) 2014 Duarte Nuno Amorim. All rights reserved.
//

#include <iostream>
#include "ParqueDiversoes.h"

using namespace std;
#include <queue>

int main(int argc, const char * argv[]) {
    ParqueDiversoes p;

    //Adicionar os Vértices ao Graph
    p.addGraphEdge(1, "Montanha-Russa", "Carros de Choque");
    p.addGraphEdge(1, "Montanha-Russa", "Castelo Assombrado");
    p.addGraphEdge(1, "Castelo Assombrado", "Canoa Aquática");
    p.addGraphEdge(1, "Carros de Choque", "Castelo Assombrado");
    p.addGraphEdge(1, "Canoa Aquática", "Bailarina");
    p.addGraphEdge(1, "Castelo Assombrado", "Bailarina");
    p.addGraphEdge(1, "Carros de Choque", "Peso Mais Forte");
    p.addGraphEdge(1, "Bailarina", "Peso Mais Forte");
    
    //Imprimir Graph
    cout << p << endl;
    
    //Apresente o caminho mínimo entre uma actividde inicial e uma actividade final.
    p.menorCaminhoNaoPesado("Montanha-Russa", "Peso Mais Forte");
    cout << endl;
    
    return 0;
}
