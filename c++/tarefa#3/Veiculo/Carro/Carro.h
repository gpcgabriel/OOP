#ifndef CARRO_H
#define CARRO_H

#include "../Veiculo.h"
#include <vector>
#include <string>

/**
 * 
 * Esta classe herda da classe Veiculo e adiciona funcionalidades específicas de um carro, como o número de portas.
 *
 */
class Carro : public Veiculo{
    private:
        int numPortas; /**< Número de portas do carro. */

    public:
        /**
         * Construtor da classe Carro.
         * @param id O ID do carro.
         * @param placa A placa do carro.
         * @param anoFabricacao O ano de fabricação do carro.
         * @param capacidadeCarga A capacidade de carga do carro.
         * @param capacidadeAtual A capacidade atual de carga do carro.
         * @param volumeCarga O volume de carga do carro.
         * @param volumeAtual O volume atual de carga do carro.
         * @param chassi O chassi do carro.
         * @param modelo O modelo do carro.
         * @param localizacao A localização atual do carro.
         * @param disponivel Indica se o carro está disponível ou não.
         * @param numPortas O número de portas do carro.
         */
        Carro(int id, string placa, int anoFabricacao, float capacidadeCarga, float capacidadeAtual, float volumeCarga, float volumeAtual, string chassi, 
                string modelo, vector<double> localizacao, bool disponivel, int numPortas);

        /**
         * Construtor padrão da classe Carro.
         */
        Carro();

        /**
         * Destrutor da classe Carro.
         */
        ~Carro();

        /**
         * Obtém o número de portas do carro.
         * @return O número de portas do carro.
         */
        int getNumPortas() const;

        /**
         * Define o número de portas do carro.
         * @param numPortas O número de portas do carro.
         * @return O número de portas definido.
         */
        int setNumPortas(const int& numPortas);

        /**
         * Sobrecarga do operador de inserção para impressão de objetos Carro.
         * @param os O stream de saída.
         * @param carro O objeto Carro a ser impresso.
         * @return O stream de saída.
         */
        friend ostream& operator<<(ostream& os, const Carro& carro);

        /**
         * Sobrecarga do operador de igualdade para comparação de objetos Carro.
         * @param outro O objeto Carro a ser comparado.
         * @return true se os carros forem iguais, false caso contrário.
         */
        bool operator==(const Carro& outro) const;
};

#endif // CARRO_H