/* 
 * File:   Mapa.h
 * Author: dnamorim
 *
 * Created on 27 de Outubro de 2014, 16:13
 */

#ifndef MAPA_H
#define	MAPA_H

#include <string>
#include "graphStlPath.h"

class Mapa : public graphStlPath<string, float>
{
private:
    void mostraCaminho(int vi, const vector<int> &path);
    void menorCaminho(const string &ci, const string &cf);
    
public:
    Mapa();
    Mapa(const Mapa &m);
    void maiorLigacao();
    void menorCaminhoDistancia(const string &ci, const string &cf);
};

Mapa::Mapa() : graphStlPath<string,float>() {
    
}

Mapa::Mapa(const Mapa &m) : graphStlPath<string, float>(m) {
    
}

//TO DO: indica a(s) cidade(s) cuja ligação direta apresenta maior distancia em kms.
void Mapa::maiorLigacao() {
    list< graphVertex<string, float> >::iterator itv;
    float max = 0;
    
    for (itv=vlist.begin(); itv != vlist.end(); itv++) {
        list< graphEdge<string, float> >::iterator ite;
        for (ite = itv->getAdjacenciesBegin(); ite != itv->getAdjacenciesEnd(); ite++) {
            if(ite->getEContent() > max) {
                max = ite->getEContent();
            }
        }
    }
    
    cout << "Maior distância de Ligação Directa: " << max << " km"<< endl;
    for (itv=vlist.begin(); itv != vlist.end(); itv++) {
        list< graphEdge<string, float> >::iterator ite;
        for (ite = itv->getAdjacenciesBegin(); ite != itv->getAdjacenciesEnd(); ite++) {
            if(ite->getEContent() == max) {
                cout << "Ligação com maior distâcia de " << itv->getVContent() << " a " << ite->getVDestination()->getVContent() << endl;
            }
        }
    }
    
}

void Mapa::menorCaminho(const string &ci, const string &cf) {
    vector<int> path;
    vector<float> dist;
    int key;
    
    this->getVertexKeyByContent(key, cf);
    this->dijkstrasAlgorithm(ci, path, dist);
    cout << dist[key] << " Km ; " << endl;
    cout << ci;
    mostraCaminho(key, path);

}

void Mapa::mostraCaminho(int vi, const vector<int> &path) {
    if (path[vi] == -1) {
        return;
    }
    mostraCaminho(path[vi], path);
    float e;
    this->getEdgeByVertexKeys(e, path[vi], vi);
    
    string c;
    this->getVertexContentByKey(c, vi);
    cout << " -> " << e << " -> " << c;
}

void Mapa::menorCaminhoDistancia(const string &ci, const string &cf) {
    cout << "Menor Distância entre " << ci << " e " << cf << ": ";
    menorCaminho(ci, cf);
}


#endif	/* MAPA_H */

