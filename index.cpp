#include"produtor.h"
#include"assinante.h"
#include"musica.h"
#include"plataformadigital.h"
#include"midia.h"
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<string> 
#include"podcast.h"
#include"usuario.h"
#include"album.h"

using namespace std;

int main(int argc, char* argv[]){

    

    ifstream midias;
    ifstream generos;
    ifstream usuarios;
    ifstream favoritos;

    midias.open("midias_corrigidas.csv", ios::in);

    if(!midias.is_open()){
        cerr << "Erro ao abrir o arquivo de midias." << endl;
        return 1;
    }
    
    generos.open("generos.csv", ios::in);

    if(!generos.is_open()){
       cerr << "Erro ao abrir o arquivo de generos." << endl;
        return 1;
    }

    usuarios.open("usuarios.csv", ios::in);
    
    if(!usuarios.is_open()){
        cerr << "Erro ao abrir o arquivo de usuarios." << endl;
        return 1;
    }

    favoritos.open("favoritos.csv", ios::in);

    if(!favoritos.is_open()){
        cerr << "Erro ao abrir o arquivo de favoritos." << endl;
        return 1;
    }

    PlataformaDigital* pd = new PlataformaDigital("nome plataforma");
    pd->carregaArquivoGeneros(generos);
    pd->carregaArquivoUsuarios(usuarios);
    pd->carregaArquivoMidias(midias);
    pd->carregaArquivoFavoritos(favoritos);
    for(int i=0;i<pd->assinantes.size();i++) delete pd->assinantes[i];
    for(int i=0;i<pd->midias.size();i++) delete pd->midias[i];
    for(int i=0;i<pd->produtores.size();i++) delete pd->produtores[i];
    for(int i=0;i<pd->generos.size();i++) delete pd->generos[i];
    return 0;
}