#include "graph.h"
#include "heap.h"

Node *graph;

int main(void)
{
    int nodes;
    int edges;
    int source, dest, cost;
    int i;
    void *heap;

    // printf("%s", "enter no. of nodes and edges : ");
    scanf("%d %d", &nodes, &edges);
    graph = create_graph(nodes);
    heap = create_list(nodes);

    i = edges;
    while(i --)
    {
        // printf("%s", "source - dest - cost : : ");
        scanf("%d %d %d", &source, &dest, &cost);
        add_edge(source, dest, cost);
    }

    print_graph(nodes);
    // printf("%s", "enter the source : ");
    scanf("%d", &source);


    call_dijkestra(heap, source, nodes);
    printf("\n" );

    for(i = 0; i < nodes; ++i)
    {
        printf("%d : %d (p : %d)\n", i , graph[i].d, graph[i].p);
    }


    return 0;
}