//
//  main.cpp
//  ESINF_TP5-AVL
//
//  Created by Duarte Nuno Amorim on 24/11/14.
//  Copyright (c) 2014 Duarte Nuno Amorim. All rights reserved.
//

#include <iostream>
#include "avlst.h"

int main(int argc, const char * argv[]) {
    avlst<int> treeAVL;
    
    //AVL Tree Construction AVL
    treeAVL.push(60);
    treeAVL.push(32);
    treeAVL.push(80);
    treeAVL.push(89);
    treeAVL.push(19);
    treeAVL.push(34);
    treeAVL.push(1);
    
    return 0;
}
