#include <iostream>
#include "Veiculo/Veiculo.h"
#include "Cliente/Cliente.h"
#include "PedidoTransporte/PedidoTransporte.h"

using namespace std;

/*
*   Para uma melhor organização vamos dividir o código em algumas pastas que representam as classes utilizadas.
*   Cada pasta, contém o arquivo de cabeçalho (.h) e o arquivo que implementa os métodos e o contrutor da 
*   classe (.cpp). Aqui, no método main, vamos instanciar os objetos e passar como parâmetro os valores dos
*   atributos. Logo após, exibimos as informações referentes a cada classe, de acordo com a sua instância.
*/

int main() {
    // Criando uma instância de Veiculo
    Veiculo veiculo("ABC123", "Caminhão", 2020, "Alegrete", 8.0);

    // Criando uma instância de Cliente
    Cliente cliente("Marcelo", "Centro, 321", "(55)9 9999-5474");

    // Criando uma instância de PedidoTransporte com o cliente e veículo criados
    PedidoTransporte pedido(cliente, "Carga pesada", "Alegrete", "Panambi", 8.0, 42.0);

    // Exibindo informações do veículo
    cout << "Informacoes do Veiculo:" << endl;
    cout << "Chassi: " << veiculo.getChassi() << endl;
    cout << "Modelo: " << veiculo.getModelo() << endl;
    cout << "Ano de Fabricacao: " << veiculo.getAnoFabricacao() << endl;
    cout << "Localizacao: " << veiculo.getLocalizacao() << endl;
    cout << "Capacidade de Carga: " << veiculo.getCapacidadeCarga() << "t." << endl;
    cout << "====================================================================================\n\n";

    // Exibindo informações do cliente
    cout << "Informacoes do Cliente:" << endl;
    cout << "Nome: " << cliente.getNome() << endl;
    cout << "Endereco: " << cliente.getEndereco() << endl;
    cout << "Telefone: " << cliente.getTelefone() << endl;
    cout << "====================================================================================\n\n";

    // Exibindo informações do pedido de transporte
    cout << "Informacoes do Pedido de Transporte:" << endl;
    cout << "Tipo de Transporte: " << pedido.getTipoTransporte() << endl;
    cout << "Local de Coleta: " << pedido.getLocalColeta() << endl;
    cout << "Local de Entrega: " << pedido.getLocalEntrega() << endl;
    cout << "Peso da Carga: " << pedido.getPesoCarga() << "t." << endl;
    cout << "Volume da Carga: " << pedido.getVolumeCarga() << "m³" << endl;

    return 0;
}
