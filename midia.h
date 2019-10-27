#ifndef MIDIA_H_
#define MIDIA_H_

#include<iostream>
#include<fstream>

using namespace std;

class Midia{
    protected:
        string nome;
        int codigo;
        float duracao;
        int anoLancamento;
        string tipo;
    public:
        class Genero{
            private:
                string nome;
                string sigla;
            public:
                Genero();
                Genero(string nome, string sigla);
                ~Genero();
                void set_nome(string nome);
                void set_sigla(string sigla);
                string get_nome();
                string get_sigla();
        };
        Genero genero;
        static int qtdProdutos;
        static void imprimeQtdProdutos();
        Midia();
        Midia(string nome, int codigo, Genero genero);
        ~Midia();
        void set_nome(string nome);
        void set_codigo(int codigo);
        void set_duracao(float duracao);
        void set_anoLancamento(int anoLancamento);
        void set_genero(Genero genero);
        void set_tipo(string tipo);
        string get_nome();
        int get_codigo();
        float get_duracao();
        int get_anoLancamento();
        Genero get_genero();
        string get_tipo();
        virtual void imprimeInfoProduto(){}
        virtual void imprimeNoArquivo(ofstream &outfile){}
};

#endif
