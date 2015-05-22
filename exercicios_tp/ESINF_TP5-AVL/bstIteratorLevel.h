/***************************************
 * bstIteratorLevel.h
 *
 * Created on 5 de Agosto de 2013, 1:33
 * 
 * @author Nuno Malheiro
 ***************************************/

#ifndef _bstIteratorLevel_
#define _bstIteratorLevel_

#include <iostream>
#include <queue>

using namespace std;

#include "treeNode.h"
#include "bstIterator.h"

template<class TN>
class bstIteratorLevel : public bstIterator<TN>
{
private:
	queue <treeNode <TN> * > unVisited;

public:
	bstIteratorLevel();
	bstIteratorLevel(const bstIterator<TN> &i);
	bstIteratorLevel(const bstIteratorLevel<TN> &i);

	bstIterator<TN> & operator++(int);

	bstIterator<TN> & operator=(const bstIterator<TN> &i);
};

template<class TN>
bstIteratorLevel<TN>::bstIteratorLevel() : bstIterator<TN>(), unVisited()
{
}

template<class TN>
bstIteratorLevel<TN>::bstIteratorLevel(const bstIterator<TN> &i) : bstIterator<TN>(i), unVisited()
{
} 

template<class TN>
bstIteratorLevel<TN>::bstIteratorLevel(const bstIteratorLevel<TN> &i) : bstIterator<TN>(i), unVisited(i.unVisited)
{
}

template<class TN>
bstIterator<TN> & bstIteratorLevel<TN>::operator++(int)
{
	if (this->now->getLeft()) unVisited.push(this->now->getLeft());
	if (this->now->getRight()) unVisited.push(this->now->getRight());

	if (!unVisited.empty()) {
		this->now=unVisited.front();
		unVisited.pop();
	} else this->now=NULL;

	return *this;
}
 
template<class TN>
bstIterator<TN> & bstIteratorLevel<TN>::operator=(const bstIterator<TN> &i)
{
	bstIterator<TN>::operator=(i);
	return *this;
}
 
#endif