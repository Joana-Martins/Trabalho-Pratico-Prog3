#ifndef PRODUTOR_H_
#define PRODUTOR_H_

#include<vector>
#include"midia.h"
#include"usuario.h"

using namespace std;

class Produtor: public Usuario{
    public:
        vector<Midia*> midias;
        Produtor();
        Produtor(string nome, int codigo);
        ~Produtor();
        void set_midias(Midia* midia);
        vector<Midia*> get_midias();
        void imprimeProdutosDesenvolvidos();
        virtual void imprimeNoArquivo(ofstream &outfile){}
};

#endif
