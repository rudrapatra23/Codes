#include<stdio.h>
void sort(int arr[], int n){
    
    for(int i = 1; i < n; i++){
        int key,j;
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}
int main(){
    int arr[] = {10,12,5,23,89,65};
    sort(arr,6);
    for(int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
}