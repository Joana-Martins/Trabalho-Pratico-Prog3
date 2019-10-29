#include"plataformadigital.h"

PlataformaDigital::PlataformaDigital(){}
PlataformaDigital::PlataformaDigital(string nome){
    this->set_nome(nome);
}
PlataformaDigital::~PlataformaDigital(){
    for(Midia::Genero* genero:this->generos) delete genero;
    for(Assinante* assinante:this->assinantes) delete assinante;
    for(Produtor* produtor:this->produtores) delete produtor;
    for(Midia* midia:this->midias)
    {   
        Podcast* pod = (Podcast*) midia;
        delete pod;
    }
    for(Album* album:this->albuns) delete album;
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
    u<<"Usuários:"<<endl;
    for(Assinante* assinante:this->assinantes){
        u<<assinante->get_codigo()<<";";
        u<<assinante->get_nome()<<endl;
    }
    for(Produtor* produtor:this->produtores){
        u<<produtor->get_codigo()<<";";
        u<<produtor->get_nome()<<endl;
    }
    u<<endl;
    u<<"Midias:"<<endl;
    for(Midia* midia:this->midias){
        u<<midia->get_nome()<<";";
        u<<midia->get_tipo()<<";";
        for(Produtor* produtor:this->produtores){
            for(Midia* aux:produtor->midias){
                if(aux->get_codigo()==midia->get_codigo()){
                    u<<produtor->get_nome().erase(produtor->get_nome().size())<<",";
                }
            }
        }
        u<<";";
        u<<midia->get_duracao()<<";";
        u<<midia->get_genero().get_nome().erase(midia->get_genero().get_nome().size())<<";";
        if(midia->get_tipo().compare("Podcast")==0){
            Podcast* p=(Podcast*)midia;
            u<<p->get_qtdTemporadas()<<";";
        }
        for(Album* album:this->albuns){
            for(Musica* musica:album->musicas){
                if(musica->get_nome().compare(midia->get_nome())==0){
                    u<<album->get_nome();
                }
            }
        }
        u<<";";
        u<<midia->get_anoLancamento()<<endl;
    }
    this->quicksort(0, this->produtores.size()-1);
    ofstream mpp;
    mpp.open("produtores.csv");
    for(Produtor* produtor : this->produtores){
        produtor->quicksort(0,produtor->midias.size()-1);
        mpp<<produtor->get_nome().erase(produtor -> get_nome().size())<<";";
        for(Midia* midia : produtor->midias){
            mpp<<midia->get_nome()<<";";
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
            f<<midia->get_genero().get_nome().erase(midia->get_genero().get_nome().size())<<";";
            f<<midia->get_duracao();
            f<<endl;
        }
    }

    ofstream e;
    e.open("estatisticas.txt");
    float hc=0;
    for(Assinante* assinante:this->assinantes){
        for(Midia* midia:assinante->favoritos) hc+=midia->get_duracao();
    }
    e<<"Horas Consumidas: "<<hc<<" minutos"<<endl;
    e<<endl;
    list<tuple<int,string,float>> lista1;
    tuple<int,string,float> auxiliar = make_tuple(0,"",0);
    for(Midia::Genero* genero:this->generos){
        tuple<int,string,float> tupla = make_tuple(0,"",0);
        get<1>(tupla) = genero->get_nome();
        for(Midia* midia:this->midias){
            if(midia->get_genero().get_nome().compare(get<1>(tupla))==0){
                get<0>(tupla) += 1;
                get<2>(tupla) += midia->get_duracao();
            }
        }
        if(get<2>(tupla)>=get<2>(auxiliar)) auxiliar = tupla;
        lista1.push_back(tupla);
    }
    e<<"Gênero mais ouvido: "<<get<1>(auxiliar).erase(get<1>(auxiliar).size())<<" - "<<get<2>(auxiliar)<<endl;
    e<<endl;
    e<<"Mídias por Gênero:"<<endl;
    for(tuple<int,string,float> t:lista1){
        e<<get<1>(t).erase(get<1>(t).size())<<":";
        e<<get<0>(t)<<endl;
    }
    e<<endl;
    e<<"Top 10 Mídias: "<<endl;

    list<tuple<int,string,string>> lista2;
    for(Midia* midia:this->midias){
        tuple<int,string,string> tupla = make_tuple(0,"","");
        get<1>(tupla) = midia->get_nome();
        get<2>(tupla) = midia->get_genero().get_nome();
        for(Assinante* assinante:this->assinantes){
            for(Midia* favorito:assinante->favoritos){
                if(favorito->get_nome().compare(get<1>(tupla))==0) get<0>(tupla) += 1;
            }
        }
        lista2.push_back(tupla);
    }
    lista2.sort();
    for(int i=0;i<10;i++){
        tuple<int,string,string> tupla = lista2.back();
        e<<get<1>(tupla)<<":"<<get<2>(tupla).erase(get<2>(tupla).size())<<":"<<get<0>(tupla)<<endl;
        lista2.pop_back();
    }
    e<<endl;
    e<<"Top 10 Produtores:"<<endl;
    list<tuple<int,string>> lista3;
    for(Produtor* produtor:this->produtores){
        int contagem=0;
        tuple<int,string> tupla = make_tuple(0,"");
        get<1>(tupla) = produtor->get_nome();
        for(Assinante* assinante:this->assinantes){
            for(Midia* favorito:assinante->favoritos){
                for(Midia* midia:produtor->midias){
                    if(midia->get_nome()==favorito->get_nome()) contagem++;
                }
                get<0>(tupla) = contagem;
            }
        }
        lista3.push_back(tupla);
    }
    lista3.sort();
    for(int i=0;i<10;i++){
        tuple<int,string> tupla = lista3.back();
        e<<get<1>(tupla).erase(get<1>(tupla).size())<<":"<<get<0>(tupla)<<endl;
        lista3.pop_back();
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
        if(tipo=="P") this->produtores.push_back(new Podcaster(nome, stoi(codigo)));
        if(tipo=="A") this->produtores.push_back(new Artista(nome, stoi(codigo)));
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
        getline(linha, anoPublicacao, '\n');

        for(int j=0;j<duracao.size();j++){
            if(duracao[j]==',') duracao[j] = '.';
        }

        string sigla;
        istringstream s1(genero);
        getline(s1,sigla,',');

        for(Midia::Genero* g:this->generos){
            if(g->get_sigla().compare(sigla)==0){
                if(tipo.compare("P")==0){
                    Podcast* podcast = new Podcast(nome, *g, stoi(temporada));
                    podcast->set_tipo(tipo);
                    podcast->set_codigo(stoi(codigo));
                    podcast->set_duracao(stof(duracao));
                    podcast->set_anoLancamento(stoi(anoPublicacao));
                    this->midias.push_back(podcast);
                }
                if(tipo.compare("M")==0){
                    Musica* musica = new Musica(nome, *g, stof(duracao), stoi(anoPublicacao));
                    musica->set_codigo(stoi(codigo));
                    musica->set_tipo(tipo);
                    this->midias.push_back(musica);
                    if(!codigoAlbum.empty()){
                        int i=0;
                        for(Album* alb:this->albuns){
                            if(alb->get_nome().compare(codigoAlbum)!=0) i++;
                        }
                        if(i==this->albuns.size()) this->albuns.push_back(new Album(codigoAlbum, stoi(duracao), stoi(anoPublicacao),0));
                    }
                    for(Album* alb:this->albuns){
                        if(alb->get_nome().compare(codigoAlbum)==0) alb->musicas.push_back(musica);
                    }
                }
            }
        }
        
        string p2;
        istringstream s2(produtores);
        while(getline(s2,p2,',')){
            if (p2[0] == ' ')
            {
                p2.erase(p2.begin());
            }
            for(int i=0;i<this->produtores.size();i++){
                if(!p2.empty()){
                    if(this->produtores[i]->get_codigo() == stoi(p2)) this->produtores[i]->midias.push_back(this->midias[stoi(codigo)-1]);
                }
            }
        }
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
                    if(this->midias[i]->get_codigo()==stoi(musica)){
                        int j=0;
                        for(Midia* midia:this->assinantes[stoi(codigo)-1]->favoritos){
                            if(midia->get_codigo() != stoi(musica)) j++;
                        }
                        if(j==this->assinantes[stoi(codigo)-1]->favoritos.size()) this->assinantes[stoi(codigo)-1]->favoritos.push_back(this->midias[stoi(musica)-1]);
                    }
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
    for(int i=0;i<x.size();i++){
        if(x[i]>=65 && x[i]<=90) x[i] += 32;
    }
    int i = p-1;
    for(int j=p;j<r;j++){
        string minusculo=this->produtores[j]->get_nome();
        for(int i=0;i<minusculo.size();i++){
            if(minusculo[i]>=65 && minusculo[i]<=90) minusculo[i] += 32;
        }
        if(minusculo.compare(x) <= 0){
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