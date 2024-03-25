#include "Cliente.h"

using namespace std;

/*
*   Este código código implementa os métodos da classe Cliente. 
*   O construtor Cliente::Cliente inicializa os atributos nome, 
*   endereco e telefone com os valores passados como parâmetros. 
*   Os métodos getNome, getEndereco e getTelefone retornam os 
*   valores dos atributos correspondentes. Os métodos setEndereco 
*   e setTelefone modificam os valores dos atributos endereco e 
*   telefone, respectivamente.
*/

// Construtor: inicializa um Cliente com nome, endereço e telefone especificados
Cliente::Cliente(string nome, string endereco, string telefone)
    : nome(nome), endereco(endereco), telefone(telefone) {}

// Retorna o nome do cliente
string Cliente::getNome() const {
    return nome;
}

// Define o nome do cliente
void Cliente::setNome(const string& nome) {
    this->nome = nome;
}

// Retorna o endereço do cliente
string Cliente::getEndereco() const {
    return endereco;
}

// Define o endereço do cliente
void Cliente::setEndereco(const string& endereco) {
    this->endereco = endereco;
}

// Retorna o telefone do cliente
string Cliente::getTelefone() const {
    return telefone;
}

// Define o telefone do cliente
void Cliente::setTelefone(const string& telefone) {
    this->telefone = telefone;
}
