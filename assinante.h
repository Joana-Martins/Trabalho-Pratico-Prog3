#ifndef ASSINANTE_H_
#define ASSINANTE_H_

#include"usuario.h"
#include"midia.h"
#include<vector>
#include<iostream>

using namespace std;

class Midia;
class Assinante: public Usuario{
    public:
        vector<Midia*> favoritos;
        Assinante();
        Assinante(string nome, int codigo);
        ~Assinante();
        void set_favoritos(Midia* favorito);
        vector<Midia*> get_favoritos();
        void imprimeFavoritos();
        void inserirFavorito(Midia* favorito);
        void removerFavorito(Midia* favorito);
        virtual void imprimeNoArquivo(ofstream &outfile){}
        int partition(int p, int r);
        void quicksort(int p, int r);
};

#endif