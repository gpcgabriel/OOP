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
    string nome;       // Nome do cliente
    string endereco;   // Endereço do cliente
    string telefone;   // Número de telefone do cliente

public:
    // Construtor: inicializa um Cliente com nome, endereço e telefone especificados
    Cliente(string nome, string endereco, string telefone);

    // Métodos getters para obter os atributos do cliente
    string getNome() const;        // Retorna o nome do cliente
    string getEndereco() const;    // Retorna o endereço do cliente
    string getTelefone() const;    // Retorna o telefone do cliente

    // Métodos setters para modificar os atributos do cliente
    void setNome(const string& nome);         // Define o nome do cliente
    void setEndereco(const string& endereco); // Define o endereço do cliente
    void setTelefone(const string& telefone); // Define o telefone do cliente
};

#endif // CLIENTE_H
