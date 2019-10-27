#ifndef ALBUM_H_
#define ALBUM_H_

#include<iostream>
#include<vector>
#include"musica.h"

using namespace std;

class Album{
    private:
        string nome;
        int duracao;
        int anoLancamento;
        int qtdMusicas;
    public:
        vector<Musica*> musicas;
        Album();
        Album(string nome, int duracao, int ano, int qtd);
        ~Album();
        void set_nome(string nome);
        void set_duracao(int duracao);
        void set_anoLancamento(int anoLancamento);
        void set_qtdMusicas(int qtdMusicas);
        void set_musicas(Musica* musica);
        string get_nome();
        int get_duracao();
        int get_anoLancamento();
        int get_qtdMusicas();
        vector<Musica*> get_musicas();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif