/* 
 * File:   Peca.h
 * Author: dnamorim
 *
 * Created on 13 de Outubro de 2014, 15:25
 */

#ifndef PECA_H
#define	PECA_H

class Peca {
    private :
        string codigo;
        
    public :
        Peca();
        Peca(string codigo);
        Peca(const Peca& p);
        virtual ~Peca();
        string getCodigo() const;
        void setCodigo(string codigo);
        virtual Peca * clone() const=0;
        
        virtual void escreve(ostream& out) const;
};

Peca::Peca(string s) : codigo(s) {
}

Peca::Peca(const Peca& p) : codigo(p.codigo) {
}

Peca::~Peca() {
}

string Peca::getCodigo() const {
    return codigo;
}

void Peca::escreve(ostream &out) const {
    out << codigo;
}

ostream & operator << (ostream &out, const Peca &p) {
    p.escreve(out);
    return out;
}

#endif	/* PECA_H */

