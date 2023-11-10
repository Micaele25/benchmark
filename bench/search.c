#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(const char *filename, int key) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int num, position = 0;
    clock_t start = clock();

    while (fscanf(file, "%d", &num) != EOF) {
        if (num == key) {
            fclose(file);
            clock_t end = clock();
            printf("Tempo de busca linear: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
            return position;
        }
        position++;
    }

    fclose(file);
    return -1;
}

// Função para fazer a busca sentinela
int sentinelSearch(const char *filename, int key) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int num, position = 0;
    int sentinel = 0;
    clock_t start = clock();

    while (fscanf(file, "%d", &num) != EOF) {
        if (num == key) {
            fclose(file);
            clock_t end = clock();
            printf("Tempo de busca sentinela: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
            return position;
        }
        position++;
    }

    fclose(file);
    return -1;
}

// Função para fazer a busca binária
int binarySearch(const char *filename, int key) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        exit(1);
    }

    int num, position = 0;
    int low = 0;
    int high = 0;
    int mid = 0;
    int found = 0;
    clock_t start = clock();

    while (fscanf(file, "%d", &num) != EOF) {
        position++;
        high = position;
    }
    rewind(file);

    while (low <= high && !found) {
        mid = (low + high) / 2;

        for (int i = 0; i < mid; i++) {
            fscanf(file, "%d", &num);
        }

        if (num == key) {
            found = 1;
        } else if (num < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    fclose(file);

    if (found) {
        clock_t end = clock();
        printf("Tempo de busca binária: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
        return mid - 1;
    } else {
        return -1;
    }
}

