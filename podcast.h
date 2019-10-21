#ifndef PODCAST_H_
#define PODCAST_H_

#include<iostream>
#include<fstream>
#include"midia.h"

using namespace std;

class Podcast: public Midia{
  private:
    int qtdTemporadas;
  public:
    Podcast();
    Podcast(string nome, Genero gen, int qtdTemp);
    ~Podcast();
    void set_qtdTemporadas(int qtdTemp);
    int get_qtdTemporadas();
    void imprimeInfoProduto();
    void imprimeNoArquivo(ofstream &outfile);
};

#endif
