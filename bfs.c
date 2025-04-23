#include <stdio.h>
#include<stdlib.h>
void BFS_function(int size, int array[size][size], int Start, int BFS[])
{
    int visited[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    int queue[size], front = 0, rear = 0;
    queue[rear++] = Start;
    visited[Start] = 1;

    int index = 0;

    while (front < rear)
    {
        int current = queue[front++];
        BFS[index++] = current;

        for (int i = 0; i < size; i++)
        {
            if (array[current][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    printf("Enter the number of graph vertexs: ");
    int v;
    scanf("%d", &v);
    int graph[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < v; i++)
    {
        graph[i][i] = 0;
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = i + 1; j < v; j++)
        {
            int x;
            printf("If there is edge between node %d and %d enter 1 else 0: ", i, j);
            scanf("%d", &x);
            graph[i][j] = x;
            graph[j][i] = x;
        }
    }
    int start;
    printf("Enter the starting vertex number:");
    scanf("%d", &start);
    if (start >= v - 1)
    {
        printf("Vertex out of bound");
        exit(0);
    }
    int BFS[v];
    int graph_copy[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            graph_copy[i][j] = graph[i][j];
        }
    }
    BFS_function(v, graph_copy, start, BFS);
    printf("Your BFS is: ");
    for (int i = 0; i < v; i++)
    {
        printf("%d  ", BFS[i]);
    }
}
