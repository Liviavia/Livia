#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char name[255];
	int score;
	Node *next;
}*head, *tail, *head1, *tail1;

Node *createNode(const char *name, int score){
	Node *newNode = (Node*) malloc (sizeof(Node));
	strcpy(newNode->name, name);
	newNode->score = score;
	newNode->next = NULL;
	return newNode;
}

void pushHead(const char *name, int score){
	
	Node *temp = createNode(name, score);
	if(!head){
		head = tail = temp;
	}
	else{
		temp->next = head;
		head = temp;
	}
}

void pushTail(const char *name, int score){
	
	Node *temp = createNode(name, score);
	if(!head){
		head = tail = temp;
	}
	else{
		tail->next = temp;
		tail = temp;
	}
}

void pushHead1(const char *name, int score){
	
	Node *temp = createNode(name, score);
	if(!head1){
		head1 = tail1 = temp;
	}
	else{
		temp->next = head1;
		head1 = temp;
	}
}

void descendingNode(){
	Node* curr = head;
	
	while(curr){
		pushHead1(curr->name, curr->score);
		curr = curr->next;
	}

}

void printList(){
	Node *curr = head;
	while(curr){
		printf("%d %s -> ", curr->score, curr->name);
		curr = curr->next;
	}
	printf("NULL\n\n");
	
	Node *curr1 = head1;
	while(curr1){
		printf("%d %s -> ", curr1->score, curr1->name);
		curr1 = curr1->next;
	}
	printf("NULL\n\n");
}

int main(){
	
	pushTail("Valencia",100);
	pushTail("Livia",150);
	pushTail("Clara",200);
	pushTail("Rio",250);
	pushTail("Mama",300);
	pushTail("Papa",350);
	descendingNode();
	printList();
	
	return 0;
}
