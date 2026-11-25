#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pedido {
    int codigo;
    string cliente;
    string endereco;
    string produto;
    int prioridade;
    string status;
};

extern vector<Pedido> pedidos;
extern int proximoCodigo;

int lerInteiro();

void cadastrarPedido();
void exibirPedido(Pedido p);
void listarPedidos();

void buscarPorCodigo();
void buscarPorCliente();
void buscarPorEndereco();

void ordenarPorCodigo();
void ordenarPorPrioridade();

void selecionarPedidoPrioritario();
void selecionarPedidoMaisAntigo();

void atualizarStatus();
void excluirPedido();

#endif
