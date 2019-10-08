#include"assinante.h"

Assinante::Assinante(){}
Assinante::Assinante(string nome, int codigo){
    this->nome = nome;
    this->codigo = codigo;
}
Assinante::~Assinante(){}
void Assinante::set_favoritos(Midia* favorito){
    this->favoritos.push_back(favorito);
}
vector<Midia*> Assinante::get_favoritos(){
    return this->favoritos;
}
void Assinante::imprimeFavoritos(){
    for(int i=0;i<this->favoritos.size();i++){
        this->favoritos[i]->imprimeInfoProduto();
    }
}
void Assinante::inserirFavorito(Midia* favorito){
    this->favoritos.push_back(favorito);
}
void Assinante::removerFavorito(Midia* favorito){
    int posicao = -1;
    for(int i=0;i<this->get_favoritos().size();i++){
        if(this->get_favoritos()[i] == favorito) posicao = i;
    }
    if(posicao != -1){
        this->favoritos.erase(this->favoritos.begin() + posicao - 1);
    }
}