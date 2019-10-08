#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

int main(){

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


    vector<string> generos_vetor;
    string s, sigla, nome;
    int rows = -1;
    getline(generos, s);
    while(generos){
        getline(generos, s, '\n');
        rows++;
    }
    generos.close();

    generos.open("generos.csv", ios::in);

   if(!generos.is_open()){
       cerr << "Erro ao abrir o arquivo de generos." << endl;
        return 1;
    }

    getline(generos, s);
    for(int i = 0; i < rows; i++){
        getline(generos, sigla, ';');
        getline(generos, nome, '\n');
        cout << sigla << endl;
        cout << nome << endl;
    }
    return 0;
    }