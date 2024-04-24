#include "Cliente.h"
#include <regex>
#include <vector>

using namespace std;

/**
 * Construtor da classe Cliente.
 * 
 * @param id Identificador do cliente.
 * @param cpf CPF do cliente.
 * @param nome Nome do cliente.
 * @param endereco Vetor de coordenadas geográficas do endereço do cliente.
 * @param telefone Número de telefone do cliente.
 */
Cliente::Cliente(int id, string cpf, string nome, vector<double> endereco, string telefone) {
    this->id = id;
    this->cpf = cpf;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
}

/**
 * Construtor padrão da classe Cliente.
 */
Cliente::Cliente() { }

/**
 * Destrutor da classe Cliente.
 */
Cliente::~Cliente() { }

/**
 * Obtém o identificador do cliente.
 * 
 * @return O identificador do cliente.
 */
int Cliente::getId() const {
    return this->id;
}

/**
 * Define o identificador do cliente.
 * 
 * @param id O identificador a ser atribuído ao cliente.
 * @return 1 se o identificador foi definido com sucesso, 0 caso contrário.
 */
int Cliente::setId(const int& id) {
    this->id = id;
    return 1;
}

/**
 * Obtém o CPF do cliente.
 * 
 * @return O CPF do cliente.
 */
string Cliente::getCpf() const {
    return this->cpf;
}

/**
 * Define o CPF do cliente.
 * 
 * @param cpf O CPF a ser atribuído ao cliente.
 * @return 1 se o CPF foi definido com sucesso, 0 caso contrário.
 */
int Cliente::setCpf(const string& cpf) {
    if (!validarCpf(cpf)) {
        return 0;
    }
    this->cpf = cpf;
    return 1;
}

/**
 * Obtém o nome do cliente.
 * 
 * @return O nome do cliente.
 */
string Cliente::getNome() const {
    return this->nome;
}

/**
 * Define o nome do cliente.
 * 
 * @param nome O nome a ser atribuído ao cliente.
 * @return 1 se o nome foi definido com sucesso, 0 caso contrário.
 */
int Cliente::setNome(const string& nome) {
    if (!validarNome(nome)) {
        return 0;
    }
    this->nome = nome;
    return 1;
}

/**
 * Obtém o endereço do cliente.
 * 
 * @return O vetor de coordenadas geográficas do endereço do cliente.
 */
vector<double> Cliente::getEndereco() const {
    return this->endereco;
}

/**
 * Define o endereço do cliente.
 * 
 * @param endereco O vetor de coordenadas geográficas a ser atribuído ao endereço do cliente.
 * @return 1 se o endereço foi definido com sucesso, 0 caso contrário.
 */
int Cliente::setEndereco(const vector<double>& endereco) {
    if (!validarEndereco(endereco)) {
        return 0;
    }
    this->endereco = endereco;
    return 1;
}

/**
 * Obtém o número de telefone do cliente.
 * 
 * @return O número de telefone do cliente.
 */
string Cliente::getTelefone() const {
    return this->telefone;
}

/**
 * Define o número de telefone do cliente.
 * 
 * @param telefone O número de telefone a ser atribuído ao cliente.
 * @return 1 se o número de telefone foi definido com sucesso, 0 caso contrário.
 */
int Cliente::setTelefone(const string& telefone) {
    if (validarTelefone(telefone)) {
        this->telefone = telefone;
        return 1;
    }
    return 0;
}

/**
 * Sobrecarga do operador de inserção para exibir informações do cliente.
 * 
 * @param os Stream de saída.
 * @param cliente Cliente cujas informações serão exibidas.
 * @return A stream de saída contendo as informações do cliente.
 */
ostream &operator<<(ostream &os, const Cliente &cliente) {
    os << "ID: " << cliente.id << endl;
    os << "CPF: " << cliente.cpf << endl;
    os << "Nome: " << cliente.nome << endl;
    os << "Endereço: ";
    for (double elemento : cliente.endereco) {
        os << elemento << " ";
    }
    os << endl;
    os << "Telefone: " << cliente.telefone << endl;
    return os;
}

/**
 * Sobrecarga do operador de igualdade para verificar se dois clientes têm o mesmo ID.
 * 
 * @param cliente Cliente a ser comparado.
 * @return True se os clientes têm o mesmo ID, False caso contrário.
 */
bool Cliente::operator==(const Cliente& cliente) const {
    return this->id == cliente.id;
}

/**
 * Valida um número de telefone usando expressão regular.
 * 
 * @param telefone Número de telefone a ser validado.
 * @return True se o número de telefone é válido, False caso contrário.
 */
bool Cliente::validarTelefone(const string& telefone) {
    // Expressão regular para validar números de telefone
    regex padrao("^(\\+\\d{1,3})?\\s*(\\(\\d{1,4}\\))?[-.\\s]?\\d{1,10}[-.\\s]?\\d{1,10}$");
    
    // Verificar se o número de telefone corresponde ao padrão
    return regex_match(telefone, padrao);
}

/**
 * Valida um nome usando expressão regular.
 * 
 * @param nome Nome a ser validado.
 * @return True se o nome é válido, False caso contrário.
 */
bool Cliente::validarNome(const string& nome) {
    // Expressão regular para validar um nome
    regex padrao("^[A-Za-z]+(?:[\\s-][A-Za-z]+)*$");
    
    // Verificar se o nome corresponde ao padrão
    return regex_match(nome, padrao);
}

/**
 * Valida um endereço verificando se possui pelo menos duas coordenadas.
 * 
 * @param endereco Vetor de coordenadas geográficas a ser validado.
 * @return True se o endereço é válido, False caso contrário.
 */
bool Cliente::validarEndereco(const vector<double>& endereco) {
    // Verificar se o endereço tem pelo menos 2 coordenadas
    return endereco.size() >= 2;
}

/**
 * Valida um CPF usando expressão regular.
 * 
 * @param cpf CPF a ser validado.
 * @return True se o CPF é válido, False caso contrário.
 */
bool Cliente::validarCpf(const string& cpf) {
    // Expressão regular para validar um CPF
    regex padrao("^(\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2})|(\\d{11})$");
    
    // Verificar se o CPF corresponde ao padrão
    return regex_match(cpf, padrao);
}