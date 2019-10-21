#include"plataformadigital.h"

PlataformaDigital::PlataformaDigital(){}
PlataformaDigital::PlataformaDigital(string nome){
    this->set_nome(nome);
}
PlataformaDigital::~PlataformaDigital(){
    delete[] this->generos[0];
}
void PlataformaDigital::set_nome(string nome){
    this->nome = nome;
}        
string PlataformaDigital::get_nome(){
    return this->nome;
}
void PlataformaDigital::imprimeProdutos(string genero){
    for(int i=0;i<this->generos.size();i++){
        if(this->generos[i]->get_nome().compare(genero) == 0){
            cout<<"Nome: "<<this->generos[i]->get_nome()<<endl;
            cout<<"Sigla: "<<this->generos[i]->get_sigla()<<endl;
            cout<<endl;
        }
    }
}
/* void imprimeAssinantes();
void inserirAssinante(Assinante* assinante);
void removerAssinante(Assinante* assinante);
void inserirProduto(Midia* novoProduto, vector<Produtor*> produtores);
void imprimeNoArquivo(ofstream &outfile);
void exportarBiblioteca();
*/
//void gerarRelatorios();

void PlataformaDigital::carregaArquivoUsuarios(ifstream &usuarios){
    string s, codigo, tipo, nome;
    getline(usuarios, s, '\n');

    while(getline(usuarios,s)){
        istringstream linha(s);
        getline(linha, codigo, ';');
        getline(linha, tipo, ';');
        getline(linha, nome, ';');
        if(tipo=="U") this->assinantes.push_back(new Assinante(nome, stoi(codigo)));
        else this->produtores.push_back(new Produtor(nome, stoi(codigo)));
    }
}

void PlataformaDigital::carregaArquivoGeneros(ifstream &generos){
    string s, sigla, nome;
    getline(generos, s, '\n');

    while(getline(generos,s)){
        istringstream linha(s);
        getline(linha, sigla, ';');
        getline(linha, nome, ';');
        this->generos.push_back(new Midia::Genero(nome, sigla));
    }
}
void PlataformaDigital::carregaArquivoMidias(ifstream &midias){
    string s, codigo, nome, tipo, produtores, duracao, genero, temporada, album, codigoAlbum, anoPublicacao;
    getline(midias, s, '\n');
    int i=0;

    while(getline(midias,s)){
        istringstream linha(s);
        getline(linha, codigo, ';');
        getline(linha, nome, ';');
        getline(linha, tipo, ';');
        getline(linha, produtores, ';');
        getline(linha, duracao, ';');
        getline(linha, genero, ';');
        getline(linha, temporada, ';');
        getline(linha, album, ';');
        getline(linha, codigoAlbum, ';');
        getline(linha, anoPublicacao, ';');
        this->midias.push_back(new Midia(nome, stoi(codigo), * new Midia::Genero("", genero)));
        for(int j=0;j<duracao.size();j++){
            if(duracao[j]==',') duracao[j] = '.';
        }
        this->midias[i]->set_duracao(stof(duracao));
        this->midias[i]->set_anoLancamento(stoi(anoPublicacao));
        i++;
    }
}
void PlataformaDigital::carregaArquivoFavoritos(ifstream &favoritos){
    string s, codigo, musica;
    getline(favoritos, s, '\n');

    while(getline(favoritos,s)){
        istringstream linha(s);
        getline(linha, codigo, ';');
        while(getline(linha, musica, ',')){
            for(int i=0;i<this->midias.size();i++){
                if(!musica.empty()){
                    if(this->midias[i]->get_codigo()==stoi(musica)) this->assinantes[stoi(codigo)-1]->favoritos.push_back(this->midias[stoi(musica)-1]);
                }
            }
        }
    }
}