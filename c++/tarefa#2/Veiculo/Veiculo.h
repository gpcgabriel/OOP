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
    int id;            // Identificador do veículo

protected:
    string chassi;     // Atributo privado para armazenar o número do chassi
    string modelo;     // Atributo privado para armazenar o modelo do veículo
    int anoFabricacao; // Atributo privado para armazenar o ano de fabricação do veículo
    string localizacao;// Atributo privado para armazenar a localização atual do veículo
    double capacidadeCarga; // Atributo privado para armazenar a capacidade de carga do veículo em toneladas
    bool ativo; // Para verificar se o veiculo está em atividade
    bool disponivel; // Para verificar se o veículo está disponível 

public:
    // Construtor da classe Veiculo
    Veiculo(int id, string chassi, string modelo, int anoFabricacao, string localizacao, double capacidadeCarga, bool ativo, bool disponivel);
    ~Veiculo();

    // Métodos Getters e Setters para acessar e modificar os atributos privados
    string getChassi() const;   // Retorna o chassi do vaículo
    string getModelo() const;   // Retorna o modelo do vaículo
    int getAnoFabricacao() const;   // Retorna o ano de fabricação do vaículo
    string getLocalizacao() const;  // Retorna a localidade do vaículo
    double getCapacidadeCarga() const;  // Retorna a capacidade de carga que o veículo possui
    bool getVeiculoAtivo() const; // Retorna se o veículo está ativo
    bool getVeiculoDisponivel() const; // Retorna se o veículo está disponivel

    int setChassi(const string& chassi); // define o chassi do veículo
    int setModelo(const string& modelo);   // define o modelo do veículo
    int setAnoFabricacao(int anoFabricacao);   // define o ano de fabricação do veículo
    int setLocalizacao(const string& localizacao); // define a localizaçaõ do veículo
    int setCapacidadeCarga(const double& capacidadeCarga);    // define a capacidade de carga do veículo
    int setVeiculoAtivo (const bool& ativo);    // define a atividade do veículo
    int setVeiculoDisponivel (const bool& disponivel);    // define a disponibilidade do veículo

    /*
     * Métodos auxiliares para os setters (métodos de validação)
    */
    bool validarChassi(const string& chassi);   // Valida o chassi do veículo
    bool validarCapacidadeCarga(const double& capacidadeCarga); // valida a capacidade de carga do veículo
    bool validarAnoFabricacao(const int& anoFabricacao);    // valida o ano de fabricação do veículo
};

#endif // VEICULO_H
