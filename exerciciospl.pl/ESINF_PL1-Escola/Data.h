/* 
 * File:   Data.h
 * Author: dnamorim
 *
 * Created on 16 de Setembro de 2014, 14:43
 */

#ifndef Data_
#define Data_


class Data 
{ 	
   private:
	int ano;			// qualquer ano
	int mes;			// 1-12
	int dia;			// 1-31 dependente do mÍs
	
	static int diasPorMes[];  
	int validaDia (int d) const;      // Confirma o valor do dia baseado no mes e ano 
	int validaMes (int m) const; 
	int validaAno (int a) const; 
	bool anoBissexto (int a) const;   // Testa se ano È bissexto
	
  public:
	
	Data();
	Data(int a, int m, int d);
	Data(const Data &d);
	~Data() ;

	void setAno (int a);
	void setMes (int m);
	void setDia (int d);
	void setData (Data dt) ;

	int getAno() const ;
	int getMes() const;
	int getDia() const;
	int getAnos () const ;

        const Data& operator++();
        const Data& operator++(int);
        const Data& operator = (const Data& d); 
        bool operator > (const Data& d) const; 
        bool operator == (const Data& d) const;

        virtual void escreve(ostream& out) const;
	void listar() const ;
};

int Data::diasPorMes[]=	{0,31,28,31,30,31,30,31,31,30,31,30,31};

Data::Data() 
{
	setAno(1900);
	setMes(1);
	setDia(1);
}

// Confirma o valor do mes e chama o metodo validaDia
// para confirmar o valor do dia.
Data::Data (int a, int m, int d ) 
{
	setAno(a);
	setMes(m);
	setDia(d);
}

Data::Data (const Data &d)
{
	ano=d.ano;
	mes=d.mes;
	dia=d.dia;
}

Data::~Data()
{

}

// Confirma o valor do dia baseado no mes e ano.
int Data::validaDia (int d) const
{
	if ( d > 0 && d <= diasPorMes[ mes ] ) 
		return d;
	// se Fevereiro: Verifica se ano bissexto
	if ( mes == 2 && d == 29 &&	anoBissexto(ano) ) 
		return d;
	cout<<"Dia " << d << " invalido. Colocado o dia 1.";
	    return 1;  // Deixa o objecto num estado consistente
}

int Data::validaMes (int m) const
{
	if (m > 0 && m <= 12 )		// valida o mes
	   return m;	
	else 
	{
	   cout<<"\nMÍs inv·lido -> mes=1";
	   return  1;
	}
}

int Data::validaAno (int a) const
{
	if (a < 0)
	{
	   cout<<"\nAno negativo - inválido -> ano=0";
	   return 0;
	}
	else
	   return a;
}

bool Data::anoBissexto(int a) const
{	
	return  (( a % 400 == 0 || a % 4 == 0 )&& a % 100 != 0 ) ;
}

// Outros mÈtodos
void Data::setAno (int a)
{
	ano = validaAno (a) ;

}

void  Data::setMes (int m)
{
	mes = validaMes (m);  // valida o mes

}

void  Data::setDia (int d)
{
	dia = validaDia (d);	// valida o dia

}

void Data::setData (Data dt)
{
	setAno(dt.ano) ;  
	setMes(dt.mes);
	setDia(dt.dia);	 
}

int Data::getAno() const
{
	return ano;
}

int Data::getMes() const
{
	return mes;
}

int Data::getDia() const
{
	return dia;
}

int Data::getAnos() const
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime( &rawtime );
  
  if ((timeinfo->tm_mon+1) < mes) 
	  return ((timeinfo->tm_year+1900)-(ano+1)) ;
  else if ((timeinfo->tm_mon+1) == mes) 
	     if (timeinfo->tm_mday < dia)  
            return (timeinfo->tm_year+1900)-(ano+1) ; 
		 else
            return ((timeinfo->tm_year+1900)-ano) ;
  else
    return (timeinfo->tm_year+1900)-ano ;
}

bool Data::operator >(const Data& d) const {
    if(ano > d.ano) {
        if(mes > d.mes) {
            if(dia > d.dia) {
                return true;
            }
        }
    }
    return false;
}

bool Data::operator ==(const Data& d) const {
    if(ano == d.ano) {
        if(mes == d.mes) {
            if(dia == d.dia) {
                return true;
            }
        }
    }
    return false;
}

const Data& Data::operator =(const Data& d) {
    if(this != &d) {
        setData(d);
    }
    return *this;
}

const Data& Data::operator ++() {
    if(dia < diasPorMes[mes]) {
        dia++;
    } else if(mes == 2 && anoBissexto(ano) && dia==28) {
        dia=1;
        mes++;
    } else {
        dia = 1;
        ano = (mes == 12 ? (ano+1) : ano);
        mes = (mes == 12 ? 1 : mes+1);
    }
    return *this;
}

const Data& Data::operator ++(int) {
    Data aux(*this) ;
    operator++() ;
    return *this; 
}

void Data::escreve(ostream& out) const {
    out << ano << "/" << mes << "/" << dia << " ";
}

void Data::listar() const 
{
    cout << dia << " / " << mes << " / " << ano << endl ;			 
}

ostream& operator<<(ostream& out, const Data& d) {
    d.escreve(out);
    return out;
}

#endif

