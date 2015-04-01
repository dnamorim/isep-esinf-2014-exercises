/* 
 * File:   PecasIndividuais.h
 * Author: dnamorim
 *
 * Created on 13 de Outubro de 2014, 15:25
 */

#ifndef PECASINDIVIDUAIS_H
#define	PECASINDIVIDUAIS_H

class PecaIndividual : public Peca {
    private :
        string tipoEmbalagem;
        
    public :
        PecaIndividual();
        PecaIndividual(string c, string t);
        PecaIndividual(const PecaIndividual& p);
        virtual ~PecaIndividual();
        
        string getTipoEmbalagem() const;
        
        virtual Peca* clone() const;
        virtual void escreve(ostream& out) const;
};

PecaIndividual::PecaIndividual(string s, string t) : Peca(s), tipoEmbalagem(t) {
}

PecaIndividual::PecaIndividual(const PecaIndividual& orig) : Peca(orig), tipoEmbalagem(orig.tipoEmbalagem) {
}

PecaIndividual::~PecaIndividual() {
}

string PecaIndividual::getTipoEmbalagem() const {
    return tipoEmbalagem;
}

Peca* PecaIndividual::clone() const {
    return new PecaIndividual(*this);
}

void PecaIndividual::escreve(ostream &out) const {
    out << "Individual: Codigo: ";
    Peca::escreve(out);
    out << " Embalagem: " << tipoEmbalagem << endl;
}




#endif	/* PECASINDIVIDUAIS_H */

