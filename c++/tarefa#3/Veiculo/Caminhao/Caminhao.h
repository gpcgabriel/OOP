#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "../Veiculo.h"
#include <vector>

/**
 * @class Caminhao
 * Classe que representa um caminhão.
 * 
 * Esta classe herda da classe Veiculo e adiciona funcionalidades específicas de um caminhão, como o número de eixos.
 */
class Caminhao : public Veiculo{
    private:
        int numEixos; /**< Número de eixos do caminhão. */

    public:
        /**
         * Construtor da classe Caminhao.
         * @param id O ID do caminhão.
         * @param placa A placa do caminhão.
         * @param anoFabricacao O ano de fabricação do caminhão.
         * @param capacidadeCarga A capacidade de carga do caminhão.
         * @param capacidadeAtual A capacidade atual de carga do caminhão.
         * @param volumeCarga O volume de carga do caminhão.
         * @param volumeAtual O volume atual de carga do caminhão.
         * @param chassi O chassi do caminhão.
         * @param modelo O modelo do caminhão.
         * @param localizacao A localização atual do caminhão.
         * @param disponivel Indica se o caminhão está disponível ou não.
         * @param numEixos O número de eixos do caminhão.
         */
        Caminhao(int id, string placa, int anoFabricacao, float capacidadeCarga, float capacidadeAtual, float volumeCarga, float volumeAtual, string chassi, 
                string modelo, vector<double> localizacao, bool disponivel, int numEixos);

        /**
         * Construtor padrão da classe Caminhao.
         */
        Caminhao();

        /**
         * Destrutor da classe Caminhao.
         */
        ~Caminhao();

        /**
         * Obtém o número de eixos do caminhão.
         * @return O número de eixos do caminhão.
         */
        int getNumEixos() const;

        /**
         * Define o número de eixos do caminhão.
         * @param numEixos O número de eixos do caminhão.
         * @return O número de eixos definido.
         */
        int setNumEixos(const int& numEixos);

        /**
         * Sobrecarga do operador de inserção para impressão de objetos Caminhao.
         * @param os O stream de saída.
         * @param caminhao O objeto Caminhao a ser impresso.
         * @return O stream de saída.
         */
        friend ostream& operator<<(ostream& os, const Caminhao& caminhao);

        /**
         * Sobrecarga do operador de igualdade para comparação de objetos Caminhao.
         * @param outro O objeto Caminhao a ser comparado.
         * @return true se os caminhões forem iguais, false caso contrário.
         */
        bool operator==(const Caminhao& outro) const;
};

#endif // CAMINHAO_H
