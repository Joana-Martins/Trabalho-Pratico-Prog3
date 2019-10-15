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

int main(){
    string s;
    int rows=-1;
    ifstream infile_generos;
    infile_generos.open("generos.csv");
    getline(infile_generos,s);
    while(infile_generos){
        getline(infile_generos,s);
        rows += 1;
    }
    infile_generos.close();

    infile_generos.open("generos.csv");
    string nome, sigla;
    vector<Midia::Genero*> generos;
    getline(infile_generos,s);
    for(int i=0;i<rows;i++){
        getline(infile_generos,sigla,';');
        getline(infile_generos,nome);
        Midia::Genero* aux=new Midia::Genero(nome,sigla);
        generos.push_back(aux);
    }
    /*
    rows = -1;
    ifstream infile_usuarios;
    infile_usuarios.open("usuarios.csv");
    getline(infile_usuarios,s);
    while(infile_usuarios){
        getline(infile_usuarios,s);
        rows += 1;
    }
    infile_usuarios.close();

    infile_usuarios.open("usuarios.csv");
    string codigo, tipo;
    getline(infile_usuarios,s);
    vector<Usuario*> usuarios;
    while(infile_usuarios){
        getline(infile_usuarios,codigo,';');
        getline(infile_usuarios,tipo,';');
        getline(infile_usuarios,nome);
        Usuario* aux = new Usuario(nome,stoi(codigo));
        usuarios.push_back(aux);
    }
    */

    PlataformaDigital* pd = new PlataformaDigital("nome plataforma");
    pd->generos = generos;
    pd->imprimeProdutos("Rock");
    for(int i=0;i<generos.size();i++)delete generos[i];

    /*
    Musica* musica = new Musica();
    musica->set_nome("Musica 1");
    musica->set_duracao(300);
    musica->set_anoLancamento(2018);
    Podcast* podcast = new Podcast();
    podcast->set_nome("Podcast 1");
    podcast->set_qtdTemporadas(3);
    ofstream outfile;
    outfile.open("saida.txt");
    podcast->imprimeNoArquivo(outfile);
    outfile.close();
    delete musica;
    delete podcast;*/
    return 0;
}