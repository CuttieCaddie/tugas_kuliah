#include <stdio.h>
#include <stdlib.h>

struct node{
	int no;
	struct node *next;
};

typedef struct node node_t;

node_t *head=NULL, *tail=NULL; 

void show(node_t *temp);

void enqueue(){
	node_t *temp = malloc(sizeof(node_t));
	printf("\nMasukkan nomor mobil yang akan dimasukkan : ");
	scanf("%d",&temp->no);
	if(tail == NULL && head == NULL){
		head = temp;
		tail = temp;	
	}
	tail->next = temp;
	tail = temp;
	temp->next = NULL;
}

void tampung(int *nomob, node_t *temp){
	node_t *hapus, *head_temp, *tail_temp;
	head_temp = head;
	tail_temp = head;
	while(tail_temp->next != temp){
		tail_temp = tail_temp->next;
	}
	head = temp;
	tail_temp->next = NULL;
	printf("\nTempat parkir\t\t: ");
	show(head);
	printf("\n\nTempat parkir sementara\t: ");
	show(head_temp);
	system("pause");
	hapus = head;
	head = head->next;
	free(hapus);
	tail_temp->next = head;
	head = head_temp;
}

void dequeue(){
	int nomob;
	node_t *temp = head;
	printf("\nMasukkan nomor mobil yang akan dikeluarkan : ");
	scanf("%d", &nomob);
	while(temp != NULL){
		if(temp->no == nomob && temp != head){
			tampung(&nomob, temp);
			break;
		}
		else if(temp->no == nomob && temp == head){
			head = head->next;
			free(temp);
			break;
		}
		else
			temp = temp->next;
	}
}

void show(node_t *temp){
	while(temp!=NULL){
		printf("(|  %d  |  ",temp->no);
		temp = temp->next;
	}
	printf("\n\n");
}

int main(){
	while(1){
		int menu;
		system("cls");
		if(head != NULL)
			show(head);	
		printf("MENU\n\n");
		printf("1. Mobil masuk\n");
		printf("2. Mobil keluar\n");
		printf("0. Exit program\n\n");
		printf("Pilihan anda : ");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			default:
				return 0;
		}
	}
	
}
