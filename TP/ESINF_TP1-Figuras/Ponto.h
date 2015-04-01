/* 
 * File:   Ponto.h
 * Author: dnamorim
 *
 * Created on 15 de Setembro de 2014, 22:08
 */

#ifndef Ponto_
#define	Ponto_

#include <iostream>
using namespace std;

class Ponto 
{
  private:
	  double x;
	  double y;

  public:
    	Ponto();
    	Ponto(double x, double y);
    	Ponto(const Ponto& other);
    	~Ponto();

	double X() const ;
	double Y() const ;
	void SetX(double x) ;
	void SetY(double y) ;
	void Set(double x, double y) ;

	void leitura() ;
	void escreve(ostream& out) const ;
        void escreve() const;
} ;

Ponto::Ponto()	// Construtor por defeito
{
  x = 0 ;
  y = 0 ;
}


Ponto::Ponto(double z, double k)	//Construtor com parâmetros
{
  x = z ;
  y = k ;
}

Ponto::Ponto(const Ponto& p)	//Construtor Cópia
{
  x = p.X() ;
  y = p.Y() ;
}

Ponto::~Ponto()	//Destrutor
{
}

double Ponto::X() const {
  return x; }

double Ponto::Y() const {
  return y;   }

void Ponto::SetX(double x) {
  this->x = x; }

void Ponto::SetY(double y) {
  this->y = y; }

void Ponto::Set(double x, double y) {
  this->x = x;
  this->y = y; }


void Ponto::leitura()   {
  cout << "\nAbcissa " ; cin >> x  ; 
  cout << "\nOrdenada " ; cin >> y ; }

void Ponto::escreve(ostream& out) const
{
  out << "(" << x << "," << y << ")"  ; 
}

void Ponto::escreve() const {
    Ponto::escreve(cout);
}

ostream& operator << (ostream& out, const Ponto& p) {
    p.escreve(out);
    return out;
}

#endif	/* Ponto_ */

