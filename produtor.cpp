#include "produtor.h"

//construtores 
Produtor::Produtor(){}
Produtor::Produtor(string nome, int codigo){
    this->set_nome(nome);
    this->set_codigo(codigo);
}
Produtor::~Produtor(){} //destrutor 

//set e get de midias 
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

//algoritmos de ordenação 

int Produtor::partition(int p, int r){ //ordena as midias pelo nome 
    Midia* aux;
    string x = this->midias[r]->get_nome();
    int i = p-1;
    for(int j=p;j<r;j++){
        if(this->midias[j]->get_nome().compare(x) <= 0){ 
            i++;
            aux = this->midias[i];
            this->midias[i] = this->midias[j];
            this->midias[j] = aux;
        }
    }
    aux = this->midias[i+1];
    this->midias[i+1] = this->midias[r];
    this->midias[r] = aux;
    return i+1;
}

void Produtor::quicksort(int p, int r){ //junto com a função acima, ordena as mídias de maneira recursiva 
    int q;
    if(p<r){
        q=this->partition(p,r);
        this->quicksort(p,q-1);
        this->quicksort(q+1,r);
    }
}