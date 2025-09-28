#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

int esCuadradoMagico(int matrix[SIZE][SIZE]) {
    int sumaRef = 0;
    for (int j = 0; j < SIZE; j++)
        sumaRef += matrix[0][j];

    // verificar filas
    for (int i = 0; i < SIZE; i++) {
        int suma = 0;
        for (int j = 0; j < SIZE; j++)
            suma += matrix[i][j];
        if (suma != sumaRef) return 0;
    }

    // verificar columnas
    for (int j = 0; j < SIZE; j++) {
        int suma = 0;
        for (int i = 0; i < SIZE; i++)
            suma += matrix[i][j];
        if (suma != sumaRef) return 0;
    }

    // verificar diagonales
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < SIZE; i++) {
        diag1 += matrix[i][i];
        diag2 += matrix[i][SIZE - 1 - i];
    }
    if (diag1 != sumaRef || diag2 != sumaRef) return 0;

    return 1;
}

int main() {
    srand(time(NULL));
    int matrix[SIZE][SIZE];

    // llenar aleatoriamente
    printf("Matriz generada aleatoriamente:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 9 + 1;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (esCuadradoMagico(matrix))
        printf("La matriz ES un cuadrado mágico.\n");
    else
        printf("La matriz NO es un cuadrado mágico.\n");

    return 0;
}
