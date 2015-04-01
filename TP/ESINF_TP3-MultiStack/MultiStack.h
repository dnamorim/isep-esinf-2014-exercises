/* 
 * File:   MultiStack.h
 * Author: dnamorim
 *
 * Created on 13 de Outubro de 2014, 15:25
 */

#ifndef MULTISTACK_H
#define	MULTISTACK_H

#define MAX_STACKS 50
#define MAX_S0 5

class MultiStack {
    private:
        vector< stack<Peca *> > m_stack;
        int capMax;
        
    public :
        MultiStack();
        MultiStack(const MultiStack& m);
        virtual ~MultiStack();
        
        bool empilhar(const Peca *p);
        int desempilhar(const string &c);
        float calculaPeso() const;
        void escreve(ostream& out) const;
};

MultiStack::MultiStack() : m_stack(MAX_STACKS) {
}

MultiStack::MultiStack(const MultiStack& orig) {
    int i=0;
    do {
        stack <Peca *> tmp1(orig.m_stack[i]), tmp2;        
        
        while (!tmp1.empty()) {
            tmp2.push(tmp1.top()->clone());
            tmp1.pop();
        }
        
        while (!tmp2.empty()) {
            m_stack[i].push(tmp2.top());
            tmp2.pop();
        }
        
        i++;
    } while ((i<MAX_STACKS) && (!orig.m_stack[i].empty()));
}

MultiStack::~MultiStack() {
    
}

bool MultiStack::empilhar(const Peca *p) {
    if (m_stack[0].size() == MAX_S0) {
        return false;
    }
    m_stack[0].push(p->clone());

    if (m_stack[0].size() < MAX_S0) {
        return true;
    }
    
    int i=1;
    while (!m_stack[0].empty()) {
        while (m_stack[i].size() == 3*i) i++;
        
        if (i==MAX_STACKS) {
            return true;
        }
        
        m_stack[i].push(m_stack[0].top());
        m_stack[0].pop();
    }
    return true;
    
}

int MultiStack::desempilhar(const string &c) {
    int rem =0;
    int i=0;
    
    // Remove
    do {        
        stack <Peca *> tmp;
        
        while (!m_stack[i].empty()) {
            if (m_stack[i].top()->getCodigo()==c)  {
                delete m_stack[i].top();
                rem++;
            } else tmp.push(m_stack[i].top());
            m_stack[i].pop();
        }
        while (!tmp.empty()) {
            m_stack[i].push(tmp.top());
            tmp.pop();
        }
        i++;
    } while ((i<MAX_STACKS) && (!m_stack[i].empty()));

    // Reorganiza    
    int last = i-1; 
    for (i=1; i<last ; i++) 
    {
        while (m_stack[i].size()<3*i)
        {
            if (!m_stack[last].empty()) {
                m_stack[i].push(m_stack[last].top());
                m_stack[last].pop();
            } else {
                last--;
                if (last==i) return rem;                
            }
        }
    }
        
    return rem;    
}

float MultiStack::calculaPeso() const {
    int peso = 0;
    int i=0;
    do {        
        stack <Peca *> tmp(m_stack[i]);
        while (!tmp.empty()) {
            PecaMontagem *pm = dynamic_cast<PecaMontagem *>(tmp.top());
            if (pm!=NULL) peso +=pm->getPeso();
            tmp.pop();
        }
        i++;
    } while ((i<MAX_STACKS) && (!m_stack[i].empty()));
    return peso;
}

void MultiStack::escreve(ostream& out) const {
    int i=0;
    do {        
        stack <Peca *> tmp(m_stack[i]);
        out << "Stack nº" << i << ": ";
        while (!tmp.empty()) {
            out << *tmp.top() << " ; ";
            tmp.pop();
        }
        out << endl;
        i++;
    } while ((i<MAX_STACKS) && (!m_stack[i].empty()));
}

ostream& operator<< (ostream& out, const MultiStack& m) {
    m.escreve(out);
    return out;
}

#endif	/* MULTISTACK_H */

