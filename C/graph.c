typedef struct graph{
    int vertices;
    struct Node** adj;
} graph;

typedef struct Node{
    int data;
    struct Node* next;
} Node;

graph* createGraph(int v){
    graph* newGraph = (graph*)malloc(sizeof(graph));
    newGraph->vertices = v;
    newGraph->adj = (Node**)malloc(v * sizeof(Node*));
    for(int i = 0;i < v;i++){
        newGraph->adj[i] = NULL;
    }
    return newGraph;
}

void addEdge(graph* G, int parent, int child){
    Node* newEdge = (Node*)malloc(sizeof(Node));
    Node* newEdge2 = (Node*)malloc(sizeof(Node));
    newEdge->data = child;
    newEdge->next = G->adj[parent];
    G->adj[parent] = newEdge;
    // For Bidirection
    newEdge2->data = parent;
    newEdge2->next = G->adj[child];
    G->adj[child] = newEdge2;
}

void printGraph(graph* G){
    for(int i = 0;i < G->vertices;i++){
        Node* temp = G->adj[i];
        printf("%d: ", i);
        while(temp){
            printf("%d, ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
