#ifndef CARRO_H
#define CARRO_H

#include "Veiculo/Veiculo.h"

using namespace std;

class Carro : public Veiculo {
public:
    // Construtor da classe Carro que chama o construtor da classe Veiculo
    Carro(int id, string chassi, string modelo, int anoFabricacao, string localizacao, double capacidadeCarga, bool ativo, bool disponivel);
    ~Carro(){} // Destrutor

private:
    int numPortas;  // Número de portas que o carro possui

    int setNumPortas(const int& numPortas); // Define o número de portas
    int getNumPortas(); // Retorna o número de portas
};

#endif // CARRO_H
