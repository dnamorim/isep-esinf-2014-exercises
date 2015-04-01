/* 
 * File:   tree.h
 * Author: Nuno
 *
 * Created on 17 de Novembro de 2014, 11:12
 */

#ifndef TREE_H
#define	TREE_H


#include "bst.h"
#include "bstIteratorPreOrder.h"
#include "bstIteratorInOrder.h"
#include "bstIteratorPosOrder.h"
#include "bstIteratorLevel.h"

template <class TN>
class tree : public bst <TN> {
private:	
    void preOrder(treeNode <TN> *n, queue <TN> &q) const;
    void inOrder(treeNode <TN> *n, queue <TN> &q) const;
    void posOrder(treeNode <TN> *n, queue <TN> &q) const;
    
    void arvoreSemFolhas(treeNode <TN> *n, tree <TN> &t) const;
public:
    tree();
    tree(const tree<TN> &t);
    ~tree();
	
    queue <TN> preOrder() const;    
    queue <TN> inOrder() const;
    queue <TN> posOrder() const;
    
    queue <TN> preOrderItera();    
    queue <TN> inOrderItera();
    queue <TN> posOrderItera();    

    queue <TN> ordemEsqDirItera();
    
    tree <TN> arvoreSemFolhas() const;
};


template<class TN>
tree<TN>::tree() : bst<TN>()
{
}

template<class TN>
tree<TN>::tree(const tree &t) : bst<TN>(t)
{
}
template<class TN>
tree<TN>::~tree()
{
}

template<class TN>
void tree<TN>::preOrder(treeNode <TN> *n, queue <TN> &q) const
{
	if (!n) return;

	q.push(n->getKey());
	preOrder(n->getLeft(), q);
	preOrder(n->getRight(), q);
}


template<class TN>
void tree<TN>::inOrder(treeNode <TN> *n, queue <TN> &q) const
{
    if (!n) return;
    
    inOrder(n->getLeft(), q);
    q.push(n->getKey());
    inOrder(n->getRight(), q);
}
template<class TN>
void tree<TN>::posOrder(treeNode <TN> *n, queue <TN> &q) const
{
    if (!n) return;
    
    posOrder(n->getLeft(), q);    
    posOrder(n->getRight(), q);
    q.push(n->getKey());
}
template<class TN>
queue <TN> tree<TN>::preOrder() const
{
	queue <TN> q;
	preOrder(this->root, q);
	return q;
}
template<class TN>
queue <TN> tree<TN>::inOrder() const
{
	queue <TN> q;
	inOrder(this->root, q);
	return q;
}
template<class TN>
queue <TN> tree<TN>::posOrder() const
{
	queue <TN> q;
	posOrder(this->root, q);
	return q;
}

template<class TN>
queue <TN> tree<TN>::preOrderItera()
{    
    queue <TN> qe;
    
    for (bstIteratorPreOrder<TN> itpr= this->begin(); 
            itpr!=this->end(); itpr++)
        qe.push(*itpr);
    
    return qe;
}
template<class TN>
queue <TN> tree<TN>::inOrderItera()
{    
    queue <TN> qe;
    
    for (bstIteratorInOrder<TN> itpr= this->begin(); itpr!=this->end(); itpr++)
        qe.push(*itpr);
    
    return qe;
}
template<class TN>
queue <TN> tree<TN>::posOrderItera()
{    
    queue <TN> qe;
    
    for (bstIteratorPosOrder<TN> itpr= this->begin(); itpr!=this->end(); itpr++)
        qe.push(*itpr);
    
    return qe;
}

template<class TN>
queue <TN> tree<TN>::ordemEsqDirItera()
{    
    queue <TN> qe; stack <TN> sd;
    
    for (bstIteratorInOrder<TN> itpr= this->begin(); 
            itpr!=this->end(); itpr++) 
    {
        if (*itpr<=this->root->getKey()) qe.push(*itpr); 
           else sd.push(*itpr);
    }
    
    while (!sd.empty()) {
        qe.push(sd.top());
        sd.pop();
    } 
    
    return qe;
}

template<class TN>
void tree<TN>::arvoreSemFolhas(treeNode <TN> *n, tree <TN> &t) const
{
	if ((!n) || ((!n->getLeft()) && (!n->getRight())))
            return;

	t.push(n->getKey());
	arvoreSemFolhas(n->getLeft(),t);
	arvoreSemFolhas(n->getRight(),t);
}

template<class TN>
tree <TN> tree<TN>::arvoreSemFolhas() const
{
	tree <TN> tmp;
	arvoreSemFolhas(this->root,tmp);
	return tmp;
}

#endif	/* TREE_H */

