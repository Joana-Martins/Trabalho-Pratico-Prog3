#include"artista.h"

Artista::Artista(string nome, int codigo):Produtor(nome,codigo){  //construtor de álbuns
    this->set_nome(nome);
    this->set_codigo(codigo);
}
Artista::~Artista(){} // destrutor 
void Artista::imprimeNoArquivo(ofstream &outfile){//pega as informações das mídias do artista, colocando-os no arquivo de saída
    for(int i=0;i<this->get_midias().size();i++){
        outfile<<"Nome: "<<this->get_midias()[i]->get_nome()<<endl;
        outfile<<"Codigo: "<<this->get_midias()[i]->get_codigo()<<endl;
        outfile<<"Duracao: "<<this->get_midias()[i]->get_duracao()<<endl;
        outfile<<"Ano Lancamento: "<<this->get_midias()[i]->get_anoLancamento()<<endl;
        outfile<<"Genero: "<<this->get_midias()[i]->get_genero().get_nome()<<endl;
        outfile<<"Sigla: "<<this->get_midias()[i]->get_genero().get_sigla()<<endl;
    }
}

//sets e gets
void Artista::set_albuns(Album* album){
    this->albuns.push_back(album);
}
vector<Album*> Artista::get_albuns(){
    return this->albuns;
}