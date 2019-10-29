#ifndef USUARIO_H_
#define USUARIO_H_

#include<iostream>

using namespace std;

class Usuario{
    protected:
      string nome;
      int codigo;
    public:
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
