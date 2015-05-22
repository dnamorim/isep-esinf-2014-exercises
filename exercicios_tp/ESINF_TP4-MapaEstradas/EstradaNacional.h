//
//  EstradaNacional.h
//  ESINF_TP4-MapaEstradas
//
//  Created by Duarte Nuno Amorim on 10/11/14.
//  Copyright (c) 2014 Duarte Nuno Amorim. All rights reserved.
//

#ifndef ESINF_TP4_MapaEstradas_EstradaNacional_h
#define ESINF_TP4_MapaEstradas_EstradaNacional_h

#import "ViaLigacao.h"

class EstradaNacional : public ViaLigacao {
public:
    EstradaNacional(const string& designacao, float km);
    EstradaNacional(const EstradaNacional& en);
    
    virtual EstradaNacional* clone() const;
    virtual void write(ostream& out) const;
};

EstradaNacional::EstradaNacional(const string& designacao, float km, float preco) : ViaLigacao(designacao, km) {

}

EstradaNacional::EstradaNacional(const EstradaNacional& en) : ViaLigacao(en) {
    
}

Estrada* EstradaNacional::clone() const {
    return new EstradaNacional(*this);
}

void EstradaNacional::write(ostream& out) const {
    out << "Estrada Nacional ";
    ViaLigacao.write(out);
}

#endif
