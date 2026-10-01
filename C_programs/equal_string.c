 /*Write a program to take string as an input from the user using confirm that the strings are equal
*/
 
 #include<stdio.h>
 #include<string.h>
 
 int main(){
    char input1[50];
    char input2[50];
    printf("Enter string 1:\n");
    scanf("%s", input1);

    printf("Enter string 2:\n");
    scanf("%s", input2);

    int a = strcmp(input1, input2);  // "" these are for strings comparison whereas variables input1 and input2 that hold what the user typed so it should be typed as it is otherwise compiler will always return a non zero value


    if(a<0 || a>0){
        printf("Both stings are not matching");
        
    }
    
    
    else if(a == 0){
        
        printf("Both stings are equal");
       
    }
    
    return 0;
 }