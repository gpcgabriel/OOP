#ifndef ORDEM_H
#define ORDEM_H

#include "../Veiculo/Veiculo.h" // Inclusão do arquivo de cabeçalho da classe Veiculo
#include "../Cliente/Cliente.h"
#include <vector> // Inclusão da biblioteca vector

class Ordem {
    private:
        int id; // identificador da ordem
        vector<double> localColeta;
        vector<double> localEntrega;
        vector<Veiculo> veiculos; // Vetor de veículos que atenderão a ordem
        Cliente *cliente;
        float pesoCarga;
        float volumeCarga;
        bool prioridade;

        /**
         * Valida o ID da ordem.
         * @param id O ID a ser validado.
         * @return true se o ID for válido, false caso contrário.
         */
        bool validarId(const int& id) const;
    public:
        /**
         * Construtor da classe Ordem.
         * @param id O identificador da ordem.
         * @param localColeta O local de coleta.
         * @param localEntrega O local de entrega.
         * @param cliente O cliente associado à ordem.
         * @param pesoCarga O peso da carga.
         * @param volumeCarga O volume da carga.
         * @param prioridade Indica se a ordem tem prioridade.
         */
        Ordem(int id, vector<double> localColeta, vector<double> localEntrega, Cliente *cliente, float pesoCarga, float volumeCarga, bool prioridade);
        ~Ordem(); // Destrutor da classe Ordens

        /**
         * Define o ID da ordem.
         * @param id O novo ID.
         * @return 0 se o ID for definido com sucesso, -1 caso contrário.
         */
        int setId(const int& id); // Método de modificação do atributo id
        /**
         * Retorna o ID da ordem.
         * @return O ID da ordem.
         */
        int getId() const; // Método de acesso ao atributo id

        /**
         * Define o local de coleta da ordem.
         * @param localColeta O novo local de coleta.
         * @return 0 se o local de coleta for definido com sucesso, -1 caso contrário.
         */
        int setLocalColeta(vector<double> localColeta);
        /**
         * Retorna o local de coleta da ordem.
         * @return O local de coleta da ordem.
         */
        vector<double> getLocalColeta() const;

        /**
         * Define o local de entrega da ordem.
         * @param localEntrega O novo local de entrega.
         * @return 0 se o local de entrega for definido com sucesso, -1 caso contrário.
         */
        int setLocalEntrega(vector<double> localEntrega);
        /**
         * Retorna o local de entrega da ordem.
         * @return O local de entrega da ordem.
         */
        vector<double> getLocalEntrega() const;

        /**
         * Define o cliente da ordem.
         * @param cliente O novo cliente.
         * @return 0 se o cliente for definido com sucesso, -1 caso contrário.
         */
        int setCliente(Cliente *cliente);
        /**
         * Retorna o cliente da ordem.
         * @return O cliente da ordem.
         */
        Cliente* getCliente() const;

        /**
         * Define o peso da carga da ordem.
         * @param pesoCarga O novo peso da carga.
         * @return 0 se o peso da carga for definido com sucesso, -1 caso contrário.
         */
        int setPesoCarga(const float& pesoCarga);
        /**
         * Retorna o peso da carga da ordem.
         * @return O peso da carga da ordem.
         */
        float getPesoCarga() const;

        /**
         * Define o volume da carga da ordem.
         * @param volumeCarga O novo volume da carga.
         * @return 0 se o volume da carga for definido com sucesso, -1 caso contrário.
         */
        int setVolumeCarga(const float& volumeCarga);
        /**
         * Retorna o volume da carga da ordem.
         * @return O volume da carga da ordem.
         */
        float getVolumeCarga() const;

        /**
         * Define se a ordem tem prioridade.
         * @param prioridade Indica se a ordem tem prioridade.
         * @return 0 se a prioridade for definida com sucesso, -1 caso contrário.
         */
        int setPrioridade(const bool& prioridade);
        /**
         * Retorna se a ordem tem prioridade.
         * @return true se a ordem tem prioridade, false caso contrário.
         */
        bool getPrioridade() const;

        /**
         * Adiciona um veículo ao vetor de veículos da ordem.
         * @param veiculo O veículo a ser adicionado.
         * @return 0 se o veículo for adicionado com sucesso, -1 caso contrário.
         */
        int setVeiculo(Veiculo& veiculo); // Método para adicionar veículos ao vetor de veículos
        /**
         * Adiciona veículos ao vetor de veículos da ordem.
         * @param veiculos Os veículos a serem adicionados.
         * @return 0 se os veículos forem adicionados com sucesso, -1 caso contrário.
         */
        int setVeiculos(const vector<Veiculo>& veiculos); // Método para adicionar veículos ao vetor de veículos

        /**
         * Retorna o vetor de veículos da ordem.
         * @return O vetor de veículos da ordem.
         */
        vector<Veiculo> getVeiculos() const; // Método para acesso ao vetor de veículos

        // Declaração da função amiga para a sobrecarga do operador <<
        friend ostream& operator<<(ostream& os, const Ordem& ordem);

        // Sobrecarga do operador ==
        bool operator==(const Ordem& outra);
};
#endif // ORDEM_H