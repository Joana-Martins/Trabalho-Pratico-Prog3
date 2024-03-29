#include"plataformadigital.h"

#include<fstream>
#include<iostream>
#include<cstdlib>
#include<string> 


using namespace std;

int main(int argc, char* argv[]){
    if(argc != 9){
        cerr<<"Erro de I/O"<<endl;
        exit(1);
    }
    ifstream generos, midias, usuarios, favoritos;
    char parametros[4];
    for(int i=0;i<4;i++){
        parametros[i] = argv[2*i+1][1];
        switch(parametros[i]){ //abre os arquivos corretamente, vendo qual arquivo é qual
            case 'g': generos.open(argv[2*i+2],ios::in); break;   
            case 'u': usuarios.open(argv[2*i+2],ios::in); break;
            case 'm': midias.open(argv[2*i+2],ios::in); break;
            case 'f': favoritos.open(argv[2*i+2],ios::in); break;
            default: cout<<"Erro de I/O"<<endl; break;
        }
    }
    if(!generos.is_open() || !usuarios.is_open() || !midias.is_open() || !favoritos.is_open()){
        cerr<<"Erro de I/O"<<endl;
        exit(1);
    }

    PlataformaDigital* pd = new PlataformaDigital("Spotify++");
    //lê todos os arquivos de entrada
    pd->carregaArquivoGeneros(generos); //carrega generos
    pd->carregaArquivoUsuarios(usuarios);// carrega usuarios
    pd->carregaArquivoMidias(midias); //carrega midias
    pd->carregaArquivoFavoritos(favoritos); //carrega favoritos
    pd->gerarRelatorios(); //gera as saídas
    delete pd;
    return 0;
}