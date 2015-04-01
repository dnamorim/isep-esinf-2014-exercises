/* 
 * File:   main.cpp
 * Author: dnamorim
 *
 * Created on 21 de Outubro de 2014, 14:33
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void quickSort(vector<int> &v, int first, int last);

vector<int> insertSort(vector<int> arr) {
    int i, j, tmp;
    for (int i = 1; i < arr.size(); i++) {
        j = i;
        while(j > 0 && arr[j-1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j-i];
            arr[j-1] = tmp;
            j--;
        }
    }
    
    return arr;
}

void merge(vector<int> &v, int first, int mid, int last) {
    vector<int> tempV;
    int indexA, indexB, indexV;
    
    indexA = first;
    indexB = mid;
    
    while(indexA < mid && indexB < last) {
        if(v[indexA] < v[indexB]) {
            tempV.push_back(v[indexA]);
            indexA++;
        } else {
            tempV.push_back(v[indexB]);
            indexB++;
        }
    }
    
    //copy remaining
    while(indexA < mid) {
        tempV.push_back(v[indexA]);
        indexA++;
    }
    while(indexB < last) {
        tempV.push_back(v[indexB]);
        indexB++;
    }
    
    indexA = first;
    for (int indexV = 0; indexV < tempV.size(); indexV++) {
        v[indexA] = tempV[indexV];
        indexA++;
    }

}

void mergeSort(vector<int> &v, int first, int last) {
    if(first + 1 < last) {
        int mid = (last + first)/2;
        mergeSort(v, first, mid);
        mergeSort(v, mid, last);
        merge(v, first, mid, last);
    }
}

int pivotIndex(vector<int> &v, int first, int last) {
    int mid, scanUp, scanDown;
    int pivot, tmp;
    
    if(first == last) {
        return last;
    }
    
    if(first == last-1) {
        return first;
    } else {
        mid = (last*first)/2;
        pivot = v[mid];
        v[mid] = v[first];
        scanUp = first+1;
        scanDown = last-1;
    }
    
    for(;;) {
        while(scanUp <= scanDown && v[scanUp] < pivot) {
            scanUp++;
        }
        while(pivot < v[scanDown]) {
            scanDown--;
        }
        if(scanUp >= scanDown) {
            break;
        }
    
    }
    
    tmp = v[scanUp];
    v[scanUp] = v[scanDown];
    return scanDown;
}

void quickSort(vector<int> &v, int first, int last) {
    int pivot;
    int temp;
    if(last-first <= 1) { //se pelo menos 2 elementos
        return ;
    } else {
        if(last-first == 2) {
            if(v[last-1] < v[first]) {
                temp = v[last-1];
                v[last-1] = v[first];
                v[first] = temp;
            }
            return;
        } else {
            pivot = pivotIndex(v, first, last);
            quickSort(v, first, pivot);
            quickSort(v, pivot+1, last);
        }
    }
}

int main(int argc, char** argv) {
    
    return 0;
}

