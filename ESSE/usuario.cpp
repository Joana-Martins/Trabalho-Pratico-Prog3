#include"usuario.h"

//construtores
Usuario::Usuario(){}
Usuario::Usuario(string nome, int codigo){
  this->set_nome(nome);
  this->set_codigo(codigo);
}
Usuario::~Usuario(){}//destrutor 

//sets e gets
void Usuario::set_nome(string nome){
  this->nome = nome;
}
void Usuario::set_codigo(int codigo){
  this->codigo = codigo;
}
string Usuario::get_nome(){
  return this->nome;
}
int Usuario::get_codigo(){
  return this->codigo;
}
