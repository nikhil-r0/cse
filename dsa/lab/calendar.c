/*
1. Develop a program in C for the following
    a. Declare a Calendar as an array of 7 elements (A dynamically Created array) to
    represent 7 days of a week. Each Element of the array is a structure having
    three fields. The first field is the name of the Day (A dynamically allocated
    string), The second field is the date of the Day (A integer), the third field is
    the description of the activity for a particular day (A dynamically allocated
    String).
    b. Write functions create(), read(), and display(); to create the calendar, to read
    the data from the keyboard and to print weeks activity details report on
    screen.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct day{
    char *event, *name;
    int date;
}day;

char* copyString(char* src){
    char* new = malloc(strlen(src)+1);
    return strcpy(new,src);
}

void create(day cal[]){
    char temp[50];
    for(int i = 0; i < 7; i++){
        printf("Day %d:\n",i+1);
        printf("Enter Event Details:");
        scanf("%s",temp);
        cal[i].event = copyString(temp);
        printf("Enter Date:");
        scanf("%d",&cal[i].date);
        printf("Enter Day name:");
        scanf("%s",temp);
        cal[i].name = copyString(temp);
        printf("\n");
    }
}

void display(day cal[]){
    for(int i = 0; i < 7; i++){
        printf("Day %d:\n",i+1);
        printf("| Date: %d\tDay: %s\tEvent: %s |\n",cal[i].date,cal[i].name,cal[i].event);
    }
}

void freememory(day cal[]){
    for(int i = 0; i < 7; i++){
        free(cal[i].event);
        free(cal[i].name);
    }
    free(cal);
}

void main(){
    day * cal = malloc(7*sizeof(day));
    create(cal);
    display(cal);
    freememory(cal);
}