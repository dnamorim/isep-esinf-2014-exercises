/* 
 * File:   Escola.h
 * Author: dnamorim
 *
 * Created on 23 de Setembro de 2014, 14:53
 */

#ifndef Escola_
#define	Escola_
#define MAX_DEP 10

#include <stddef.h>

#include "Pessoa.h"
#include "Aluno.h"
#include "Professor.h"

class Escola {
    private :
        int dimensao;
        int actual;
        Pessoa* *pessoas;
        
        int verificaCursos(string* cursos);//<=> string[]
        
    public :
        Escola(int d);
        Escola(const Escola& e);
        ~Escola();
        
        void insElem(Pessoa* p);
        float idadeMed();
        void listarAlunos();
        void alterCurso(int i, int f);
        bool operator !=(const Escola& e);
        int verificaDepartamentos(string* departamentos) const;
        
        void escreve(ostream& out) const;
};

Escola::Escola(int d) {
    dimensao = d;
    actual = 0;
    pessoas = new Pessoa *[d];
}

Escola::Escola(const Escola& e) {
    dimensao = e.dimensao;
    actual = e.actual;
    pessoas = new Pessoa *[dimensao];
    for (int i = 0; i < actual; i++) {
        if (e.pessoas[i] != NULL){
            pessoas[i] = e.pessoas[i]->clone();
        }
    }
}

Escola::~Escola() {
    for (int i = 0; i < actual; i++) {
        delete pessoas[i];
    }
    delete [] pessoas;
}

void Escola::insElem(Pessoa* p) {
    if(actual == dimensao) {
        Pessoa* *ptemp;
        ptemp = new Pessoa* [2*dimensao];
        for (int i = 0; i < dimensao; i++) {
            ptemp[i] = pessoas[i];
        }
        dimensao = 2*dimensao;
        delete [] pessoas;
        pessoas = ptemp;
    }
    
    pessoas[actual] = p->clone();
    actual++;
}

float Escola::idadeMed() {
    int med=0, c=0;
    for (int i = 0; i < actual; i++) {
        if(typeid(*pessoas[i]) == typeid(Aluno)) {
            med += pessoas[i]->getDataNac().getAnos();
            c++;
        }
    }
    
    return ((float)med/ (float)c);
}

void Escola::alterCurso(int i, int f) {
    Aluno* a;
    string c;
    
    for (int i = 0; i < actual; i++) {
        if(typeid(Aluno) == typeid(*pessoas[i])) {
            a = dynamic_cast<Aluno *>(pessoas[i]);
            if((a->getNr() >= i) && (a->getNr() <= f)) {
                cout << "\nDefina o curso novo para o aluno " << a->getNome() << ":" << endl;
                cin >> c;
                a->setCurso(c);
            }
        }
    }
}

void Escola::listarAlunos() {
    string cursos[10];
    int nCursos=verificaCursos(cursos);
    Aluno* a;
    
    for (int i = 0; i < nCursos; i++) {
    cout << "Listagem de Alunos de " << cursos[i] << "\n" << endl;
        for(int j=0; j < actual; j++) {
            if(typeid(*pessoas[j]) == typeid(Aluno)) {
                a = dynamic_cast<Aluno *>(pessoas[j]);
                if(cursos[i] == a->getCurso()) {
                    cout << *a;
                }
            }
        }
    }
}

int Escola::verificaCursos(string* cursos) {
    int nCursos=0;
    Aluno* a;
    bool existeCurso=false;
    
    for (int i = 0; i < actual; i++) {
        if(typeid(*pessoas[i]) == typeid(Aluno)) {
            a = dynamic_cast<Aluno *>(pessoas[i]);
            for (int j = 0; j < nCursos; j++) {
                if(cursos[j] == a->getCurso()) {
                    existeCurso = true;
                } else {
                    existeCurso = false;
                }
            }
            
            if(!existeCurso) {
                cursos[nCursos]=a->getCurso();
                nCursos++;
            }
        }
    }
    return nCursos;
}

/**
 * Exercício Avaliação 1 ESINF - Implementar o operador != que compara duas escolas quando ao nº de departamento diferentes. 
 * Nome: AIS-2DK-1130674-1120703.ext
 *  
 * @param e Escola a comparar se diferente
 * @return TRUE se diferentes, FALSE se iguais
 */
bool Escola::operator !=(const Escola& e) {
    string departamentosEscolaA[MAX_DEP];
    int nDepartamentosEscolaA = verificaDepartamentos(departamentosEscolaA);
    
    string departamentosEscolaB[MAX_DEP];
    int nDepartamentosEscolaB = e.verificaDepartamentos(departamentosEscolaB);
    
    return ((nDepartamentosEscolaA == nDepartamentosEscolaB) ? false : true);
}

int Escola::verificaDepartamentos(string* departamentos) const {
    int nDepartamentos=0;
    Professor* p;
    bool existeDepartamento=false;
    
    for (int i = 0; i < actual; i++) {
        if(typeid(*pessoas[i]) == typeid(Professor)) {
            p = dynamic_cast<Professor *>(pessoas[i]);
            for (int j = 0; j < nDepartamentos; j++) {
                if(departamentos[j] == p->getDepartamento()) {
                    existeDepartamento = true;
                } else {
                    existeDepartamento = false;
                }
            }
            
            if(!existeDepartamento) {
                departamentos[nDepartamentos]=p->getDepartamento();
                nDepartamentos++;
            }
        }
    }
    return nDepartamentos;
}


 
void Escola::escreve(ostream& out) const {
    out << "Listagem de Pessoas pertencentes à Escola (" << actual << "/" << dimensao << "): " << endl;
    for (int i = 0; i < actual; i++) {
        out << *pessoas[i];
    }  
}

ostream& operator << (ostream& out, const Escola& e) {
    e.escreve(out);
    return out;
}


#endif	/* Escola_ */



