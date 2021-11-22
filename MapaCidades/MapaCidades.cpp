#include <iostream>
#include "Mapa.h"

using namespace std;


int main()
{
    Mapa m;

    // Adicao das cidades
    m.adiciona_cidade("Londrina");
    m.adiciona_cidade("Itarare");
    m.adiciona_cidade("Sao Paulo");
    m.adiciona_cidade("Ponta Grossa");
    m.adiciona_cidade("Curitiba");
    m.adiciona_cidade("Registro");
    m.adiciona_cidade("Porto Uniao");
    m.adiciona_cidade("Mafra");
    m.adiciona_cidade("Joinville");
    m.adiciona_cidade("Blumenau");
    m.adiciona_cidade("Itajai");
    m.adiciona_cidade("Lages");
    m.adiciona_cidade("Florianopolis");

    // Criacao das distancias
    m.unep("Londrina", "Ponta Grossa", 271.0);
    m.unep("Londrina", "Itarare", 310.0);
    m.unep("Itarare", "Ponta Grossa", 174.0);
    m.unep("Itarare", "Curitiba", 208.0);
    m.unep("Itarare", "Sao Paulo", 342.0);
    m.unep("Curitiba", "Ponta Grossa", 114.0);
    m.unep("Curitiba", "Mafra", 115.0);
    m.unep("Curitiba", "Joinville", 132.0);
    m.unep("Curitiba", "Registro", 221.2);
    m.unep("Registro", "Sao Paulo", 185.9);
    m.unep("Mafra", "Ponta Grossa", 155.0);
    m.unep("Mafra", "Porto Uniao", 143.0);
    m.unep("Mafra", "Blumenau", 165.0);
    m.unep("Mafra", "Joinville", 136.0);
    m.unep("Porto Uniao", "Ponta Grossa", 209.0);
    m.unep("Porto Uniao", "Lages", 271.0);
    m.unep("Lages", "Mafra", 349.0);
    m.unep("Lages", "Blumenau", 223.0);
    m.unep("Lages", "Florianopolis", 231.0);
    m.unep("Itajai", "Florianopolis", 102.0);
    m.unep("Itajai", "Blumenau", 52.3);
    m.unep("Itajai", "Joinville", 86.2);

    string cidade_a, cidade_b;

    cout << "Cidade A: ";
    getline(cin, cidade_a);
    cout << "Cidade B: ";
    getline(cin, cidade_b);
    cout << endl;
    m.menor_caminho(cidade_a, cidade_b);

    cout << endl;

    return 0;
}