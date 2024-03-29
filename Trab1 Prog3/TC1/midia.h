#ifndef MIDIA_H_
#define MIDIA_H_

#include<iostream>
#include<fstream>

using namespace std;

class Midia{
    protected:
        string nome;
        int codigo;
        int duracao;
        int anoLancamento;
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
        void set_duracao(int duracao);
        void set_anoLancamento(int anoLancamento);
        void set_genero(Genero genero);
        string get_nome();
        int get_codigo();
        int get_duracao();
        int get_anoLancamento();
        Genero get_genero();
        virtual void imprimeInfoProduto(){}
        virtual void imprimeNoArquivo(ofstream &outfile){}
};

#endif
