#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    // Começa com um gap grande, então reduz gradualmente
    for (gap = n/2; gap > 0; gap /= 2) {
        // Faz um Insertion Sort para os elementos com o gap atual
        for (i = gap; i < n; i++) {
            temp = arr[i];

            // Move os elementos que são maiores que temp para frente do seu gap
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Insere temp na sua posição correta
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shellSort(arr, n);

    printf("Array ordenado em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


//Explicação do Código:
//shellSort(int arr[], int n): Esta função recebe um vetor arr de inteiros e seu tamanho n. Implementa o algoritmo Shell Sort para ordenar o vetor em ordem crescente.

//main():

//Define o vetor inicial arr.
//Calcula o tamanho do vetor n utilizando sizeof(arr) / sizeof(arr[0]).
//Imprime o vetor original.
//Chama a função shellSort(arr, n) para ordenar o vetor.
//Imprime o vetor ordenado.
//Funcionamento do Shell Sort:

//Começa com um gap grande (n/2), depois reduz o gap pela metade a cada passo.
//Para cada gap, aplica o Insertion Sort para ordenar os subgrupos formados pelo gap.
//Continua reduzindo o gap até que ele seja igual a 1, quando o algoritmo se comporta como um Insertion Sort padrão.
//No exemplo dado (int arr[] = {12, 34, 54, 2, 3};), o vetor será ordenado para {2, 3, 12, 34, 54} após a execução do Shell Sort.
