#include <stdio.h>
#include <stdlib.h>


void todolist(void);
void About(void);
void TEST(void);
void Exit(void);

int main(void){

    int selection = 0;


    while(selection != 4){

        printf("======================\n");
        printf("Terminal to do project\n");
        printf("======================\n");
        printf("\n");
        printf("[1] To-do list\n");
        printf("[2] About\n");
        printf("[3] TEST\n");
        printf("[4] Exit\n");


        if(scanf("%d", &selection) != 1){
            while(getchar() != '\n');
            selection = -1;
            system("clear");
            continue;
    }

        if(selection >= 1 && selection <= 3){
        printf("%d\n", selection);
        system("clear");

        if(selection == 1){
            todolist();
        }
        else if(selection == 2){
            About();
        }
        else if(selection == 3){
            TEST();
        }
    }

    else if(selection == 4){
        Exit();
    }
    else{
        printf("Incorrect\n");
    }
    }
    

    return 0;
}

void todolist(void){
    int selection = 1;
    char reminder[100];
    
    while(selection != 0){
        printf("======================\n");
        printf("      To-do list\n");
        printf("======================\n");
        printf("[0] Back\n");
        if(scanf("%d", &selection) != 1){ // not a number
        while(getchar() != '\n'); // throw away the bad input
        selection = -1; // so it doesn't reuse the old value
        continue; // redraw the menu
        }

        if(selection == 0){
            system("clear");
            return;
        }
        else if(selection == 1){
            printf("Type a reminder (No more then 100 characters):");
            scanf("%s", reminder);
        }
    }

}

void About(void){
    int selection = 0;
    

    printf("======================\n");
    printf("      About\n");
    printf("======================\n");
    printf("[0] Back\n");
    scanf("%d", &selection);

    if(selection == 0){
        system("clear");
        return;
    }
}

void TEST(void){
    int selection = 0;


    printf("======================\n");
    printf("      TEST\n");
    printf("======================\n");
    printf("[0] Back\n");
    scanf("%d", &selection);

    if(selection == 0){
        system("clear");
        return;
    }
}

void Exit(void){
    printf("Exiting To do list...");

    return;
}