#include "PedidoTransporte.h"
#include <iostream>
#include <string>

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

//Destrutor da classe
PedidoTransporte::~PedidoTransporte(){}

// Retorna o cliente do pedido
Cliente PedidoTransporte::getCliente() const {
    return cliente;
}

// Define o cliente do pedido
int PedidoTransporte::setCliente(const Cliente& cliente) {
    try
    {
        this->cliente = cliente;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao cadastrar o cliente" << endl;
        return 1;
    }
    
}

// Retorna o tipo de transporte
string PedidoTransporte::getTipoTransporte() const {
    return tipoTransporte;
}

// Define o tipo de transporte
int PedidoTransporte::setTipoTransporte(const string& tipoTransporte) {
    try
    {
        this->tipoTransporte = tipoTransporte;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao cadastrar o tipo de transporte!" << endl;
        return 1;
    }
    
}

// Retorna o local de coleta da carga
string PedidoTransporte::getLocalColeta() const {
    return localColeta;
}

// Define o local de coleta da carga
int PedidoTransporte::setLocalColeta(const string& localColeta) {
    try
    {
        this->localColeta = localColeta;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao registrar local da coleta!" << endl;
        return 1;
    }
    
}

// Retorna o local de entrega da carga
string PedidoTransporte::getLocalEntrega() const {
    return localEntrega;
}

// Define o local de entrega da carga
int PedidoTransporte::setLocalEntrega(const string& localEntrega) {
    try
    {   
        this->localEntrega = localEntrega;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao registrar local da entrega!" << endl;
        return 1;
    }
}

// Retorna o peso da carga
double PedidoTransporte::getPesoCarga() const {
    return pesoCarga;
}

// Define o peso da carga
int PedidoTransporte::setPesoCarga(const double& pesoCarga) {
    this->pesoCarga = pesoCarga;
    try
    {
        this->pesoCarga = pesoCarga;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao registrar peso da carga!" << endl;
        return 1;
    }
}

// Retorna o volume da carga
double PedidoTransporte::getVolumeCarga() const {
    return volumeCarga;
}

// Define o volume da carga
int PedidoTransporte::setVolumeCarga(const double& volumeCarga) {
    try
    {
        this->volumeCarga = volumeCarga;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao registrar volume da carga!" << endl;
        return 1;
    }
}

/*
 * Métodos auxiliares (para validar os dados de entrada)
*/
// Valida o peso da carga
bool PedidoTransporte::validarPesoCarga(const double& pesoCarga){
    return pesoCarga >= 0;
}

// Valida o volume da carga
bool PedidoTransporte::validarVolumeCarga(const double& volumeCarga){
    return volumeCarga >= 0;
}