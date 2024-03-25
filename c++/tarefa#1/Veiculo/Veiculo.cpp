#include "Veiculo.h"  // Inclusão do arquivo de cabeçalho da classe Veiculo

using namespace std;

/*
*   Neste trecho de código, estamos implementando os métodos da classe Veiculo. 
*   O construtor Veiculo::Veiculo inicializa os atributos da classe com os 
*   valores passados como parâmetros. Os métodos getChassi, getModelo, 
*   getLocalizacao, getAnoFabricacao e getCapacidadeCarga retornam os valores 
*   dos atributos correspondentes. O método setLocalizacao modifica o valor do 
*   atributo localizacao.
*/

// Implementação do construtor da classe Veiculo
Veiculo::Veiculo(string chassi, string modelo, int anoFabricacao, string localizacao, double capacidadeCarga)
    : chassi(chassi), modelo(modelo), anoFabricacao(anoFabricacao), localizacao(localizacao), capacidadeCarga(capacidadeCarga) {}

// Implementação do método getter para o atributo chassi
string Veiculo::getChassi() const {
    return chassi;
}

// Implementação do método setter para o atributo chassi
void Veiculo::setChassi(const string& chassi) {
    this->chassi = chassi;
}

// Implementação do método getter para o atributo modelo
string Veiculo::getModelo() const {
    return modelo;
}

// Implementação do método setter para o atributo modelo
void Veiculo::setModelo(const string& modelo) {
    this->modelo = modelo;
}

// Implementação do método getter para o atributo anoFabricacao
int Veiculo::getAnoFabricacao() const {
    return anoFabricacao;
}

// Implementação do método setter para o atributo anoFabricacao
void Veiculo::setAnoFabricacao(int anoFabricacao) {
    this->anoFabricacao = anoFabricacao;
}

// Implementação do método getter para o atributo localizacao
string Veiculo::getLocalizacao() const {
    return localizacao;
}

// Implementação do método setter para o atributo localizacao
void Veiculo::setLocalizacao(const string& localizacao) {
    this->localizacao = localizacao;
}

// Implementação do método getter para o atributo capacidadeCarga
double Veiculo::getCapacidadeCarga() const {
    return capacidadeCarga;
}

// Implementação do método setter para o atributo capacidadeCarga
void Veiculo::setCapacidadeCarga(double capacidadeCarga) {
    this->capacidadeCarga = capacidadeCarga;
}