/*Write your own version of strlen function from <string.h>*/

#include <stdio.h>

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
    count = i - 1; 

    return count;
}

int main()
{

    char str1[] = "FOOTBALL";
    char str2[] = "555";
    char str3[] = "CRICKET GAME";
    printf("%d\n", strlen(str1));
    printf("%d\n", strlen(str2));
    printf("%d\n", strlen(str3));

    return 0;
}