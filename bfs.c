#include<stdio.h>

void BFS_function(int size,int array[size][size], int Start,int BFS[]){
    int queue[size], font = 0, rear = 0;
    for(int i = 0; i < size; i++ ){
        BFS[i] = Start;
        for(int j = 0; j < size; j++){

            if(array[Start][j] == 1){
                queue[rear] = j;

                array[BFS[i]][j] = 0;
                array[j][BFS[i]] = 0;
                rear++;
                for(int k=0;k<size;k++)
                array[k][j]=0;
            }
        }
        printf("\n");
        Start = queue[font];
        font++;
    }
}

int main(){
    printf("Enter the number of graph vertexs: ");
    int v;
    scanf("%d",&v);
    int graph[v][v];
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            graph[i][j] = 0;
        }
    }
    for(int i = 0; i < v; i++){
        for(int j = v-1; j != i; j--){
            if(i != j){
                printf("Is There any edge between vertex %d and vertex %d (For 'YES' enter '1' and For 'NO' enter '0'): ",i,j);
                scanf("%d",&graph[i][j]);
                graph[j][i] = graph[i][j];
            } else {
                graph[i][j] = 0;
                break;
            }
        }
    }
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    int start;
    printf("Enter the starting vertex number:");
    scanf("%d",&start);
    if(start >= v-1){
        printf("Vertex out of bound");
        exit(0);
    }
    int BFS[v];
    int graph_copy[v][v];
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            graph_copy[i][j] = graph[i][j];
        }
    }
    BFS_function(v,graph_copy,start,BFS);
    printf("Your BFS is: ");
    for(int i = 0; i < v; i++){
        printf("%d  ",BFS[i]);
    }
}