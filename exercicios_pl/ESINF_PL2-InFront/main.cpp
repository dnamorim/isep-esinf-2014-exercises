/* 
 * File:   main.cpp
 * Author: dnamorim
 *
 * Created on 13 de Outubro de 2014, 15:17
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#include "inFront.h"
/*
 * 
 */
int main(int argc, char** argv) {
    InFront<string> inf(8);
    string sve[15] = {	"strA", "strB", "strC", "strD", "strE", "strF", "strG", "strH", "strH", "strI", "strJ", "strK", "strL", "strM", "strG"};
    
    
    //inserir elementos
    for (int i = 0; i < 5; i++) {
        inf.push(0, sve[i]);
    }
    for (int i = 5; i < 15; i++) {
        inf.push(1, sve[i]);
    }
    
    //print
    cout << inf << endl;
    
    //remover 1 elementos da sequencia 1
    inf.pop(1, 3);
    
    //print
    cout << inf << endl;
    return 0;
}

