#include"musica.h"

Musica::Musica(){}
Musica::Musica(string nome, Genero gen, int duracao, int ano): Midia(nome,codigo,genero){
    this->set_nome(nome);
    this->set_genero(gen);
    this->set_duracao(duracao);
    this->set_anoLancamento(ano);
}
Musica::~Musica(){}
void Musica::imprimeInfoProduto(){
    cout<<"Nome: "<<this->get_nome()<<endl;
    //cout<<"Codigo: "<<this->get_codigo()<<endl;
    cout<<"Duracao: "<<this->get_duracao()<<endl;
    cout<<"Ano de Lancamento: "<<this->get_anoLancamento()<<endl;
    //cout<<"Genero: "<<this->get_genero().get_nome()<<endl;
    //cout<<"Sigla: "<<this->get_genero().get_sigla()<<endl;
}
void Musica::imprimeNoArquivo(ofstream &outfile){
    outfile<<"Nome: "<<this->get_nome()<<endl;
    //outfile<<"Codigo: "<<this->get_codigo()<<endl;
    outfile<<"Duracao: "<<this->get_duracao()<<endl;
    outfile<<"Ano de Lancamento: "<<this->get_anoLancamento()<<endl;
    //outfile<<"Genero: "<<this->get_genero().get_nome()<<endl;
    //outfile<<"Sigla: "<<this->get_genero().get_sigla()<<endl;
}
