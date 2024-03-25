#include "PedidoTransporte.h"

using namespace std;  // Usa o namespace padrão std

/*
*   Neste trecho de código, estamos implementando os métodos da classe PedidoTransporte. 
*   O construtor PedidoTransporte::PedidoTransporte inicializa os atributos da classe 
*   com os valores passados como parâmetros. Os métodos getCliente, getTipoTransporte, 
*   getLocalColeta, getLocalEntrega, getPesoCarga e getVolumeCarga retornam os valores 
*   dos atributos correspondentes. Os métodos setTipoTransporte, setLocalColeta e 
*   setLocalEntrega modificam os valores dos atributos correspondentes.
*/

// Construtor: inicializa um PedidoTransporte com os parâmetros fornecidos
PedidoTransporte::PedidoTransporte(Cliente cliente, string tipoTransporte, string localColeta, string localEntrega, double pesoCarga, double volumeCarga)
    : cliente(cliente), tipoTransporte(tipoTransporte), localColeta(localColeta), localEntrega(localEntrega), pesoCarga(pesoCarga), volumeCarga(volumeCarga) {}

// Retorna o cliente do pedido
Cliente PedidoTransporte::getCliente() const {
    return cliente;
}

// Define o cliente do pedido
void PedidoTransporte::setCliente(const Cliente& cliente) {
    this->cliente = cliente;
}

// Retorna o tipo de transporte
string PedidoTransporte::getTipoTransporte() const {
    return tipoTransporte;
}

// Define o tipo de transporte
void PedidoTransporte::setTipoTransporte(const string& tipoTransporte) {
    this->tipoTransporte = tipoTransporte;
}

// Retorna o local de coleta da carga
string PedidoTransporte::getLocalColeta() const {
    return localColeta;
}

// Define o local de coleta da carga
void PedidoTransporte::setLocalColeta(const string& localColeta) {
    this->localColeta = localColeta;
}

// Retorna o local de entrega da carga
string PedidoTransporte::getLocalEntrega() const {
    return localEntrega;
}

// Define o local de entrega da carga
void PedidoTransporte::setLocalEntrega(const string& localEntrega) {
    this->localEntrega = localEntrega;
}

// Retorna o peso da carga
double PedidoTransporte::getPesoCarga() const {
    return pesoCarga;
}

// Define o peso da carga
void PedidoTransporte::setPesoCarga(double pesoCarga) {
    this->pesoCarga = pesoCarga;
}

// Retorna o volume da carga
double PedidoTransporte::getVolumeCarga() const {
    return volumeCarga;
}

// Define o volume da carga
void PedidoTransporte::setVolumeCarga(double volumeCarga) {
    this->volumeCarga = volumeCarga;
}