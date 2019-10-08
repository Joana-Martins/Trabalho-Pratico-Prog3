#include"plataformadigital.h"

PlataformaDigital::PlataformaDigital(){}
PlataformaDigital::PlataformaDigital(string nome){
    this->set_nome(nome);
}
void PlataformaDigital::set_nome(string nome){
    this->nome = nome;
}        
string PlataformaDigital::get_nome(){
    return this->nome;
}
void PlataformaDigital::imprimeProdutos(string genero){
    for(int i=0;i<this->generos.size();i++){
        cout<<"Nome: "<<this->generos[i]->get_nome()<<endl;
        cout<<"Sigla: "<<this->generos[i]->get_sigla()<<endl;
        cout<<endl;
    }
}
/* void imprimeAssinantes();
void inserirAssinante(Assinante* assinante);
void removerAssinante(Assinante* assinante);
void inserirProduto(Midia* novoProduto, vector<Produtor*> produtores);
void imprimeNoArquivo(ofstream &outfile);
void carregaArquivoUsuarios(ifstream &infile);
void carregaArquivoGeneros(ifstream &infile);
void carregaArquivoMidias(ifstream &infile);
void exportarBiblioteca();
void gerarRelatorios();
void carregaArquivoFavoritos(ifstream &infile);
*/