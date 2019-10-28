#ifndef PLATAFORMADIGITAL_H_
#define PLATAFORMADIGITAL_H_

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<istream>
#include<sstream>
#include<string>
#include<typeinfo>
#include <bits/stdc++.h> 
#include"midia.h"
#include"podcast.h"
#include"album.h"
#include"assinante.h"
#include"produtor.h"

using namespace std;

class Midia;
class Assinante;
class PlataformaDigital{
    private:
        string nome;
    public:
        vector<Assinante*> assinantes;
        vector<Midia::Genero*> generos;
        vector<Midia*> midias;
        vector<Produtor*> produtores;
        vector<Album*> albuns;
        void set_nome(string nome);
        string get_nome();
        PlataformaDigital();
        PlataformaDigital(string nome);
        ~PlataformaDigital();
        void imprimeProdutos(string genero);
        void imprimeAssinantes();
        void inserirAssinante(Assinante* assinante);
        void removerAssinante(Assinante* assinante);
        void inserirProduto(Midia* novoProduto, vector<Produtor*> produtores);
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivoUsuarios(ifstream &infile);
        void carregaArquivoGeneros(ifstream &infile);
        void carregaArquivoMidias(ifstream &infile);
        void exportarBiblioteca();
        void gerarRelatorios();
        void carregaArquivoFavoritos(ifstream &infile);
        int partition(int p, int r);
        void quicksort(int p, int r);
};

#endif