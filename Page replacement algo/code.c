//Page replacement algo
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define BUFFER 3

typedef struct node{
	int data;
	struct node *next;
}node;

int n;
node *head = NULL;
node *tail = NULL;

int *getArray(int *arr){

	printf("No. of elements: ");
	scanf("%d", &n);
	printf("Elements: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	return arr;
}

bool notfound(int ele){
	node *ptr = head;
	while(ptr != NULL && ptr->next != head){
		if(ptr->data == ele){
			return false;
		}
		ptr = ptr->next;
	}
	if(ptr != NULL && ptr->data == ele){
		return false;
	}
	return true;
}

int process(int *arr){
	int p = 0, pf = 0, ele, flag;
	node *ptr;
	for(int i = 0; i < n; i++){
		ele = arr[i];
		if(notfound(ele) == true){
			flag = 1;
			while(p != 3){
				node *newNode = (node *)malloc(sizeof(node));
				newNode->data = arr[i];
				p++;
				if(head == NULL){
					newNode->next = newNode;
					ptr = newNode;
					head = newNode;
					tail = newNode;
					pf++;
					flag = 0;
					break;
				}
				tail->next = newNode;
				newNode->next = head;
				tail = newNode;
				pf++;
				flag = 0;
				break;
			}
			if(flag == 1){
				ptr->data = ele;
				ptr = ptr->next;
				pf++;
			}
			
		}
	}
	return pf;
}

int main(){
	int arr[50], pgFrame;
	int *input;
	input = getArray(arr);
	pgFrame = process(input);
	printf("PageFrame for the input string: %d\n", pgFrame);
	return 0;
}
