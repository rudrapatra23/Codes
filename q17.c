#include<stdio.h>
#include<stdlib.h>  
struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *s){
    if(!isFull(s)){
        int val;
        printf("Enter the value to be pushed: ");
        scanf("%d",&val);
        s->top++;
        s->arr[s->top] = val;
    }else{
        printf("The stack is already full.");
    }
}
void pop(struct stack *s){
    
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        s->top--;
    }
}
void multipop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        int times;
        printf("Enter number of elements to pop: ");
        scanf("%d", &times);
        for (int i = 0; i < times; i++) {   
            if (!isEmpty(s)) {
                pop(s);
            }else{
                printf("Can not pop %d elements at a time...", times);
            }
        }
    }
}
void view(struct stack *s){
    printf("%d is on top of the stack.\n",s->arr[s->top]);
}
int main(){
    int val,times;
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    printf("Enter the size of the stack:");
    scanf("%d", &s->size);
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    int choice;
    while(1){
        printf("Press 1 to push\nPress 2 to pop\nPress 3 to multiple pop\nPress 4 to view\nPress 5 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push(s);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                multipop(s);
                break;
            case 4:
                view(s);
                break;
            case 5:
                free(s); 
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

}   
