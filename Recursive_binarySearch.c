#include<stdio.h>
int search(int arr[], int low, int high, int key){
    if(low<high){
        int mid = (low+high)/2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] < key){
            search(arr,mid+1, high, key);
        }else{
            search(arr,low, mid-1,key);
        }
    }
    return -1;
}
int main(){
    int arr[] = {1, 2 , 3 , 4 , 5 , 6 , 7};
    int key = 8;
    int l= 0;
    int h = 6;
    int x = search(arr,l,h,key);
    if(x >= 0){
        printf("Found at %d",x);
    }else{
        printf("Not found");
    }
}