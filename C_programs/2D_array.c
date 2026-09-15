/* Create an array of size 3 × 10 containing multiplication tables of the numbers 2, 7 and 9 respectiviely
 */

// In C, when passing a 2D array to a function, you must specify the size of all dimensions except the first:

#include <stdio.h>

void multiplication_array(int arr[][10], int a, int b);
void multiplication_array(int arr[][10], int a, int b)
{

    int numbers[3] = {2, 7, 9};// the three numbers whose tables we want
    
    for (int j = 0; j < a; j++)
    {
        
        for (int i = 0; i < b; i++)
        {
            arr[j][i] = numbers[j] * (i + 1);
        }
    }
}
int main(){

    int arr[3][10];
    multiplication_array(arr, 3, 10);

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}