#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// 공백 연결 큐를 생성하는 연산
LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;	
}

// 연결 큐가 공백 상태인지 검사하는 연산
int isLQEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1; // True
	}
	else return 0; // False
}

// 연결 큐의 rear에 원소를 삽입하는 연산
void enLQueue(LQueueType* LQ, element item) {
	QNode* newNode = (QNode*) malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {		// 현재 연결 큐가 공백 상태인 경우
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {							// 현재 연결 큐가 공백 상태가 아닌 경우
		LQ->rear->link = newNode;	// 현재 큐의 마지막 노드가 새 노드를 가리키도록
		LQ->rear = newNode;		// rear가 새 노드 가리키도록
	}
}

// 연결 큐에서 원소를 삭제하고 반환하는 연산
element deLQueue(LQueueType* LQ) {
	QNode* old = LQ->front;
	element item;
	if(isLQEmpty(LQ)) return ;
	else {
		item = old->data;
		LQ->front = LQ->front->link;	// 첫번째 노드가 가리키던 노드를 첫노드로
		if (LQ->front == NULL)		// 원소 삭제하고 남은 노드가 없는 경우
			LQ->rear = NULL;
		free(old);
		return item;
	}	
}

// 연결 큐에서 원소를 검색하는 연산
element peekLQ(LQueueType* LQ) {
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = LQ->front->data;		// 첫 노드의 원소 반환
		return item;
	}
}

// 연결 큐의 원소를 출력하는 연산
void printLQ(LQueueType* LQ) {
	QNode* temp = LQ->front;
	printf(" Linked Queue  : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}