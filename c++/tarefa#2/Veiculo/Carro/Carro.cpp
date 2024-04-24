#include "Carro.h"
#include <iostream>

// Implementação do construtor da classe Carro
Carro::Carro(int id, string chassi, string modelo, int anoFabricacao, string localizacao, double capacidadeCarga)
    : Veiculo(id, chassi, modelo, anoFabricacao, localizacao, capacidadeCarga) {
}

Carro::~Carro(){}

// Define o número de portas que o carro possuirá
int Carro::setNumPortas(const int& numPortas){
    try
    {
        this->numPortas = numPortas;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao registrar o número de portas!" << endl;
        return 1;
    }
}

// Retorna o número de portas que o carro possui
int Carro::getNumPortas(){
    try
    {
        return this->numPortas;
    }
    catch(const std::exception& e)
    {
        cout << "Erro interno!" << endl;
        return 1;
    }
    
}