#include<stdio.h>

int main(){
    int c;
    int b;
    int a;
    printf("Enter first number\n");
    scanf("%d", &c);
    printf("Enter second number\n");
    scanf("%d", &b);
    printf("Choose\n0 -> Addition\n1 -> Subtration\n2 -> Multiplication\n3 -> Division\n");
    scanf("%d", &a);

    if(a == 0){
        printf("you choose addition\n");
        printf("%d", c+b);
    }
    if(a == 1){
         printf("you choose subtraction\n");
        printf("%d", c-b);
    }
    if(a == 2){
         printf("you choose multiplication\n");
        printf("%d", c*b);
    }
    if(a == 3){
         printf("you choose division\n");
        printf("%d", c/b);
    }
    return 0;
}