#include "Carro.h"
#include <iostream>

using namespace std;

/**
 * Construtor parametrizado da classe Carro.
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
Carro::Carro(int id, string placa, int anoFabricacao, float capacidadeCarga, float capacidadeAtual, float volumeCarga, float volumeAtual, string chassi, 
                string modelo, vector<double> localizacao, bool disponivel, int numPortas) : 
                Veiculo(id, placa, anoFabricacao, capacidadeCarga, capacidadeAtual, volumeCarga, volumeAtual, chassi, modelo, localizacao, disponivel) {
                        this->numPortas = numPortas;
}

/**
 * Construtor padrão da classe Carro.
 */
Carro::Carro() { }

/**
 * Destrutor da classe Carro.
 */
Carro::~Carro() { }

/**
 * Obtém o número de portas do carro.
 * @return O número de portas do carro.
 */
int Carro::getNumPortas() const {
    return this->numPortas;
}

/**
 * Define o número de portas do carro.
 * @param numPortas O número de portas do carro.
 * @return O número de portas definido.
 */
int Carro::setNumPortas(const int& numPortas) {
    this->numPortas = numPortas;
    return 1;
}

/**
 * Sobrecarga do operador de inserção para impressão de objetos Carro.
 * @param os O stream de saída.
 * @param carro O objeto Carro a ser impresso.
 * @return O stream de saída.
 */
ostream& operator<<(ostream& os, const Carro& carro) {
    os << "ID: " << carro.getId() << endl;
    os << "Placa: " << carro.getPlaca() << endl;
    os << "Ano de Fabricação: " << carro.anoFabricacao << endl;
    os << "Capacidade de Carga: " << carro.capacidadeCarga << "kg" << endl;
    os << "Capacidade Atual: " << carro.capacidadeAtual << "kg" << endl;
    os << "Chassi: " << carro.chassi << endl;
    os << "Modelo: " << carro.modelo << endl;
    os << "Volume de Carga: " << carro.volumeCarga << "m³" << endl;
    os << "Volume Atual: " << carro.volumeAtual << "m³" << endl;
    os << "Disponibilidade: " << (carro.disponivel ? "disponível" : "indisponível") << endl;
    os << "Localização: ";
    for (double elemento : carro.localizacao) {
        os <<  elemento << " ";
    }
    os << endl;
    os << "Número de Portas: " << carro.numPortas << endl;
    return os;
}

/**
 * Sobrecarga do operador de igualdade para comparação de objetos Carro.
 * @param outro O objeto Carro a ser comparado.
 * @return true se os carros forem iguais, false caso contrário.
 */
bool Carro::operator==(const Carro& outro) const {
    return (this->getId() == outro.getId() &&
            this->getPlaca() == outro.getPlaca() &&
            this->anoFabricacao == outro.anoFabricacao &&
            this->capacidadeCarga == outro.capacidadeCarga &&
            this->chassi == outro.chassi &&
            this->modelo == outro.modelo &&
            this->volumeCarga == outro.volumeCarga &&
            this->localizacao == outro.localizacao &&
            this->disponivel == outro.disponivel &&
            this->numPortas == outro.numPortas);
}