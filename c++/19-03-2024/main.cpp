#include <iostream> // Inclui a biblioteca iostream, que fornece funcionalidades para entrada e saída de dados.

using namespace std; // Usa o namespace std, onde estão definidas as funções e objetos padrão da biblioteca padrão de C++.

class User{ // Declaração da classe User.
    private: // Modificador de acesso "private": os membros são acessíveis apenas dentro da classe.
        string name; // Declaração de uma variável membro privada do tipo string chamada 'name'.
        string email; // Declaração de uma variável membro privada do tipo string chamada 'email'.
        int age; // Declaração de uma variável membro privada do tipo int chamada 'age'.
        
    public: // Modificador de acesso "public": os membros são acessíveis a partir de qualquer parte do código.
        void setName(string name){ // Declaração de uma função membro pública chamada 'setName' que aceita um parâmetro 'name' do tipo string e não retorna valor.
            this->name = name; // Atribui o valor do parâmetro 'name' ao membro 'name' da classe usando o ponteiro 'this'.
        }
        void setAge(int age){ // Declaração de uma função membro pública chamada 'setAge' que aceita um parâmetro 'age' do tipo int e não retorna valor.
            this->age = age; // Atribui o valor do parâmetro 'age' ao membro 'age' da classe usando o ponteiro 'this'.
        }
        void setEmail(string email){ // Declaração de uma função membro pública chamada 'setEmail' que aceita um parâmetro 'email' do tipo string e não retorna valor.
            this->email = email; // Atribui o valor do parâmetro 'email' ao membro 'email' da classe usando o ponteiro 'this'.
        }
        
        string getName(){ // Declaração de uma função membro pública chamada 'getName' que não aceita parâmetros e retorna um valor do tipo string.
            return this->name; // Retorna o valor do membro 'name' da classe usando o ponteiro 'this'.
        }
        int getAge(){ // Declaração de uma função membro pública chamada 'getAge' que não aceita parâmetros e retorna um valor do tipo int.
            return this->age; // Retorna o valor do membro 'age' da classe usando o ponteiro 'this'.
        }
        string getEmail(){ // Declaração de uma função membro pública chamada 'getEmail' que não aceita parâmetros e retorna um valor do tipo string.
            return this->email; // Retorna o valor do membro 'email' da classe usando o ponteiro 'this'.
        }
};


int main() // Função principal do programa.
{
    User user1; // Criação de um objeto 'user1' da classe User.
    user1.setName("Gabriel"); // Chama a função 'setName' do objeto 'user1' e passa o valor "Gabriel".
    user1.setEmail("gabrielprates.aluno@unipampa.edu.br"); // Chama a função 'setEmail' do objeto 'user1' e passa o valor do e-mail.
    user1.setAge(64); // Chama a função 'setAge' do objeto 'user1' e passa o valor da idade.
    
    User *user2 = new User(); // Criação de um ponteiro para um objeto 'User' chamado 'user2' usando o operador 'new'.
    user2->setName("Marcelo"); // Chama a função 'setName' do objeto apontado por 'user2' e passa o valor "Marcelo".
    user2->setAge(25); // Chama a função 'setAge' do objeto apontado por 'user2' e passa o valor da idade.
    user2->setEmail("marceloluizelli@unipampa.edu.br"); // Chama a função 'setEmail' do objeto apontado por 'user2' e passa o valor do e-mail.

    cout << "User1: " << user1.getName() << ", " << user1.getAge() << " anos, " << user1.getEmail(); // Imprime os detalhes do usuário 1.
    cout << "\n###############################################################\n"; // Imprime uma linha divisória.
    cout << "User2: " << user2->getName() << ", " << user2->getAge() << " anos, " << user2->getEmail(); << "\n"// Imprime os detalhes do usuário 2.

    return 0; // Retorna 0 para indicar que o programa foi concluído com sucesso.
}
