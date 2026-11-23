#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/select.h>

void todolist(void);
void About(void);
void TimeAndDate(void);
void Exit(void);

static int input_ready(void) {
    struct timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}


int main(void){

    int selection = 0; // A veriable 


    while(selection != 4){ //while slelection is not equal to 4, the program will continue to run

        printf("======================\n");
        printf("Terminal to do project\n");
        printf("======================\n");
        printf("\n");
        printf("[1] To-do list\n");
        printf("[2] About\n");
        printf("[3] Time & date\n");
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

        switch(selection){
            case 1:
                todolist();
                break;
            case 2:
                About();
                break;
            case 3:
                TimeAndDate();
                break;
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
    static char reminders[10][101] = {0};
    int rows = sizeof(reminders) / sizeof(reminders[0]);
    static int reminderCount = 0;
    int number = 1;
    int deleteSelection;
    
    while(selection != 0){

        printf("======================\n");
        printf("      To-do list\n");
        printf("======================\n");
        printf("[0] Back\n");
        printf("[1] Add a reminder\n");
        printf("[2] Delete a reminder\n");
        printf("\n");
        printf("Reminders: \n");

            number = 1;
        
            for (int i = 0; i < rows; i++){

                if (reminders[i][0] != '\0'){
                    printf("%d. %s\n", number, reminders[i]);
                    number++;
                }
            }

        if(scanf("%d", &selection) != 1){ // not a number
            while(getchar() != '\n'); // throw away the bad input
            selection = -1; // so it doesn't reuse the old value
            continue; // redraw the menu
        }

        while(getchar() != '\n' && !feof(stdin));

        switch(selection) {
            case 0:
                system("clear");
                return;
                break;
            case 1:
                if(reminderCount<rows) {
                printf("Type a reminder (No more then 100 characters): ");


                if (fgets(reminders[reminderCount], 101, stdin) != NULL) {
                    reminders[reminderCount][strcspn(reminders[reminderCount], "\n")] = '\0';
                    reminderCount++;

                }
            }
            else{
                    printf("Reminder list is full!\n");
                }

 
                break;
            case 2:
                // TODO: Implement reminder deletion 
                if(reminderCount > 0) {
                    printf("What reminder do you want to delete?\n");
                    printf("Number: ");

                    if(scanf("%d", &deleteSelection) != 1){ 
                        while(getchar() != '\n'); // throw away the bad input
                        continue; // redraw the menu
                    }
                    // Clear input buffer
                    if (deleteSelection >= 1 && deleteSelection <= reminderCount){

                        for (int i = deleteSelection - 1; i < reminderCount - 1; i++){
                            strcpy(reminders[i], reminders[i + 1]);
                        }
                    reminderCount--;
                    reminders[reminderCount][0] = '\0';

                    }
                    else {
                        printf("Invalid reminder number\n");
                    }
                
            }
            else {
                printf("There are no reminders to delete!\n");
            }
            break;

        }
    }

}
void About(void){
    int selection = 0;
    

    printf("======================\n");
    printf("      About\n");
    printf("======================\n");
    printf("[0] Back\n");
    printf("\n");
    printf("Welcome to the Terminal to-do project!\n");
    printf("\n");
    printf("This is my firt project that im doing that\n");
    printf("involved minimal help from outside sources,\n");
    printf("and is my first github project!\n");
    printf("I plan to make MANY more projects that are more\n");
    printf("thought out than this, but this a good way to start :3\n");
    printf("\n");
    printf("Hope you like it! :3\n");
    scanf("%d", &selection);

    if(selection == 0){
        system("clear");
        return;
    }
}


void TimeAndDate(void) {
   int selection = -1;

    printf("======================\n");
    printf("    Time and date\n");
    printf("======================\n");
    printf("[0] Back\n");
    printf("\n   DATE       TIME\n");

    time_t rawtime = 0;
    struct tm *pTime = NULL;

    while (true) {
        time(&rawtime);
        pTime = localtime(&rawtime);

        printf("\r%02d/%02d/%02d   %02d:%02d:%02d",
               pTime->tm_mon + 1,
               pTime->tm_mday,
               pTime->tm_year % 100,
               pTime->tm_hour,
               pTime->tm_min,
               pTime->tm_sec);
        fflush(stdout);

        /* Only call scanf once the user has typed something and hit Enter */
        if (input_ready()) {
            if (scanf("%d", &selection) == 1 && selection == 0) {
                break;
            }
            /* Clear any invalid text if they didn't type 0 */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }

        usleep(200000);
    }

    system("clear");
}


void Exit(void){
    printf("Exiting To do list...");

    return;
}