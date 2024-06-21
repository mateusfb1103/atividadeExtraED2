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

// Estrutura para representar uma fila (queue) usada na BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
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

// Função para criar uma fila (queue)
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    if (!queue) {
        perror("Falha ao alocar memória para a fila");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // Inicializa o índice do último elemento da fila
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    if (!queue->array) {
        perror("Falha ao alocar memória para o vetor da fila");
        exit(EXIT_FAILURE);
    }
    return queue;
}

// Função para verificar se a fila está vazia
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Função para verificar se a fila está cheia
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Função para enfileirar um item na fila
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Fila cheia\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Função para desenfileirar um item da fila
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Função para realizar a busca em largura (BFS)
void BFS(struct Graph* graph, int startVertex) {
    // Cria uma fila para a BFS
    struct Queue* queue = createQueue(graph->numVertices);

    // Marca o vértice inicial como visitado e o enfileira
    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        // Desenfileira um vértice da fila e imprime
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Percorre todos os vértices adjacentes ao vértice desenfileirado
        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                // Marca o vértice adjacente como visitado e o enfileira
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }

    // Libera a memória usada pela fila
    free(queue->array);
    free(queue);
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

    printf("Busca em largura (BFS) a partir do vértice 2:\n");
    BFS(graph, 2); // Começa a busca em largura a partir do vértice 2

    return 0;
}


//Explicação do Código
//Estruturas de Dados:

//struct Node: Representa um nó da lista de adjacências.
//struct Graph: Representa o grafo usando listas de adjacências e inclui um vetor visited para controlar os vértices visitados.
//struct Queue: Representa a fila utilizada na BFS, com funções para criar, enfileirar, desenfileirar, verificar se está vazia ou cheia.
//Função createNode:

//Cria um novo nó na lista de adjacências com o vértice v.
//Função createGraph:

//Cria um grafo com um número específico de vértices, inicializando a lista de adjacências e o vetor visited.
//Função addEdge:

//Adiciona uma aresta ao grafo entre os vértices src e dest, criando um novo nó na lista de adjacências de src.
//Função createQueue, isEmpty, isFull, enqueue, dequeue:

//Funções auxiliares para operar na fila utilizada pela BFS. createQueue cria a fila, isEmpty verifica se está vazia, isFull verifica se está
