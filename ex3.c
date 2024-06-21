#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista de adjacências
struct Node {
    int vertex;
    struct Node* next;
};

// Estrutura para representar o grafo usando listas de adjacências
struct Graph {
    int numVertices;
    struct Node** adjList;
    int* visited; // Vetor para controlar os vértices visitados
};

// Função para criar um novo nó na lista de adjacências
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Falha ao alocar memória para o novo nó");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com um número específico de vértices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    if (!graph) {
        perror("Falha ao alocar memória para o grafo");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = numVertices;

    // Criação da lista de adjacências
    graph->adjList = (struct Node**) malloc(numVertices * sizeof(struct Node*));
    if (!graph->adjList) {
        perror("Falha ao alocar memória para a lista de adjacências");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL; // Inicializa cada lista como vazia
    }

    // Vetor para controlar os vértices visitados
    graph->visited = (int*) malloc(numVertices * sizeof(int));
    if (!graph->visited) {
        perror("Falha ao alocar memória para o vetor de visitados");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < numVertices; i++) {
        graph->visited[i] = 0; // Inicializa todos os vértices como não visitados
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    // Adiciona uma aresta de src para dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Função recursiva para realizar a busca em profundidade (DFS)
void DFS(struct Graph* graph, int vertex) {
    // Marca o vértice como visitado
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    // Percorre todos os vértices adjacentes ao vértice atual
    struct Node* adjList = graph->adjList[vertex];
    while (adjList != NULL) {
        int adjVertex = adjList->vertex;
        if (graph->visited[adjVertex] == 0) {
            DFS(graph, adjVertex); // Chama recursivamente DFS se o vértice adjacente não foi visitado
        }
        adjList = adjList->next;
    }
}

// Função principal
int main() {
    int numVertices = 5; // Exemplo: um grafo com 5 vértices
    struct Graph* graph = createGraph(numVertices);

    // Exemplo de adição de arestas ao grafo
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("Busca em profundidade (DFS) a partir do vértice 2:\n");
    DFS(graph, 2); // Começa a busca em profundidade a partir do vértice 2

    return 0;
}


//Explicação do Código
//Estruturas de Dados:

//struct Node: Representa um nó da lista de adjacências.
//struct Graph: Representa o grafo usando listas de adjacências e inclui um vetor visited para controlar os vértices visitados.
//Função createNode:

//Cria um novo nó na lista de adjacências com o vértice v.
//Função createGraph:

//Cria um grafo com um número específico de vértices, inicializando a lista de adjacências e o vetor visited.
//Função addEdge:

//Adiciona uma aresta ao grafo entre os vértices src e dest, criando um novo nó na lista de adjacências de src.
//Função DFS:

//Implementa a busca em profundidade (DFS) a partir de um vértice vertex.
//Marca o vértice como visitado, imprime-o e chama recursivamente DFS para cada vértice adjacente não visitado.
//Função main:

//Exemplo de criação de um grafo com 5 vértices e adição de várias arestas.
//Chama DFS a partir do vértice 2 e imprime a sequência de vértices visitados.
//Execução e Resultado Esperado
//Ao executar o programa, ele realizará a busca em profundidade a partir do vértice 2 do grafo de exemplo criado. A saída esperada será a sequência de vértices visitados durante a travessia do grafo, seguindo o princípio de visitar o mais fundo possível antes de retroceder.

//Considerações Finais
//Este código fornece uma implementação básica e funcional da busca em profundidade (DFS) em um grafo representado por listas de adjacências em C. Você pode expandir este código para incluir mais funcionalidades, como a impressão dos caminhos encontrados, a verificação de componentes conexos, entre outros. É uma base sólida para entender e implementar algoritmos de busca em grafos usando estruturas de dados simples e eficientes.
