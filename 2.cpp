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

void findMaxMin(){
	Node *curr = head;
	Node *max = curr;
	Node *min = curr;
	while(curr){
		if(curr->score <= min->score){
			min = curr;
		}
		if(curr->score >= max->score){
			max = curr;
		}
		curr = curr->next;
	}
	printf("Min : %d\n",min->score);
	printf("Max : %d\n",max->score);
	printf("Selisih : %d\n",max->score - min->score);
	
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
	findMaxMin();
	
	
	return 0;
}
