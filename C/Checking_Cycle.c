#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool present = 0;

struct node
{
    int data;
    struct node *next;
};

struct graph
{
    int vertices;
    struct node **adj;
    int *visited;
};

struct graph *create_graph(int n)
{

    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->vertices = n;
    g->adj = (struct node **)malloc(sizeof(struct node *));
    g->visited = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        g->adj[i] = NULL;
        g->visited[i] = 0;
    }

    return g;
}

void check_cycle(struct graph *g, int vertice)
{
    struct node *temp = g->adj[vertice];
    if (temp){
        if (g->visited[temp->data])
        {
            printf("CYCLE DETECT\n");
            present=1;
        }

        else
        {
            g->visited[vertice] = 1;
            while (temp)
            {
                check_cycle(g, temp->data);
                temp = temp->next;
            }
            g->visited[vertice] = 0;
        }
    }
    return;
}

struct node *create_node(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

struct graph *add_edge(struct graph *g, int start, int end)
{

    struct node *temp = create_node(end);
    temp->next = g->adj[start];
    g->adj[start] = temp;

    return g;
}

void graph_Traversal(struct graph *g)
{
    for (int i = 0; i < g->vertices; i++)
    {
        struct node *temp = g->adj[i];
        printf("%d->", i);
        while (temp)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct graph *g = create_graph(5);
    g = add_edge(g, 0, 1);
    g = add_edge(g, 1, 2);
    g = add_edge(g, 2, 0);
    g = add_edge(g, 2, 4);
    g = add_edge(g, 4, 2);
    graph_Traversal(g);
    for (int i = 0; i < g->vertices; i++)
    {
        struct node *temp = g->adj[i];
        g->visited[i] = 1;
        while (temp)
        {
            check_cycle(g, temp->data);
            temp = temp->next;
            if(present==1)
            {
                break;
            }
        }
        g->visited[i] = 0;
        if(present==1)
        {
            break;
        }
    }
    return 0;
}