#include "Cliente.h"
#include <regex>
#include <iostream>
#include <cctype> // Biblioteca para funções de caracteres

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
Cliente::Cliente(int id, string CPF, string nome, string email, string endereco, string telefone)
    : nome(nome), endereco(endereco), telefone(telefone) {}

// Destrutor da classe
Cliente::~Cliente(){}

// Retorna o id do cliente
int Cliente::getId() const{
    return this->id;
}

// Define o id do cliente
int Cliente::setId(const int& id){
    try
    {
       this->id = id;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao definir o ID do cliente" << endl;
        return 1;
    }
}

// Retorna o cpf do cliente
string Cliente::getCpf() const{
    return this->cpf;
}

// Define o cpf do cliente
int Cliente::setCpf(const string& cpf){
    if (validarCPF(cpf)){
        this->cpf = cpf;
        return 0;
    }else{
        cout << "insira um CPF válido!" << endl;
        return 1;
    }
}

// Retorna o nome do cliente
string Cliente::getNome() const {
    return nome;
}

// Define o nome do cliente
int Cliente::setNome(const string& nome) {
    if(validarNome(nome)){
        this->nome = nome;
        return 0;
    }else{
        cout << "Erro ao validar o nome!" << endl;
        return 1;
    }
    
}

// Retorna o email do cliente
string Cliente::getEmail() const {
    return email;
}

// Define o email do cliente
int Cliente::setEmail(const string& email) {
    if(validarEmail(email)){
        this->email = email;
        return 0;
    }else{
        cout << "Erro ao validar o email" << endl;
        return 1;
    }
}

// Retorna o endereço do cliente
string Cliente::getEndereco() const {
    return endereco;
}

// Define o endereço do cliente
int Cliente::setEndereco(const string& endereco) {
    try
    {
        this->endereco = endereco;
        return 0;
    }
    catch(const std::exception& e)
    {
        cout << "Erro ao cadastrar o endereço!";
        return 1;
    }
    
}

// Retorna o telefone do cliente
string Cliente::getTelefone() const {
    return telefone;
}

// Define o telefone do cliente
int Cliente::setTelefone(const string& telefone) {
    if(validarTelefone(telefone)){
        this->telefone = telefone;
        return 0;
    }else{
        cout << "Erro ao validar o telefone!" << endl;
        return 1;
    }
}

/*
 * Métodos auxiliares de validação
*/
// Verifica se todos os dígitos do CPF são iguais
bool Cliente::todosDigitosIguais(const string& str) {
    char primeiroDigito = str[0];
    for (char c : str) {
        if (c != primeiroDigito) {
            return false;
        }
    }
    return true;
}

// Remove os dígitos desimportantes (como "." e "-")
string Cliente::removerNaoNumericos(const string& str) {
    string resultado;
    for (char c : str) {
        if (isdigit(c)) {
            resultado += c;
        }
    }
    return resultado;
}

bool Cliente::validarCPF(const string& cpf) {
    // Remove caracteres não numéricos do CPF
    string cpfLimpo = removerNaoNumericos(cpf);

    // Verifica se o CPF tem 11 dígitos
    if (cpfLimpo.length() != 11) {
        return false;
    }

    // Verifica se todos os dígitos do CPF são iguais, o que é inválido
    if (todosDigitosIguais(cpfLimpo)) {
        return false;
    }

    // Calcula e verifica os dígitos verificadores do CPF
    int soma = 0;
    
    for (int i = 0; i < 9; i++) {
        soma += (cpfLimpo[i] - '0') * (10 - i);
    }
    
    int primeiroDigitoVerificador = (soma * 10) % 11;
    
    if (primeiroDigitoVerificador == 10) {
        primeiroDigitoVerificador = 0;
    }
    
    if (primeiroDigitoVerificador != cpfLimpo[9] - '0') {
        return false;
    }

    soma = 0;
    
    for (int i = 0; i < 10; i++) {
        soma += (cpfLimpo[i] - '0') * (11 - i);
    }
    
    int segundoDigitoVerificador = (soma * 10) % 11;
    
    if (segundoDigitoVerificador == 10) {
        segundoDigitoVerificador = 0;
    }
    
    if (segundoDigitoVerificador != cpfLimpo[10] - '0') {
        return false;
    }

    return true; // Se todas as verificações passarem, o CPF é considerado válido
}

bool Cliente::validarNome(const string& nome) {
    // Verifica se o nome não está vazio
    if (nome.empty()) {
        return false;
    }

    // Verifica se o nome contém apenas letras e espaços
    for (char c : nome) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }

    // Verifica se o primeiro e o último caractere são letras
    if (!isalpha(nome.front()) || !isalpha(nome.back())) {
        return false;
    }

    // Verifica se há dois espaços consecutivos
    for (size_t i = 0; i < nome.size() - 1; ++i) {
        if (nome[i] == ' ' && nome[i + 1] == ' ') {
            return false;
        }
    }

    // Verificação passou, nome é válido
    return true;
}

bool Cliente::validarEmail(const string& email) {
    // Expressão regular para validar o formato do e-mail
    // Essa expressão regular valida a maioria dos padrões de e-mail comuns, mas pode não cobrir todos os casos possíveis
    regex regexEmail("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

    // Verifica se o e-mail corresponde à expressão regular
    return regex_match(email, regexEmail);
}

bool Cliente::validarTelefone(const string& telefone) {
    // Expressão regular para validar o formato do telefone
    // Este exemplo assume que o formato é composto apenas por dígitos e caracteres especiais como -, (, )
    regex regexTelefone("^\\+?[0-9\\-\\(\\)\\s]+$");

    // Verifica se o telefone corresponde à expressão regular
    return regex_match(telefone, regexTelefone);
}
