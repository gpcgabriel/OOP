#include "Veiculo/Veiculo.h"
#include "GerenciadorVeiculo/GerenciadorVeiculo.h"
#include "Veiculo/Carro/Carro.h"
#include "Veiculo/Caminhao/Caminhao.h"
#include "Cliente/Cliente.h"
#include "Ordem/Ordem.h"
#include "Roteirizacao/Roteirizacao.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * Função principal do programa.
 * 
 * Esta função cria instâncias de veículos, clientes, ordens de transporte e 
 * um gerenciador de veículos. Em seguida, instancia objetos de roteirização 
 * para planejar rotas de transporte com base nas ordens de transporte e nos 
 * veículos disponíveis. Finalmente, exibe as informações das rotas planejadas.
 * 
 * @return 0 se o programa foi executado com sucesso.
 */
int main() {
    // Coordenadas geográficas de algumas cidades
    vector<double> alegrete = {-29.786994, -55.7689568, 0};
    vector<double> panambi = {-28.288556, -53.4950704, 0};
    vector<double> cacequi = {-29.8810086, -54.822953, 0};
    vector<double> mViana = {-29.5871209, -55.4842407, 0};
    vector<double> saoGabriel = {-30.3368225, -54.3641182, 0};
    vector<double> uruguaiana = {-29.771745, -57.1171232, 0};

    // Criando instâncias de veículos
    Carro *fusca = new Carro(1, "ABC1234", 1990, 500.0, 500.0, 5.0, 5.0, "1A2B3C4D5E6F7G8H8", "Fusca", alegrete, true, 2);

    Carro *gol = new Carro();
    gol->setId(2);
    gol->setPlaca("IIT8119");
    gol->setAnoFabricacao(2008);
    gol->setCapacidadeCarga(200.0);
    gol->setCapacidadeAtual(200.0);
    gol->setChassi("1A2B3C4D5E6F7G8H9");
    gol->setModelo("Gol");
    gol->setVolumeCarga(20.0);
    gol->setVolumeAtual(20.0);
    gol->setLocalizacao(panambi);
    gol->setNumPortas(4);
    gol->setDisponibilidade(true);

    Caminhao *caminhao = new Caminhao(3, "AAA1111", 2010, 10000.0, 10000.0, 50.0, 50.0, "1234567890", "Scania", alegrete, true, 6);

    Caminhao *caminhao2 = new Caminhao();
    caminhao2->setId(4);
    caminhao2->setPlaca("BBB2222");
    caminhao2->setAnoFabricacao(2015);
    caminhao2->setCapacidadeCarga(20000.0);
    caminhao2->setCapacidadeAtual(20000.0);
    caminhao2->setChassi("1A2B3C4D5E6F7G8H2");
    caminhao2->setModelo("Volvo");
    caminhao2->setVolumeCarga(60.0);
    caminhao2->setVolumeAtual(60.0);
    caminhao2->setLocalizacao(panambi);
    caminhao2->setNumEixos(8);
    caminhao2->setDisponibilidade(true);

    // Criando instâncias de clientes
    Cliente *cliente = new Cliente();
    cliente->setId(1);
    cliente->setCpf("123.456.789-01");
    cliente->setNome("Joao");
    cliente->setEndereco(alegrete);
    cliente->setTelefone("55996632029");

    Cliente *cliente2 = new Cliente(2, "987.654.321-09", "Maria", uruguaiana, "55996632029");

    // Criando e adicionando veículos ao gerenciador
    GerenciadorVeiculo *gerenciadorVeiculo = new GerenciadorVeiculo(fusca);
    gerenciadorVeiculo->adicionarVeiculo(gol);
    gerenciadorVeiculo->adicionarVeiculo(caminhao);
    gerenciadorVeiculo->adicionarVeiculo(caminhao2);

    // Criando instâncias de ordens de transporte
    Ordem *panambiAlegrete = new Ordem(1, panambi, alegrete, cliente, 200.0, 25.0, false);
    Ordem *alegretePanambi = new Ordem(2, alegrete, panambi, cliente, 20000.0, 30.0, true);

    // Criando vetor de ordens e adicionando ordens
    vector<Ordem> *ordens = new vector<Ordem>();
    ordens->push_back(*alegretePanambi);
    ordens->push_back(*panambiAlegrete);

    Ordem *cacequiSaoGabriel = new Ordem(3, cacequi, saoGabriel, cliente2, 600.0, 5.0, false);
    Ordem *mVianaUruguaiana = new Ordem(4, mViana, uruguaiana, cliente2, 200.0, 3.0, false);

    // Criando vetor de ordens e adicionando ordens
    vector<Ordem> *ordens2 = new vector<Ordem>();
    ordens2->push_back(*cacequiSaoGabriel);
    ordens2->push_back(*mVianaUruguaiana);

    // Criando instâncias de roteirização e planejando rotas
    Roteirizacao *rota = new Roteirizacao(ordens, gerenciadorVeiculo);
    Roteirizacao *rota2 = new Roteirizacao(ordens2, gerenciadorVeiculo);

    // Exibindo as informações das rotas
    cout << *rota << endl;
    cout << *rota2 << endl;

    // Liberando a memória alocada
    delete rota;
    delete ordens;
    delete gerenciadorVeiculo;

    delete fusca;
    delete gol;
    delete caminhao;
    delete caminhao2;
    delete cliente;

    delete panambiAlegrete;
    delete alegretePanambi;

    return 0;
}