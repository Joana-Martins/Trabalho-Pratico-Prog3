#include "podcaster.h"

Podcaster::Podcaster(string nome, int codigo):Produtor(nome,codigo){ //construtor
    this->set_nome(nome);
    this->set_codigo(codigo);
}
Podcaster::~Podcaster(){}//destrutor

//sets e gets
void Podcaster::set_podcasts(Podcast* podcast){
    this->podcasts.push_back(podcast);
}
vector<Podcast*> Podcaster::get_podcasts(){
    return this->podcasts;
}

//imprimir no arquivo de saída as informações dos podcast dos podcaster 
void Podcaster::imprimeNoArquivo(ofstream &outfile){
    for(int i=0;i<this->get_midias().size();i++){
        outfile<<"Nome: "<<this->get_midias()[i]->get_nome()<<endl;
        outfile<<"Codigo: "<<this->get_midias()[i]->get_codigo()<<endl;
        outfile<<"Duracao: "<<this->get_midias()[i]->get_duracao()<<endl;
        outfile<<"Ano Lancamento: "<<this->get_midias()[i]->get_anoLancamento()<<endl;
        outfile<<"Genero: "<<this->get_midias()[i]->get_genero().get_nome()<<endl;
        outfile<<"Sigla: "<<this->get_midias()[i]->get_genero().get_sigla()<<endl;
        outfile<<"Quantidade de temporadas: "<<this->get_podcasts()[i]->get_qtdTemporadas()<<endl;
    }
}