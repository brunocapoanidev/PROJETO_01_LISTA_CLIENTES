#include <stdio.h>
#include <string.h>

char clientes[10][30];
int total = 0;

void adicionar() {
    if (total < 10) {
        printf("Nome do cliente: ");
        scanf(" %s", clientes[total]);
        total++;
        printf("Cliente adicionado!\n");
    } else {
        printf("Limite de cliente atingido.\n");
    }
}

void listar() {
    if (total == 0) {
        printf("Nenhum cliente cadastrado.\n");
    } else {
        printf("Lista de clientes:\n");
        for (int i = 0; i < total; i++) {
            printf("%d - %s\n", i + 1, clientes[i]);
        }
    }
}

void remover() {
    int pos;
    if (total == 0) {
        printf("Nao ha clientes para remover.\n");
    } else {
        listar();
        printf("Digite o numero do cliente para remover: ");
        scanf("%d", &pos);
        if (pos >= 1 && pos <= total) {
            for (int i = pos - 1; i < total - 1; i++) {
                strcpy(clientes[i], clientes[i + 1]);
            }
            total--;
            printf("Cliente removido!\n");
        } else {
            printf("Numero invalido.\n");
        }
    }
}

void limparLista() {
    if (total == 0) {
        printf("Lista ja esta vazia.\n");
    } else {
        total = 0;
        printf("Todos os clientes foram removidos.\n");
    }
}

void mostrarTotal() {
    printf("Total de clientes cadastrados: %d\n", total);
}

int main() {
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Remover cliente\n");
        printf("4 - Mostrar total de clientes\n");
        printf("5 - Limpar lista\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            adicionar();
        } else if (opcao == 2) {
            listar();
        } else if (opcao == 3) {
            remover();
        } else if (opcao == 4) {
            mostrarTotal();
        } else if (opcao == 5) {
            limparLista();
        } else if (opcao == 6) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 6);

    return 0;
}
