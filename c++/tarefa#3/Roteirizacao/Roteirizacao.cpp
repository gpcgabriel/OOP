#include "../GerenciadorVeiculo/GerenciadorVeiculo.h"
#include "../Ordem/Ordem.h"
#include "Roteirizacao.h"
#include <vector>
#include <algorithm> // Para a método sort

using namespace std;

/**
 * Construtor da classe Roteirizacao.
 * @param ordem Ponteiro para o vetor de ordens.
 * @param veiculos Ponteiro para o gerenciador de veículos.
 */
Roteirizacao::Roteirizacao(vector<Ordem>* ordem, GerenciadorVeiculo* veiculos) : ordem(ordem), veiculos(veiculos) {
    this->definirOrdemAtendimento();
    this->alocarVeiculosParaOrdem();
}

/**
 * Destrutor da classe Roteirizacao.
 */
Roteirizacao::~Roteirizacao(){}

/**
 * Ordena o vetor de ordens por prioridade.
 */
void Roteirizacao::definirOrdemAtendimento() {
    sort(ordem->begin(), ordem->end(), [](const Ordem& ordem1, const Ordem& ordem2) {
        return ordem1.getPrioridade() > ordem2.getPrioridade();
    });
}

/**
 * Ordena o vetor de veículos usando o algoritmo QuickSort.
 * @param veiculos O vetor de ponteiros para veículos a ser ordenado.
 */
void Roteirizacao::quickSort(vector<Veiculo*>& veiculos, int low, int high) {
    if (low < high) {
        int pi = partition(veiculos, low, high);
        quickSort(veiculos, low, pi - 1);
        quickSort(veiculos, pi + 1, high);
    }
}

/**
 * Método auxiliar para particionar o vetor durante o QuickSort.
 */
int Roteirizacao::partition(vector<Veiculo*>& veiculos, int low, int high) {
    float pivot = veiculos[high]->getCapacidadeCarga() / veiculos[high]->getVolumeCarga();
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (veiculos[j]->getCapacidadeCarga() / veiculos[j]->getVolumeCarga() < pivot) {
            ++i;
            swap(veiculos[i], veiculos[j]);
        }
    }
    swap(veiculos[i + 1], veiculos[high]);
    return i + 1;
}

/**
 * Ordena o vetor de veículos usando o algoritmo QuickSort.
 * @param veiculos O vetor de ponteiros para veículos a ser ordenado.
 */
void Roteirizacao::quickSort(vector<Veiculo*>& veiculos) {
    int n = veiculos.size();
    quickSort(veiculos, 0, n - 1);
}

/**
 * Aloca veículos para as ordens.
 */
void Roteirizacao::alocarVeiculosParaOrdem() {
    vector<Veiculo*> veiculos = this->veiculos->getVeiculos();
    this->quickSort(veiculos);

    for(Ordem& ordem : *this->ordem) {
        for(Veiculo *v : veiculos) {
            if((v->getCapacidadeAtual() >= ordem.getPesoCarga()) && (v->getVolumeAtual() >= ordem.getVolumeCarga())) {
                ordem.setVeiculo({*(v)});
                v->alocarPesoCarga(ordem.getPesoCarga());
                v->alocarVolumeCarga(ordem.getVolumeCarga());

                if(v->getCapacidadeAtual() == 0 || v->getVolumeAtual() == 0) {
                    v->setDisponibilidade(false);
                }

                break;
            }
        }
    }
}

/**
 * Sobrecarga do operador << para impressão das ordens.
 * @param os O fluxo de saída.
 * @param roteirizacao A instância da classe Roteirizacao.
 * @return O fluxo de saída modificado.
 */
ostream& operator<<(ostream& os, const Roteirizacao& roteirizacao) {
    for(const Ordem& ordem : *roteirizacao.ordem){
        os << ordem;
        os << "################################################################################" << endl;
    }
    return os;
}

/**
 * Sobrecarga do operador == para comparação de igualdade entre duas instâncias da classe Roteirizacao.
 * @param outra A outra instância da classe Roteirizacao.
 * @return true se as instâncias forem iguais, false caso contrário.
 */
bool Roteirizacao::operator==(const Roteirizacao& outra) const {
    return (ordem == outra.ordem) && (veiculos == outra.veiculos);
}