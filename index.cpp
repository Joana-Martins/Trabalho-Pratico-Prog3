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
    if(argc != 9){
        cerr<<"Numero de parametros insuficientes."<<endl;
        exit(1);
    }
    ifstream generos, midias, usuarios, favoritos;
    char parametros[4];
    for(int i=0;i<4;i++){
        parametros[i] = argv[2*i+1][1];
        switch(parametros[i]){
            case 'g':{
                generos.open(argv[2*i+2],ios::in);
                if(!generos.is_open()){
                    cerr<<"Erro ao abrir o arquivo de generos."<<endl;
                    return 1;
                }
                break;   
            }
            case 'u':{
                usuarios.open(argv[2*i+2],ios::in);
                if(!usuarios.is_open()){
                    cerr<<"Erro ao abrir o arquivo de usuarios."<<endl;
                    return 1;
                }
                break;
            }
            case 'm':{
                midias.open(argv[2*i+2],ios::in);
                if(!midias.is_open()){
                    cerr<<"Erro ao abrir o arquivo de midias."<<endl;
                    return 1;
                }
                break;
            }
            case 'f':{
                favoritos.open(argv[2*i+2],ios::in);
                if(!favoritos.is_open()){
                    cerr<<"Erro ao abrir o arquivo de favoritos."<<endl;
                    return 1;
                }
                break;
            }
            default: cout<<"Erro na abertura do arquivo."<<endl; break;
        }
    }

    PlataformaDigital* pd = new PlataformaDigital("nome plataforma");
    pd->carregaArquivoGeneros(generos);
    pd->carregaArquivoUsuarios(usuarios);
    pd->carregaArquivoMidias(midias);
    pd->carregaArquivoFavoritos(favoritos);
    pd->gerarRelatorios();
    for(int i=0;i<pd->assinantes.size();i++) delete pd->assinantes[i];
    for(int i=0;i<pd->midias.size();i++) delete pd->midias[i];
    for(int i=0;i<pd->produtores.size();i++) delete pd->produtores[i];
    for(int i=0;i<pd->generos.size();i++) delete pd->generos[i];
    return 0;
}