#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move os elementos do arr[0..i-1] que são maiores que key
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("Array ordenado em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


//Explicação do Código:
//insertionSort(int arr[], int n): Esta função recebe um vetor arr de inteiros e seu tamanho n. Implementa o algoritmo Insertion Sort para ordenar o vetor em ordem crescente.

//main():

//Define o vetor inicial arr.
//Calcula o tamanho do vetor n utilizando sizeof(arr) / sizeof(arr[0]).
//Imprime o vetor original.
//Chama a função insertionSort(arr, n) para ordenar o vetor.
//Imprime o vetor ordenado.
//Funcionamento do Insertion Sort:

//Começa com o segundo elemento (i = 1) e o compara com os elementos anteriores na parte ordenada.
//Move elementos maiores um lugar para a direita até encontrar a posição correta para inserir o elemento atual.
//Repete o processo até que todos os elementos estejam na parte ordenada.
//No exemplo dado (int arr[] = {12, 11, 13, 5, 6};), o vetor será ordenado para {5, 6, 11, 12, 13} após a execução do Insertion Sort.
