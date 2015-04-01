/***************************************
 * treeNode.h
 *
 * Created on 4 de Agosto de 2013, 14:40
 * 
 * @author Nuno Malheiro
 ***************************************/

#ifndef _treeNode_
#define _treeNode_

#include <iostream>

using namespace std;

template<class TN>
class treeNode
{
	private:
		TN key;
		treeNode <TN> *left, *right;
		int hLeft, hRight;

	public:
		treeNode();
		treeNode(const TN &key, int hLeft=0, int hRight=0, treeNode <TN> *left=NULL, treeNode <TN> *right=NULL );
		treeNode(const treeNode <TN> &n);
		~treeNode();

		TN getKey() const;

		treeNode <TN> *getLeft() const;
		void setLeft(treeNode <TN> *left);

		treeNode <TN> *getRight() const;
		void setRight(treeNode <TN> *right);

		int getLeftHeight() const;
		void setLeftHeight(int lh);
		void setLeftSide(treeNode <TN> *left, int lh);

		int getRightHeight() const;
		void setRightHeight(int rh);
		void setRightSide(treeNode <TN> *right, int rh);

		int getBalanceFactor() const;
};


/*************************************
	treeNode Implementation
*************************************/

template<class TN>
treeNode<TN>::treeNode() : key(), left(NULL), right(NULL), hLeft(0), hRight(0)
{
}

template<class TN>
treeNode<TN>::treeNode(const TN &key , int hLeft, int hRight , treeNode <TN> *left, treeNode <TN> *right ) : 
	key(key), hLeft(hLeft), hRight(hRight), left(left), right(right)
{
}

template<class TN>
treeNode<TN>::treeNode(const treeNode <TN> &n) : key(n.key), left(n.left), right(n.right), hLeft(n.hLeft), hRight(n.hRight)
{
}

template<class TN>
treeNode<TN>::~treeNode() 
{
}

template<class TN>
TN treeNode<TN>::getKey() const
{
	return key;
}

template<class TN>
treeNode <TN> * treeNode<TN>::getLeft() const
{
	return left;
}

template<class TN>
void treeNode<TN>::setLeft(treeNode <TN> *left)
{
	this->left = left;
}

template<class TN>		
treeNode <TN> * treeNode<TN>::getRight() const
{
	return right;
}

template<class TN>
void treeNode<TN>::setRight(treeNode <TN> *right)
{
	this->right = right;
}

template<class TN>
void treeNode<TN>::setRightSide(treeNode <TN> *right, int rh)
{
	this->right = right;
	this->hRight=rh;
}

template<class TN>
void treeNode<TN>::setLeftSide(treeNode <TN> *left, int lh)
{
	this->left=left;
	this->hLeft = lh;
}

template<class TN>
int treeNode<TN>::getLeftHeight() const
{
	return hLeft;
}

template<class TN>
void treeNode<TN>::setLeftHeight(int lh)
{
	this->hLeft = lh;
}

template<class TN>
int treeNode<TN>::getRightHeight() const
{
	return hRight;
}

template<class TN>
void treeNode<TN>::setRightHeight(int rh)
{
	this->hRight=rh;
}

template<class TN>
int treeNode<TN>::getBalanceFactor() const
{
	return (hRight-hLeft);
}


#endif