#include "produtor.h"

Produtor::Produtor(){}
Produtor::Produtor(string nome, int codigo){
    this->set_nome(nome);
    this->set_codigo(codigo);
}
Produtor::~Produtor(){}
void Produtor::set_midias(Midia* midia){
    this->midias.push_back(midia);
}
vector<Midia*> Produtor::get_midias(){
    return this->midias;
}
void Produtor::imprimeProdutosDesenvolvidos(){
    for(int i=0;i<this->midias.size();i++){
        this->midias[i]->imprimeInfoProduto();
    }
}
