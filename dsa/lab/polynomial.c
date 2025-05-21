#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int px,py,pz,coef;
    struct node* next;
}node;

node* insert_node(node* root){
    node* new = malloc(sizeof(node));
    printf("Enter the coefficient and power of x,y and z:");
    scanf("%d%d%d%d",&new->coef,&new->px,&new->py,&new->pz);

    new->next = new;
    if(!root){
        return new;
    }
    node* temp = root;
    for(;temp->next != root;temp = temp->next);
    new->next = root;
    temp->next = new;
    return root;
}

void print_poly(node* root){
    node* temp = root;
    do{
        printf("%d*x^%d*y^%d*z^%d",temp->coef,temp->px,temp->py,temp->pz);
        if(temp->next != root) printf(" + ");
        temp = temp->next;
    }while(temp!=root);
    printf("\n");
}

node* create_poly(){
    int n;
    node* root = NULL;
    printf("Enter the no. of elements in the polynomial:");
    scanf("%d",&n);
    for(int i = 0;i < n; i++){
        root = insert_node(root);
    }
    print_poly(root);
    return root;
}

void main(){
    node *root = create_poly();
}