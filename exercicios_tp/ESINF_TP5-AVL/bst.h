/***************************************
 * bst.h
 *
 * Created on 4 de Agosto de 2013, 14:40
 * 
 * @author Nuno Malheiro
 ***************************************/

#ifndef _bst_
#define _bst_

#include "treeNode.h"
#include "bstIterator.h"


template<class TN>
class bst
{
protected:
	treeNode <TN> *root;
	int nodeCount;

	virtual bool lessThanKeys(const TN &key1, const TN &key2); // If TN is a pointer type, this method should be overloaded
	virtual bool equalToKeys(const TN &key1, const TN &key2); // If TN is a pointer type, this method should be overloaded
	
	treeNode <TN> *copyRecursive(const treeNode <TN> *node);  
	int getTreeHeight(treeNode <TN> *node) const;  

	treeNode <TN> * deleteAndUpdate(treeNode <TN> *toDelete, treeNode <TN> *node, treeNode <TN> * &substitute);  
	treeNode <TN> * popOneNode(treeNode <TN> *node);  

	virtual treeNode <TN> * balanceNode(treeNode <TN> *node) { return node; } // dummy (used to avoid code repetition in subclasses)
	treeNode <TN> * pushRecursive(treeNode <TN> *node, const TN &key, bool &isInserted);
	treeNode <TN> * popRecursive(treeNode <TN> *node, const TN &key, bool &isDeleted);
	void clearRecursive(treeNode <TN> *node);

public:
	bst();
	bst(const bst<TN> &bst);
	~bst();

	int getTreeHeight() const;

	int size() const;
	bool push(const TN &key);
	bool pop(const TN &key);
	void clear();

	bstIterator<TN> begin();
	bstIterator<TN> end();

};

template<class TN>
bool bst<TN>::lessThanKeys(const TN &key1, const TN &key2)
{
	return (key1<key2);
}

template<class TN>
bool bst<TN>::equalToKeys(const TN &key1, const TN &key2)
{
	return (key1==key2);
}

template<class TN>
treeNode <TN> * bst<TN>::copyRecursive(const treeNode <TN> *node)
{
	if (!node) return NULL;

	treeNode <TN> *n = new treeNode<TN>(node->getKey(), node->getLeftHeight(), node->getRightHeight());
	
	n->setLeft(copyRecursive(node->getLeft()));
	n->setRight(copyRecursive(node->getRight()));

	return n;
}

template<class TN>
int bst<TN>::getTreeHeight(treeNode <TN> *node) const
{
	if (!node) return 0;

	int l = getTreeHeight(node->getLeft())+1;
	int r = getTreeHeight(node->getRight())+1;

	return ((l<r)?r:l);
}


template<class TN>
treeNode <TN> * bst<TN>::pushRecursive(treeNode <TN> *node, const TN &key, bool &isInserted)
{
	if (!node) {
		isInserted=true;
		node = new treeNode<TN>(key);
		return node;
	}

	if (equalToKeys(node->getKey(), key)) {
		isInserted=false;
		return node;
	}

	if (lessThanKeys(node->getKey(), key))
	{
		treeNode <TN> *rn = pushRecursive(node->getRight(),key,isInserted);
		if (isInserted) {
			node->setRightSide(rn,getTreeHeight(rn));			
			node=balanceNode(node);// check node balance (used for balanced trees only)
		}		
	}
	else 
	{
		treeNode<TN> *rn = pushRecursive(node->getLeft(),key,isInserted);
		if (isInserted) {
			node->setLeftSide(rn,getTreeHeight(rn));			
			node=balanceNode(node);// check node balance (used for balanced trees only)
		}
	}
	return node;
}

template<class TN>
treeNode <TN> * bst<TN>::deleteAndUpdate(treeNode <TN> *toDelete, treeNode <TN> *node, treeNode <TN> * &substitute)
{
	if (node->getRight()) node->setRight(deleteAndUpdate(toDelete,node->getRight(),substitute)); 
	else {
		substitute=node;
		node->setRightSide(toDelete->getRight(),toDelete->getRightHeight());
		if (node==toDelete->getLeft()) return node->getLeft(); // first node is closest

		treeNode <TN> *leftTree=node->getLeft();
		node->setLeftSide(toDelete->getLeft(),getTreeHeight(toDelete->getLeft()));
		return leftTree;
	}
	node->setRightHeight(getTreeHeight(node->getRight()));
	node=balanceNode(node);
	return node;
}

template<class TN>
treeNode <TN> * bst<TN>::popOneNode(treeNode <TN> *toDelete) // pop one node maintaining the tree's integrity
{
	treeNode <TN> *newNode, *newLeft;
	// There is no left node, so simply delete it
	if (!toDelete->getLeft()) {
		newNode=toDelete->getRight();
		delete toDelete;
		return newNode;
	}

	newLeft=deleteAndUpdate(toDelete,toDelete->getLeft(), newNode);
	newNode->setLeftSide(newLeft,getTreeHeight(newLeft));
	newNode=balanceNode(newNode);

	delete toDelete;
	return newNode;
}

template<class TN>
treeNode <TN> * bst<TN>::popRecursive(treeNode <TN> *node, const TN &key, bool &isDeleted)
{
	if (!node) {
		isDeleted=false;
		return node;
	}

	if (equalToKeys(node->getKey(), key)) {
		isDeleted=true;
		return popOneNode(node);
	}
	if (lessThanKeys(node->getKey(), key))
	{
		treeNode<TN> *rn = popRecursive(node->getRight(),key,isDeleted);
		if (isDeleted) {
			node->setRightSide(rn,getTreeHeight(rn));
			node=balanceNode(node);// check node balance (used for balanced trees only)
		}
	}
	else 
	{
		treeNode<TN> *rn = popRecursive(node->getLeft(),key,isDeleted);
		if (isDeleted) {
			node->setLeftSide(rn,getTreeHeight(rn));
			node=balanceNode(node);// check node balance (used for balanced trees only)
		}
	}
	return node;
}


template<class TN>
void bst<TN>::clearRecursive(treeNode <TN> *node)
{
	if (!node) return;

	clearRecursive(node->getLeft());
	clearRecursive(node->getRight());

	delete node;
}

template<class TN>
bst<TN>::bst() : root(NULL), nodeCount(0)
{
}

template<class TN>
bst<TN>::bst(const bst<TN> &bst) : nodeCount(bst.nodeCount)
{
	root=copyRecursive(bst.root);
}

template<class TN>
bst<TN>::~bst()
{
	clear();
}

template<class TN>
int bst<TN>::getTreeHeight() const
{
	return getTreeHeight(root);
}

template<class TN>
int bst<TN>::size() const
{
	return nodeCount;
}

template<class TN>
bool bst<TN>::push(const TN &key)
{
	bool isInserted;
	root=pushRecursive(root,key,isInserted);
	if (isInserted) nodeCount++;
	return isInserted;
}

template<class TN>
bool bst<TN>::pop(const TN &key)
{
	bool isDeleted=false;
	root=popRecursive(root,key,isDeleted);
	if (isDeleted) nodeCount--;
	return isDeleted;
}

template<class TN>
void bst<TN>::clear()
{
	clearRecursive(root);
	root=NULL;
	nodeCount=0;
}
 
template<class TN>
bstIterator<TN> bst<TN>::begin()
{
	return bstIterator<TN>(root);
}

template<class TN>
bstIterator<TN> bst<TN>::end()
{
	return bstIterator<TN>();
}


#endif