#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>

using namespace std;

/**
 * Classe que representa um cliente.
 */
class Cliente {
private:
    int id; /**< Identificador do cliente. */

    /**
     * Método privado para validar um número de telefone.
     * 
     * @param telefone Número de telefone a ser validado.
     * @return True se o número de telefone é válido, False caso contrário.
     */
    bool validarTelefone(const string& telefone);

    /**
     * Método privado para validar um nome.
     * 
     * @param nome Nome a ser validado.
     * @return True se o nome é válido, False caso contrário.
     */
    bool validarNome(const string& nome);

    /**
     * Método privado para validar um endereço.
     * 
     * @param endereco Vetor de coordenadas geográficas a ser validado.
     * @return True se o endereço é válido, False caso contrário.
     */
    bool validarEndereco(const vector<double>& endereco);

    /**
     * Método privado para validar um CPF.
     * 
     * @param cpf CPF a ser validado.
     * @return True se o CPF é válido, False caso contrário.
     */
    bool validarCpf(const string& cpf);

protected:
    string nome; /**< Nome do cliente. */
    vector<double> endereco; /**< Coordenadas geográficas do endereço do cliente. */
    string telefone; /**< Número de telefone do cliente. */
    string cpf; /**< CPF do cliente. */

public:
    /**
     * Construtor da classe Cliente.
     * 
     * @param id Identificador do cliente.
     * @param cpf CPF do cliente.
     * @param nome Nome do cliente.
     * @param endereco Vetor de coordenadas geográficas do endereço do cliente.
     * @param telefone Número de telefone do cliente.
     */
    Cliente(int id, string cpf, string nome, vector<double> endereco, string telefone);

    /**
     * Construtor padrão da classe Cliente.
     */
    Cliente();

    /**
     * Destrutor da classe Cliente.
     */
    ~Cliente();

    /**
     * Obtém o identificador do cliente.
     * 
     * @return O identificador do cliente.
     */
    int getId() const;

    /**
     * Define o identificador do cliente.
     * 
     * @param id O identificador a ser atribuído ao cliente.
     * @return 1 se o identificador foi definido com sucesso, 0 caso contrário.
     */
    int setId(const int& id);

    /**
     * Obtém o CPF do cliente.
     * 
     * @return O CPF do cliente.
     */
    string getCpf() const;

    /**
     * Define o CPF do cliente.
     * 
     * @param cpf O CPF a ser atribuído ao cliente.
     * @return 1 se o CPF foi definido com sucesso, 0 caso contrário.
     */
    int setCpf(const string& cpf);

    /**
     * Obtém o nome do cliente.
     * 
     * @return O nome do cliente.
     */
    string getNome() const;

    /**
     * Define o nome do cliente.
     * 
     * @param nome O nome a ser atribuído ao cliente.
     * @return 1 se o nome foi definido com sucesso, 0 caso contrário.
     */
    int setNome(const string& nome);

    /**
     * Obtém o endereço do cliente.
     * 
     * @return O vetor de coordenadas geográficas do endereço do cliente.
     */
    vector<double> getEndereco() const;

    /**
     * Define o endereço do cliente.
     * 
     * @param endereco O vetor de coordenadas geográficas a ser atribuído ao endereço do cliente.
     * @return 1 se o endereço foi definido com sucesso, 0 caso contrário.
     */
    int setEndereco(const vector<double>& endereco);

    /**
     * Obtém o número de telefone do cliente.
     * 
     * @return O número de telefone do cliente.
     */
    string getTelefone() const;

    /**
     * Define o número de telefone do cliente.
     * 
     * @param telefone O número de telefone a ser atribuído ao cliente.
     * @return 1 se o número de telefone foi definido com sucesso, 0 caso contrário.
     */
    int setTelefone(const string& telefone);

    /**
     * Sobrecarga do operador de inserção para exibir informações do cliente.
     * 
     * @param os Stream de saída.
     * @param cliente Cliente cujas informações serão exibidas.
     * @return A stream de saída contendo as informações do cliente.
     */
    friend ostream& operator<<(ostream& os, const Cliente& cliente);

    /**
     * Sobrecarga do operador de igualdade para verificar se dois clientes têm o mesmo ID.
     * 
     * @param cliente Cliente a ser comparado.
     * @return True se os clientes têm o mesmo ID, False caso contrário.
     */
    bool operator==(const Cliente& cliente) const;
};

#endif // CLIENTE_H