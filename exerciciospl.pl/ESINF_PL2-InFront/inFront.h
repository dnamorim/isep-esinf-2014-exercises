/* 
 * File:   inFront.h
 * Author: dnamorim
 *
 * Created on 9 de Outubro de 2014, 16:23
 */

#ifndef INFRONT_H
#define	INFRONT_H

template <class T>
class InFront {
    private:
        vector<deque<T> > vec;
        typename deque<T>::iterator it;
        int max;
        
    public:
        InFront(int n);
        InFront();
        InFront(const InFront& inf);
        ~InFront();
        
        //bool operator =(const InFront& inf);
        
        void push(int i, const T& obj);
        void pop(int i, int n);
        void escreve(ostream& out) const;
};

template <class T>
InFront<T>::InFront(int n)
{
    max = n;
    deque<T> seq;
    vec.push_back(seq);
}

template <class T>
InFront<T>::InFront() {
    max = 10;
    deque<T> seq;
    vec.push_back(seq);
}

template <class T>
InFront<T>::InFront(const InFront& inf) : vec(inf.vec) {
    max = inf.max;
}

template <class T>
InFront<T>::~InFront() {
    
}

template <class T>
void InFront<T>::push(int pos, const T& obj) {
    for (int i = (int) vec.size(); i <= pos; i++) {
        vec.push_back(deque<T>());
    }
    
    //eliminar objecto repetido
    deque<T> dtmp, ds=vec[pos];
    vec[pos].clear();
    while (!ds.empty()) {
        if (ds.front()!=obj) {
            dtmp.push_back(ds.front());
        }
        ds.pop_front();
       
    }
    vec[pos]=dtmp;
   ////Inserir objecto na sequencia
    vec[pos].push_front(obj);
}


template <class T>
void InFront<T>::pop(int i, int n) {
    int c = 0;
    while(c != n && !(vec[i].empty())) {
        vec[i].pop_back();
        c++;
    }
    
}

template <class T>
void InFront<T>::escreve(ostream& out) const {
    out << "Listagem de Instância de InFront" << endl;
    
    for (int i = 0; i < (int) vec.size(); i++) {
        cout << "Sequência " << i << endl;
        
        deque<T> aux = vec[i];
        while (!aux.empty()) {
            out << aux.front() << "; ";
            aux.pop_front();
        }
        
        cout << endl;
    }

}

template <typename T>
ostream& operator << (ostream& out, const InFront<T>& inf) {
    inf.escreve(out);
    return out;
}


#endif	/* INFRONT_H */

