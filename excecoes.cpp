#include"excecoes.h"

void checa_se_numero(string palavra){
    for(int i=0;i<palavra.size();i++){
        if(!isdigit(palavra[i])) throw "Erro de formatação";
    }
}
void checa_se_float(string palavra){
    for(int i=0;i<palavra.size();i++){
        if(palavra[i]==',') palavra[i]='.' ;
        else if(!isdigit(palavra[i]) && palavra[i]!='.'){
            throw "Erro de formatação";
        }
    }
}