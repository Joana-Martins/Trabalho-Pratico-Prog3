#ifndef MUSICA_H_
#define MUSICA_H_

#include<fstream>
#include"midia.h"

using namespace std;

class Musica: public Midia{ // música tem atributos herdados de Midia
    public:
        //métodos da classe, construtor, destrutor, e métodos de impressão de informações 
        Musica(); 
        Musica(string nome, Genero gen, float duracao, int ano);
        ~Musica();
        void imprimeInfoProduto();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif
