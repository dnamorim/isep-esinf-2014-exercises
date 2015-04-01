 /* 
 * File:   Quadrado.h
 * Author: dnamorim
 *
 * Created on 16 de Setembro de 2014, 21:50
 */

#ifndef Quadrado_
#define	Quadrado_

#include "Rectangulo.h"


class Quadrado : public Rectangulo {
    public :
        Quadrado(const Ponto& p, double l, const string& c);
        Quadrado(const Ponto& p, double l);
        Quadrado(const Quadrado &q);
        virtual ~Quadrado();
        virtual Figura* clone() const;
        
        void setLado(double l);
        double getLado() const;
        
        virtual Quadrado& operator = (const Quadrado& q);
        
        virtual void desenhar() const;
        virtual void escreve(ostream& out) const;
};

Quadrado::Quadrado(const Ponto& p, double l, const string& c) : Rectangulo(p, l, l, c){
    
}

Quadrado::Quadrado(const Ponto& p, double l) : Rectangulo(p, l, l){
    
}

Quadrado::Quadrado(const Quadrado& q) : Rectangulo(q) {
    
}

Quadrado::~Quadrado() {
    
}

Figura* Quadrado::clone() const {
    return new Quadrado(*this);
}

void Quadrado::setLado(double l) {
    setComprimento(l);
    setLargura(l);
}

double Quadrado::getLado() const {
    return Rectangulo::getComprimento();
}

Quadrado& Quadrado::operator =(const Quadrado& q) {
    if(this != &q) {
        Rectangulo::operator =(q);
    }
    
    return *this;
}

void Quadrado::desenhar() const {
    cout << "Quadrado - Lado: " << getLado() << endl
             << " Super Classe: ";
    Rectangulo::desenhar();
}

void Quadrado::escreve(ostream& out) const {
    out << "Quadrado -> Lado: " << getLado() << endl; 
    Figura::escreve(out);
}

ostream& operator <<(ostream& out, const Quadrado& q) {
    q.escreve(out);
    return out;
}

#endif	/* Quadrado_ */

