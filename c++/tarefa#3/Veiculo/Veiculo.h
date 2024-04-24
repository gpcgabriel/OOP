#ifndef VEICULO_H // Diretiva de pré-processamento: evita múltiplas inclusões do mesmo arquivo de cabeçalho
#define VEICULO_H

#include <vector>
#include <string>

using namespace std;

class Veiculo {
    private:
        int id;
        string placa;

        /**
         * @param chassi A string representando o chassi do veículo.
         * @return Retorna verdadeiro se o chassi for válido, falso caso contrário.
         */
        bool validarChassi(const string& chassi);

        /**
         * @param placa A string representando a placa do veículo.
         * @return Retorna verdadeiro se a placa for válida, falso caso contrário.
         */
        bool validarPlaca(const string& placa);

    protected:
        int anoFabricacao;
        float capacidadeCarga;
        float volumeCarga;
        float capacidadeAtual;
        float volumeAtual;
        string chassi;
        string modelo;
        bool disponivel;
        vector<double> localizacao;

    public:
        /**
         * @param id O identificador do veículo.
         * @param placa A placa do veículo.
         * @param anoFabricacao O ano de fabricação do veículo.
         * @param capacidadeCarga A capacidade de carga do veículo.
         * @param capacidadeAtual A capacidade atual de carga do veículo.
         * @param volumeCarga O volume de carga do veículo.
         * @param volumeAtual O volume atual de carga do veículo.
         * @param chassi O chassi do veículo.
         * @param modelo O modelo do veículo.
         * @param localizacao A localização do veículo.
         * @param disponivel Indica se o veículo está disponível.
         */
        Veiculo(int id, string placa, int anoFabricacao, float capacidadeCarga, float capacidadeAtual, float volumeCarga, float volumeAtual, string chassi, 
                string modelo, vector<double> localizacao, bool disponivel);

        /**
         * Construtor padrão para a classe Veiculo.
         */
        Veiculo(); // Construtor
            
        /**
         * Destrutor para a classe Veiculo.
         */
        ~Veiculo(); // Destrutor

        /**
         * @return Retorna o identificador do veículo.
         */
        int getId() const;

        /**
         * @param id O novo identificador do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setId(const int& id);

        /**
         * @return Retorna a placa do veículo.
         */
        string getPlaca() const;

        /**
         * @param placa A nova placa do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setPlaca(const string& placa);

        /**
         * @return Retorna o ano de fabricação do veículo.
         */
        int getAnoFabricacao() const;

        /**
         * @param anoFabricacao O novo ano de fabricação do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setAnoFabricacao(const int& anoFabricacao);

        /**
         * @return Retorna a capacidade de carga do veículo.
         */
        float getCapacidadeCarga() const;

        /**
         * @param capacidadeCarga A nova capacidade de carga do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setCapacidadeCarga(const float& capacidadeCarga);

        /**
         * @return Retorna o volume de carga do veículo.
         */
        float getVolumeCarga() const;

        /**
         * @param volumeCarga O novo volume de carga do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setVolumeCarga(const float& volumeCarga);

        /**
         * @param volumeCarga O volume de carga a ser alocado.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int alocarVolumeCarga(const float& volumeCarga);

        /**
         * @param pesoCarga O peso da carga a ser alocado.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int alocarPesoCarga(const float& pesoCarga);

        /**
         * @param cargaAtual A nova capacidade atual de carga do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setCapacidadeAtual(const float& cargaAtual);

        /**
         * @return Retorna a capacidade atual de carga do veículo.
         */
        float getCapacidadeAtual() const;

        /**
         * @param volumeAtual O novo volume atual de carga do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setVolumeAtual(const float& volumeAtual);

        /**
         * @return Retorna o volume atual de carga do veículo.
         */
        float getVolumeAtual() const;

        /**
         * @return Retorna o chassi do veículo.
         */
        string getChassi() const;

        /**
         * @param chassi O novo chassi do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setChassi(const string& chassi);

        /**
         * @return Retorna o modelo do veículo.
         */
        string getModelo() const;

        /**
         * @param modelo O novo modelo do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setModelo(const string& modelo);

        /**
         * @return Retorna a localização do veículo.
         */
        vector<double> getLocalizacao() const;

        /**
         * @param localizacao A nova localização do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setLocalizacao(const vector<double>& localizacao);

        /**
         * @return Retorna a disponibilidade do veículo.
         */
        bool getDisponibilidade() const;

        /**
         * @param disponivel A nova disponibilidade do veículo.
         * @return Retorna 0 se a operação for bem-sucedida, -1 caso contrário.
         */
        int setDisponibilidade(const bool& disponivel);

        /**
         * @param os O fluxo de saída.
         * @param veiculo O objeto Veiculo a ser impresso.
         * @return Retorna o fluxo de saída modificado.
         */
        friend ostream& operator<<(ostream& os, const Veiculo& veiculo);

        /**
         * @param outro O objeto Veiculo a ser comparado.
         * @return Retorna verdadeiro se os objetos forem iguais, falso caso contrário.
         */
        bool operator==(const Veiculo& outro) const;

        /**
         * @param localizacao A localização a ser validada.
         * @return Retorna verdadeiro se a localização for válida, falso caso contrário.
         */
        static bool validarLocalizacao(const vector<double>& localizacao);

        /**
         * @param capacidadeCarga A capacidade de carga a ser validada.
         * @return Retorna verdadeiro se a capacidade de carga for válida, falso caso contrário.
         */
        static bool validarCapacidadeCarga(const float& capacidadeCarga);

        /**
         * @param anoFabricacao O ano de fabricação a ser validado.
         * @return Retorna verdadeiro se o ano de fabricação for válido, falso caso contrário.
         */
        static bool validarAnoFabricacao(const int& anoFabricacao);
};

#endif // VEICULO_H