#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_index;

    // Percorre o vetor até o penúltimo elemento
    for (i = 0; i < n-1; i++) {
        // Encontra o índice do menor elemento no vetor não ordenado
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Troca o elemento atual com o menor elemento encontrado
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    printf("Array ordenado em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


//Explicação do Código:
//selectionSort(int arr[], int n): Esta função recebe um vetor arr de inteiros e seu tamanho n. Implementa o algoritmo Selection Sort para ordenar o vetor em ordem crescente.

//main():

//Define o vetor inicial arr.
//Calcula o tamanho do vetor n utilizando sizeof(arr) / sizeof(arr[0]).
//Imprime o vetor original.
//Chama a função selectionSort(arr, n) para ordenar o vetor.
//Imprime o vetor ordenado.
//Funcionamento do Selection Sort:

//O algoritmo divide o vetor em duas partes: a parte ordenada e a parte não ordenada.
//A cada iteração, encontra o menor elemento na parte não ordenada e o move para o final da parte ordenada.
//Após n-1 iterações, o vetor estará ordenado.
//No exemplo dado (int arr[] = {64, 25, 12, 22, 11};), o vetor será ordenado para {11, 12, 22, 25, 64} após a execução do Selection Sort.
