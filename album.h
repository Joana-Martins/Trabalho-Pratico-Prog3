#ifndef ALBUM_H_
#define ALBUM_H_

#include<iostream>
#include<vector>
#include"musica.h"

using namespace std;

class Album{ //começo da classe album 
    private:
        string nome;
        int duracao;
        int anoLancamento;
        int qtdMusicas;
        //atributos de album 
    public:
        vector<Musica*> musicas; //um álbum pode possuir diversas músicas 
        Album();
        Album(string nome, int duracao, int ano, int qtd); //contrutor
        ~Album(); // destrutor 

        // set e gets dos atributos da classe
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