#include<stdio.h>
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(i < high && arr[i] <= pivot){
            i++;
        }
        while(j > low && arr[j] > pivot){
            j--;
        }
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void sort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr,low,high);
        sort(arr,low,pivot-1);
        sort(arr,pivot+1,high);
    }
}
int main(){
    int arr[] = {10,12,5,23,89,65};
    sort(arr,0,5);
    for(int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
}