#ifndef USUARIO_H_
#define USUARIO_H_

#include<iostream>

using namespace std;

class Usuario{ //classe base para Produtor e Assinante 
    protected:
    //métodos da classe que podem ser acessados também por classes herdadas 
      string nome;
      int codigo;
    public:
    //métodos da classe, contrutores, destrutores, set e gets, impressão em arquivo
      Usuario();
      Usuario(string nome, int codigo);
      ~Usuario();
      void set_nome(string nome);
      void set_codigo(int codigo);
      string get_nome();
      int get_codigo();
      virtual void imprimeNoArquivo(ofstream &outfile){}
};

#endif
