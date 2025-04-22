#include<stdio.h>
void sort(int arr[], int n){
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } 
        }
    }
}
int main(){
    int arr[] = {10,12,5,23,89,65};
    sort(arr,6);
    for(int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
}