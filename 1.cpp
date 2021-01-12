#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char name[255];
	int score;
	Node *next;
}*head, *tail;

struct Node1{
	char name[255];
	int score;
	Node1 *next;
}*head1, *tail1;

struct Node2{
	char name[255];
	int score;
	Node2 *next;
}*head2, *tail2;

Node *createNode(const char *name, int score){
	Node *newNode = (Node*) malloc (sizeof(Node));
	strcpy(newNode->name, name);
	newNode->score = score;
	newNode->next = NULL;
	return newNode;
}

Node1 *createNode1(const char *name, int score){
	Node1 *newNode1 = (Node1*) malloc (sizeof(Node1));
	strcpy(newNode1->name, name);
	newNode1->score = score;
	newNode1->next = NULL;
	return newNode1;
}

Node2 *createNode2(const char *name, int score){
	Node2 *newNode2 = (Node2*) malloc (sizeof(Node2));
	strcpy(newNode2->name, name);
	newNode2->score = score;
	newNode2->next = NULL;
	return newNode2;
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

void pushTail1(const char *name, int score){
	
	Node1 *temp = createNode1(name, score);
	if(!head1){
		head1 = tail1 = temp;
	}
	else{
		tail1->next = temp;
		tail1 = temp;
	}
}

void pushTail2(const char *name, int score){
	
	Node2 *temp = createNode2(name, score);
	if(!head2){
		head2 = tail2 = temp;
	}
	else{
		tail2->next = temp;
		tail2 = temp;
	}
}

void printList(){
	
	Node2 *curr2 = head2;
	while (curr2){
		if(curr2 == head2){
			printf(" (head) ");
		}
		else if(curr2 == tail2){
			printf(" (tail) ");
		}
		printf("%s %d -> ",curr2->name, curr2->score);
		curr2 = curr2->next;
	}
	puts("NULL");
	
}

void mergeLinkedList(){
	Node* curr = head;
	Node1* curr1 = head1;
	
	while(curr && curr1){
		if(curr->score <= curr1->score){
			pushTail2(curr->name, curr->score);
			curr = curr->next;
		}
		else if(curr->score >= curr1->score){
			pushTail2(curr1->name, curr1->score);
			curr1 = curr1->next;
		}
	}
	
	while(curr){
		pushTail2(curr->name, curr->score);
		curr = curr->next;
	}
	
	while(curr1){
		pushTail2(curr1->name, curr1->score);
		curr1 = curr1->next;
	}
	
}

int main(){
	
	pushTail("Valencia",100);
	pushTail("Livia",150);
	pushTail("Clara",300);
	pushTail1("Bryan",90);
	pushTail1("Carrick",100);
	pushTail1("Andi",150);
	mergeLinkedList();
	printList();
	
	return 0;
}
