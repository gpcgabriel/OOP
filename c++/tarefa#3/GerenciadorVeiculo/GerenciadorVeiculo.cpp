#include "../Veiculo/Veiculo.h" // Inclui a definição da classe Veiculo
#include "GerenciadorVeiculo.h" // Inclui a definição da classe GerenciadorVeiculo
#include <vector> // Inclui a biblioteca para utilizar vetores
#include <iostream> // Inclui a biblioteca para entrada e saída padrão

using namespace std;

/**
 * Construtor da classe GerenciadorVeiculo.
 * 
 * @param veiculo Ponteiro para o veículo a ser adicionado ao gerenciador.
 */
GerenciadorVeiculo::GerenciadorVeiculo(Veiculo *veiculo) {
    this->veiculos.push_back(veiculo);
}

/**
 * Destrutor da classe GerenciadorVeiculo.
 */
GerenciadorVeiculo::~GerenciadorVeiculo(){}

/**
 * Adiciona um veículo ao gerenciador.
 * 
 * @param veiculo Ponteiro para o veículo a ser adicionado.
 * @return 1 se o veículo foi adicionado com sucesso, 0 caso contrário.
 */
int GerenciadorVeiculo::adicionarVeiculo(Veiculo *veiculo){
    this->veiculos.push_back(veiculo);
    return 1;
}

/**
 * Remove um veículo do gerenciador com base no ID.
 * 
 * @param id ID do veículo a ser removido.
 * @return 1 se o veículo foi removido com sucesso, 0 caso contrário.
 */
int GerenciadorVeiculo::removerVeiculo(const int& id){
    for(int i = 0; i < this->veiculos.size(); i++){
        if(this->veiculos[i]->getId() == id){
            this->veiculos.erase(this->veiculos.begin() + i);
            return 1;
        }
    }
    return 0;
}

/**
 * Remove um veículo do gerenciador com base na placa.
 * 
 * @param placa Placa do veículo a ser removido.
 * @return 1 se o veículo foi removido com sucesso, 0 caso contrário.
 */
int GerenciadorVeiculo::removerVeiculo(const string& placa){
    for(int i = 0; i < this->veiculos.size(); i++){
        if(this->veiculos[i]->getPlaca() == placa){
            this->veiculos.erase(this->veiculos.begin() + i);
            return 1;
        }
    }
    return 0;
}

/**
 * Obtém um veículo do gerenciador com base no ID.
 * 
 * @param id ID do veículo a ser obtido.
 * @return Ponteiro para o veículo se encontrado, nullptr caso contrário.
 */
Veiculo* GerenciadorVeiculo::getVeiculo(const int& id) const{
    for(int i = 0; i < this->veiculos.size(); i++){
        if(this->veiculos[i]->getId() == id){
            return this->veiculos[i];
        }
    }
    return nullptr;
}

/**
 * Obtém um veículo do gerenciador com base na placa.
 * 
 * @param placa Placa do veículo a ser obtido.
 * @return Ponteiro para o veículo se encontrado, nullptr caso contrário.
 */
Veiculo* GerenciadorVeiculo::getVeiculo(const string& placa) const{
    for(int i = 0; i < this->veiculos.size(); i++){
        if(this->veiculos[i]->getPlaca() == placa){
            return this->veiculos[i];
        }
    }
    return nullptr;
}

/**
 * Obtém todos os veículos do gerenciador.
 * 
 * @return Vetor contendo ponteiros para todos os veículos do gerenciador.
 */
vector<Veiculo*> GerenciadorVeiculo::getVeiculos() const{
    return this->veiculos;
}

/**
 * Obtém todos os veículos disponíveis no gerenciador.
 * 
 * @return Vetor contendo ponteiros para todos os veículos disponíveis no gerenciador.
 */
vector<Veiculo*> GerenciadorVeiculo::getVeiculosDisponiveis() const{
    vector<Veiculo*> veiculosDisponiveis;
    for(int i = 0; i < this->veiculos.size(); i++){
        if(this->veiculos[i]->getDisponibilidade()){
            veiculosDisponiveis.push_back(this->veiculos[i]);
        }
    }
    return veiculosDisponiveis;
}

/**
 * Sobrecarga do operador de inserção para exibir informações do gerenciador de veículos.
 * 
 * @param os Stream de saída.
 * @param gv Gerenciador de veículos cujas informações serão exibidas.
 * @return A stream de saída contendo as informações do gerenciador de veículos.
 */
ostream& operator<<(ostream& os, const GerenciadorVeiculo& gv) {
    for (const auto& veiculo : gv.veiculos) {
        os << *veiculo << endl;
        cout << "##############" <<endl;
    }
    return os;
}

/**
 * Sobrecarga do operador de igualdade para comparar dois gerenciadores de veículos.
 * 
 * @param gv1 Primeiro gerenciador de veículos a ser comparado.
 * @return True se os gerenciadores de veículos são iguais, False caso contrário.
 */
bool GerenciadorVeiculo::operator==(const GerenciadorVeiculo& gv1){
    if(this->getVeiculos().size() != gv1.getVeiculos().size()){
        return false;
    }
    for(Veiculo *veiculo : this->getVeiculos()){
        for (int i=0; i < gv1.getVeiculos().size(); i++){
            if(veiculo->getId() != gv1.getVeiculos()[i]->getId() && i == gv1.getVeiculos().size()-1){
                return false;
            }
        }
    }
    return true;
}