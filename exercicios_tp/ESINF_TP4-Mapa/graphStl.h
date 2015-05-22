/***************************************
 * graphStl.h
 *
 * Created on 18 de Julho de 2013, 15:35
 * 
 * @author Nuno Malheiro
 * rev1: g++ compatibility 23/10/2013
 * rev2: mac compatibility 28/10/2013
 ***************************************/

#ifndef _graphStl_
#define _graphStl_

#define MAX_VERTICES 256	// maximum vertices allowed

#include <list>
#include <algorithm>

using namespace std;

#include "graphVertex.h"
#include "graphEdge.h"



template<class TV,class TE>
class graphStl
{
private:
	TE infinite; // Dijkstra's Infinite 
	int keys;

protected:
	list < graphVertex <TV,TE> > vlist;  // Vertice list

	TE getInfinite() const;
		// TO DO: if TV is a pointer compareVertices will have to be re-written
	virtual bool compareVertices(TV const &vContent1, TV const &vContent2);

	bool getVertexIteratorByContent(typename list < graphVertex <TV,TE> >::iterator &vIterator, const TV &vContent ); // Get the iterator to the vertex  given TV
	bool getVertexIteratorByKey(typename list < graphVertex <TV,TE> >::iterator &itv, int vKey ); // get the content of the vertex by key (needed for Dijkdtra's vector)	
public:
	graphStl();

	// To find a vextex and fill data above the compared with operator==. Useful for when objects have comparing keys plus other information
	bool getVertexContentBySubContent(TV &vContent, const TV &vSubContent );

	// get the content of the vertex given its internal numeric key (e.g. useful to use Dijkdtra's vector and rebuild its paths)
	bool getVertexContentByKey(TV &vContent, int vKey ); 
	
	// get the key of the vertex by content (useful to use Dijkdtra's vector and rebuild its paths)
	bool getVertexKeyByContent(int &vKey, const TV &vContent);

	// get the content of the edge by supplying the vertexes (useful to use Dijkdtra's vector and rebuild its paths)
	bool getEdgeByVertexContents(TE &eContent, const TV &vOrigin, const TV &vDestination);
	
	// get the content of the edge by supplying the vertexes' keys (useful to use Dijkdtra's vector and rebuild its paths)
	bool getEdgeByVertexKeys(TE &eContent, int vKeyOrigin, int vKeyDestination);

	int getEntranceDegree(const TV& vContent);
	int getExitDegree(const TV& vContent);	

	bool addGraphVertex(const TV& vContent);
	bool addGraphEdge(const TE& eContent, const TV& vOrigin, const TV& vDestination);
	
	virtual void write(ostream &o);
};

/*************************************
	graph_stl Implementation
*************************************/

template<class TV,class TE>
TE graphStl<TV,TE>::getInfinite() const
{
	return infinite;
}

template<class TV,class TE>
bool graphStl<TV,TE>::compareVertices(TV const &vContent1, TV const &vContent2)
{
	return (vContent1==vContent2);
}

template<class TV,class TE>
bool graphStl<TV,TE>::getVertexIteratorByContent(typename list < graphVertex <TV,TE> >::iterator &vIterator, const TV &vContent)
{
	for (typename list < graphVertex <TV,TE> >::iterator itv=vlist.begin(); itv!=vlist.end() ; itv++ )
		if (compareVertices(itv->getVContent(), vContent)) {
			vIterator = itv;
			return true;
		}
	return false;
}



template<class TV,class TE>
bool graphStl<TV,TE>::getVertexIteratorByKey(typename list < graphVertex <TV,TE> >::iterator &vIterator, int vKey)
{
	for (typename list < graphVertex <TV,TE> >::iterator itv=vlist.begin(); itv!=vlist.end() ; itv++ )
		if (itv->getVKey() == vKey) {
			vIterator = itv;
			return true;
		}
	return false;
}

template<class TV,class TE>
graphStl<TV,TE>::graphStl() : infinite(), keys(0), vlist()
{
}

template<class TV,class TE>
bool graphStl<TV,TE>::getVertexContentBySubContent(TV &vContent, const TV &vSubContent )
{
	typename list < graphVertex <TV,TE> >::iterator itv;
	bool r=getVertexIteratorByContent(itv, vSubContent);

	if (r) vContent=itv->getVContent();
	return r;
}

template<class TV,class TE>
bool graphStl<TV,TE>::getVertexKeyByContent(int &vKey, const TV &vContent)
{
	typename list < graphVertex <TV,TE> >::iterator itv;
	bool r=getVertexIteratorByContent(itv, vContent);

	if (r) vKey=itv->getVKey();
	return r;
}

template<class TV,class TE>
bool graphStl<TV,TE>::getVertexContentByKey(TV &vContent, int vKey)
{
	typename list < graphVertex <TV,TE> >::iterator itv;
	bool r=getVertexIteratorByKey( itv, vKey );

	if (r) vContent = itv->getVContent();
	return r;
}

template<class TV,class TE>
bool graphStl<TV,TE>::getEdgeByVertexContents(TE &eContent, const TV &vOrigin, const TV &vDestination)
{
	typename list < graphVertex <TV,TE> >::iterator itvo, itvd;

	if (!(getVertexIteratorByContent(itvo, vOrigin) && getVertexIteratorByContent(itvd, vDestination))) return false;

	return itvo->getEdgeContentByVDestination(eContent,itvd);
}

template<class TV,class TE>
bool graphStl<TV,TE>::getEdgeByVertexKeys(TE &eContent, int vKeyOrigin, int vKeyDestination)
{
	typename list < graphVertex <TV,TE> >::iterator itvo, itvd;

	if (!(getVertexIteratorByKey(itvo, vKeyOrigin) && getVertexIteratorByKey(itvd, vKeyDestination))) return false;

	return itvo->getEdgeContentByVDestination(eContent,itvd);
}

template<class TV,class TE>
int graphStl<TV,TE>::getEntranceDegree(const TV& vContent)
{
	int c = 0;
	typename list < graphVertex <TV,TE> >::iterator ited;
	
	if (!getVertexIteratorByContent(ited, vContent)) return -1;

	for (typename list < graphVertex <TV,TE> >::iterator itv=vlist.begin(); itv!=vlist.end() ; itv++ )
		for (typename list < graphEdge <TV,TE> >::iterator ite=itv->getAdjacenciesBegin() ; ite!=itv->getAdjacenciesEnd() ; ite++)
			if (ite->getVDestination()==ited) c++;

	return c;
}
	
template<class TV,class TE>
int graphStl<TV,TE>::getExitDegree(const TV& vContent)
{
	typename list < graphVertex <TV,TE> >::iterator ited;

	if (!getVertexIteratorByContent(ited, vContent)) return -1;

	return ited->getAdjacenciesSize();
}

template<class TV,class TE>
bool graphStl<TV,TE>::addGraphVertex(const TV& vContent)
{
	typename list < graphVertex <TV,TE> >::iterator itv;

	if ((keys>MAX_VERTICES) || getVertexIteratorByContent(itv,vContent)) return false;

	vlist.push_back(graphVertex<TV,TE>(vContent, keys));
	keys++;
	return true;
}

template<class TV,class TE>
bool graphStl<TV,TE>::addGraphEdge(const TE& eContent, const TV& vOrigin, const TV& vDestination)
{
	if (vOrigin==vDestination) return false;
	
	addGraphVertex(vOrigin); addGraphVertex(vDestination);

	typename list < graphVertex <TV,TE> >::iterator itvOrigin, itvDestination;	
	if (!(getVertexIteratorByContent(itvOrigin, vOrigin) && getVertexIteratorByContent(itvDestination, vDestination))) return false;	

	itvOrigin->addAdjacency(eContent, itvDestination);

	if (infinite+eContent>infinite) infinite += eContent;
	return true;
}

template<class TV,class TE>
void graphStl<TV,TE>::write(ostream &out)
{
	out << "Infinite: " << infinite << endl;
	for (typename list < graphVertex <TV,TE> >::const_iterator itv = vlist.begin() ; itv != vlist.end() ; itv++ )
		out << *itv;
}

template<class TV,class TE>
ostream & operator <<( ostream &out, graphStl <TV,TE> &g)
{
	g.write(out);
	return out;
}


#endif