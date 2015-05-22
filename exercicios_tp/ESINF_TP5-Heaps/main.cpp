//
//  main.cpp
//  ESINF_TP5-Heaps
//
//  Created by Duarte Nuno Amorim on 01/12/14.
//  Copyright (c) 2014 Duarte Nuno Amorim. All rights reserved.
//

#include <iostream>
#include "heap.h"
#include <list>

using namespace std;

bool compare(int v1, int v2) {
    return (v1 > v2);
}
int main(int argc, const char * argv[]) {
    heap<int> hp;

    list<int> lst;
    lst.push_back(2);
    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(4);
    

    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;
    
    lst.sort(compare);
    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;
    
    return 0;
}
