/***************************************
 * graphVertex.h
 *
 * Created on 18 de Julho de 2013, 15:39
 * 
 * @author Nuno Malheiro
 * rev1: g++ compatibility 23/10/2013
 * rev2: mac compatibility 28/10/2013
 ***************************************/


#ifndef _graphVertex_
#define _graphVertex_

#include <list>
#include <algorithm>

using namespace std;

template<class TV,class TE>
class graphEdge;

template<class TV, class TE>
class graphVertex
{
	private:
		int vKey;  // Vertex unique key in the graph
		TV vContent;  // Vertex content
		list < graphEdge <TV,TE> > eList; // Vertex list of edges (each edge contains its adjacent vertices)

	public:
		graphVertex();
		graphVertex(const TV& vContent, int vKey=-1);
		graphVertex(const graphVertex<TV,TE>& v);
		~graphVertex();

		TV getVContent() const ;
		void setVContent(const TV& vContent);

		int getVKey() const ;
		void setVKey(int vKey) ;

		bool getEdgeContentByVDestination(TE& eContent, typename list < graphVertex <TV,TE> >::iterator vDestination);

		typename list < graphEdge <TV,TE> >::iterator getAdjacenciesBegin() ;
		typename list < graphEdge <TV,TE> >::iterator getAdjacenciesEnd()  ;
		int getAdjacenciesSize() const ;
		void addAdjacency( const TE& econtent, typename list < graphVertex <TV,TE> >::iterator vDestination );		

		bool operator ==(const graphVertex <TV,TE> &v) const;
		void write(ostream &o) const;
};

/*************************************
	graphVertex Implementation
*************************************/

template<class TV,class TE>
graphVertex<TV,TE>::graphVertex() : vKey(-1), vContent(), eList()
{
}
template<class TV,class TE>
graphVertex<TV,TE>::graphVertex(const TV& vContent, int vKey) : vKey(vKey), vContent(vContent), eList()
{
}
template<class TV,class TE>
graphVertex<TV,TE>::graphVertex(const graphVertex<TV,TE>& v) : vKey(v.vKey), vContent(v.vContent), eList(v.eList)
{
}
template<class TV,class TE>
graphVertex<TV,TE>::~graphVertex()
{
}
template<class TV,class TE>
TV graphVertex<TV,TE>::getVContent() const 
{
	return vContent;
}
template<class TV,class TE>
void graphVertex<TV,TE>::setVContent(const TV& vContent)
{
	this->vContent=vContent;
}
template<class TV,class TE>
int graphVertex<TV,TE>::getVKey() const 
{
	return vKey;
}
template<class TV,class TE>
void graphVertex<TV,TE>::setVKey(int vKey)
{
	this->vKey=vKey;
}

template<class TV,class TE>
bool graphVertex<TV,TE>::getEdgeContentByVDestination(TE &eContent, typename list < graphVertex <TV,TE> >::iterator vDestination)
{
	for (typename list < graphEdge <TV,TE> >::iterator ite=eList.begin() ; ite!=eList.end() ; ite++)
		if (ite->getVDestination()==vDestination) {
			eContent=ite->getEContent();
			return true;
		}
	return false;
}

template<class TV,class TE>
typename list < graphEdge <TV,TE> >::iterator graphVertex<TV,TE>::getAdjacenciesBegin()  
{
	return eList.begin();
}
template<class TV,class TE>
typename list < graphEdge <TV,TE> >::iterator graphVertex<TV,TE>::getAdjacenciesEnd() 
{
	return eList.end();
}
template<class TV,class TE>
int graphVertex<TV,TE>::getAdjacenciesSize() const 
{
	return eList.size();
}
template<class TV,class TE>
void graphVertex<TV,TE>::addAdjacency( const TE& econtent, typename list < graphVertex <TV,TE> >::iterator vDestination )
{
	eList.push_back(graphEdge<TV,TE>(econtent,vDestination));
}
template<class TV,class TE>
bool graphVertex<TV,TE>::operator ==(const graphVertex <TV,TE> &v) const
{
	return (v.getVContent() == getVContent());
}

template<class TV,class TE>
void graphVertex<TV,TE>::write(ostream &out) const
{
	out << "Vertex: " << vContent << " Key: " << vKey << endl;
	out << "Connects to: " << endl;
	for (typename list < graphEdge <TV,TE> >::const_iterator ite = eList.begin() ; ite != eList.end() ; ite++ )
		out << *ite;

}

template<class TV,class TE>
ostream & operator <<( ostream &out, const graphVertex <TV,TE> &v)
{
	v.write(out);
	return out;
}

#endif