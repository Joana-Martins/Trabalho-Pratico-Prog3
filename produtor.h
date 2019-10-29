#ifndef PRODUTOR_H_
#define PRODUTOR_H_

#include<vector>
#include"midia.h"
#include"usuario.h"

using namespace std;

class Produtor: public Usuario{ //o produtor herda atributos de usuario 
    public: 
        vector<Midia*> midias; //um produtor possui várias mídias 
        //métodos da classe, construtores, destrutor, get e sets, impressão em arquivo e no terminal e funções de ordenação
        Produtor();
        Produtor(string nome, int codigo);
        ~Produtor();
        void set_midias(Midia* midia);
        vector<Midia*> get_midias();
        void imprimeProdutosDesenvolvidos();
        virtual void imprimeNoArquivo(ofstream &outfile){}
        int partition(int p, int r);
        void quicksort(int p, int r);
};

#endif
