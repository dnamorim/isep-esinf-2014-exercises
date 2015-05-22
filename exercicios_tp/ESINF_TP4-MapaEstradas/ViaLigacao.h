//
//  ViaLigacao.h
//  ESINF_TP4-MapaEstradas
//
//  Created by Duarte Nuno Amorim on 10/11/14.
//  Copyright (c) 2014 Duarte Nuno Amorim. All rights reserved.
//

#ifndef ESINF_TP4_MapaEstradas_ViaLigacao_h
#define ESINF_TP4_MapaEstradas_ViaLigacao_h

#include <string.h>

class ViaLigacao {
private:
    float km;
    string designacao;
    
public:
    ViaLigacao(const string& designacao, float km);
    ViaLigacao(const ViaLigacao& v);
    ViaLigacao();
    virtual ~ViaLigacao();
    
    string getDesignacao();
    void setDesignacao(const string& designacao);
    
    float getKm() const;
    void setKm(float km);
    
    virtual bool operator==(const ViaLigacao& v);
    virtual ViaLigacao& operator=(const ViaLigacao& v);
    
    virtual ViaLigacao* clone() const = 0;
    virtual void write(ostream& out) const;
};

#endif
