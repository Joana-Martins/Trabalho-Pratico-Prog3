#ifndef ARTISTA_H_
#define ARTISTA_H_

#include"produtor.h"
#include"album.h"

class Artista: public Produtor{ //definir artista, sendo uma classe hererditária de Produtor
    public:
        vector<Album*> albuns; // cada Artista pode ter mais de um álbum 
        Artista(string nome, int codigo);//construtor
        ~Artista();  //destrutor  
        
        //sets e gets
        void set_albuns(Album* album); 
        vector<Album*> get_albuns();
        //manipulação do arquivo de saida
        void imprimeNoArquivo(ofstream &outfile);
};

#endif