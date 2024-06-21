#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista de adjacências
struct Node {
    int vertex;
    struct Node* next;
};

// Estrutura para representar a lista de adjacências
struct Graph {
    int numVertices;
    struct Node** adjList;
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

    return graph;
}

// Função para adicionar uma aresta não direcionada ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    // Adiciona uma aresta de src para dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Adiciona uma aresta de dest para src (grafo não direcionado)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Função para remover uma aresta entre dois vértices
void removeEdge(struct Graph* graph, int u, int v) {
    // Verifica se u e v são vértices válidos
    if (u < 0 || u >= graph->numVertices || v < 0 || v >= graph->numVertices) {
        printf("Erro: Vértices inválidos.\n");
        return;
    }

    // Remove a aresta u -> v
    struct Node* prev = NULL;
    struct Node* curr = graph->adjList[u];
    while (curr != NULL && curr->vertex != v) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Erro: Aresta não encontrada.\n");
        return;
    }
    if (prev == NULL) {
        graph->adjList[u] = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);

    // Remove a aresta v -> u
    prev = NULL;
    curr = graph->adjList[v];
    while (curr != NULL && curr->vertex != u) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Erro: Aresta não encontrada.\n");
        return;
    }
    if (prev == NULL) {
        graph->adjList[v] = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);

    printf("Aresta entre %d e %d removida com sucesso.\n", u, v);
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Lista de adjacencias do vertice %d:\nhead", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Função principal
int main() {
    int numVertices = 5; // Exemplo: um grafo com 5 vértices
    struct Graph* graph = createGraph(numVertices);

    // Exemplo de adição de arestas
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Grafo original:\n");
    printGraph(graph);

    // Exemplo de remoção de aresta
    removeEdge(graph, 1, 4);

    printf("\nGrafo apos a remocao da aresta entre 1 e 4:\n");
    printGraph(graph);

    return 0;
}


//Explicação do Código
//Estruturas Utilizadas:

//struct Node: Representa um nó da lista de adjacências.
//struct Graph: Representa o grafo utilizando listas de adjacências.
//Função createNode:

//Cria um novo nó na lista de adjacências com o vértice v.
//Função createGraph:

//Cria um grafo com um número específico de vértices, inicializando a lista de adjacências.
//Função addEdge:

//Adiciona uma aresta não direcionada entre os vértices src e dest, atualizando as listas de adjacências de ambos os vértices.
//Função removeEdge:

//Remove a aresta entre os vértices u e v, percorrendo as listas de adjacências dos dois vértices e removendo o vértice correspondente.
//Função printGraph:

//Imprime o grafo mostrando todas as listas de adjacências.
//Função main:

//Exemplo de criação de um grafo com 5 vértices e adição de várias arestas.
//Demonstração da remoção de uma aresta entre os vértices 1 e 4.
//Observações
//Este código é capaz de lidar com grafos não direcionados.
//A função removeEdge é implementada de forma eficiente, percorrendo as listas de adjacências apenas uma vez para cada vértice.
//A estrutura de dados escolhida (lista de adjacências) é eficiente para grafos esparsos.
//Este programa em C é um exemplo básico e funcional para remover uma aresta entre dois vértices em um grafo representado por listas de adjacências. Ele pode ser expandido com mais funcionalidades, como verificação de existência de arestas antes da remoção, tratamento de casos especiais, entre outros.
