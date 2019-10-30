#include "midia.h"

//construtores de generos
Midia::Genero::Genero(){}
Midia::Genero::Genero(string nome, string sigla){
    this->set_nome(nome);
    this->set_sigla(sigla);
}
Midia::Genero::~Genero(){} //destrutor de generos

//sets e gets de generos
void Midia::Genero::set_nome(string nome){
    this->nome = nome;
}
void Midia::Genero::set_sigla(string sigla){
    this->sigla = sigla;
}
string Midia::Genero::get_nome(){
    return this->nome;
}
string Midia::Genero::get_sigla(){
    return this->sigla;
}
//construtores de midia 
Midia::Midia(){}
Midia::Midia(string nome, int codigo, Genero genero){
    this->set_nome(nome);
    this->set_codigo(codigo);
    this -> genero = genero;
    qtdProdutos++;
}
Midia::~Midia(){}//destrutor de midia 

//sets e gets de midia
void Midia::set_nome(string nome){
    this->nome = nome;
}
void Midia::set_codigo(int codigo){
    this->codigo = codigo;
}
void Midia::set_duracao(float duracao){
    this->duracao = duracao;
}
void Midia::set_anoLancamento(int anoLancamento){
    this->anoLancamento = anoLancamento;
}
void Midia::set_genero(Genero genero){
    this->genero = genero;
}
void Midia::set_tipo(string tipo){
    if(tipo.compare("P") == 0) this->tipo = "Podcast";
    if(tipo.compare("M") == 0) this->tipo = "Música";
}
string Midia::get_nome(){
    return this->nome;
}
int Midia::get_codigo(){
    return this->codigo;
}
float Midia::get_duracao(){
    return this->duracao;
}
int Midia::get_anoLancamento(){
    return this->anoLancamento;
}
Midia::Genero Midia::get_genero(){
    return this->genero;
}
string Midia::get_tipo(){
    return this->tipo;
}
int Midia::qtdProdutos = 0;//dando inicio a um atributo do tipo static 

//imprime a quantidade 
void Midia::imprimeQtdProdutos(){
    cout<<"Quantidade de produtos: "<<qtdProdutos<<endl;
}