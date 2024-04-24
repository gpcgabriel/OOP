#ifndef GERENCIADORVEICULO_H
#define GERENCIADORVEICULO_H

#include "../Veiculo/Veiculo.h" // Inclui a definição da classe Veiculo
#include "../Cliente/Cliente.h" // Inclui a definição da classe Cliente
#include <vector> // Inclui a biblioteca para utilizar vetores

class GerenciadorVeiculo {
private:
    vector<Veiculo*> veiculos; // Vetor de ponteiros para veículos

public:
    /**
     * Construtor da classe GerenciadorVeiculo.
     * 
     * @param veiculo Ponteiro para o veículo a ser adicionado ao gerenciador.
     */
    GerenciadorVeiculo(Veiculo *veiculo);

    /**
     * Destrutor da classe GerenciadorVeiculo.
     */
    ~GerenciadorVeiculo();

    /**
     * Adiciona um veículo ao gerenciador.
     * 
     * @param veiculo Ponteiro para o veículo a ser adicionado.
     * @return 1 se o veículo foi adicionado com sucesso, 0 caso contrário.
     */
    int adicionarVeiculo(Veiculo *veiculo);

    /**
     * Remove um veículo do gerenciador com base na placa.
     * 
     * @param placa Placa do veículo a ser removido.
     * @return 1 se o veículo foi removido com sucesso, 0 caso contrário.
     */
    int removerVeiculo(const string& placa);

    /**
     * Remove um veículo do gerenciador com base no ID.
     * 
     * @param id ID do veículo a ser removido.
     * @return 1 se o veículo foi removido com sucesso, 0 caso contrário.
     */
    int removerVeiculo(const int& id);

    /**
     * Obtém um veículo do gerenciador com base no ID.
     * 
     * @param id ID do veículo a ser obtido.
     * @return Ponteiro para o veículo se encontrado, nullptr caso contrário.
     */
    Veiculo* getVeiculo(const int& id) const;

    /**
     * Obtém um veículo do gerenciador com base na placa.
     * 
     * @param placa Placa do veículo a ser obtido.
     * @return Ponteiro para o veículo se encontrado, nullptr caso contrário.
     */
    Veiculo* getVeiculo(const string& placa) const;

    /**
     * Obtém todos os veículos do gerenciador.
     * 
     * @return Vetor contendo ponteiros para todos os veículos do gerenciador.
     */
    vector<Veiculo*> getVeiculos() const;

    /**
     * Obtém todos os veículos disponíveis no gerenciador.
     * 
     * @return Vetor contendo ponteiros para todos os veículos disponíveis no gerenciador.
     */
    vector<Veiculo*> getVeiculosDisponiveis() const;

    /**
     * Sobrecarga do operador de inserção para exibir informações do gerenciador de veículos.
     * 
     * @param os Stream de saída.
     * @param gv Gerenciador de veículos cujas informações serão exibidas.
     * @return A stream de saída contendo as informações do gerenciador de veículos.
     */
    friend ostream& operator<<(ostream& os, const GerenciadorVeiculo& gv);

    /**
     * Sobrecarga do operador de igualdade para comparar dois gerenciadores de veículos.
     * 
     * @param gv1 Primeiro gerenciador de veículos a ser comparado.
     * @return True se os gerenciadores de veículos são iguais, False caso contrário.
     */
    bool operator==(const GerenciadorVeiculo& gv1);
};

#endif // GERENCIADORVEICULO_H