#include "pedidos.h"
#include <locale.h>

int main() {
	
	setlocale (LC_ALL, "Portuguese");
    int opcao;

    do {
        cout << "\n====================================\n";
        cout << " SISTEMA DE GERENCIAMENTO DE PEDIDOS\n";
        cout << "====================================\n";

        cout << "1 - Cadastrar pedido\n";
        cout << "2 - Listar pedidos\n";
        cout << "3 - Buscar por código\n";
        cout << "4 - Buscar por cliente\n";
        cout << "5 - Buscar por endereço\n";
        cout << "6 - Ordenar por código\n";
        cout << "7 - Ordenar por prioridade\n";
        cout << "8 - Selecionar pedido prioritário\n";
        cout << "9 - Selecionar pedido mais antigo\n";
        cout << "10 - Atualizar status\n";
        cout << "11 - Excluir pedido\n";
        cout << "0 - Sair\n";

        cout << "\nEscolha uma opção: ";
        opcao = lerInteiro();

        switch (opcao) {
            case 1:
                cadastrarPedido();
                break;

            case 2:
                listarPedidos();
                break;

            case 3:
                buscarPorCodigo();
                break;

            case 4:
                buscarPorCliente();
                break;

            case 5:
                buscarPorEndereco();
                break;

            case 6:
                ordenarPorCodigo();
                break;

            case 7:
                ordenarPorPrioridade();
                break;

            case 8:
                selecionarPedidoPrioritario();
                break;

            case 9:
                selecionarPedidoMaisAntigo();
                break;

            case 10:
                atualizarStatus();
                break;

            case 11:
                excluirPedido();
                break;

            case 0:
                cout << "\nEncerrando o sistema...\n";
                break;

            default:
                cout << "\nOpção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}
