#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    printf("Escolha uma opção:\n");
    printf("1. Busca de elemento\n");
    printf("2. Classificação de elementos\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int key;
        printf("Digite o número que deseja buscar: ");
        scanf("%d", &key);

        // Chame as funções de busca aqui
    } else if (choice == 2) {
        // Chame a função de classificação aqui
    } else {
        printf("Opção inválida\n");
    }

    return 0;
}
