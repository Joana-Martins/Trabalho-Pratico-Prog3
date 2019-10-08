#ifndef PODCASTER_H_
#define PODCASTER_H_

#include<iostream>
#include<fstream>
#include<vector>
#include"produtor.h"
#include"podcast.h"

class Podcaster: public Produtor{
    public:
        vector<Podcast*> podcasts;
        Podcaster();
        Podcaster(string nome, int codigo);
        ~Podcaster();
        void set_podcasts(Podcast* podcast);
        vector<Podcast*> get_podcasts();
        void imprimeNoArquivo(ofstream &outfile);
};

#endif
