//
//  AutoEstrada.h
//  ESINF_TP4-MapaEstradas
//
//  Created by Duarte Nuno Amorim on 10/11/14.
//  Copyright (c) 2014 Duarte Nuno Amorim. All rights reserved.
//

#ifndef ESINF_TP4_MapaEstradas_AutoEstrada_h
#define ESINF_TP4_MapaEstradas_AutoEstrada_h

#import "ViaLigacao.h"

class AutoEstrada : public ViaLigacao {
private:
    float precoPortagem;
    
public:
    AutoEstrada(const string& designacao, float km, float preco);
    AutoEstrada(const AutoEstrada& ae);
    AutoEstrada();
    
    float getPrecoPortagem() const;
    void setPrecoPortagem(float preco);
    
    virtual AutoEstrada& operator=(const AutoEstrada& ae);
    virtual bool operator==(const AutoEstrada& ae);
    
    virtual AutoEstrada* clone() const;
    virtual void write(ostream& out) const;
};

AutoEstrada::AutoEstrada(const string& designacao, float km, float preco) : ViaLigacao(designacao, km, preco) {
    this.precoPortagem = preco;
}

AutoEstrada::AutoEstrada(const AutoEstrada& ae) : ViaLigacao(ae) {
    this.precoPortagem = ae.precoPortagem;
}

AutoEstrada::AutoEstrada() : ViaLigacao() {
    this.precoPortagem = 0;
}

float AutoEstrada::getPrecoPortagem() const {
    return this.precoPortagem;
}

void AutoEstrada::setPrecoPortagem(float preco) {
    this.precoPortagem = preco;
}

bool AutoEstrada::operator==(const AutoEstrada& ae) {
    if(ViaLigacao::operator==(ae)) {
        return ((this.precoPortagem == ae.precoPortagem) ? true : false);
    }
    return false;
}

AutoEstrada& AutoEstrada::operator=(const AutoEstrada& ae) {
    if(this != &ae) {
        ViaLigacao::operator=(ae);
        this.precoPortagem = ae.precoPortagem;
    }
    
    return *this;
}

AutoEstrada* AutoEstrada::clone() const {
    return new AutoEstrada(*this);
}

void AutoEstrada::write(ostream& out) const {
    cout << "Auto-Estrada: ";
    out.write(out);
    cout << "Preço Portagem: " << precoPortagem << " €" << endl;
}

#endif
