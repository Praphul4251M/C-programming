// Write a program to encrypt a string by adding 1 to the ASCII value of its characters


#include<stdio.h>
#include<string.h>


int main(){

    char str[] = "FOOTBALL";

    for(int i = 0;i<strlen(str);i++){

        str[i] = str[i] + 1;


    }
    
    printf("%s", str);






    return 0;
}