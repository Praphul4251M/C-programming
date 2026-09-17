/*Create an array of size 3 × 10 containing multiplication tables of the numbers for a custom input given by the user
*/

#include <stdio.h>

void multiplication_array(int arr[][10], int a, int b);
void multiplication_array(int arr[][10], int a, int b)
{

    int numbers[3];// the three numbers whose tables we want

      for(int k = 0;k<3;k++){
   printf("Enter any three numbers for which table you want\n");
   scanf("%d", &numbers[k]);// this is the part of initialization so will be done in function part only
  }
    
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