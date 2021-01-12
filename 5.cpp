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

void findNode(int angka){
	Node *curr = head;
	int count = 0;
	
	while(curr){
		curr = curr->next;
		count++;
	}
	curr = head;
	int temp = 0;
	int stop = count - angka;
	while(curr){
		if(temp == stop){
			printf("Node ke %d dari belakang : %s %d\n",angka,curr->name,curr->score);
			break;
		}
		temp++;
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
}

int main(){
	
	pushTail("Valencia",100);
	pushTail("Livia",150);
	pushTail("Clara",1000);
	pushHead("Rio",500);
	pushHead("Mama",30);
	pushHead("Papa",5000);
	printList();
	findNode(6);
	
	return 0;
}
