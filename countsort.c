#include<stdio.h>
#include<limits.h>
int max(int arr[], int n){
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}
void sort(int arr[], int n){
    int m = max(arr,n);
    int hash[m+1];
    for(int i = 0; i <= m; i++){
        hash[i] = 0;
    }
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    for(int i = 1; i <= m; i++){
        hash[i] += hash[i-1];
    }
    int final[n];
    for(int i = n - 1; i >= 0; i--){
        final[--hash[arr[i]]] = arr[i];
    }
    for(int i = 0; i < n; i++){
        printf("%d ", final[i]);
    }
}
int main(){
    int arr[] = {10,12,5,23,89,65};
    sort(arr,6);
    
}
