/*Write a program to take string as an input from the user using confirm that the strings are equal (char by char)
*/


#include<stdio.h>

int main(){
    char str[6];


    for(int i = 0;i<5;i++){

        scanf("%c", &str[i]);
        fflush(stdin);  

    }

    str[5] = '\0';
    printf("%s", str);
    
    return 0;
}