#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node stack;
void create (stack*);
void display(stack*);
void push (stack*);
void pop(stack*);
int main(){
	int ch;
	stack* head;
	head=(stack*) malloc(sizeof(stack*));
	head->next=NULL;
	do{
		printf("1.Create 2.Display 3.Push 4.Pop 5.Exit");
			scanf("%d",&ch);

		switch(ch){
			case 1:
				create(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				push( head);
				break;
			case 4:
				pop(head);
				break;
			case 5:
				exit(0);
				break;
		}
	}while(ch!=5);
	}
	
void create(stack *p){
	p=p->next;
}
void display(stack *p){
	while(p->next !=NULL){
		printf("%d",p->data);
	}
}
void push(stack *p){
	p=p->next;
	stack *n;
	n=(stack*)malloc(sizeof(stack*));
	printf("enter data for n");
	n->next=NULL;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=n;
}
void pop(stack *p){
	if(p->next== NULL){
		printf("Empty");
	}
	else{
		p=p->next;
		while(p->next!=NULL)
			p=p->next;
		p->next=NULL;
	}
}	
	
	
	
	
	
	
	
	
