/***************************************
 * bstIteratorPosOrder.h
 *
 * Created on 5 de Agosto de 2013, 2:01
 * 
 * @author Nuno Malheiro
 ***************************************/

#ifndef _bstIteratorPosOrder_
#define _bstIteratorPosOrder_

#include <iostream>
#include <stack>

using namespace std;

#include "treeNode.h"
#include "bstIterator.h"

template<class TN>
class bstIteratorPosOrder : public bstIterator<TN>
{
private:
	stack <treeNode <TN> * > unVisited;
	stack <bool> unVisitedRight;

	void findDeepestPosOrder(); 
 
public:
	bstIteratorPosOrder();
	bstIteratorPosOrder(const bstIterator<TN> &i);
	bstIteratorPosOrder(const bstIteratorPosOrder <TN> &i);

	virtual bstIterator<TN> & operator++(int);

	bstIterator<TN> & operator=(const bstIterator<TN> &i);
};

template<class TN>
void bstIteratorPosOrder<TN>::findDeepestPosOrder()
{
	if (!this->now) return;

	// while there is at least one subtree
	while (this->now->getLeft() || this->now->getRight())
	{
		// try the left subtree first
		if (this->now->getLeft())
		{
			unVisited.push(this->now);
			unVisitedRight.push(true);
			this->now=this->now->getLeft();
		}

		// go to the right subtree while there is no left subtree
		while ((!this->now->getLeft()) && this->now->getRight())
		{
			unVisited.push(this->now);
			unVisitedRight.push(false);
			this->now=this->now->getRight();
		}
	}
}

template<class TN>
bstIteratorPosOrder<TN>::bstIteratorPosOrder() : bstIterator<TN>(), unVisited()
{
}

template<class TN>
bstIteratorPosOrder<TN>::bstIteratorPosOrder(const bstIterator <TN> &i) : bstIterator<TN>(i), unVisited()
{
	// Get to the first element
	findDeepestPosOrder();
}
template<class TN>
bstIteratorPosOrder<TN>::bstIteratorPosOrder(const bstIteratorPosOrder <TN> &i) : bstIterator<TN>(i), unVisited(i.unVisited), unVisitedRight(i.unVisitedRight)
{
}

template<class TN>
bstIterator<TN> & bstIteratorPosOrder<TN>::operator++(int)
{
	if (!unVisited.empty())
	{
		// if the node has an existant and unvisited right subtree go to it else visit the node
		if (unVisitedRight.top() && unVisited.top()->getRight())
		{
			unVisitedRight.pop();
			unVisitedRight.push(false);
			this->now=unVisited.top()->getRight();
			findDeepestPosOrder();
		} else {
			this->now=unVisited.top();
			unVisited.pop();
			unVisitedRight.pop();
		}
	} else this->now=NULL;

	return *this;
}

template<class TN>
bstIterator<TN> & bstIteratorPosOrder<TN>::operator=(const bstIterator<TN> &i)
{
	bstIterator<TN>::operator=(i);	
	// Get to the first element	
	if (!this->now) 
		return *this;
	
	findDeepestPosOrder();   
	
	return *this;
}

#endif