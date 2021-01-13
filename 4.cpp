#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char name[255];
	int score;
	Node *next;
}*head, *tail;

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

void printList(){
	Node *curr = head;
	while(curr){
		printf("%d %s -> ", curr->score, curr->name);
		curr = curr->next;
	}
	printf("NULL\n\n");
}

void removeDuplicate(){
	Node *curr = head;
	Node *temp;
	Node *toBeDeleted;
	Node *last;
	int count = 1;
	while(curr){
		temp = curr->next;
		while(temp){
			if(curr->score == temp->score){
				toBeDeleted = temp;
				curr->next = temp->next;
				toBeDeleted->next = NULL;
				free(toBeDeleted);
			}
			if(curr->score < temp->score) break;
			temp = temp->next;
		}
		curr = curr->next;
	}
}

int main(){
	
	pushTail("Valencia",100);
	pushTail("Livia",150);
	pushTail("Clara",130);
	pushHead("Rio",150);
	pushHead("Mama",100);
	pushHead("Papa",170);

	printList();
	removeDuplicate();
	printList();
	
	
	return 0;
}
