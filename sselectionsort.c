#include<stdio.h>
#include<limits.h>
void sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int mini = i;
        for(int j = i+1; j < n; j++){
            if(arr[j]< arr[mini]){
                mini = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
    }
}
int main(){
    int arr[] = {10,12,5,23,89,65};
    sort(arr,6);
    for(int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
}