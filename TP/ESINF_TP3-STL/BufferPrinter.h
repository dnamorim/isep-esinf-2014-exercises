/* 
 * File:   BufferPrinter.h
 * Author: dnamorim
 *
 * Created on 6 de Outubro de 2014, 15:21
 */

#ifndef BUFFERPRINTER_H
#define	BUFFERPRINTER_H

#include "Document.h"


class BufferPrinter {
    private:
        queue<Document> bufferprinter;
        int tam_max, tam_actual;
        
    public:
        BufferPrinter();
        ~BufferPrinter();
        BufferPrinter(const BufferPrinter &bp);
        void AddsDoc(const Document& doc);
        void ElimDoc(const string nome, const string autor);
        void ElimDocsT(const int tam);
        
        void escreve(ostream& out) const;
};

BufferPrinter::BufferPrinter() : bufferprinter() {
    tam_max = 1000;
    tam_actual = 0;
}

BufferPrinter::BufferPrinter(const BufferPrinter& bp) : bufferprinter(bp.bufferprinter) {
    tam_max = bp.tam_max;
    tam_actual = bp.tam_actual;
}

BufferPrinter::~BufferPrinter() {
    
}

void BufferPrinter::AddsDoc(const Document& doc) {
    if(doc.getTam() < (tam_max - tam_actual)) {
        bufferprinter.push(doc);
        tam_actual += doc.getTam();
        cout << "Inserido: " << doc.getNome() << endl;
    } else {
        cout << "Atenção: Tamanho Excedido do Buffer."<< endl;
    }
}

void BufferPrinter::ElimDoc(const string nome, const string autor) {
    Document doc_aux;
    queue<Document> bp_aux;
    
    while(!bufferprinter.empty()) {
        doc_aux = bufferprinter.front();
        bufferprinter.pop();
        
        if (doc_aux.getNome() != nome || doc_aux.getAutor() != autor) {
            bp_aux.push(doc_aux);
        } else {
            tam_actual -= doc_aux.getTam();
        }
    }
    
    bufferprinter = bp_aux;
}

void BufferPrinter::ElimDocsT(const int tam) {
    Document doc_aux;
    queue<Document> bp_aux;
    
    while(!bufferprinter.empty()) {
        doc_aux = bufferprinter.front();
        bufferprinter.pop();
        
        if (doc_aux.getTam() != tam) {
            bp_aux.push(doc_aux);
        } else {
            tam_actual -= doc_aux.getTam();
        }
    }
    
    bufferprinter = bp_aux;
}

void BufferPrinter::escreve (ostream& out) const {
    queue<Document> bp_aux;
    Document doc_aux;
    
    bp_aux=bufferprinter;
    
    while(!bp_aux.empty()) {
        doc_aux = bp_aux.front();
        out << doc_aux;
        bp_aux.pop();
    }
    out << endl;
}

ostream& operator << (ostream& out, const BufferPrinter& bp) {
    bp.escreve(out);
    return out;
}

#endif	/* BUFFERPRINTER_H */