/***************************************
 * bstIteratorInOrder.h
 *
 * Created on 5 de Agosto de 2013, 2:01
 * 
 * @author Nuno Malheiro
 ***************************************/

#ifndef _bstIteratorInOrder_
#define _bstIteratorInOrder_

#include <iostream>
#include <stack>

using namespace std;

#include "treeNode.h"
#include "bstIterator.h"

template<class TN>
class bstIteratorInOrder : public bstIterator<TN>
{
private:
	stack <treeNode <TN> * > unVisited;

	void findFirstElement();

public:
	bstIteratorInOrder();
	bstIteratorInOrder(const bstIterator<TN> &i);
	bstIteratorInOrder(const bstIteratorInOrder<TN> &i);

	bstIterator<TN> & operator++(int);
	
	bstIterator<TN> & operator=(const bstIterator<TN> &i) ;
};

template<class TN>
void bstIteratorInOrder<TN>::findFirstElement()
{
	if (!this->now) return;
	while (this->now->getLeft())
	{
		unVisited.push(this->now);
		this->now=this->now->getLeft();
	}
}

template<class TN>
bstIteratorInOrder<TN>::bstIteratorInOrder() : bstIterator<TN>(), unVisited()
{
}

template<class TN>
bstIteratorInOrder<TN>::bstIteratorInOrder(const bstIterator<TN> &i) : bstIterator<TN>(i), unVisited()
{
	findFirstElement();
} 

template<class TN>
bstIteratorInOrder<TN>::bstIteratorInOrder(const bstIteratorInOrder<TN> &i) : bstIterator<TN>(i), unVisited(i.unVisited)
{
}

template<class TN>
bstIterator<TN> & bstIteratorInOrder<TN>::operator++(int)
{
	if (this->now->getRight()) {
		this->now=this->now->getRight();
		while (this->now->getLeft())
		{
			unVisited.push(this->now);
			this->now=this->now->getLeft();
		}
		return *this;
	}

	if (!unVisited.empty())
	{
		this->now=unVisited.top();
		unVisited.pop();
	} else this->now=NULL;

	return *this;
}
 
template<class TN>
bstIterator<TN> & bstIteratorInOrder<TN>::operator=(const bstIterator<TN> &i)
{
	bstIterator<TN>::operator=(i);
	findFirstElement();
	return *this;
}
 
#endif