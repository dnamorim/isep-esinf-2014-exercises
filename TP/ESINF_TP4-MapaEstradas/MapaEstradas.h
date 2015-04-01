//
//  MapaEstradas.h
//  ESINF_TP4-MapaEstradas
//
//  Created by Duarte Nuno Amorim on 10/11/14.
//  Copyright (c) 2014 Duarte Nuno Amorim. All rights reserved.
//

#ifndef ESINF_TP4_MapaEstradas_MapaEstradas_h
#define ESINF_TP4_MapaEstradas_MapaEstradas_h

#import "ViaLigacao.h"

class MapaEstradas : public graphStlPath<string, pntEstrada> {
public:
    MapaEstradas();
    MapaEstradas(const MapaEstradas& me);
    void maiorLigacao();
    void menorCaminhoDistancia(const string& ci, const string& cf);
    void menorCaminhoCusto(const string& ci, const string& cf);
    
private:
    void mostraCaminho(int vi, const vector<int> &path);
    void menorCaminho(const string &ci, const string &cf);
    
}

#endif
