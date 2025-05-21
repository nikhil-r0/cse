#include <stdio.h>
#include <string.h>

#define HASH_SIZE 50

typedef struct employee{
    char name[50];
    int id;
}emp;

int H(int key){
    return key % HASH_SIZE;
}

void print_table(emp tb[]){
    for(int i = 0; i < HASH_SIZE; i ++){
        if(tb[i].id != 0){
            printf("| hash_value:%d\tid:%d\tname:%s |",i,tb[i].id,tb[i].name);
        }
    }
    printf("\n");
}

void insert_emp(int id, char* name,emp tb[]){
    int h_value = H(id), i ;
    for(i = 0; i < HASH_SIZE; i ++){
        h_value = H(h_value + i);
        if(tb[h_value].id == 0){
            tb[h_value].id = id;
            strcpy(tb[h_value].name,name);
            break;
        }
    }
    if(i == HASH_SIZE){
        printf("Hash Table is full.\n");
    }
}

void main(){
    emp tb[HASH_SIZE];
    int ch, id;
    char name[50];
    for(int i = 0; i < HASH_SIZE; i ++)
        tb[i].id = 0;
   while(1){
        printf("Enter Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter Name and ID:");
            scanf("%s%d",name,&id);
            insert_emp(id,name,tb);
            break;
            case 2: print_table(tb);
            break;
            case 3 : return;
        }
   }
}