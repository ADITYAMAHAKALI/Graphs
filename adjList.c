#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node* next;
}node;
node* createNode(int);

typedef struct Graph {
  int numVertices;
  struct node** adjLists;
}graph;

// Create a node
node* createNode(int v) {
    node* newNode = malloc(sizeof(node));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}


graph* createAGraph(int vertices) {
    graph* g = malloc(sizeof(graph));
    g->numVertices = vertices;
    g->adjLists = malloc(vertices * sizeof(node*));
    int i;
    for(i = 0; i < vertices; i++)
        g->adjLists[i] = NULL;
    return g;
}

// Add edge
void addEdge(graph* g, int s, int d) {
  // Add edge from s to d
  node* newNode = createNode(d);
  newNode->next = g->adjLists[s];
  g->adjLists[s] = newNode;

  // Add edge from d to s
  newNode = createNode(s);
  newNode->next = g->adjLists[d];
  g->adjLists[d] = newNode;
}

// Print the graph
void printGraph(graph* g) {
  int v;
  for (v = 0; v < g->numVertices; v++) {
    node* temp = g->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->value);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
    struct Graph* graph = createAGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    printGraph(graph);

    return 0;
}