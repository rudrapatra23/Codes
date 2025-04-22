#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void comp_lps(char *pattern, int n, int lps[]){
    int length = 0;
    int i = 1;
    lps[0] = 0;
    while(i < n){
        if(pattern[i] == pattern[length]){
            length++;
            lps[i] = length;
            i++;
        }else{
            if(length != 0){
                length = lps[length - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char *pattern, char *text){
    int m = strlen(text);
    int n = strlen(pattern);
    int lps[n];
    comp_lps(pattern,n,lps);
    int i = 0;
    int j = 0;
    int found = 0;
    while(i < m){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j == n){
            printf("Pattern found at index: %d", i - j);
            j = lps[j - 1];
            found = 1;
        }
        else if(i < m && pattern[j] != text[i]){
            if(j != 0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
    }
    if(!found){
        printf("Pattren not found...");
    }
}

int main(){
    char x[100];
    char y[50];
    printf("Enter the text: ");
    fgets(x,sizeof(x), stdin);
    x[strcspn(x, "\n")] = '\0';
    printf("enter the pattern: ");
    fgets(y, sizeof(y), stdin);
    y[strcspn(y, "\n")] = '\0';
    kmp(y,x);
}
