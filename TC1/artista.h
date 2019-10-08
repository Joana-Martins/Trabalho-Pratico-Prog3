#ifndef ARTISTA_H_
#define ARTISTA_H_

#include"produtor.h"

class Artista: public Produtor{
    public:
        Artista();
        Artista(string nome, int codigo);
        ~Artista();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif