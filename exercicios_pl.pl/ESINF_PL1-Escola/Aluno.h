/* 
 * File:   Aluno.h
 * Author: dnamorim
 *
 * Created on 16 de Setembro de 2014, 15:10
 */

#ifndef Aluno_
#define	Aluno_

class Aluno : public Pessoa
{
    private :
        int nr;
        string curso;
        
        public :
            Aluno();
            Aluno(string nm, Data dt, float h, int n, string c);
            Aluno(const Aluno& a);
            ~Aluno();
            
            Aluno* clone() const; 
            
            void setNr(int n);
            void setCurso(string c);
            
            int getNr() const;
            string getCurso() const;
            
            bool operator == (const Aluno& a);
            Aluno& operator = (const Aluno& a);
            void escreve(ostream& out) const;
};

Aluno::Aluno() : Pessoa() 
{
    nr = 0;
    curso = "Not Defined";
}

Aluno::Aluno(string nm, Data dt, float h, int n, string c) : Pessoa(nm, dt, h) 
{
    nr = n;
    curso = c;
}

Aluno::Aluno(const Aluno& a) : Pessoa(a) {
    nr = a.nr;
    curso = a.curso;
}

Aluno::~Aluno() 
{
    
}

Aluno* Aluno::clone() const {
    return new Aluno(*this);
}

void Aluno::setNr(int n) 
{
    nr = n;
}

void Aluno::setCurso(string c) 
{
    curso = c;
}

int Aluno::getNr() const 
{
    return nr;
}

string Aluno::getCurso() const 
{
    return curso;
}

Aluno& Aluno::operator = (const Aluno& a) {
    if(this != &a) {
        Pessoa::operator =(a);
        setNr(a.nr);
        setCurso(a.curso);
    }
    
    return *this;
}

bool Aluno::operator == (const Aluno& a) {
    if(Pessoa::operator ==(a)) {
        if((nr == a.nr) && (curso == a.curso)) {
            return true;
        }
    }
    
    return false;
}

void Aluno::escreve(ostream& out) const 
{
    Pessoa::escreve(out);
    out << "Número: " << nr << "\nCurso: " << curso << "\n" << endl;
}

ostream& operator <<(ostream& out, const Aluno& a) {
    a.escreve(out);
    return out;
}

#endif	/* Aluno_ */

