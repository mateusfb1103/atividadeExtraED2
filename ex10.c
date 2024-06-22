#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria vetores temporários
    int L[n1], R[n2];

    // Copia dados para vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mescla os vetores temporários de volta em arr[l..r]
    i = 0; // Índice inicial para o subvetor esquerdo
    j = 0; // Índice inicial para o subvetor direito
    k = l; // Índice inicial para mesclar no vetor original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Calcula o meio do vetor

        // Ordena as duas metades recursivamente
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Junta as duas metades ordenadas
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Array ordenado em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


//Explicação do Código:
//merge(int arr[], int l, int m, int r): Esta função mescla dois subvetores de arr[]. O primeiro subvetor é arr[l..m] e o segundo é arr[m+1..r]. Os subvetores são mesclados em ordem crescente.

//mergeSort(int arr[], int l, int r): Esta função implementa o Merge Sort recursivamente. Ela divide o vetor em duas metades, chama a si mesma para as duas metades e, então, chama a função merge() para mesclar as duas metades ordenadas.

//main():

//Define o vetor inicial arr.
//Calcula o tamanho do vetor n utilizando sizeof(arr) / sizeof(arr[0]).
//Imprime o vetor original.
//Chama a função mergeSort(arr, 0, n - 1) para ordenar o vetor.
//Imprime o vetor ordenado.
//Funcionamento do Merge Sort:

//Divide o vetor em duas metades recursivamente até que cada subvetor tenha um único elemento.
//Mescla os subvetores ordenados para formar subvetores maiores, até que todo o vetor seja ordenado.
//No exemplo dado (int arr[] = {12, 11, 13, 5, 6, 7};), o vetor será ordenado para {5, 6, 7, 11, 12, 13} após a execução do Merge Sort.



