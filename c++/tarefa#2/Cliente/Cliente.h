#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

/*
*   Este código é um arquivo de cabeçalho (.h) que define a classe Cliente. 
*   Ele contém os atributos privados nome, endereco e telefone, bem como os 
*   métodos públicos getNome, getEndereco, getTelefone, setEndereco e setTelefone. 
*   A diretiva de pré-processador #ifndef, #define e #endif é usada para evitar a 
*   inclusão múltipla do arquivo de cabeçalho em outros arquivos fonte (.cpp).
*/

class Cliente {
private:
    int id;            // Identificador do cliente

    // Remove os dígitos desimportantes do CPF digitado
    string removerNaoNumericos(const string& str);
    
    // Verifica se todos os dígitos do CPF são iguais
    bool todosDigitosIguais(const string&);
protected:
    string cpf;        // CPF do cliente
    string nome;       // Nome do cliente
    string email;      // Email do cliente
    string endereco;   // Endereço do cliente
    string telefone;   // Número de telefone do cliente
public:
    // Construtor: inicializa um Cliente com nome, endereço e telefone especificados
    Cliente(int id, string cpf, string nome, string email, string endereco, string telefone);
    ~Cliente();

    // Métodos getters para obter os atributos do cliente
    int getId() const;             // Retorna o ID do cliente
    string getCpf() const;         // Retorna o CPF do cliente
    string getNome() const;        // Retorna o nome do cliente
    string getEmail() const;       // Retorna o email do cliente
    string getEndereco() const;    // Retorna o endereço do cliente
    string getTelefone() const;    // Retorna o telefone do cliente

    // Métodos setters para modificar os atributos do cliente
    int setId(const int& id);                // Define o id do cliente
    int setCpf(const string& cpf);           // Define o CPF do cliente
    int setNome(const string& nome);         // Define o nome do cliente
    int setEmail(const string& email);       // Define o email do cliente
    int setEndereco(const string& endereco); // Define o endereço do cliente
    int setTelefone(const string& telefone); // Define o telefone do cliente

    // Métodos auxiliares para validar os dados inseridos através dos setters
    bool validarCPF(const string& cpf);       // Valida o CPF do cliente
    bool validarNome(const string& nome);     // Valida o nome do cliente
    bool validarEmail(const string& email);   // Valida o email do cliente
    bool validarTelefone(const string& telefone); // Valida o telefone do cliente
};

#endif // CLIENTE_H
