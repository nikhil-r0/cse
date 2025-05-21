#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *rlink,*llink;
}node;

node* insert_node(int data, node* root){
    node* new = malloc(sizeof(node)), *temp = root, *root1 = root;
    new->data = data;
    new->llink = new->rlink = NULL;

    if(!root){
        return new;
    }
    
    while(root){
        temp = root;
        if(root->data < data){
            root = root->rlink;
        }else{
            root = root->llink;
        }
    }
    if(temp){
        if(temp->data < data){
            new->rlink = temp->rlink;
            temp->rlink = new;
        }else{
            new->llink = temp->llink;
            temp->llink= new;
        }
    }
    return root1;
}

void preorder(node* root){
    if(!root)
        return;
    printf("%d\t",root->data);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(node* root){
    if(!root)
        return;
    preorder(root->llink);
    preorder(root->rlink);
    printf("%d\t",root->data);
}

void inorder(node* root){
    if(!root)
        return;
    preorder(root->llink);
    printf("%d\t",root->data);
    preorder(root->rlink);
}

node* create_bst(){
    int n,data;
    node* root = NULL;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        printf("Enter node%d:",i+1);
        scanf("%d",&data);
        root = insert_node(data,root);
    }
    printf("Preorder:\n");
    preorder(root);
    printf("\n");
    printf("Inorder:\n");
    inorder(root);
    printf("\n");
    printf("Postorder:\n");
    postorder(root);
    printf("\n");
    return root;
}

void search(node* root){
    int data, steps = 0;
    printf("Enter the data to search:");
    scanf("%d",&data);
    while(root){
        steps++;
        printf("%d->",root->data);
        if(root->data==data){
            printf("\nFound %d in %d steps.\n",data,steps);
            return;
        }else if(root->data < data){
            root = root->rlink;
        }else{
            root = root->llink;
        }
    }
    printf("Not found!\n");
}

void main(){
    node* root = create_bst();
    search(root);
}