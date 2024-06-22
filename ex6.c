#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Últimos i elementos já estão no lugar certo
        for (j = 0; j < n-i-1; j++) {
            // Troca se o elemento atual for maior que o próximo
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Array ordenado em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}



//Explicação do Código:
//bubbleSort(int arr[], int n): Esta função recebe um vetor arr de inteiros e seu tamanho n. Implementa o algoritmo Bubble Sort para ordenar o vetor em ordem crescente.

//main():

//Define o vetor inicial arr.
//Calcula o tamanho do vetor n utilizando sizeof(arr) / sizeof(arr[0]).
//Imprime o vetor original.
//Chama a função bubbleSort(arr, n) para ordenar o vetor.
//Imprime o vetor ordenado.
//Funcionamento do Bubble Sort:

//O algoritmo percorre o vetor várias vezes (passes).
//A cada passagem, compara cada par de elementos adjacentes.
//Se um elemento for maior que o próximo, eles são trocados de lugar.
//Após cada passagem completa pelo vetor, o maior elemento da parte não ordenada é colocado na posição correta.
//O processo é repetido até que nenhum swap seja necessário em uma passagem, indicando que o vetor está ordenado.
//No exemplo dado (int arr[] = {64, 34, 25, 12, 22, 11, 90};), o vetor será ordenado para {11, 12, 22, 25, 34, 64, 90} após a execução do Bubble Sort.



