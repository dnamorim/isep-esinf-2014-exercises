/* 
 * File:   Professor.h
 * Author: dnamorim
 *
 * Created on 16 de Setembro de 2014, 15:13
 */

#ifndef Professor_
#define	Professor_

#include "Pessoa.h"


class Professor : public Pessoa
{
    private :
        string departamento;
    
    public :
        Professor();
        Professor(string nm, Data dt, float h, string dep);
        Professor(const Professor& p);
        ~Professor();
        
        Pessoa* clone() const; 
        
        void setDepartamento(string d);
        string getDepartamento() const;
        
        bool operator ==(const Professor& p);
        Professor& operator = (const Professor& p);
        
        void escreve(ostream& out) const;
};

Professor::Professor() : Pessoa()
{
    setDepartamento("Not Defined");
}

Professor::Professor(string nm, Data dt, float h, string dep) : Pessoa(nm, dt, h)
{
    setDepartamento(dep);
}

Professor::Professor(const Professor& p) : Pessoa(p) {
    setDepartamento(p.departamento);
}

Professor::~Professor() {
    
}

Pessoa* Professor::clone() const {
    return new Professor(*this);
}


void Professor::setDepartamento(string d) {
    departamento = d;
}

string Professor::getDepartamento() const {
    return departamento;
}

Professor& Professor::operator = (const Professor& p) {
    if(this != &p) {
        Pessoa::operator =(p);
        setDepartamento(p.departamento);
    }
    
    return *this;
}

bool Professor::operator == (const Professor& p) {
    if(Pessoa::operator ==(p)) {
        if(departamento == p.departamento) {
            return true;
        }
    }
    
    return false;
}

void Professor::escreve(ostream& out) const {
    Pessoa::escreve(out);
    out << "Departamento: " << departamento << "\n" << endl;
}

ostream& operator <<(ostream& out, const Professor& p) {
    p.escreve(out);
    return out;
}

#endif	/* Professor_ */

