#include "Caminhao.h"
#include <iostream>

// Implementação do construtor da classe Caminhao
Caminhao::Caminhao(int id, string chassi, string modelo, int anoFabricacao, string localizacao, double capacidadeCarga)
    : Veiculo(id, chassi, modelo, anoFabricacao, localizacao, capacidadeCarga) {
}

Caminhao::~Caminhao(){}

// Define o número de Eixos que o Caminhao possuirá
int Caminhao::setNumEixos(const int& numEixos){
    try
    {
        this->numEixos = numEixos;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao registrar o número de Eixos!" << endl;
        return 1;
    }
}

// Retorna o número de Eixos que o Caminhao possui
int Caminhao::getNumEixos(){
    try
    {
        return this->numEixos;
    }
    catch(const std::exception& e)
    {
        cout << "Erro interno!" << endl;
        return 1;
    }
    
}