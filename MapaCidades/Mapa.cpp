#include "Mapa.h"

Mapa::Mapa()
{
	// Cria uma classe com 0 cidades
	N = 0;
	// Popula a tabela adj inteira com false e a tabela de distancia com infinito
	for (int i = 0; i < MAXNOS; ++i)
		for (int j = 0; j < MAXNOS; ++j)
		{
			adj[i][j] = false;
			peso[i][j] = INFINITO;
		}
}

int Mapa::indice_cidade(string nome_cidade)
{
	// Procura o indice de uma cidade
	for (int i = 0; i < N; ++i)
		if (cidades[i] == nome_cidade) return i;
	// Caso nao encontre, retorna -1
	return -1;
}

bool Mapa::validos(int a, int b)
{
	return (a > -1 && a < MAXNOS&& b > -1 && b < MAXNOS);
}

void Mapa::adiciona_cidade(string nome_cidade)
{
	if (N < MAXNOS)
	{
		// Add cidade na lista de todas as cidades
		cidades[N] = nome_cidade;
		// Incrementa o numero total de cidades
		++N;
	}
	else cerr << "Numero maximo atingido!" << endl;
}

void Mapa::unep(string cidade_a, string cidade_b, float distancia)
{
	if (N > 0)
	{
		int a = indice_cidade(cidade_a);
		int b = indice_cidade(cidade_b);
		if (validos(a, b))
		{
			adj[a][b] = adj[b][a] = true;			// a <-> b = true
			peso[a][b] = peso[b][a] = distancia;	// a <-> b = distancia
		}
	}
	else cerr << "Tamanho invalido!" << endl;
}

float Mapa::distancia_entre_cidades(int atual, int i)
{
	if (validos(atual, i))
		if (adj[i][atual]) return peso[i][atual];
	else return INFINITO;
}

void Mapa::menor_caminho(string cidade_a, string cidade_b)
{
	// Start
	int s = indice_cidade(cidade_a);
	// Target
	int t = indice_cidade(cidade_b);
	// Caminho que sera percorrido
	int precede[MAXNOS] = { s };

	// Lista do menor caminho percorrido
	string menor_caminho[MAXNOS];

	float distancia[MAXNOS];
	bool calculado[MAXNOS];

	for (int i = 0; i < N; i++)
	{
		distancia[i] = INFINITO;
		calculado[i] = false;
	}

	distancia[s] = 0;
	calculado[s] = true;

	int atual = s;

	// Calculo do menor caminho
	while (atual != t)
	{
		float menordist = INFINITO;
		int k = 0;
		float dc = distancia[atual];
		for (int i = 0; i < N; i++)
		{
			if (!calculado[i])
			{
				float novadist = dc + distancia_entre_cidades(atual, i);
				if (novadist < distancia[i])
				{
					distancia[i] = novadist;
					precede[i] = atual;
				}
				if (distancia[i] < menordist)
				{
					menordist = distancia[i];
					k = i;
				}
			}
		}
		atual = k;
		calculado[atual] = true;
	}

	string caminho = cidades[t];
	int caminho_int = t;
	int cont = 0;
	// Caminho de "target" (t) ate o "start" s
	// Caminho inverso, do fim para o inicio
	while (caminho != cidade_a)
	{
		menor_caminho[cont] = caminho;
		caminho = cidades[precede[caminho_int]];
		caminho_int = indice_cidade(caminho);
		++cont;
	}

	// Revertendo o vector de strings para obter o caminho 
	for (int i = 0, j = cont - 1; i < cont / 2; i++, j--)
	{
		string temp = menor_caminho[i];
		menor_caminho[i] = menor_caminho[j];
		menor_caminho[j] = temp;
	}

	// Mostrar o resultado na tela
	cout << "Menor distancia = " << distancia[t] << " km" << endl;
	cout << "Menor caminho = ";
	cout << cidade_a << " -> ";
	for (int i = 0; i < cont; ++i)
	{
		cout << menor_caminho[i];
		if (i != cont - 1) cout << " -> ";
	}
}
