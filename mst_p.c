#include<stdio.h>
#include<limits.h>
int minkey(int visited[], int key[], int v){
	int min = INT_MAX;
	int min_idx;
	for(int i = 0; i < v; i++){
		if(key[i] < min && visited[i] == 0){
			min = key[i];
			min_idx = i;
		}
	}
	return min_idx;
}
void print(int parent[], int v, int graph[v][v]){
	int weight = 0;
	printf("The minimum Spanning tree is: \n");
	printf("Edge\tWeight\n");
	for(int i = 1; i < v; i++){
		printf("%d - %d  %d\n", parent[i],i,graph[i][parent[i]]);
		weight += graph[i][parent[i]];
	}
	printf("Minimum cost: %d", weight);
}
void mst(int v, int graph[v][v]){
	int parent[v];
	int key[v];
	int visited[v];
	for(int i = 0; i < v; i++){
		key[i] = INT_MAX;
		visited[i] = 0;
	}
	parent[0] = -1;
	key[0] = 0;
	for(int count = 0; count < v; count++){
		int u = minkey(visited, key,v);
		visited[u] = 1;
		for(int x = 0; x < v; x++){
			if(visited[x] == 0 && graph[u][x] != INT_MAX && graph[u][x] < key[x]){
				parent[x] = u;
				key[x] = graph[u][x];
			}
		}
	}
	print(parent, v, graph);
}
int main(){
	int v;
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	int graph[v][v];
	for(int i  = 0; i < v; i++){
		graph[i][i] = 0;
	}
	 for (int i = 0; i < v; i++) {
        for (int j = i+1; j < v; j++) {
            int x;
            printf("Enter the weight of the edge present between %d and %d, if not enter 0: ",i,j);
            scanf("%d", &x);
            if(x == 0) 
                x = INT_MAX;
            graph[i][j] = x;
            graph[j][i] = x;
        }
    }
    mst(v, graph);
}
