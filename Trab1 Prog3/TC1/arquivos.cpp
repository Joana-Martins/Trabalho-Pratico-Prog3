#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include "midia.h"

using namespace std;

int row_cont(string arquivo){
    ifstream arq;
    string aux;
    int rows = -1;
    arq.open(arquivo);

    if(!arq.is_open()){
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1);
    }
   
    getline(arq, aux);
    while(arq){
        getline(arq, aux, '\n');
        rows++;
    }
    arq.close();

    return rows;
}

vector <Midia :: Genero*> lergeneros(string arquivo){
    
    ifstream generos;
    string aux, sigla, nome;
    vector <Midia::Genero*> vetor_generos; 
   
   int rows = row_cont(arquivo);

    getline(generos, aux);
    for(int i = 0; i < rows; i++){
        getline(generos, sigla, ';');
        getline(generos, nome, '\n');
        Midia :: Genero *aux =  new Midia :: Genero(nome, sigla);
        vetor_generos.push_back(aux);
    }

    return vetor_generos;
}

vector <Midia *> lermidias (string arquivo){

    ifstream midia;
    string aux;
    vector<Midia *> vetor_midias;

     midia.open(arquivo);

    int rows = row_cont(arquivo);

    midias.open(arquivo);

    getline(generos, s);
    for(int i = 0; i < rows; i++){
        getline(generos, sigla, ';');
        getline(generos, nome, '\n');
        Midia :: Genero *aux =  new Midia :: Genero(nome, sigla);
        vetor_generos.push_back(aux);
    }
    return vetor_midias;
}

int main (int argc, char *argv[]){
    int i, j; 
    vector <Midia :: Genero*> generos; 
    vector <Midia*> midias; 
    if(argc != 9 ){
        cerr << "Entrada invalida, tente executar novamente." << endl;
        return 1;
    }
    
    for(int i = 0; i < 9; i++){
        string aux = argv[i];
        if((aux.compare("-g")) == 0){
            generos = lergeneros(argv[i+1]);
         }else if ((aux.compare("-m")) == 0){
             midias = lermidias(argv[i+1]);
            }else if((aux.compare("-u")) == 0){

            }else if((aux.compare("-f")) == 0){
                
            }
    }

    for(j = 0; j < generos.size(); j++){
        cout << generos[j]->get_nome() << endl;
        cout << generos[j]->get_sigla() << endl;
    }

    for( j = 0; j < generos.size(); j++){
        delete generos[j];
    }


    return 0;
}
