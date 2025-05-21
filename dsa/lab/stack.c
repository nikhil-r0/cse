#include <stdio.h>
#include <stdlib.h>
#define MAX 7
int stack[MAX],item;
int ch,top = -1,status = 0,i;

void push(int stack[],int item){
	if(top == (MAX-1)){
		printf("Stack Overflow");
	}else{
		stack[++top] = item;
		status ++;
	}
}

int pop(int stack[]){
	int delItem = 0;
	if(top == -1){
		printf("Stack is empty.\n");
	}else{
		delItem = stack[top--];
		status --;
		printf("\nPopped item is %d\n",delItem); 
	}
	return delItem;
}

void display(int stack[]){
	int i;
	if(top == -1){
		printf("Stack is empty.\n");
	}
	else{
		printf("Stack Contains\n");
		for(i = top; i >= 0; i--)
			printf("\n----\n|%d|",stack[i]);
		printf("\n"); 
	}
}

void palindrome(int stack[]){
	int flag = 1;
	display(stack);
	for(i = 0; i <= top/2; i++){
		if(stack[i] != stack[top-i]){
			flag = 0;
			break;
		}
	}
	if(flag == 1)
		printf("Palindrome");
	else
		printf("Not a palindrome");
}

void main(){
	do{
		printf("\n\n-----Main Menu-----\n");
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Palindrome");
		printf("\n4.Display");
		printf("\n5.Exit");
		printf("\nChoice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:printf("Enter element to push:");
			scanf("%d",&item);
			push(stack,item);
			display(stack);
			break;
			case 2:item = pop(stack);
			break;
			case 3:palindrome(stack);
			break;
			case 4: display(stack);
			break;
			case 5: exit(0);
			break;
			default: printf("Invalid choice.\n");
			break;
		}
	}while(1);
}
