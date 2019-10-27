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
void PlataformaDigital::gerarRelatorios(){
    ofstream u;
    u.open("backup.txt");
    for(Assinante* assinante:this->assinantes){
        u<<assinante->get_codigo()<<";";
        u<<assinante->get_nome();
    }
    for(Produtor* produtor:this->produtores){
        u<<produtor->get_codigo()<<";";
        u<<produtor->get_nome();
    }
    u<<"Midias:"<<endl;
    for(Midia* midia:this->midias){
        u<<midia->get_nome()<<";";
        u<<midia->get_tipo()<<";";
        for(Produtor* produtor:this->produtores){
            for(Midia* aux:produtor->midias){
                if(aux->get_codigo()==midia->get_codigo()){
                    u<<produtor->get_nome().erase(produtor->get_nome().size()-1)<<";";
                }
            }
        }
        u<<midia->get_duracao()<<";";
        u<<midia->get_genero().get_nome().erase(midia->get_genero().get_nome().size() - 1)<<";";
        u<<midia->get_anoLancamento()<<endl;
    }
    this->quicksort(0, this->produtores.size()-1);
    ofstream mpp;
    mpp.open("produtores.csv");
    for(Produtor* produtor : this->produtores){
        mpp<<produtor->get_nome().erase(produtor -> get_nome().size() - 1)<<";";
        for(Midia* midia : produtor->midias){
            mpp<<midia->get_nome()<<",";
        }
        mpp<<endl;
    }

    ofstream f;
    f.open("favorito.csv");
    for(Assinante* assinante:this->assinantes){
        if(assinante->favoritos.empty()) f<<assinante->get_codigo()<<";"<<endl;
        for(Midia* midia:assinante->favoritos){
            f<<assinante->get_codigo()<<";";
            f<<midia->get_tipo()<<";";
            f<<midia->get_codigo()<<";";
            f<<midia->get_genero().get_nome().erase(midia->get_genero().get_nome().size() - 1)<<";";
            f<<midia->get_duracao();
            f<<endl;
        }
    }
}

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

        string p1;
        istringstream s1(genero);
        getline(s1,p1,',');
        for(Midia::Genero* aux:this->generos){
            if(aux->get_sigla().compare(p1)==0){
                this->midias.push_back(new Midia(nome, stoi(codigo), * new Midia::Genero(aux->get_nome(), p1)));
            }
        }
        
        for(int j=0;j<duracao.size();j++){
            if(duracao[j]==',') duracao[j] = '.';
        }
        this->midias[i]->set_tipo(tipo);
        this->midias[i]->set_duracao(stof(duracao));
        this->midias[i]->set_anoLancamento(stoi(anoPublicacao));
        
        string p2;
        istringstream s2(produtores);
        while(getline(s2,p2,',')){
            for(int i=0;i<this->produtores.size();i++){
                if(!p2.empty()){
                    if(this->produtores[i]->get_codigo() == stoi(p2)) this->produtores[i]->midias.push_back(this->midias[stoi(codigo)-1]);
                }
            }
        }

        i++;
    }
    Album* aux = new Album(codigoAlbum, stof(duracao), stoi(anoPublicacao), 0);
    this->albuns.push_back(aux);
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

    for(Assinante* assinante:this->assinantes){
        if(!assinante->get_favoritos().empty()) assinante->quicksort(0,assinante->favoritos.size()-1);
        assinante->quicksort_(0,assinante->conta_podcasts());
        assinante->quicksort_(assinante->conta_podcasts()+1,assinante->favoritos.size()-1);
        }
}
int PlataformaDigital::partition(int p, int r){
    Produtor* aux;
    string x = this->produtores[r]->get_nome();
    int i = p-1;
    for(int j=p;j<r;j++){
        if(this->produtores[j]->get_nome().compare(x) <= 0){
            i++;
            aux = this->produtores[i];
            this->produtores[i] = this->produtores[j];
            this->produtores[j] = aux;
        }
    }
    aux = this->produtores[i+1];
    this->produtores[i+1] = this->produtores[r];
    this->produtores[r] = aux;
    return i+1;
}
void PlataformaDigital::quicksort(int p, int r){
    int q;
    if(p<r){
        q=this->partition(p,r);
        this->quicksort(p,q-1);
        this->quicksort(q+1,r);
    }
}