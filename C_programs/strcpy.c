/* Write your own version of strcpy function from <string.h>
 */

#include<stdio.h>


int strlen(char str[]);
int strlen(char str[])
{

    int i = 0, count;
    char c = str[i];

    while (c != '\0')
    {

        c = str[i];
        i++;
    }
    count = i - 1; // while loop will not stop until requirement meet ,so here have to exclude requirement also

    return count;
}


void mystrcpy(char target[], char source[]);
void mystrcpy(char target[], char source[]){
    

    for(int i = 0;i<strlen(source);i++){

        target[i] = source[i];

    }

    target[strlen(source)] = '\0';

}

 int main(){

    char a[] = "FOOTBALL";
    char b[10];
    mystrcpy(b, a);

    printf("%s", b);

   
    
    return 0;
 }