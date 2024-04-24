#ifndef ROTEIRIZACAO_H
#define ROTEIRIZACAO_H

#include "../GerenciadorVeiculo/GerenciadorVeiculo.h"
#include "../Ordem/Ordem.h"
#include <vector>
#include <iostream>

/**
 * Classe responsável por realizar a roteirização das ordens de entrega.
 */
class Roteirizacao {
public:
    /**
     * Construtor da classe Roteirizacao.
     * @param ordem Ponteiro para o vetor de ordens.
     * @param veiculos Ponteiro para o gerenciador de veículos.
     */
    Roteirizacao(std::vector<Ordem>* ordem, GerenciadorVeiculo* veiculos);

    /**
     * Destrutor da classe Roteirizacao.
     */
    ~Roteirizacao();

    /**
     * Sobrecarga do operador de inserção para impressão das ordens.
     * @param os O fluxo de saída.
     * @param roteirizacao A instância da classe Roteirizacao.
     * @return O fluxo de saída modificado.
     */
    friend std::ostream& operator<<(std::ostream& os, const Roteirizacao& roteirizacao);

    /**
     * Sobrecarga do operador de igualdade para comparação de igualdade entre duas instâncias da classe Roteirizacao.
     * @param outra A outra instância da classe Roteirizacao.
     * @return true se as instâncias forem iguais, false caso contrário.
     */
    bool operator==(const Roteirizacao& outra) const;

private:
    std::vector<Ordem>* ordem; // Ponteiro para o vetor de ordens.
    GerenciadorVeiculo* veiculos; // Ponteiro para o gerenciador de veículos.

    /**
     * Ordena o vetor de ordens por prioridade.
     */
    void definirOrdemAtendimento();

    /**
     * Ordena o vetor de veículos usando o algoritmo QuickSort.
     * @param veiculos O vetor de ponteiros para veículos a ser ordenado.
     * @param low Índice inicial.
     * @param high Índice final.
     */
    void quickSort(std::vector<Veiculo*>& veiculos, int low, int high);

    /**
     * Função auxiliar para particionar o vetor durante o QuickSort.
     * @param veiculos O vetor de ponteiros para veículos a ser ordenado.
     * @param low Índice inicial.
     * @param high Índice final.
     * @return O índice do pivô.
     */
    int partition(std::vector<Veiculo*>& veiculos, int low, int high);

    /**
     * Ordena o vetor de veículos usando o algoritmo QuickSort.
     * @param veiculos O vetor de ponteiros para veículos a ser ordenado.
     */
    void quickSort(std::vector<Veiculo*>& veiculos);

    /**
     * Aloca veículos para as ordens.
     */
    void alocarVeiculosParaOrdem();
};

#endif // ROTEIRIZACAO_H