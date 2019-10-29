#ifndef ARTISTA_H_
#define ARTISTA_H_

#include"produtor.h"
#include"album.h"

class Artista: public Produtor{
    public:
        vector<Album*> albuns;
        Artista(string nome, int codigo);
        ~Artista();
        void set_albuns(Album* album);
        vector<Album*> get_albuns();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif