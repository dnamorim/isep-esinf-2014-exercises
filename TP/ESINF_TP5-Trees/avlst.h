/***************************************
 * avlst.h
 *
 * Created on 7 de Agosto de 2013, 11:26
 * 
 * @author Nuno Malheiro
 ***************************************/

#ifndef _avlst_
#define _avlst_

#include <iostream>
#include <cstdlib>

using namespace std;

#include "treeNode.h"
#include "bst.h"

template<class TN>
class avlst : public bst <TN>
{
private:
		treeNode <TN> * RotationLeft (treeNode <TN> * node);
		treeNode <TN> * RotationRight (treeNode <TN> * node);
		treeNode <TN> * twoRotations (treeNode <TN> * node);
		treeNode <TN> * balanceNode (treeNode <TN> * node);

public:
	avlst();
	avlst(const avlst<TN> &a);
	~avlst() ;
};

template<class TN>
treeNode <TN>* avlst<TN>::RotationLeft(treeNode <TN>* node) {

	treeNode <TN> *nodeSon = node->getRight();
	
	node->setRight(nodeSon->getLeft());
	nodeSon->setLeft(node);
	
	node->setLeftHeight(this->getTreeHeight(node->getLeft()));
	node->setRightHeight(this->getTreeHeight(node->getRight()));
	
	nodeSon->setLeftHeight(this->getTreeHeight(nodeSon->getLeft()));
	nodeSon->setRightHeight(this->getTreeHeight(nodeSon->getRight()));
	
	node = nodeSon ;
	
	return node ; 
}

template<class TN>
treeNode <TN> * avlst<TN>::RotationRight(treeNode <TN> * node) {

	treeNode <TN> *nodeSon = node->getLeft();
	
	node->setLeft(nodeSon->getRight());
	nodeSon->setRight(node);
	
	node->setLeftHeight(this->getTreeHeight(node->getLeft()));
	node->setRightHeight(this->getTreeHeight(node->getRight()));
	 
	nodeSon->setLeftHeight(this->getTreeHeight(nodeSon->getLeft()));
	nodeSon->setRightHeight(this->getTreeHeight(nodeSon->getRight()));
	 
	node = nodeSon ;

	return node ;
}

template<class TN>
treeNode <TN> * avlst<TN>::twoRotations(treeNode <TN> * node) {

	if (node->getBalanceFactor() < 0) {
	  node->setLeft(RotationLeft(node->getLeft()));
	  node = RotationRight(node) ;
	}
	else {
	  node->setRight(RotationRight(node->getRight()));	
	  node = RotationLeft(node) ;
	}
	return node ;
}

template<class TN>
treeNode <TN> * avlst<TN>::balanceNode(treeNode <TN> * node)
{
  if (node->getBalanceFactor() < -1) 
       if (node->getLeft()->getBalanceFactor() <= 0)
	      node = RotationRight(node);  
       else  
		  node = twoRotations(node) ; 

   if (node->getBalanceFactor() > 1) 
	   if (node->getRight()->getBalanceFactor() >= 0)
		  node = RotationLeft(node) ;  
       else 
		  node = twoRotations(node) ;  

   return node ;
}

template<class TN>
avlst<TN>::avlst() : bst<TN>()
{}

template<class TN>
avlst<TN>::avlst(const avlst<TN> &a) : bst<TN>(a)
{}

template<class TN>
avlst<TN>::~avlst()
{}



#endif