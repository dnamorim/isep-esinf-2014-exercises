//
//  pntEstrada.h
//  ESINF_TP4-MapaEstradas
//
//  Created by Duarte Nuno Amorim on 10/11/14.
//  Copyright (c) 2014 Duarte Nuno Amorim. All rights reserved.
//

#ifndef ESINF_TP4_MapaEstradas_pntEstrada_h
#define ESINF_TP4_MapaEstradas_pntEstrada_h

#include "ViaLigacao.h"
#include "EstradaNacional.h"
#include "AutoEstrada.h"

class pntEstrada {
private:
    ViaLigacao* vl;
    
    enum TipoComparacao(KMS, CUSTO);
    static TipoComparacao tipoComparacao;
    
public:
    static void setComparacaoKMS();
    static void setComparacaoCUSTO();
    
    float getKm();
    float getCusto();
    
    pntEstrada();
    pntEstrada(const ViaLigacao& vl);
    pntEstrada(const pntEstrada& pe);
    pntEstrada(float km, float custo);
    ~pntEstrada();
    
    bool operator > (const pntEstrada& pe) const;
    bool operator < (const pntEstrada& pe) const;
    bool operator == (const pntEstrada& pe) const;
    pntEstrada& operator= (const pntEstrada& pe);
    pntEstrada& operator+= (const pntEstrada& pe);
    pntEstrada operator+ (const pntEstrada& pe);

    void write(ostream& out) const;
};

pntEstrada::TipoComparacao pntEstrada::tipoComparacao==pntEstrada::TipoComparacao::KMS;
void pntEstrada::setComparacaoKMS() {
    tipoComparacao = TipoComparacao::KMS;
}

void pntEstrada::setComparacaoCUSTO() {
    tipoComparacao = TipoComparacao::CUSTO;
}

float pntEstrada::getKm() const {
    return vl->getKm();
}

float pntEstrada::getCusto() const {
    return vl->getCusto();
}

pntEstrada::pntEstrada() {
    this->vl = new AutoEstrada();
}

pntEstrada::pntEstrada(int km, int custo) {
    this->vl = new AutoEstrada("", km, custo);
}

pntEstrada::pntEstrada(const ViaLigacao& vl) {
    this->vl = vl.clone();
}

pntEstrada::pntEstrada(const pntEstrada& pe) {
    this->vl = pe.vl->clone();
}

pntEstrada::~pntEstrada() {
    delete vl;
}

bool pntEstrada::operator > (const pntEstrada& pe) const {
    if(tipoComparacao == TipoComparacao::KMS) {
        return (this->vl->getKm() > pe.vl->getKm());
    }
    return (this->vl->getCusto() > pe.vl->getCusto());
}

bool pntEstrada::operator < (const pntEstrada& pe) const {
    if(tipoComparacao == TipoComparacao::KMS) {
        return (this->vl->getKm() < pe.vl->getKm());
    }
    return (this->vl->getCusto() < pe.vl->getCusto());
}

bool pntEstrada::operator == (const pntEstrada& pe) const {
    if(tipoComparacao == TipoComparacao::KMS) {
        return (this->vl->getKm() == pe.vl->getKm());
    }
    return (this->vl->getCusto() == pe.vl->getCusto());
}

pntEstrada pntEstrada::operator + (const pntEstrada& pe) const {
    return pntEstrada(this->vl->getKm() + pe.vl->getKm(), this->vl->getCusto() + pe.vl->getCusto());
}

pntEstrada& pntEstrada::operator + (const pntEstrada& pe) const {
    this->vl->setKm(this->vl->getKm() + pe.vl->getKm());
    if(typeid(*vl) == typeid(AutoEstrada)) {
        AutoEstrada *ae = (AutoEstrada *) this->vl;
        ae->setCusto(ae->getCusto() + pe.vl->getCusto());
    }
    return *this;
}

pntEstrada& pntEstrada::operator = (const pntEstrada& pe) {
    this->vl = pe.vl->clone();
    return *this;
}

void pntEstrada::write(ostream& out) const {
    out << *vl;
}

ostream& operator << (ostream& out, const pntEstrada& pe) {
    pe.write(out);
    return out;
}

#endif
