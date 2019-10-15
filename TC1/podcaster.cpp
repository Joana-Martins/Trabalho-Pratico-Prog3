#include "podcaster.h"

Podcaster::Podcaster(string nome, int codigo){
    this->set_nome(nome);
    this->set_codigo(codigo);
}
Podcaster::~Podcaster(){}
void Podcaster::set_podcasts(Podcast* podcast){
    this->podcasts.push_back(podcast);
}
vector<Podcast*> Podcaster::get_podcasts(){
    return this->podcasts;
}
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