//
//  tree.h
//  ESINF_TP5-Trees
//
//  Created by Duarte Nuno Amorim on 17/11/14.
//  Copyright (c) 2014 Duarte Nuno Amorim. All rights reserved.
//

// Notas Teórico-Prática:
//
// Numa árvore binária, cada nó tem 0, 1 ou 2 filhos.
// De forma recursiva, podemos definir uma árvore binária como sendo:
//  - uma árvore vazia
//  - um nó raíz tendo 2 sub-árvores, identificadas como a sub-árvore da direita e a sub-árvore da esquerda.

// Visitas/Travesias:
//  - Ordem: Esq., Raíz, Dir.
//  - Pré-Ordem: Raíz, Esq., Dir.
//  - Pós-Ordem: Esq., Dir., Raíz
//  - Nível

#ifndef ESINF_TP5_Trees_tree_h
#define ESINF_TP5_Trees_tree_h

#include "bst.h"
#include "treeNode.h"

template<class TN>
class tree : public bst<TN> {
    
public: //Interface Functions
    void createMirrorTree(const tree<TN> &node) {
    void inOrder() const;
    void inDecrescent() const;
    void listInOrderLeftInDescrescentRight() const;
    void createTreeWithoutLeafs(const tree<TN> &node);
    
private: //Recursive Functions
    void inOrder(treeNode<TN>* rz) const;
    void inDecrescent(treeNode<TN>* rz) const;
    void listInOrderLeftInDescrescentRight(treeNode<TN>* rz) const;
    treeNode<TN>* createMirrorTree(treeNode<TN>* node);
    treeNode<TN>* createTreeWithoutLeafs(treeNode<TN>* node);
};

template<class TN>
void tree<TN>::inOrder() const {
    cout << "Visita em Ordem (ou Simétrica):\n" << endl;
    inOrder(this->root);
}

template<class TN>
void tree<TN>::inOrder(treeNode<TN>* rz) const {
    if(rz != NULL) {
        inOrder(rz->getLeft());
        cout << rz->getKey() << " ";
        inOrder(rz->getRight());
    }
}

template<class TN>
void tree<TN>::inDecrescent() const {
    cout << "Visita em Ordem Decrescente:\n" << endl;
    inDecrescent(this->root);
}

template<class TN>
void tree<TN>::inDecrescent(treeNode<TN>* rz) const {
    if(rz != NULL) {
        inDecrescent(rz->getRight());
        cout << rz->getKey() << " ";
        inDecrescent(rz->getLeft());
    }
}

template<class TN>
void tree<TN>::listInOrderLeftInDescrescentRight() const {
    cout << "Visita em \n:";
    listEsqDir(this->root);
}

template<class TN>
void tree<TN>::listInOrderLeftInDescrescentRight(treeNode<TN>* rz) const {
    if(rz != NULL) {
        inOrder(rz->getLeft());
        cout << rz->getKey() << " ";
        inDecrescent(rz->getRight());
    }
}

template<class TN>
void tree<TN>::createMirrorTree(const tree<TN> &node){
    this->root = createMirrorTree(node.root);
}
    
template<class TN>
treeNode<TN>* tree<TN>::createMirrorTree(treeNode<TN>* node) {
    if (node == NULL) { //  Empty Tree
        return NULL;
    }
    
    if (node->getLeft() == NULL && node->getRight() == NULL) {  // Empty Leaf Nodes
        return NULL;
    }
    
    treeNode<TN> *n = new treeNode<TN>(node->getKey());
    n->setLeft(createMirrorTree(node->getRight()));
    n->setRight(createMirrorTree(node->getLeft()));
    
    return n;
}

template<class TN>
void tree<TN>::createTreeWithoutLeafs(const tree<TN> &node){
    this->root = createMirrorTree(node.root);
}

template<class TN>
treeNode<TN>* tree<TN>::createTreeWithoutLeafs(treeNode<TN>* node) {
    if (node == NULL) { //  Empty Tree
        return NULL;
    }
    
    if (node->getLeft() == NULL && node->getRight() == NULL) {  // Empty Leaf Nodes
        return NULL;
    }
    
    treeNode<TN> *n = new treeNode<TN>(node->getKey(), node->getLeftHeight(), node->getRightHeight());
    n->setLeft(createTreeWithoutLeafs(node->getLeft()));
    n->setRight(createTreeWithoutLeafs(node->getRight()));
    
    return n;
}





#endif
