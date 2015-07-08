/* 
 * File:   Pessoa.h
 * Author: dnamorim
 *
 * Created on 16 de Setembro de 2014, 14:41
 */

#ifndef Pessoa_
#define	Pessoa_

#include "Data.h"


class Pessoa : public Data
{
    private:
        string nome;
        Data datanasc;
        float altura;
    
    public:
        Pessoa();
        Pessoa(string n, Data dt, float h);
        Pessoa(const Pessoa &p);
        virtual ~Pessoa();
        
        virtual Pessoa* clone() const=0;
        
        void setNome(string n);
        void setDataNasc(Data dt);
        void setAltura(float h);
        
        string getNome() const;
        Data getDataNac() const;
        float getAltura() const;
        
        bool operator > (const Pessoa& p);
        bool operator == (const Pessoa& p);
        bool operator != (const Pessoa& p);
        bool operator <= (const Pessoa& p);
        Pessoa& operator = (const Pessoa& p);
        
        
        virtual void escreve(ostream& out) const;
};

Pessoa::Pessoa() : datanasc()
{
    setNome("Not Defined");
    setAltura(0);
}

Pessoa::Pessoa(string n, Data dt, float h) : datanasc(dt)
{
    setNome(n);
    setAltura(h);
}

Pessoa::Pessoa(const Pessoa& p) : datanasc(p.datanasc)
{
    nome=p.nome;
    altura=p.altura;
}

Pessoa::~Pessoa() {
    
}

void Pessoa::setNome(string n) {
    nome = n;
}

void Pessoa::setDataNasc(Data dt) {
    datanasc.setData(dt);
}

void Pessoa::setAltura(float h)
{
    altura = h;
}

string Pessoa::getNome() const 
{
    return nome;
}

Data Pessoa::getDataNac() const 
{
    return datanasc;
}

float Pessoa::getAltura() const
{
    return altura;
}

Pessoa& Pessoa::operator =(const Pessoa& p) {
    if(this != &p) {
        setNome(p.nome);
        setDataNasc(p.datanasc);
        setAltura(p.altura);
    }
    
    return *this;
}

bool Pessoa::operator ==(const Pessoa& p) {
    if(nome == p.nome) {
        if(datanasc == p.datanasc) {
            if(altura == p.altura) {
                return true;
            }
        }
    }
    
    return false;
}

bool Pessoa::operator !=(const Pessoa& p) {
    if(nome == p.nome) {
        if(datanasc == p.datanasc) {
            if(altura == p.altura) {
                return false;
            }
        }
    }
    
    return true;
}

bool Pessoa::operator >(const Pessoa& p) {
    return (altura > p.altura ? true : false);
}

bool Pessoa::operator <=(const Pessoa& p) {
    return (altura <= p.altura ? true : false);
}

void Pessoa::escreve(ostream& out) const 
{
    out << "Nome: " << nome << "\nData Nascimento: " << datanasc << endl; 
    out << "Altura: " << altura << endl;
}

ostream& operator <<(ostream& out, const Pessoa& p) {
    p.escreve(out);
    return out;
}

#endif	/* Pessoa_ */

