/* 
 * File:   Document.h
 * Author: dnamorim
 *
 * Created on 6 de Outubro de 2014, 15:30
 */

#ifndef DOCUMENT_H
#define	DOCUMENT_H

class Document {
    private:
        string nome;
        string autor;
        int tamanho;
        
    public:
        Document(string n, string a, int s);
        Document(const Document &doc);
        Document();
        ~Document();
        
        Document& operator=(const Document& doc);
        bool operator==(const Document& doc) const;
        
        int getTam() const;
        string getNome() const;
        string getAutor() const;
        
        void escreve(ostream& out) const;
};

Document::Document(string n, string a, int s) {
    nome = n;
    autor = a;
    tamanho = s;
}

Document::Document(const Document& doc) {
    nome = doc.nome;
    autor = doc.autor;
    tamanho = doc.tamanho;
}

Document::Document() {
    nome = "";
    autor = "";
    tamanho = 0;
}
Document::~Document() {
    
}

string Document::getNome() const {
    return nome;
}

string Document::getAutor() const {
    return autor;
}

int Document::getTam() const {
    return tamanho;
}

void Document::operator =(const Document& doc) {
    if(this != &doc) {
        nome = doc.nome;
        autor = doc.autor;
        tamanho = doc.tamanho;
    }
    return *this;
}

bool Document::operator == (const Document &doc) const {
     return ((nome==doc.nome)&&(autor==doc.autor));
 }

void Document::escreve(ostream& out) const {
    out << "-- Documento " << nome << " -- Autor: " << autor << "; Tamanho: " << tamanho << endl;
}

ostream& operator<<(ostream& out, const Document& doc) {
    doc.escreve(out);
    return out;
}

#endif	/* DOCUMENT_H */

