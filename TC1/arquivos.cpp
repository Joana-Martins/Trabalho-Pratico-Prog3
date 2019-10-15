#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include "midia.h"

using namespace std;

vector <Midia :: Genero*> lergeneros(string arquivo){
    
    ifstream generos;
    vector <Midia::Genero*> vetor_generos; 
   
    generos.open(arquivo);

    if(!generos.is_open()){
        cerr << "Erro ao abrir o arquivo de generos." << endl;
        exit(1);
    }
    
    // vector<string> generos_vetor;
    string s, sigla, nome;
    int rows = -1;
    getline(generos, s);
    while(generos){
        getline(generos, s, '\n');
        rows++;
    }
    generos.close();

    generos.open(arquivo);

   if(!generos.is_open()){
       cerr << "Erro ao abrir o arquivo de generos." << endl;
        exit(1);
    }

    getline(generos, s);
    for(int i = 0; i < rows; i++){
        getline(generos, sigla, ';');
        getline(generos, nome, '\n');
        Midia :: Genero *aux =  new Midia :: Genero(nome, sigla);
        vetor_generos.push_back(aux);
    }

    return vetor_generos;
}

vector <Midias*> lermidias (string arquivo){
    
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
         }else if ((aux.compare("-m"))==0){
             midias = lermidias(argv[i+1]);
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
