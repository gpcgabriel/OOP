#include "Veiculo.h"
#include <vector>
#include <string>
#include <regex>

using namespace std;

/**
 * Construtor da classe Veiculo.
 * 
 * @param id Identificador único do veículo.
 * @param placa Placa do veículo.
 * @param anoFabricacao Ano de fabricação do veículo.
 * @param capacidadeCarga Capacidade máxima de carga do veículo em kg.
 * @param capacidadeAtual Capacidade atual de carga do veículo em kg.
 * @param volumeCarga Capacidade máxima de volume do veículo em m³.
 * @param volumeAtual Volume atual de carga do veículo em m³.
 * @param chassi Número de chassi do veículo.
 * @param modelo Modelo do veículo.
 * @param localizacao Coordenadas de localização do veículo (latitude, longitude).
 * @param disponivel Disponibilidade do veículo para uso.
 */
Veiculo::Veiculo(int id, string placa, int anoFabricacao, float capacidadeCarga, float capacidadeAtual, float volumeCarga, float volumeAtual, string chassi, 
                    string modelo, vector<double> localizacao, bool disponivel) {
    this->id = id;
    this->placa = placa;
    this->anoFabricacao = anoFabricacao;
    this->capacidadeCarga = capacidadeCarga;
    this->volumeCarga = volumeCarga;
    this->capacidadeAtual = capacidadeAtual;
    this->volumeAtual = volumeAtual;
    this->chassi = chassi;
    this->modelo = modelo;
    this->localizacao = localizacao;
    this->disponivel = disponivel;
}

/**
 * Construtor padrão da classe Veiculo.
 */
Veiculo::Veiculo() { }

/**
 * Destrutor da classe Veiculo.
 */
Veiculo::~Veiculo() { }

/**
 * Obtém o ID do veículo.
 * 
 * @return O ID do veículo.
 */
int Veiculo::getId() const {
    return this->id;
}

/**
 * Define o ID do veículo.
 * 
 * @param id O ID do veículo.
 * @return 1 se o ID foi definido com sucesso, 0 caso contrário.
 */
int Veiculo::setId(const int& id) {
    this->id = id;
    return 1;
}

/**
 * Obtém a placa do veículo.
 * 
 * @return A placa do veículo.
 */
string Veiculo::getPlaca() const {
    return this->placa;
}

/**
 * Define a placa do veículo.
 * 
 * @param placa A placa do veículo.
 * @return 1 se a placa foi definida com sucesso, 0 caso contrário.
 */
int Veiculo::setPlaca(const string& placa) {
    if(validarPlaca(placa)){
        this->placa = placa;
        return 1;
    }
    return 0;
}

/**
 * Obtém o ano de fabricação do veículo.
 * 
 * @return O ano de fabricação do veículo.
 */
int Veiculo::getAnoFabricacao() const {
    return this->anoFabricacao;
}

/**
 * Define o ano de fabricação do veículo.
 * 
 * @param anoFabricacao O ano de fabricação do veículo.
 * @return 1 se o ano de fabricação foi definido com sucesso, 0 caso contrário.
 */
int Veiculo::setAnoFabricacao(const int& anoFabricacao) {
    if(validarAnoFabricacao(anoFabricacao)){
        this->anoFabricacao = anoFabricacao;
        return 1;
    }
    return 0;
}

/**
 * Obtém a capacidade de carga do veículo.
 * 
 * @return A capacidade de carga do veículo em kg.
 */
float Veiculo::getCapacidadeCarga() const {
    return this->capacidadeCarga;
}

/**
 * Define a capacidade atual de carga do veículo.
 * 
 * @param capacidadeAtual A capacidade atual de carga do veículo em kg.
 * @return 1 se a capacidade atual foi definida com sucesso, 0 caso contrário.
 */
int Veiculo::setCapacidadeAtual(const float& capacidadeAtual){
    if(!validarCapacidadeCarga(capacidadeAtual)){
        return 0;
    }
    this->capacidadeAtual = capacidadeAtual;
    return 1;
}

/**
 * Obtém a capacidade atual de carga do veículo.
 * 
 * @return A capacidade atual de carga do veículo em kg.
 */
float Veiculo::getCapacidadeAtual() const{
    return this->capacidadeAtual;
}

/**
 * Define o volume atual de carga do veículo.
 * 
 * @param volumeAtual O volume atual de carga do veículo em m³.
 * @return 1 se o volume atual foi definido com sucesso, 0 caso contrário.
 */
int Veiculo::setVolumeAtual(const float& volumeAtual){
    if(!validarCapacidadeCarga(volumeAtual)){
        return 0;
    }
    this->volumeAtual = volumeAtual;
    return 1;
}

/**
 * Obtém o volume atual de carga do veículo.
 * 
 * @return O volume atual de carga do veículo em m³.
 */
float Veiculo::getVolumeAtual() const{
    return this->volumeAtual;
}

/**
 * Define a capacidade de carga do veículo.
 * 
 * @param capacidadeCarga A capacidade de carga do veículo em kg.
 * @return 1 se a capacidade de carga foi definida com sucesso, 0 caso contrário.
 */
int Veiculo::setCapacidadeCarga(const float& capacidadeCarga) {
    if(validarCapacidadeCarga(capacidadeCarga)){
        this->capacidadeCarga = capacidadeCarga;
        return 1;
    }
    return 0;
}

/**
 * Obtém a capacidade de volume do veículo.
 * 
 * @return A capacidade de volume do veículo em m³.
 */
float Veiculo::getVolumeCarga() const {
    return this->volumeCarga;
}

/**
 * Define o volume de carga do veículo.
 * 
 * @param volumeCarga O volume de carga do veículo em m³.
 * @return 1 se o volume de carga foi definido com sucesso, 0 caso contrário.
 */
int Veiculo::setVolumeCarga(const float& volumeCarga) {
    if(!validarCapacidadeCarga(volumeCarga)){
        return 0;
    }
    this->volumeCarga = volumeCarga;
    return 1;
}

/**
 * Obtém o número de chassi do veículo.
 * 
 * @return O número de chassi do veículo.
 */
string Veiculo::getChassi() const {
    return this->chassi;
}

/**
 * Define o número de chassi do veículo.
 * 
 * @param chassi O número de chassi do veículo.
 * @return 1 se o número de chassi foi definido com sucesso, 0 caso contrário.
 */
int Veiculo::setChassi(const string& chassi) {
    if(validarChassi(chassi)){
        this->chassi = chassi;
        return 1;
    }
    return 0;
}

/**
 * Obtém o modelo do veículo.
 * 
 * @return O modelo do veículo.
 */
string Veiculo::getModelo() const {
    return this->modelo;
}

/**
 * Define o modelo do veículo.
 * 
 * @param modelo O modelo do veículo.
 * @return 1 se o modelo foi definido com sucesso, 0 caso contrário.
 */
int Veiculo::setModelo(const string& modelo) {
    this->modelo = modelo;
    return 1;
}

/**
 * Obtém a localização do veículo.
 * 
 * @return As coordenadas de localização do veículo (latitude, longitude).
 */
vector<double> Veiculo::getLocalizacao() const {
    return this->localizacao;
}

/**
 * Define a localização do veículo.
 * 
 * @param localizacao As coordenadas de localização do veículo (latitude, longitude).
 * @return 1 se a localização foi definida com sucesso, 0 caso contrário.
 */
int Veiculo::setLocalizacao(const vector<double>& localizacao) {
    if(validarLocalizacao(localizacao)){
        this->localizacao = localizacao;
        return 1;
    }
    return 0;
}

/**
 * Verifica a disponibilidade do veículo.
 * 
 * @return true se o veículo está disponível, false caso contrário.
 */
bool Veiculo::getDisponibilidade() const {
    return this->disponivel;
}

/**
 * Define a disponibilidade do veículo.
 * 
 * @param disponivel A disponibilidade do veículo.
 * @return 1 se a disponibilidade foi definida com sucesso, 0 caso contrário.
 */
int Veiculo::setDisponibilidade(const bool& disponivel) {
    this->disponivel = disponivel;
    return 1;
}

/**
 * Aloca volume de carga no veículo.
 * 
 * @param volumeCarga O volume de carga a ser alocado em m³.
 * @return 1 se o volume de carga foi alocado com sucesso, 0 caso contrário.
 */
int Veiculo::alocarVolumeCarga(const float& volumeCarga){
    if(validarCapacidadeCarga(volumeCarga) && this->volumeAtual >= volumeCarga){
        this->volumeAtual -= volumeCarga;
        return 1;
    }
    return 0;
}

/**
 * Aloca peso de carga no veículo.
 * 
 * @param pesoCarga O peso de carga a ser alocado em kg.
 * @return 1 se o peso de carga foi alocado com sucesso, 0 caso contrário.
 */
int Veiculo::alocarPesoCarga(const float& pesoCarga){
    if(validarCapacidadeCarga(pesoCarga) && this->capacidadeAtual >= pesoCarga){
        this->capacidadeAtual -= pesoCarga;
        return 1;
    }
    return 0;
}

/**
 * Sobrecarga do operador de inserção para a classe Veiculo.
 * 
 * @param os Stream de saída.
 * @param veiculo Objeto da classe Veiculo a ser inserido na stream de saída.
 * @return A stream de saída.
 */
ostream& operator<<(ostream& os, const Veiculo& veiculo) {
    os << "ID: " << veiculo.id << endl;
    os << "Placa: " << veiculo.placa << endl;
    os << "Ano de Fabricação: " << veiculo.anoFabricacao << endl;
    os << "Capacidade de Carga: " << veiculo.capacidadeCarga << "kg" << endl;
    os << "Capacidade de Volume: " << veiculo.volumeCarga << "m³" << endl;
    os << "Chassi: " << veiculo.chassi << endl;
    os << "Modelo: " << veiculo.modelo << endl;
    os << "Disponibilidade: " << (veiculo.disponivel ? "disponível" : "indisponível") << endl;
    os << "Localização: ";
    for (double elemento : veiculo.localizacao) {
        os <<  elemento << " ";
    }
    os << endl;
    return os;
}

/**
 * Sobrecarga do operador de igualdade para a classe Veiculo.
 * 
 * @param outro Outro objeto da classe Veiculo a ser comparado.
 * @return true se os veículos são iguais, false caso contrário.
 */
bool Veiculo::operator==(const Veiculo& outro) const {
    return (this->id == outro.id &&
                this->placa == outro.placa &&
                this->anoFabricacao == outro.anoFabricacao &&
                this->capacidadeCarga == outro.capacidadeCarga &&
                this->chassi == outro.chassi &&
                this->modelo == outro.modelo &&
                this->disponivel == outro.disponivel &&
                this->localizacao == outro.localizacao);
}

/**
 * Valida a localização do veículo.
 * 
 * @param localizacao As coordenadas de localização do veículo (latitude, longitude).
 * @return true se a localização é válida, false caso contrário.
 */
bool Veiculo::validarLocalizacao(const vector<double>& localizacao) {
    return localizacao.size() >= 2;
}

/**
 * Valida a capacidade de carga do veículo.
 * 
 * @param capacidadeCarga A capacidade de carga do veículo em kg.
 * @return true se a capacidade de carga é válida, false caso contrário.
 */
bool Veiculo::validarCapacidadeCarga(const float& capacidadeCarga){
    return capacidadeCarga > 0;
}

/**
 * Valida o ano de fabricação do veículo.
 * 
 * @param anoFabricacao O ano de fabricação do veículo.
 * @return true se o ano de fabricação é válido, false caso contrário.
 */
bool Veiculo::validarAnoFabricacao(const int& anoFabricacao){
    return anoFabricacao > 0;
}

/**
 * Valida o número de chassi do veículo.
 * 
 * @param chassi O número de chassi do veículo.
 * @return true se o número de chassi é válido, false caso contrário.
 */
bool Veiculo::validarChassi(const string& chassi){
    // Expressão regular para validar números de chassi
    regex padrao("^[A-HJ-NPR-Z0-9]{17}$");

    // Verificar se o número de chassi corresponde ao padrão
    return regex_match(chassi, padrao);
}

/**
 * Valida a placa do veículo.
 * 
 * @param placa A placa do veículo.
 * @return true se a placa é válida, false caso contrário.
 */
bool Veiculo::validarPlaca(const string& placa){
    // Expressão regular para validar placas de veículos
    regex padrao("^[A-Z]{3}[0-9]{4}$");
    
    // Verificar se a placa corresponde ao padrão
    return regex_match(placa, padrao);
}