#include "Veiculo.h"  // Inclusão do arquivo de cabeçalho da classe Veiculo
#include <regex>
#include <iostream>

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
Veiculo::Veiculo(int id, string chassi, string modelo, int anoFabricacao, string localizacao, double capacidadeCarga, bool ativo, bool disponivel)
    :id(id), chassi(chassi), modelo(modelo), anoFabricacao(anoFabricacao), localizacao(localizacao), capacidadeCarga(capacidadeCarga) {}

//Implementação do destrutor da classe Veículo
Veiculo::~Veiculo(){}

// Implementação do método para retornar atividade
bool Veiculo::getVeiculoAtivo() const {
    try
    {
        return this->ativo;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao buscar atividade do veiculo!" << endl;
        return false;
    }
}

// Implementação do método de registrar atividade
int Veiculo::setVeiculoAtivo(const bool& ativo){
    try
    {
        this->ativo = ativo;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao cadastrar atividade do veículo!" << endl;
        return 1;
    } 
}

// Implementação do método de retornar disponibilidade
bool Veiculo::getVeiculoDisponivel()const {
    try
    {
        return this->disponivel;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao retornar o estado do veículo";
        return false;
    }
    
}

// Implementação do método de cadastrar disponibilidade
int Veiculo::setVeiculoDisponivel(const bool& disponivel){
    try
    {
        this->disponivel = disponivel;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao registrar a disponibilidade do veículo!" << endl;
        return 1;
    }
    
}

// Implementação do método getter para o atributo chassi
string Veiculo::getChassi() const {
    return chassi;
}

// Implementação do método setter para o atributo chassi
int Veiculo::setChassi(const string& chassi) {
    if(validarChassi(chassi)){
        this->chassi = chassi;
        return 0;
    }else{
        cout << "O chassi digitado é inválido!" << endl;
        return 1;
    }
}

// Implementação do método getter para o atributo modelo
string Veiculo::getModelo() const {
    return modelo;
}

// Implementação do método setter para o atributo modelo
int Veiculo::setModelo(const string& modelo) {
    this->modelo = modelo;
    try
    {
        this->modelo = modelo;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao registrar o modelo do veículo!" << endl;
        return 1;
    }
}

// Implementação do método getter para o atributo anoFabricacao
int Veiculo::getAnoFabricacao() const {
    return anoFabricacao;
}

// Implementação do método setter para o atributo anoFabricacao
int Veiculo::setAnoFabricacao(int anoFabricacao) {
    if(validarAnoFabricacao(anoFabricacao)){
        this->anoFabricacao = anoFabricacao;
        return 0;
    }else{
        cout << "O ano de fabricação é inválido!" << endl;
        return 1;
    }
}

// Implementação do método getter para o atributo localizacao
string Veiculo::getLocalizacao() const {
    return localizacao;
}

// Implementação do método setter para o atributo localizacao
int Veiculo::setLocalizacao(const string& localizacao) {
    try
    {
        this->localizacao = localizacao;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao registrar a localização do veículo!" << endl;
        return 1;
    }
}

// Implementação do método getter para o atributo capacidadeCarga
double Veiculo::getCapacidadeCarga() const {
    return capacidadeCarga;
}

// Implementação do método setter para o atributo capacidadeCarga
int Veiculo::setCapacidadeCarga(const double& capacidadeCarga) {
    if(validarCapacidadeCarga(capacidadeCarga)){
        this->capacidadeCarga = capacidadeCarga;
        return 0;
    }else{
        cout << "A capacidade de carga inserida é inválida!" << endl;
        return 1;
    }
}

bool Veiculo::validarAnoFabricacao(const int& anoFabricacao){
    // O primeiro veículo a vapor foi fabricado em 1769 pelo inventor francês Nicolas-Joseph Cugnot
    return anoFabricacao >= 1769;
}

bool Veiculo::validarChassi(const string& chassi) {
    // Expressão regular para validar o formato do chassi
    regex regexChassi("^[A-HJ-NPR-Z0-9]{17}$");

    // Verifica se o chassi corresponde à expressão regular
    return regex_match(chassi, regexChassi);
}

bool Veiculo::validarCapacidadeCarga(const double& capacidadeCarga){
    return capacidadeCarga >= 0;
}