#include <stdio.h>

int main(){

    int selection = 0;

    printf("======================\n");
    printf("Terminal to do project\n");
    printf("======================\n");
    printf("\n");
    printf("[1] To-do list\n");
    printf("[2] About\n");
    printf("[3] TEST\n");
    printf("[4] Exit\n");

    scanf("%d", &selection);

    if(selection >= 1 && selection <= 3){
        printf("%d\n", selection);
    }
    else if(selection == 4){
        printf("Exiting To do list...");
    }
    else{
        printf("Incorrect");
    }

    return 0;
}