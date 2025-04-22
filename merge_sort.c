#include<stdio.h>
void merge(int arr[], int l,int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1],R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + j + 1];
    }
    int k = l;
    int i = 0;
    int j = 0;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}
void merge_sort(int arr[], int l, int h){
    if(l < h){
        int mid = (l+h)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main(){
    int arr[] = {10,12,5,23,89,65};
    merge_sort(arr,0,6);
    for(int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
}