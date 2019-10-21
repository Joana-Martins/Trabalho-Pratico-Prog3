#include"podcast.h"

Podcast::Podcast(){}
Podcast::Podcast(string nome, Genero gen, int qtdTemp): Midia(nome, codigo, genero){
  this->set_nome(nome);
  this->set_genero(gen);
  this->set_qtdTemporadas(qtdTemp);
}
Podcast::~Podcast(){}
void Podcast::set_qtdTemporadas(int qtdTemp){
  this->qtdTemporadas = qtdTemp;
}
int Podcast::get_qtdTemporadas(){
  return this->qtdTemporadas;
}
void Podcast::imprimeInfoProduto(){
  cout<<"Nome: "<<this->get_nome()<<endl;
  //cout<<"Codigo: "<<this->get_codigo()<<endl;
  //cout<<"Duracao: "<<this->get_duracao()<<endl;
  //cout<<"Ano de lancamento: "<<this->get_anoLancamento()<<endl;
  //cout<<"Genero: "<<this->get_genero().get_nome()<<endl;
  //cout<<"Sigla: "<<this->get_genero().get_sigla()<<endl;
  cout<<"Quantidade de temporadas: "<<this->get_qtdTemporadas()<<endl;
}
void Podcast::imprimeNoArquivo(ofstream &outfile){
  outfile<<"Nome: "<<this->get_nome()<<endl;
  //outfile<<"Codigo: "<<this->get_codigo()<<endl;
  //outfile<<"Duracao: "<<this->get_duracao()<<endl;
  //outfile<<"Ano de lancamento: "<<this->get_anoLancamento()<<endl;
  //outfile<<"Genero: "<<this->get_genero().get_nome()<<endl;
  //outfile<<"Sigla: "<<this->get_genero().get_sigla()<<endl;
  outfile<<"Quantidade de temporadas: "<<this->get_qtdTemporadas()<<endl;
}
