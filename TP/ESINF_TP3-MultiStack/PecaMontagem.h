/* 
 * File:   PecaMontagem.h
 * Author: dnamorim
 *
 * Created on 13 de Outubro de 2014, 15:26
 */

#ifndef PECAMONTAGEM_H
#define	PECAMONTAGEM_H

class PecaMontagem : public Peca {
    private :
        float peso;
        
    public :
        PecaMontagem();
        PecaMontagem(string c, float p);
        PecaMontagem(const PecaMontagem& p);
        virtual ~PecaMontagem();
        float getPeso() const;
        void setPeso(float p);
        virtual Peca * clone() const;
        
        virtual void escreve(ostream& out) const;
};

PecaMontagem::PecaMontagem(string c, float p) : Peca(c), peso(p) {
}

PecaMontagem::PecaMontagem(const PecaMontagem& orig) : Peca(orig), peso(orig.peso) {
}

PecaMontagem::~PecaMontagem() {
}

float PecaMontagem::getPeso() const {
    return peso;
}

Peca* PecaMontagem::clone() const {
    return new PecaMontagem(*this);
}

void PecaMontagem::escreve(ostream &out) const {
    out << "Montagem: Codigo: ";
    Peca::escreve(out);
    out << " Peso: " << peso << endl;
}

#endif	/* PECAMONTAGEM_H */

