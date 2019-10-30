#ifndef PODCAST_H_
#define PODCAST_H_

#include<iostream>
#include<fstream>
#include"midia.h"

using namespace std;

class Podcast: public Midia{ //o podcast herda atributos de mídia 
  private:
    //temporadas é um atributo apenas de podcasts
    int qtdTemporadas;
  public:
    //métodos da classe, gets, sets e imprimir informações(terminal e arquivo).
    Podcast();
    Podcast(string nome, Genero gen, int qtdTemp);
    ~Podcast();
    void set_qtdTemporadas(int qtdTemp);
    int get_qtdTemporadas();
    void imprimeInfoProduto();
    void imprimeNoArquivo(ofstream &outfile);
};

#endif
