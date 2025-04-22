#include<stdio.h>
#include<math.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int size, int t){
    int largest = t;
    int left = 2 * t + 1;
    int right = 2 * t +2;

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != t){
        swap(&arr[largest], &arr[t]);
        heapify(arr,size,largest);
    }
}

void heapsort(int arr[], int n){
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr,n,i);
    }
    for(int j = n - 1; j >= 0; j--){
        swap(&arr[0], &arr[j]);
        heapify(arr,j,0);
    }
}
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    heapsort(arr,n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}