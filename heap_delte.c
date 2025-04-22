#include<stdio.h>
#define max 100
int size = 0;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && heap[largest] < heap[l]){
        largest = l;
    }
    if(r < n && heap[largest] < heap[r]){
        largest = r;
    }
    if(i != largest){
        swap(&heap[largest], &heap[i]);
        heapify(heap,n,largest);
    }
}
void insert(int heap[], int num){
    int current = size++;
    heap[current] = num;
    while(current != 0){
        int parent = (current - 1) / 2;
        if(heap[current] > heap[parent]){
            swap(&heap[current], &heap[parent]);
            current = parent;
        }
        else{
            break;
        }
    }

}
void delete(int heap[], int num){
    int i;
    for(i = 0; i < size; i++){
        if(heap[i] == num){
            break;
        }
    }
    swap(&heap[i], &heap[size-1]);
    size--;
    heapify(heap,size,i);
}

void printHeap(int heap[], int size) {
    printf("Max-Heap array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int heap[max];
    int n, val, choice;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(heap, val);
    }

    printHeap(heap, size);

    printf("Enter value to delete from heap: ");
    scanf("%d", &val);
    delete(heap, val);

    printHeap(heap, size);

    return 0;
}
