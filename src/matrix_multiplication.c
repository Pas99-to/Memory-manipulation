#include <stdio.h>
#include <stdlib.h>
//Orden de ejecución de los métodos 
void enterData();
int* initializeMatrix(int Mrows, int Mcolumns);
void enterMatrix(int *M, int Mrows, int Mcolumns);
void multiplyMatrices();
void displayResult();
void display(int *M, int Mrows, int Mcolumns);
void cleanMemory();
//variables a utilizar 
int *A, *B, *C;
int Arows, Acolumns, Brows, Bcolumns;

// Método main , retorna 0 al acabar los procedimientos
//probamos nuestro programa
int main() {
    enterData();
    multiplyMatrices();
    displayResult();
    cleanMemory();

    return 0;
}
// Método de entrada de datos de filas y columnas de la matriz A y B
void enterData() {
	do {
		printf("Ingrese filas y columnas para la matriz A: ");
		scanf("%d %d", &Arows, &Acolumns);
		printf("Ingrese filas y columnas para la matriz B: ");
		scanf("%d %d", &Brows, &Bcolumns);
	} while (Acolumns != Brows);

    A = initializeMatrix(Arows, Acolumns);
    B = initializeMatrix(Brows, Bcolumns);
    C = initializeMatrix(Arows, Bcolumns);

	printf("\nIngrese los elementos de A\n");
    enterMatrix(A, Arows, Acolumns);

	printf("\nIngrese los elementos de B\n");
    enterMatrix(B, Brows, Bcolumns);
}

void enterMatrix(int *M, int Mrows, int Mcolumns) {
	for(int row = 0; row < Mrows; ++row)
		for(int column = 0; column < Mcolumns; ++column) {
			printf("Ingrese elemento [%d,%d]: ", row + 1, column + 1);
                scanf("%d", M + row * Mcolumns + column);
		}
}

int* initializeMatrix(int Mrows, int Mcolumns) {
    return calloc(Mrows * Mcolumns, sizeof(int));
}

void multiplyMatrices()
{
	for(int row = 0; row < Arows; ++row) {
		for(int column = 0; column < Bcolumns; ++column) {
			for(int k=0; k < Acolumns; ++k) {
                *(C + row * Bcolumns + column) += (
                    *(A + row * Acolumns + k) * *(B + k * Bcolumns + column)
                );
			}
		}
	}
}

void displayResult() {
    printf("\nMatriz A\n");
    display(A, Arows, Acolumns);
    printf("Matriz B\n");
    display(B, Brows, Bcolumns);
    printf("Matriz C (Resultado)\n");
    display(C, Arows, Bcolumns);
}

void display(int *M, int Mrows, int Mcolumns)
{
	for(int row = 0; row < Mrows; ++row) {
        printf("\t");
		for(int column = 0; column < Mcolumns; ++column)
			printf("%2d ", *(M + row * Mcolumns + column));
        printf("\n");
	}
}

void cleanMemory() {
    free(A);
    free(B);
    free(C);
}
