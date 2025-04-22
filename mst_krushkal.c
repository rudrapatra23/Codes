#include<stdio.h>
#include<stdlib.h>
int comparator(const int p1[], const int p2[]){
    return p1[2] - p2[2];
}

void disjoint_set(int parent[], int rank[], int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_parent(int parent[], int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find_parent(parent,parent[node]);
}

void union_set(int u, int v, int parent[], int rank[], int n){
    u = find_parent(parent, u);
    v = find_parent(parent, v);
    if(rank[u]>rank[v]){
        parent[v] = u;
    }
    else if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else{
        parent[u] = v;
        rank[v]++;
    }
}
int krushkalMST(int n, int edge[n][3]){
    qsort(edge, n, sizeof(edge[0]),comparator);
    int parent[n];
    int rank[n];
    int min_weight = 0;
    disjoint_set(parent,rank,n);
    for(int i = 0; i < n; i++){
        int v1 = find_parent(parent, edge[i][0]);
        int v2 = find_parent(parent, edge[i][1]);
        int weight = edge[i][2];
        if(v1 != v2){
            union_set(v1, v2, parent, rank, n);
            min_weight += weight;
        }
    }
    return min_weight;
}

int main(){
    int n;
    printf("Enter the number of edge: ");
    scanf("%d", &n);
    int edge[n][3];
    for(int i = 0; i < n; i++){
        printf("Enter the details of %dvertex in this format (starting, ending, weight): ",i+1);
        scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
    }
    printf("minimum cost: %d", krushkalMST(n,edge));
}