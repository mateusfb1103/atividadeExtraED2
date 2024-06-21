#include <stdio.h>

#define MAX_VERTICES 100

int main() {
    int n; // número de vértices
    int adj[MAX_VERTICES][MAX_VERTICES]; // matriz de adjacências
    int u, v; // vértices a conectar com a nova rua

    // Entrada do número de vértices
    printf("Digite o numero de vertices: ");
    scanf("%d", &n);

    // Inicialização da matriz de adjacências com zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Inserção de nova rua
    printf("\nInsira uma nova rua (entre dois vertices):\n");
    printf("Vertice u: ");
    scanf("%d", &u);
    printf("Vertice v: ");
    scanf("%d", &v);

    // Verificação se u e v são válidos
    if (u < 0 || u >= n || v < 0 || v >= n) {
        printf("Vertices invalidos!\n");
        return 1; // saída do programa com erro
    }

    // Atualização da matriz de adjacências para a nova rua (bidirecional)
    adj[u][v] = 1;
    adj[v][u] = 1;

    // Exibição da matriz de adjacências atualizada
    printf("\nMatriz de adjacencias atualizada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//Inicialização da Matriz de Adjacências:

//A matriz adj é inicializada com todos os elementos iguais a zero, indicando que inicialmente não há ruas entre quaisquer pares de interseções.
//Inserção de Nova Rua:

//O programa solicita ao usuário os vértices u e v que deseja conectar com uma nova rua.
//Verifica se u e v são válidos.
//Se forem válidos, a matriz de adjacências é atualizada para refletir a nova rua entre u e v.
//Exibição da Matriz de Adjacências:

//Após a inserção da rua, a matriz de adjacências atualizada é exibida para que o usuário possa verificar as modificações realizadas.
//Este programa básico permite a inserção de uma rua entre quaisquer duas interseções em um grafo representado por uma matriz de adjacências em C. Ele é adequado para um número razoável de vértices (MAX_VERTICES definido como 100 neste exemplo) e pode ser expandido conforme necessário para incluir mais funcionalidades ou tratamento de erros específicos. 
