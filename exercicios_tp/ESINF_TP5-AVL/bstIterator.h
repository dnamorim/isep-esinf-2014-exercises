/***************************************
 * bstIterator.h
 *
 * Created on 5 de Agosto de 2013, 0:15
 * 
 * @author Nuno Malheiro
 ***************************************/

#ifndef _bstIterator_
#define _bstIterator_

#include <iostream>

using namespace std;

#include "treeNode.h"

template<class TN>
class bstIterator
{
protected:
	treeNode <TN> *now;

public:
	bstIterator();
	bstIterator(treeNode <TN> *now);
	bstIterator(const bstIterator<TN> &i);

	TN operator*() const;
	TN operator->() const;
	bool operator==(const bstIterator<TN> &i) const;
	bool operator!=(const bstIterator<TN> &i) const;

	virtual bstIterator<TN> & operator++(int) { return *this;}; // dummy
	virtual bstIterator<TN> & operator=(const bstIterator<TN> &i);

};

template<class TN>
bstIterator<TN>::bstIterator() : now(NULL)
{
}

template<class TN>
bstIterator<TN>::bstIterator(treeNode <TN> *now) : now(now)
{
}

template<class TN>
bstIterator<TN>::bstIterator(const bstIterator<TN> &i) : now(i.now)
{
}

template<class TN>
TN bstIterator<TN>::operator*() const
{
	return now->getKey();
}

template<class TN>
TN bstIterator<TN>::operator->() const
{
	return now->getKey();
}
	
template<class TN>
bool bstIterator<TN>::operator==(const bstIterator<TN> &i) const
{
	return (now==i.now);
}
	
template<class TN>
bool bstIterator<TN>::operator!=(const bstIterator<TN> &i) const
{
	return (now!=i.now);
}

template<class TN>
bstIterator<TN> & bstIterator<TN>::operator=(const bstIterator<TN> &i)
{
	now=i.now;
	return *this;
}


#endif
