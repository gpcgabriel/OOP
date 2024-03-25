#ifndef VEICULO_H  // Diretiva de pré-processamento: evita múltiplas inclusões do mesmo arquivo de cabeçalho
#define VEICULO_H

#include <string>  // Inclusão da biblioteca string

using namespace std;  // Usa o namespace padrão std
/*
*    Este código define a classe Veiculo, que representa um veículo. 
*    A classe possui atributos privados para armazenar informações 
*    sobre o veículo, como o número do chassi, modelo, localização, 
*    ano de fabricação e capacidade de carga. Além disso, possui um 
*    construtor que permite inicializar os atributos durante a criação 
*    de um objeto. Também possui métodos públicos para acessar (getters) 
*    e modificar (setter) os atributos do veículo.   
*/

class Veiculo {  // Definição da classe Veiculo
private:
    string chassi;  // Atributo privado para armazenar o número do chassi
    string modelo;  // Atributo privado para armazenar o modelo do veículo
    int anoFabricacao;   // Atributo privado para armazenar o ano de fabricação do veículo
    string localizacao;  // Atributo privado para armazenar a localização atual do veículo
    double capacidadeCarga;   // Atributo privado para armazenar a capacidade de carga do veículo em toneladas

public:
    // Construtor da classe Veiculo
    Veiculo(string chassi, string modelo, int anoFabricacao, string localizacao, double capacidadeCarga);

    // Métodos Getters e Setters para acessar e modificar os atributos privados
    string getChassi() const;
    void setChassi(const string& chassi);

    string getModelo() const;
    void setModelo(const string& modelo);

    int getAnoFabricacao() const;
    void setAnoFabricacao(int anoFabricacao);

    string getLocalizacao() const;
    void setLocalizacao(const string& localizacao);

    double getCapacidadeCarga() const;
    void setCapacidadeCarga(double capacidadeCarga);
};

#endif // VEICULO_H
