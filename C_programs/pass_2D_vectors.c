// Write a function which returns the sum of two vectors passed to it. The vectors must be two-dimensional


#include<stdio.h>

struct vector{
    int i;
    int j;
  

};  // initialize

struct vector sum_vector(struct vector v1, struct vector v2);
struct vector sum_vector(struct vector v1, struct vector v2){

  struct vector v3;

  v3.i = v1.i + v2.i;
  v3.j = v1.j + v2.j;

   return v3;

}


int main(){

    struct vector v1 = {3, 8};
    struct vector v2 = {6, 10};

    struct vector v3 = sum_vector(v1, v2);
    printf("The sum of the two vectors is %di + %dj", v3.i, v3.j);
 
    return 0;  

}
/*
This keeps vector as a proper 2D-vector type, takes two separate vector values as parameters, and the function actually returns the sum — printing is left to main, which is a cleaner separation of concerns anyway.
*/


