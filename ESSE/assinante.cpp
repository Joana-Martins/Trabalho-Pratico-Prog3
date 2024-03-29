#include"assinante.h"

//construtores 
Assinante::Assinante(){}
Assinante::Assinante(string nome, int codigo){
    this->nome = nome;
    this->codigo = codigo;
}
Assinante::~Assinante(){}//destrutor

//set e get
void Assinante::set_favoritos(Midia* favorito){
    this->favoritos.push_back(favorito);
}
vector<Midia*> Assinante::get_favoritos(){
    return this->favoritos;
}

//imprime quais são as midias dentro do vetor favoritos 
void Assinante::imprimeFavoritos(){
    for(int i=0;i<this->favoritos.size();i++){
        this->favoritos[i]->imprimeInfoProduto();
    }
}

//insere mídias no vetor 
void Assinante::inserirFavorito(Midia* favorito){
    this->favoritos.push_back(favorito);
}

//retira uma mídia do vetor de favoritos
void Assinante::removerFavorito(Midia* favorito){
    int posicao = -1;
    for(int i=0;i<this->get_favoritos().size();i++){
        if(this->get_favoritos()[i] == favorito) posicao = i;
    }
    if(posicao != -1){
        this->favoritos.erase(this->favoritos.begin() + posicao - 1);
    }
}

//métodos de ordenação 
int Assinante::partition(int p, int r){ //ordena midias pelo tipo 
    Midia* aux;
    string x = this->favoritos[r]->get_tipo();
    int i = p-1;
    for(int j=p;j<r;j++){
        if(this->favoritos[j]->get_tipo().compare(x) > 0){
            i++;
            aux = this->favoritos[i];
            this->favoritos[i] = this->favoritos[j];
            this->favoritos[j] = aux;
        }
    }
    aux = this->favoritos[i+1];
    this->favoritos[i+1] = this->favoritos[r];
    this->favoritos[r] = aux;

    return i+1;
}
void Assinante::quicksort(int p, int r){//com ajuda do método acima termina de ordenar
    int q;
    if(p<r){
        q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}
int Assinante::partition_(int p, int r){ //ordena midias pelo codigo
    Midia* aux;
    int x = this->favoritos[r]->get_codigo();
    int i = p-1;
    for(int j=p;j<r;j++){
        if(this->favoritos[j]->get_codigo() <= x){
            i++;
            aux = this->favoritos[i];
            this->favoritos[i] = this->favoritos[j];
            this->favoritos[j] = aux;
        }
    }
    aux = this->favoritos[i+1];
    this->favoritos[i+1] = this->favoritos[r];
    this->favoritos[r] = aux;

    return i+1;
}
void Assinante::quicksort_(int p, int r){//termina de ordenar
    int q;
    if(p<r){
        q=partition_(p,r);
        quicksort_(p,q-1);
        quicksort_(q+1,r);
    }
}

//método para contar quantos podcasts têm
int Assinante::conta_podcasts(){
    int n_podcasts = 0;
    for(Midia* midia:this->favoritos){
        if(midia->get_tipo().compare("Podcast") == 0) n_podcasts++;
    }
    return n_podcasts-1;
}