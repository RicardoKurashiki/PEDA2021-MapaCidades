#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int MAXNOS = 15;
constexpr int INFINITO = 1000000;

class Mapa
{
public:
	Mapa();
	void adiciona_cidade(string nome_cidade);
	void unep(string cidade_a, string cidade_b, float distancia);
	void menor_caminho(string cidade_a, string cidade_b);
private:
	int N;
	string cidades[MAXNOS];
	bool adj[MAXNOS][MAXNOS];
	float peso[MAXNOS][MAXNOS];
	int indice_cidade(string nome_cidade);
	float distancia_entre_cidades(int corrente, int i);
	bool validos(int a, int b);
};

#endif