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

void findNode(){
	Node *curr = head;
	int count = 0;
	
	while(curr){
		curr = curr->next;
		count++;
	}
	printf("Jumlah node : %d\n",count);
	
	curr = head;
	int temp = 0;
	
	while(curr){
		temp++;
		if(temp == count/2){
			printf("Node ke %d : %s %d\n",temp,curr->name,curr->score);
			break;
		}
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
	findNode();
	
	
	return 0;
}
