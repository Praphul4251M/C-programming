#include<stdio.h>

void swap_with_add_sub(int *a, int *b);
void swap_with_add_sub(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
void swap_with_temp(int *a, int *b);
void swap_with_temp(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap_with_mult_div(int *a, int *b);
void swap_with_mult_div(int *a, int *b){
    if(*a != 0 && *b != 0){
        *a = *a * *b;
        *b = *a / *b;
        *a = *a / *b;

    }
}
void swap_with_xor(int *a, int *b);
void swap_with_xor(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void swap_with_pointers(int *a, int *b);
void swap_with_pointers(int *a, int *b){
    int *temp = a;
    a = b;
    b = temp;
}

int main(){
    int x =10, y =15;
    x = x+ y -(x=y);
    // write c code to swap to character data item of char type using first pointer addition and subtraction and second multiplication and division
    // write swappping logic for two variable without actually writng on a memory location of the two variables
    // create a student structure with atleat 15 relevant paramenters with c
    // when we access an internal data item of a structure using a pointer to that structure



    
    return 0;
}