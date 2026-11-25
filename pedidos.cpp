#include "pedidos.h"
#include <limits>

vector<Pedido> pedidos;
int proximoCodigo = 1;

int lerInteiro() {
    int valor;

    while (!(cin >> valor)) {
        cout << "Entrada inválida. Digite um número: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return valor;
}

void cadastrarPedido() {
    int quantidade;

    cout << "Deseja cadastrar quantos pedidos? ";
    cin >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        Pedido novoPedido;

        novoPedido.codigo = proximoCodigo++;

        cout << "\nCadastro do pedido " << i + 1 << endl;

        cout << "Nome do cliente: ";
        cin.ignore();
        getline(cin, novoPedido.cliente);

        cout << "Endereço: ";
        getline(cin, novoPedido.endereco);

        cout << "Produto: ";
        getline(cin, novoPedido.produto);

        cout << "Prioridade (1 - Alta, 2 - Media, 3 - Baixa): ";
        cin >> novoPedido.prioridade;

        novoPedido.status = "Pendente";

        pedidos.push_back(novoPedido);

        cout << "Pedido cadastrado!\n";
    }
}

void exibirPedido(Pedido p) {
    cout << "\nCódigo: " << p.codigo;
    cout << "\nCliente: " << p.cliente;
    cout << "\nEndereço: " << p.endereco;
    cout << "\nProduto: " << p.produto;

    cout << "\nPrioridade: ";

    if (p.prioridade == 1)
        cout << "Alta";
    else if (p.prioridade == 2)
        cout << "Média";
    else
        cout << "Baixa";

    cout << "\nStatus: " << p.status;
    cout << "\n--------------------------\n";
}

void listarPedidos() {
    if (pedidos.empty()) {
        cout << "\nNenhum pedido cadastrado.\n";
        return;
    }

    cout << "\n--- LISTA DE PEDIDOS ---\n";

    for (int i = 0; i < pedidos.size(); i++) {
        exibirPedido(pedidos[i]);
    }
}

void buscarPorCodigo() {
    int codigo;
    bool encontrado = false;

    cout << "\nDigite o código do pedido: ";
    codigo = lerInteiro();

    for (int i = 0; i < pedidos.size(); i++) {
        if (pedidos[i].codigo == codigo) {
            exibirPedido(pedidos[i]);
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "\nPedido não encontrado.\n";
}

void buscarPorCliente() {
    string nome;
    bool encontrado = false;

    cout << "\nDigite o nome do cliente: ";
    getline(cin, nome);

    for (int i = 0; i < pedidos.size(); i++) {
        if (pedidos[i].cliente.find(nome) != string::npos) {
            exibirPedido(pedidos[i]);
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "\nNenhum pedido encontrado para esse cliente.\n";
}

void buscarPorEndereco() {
    string endereco;
    bool encontrado = false;

    cout << "\nDigite o endereço ou trecho do endereço: ";
    getline(cin, endereco);

    for (int i = 0; i < pedidos.size(); i++) {
        if (pedidos[i].endereco.find(endereco) != string::npos) {
            exibirPedido(pedidos[i]);
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "\nNenhum pedido encontrado nesse endereço.\n";
}

void ordenarPorCodigo() {
    if (pedidos.size() < 2) {
        cout << "\nNão há pedidos suficientes para ordenar.\n";
        return;
    }

    for (int i = 0; i < pedidos.size() - 1; i++) {
        for (int j = 0; j < pedidos.size() - 1 - i; j++) {
            if (pedidos[j].codigo > pedidos[j + 1].codigo) {
                Pedido auxiliar = pedidos[j];
                pedidos[j] = pedidos[j + 1];
                pedidos[j + 1] = auxiliar;
            }
        }
    }

    cout << "\nPedidos ordenados por código.\n";
    listarPedidos();
}

void ordenarPorPrioridade() {
    if (pedidos.size() < 2) {
        cout << "\nNão há pedidos suficientes para ordenar.\n";
        return;
    }

    for (int i = 0; i < pedidos.size() - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < pedidos.size(); j++) {
            if (pedidos[j].prioridade < pedidos[menor].prioridade) {
                menor = j;
            }
        }

        Pedido auxiliar = pedidos[i];
        pedidos[i] = pedidos[menor];
        pedidos[menor] = auxiliar;
    }

    cout << "\nPedidos ordenados por prioridade.\n";
    listarPedidos();
}

void selecionarPedidoPrioritario() {
    int indice = -1;

    for (int i = 0; i < pedidos.size(); i++) {
        if (pedidos[i].status == "Pendente") {
            if (indice == -1 ||
                pedidos[i].prioridade < pedidos[indice].prioridade) {
                indice = i;
            }
        }
    }

    if (indice == -1) {
        cout << "\nNão existem pedidos pendentes.\n";
        return;
    }

    cout << "\n--- PEDIDO PRIORITÁRIO ---\n";
    exibirPedido(pedidos[indice]);
}

void selecionarPedidoMaisAntigo() {
    int indice = -1;

    for (int i = 0; i < pedidos.size(); i++) {
        if (pedidos[i].status == "Pendente") {
            if (indice == -1 ||
                pedidos[i].codigo < pedidos[indice].codigo) {
                indice = i;
            }
        }
    }

    if (indice == -1) {
        cout << "\nNão existem pedidos pendentes.\n";
        return;
    }

    cout << "\n--- PEDIDO PENDENTE MAIS ANTIGO ---\n";
    exibirPedido(pedidos[indice]);
}

void atualizarStatus() {
    int codigo;
    bool encontrado = false;

    cout << "\nDigite o código do pedido: ";
    codigo = lerInteiro();

    for (int i = 0; i < pedidos.size(); i++) {
        if (pedidos[i].codigo == codigo) {
            encontrado = true;

            cout << "\nPedido encontrado:\n";
            exibirPedido(pedidos[i]);

            cout << "\nNovo status:\n";
            cout << "1 - Em preparo\n";
            cout << "2 - Saiu para entrega\n";
            cout << "3 - Entregue\n";
            cout << "4 - Cancelado\n";
            cout << "Escolha: ";

            int opcao = lerInteiro();

            switch (opcao) {
                case 1:
                    pedidos[i].status = "Em preparo";
                    break;

                case 2:
                    pedidos[i].status = "Saiu para entrega";
                    break;

                case 3:
                    pedidos[i].status = "Entregue";
                    break;

                case 4:
                    pedidos[i].status = "Cancelado";
                    break;

                default:
                    cout << "\nOpção inválida.\n";
                    return;
            }

            cout << "\nStatus atualizado com sucesso!\n";
            break;
        }
    }

    if (!encontrado)
        cout << "\nPedido não encontrado.\n";
}

void excluirPedido() {
    int codigo;
    bool encontrado = false;

    cout << "\nDigite o código do pedido que deseja excluir: ";
    codigo = lerInteiro();

    for (int i = 0; i < pedidos.size(); i++) {
        if (pedidos[i].codigo == codigo) {
            pedidos.erase(pedidos.begin() + i);
            encontrado = true;

            cout << "\nPedido excluído com sucesso!\n";
            break;
        }
    }

    if (!encontrado)
        cout << "\nPedido não encontrado.\n";
}
