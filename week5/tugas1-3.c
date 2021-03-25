#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8

struct q{
	int index;
	int nilai;
	struct q *next;
};

typedef struct q q_t;
	
q_t *head = NULL, *tail = NULL;	

int total=0, jumlah=0, min=0, max=0;
	
void initiate(){
	for(int i=0; i<MAX; i++){
		q_t *temp = malloc(sizeof(q_t));
		if(head==NULL){
			temp->index = 0;
			temp->nilai = 0;
			head = temp;
			tail = temp;
			temp->next = NULL;
			continue;
		}
    	temp->index = i;
    	temp->nilai = 0;
    	tail->next = temp;
    	tail = temp;
	}
	tail->next = head;
	tail = head;
}

//svbi = search_value_by_index
int svbi(int x){
	q_t *temp = tail;
	for(int i=0; i<MAX; i++){
		if(temp->index == x)
			return temp->nilai;
		temp = temp->next;
	}
}

void show(){
	printf("  ---------------  --------------  ---------------  ---------------\n");
	printf("  | 0 | %d\t|->| 1 | %d\t|->| 2 |%d\t |->| 3 | %d\t  |\n",svbi(0),svbi(1),svbi(2),svbi(3));
	printf("  ---------------  --------------  ---------------  ---------------\n");
	printf("\t ^\t\t\t\t\t\t   |\n");
	printf("\t |\t\t\t\t\t\t   v\n");
	printf("  ---------------  --------------  ---------------  ---------------\n");
	printf("  | 7 | %d\t|<-| 6 | %d\t|<-| 5 |%d\t |<-| 4 | %d\t  |\n",svbi(7),svbi(6),svbi(5),svbi(4));
	printf("  ---------------  --------------  ---------------  ---------------\n\n\n");
}

void enqueue(){
	printf("\nMasukkan angka : ");
	scanf("%d",&head->nilai);
	head = head->next;
}

void dequeue(){
	tail->nilai = 0;
	tail = tail->next;
}

void ingfo(){
	q_t *temp = tail;
	total=0;
	jumlah=0;
	min=0;
	max=0;
	for(int i=0; i<MAX; i++){
		if(temp->nilai != 0){
			total++;
			jumlah += temp->nilai;
			if(min > temp->nilai || min == 0)
				min = temp->nilai;
			if(max < temp->nilai)
				max = temp->nilai;
		}
		temp = temp->next;
	}
	printf("\n\nTotal data sebanyak : %d\n",total);
	printf("Jumlah data : %d\n",jumlah);
	printf("Rata-rata data : %.2f\n",(100.0/100)*jumlah/total);
	printf("Angka terkecil : %d\n",min);
	printf("Angka terbesar : %d\n\n\n",max);
	system("pause");
}

int main(){
	initiate();
	while(1){
		system("cls");
		int menu;
		show();
		printf("1. Enqueue angka\n");	
		printf("2. Dequeue angka\n");	
		printf("3. Info tentang nilai pada Queue\n");
		printf("0. Exit\n\n");
		printf("Pilihan anda : ");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				if(tail==head && head->nilai!=0){
					printf("\n\nQueue Penuh!\n\n");
					system("pause");
					break;
				}
				enqueue();
				break;
			case 2:
				if(tail==head && head->nilai==0){
					printf("\n\nQueue Kosong!\n\n");
					system("pause");
					break;
				}
				dequeue();
				break;
			case 3:
				ingfo();
				break;
			default:
				return 0;
		}
	}
}
