#ifndef EXCECOES_H_
#define EXCECOES_H_

#include<iostream>
#include<string>
#include<vector>
#include<ctype.h>
#include"midia.h"
#include"produtor.h"
#include"assinante.h"

using namespace std;

void checa_se_numero(string palavra);
void checa_se_float(string palavra);
void checa_se_existe(string sigla, vector<Midia::Genero*> generos);
void checa_se_existe(string tipo);
void checa_se_existe(int produtor, vector<Produtor*> produtores);
void checa_se_existe(int codigo, vector<Assinante*> assinantes);
void checa_se_existe(int musica, vector<Midia*> midias);
void checa_se_existe_usuario(string tipo);

#endif