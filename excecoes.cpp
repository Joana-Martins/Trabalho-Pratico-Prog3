#include"excecoes.h"

void checa_se_numero(string palavra){ //checa se uma string de entrda é um número inteiro
    for(int i=0;i<palavra.size();i++){
        if(!isdigit(palavra[i])) throw "Erro de formatação";
    }
}
void checa_se_float(string palavra){ //checa se uma string de entrada é um float 
    for(int i=0;i<palavra.size();i++){
        if(!isdigit(palavra[i]) && palavra[i]!='.') throw "Erro de formatação";
    }
}
void checa_se_existe(string sigla, vector<Midia::Genero*> generos){ //checa se a sigla de generos existe dentro da Plataforma
    int i=0;
    for(Midia::Genero* g:generos){
        if(sigla.compare(g->get_sigla()) != 0) i++;
    }
    if(i==generos.size()) throw "Inconsistências na entrada";
}
void checa_se_existe(string tipo){ //testa se o tipo da midia é P ou M(unicos possiveis)
    if(tipo!="P" && tipo!="M") throw "Inconsistências na entrada";
}
void checa_se_existe(int produtor, vector<Produtor*> produtores){ //checa se o produtor, pelo código, existe na Plataforma
    int i=0;
    for(Produtor* p:produtores){
        if(produtor!=p->get_codigo()) i++;
    }
    if(i==produtores.size()) throw "Inconsistências na entrada";
}
void checa_se_existe(int codigo, vector<Assinante*> assinantes){ //checa se o assinante existe, através do código
    int i=0;
    for(Assinante* a:assinantes){
        if(codigo!=a->get_codigo()) i++;
    }
    if(i==assinantes.size()){
        cout<<codigo<<endl;
        throw "Inconsistências na entrada";
    }
}
void checa_se_existe(int musica, vector<Midia*> midias){ //checa se a música, pelo seu código, existe
    int i=0;
    for(Midia* m:midias){
        if(musica!=m->get_codigo()) i++;
    }
    if(i==midias.size()){
        throw "Inconsistências na entrada";
    }
}
void checa_se_existe_usuario(string tipo){ //checa se o tipo de usuario existem, podenod ser apenas P, U, A
    if(tipo!="P" && tipo!="U" && tipo!="A") throw "Inconsistências na entrada";
}