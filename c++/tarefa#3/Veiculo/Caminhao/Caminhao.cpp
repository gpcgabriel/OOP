#include "Caminhao.h"
#include "../Veiculo.h"
#include <iostream>

using namespace std;

/**
 * Construtor parametrizado da classe Caminhao.
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
Caminhao::Caminhao(int id, string placa, int anoFabricacao, float capacidadeCarga, float capacidadeAtual, float volumeCarga, float volumeAtual, string chassi, 
                    string modelo, vector<double> localizacao, bool disponivel, int numEixos) : 
                Veiculo(id, placa, anoFabricacao, capacidadeCarga, capacidadeAtual, volumeCarga, volumeAtual, chassi, modelo, localizacao, disponivel) {
                        this->numEixos = numEixos;
}

/**
 * Construtor padrão da classe Caminhao.
 */
Caminhao::Caminhao() { }

/**
 * Destrutor da classe Caminhao.
 */
Caminhao::~Caminhao() { }

/**
 * Obtém o número de eixos do caminhão.
 * @return O número de eixos do caminhão.
 */
int Caminhao::getNumEixos() const {
    return this->numEixos;
}

/**
 * Define o número de eixos do caminhão.
 * @param numEixos O número de eixos do caminhão.
 * @return O número de eixos definido.
 */
int Caminhao::setNumEixos(const int& numEixos) {
    this->numEixos = numEixos;
    return 1;
}

/**
 * Sobrecarga do operador de inserção para impressão de objetos Caminhao.
 * @param os O stream de saída.
 * @param caminhao O objeto Caminhao a ser impresso.
 * @return O stream de saída.
 */
ostream& operator<<(ostream& os, const Caminhao& caminhao) {
    os << "ID: " << caminhao.getId() << endl;
    os << "Placa: " << caminhao.getPlaca() << endl;
    os << "Ano de Fabricação: " << caminhao.anoFabricacao << endl;
    os << "Capacidade de Carga: " << caminhao.capacidadeCarga << "kg" << endl;
    os << "Capacidade Atual: " << caminhao.capacidadeAtual << "kg" << endl;
    os << "Chassi: " << caminhao.chassi << endl;
    os << "Modelo: " << caminhao.modelo << endl;
    os << "Volume de Carga: " << caminhao.volumeCarga << "m³" << endl;
    os << "Volume Atual: " << caminhao.volumeAtual << "m³" << endl;
    os << "Disponibilidade: " << (caminhao.disponivel ? "disponível" : "indisponível") << endl;
    os << "Localização: ";
    for (double elemento : caminhao.localizacao) {
        os <<  elemento << " ";
    }
    os << endl;
    os << "Número de Eixos: " << caminhao.numEixos << endl;
    return os;
}

/**
 * Sobrecarga do operador de igualdade para comparação de objetos Caminhao.
 * @param outro O objeto Caminhao a ser comparado.
 * @return true se os caminhões forem iguais, false caso contrário.
 */
bool Caminhao::operator==(const Caminhao& outro) const {
    return (this->getId() == outro.getId() &&
            this->getPlaca() == outro.getPlaca() &&
            this->anoFabricacao == outro.anoFabricacao &&
            this->capacidadeCarga == outro.capacidadeCarga &&
            this->chassi == outro.chassi &&
            this->modelo == outro.modelo &&
            this->volumeCarga == outro.volumeCarga &&
            this->disponivel == outro.disponivel &&
            this->localizacao == outro.localizacao &&
            this->numEixos == outro.numEixos);
}