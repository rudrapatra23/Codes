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

void countSort(int arr[], int n, int exp){
    int hash[10];
    for(int i =0; i < 10; i++){
        hash[i] = 0;
    }
    for(int i = 0; i < n; i++){
        hash[(arr[i]/exp)%10]++;
    }
    for(int i = 1; i < 10; i++){
        hash[i] += hash[i - 1];
    }
    int final[n];
    for(int i = n - 1; i >= 0; i--){
        final[--hash[(arr[i]/exp)%10]] = arr[i];
    }
    for(int i = 0; i < n; i++){
        arr[i] = final[i];
    }
}
void radix_sort(int arr[], int n){
    int maxi = max(arr,n);
    for(int i = 1; maxi/i > 0; i *= 10){
        countSort(arr,n,i);
    }
}
int main(){
    int n = 5;
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter the %dth digit: ", i+1);
        scanf("%d",&arr[i]);
    }
    radix_sort(arr,n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

}