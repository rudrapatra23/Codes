#include <stdio.h>
#include <stdlib.h>

void DFS(int i, int n, int adj[n][n], int visited[]){
    printf("%d ",i);
    visited[i]=1;
    for (int j = 0; j < n; j++)
    {
        if(adj[i][j]==1 && !visited[j]){
            DFS(j,n,adj,visited);
        }
    }
}

int main(){
    int n;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    int adj[n][n];
    for(int i = 0; i < n; i++){
        adj[i][i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int x;
            printf("Enter 1 if %d has a connection with %d else enter 0:",i,j);
            scanf("%d",&x);
            adj[i][j] = x;
            adj[j][i] = x;
        }
    }
    int visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    int start_node;
    printf("Enter the starting node:");
    scanf("%d",&start_node);
    printf("DFS Traversal starting from vertex %d:\n",start_node);
    DFS(start_node, n, adj, visited);
}
