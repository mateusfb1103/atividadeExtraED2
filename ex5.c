#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9 // Número de vértices no grafo

// Função para encontrar o vértice não visitado com a menor distância
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Função para imprimir o caminho mínimo
void printPath(int parent[], int j) {
    // Caso base: quando chega no vértice inicial
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf(" -> %d", j);
}

// Função para imprimir a solução, ou seja, as distâncias mínimas do vértice inicial
void printSolution(int dist[], int parent[], int src) {
    printf("Vértice   Distância do vértice inicial   Caminho\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d \t\t\t\t %d", i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

// Função que implementa o algoritmo de Dijkstra para um grafo representado por matriz de adjacências
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Array para armazenar as distâncias mais curtas do vértice inicial
    int visited[V]; // Array para verificar se o vértice foi visitado
    int parent[V]; // Array para armazenar o caminho mínimo

    // Inicialização das distâncias como infinito e marcando todos os vértices como não visitados
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0; // Distância do vértice inicial para ele mesmo é zero

    // Encontrar o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolher o vértice com a menor distância não visitado
        int u = minDistance(dist, visited);

        // Marcar o vértice escolhido como visitado
        visited[u] = 1;

        // Atualizar a distância de vértices adjacentes ao vértice escolhido
        for (int v = 0; v < V; v++) {
            // Atualizar dist[v] apenas se ainda não foi visitado, há um caminho de u para v e
            // o peso total do caminho de src para v através de u é menor que o valor atual de dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Imprimir as distâncias calculadas e os caminhos mínimos
    printSolution(dist, parent, src);
}

// Função principal
int main() {
    // Exemplo de matriz de adjacências do grafo
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    // Chamada da função Dijkstra para encontrar as distâncias mínimas do vértice 0
    dijkstra(graph, 0);

    return 0;
}


//Explicação do Código
//Definições e Inicialização:

//V é definido como o número de vértices no grafo.
//A função minDistance é usada para encontrar o vértice não visitado com a menor distância dist[].
//printPath é uma função recursiva para imprimir o caminho mínimo a partir do vértice inicial até um vértice específico.
//printSolution imprime as distâncias mínimas calculadas e os caminhos mínimos a partir do vértice inicial.
//Função dijkstra:

//graph[V][V] representa a matriz de adjacências do grafo com pesos.
//dist[V] armazena as distâncias mínimas do vértice inicial (src) a cada vértice.
//visited[V] é usado para marcar os vértices como visitados durante a execução do algoritmo.
//parent[V] é usado para armazenar o caminho mínimo de src a cada vértice.
//A função itera V-1 vezes para encontrar as distâncias mínimas para todos os vértices.
//Dentro do loop, o vértice com a menor distância não visitada é escolhido (u).
//A função atualiza as distâncias de todos os vértices adjacentes a u que ainda não foram visitados, considerando o peso das arestas.
//Função main:

//Define um exemplo de matriz de adjacências graph para um grafo de exemplo com 9 vértices.
//Chama a função dijkstra(graph, 0) para encontrar as distâncias mínimas a partir do vértice 0.
//Execução e Resultado Esperado
//Ao executar o programa, ele calculará e imprimirá as distâncias mínimas a partir do vértice inicial (neste caso, vértice 0) para todos os outros vértices no grafo de exemplo fornecido. O resultado esperado é uma tabela mostrando a distância de 0
