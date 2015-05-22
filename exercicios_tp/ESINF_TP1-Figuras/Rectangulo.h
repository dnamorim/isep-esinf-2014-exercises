/* 
 * File:   Rectangulo.h
 * Author: dnamorim
 *
 * Created on 16 de Setembro de 2014, 21:50
 */

#ifndef Rectangulo_
#define	Rectangulo_

class Rectangulo : public Figura {
    private :
        double comprimento, largura;
    
    public :
        Rectangulo(const Ponto& p, double cmp, double l, const string& c);
        Rectangulo(const Ponto& p, double cmp, double l);
        Rectangulo(const Rectangulo &r);
        virtual ~Rectangulo();
        virtual Figura* clone() const;
        
        void setComprimento(double c);
        double getComprimento() const;
        
        void setLargura(double l);
        double getLargura() const ;
        
        virtual double area() const;
        virtual double perimetro() const;
        virtual void desenhar() const;
        virtual Rectangulo& operator = (const Rectangulo& r);
        
        virtual void escreve(ostream& out) const;
};

Rectangulo::Rectangulo(const Ponto& p, double cmp, double l, const string& c) : Figura(p, c) {
    comprimento = cmp;
    largura = l;
}

Rectangulo::Rectangulo(const Ponto& p, double cmp, double l) : Figura(p) {
    comprimento = cmp;
    largura = l;
}

Rectangulo::Rectangulo(const Rectangulo  &r) : Figura(r) {
    comprimento = r.comprimento;
    largura = r.largura;
    
}

Rectangulo::~Rectangulo() {
    
}

Figura* Rectangulo::clone() const {
    return new Rectangulo(*this);
}

void Rectangulo::setComprimento(double c) {
    comprimento = c;
}

double Rectangulo::getComprimento() const {
    return comprimento;
}

void Rectangulo::setLargura(double l) {
    largura = l;
}

double Rectangulo::getLargura() const {
    return largura;
}

double Rectangulo::area() const {
    return (comprimento*largura);
}

double Rectangulo::perimetro() const {
    return 2*(comprimento + largura);
}

void Rectangulo::desenhar() const 
{
    cout << "Retangulo - Comprimento: " << comprimento << " Largura: " << largura << endl
             << " Super Classe: ";
    Figura::desenhar();
}

Rectangulo& Rectangulo::operator =(const Rectangulo& r) {
    if(this != &r) {
        Figura::operator =(r);
        comprimento = r.comprimento;
        largura = r.largura;
    }
    
    return *this;
}

void Rectangulo::escreve(ostream& out) const {
    out << "Rectângulo: <- Comprimento: " << comprimento << " ; Largura: " << largura << endl;
    Figura::escreve(out);
}

ostream& operator <<(ostream& out, const Rectangulo& r) {
    r.escreve(out);
    return out;
}

#endif	/* Rectangulo_ */

