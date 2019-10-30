#ifndef PODCASTER_H_
#define PODCASTER_H_

#include<iostream>
#include<fstream>
#include<vector>
#include"produtor.h"
#include"podcast.h"

class Podcaster: public Produtor{// Declaração da classe Podcaster que é herdada de Produtor
    public:
        vector<Podcast*> podcasts; //um podcaster tem vários podcasts que ele/ela fizeram
        Podcaster(string nome, int codigo); //construtor
        ~Podcaster();//destrutor 
        //sets e gets
        void set_podcasts(Podcast* podcast);
        vector<Podcast*> get_podcasts();
        //manipulação de arquivos
        void imprimeNoArquivo(ofstream &outfile);
};

#endif
