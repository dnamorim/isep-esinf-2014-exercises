/* 
 * File:   RingBuffer.h
 * Author: dnamorim
 *
 * Created on 16 de Outubro de 2014, 16:25
 */

#ifndef RINGBUFFER_H
#define	RINGBUFFER_H

template <class T>
class RingBuffer {
    private :
        deque<T> buffer;
        int pos;
        int dimensao;
        
    public :
        RingBuffer(int d);
        RingBuffer();
        RingBuffer(const RingBuffer& rb);
        ~RingBuffer();
        
        void insert(const T& obj);
        T remove();
        void escreve(ostream& out) const;
};

template <class T>
RingBuffer<T>::RingBuffer(int d) {
    dimensao = d;
    pos = 0;
}

template <class T>
RingBuffer<T>::RingBuffer() {
    dimensao = 10;
    pos = 0;
}

template <class T>
RingBuffer<T>::RingBuffer(const RingBuffer<T>& rb) : buffer(rb.buffer) {
    dimensao = rb.dimensao;
    pos = rb.pos;
}

template <class T>
RingBuffer<T>::~RingBuffer() {
    
}

template <class T>
void RingBuffer<T>::insert(const T& obj) {
    if(pos == dimensao) {
        buffer.pop_front();
        buffer.push_back(obj);
    } else {
        buffer.push_back(obj);
        pos++;
    }
}

template <class T>
T RingBuffer<T>::remove() {
    pos--;
    T obj = buffer.front();
    buffer.pop_front();
    return obj;
}

template <class T>
void RingBuffer<T>::escreve(ostream& out) const {
    out << "Estado do RingBuffer:\n" << endl;
    deque<T> dq = buffer;
    while(!dq.empty()) {
        out << dq.front() << endl;
        dq.pop_front();
    }
    out << endl;
}

template <typename T>
ostream& operator << (ostream& out, const RingBuffer<T>& rb) {
    rb.escreve(out);
    return out;
}

#endif	/* RINGBUFFER_H */

