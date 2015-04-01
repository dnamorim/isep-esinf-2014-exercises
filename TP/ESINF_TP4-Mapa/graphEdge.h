/***************************************
 * graphEdge.h
 *
 * Created on 18 de Julho de 2013, 15:48
 * 
 * @author Nuno Malheiro
 * rev1: g++ compatibility 23/10/2013
 * rev2: mac compatibility 28/10/2013
 ***************************************/

#ifndef _graphEdge_
#define _graphEdge_

#include <list>

using namespace std;


template<class TV,class TE>
class graphVertex;

template<class TV,class TE>
class graphEdge
{
	private:
		TE eContent;  // Edge content
		typename list < graphVertex <TV,TE> >::iterator vDestination; // Edge destination (vertex)

	public:
		graphEdge();
		graphEdge(const TE& eContent, typename list < graphVertex <TV,TE> >::iterator vDestination);
		graphEdge(const graphEdge<TV,TE>& e);
		~graphEdge();

		TE getEContent() const ;
		void setEContent(const TE& eContent);		

		typename list < graphVertex <TV,TE> >::iterator getVDestination();
		void setVDestination(typename list < graphVertex <TV,TE> >::iterator vDestination) ;
		void write(ostream &o) const;
};


/*************************************
	graphEdge Implementation
*************************************/

template<class TV,class TE>
graphEdge<TV,TE>::graphEdge() : eContent(), vDestination()
{
}
template<class TV,class TE>
graphEdge<TV,TE>::graphEdge(const TE& eContent, typename list < graphVertex <TV,TE> >::iterator vDestination) : eContent(eContent), vDestination(vDestination)
{
}
template<class TV,class TE>
graphEdge<TV,TE>::graphEdge(const graphEdge<TV,TE>& e)  : eContent(e.eContent), vDestination(e.vDestination)
{
}
template<class TV,class TE>
graphEdge<TV,TE>::~graphEdge()
{
}

template<class TV,class TE>
TE graphEdge<TV,TE>::getEContent() const 
{
	return eContent;
}
template<class TV,class TE>
void graphEdge<TV,TE>::setEContent(const TE& eContent)
{
	this->eContent = eContent;
}

template<class TV,class TE>
typename list < graphVertex <TV,TE> >::iterator graphEdge<TV,TE>::getVDestination() 
{
	return vDestination;
}
template<class TV,class TE>
void graphEdge<TV,TE>::setVDestination(typename list < graphVertex <TV,TE> >::iterator vDestination) 
{
	this->vDestination = vDestination;
}

template<class TV,class TE>
void graphEdge<TV,TE>::write(ostream &out) const
{
	out << "Edge: " << eContent << " connects to " << vDestination->getVContent() << endl;
}

template<class TV,class TE>
ostream & operator <<( ostream &out, const graphEdge <TV,TE> &e)
{
	e.write(out);
	return out;
}

#endif