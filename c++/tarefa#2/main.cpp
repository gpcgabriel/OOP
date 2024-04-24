#include <iostream>
#include <list>
#include "Cliente/Cliente.h"
#include "Veiculo/Veiculo.h"
#include "PedidoTransporte/PedidoTransporte.h"
#include "Veiculo/Carro/Carro.h"
#include "Veiculo/Caminhao/Caminhao.h"
using namespace std;

/*
*   Para uma melhor organização vamos dividir o código em algumas pastas que representam as classes utilizadas.
*   Cada pasta, contém o arquivo de cabeçalho (.h) e o arquivo que implementa os métodos e o contrutor da 
*   classe (.cpp). Aqui, no método main, vamos instanciar os objetos e passar como parâmetro os valores dos
*   atributos. Logo após, exibimos as informações referentes a cada classe, de acordo com a sua instância.
*/

int main() {
    // Definições iniciais (apenas para testar todas as classes)
    Cliente *meuCliente = new Cliente(100, "264.768.960-16", "Fulano", "fulano_de_tal@gmail.com", "Rua A, 350", "(55)34212474");
    Veiculo *meuVeiculo = new Veiculo(200, "ABC12345678901234", "SUV", 2020, "Rua", 200.00, false, true);
    PedidoTransporte *meuPedido = new PedidoTransporte(*meuCliente, "Rodoviário", "Alegrete", "Santa Maria", 500.0, 220.74);

    // Definindo os objetos dinâmicos que serão usados na lista
    Carro *meuCarro = new Carro(300, "ABC12345678901234", "Uno com escada", 2020, "Rua", 200.00, false, false);
    Caminhao *meuCaminhao = new Caminhao(400, "ABC12345678901234", "Volvo", 202, "Alegrete", 5700.9);

    list<Veiculo*> *frota = new list<Veiculo*>; // Criando a lista
    // Adicionando veículos
    frota->push_front(meuCarro);
    frota->push_front(meuCaminhao);

    //Removendo um veículo
    frota->pop_back();

    return 0;
}
