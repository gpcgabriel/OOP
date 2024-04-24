#include "../Veiculo/Veiculo.h" // Inclui a definição da classe Veiculo
#include "../Cliente/Cliente.h" // Inclui a definição da classe Cliente
#include "Ordem.h" // Inclui a definição da classe Ordem
#include <vector> // Inclui a biblioteca para utilizar vetores
#include <iostream> // Inclui a biblioteca para entrada e saída padrão

using namespace std;

/**
 * Construtor da classe Ordem.
 * 
 * @param id ID da ordem.
 * @param localColeta Vetor representando a localização da coleta.
 * @param localEntrega Vetor representando a localização da entrega.
 * @param cliente Ponteiro para o cliente associado à ordem.
 * @param pesoCarga Peso da carga da ordem.
 * @param volumeCarga Volume da carga da ordem.
 * @param prioridade Indica se a ordem é prioritária ou não.
 */
Ordem::Ordem(int id, vector<double> localColeta, vector<double> localEntrega, Cliente *cliente, float pesoCarga, float volumeCarga, bool prioridade)
                : id(id), localColeta(localColeta), localEntrega(localEntrega), cliente(cliente), pesoCarga(pesoCarga), volumeCarga(volumeCarga), prioridade(prioridade) {}

/**
 * Destrutor da classe Ordem.
 */
Ordem::~Ordem(){}

/**
 * Define o ID da ordem.
 * 
 * @param id Novo ID da ordem.
 * @return 1 se o ID foi definido com sucesso, 0 caso contrário.
 */
int Ordem::setId(const int& id) {
    if(!validarId(id)){
        return 0;
    }
    this->id = id;
    return 1;
}

/**
 * Obtém o ID da ordem.
 * 
 * @return ID da ordem.
 */
int Ordem::getId() const {
    return this->id;
}

/**
 * Define o local de coleta da ordem.
 * 
 * @param localColeta Novo local de coleta da ordem.
 * @return 1 se o local de coleta foi definido com sucesso, 0 caso contrário.
 */
int Ordem::setLocalColeta(vector<double> localColeta) {
    // Utilizamos os métodos de Veiculo para não ter redundâncias no código
    if(!Veiculo::validarLocalizacao(localColeta)){
        return 0;
    }
    this->localColeta = localColeta;
    return 1;
}

/**
 * Obtém o local de coleta da ordem.
 * 
 * @return Vetor representando o local de coleta da ordem.
 */
vector<double> Ordem::getLocalColeta() const {
    return localColeta;
}

/**
 * Define o local de entrega da ordem.
 * 
 * @param localEntrega Novo local de entrega da ordem.
 * @return 1 se o local de entrega foi definido com sucesso, 0 caso contrário.
 */
int Ordem::setLocalEntrega(vector<double> localEntrega) {
    // Utilizamos os métodos de Veiculo para não ter redundâncias no código
    if(!Veiculo::validarLocalizacao(localEntrega)){
        return 0;
    }
    this->localEntrega = localEntrega;
    return 1;
}

/**
 * Obtém o local de entrega da ordem.
 * 
 * @return Vetor representando o local de entrega da ordem.
 */
vector<double> Ordem::getLocalEntrega() const {
    return localEntrega;
}

/**
 * Define o cliente associado à ordem.
 * 
 * @param cliente Ponteiro para o cliente associado à ordem.
 * @return 1 se o cliente foi definido com sucesso, 0 caso contrário.
 */
int Ordem::setCliente(Cliente *cliente) {
    this->cliente = cliente;
    return 1;
}

/**
 * Obtém o cliente associado à ordem.
 * 
 * @return Ponteiro para o cliente associado à ordem.
 */
Cliente* Ordem::getCliente() const {
    return cliente;
}

/**
 * Define o peso da carga da ordem.
 * 
 * @param pesoCarga Novo peso da carga da ordem.
 * @return 1 se o peso da carga foi definido com sucesso, 0 caso contrário.
 */
int Ordem::setPesoCarga(const float& pesoCarga) {
    // Utilizamos os métodos de Veiculo para não ter redundâncias no código
    if(!Veiculo::validarCapacidadeCarga(pesoCarga)){
        return 1;
    }
    this->pesoCarga = pesoCarga;
    return 0;
}

/**
 * Obtém o peso da carga da ordem.
 * 
 * @return Peso da carga da ordem.
 */
float Ordem::getPesoCarga() const {
    return pesoCarga;
}

/**
 * Define o volume da carga da ordem.
 * 
 * @param volumeCarga Novo volume da carga da ordem.
 * @return 1 se o volume da carga foi definido com sucesso, 0 caso contrário.
 */
int Ordem::setVolumeCarga(const float& volumeCarga) {
    if(!Veiculo::validarCapacidadeCarga(volumeCarga)){
        return 1;
    }
    this->volumeCarga = volumeCarga;
    return 0;
}

/**
 * Obtém o volume da carga da ordem.
 * 
 * @return Volume da carga da ordem.
 */
float Ordem::getVolumeCarga() const {
    return volumeCarga;
}

/**
 * Define se a ordem é prioritária ou não.
 * 
 * @param prioridade Indica se a ordem é prioritária ou não.
 * @return 1 se a prioridade foi definida com sucesso, 0 caso contrário.
 */
int Ordem::setPrioridade(const bool& prioridade) {
    this->prioridade = prioridade;
    return 1;
}

/**
 * Verifica se a ordem é prioritária.
 * 
 * @return True se a ordem é prioritária, False caso contrário.
 */
bool Ordem::getPrioridade() const {
    return prioridade;
}

/**
 * Adiciona um veículo à ordem.
 * 
 * @param veiculo Veículo a ser adicionado à ordem.
 * @return 1 se o veículo foi adicionado com sucesso, 0 caso contrário.
 */
int Ordem::setVeiculo(Veiculo& veiculo) {
    this->veiculos.push_back(veiculo);
    return 1;
}

/**
 * Define os veículos da ordem.
 * 
 * @param veiculos Vetor de veículos a serem associados à ordem.
 * @return 1 se os veículos foram definidos com sucesso, 0 caso contrário.
 */
int Ordem::setVeiculos(const vector<Veiculo>& veiculos){
    this->veiculos = veiculos;
    return 1;
}

/**
 * Obtém os veículos associados à ordem.
 * 
 * @return Vetor contendo os veículos associados à ordem.
 */
vector<Veiculo> Ordem::getVeiculos() const {
    return veiculos;
}

/**
 * Sobrecarga do operador de inserção para exibir informações da ordem.
 * 
 * @param os Stream de saída.
 * @param ordem Ordem cujas informações serão exibidas.
 * @return A stream de saída contendo as informações da ordem.
 */
ostream& operator<<(ostream& os, const Ordem& ordem) {
    os << endl;
    os << "Ordem ID: " << ordem.id << endl;
    os << "Local de Coleta: ";
    for (double d : ordem.localColeta) {
        os << d << " ";
    }
    os << endl;
    os << "Local de Entrega: ";
    for (double d : ordem.localEntrega) {
        os << d << " ";
    }
    os << endl;
    os << "Cliente: " << ordem.cliente->getNome() << endl;
    os << "Peso da Carga: " << ordem.pesoCarga << "kg" << endl;
    os << "Volume da Carga: " << ordem.volumeCarga << "m³" << endl;
    os << "Carga prioritária: " << (ordem.prioridade? "Sim" : "Não") << endl;
    os << "\nVeículo(s) realizando a entrega: " << endl;
    for (const Veiculo& veiculo : ordem.veiculos) {
        os << veiculo;
    }
    return os;
}

/**
 * Sobrecarga do operador de igualdade para comparar duas ordens.
 * 
 * @param outra Ordem a ser comparada.
 * @return True se as ordens são iguais, False caso contrário.
 */
bool Ordem::operator==(const Ordem& outra) {
    return id == outra.id;
}

/**
 * Valida o ID da ordem.
 * 
 * @param id ID da ordem a ser validado.
 * @return True se o ID é válido, False caso contrário.
 */
bool Ordem::validarId(const int& id) const {
    return id > 0;
}