#include"album.h"

//implementação das função do .h, sets, gets, contrutor e destrutor.
Album::Album(){}
Album::Album(string nome, int duracao, int ano, int qtd){
    this->set_nome(nome);
    this->set_duracao(duracao);
    this->set_anoLancamento(ano);
    this->set_qtdMusicas(qtd);
}
Album::~Album(){}
void Album::set_nome(string nome){
    this->nome = nome;
}
void Album::set_duracao(int duracao){
    this->duracao = duracao;
}
void Album::set_anoLancamento(int anoLancamento){
    this->anoLancamento = anoLancamento;
}
void Album::set_qtdMusicas(int qtdMusicas){
    this->qtdMusicas = qtdMusicas;
}
void Album::set_musicas(Musica* musica){
    this->musicas.push_back(musica);
}
string Album::get_nome(){
    return this->nome;
}
int Album::get_duracao(){
    return this->duracao;
}
int Album::get_anoLancamento(){
    return this->anoLancamento;
}
int Album::get_qtdMusicas(){
    return this->qtdMusicas;
}
vector<Musica*> Album::get_musicas(){
    return this->musicas;
}
void Album::imprimeNoArquivo(ofstream &outfile){
    cout<<"calma"<<endl;
}