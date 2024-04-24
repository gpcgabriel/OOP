#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo/Veiculo.h"

using namespace std;

class Caminhao : public Veiculo {
public:
    // Construtor da classe caminhao que chama o construtor da classe Veiculo
    Caminhao(int id, string chassi, string modelo, int anoFabricacao, string localizacao, double capacidadeCarga);
    ~Caminhao(){} // Destrutor

private:
    int numEixos;  // Número de portas que o caminhao possui

    int setNumEixos(const int& numPortas); // Define o número de eixos
    int getNumEixos(); // Retorna o número de eixos
};

#endif // CAMINHAO_H
