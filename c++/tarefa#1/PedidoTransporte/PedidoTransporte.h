// PedidoTransporte.h - Declaração da classe PedidoTransporte

#ifndef PEDIDO_TRANSPORTE_H
#define PEDIDO_TRANSPORTE_H

#include "../Cliente/Cliente.h" // Inclui a definição da classe Cliente

#include <string>

using namespace std;

/*
*   Este código define a classe PedidoTransporte, que representa um pedido de transporte. 
*   Ele inclui o conteúdo do arquivo de cabeçalho "Cliente.class.h" para permitir a 
*   utilização da classe Cliente. A classe possui atributos privados para armazenar 
*   informações sobre o pedido de transporte, bem como métodos públicos para acessar e 
*   modificar essas informações.
*/

class PedidoTransporte {
private:
    Cliente cliente;            // Cliente que fez o pedido de transporte
    string tipoTransporte; // Tipo de transporte solicitado
    string localColeta;    // Local de coleta da carga
    string localEntrega;   // Local de entrega da carga
    double pesoCarga;           // Peso da carga (em toneladas)
    double volumeCarga;         // Volume da carga (em m³)

public:
    // Construtor: inicializa um PedidoTransporte com os parâmetros fornecidos
    PedidoTransporte(Cliente cliente, string tipoTransporte, string localColeta, string localEntrega, double pesoCarga, double volumeCarga);

    // Métodos getters para obter os atributos do pedido de transporte
    Cliente getCliente() const;                 // Retorna o cliente do pedido
    string getTipoTransporte() const;      // Retorna o tipo de transporte
    string getLocalColeta() const;         // Retorna o local de coleta da carga
    string getLocalEntrega() const;        // Retorna o local de entrega da carga
    double getPesoCarga() const;                // Retorna o peso da carga
    double getVolumeCarga() const;              // Retorna o volume da carga

    // Métodos setters para modificar os atributos do pedido de transporte
    void setCliente(const Cliente& cliente);          // Define o cliente do pedido
    void setTipoTransporte(const string& tipoTransporte); // Define o tipo de transporte
    void setLocalColeta(const string& localColeta);       // Define o local de coleta da carga
    void setLocalEntrega(const string& localEntrega);     // Define o local de entrega da carga
    void setPesoCarga(double pesoCarga);                      // Define o peso da carga
    void setVolumeCarga(double volumeCarga);                  // Define o volume da carga
};

#endif // PEDIDO_TRANSPORTE_H