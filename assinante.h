#ifndef ASSINANTE_H_
#define ASSINANTE_H_

#include"usuario.h"
#include"midia.h"
#include<vector>
#include<iostream>

using namespace std;

class Midia;
class Assinante: public Usuario{//o assinante herda características ds classe usuario 
    public:
        vector<Midia*> favoritos; //um usuario tem um vetor de mais de uma midia favorita 

        //métodos da classe, construtores, destrutor, get e set, imprimir informações em arquivo ou no terminal, funções
        // de inserir e remover dos favoritos do assinante, e métodos de ordenação  
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
        int partition_(int p, int r);
        void quicksort_(int p, int r);
        int conta_podcasts();
};

#endif