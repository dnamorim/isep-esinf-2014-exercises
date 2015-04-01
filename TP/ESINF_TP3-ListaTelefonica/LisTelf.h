/* 
 * File:   LisTelf.h
 * Author: dnamorim
 *
 * Created on 13 de Outubro de 2014, 16:09
 */

#ifndef LISTELF_H
#define	LISTELF_H

class LisTelf {
    private:
        map<string, list<string>> contactos;

        bool validaNumero(const string &nr);
        
    public :
        LisTelf();
        LisTelf(const LisTelf& l);
        ~LisTelf();
        
        void inserirContacto(const string &nome, const string &nr);
        list<string> get(const string &nome);
};

bool LisTelf::validaNumero(const string &nr) {
    return ((nr.size() == 9) &&                                        // Testa # de dígitos
            (nr.find_first_not_of("0123456789") == string::npos) &&     // Testa se somente digitos
            (nr.substr(0,1).find_first_not_of("29") == string::npos) ); // Testa o primeiro digito
}

LisTelf::LisTelf() : contactos() {
}

LisTelf::LisTelf(const LisTelf& lt) : contactos(lt.contactos) {    
}

LisTelf::~LisTelf() {
}

bool LisTelf::inserirContacto(const string &nome, const string &nr) {
    if (!validaNumero(nr)) return false;
    
    map <string, list <string> >::iterator it = contactos.find(nome);
    
    if (it==contactos.end()) { // Não existe o nome
        list <string> ls;
        ls.push_back(nr);
        contactos[nome]=ls;
        return true;
    }
    
    if (find( it->second.begin(), it->second.end(), nr) != it->second.end())    // Já existe o número
        return true;
    
    it->second.push_back(nr);
    
    return true;
}

list <string> LisTelf::get(const string &nome) {
    map <string, list <string> >::iterator it = contactos.find(nome);
    
    if (it==contactos.end()) return list <string>();
    
    return it->second;    
}


#endif	/* LISTELF_H */
