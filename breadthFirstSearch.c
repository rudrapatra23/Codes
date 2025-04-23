#include <stdio.h>
#include<stdlib.h>
struct queue{
	int *items;
	int rear;
	int front;
	int size;
};
int isFull(struct queue *ptr)
{
	if(ptr->rear==ptr-> size-1){
		printf("queue is full");
		return 1;
	}else{
		return 0;
	}
}
int isEmpty(struct queue *ptr){
	if(ptr->front == ptr->rear){
		return 1;
	}else{
		return 0;
	}
}
void enqueue(struct queue *ptr, int val)
{
	if(isFull(ptr)){
		printf("Queue is full\n");
	}
	else{
		ptr->rear++;
		ptr->items[ptr->rear] = val;
	}
}
int dequeue(struct queue *ptr){
	int a = -1;
	if(isEmpty(ptr)){
		printf("the queue is empty\n"); 
	}else{
		ptr->front++;
		a = ptr->items[ptr->front];
	}
	return a;
}
int main(){
	struct queue *ptr = (struct queue*)malloc(sizeof(struct queue)); 
	int n;
	printf("Enter the number of nodes in the graph: ");
	scanf("%d",&n); 
	ptr->size = n;
	ptr->front = ptr->rear = -1;
	ptr->items = (int*)malloc(ptr->size * sizeof(int));
	int arr[n][n];
	for(int i = 0; i < n ; i++){
		arr[i][i] = 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int x;
			printf("If there is edge between node %d and %d enter 1 else 0: ", i,j);
			scanf("%d", &x);  
			arr[i][j] = x;   
			arr[j][i] = x;    
		}
	}
	int visited[n];
	for (int i = 0; i < n; ++i)	{
		visited[i] = 0;
	}
	int u;
	printf("Enter the starting vertex: ");
	scanf("%d",&u);  
	printf("Graph is starting from -> %d",u );  
	enqueue(ptr,u);
	visited[u] = 1;
	while(!isEmpty(ptr)){
		int node = dequeue(ptr);
		for(int i = 0; i < n; i++) {
			if (arr[node][i]==1 && visited[i] == 0)
			{
				printf("->%d", i);
				enqueue(ptr, i);
				visited[i] = 1;
			}
		}
	}
	printf("\n");
	free(ptr->items);
	free(ptr);
	return 0;
}