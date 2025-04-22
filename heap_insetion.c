#include<stdio.h>
#define max 100
int size = 0;
void insert(int heap[], int val){
    if(size >= max){
        printf("heap is full");
        return;
    }else{
        int current = size++;
        heap[current] = val;
        while(current != 0){
            int parent = (current - 1) / 2;
            if(heap[current] > heap[parent]){
                int temp = heap[current];
                heap[current] = heap[parent];
                heap[parent] = temp;
                current = parent;
            }else{
                break;
            }
        }
        
    }
}

void printHeap(int heap[], int size) {
    printf("Max-Heap array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main(){
    
    int val, n;
    int heap[max];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &val);
        insert(heap,val);
    }

    printHeap(heap,size);
    
}