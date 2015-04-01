//
//  ParqueDiversoes.h
//  ESINF_TP4-ParqueDiversoes
//
//  Created by Duarte Nuno Amorim on 03/11/14.
//  Copyright (c) 2014 Duarte Nuno Amorim. All rights reserved.
//

#ifndef ESINF_TP4_ParqueDiversoes_ParqueDiversoes_h
#define ESINF_TP4_ParqueDiversoes_ParqueDiversoes_h

#include <string>
#include "graphStlPath.h"

class ParqueDiversoes : public graphStlPath<string, int>
{
private:
    void mostraCaminho(int vi, const vector<int> &path);
    void menorCaminho(const string &ci, const string &cf);
    
public:
    ParqueDiversoes();
    ParqueDiversoes(const ParqueDiversoes &p);
    
    void menorCaminhoNaoPesado(const string &ci, const string &cf);
};

ParqueDiversoes::ParqueDiversoes() : graphStlPath<string, int>() {
    
}

ParqueDiversoes::ParqueDiversoes(const ParqueDiversoes &p) : graphStlPath<string, int>(p) {
    
}

void ParqueDiversoes::menorCaminhoNaoPesado(const string &ci, const string &cf) {
    cout << "Menor distância entre " << ci << " e " << cf << ": ";
    menorCaminho(ci, cf);
}

void ParqueDiversoes::menorCaminho(const string &ci, const string &cf) {
    vector <int> path;
    vector<int> dist;
    int key;
    
    this->getVertexKeyByContent(key, cf);
    this->dijkstrasAlgorithm(ci, path, dist);
    cout << dist[key] << " Ramos ; " << endl;
    cout << ci;
    mostraCaminho(key, path);
}

void ParqueDiversoes::mostraCaminho(int vi, const vector<int> &path) {
    if (path[vi] == -1) {
        return;
    }
    mostraCaminho(path[vi], path);
    int e;
    this->getEdgeByVertexKeys(e, path[vi], vi);
    
    string c;
    this->getVertexContentByKey(c, vi);
    cout << " -> " << e << " -> " << c;
}


#endif
