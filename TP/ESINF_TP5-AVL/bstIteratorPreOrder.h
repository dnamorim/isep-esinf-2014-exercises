/***************************************
 * bstIteratorPreOrder.h
 *
 * Created on 5 de Agosto de 2013, 0:49
 * 
 * @author Nuno Malheiro
 ***************************************/

#ifndef _bstIteratorPreOrder_
#define _bstIteratorPreOrder_

#include <iostream>
#include <stack>

using namespace std;

#include "treeNode.h"
#include "bstIterator.h"

template<class TN>
class bstIteratorPreOrder : public bstIterator<TN>
{
private:
	stack <treeNode <TN> * > unVisited;

public:
	bstIteratorPreOrder();
	bstIteratorPreOrder(const bstIterator<TN> &i);
	bstIteratorPreOrder(const bstIteratorPreOrder<TN> &i);

	bstIterator<TN> & operator++(int);

	bstIterator<TN> & operator=(const bstIterator<TN> &i);
};

template<class TN>
bstIteratorPreOrder<TN>::bstIteratorPreOrder() : bstIterator<TN>(), unVisited()
{
}

template<class TN>
bstIteratorPreOrder<TN>::bstIteratorPreOrder(const bstIterator<TN> &i) : bstIterator<TN>(i), unVisited()
{
}
template<class TN>
bstIteratorPreOrder<TN>::bstIteratorPreOrder(const bstIteratorPreOrder<TN> &i) : bstIterator<TN>(i), unVisited(i.unVisited)
{
}

template<class TN>
bstIterator<TN> & bstIteratorPreOrder<TN>::operator++(int)
{
	if (this->now->getLeft()) {
		if (this->now->getRight()) 
			unVisited.push(this->now);
		this->now=this->now->getLeft();
		return *this;
	}

	if (this->now->getRight()) {
		this->now=this->now->getRight();
		return *this;
	}

	if (!unVisited.empty())
	{
		this->now=unVisited.top()->getRight();
		unVisited.pop();
	} else this->now=NULL;

	return *this;
}
 
template<class TN>
bstIterator<TN> & bstIteratorPreOrder<TN>::operator=(const bstIterator<TN> &i)
{
	bstIterator<TN>::operator=(i);
	return *this;
}
 
#endif