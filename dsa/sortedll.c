#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct arr{
    int* arr;
    int len;
}arr;



arr createArr(int* array, int len){
    arr a;
    a.arr = array;
    a.len = len;
    return a;
}

node* createNode(int data){
    node* temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node* addNode(node* old, int data){
    node* new = createNode(data);
    if(old == NULL){
        return new;
    }
    node* temp, *cur = old;
    for(;cur; cur = cur->next){
        if(cur->next == NULL){
            temp = cur;
        }
    }
    if(temp){
        temp->next = new;
        new->next = NULL;
    }
    return old;
}

node* createList(arr a){
    node* l = malloc(sizeof(node)), *temp, *cur;
    cur = l;
    for(int i = 0; i < a.len; i++){
        temp = createNode(a.arr[i]);
        cur->next = temp;
        cur = cur->next;
    }
    temp = l;
    l = l->next;
    free(temp);
    return l;
}

void printList(node * l){
    for(;l != NULL;l = l->next){
        printf("%d\t",l->data);
    }
    printf("\n");
}

int compare(int* a){
    int i;
    if(a[0] <= a[1] && a[0] <= a[2]){
        i = 0;
    }else if(a[1] <= a[0] && a[1] <= a[2]){
        i = 1;
    }else if(a[2] <= a[0] && a[2] <= a[1]){
        i = 2;
    }
    return i;
}

void concatLists(node* a, node* b){
    node* l;
    for(;a;a=a->next){
        if(!a->next){
            l = a;
        }
    }
    l->next = b;
}

node* merge2SortedList(node** a, node** b){
    node* res = NULL;
    while( *a && *b ){
        if((*a)->data < (*b)->data){
            res = addNode(res,(*a)->data);
            *a = (*a)->next;
        }else{
            res = addNode(res,(*b)->data);
            *b = (*b)->next;
        }
    }
    return res;
}

node* merge3SortedLists(node* input[]){
    node *l1 = input[0], *l2 = input[1], *l3 = input[2], *result = NULL;
    int a[3],i; 
    while (l1 != NULL && l2 != NULL && l3 != NULL)
    {
        a[0] = l1->data;
        a[1] = l2->data;
        a[2] = l3->data;
        i = compare(a);
        result = addNode(result, a[i]);
        switch (i)
        {
        case 0:
            l1 = l1->next;
            break;
        case 1:
            l2 = l2->next;
            break;
        case 2:
            l3 = l3->next;
            break;
        default:
            break;
        }
    }
    concatLists(result, merge2SortedList(&l1,&l2));
    concatLists(result, merge2SortedList(&l2,&l3));
    concatLists(result, merge2SortedList(&l3,&l1));
    for(;l1;l1 = l1->next){
        result = addNode(result,l1->data);
    }
    for(;l2;l2 = l2->next){
        result = addNode(result,l2->data);
    }
    for(;l3;l3 = l3->next){
        result = addNode(result,l3->data);
    }
    return result;
}

void main(){
    //Input
    int a[] = {1,2,3,4,5};
    int b[] = {1,3,4,7,8};
    int c[] = {2,6,9};
    arr arr1 = createArr(a,5);
    arr arr2 = createArr(b,5);
    arr arr3 = createArr(c,3);
    node* input[3];
    input[0] = createList(arr1);
    input[1] = createList(arr2);
    input[2] = createList(arr3);
    //Output
    node* result = merge3SortedLists(input);
    printList(result);
}