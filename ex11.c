#include <stdio.h>

// Função para trocar dois elementos de posição
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o vetor e retornar o índice do pivô
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivô é o último elemento
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal que implementa o Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Obtém o índice do pivô após o particionamento
        int pi = partition(arr, low, high);

        // Ordena os elementos antes e depois do pivô recursivamente
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Array ordenado em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}



//Explicação do Código:
//swap(int a, int b)**: Esta função auxiliar troca os valores de dois elementos utilizando ponteiros.

//partition(int arr[], int low, int high): Esta função escolhe o pivô (aqui escolhido como o último elemento), rearranja os elementos do vetor de modo que os elementos menores que o pivô fiquem à esquerda e os maiores à direita, e retorna o índice do pivô após o particionamento.

//quickSort(int arr[], int low, int high): Esta função implementa o Quick Sort recursivamente. Ela escolhe um pivô, particiona o vetor ao redor do pivô e chama a si mesma recursivamente para as duas subpartições.

//main():

//Define o vetor inicial arr.
//Calcula o tamanho do vetor n utilizando sizeof(arr) / sizeof(arr[0]).
//Imprime o vetor original.
//Chama a função quickSort(arr, 0, n - 1) para ordenar o vetor.
//Imprime o vetor ordenado.
//Funcionamento do Quick Sort:

//Seleciona um elemento como pivô e rearranja o vetor de modo que os elementos menores que o pivô fiquem à esquerda e os maiores à direita.
//Aplica o mesmo procedimento recursivamente nas subpartições até que todo o vetor esteja ordenado.
//No exemplo dado (int arr[] = {10, 7, 8, 9, 1, 5};), o vetor será ordenado para {1, 5, 7, 8, 9, 10} após a execução do Quick Sort.
