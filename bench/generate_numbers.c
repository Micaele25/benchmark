#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumbers(int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int num = rand() % 1000;
        fprintf(file, "%d ", num);
    }

    fclose(file);
}

int main() {
    int count;
    printf("Digite a quantidade de números inteiros a serem gerados: ");
    scanf("%d", &count);

    generateRandomNumbers(count, "random_numbers.txt");

    return 0;
}
