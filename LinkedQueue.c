#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// ���� ���� ť�� �����ϴ� ����
LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;	
}

// ���� ť�� ���� �������� �˻��ϴ� ����
int isLQEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1; // True
	}
	else return 0; // False
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enLQueue(LQueueType* LQ, element item) {
	QNode* newNode = (QNode*) malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {		// ���� ���� ť�� ���� ������ ���
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {							// ���� ���� ť�� ���� ���°� �ƴ� ���
		LQ->rear->link = newNode;	// ���� ť�� ������ ��尡 �� ��带 ����Ű����
		LQ->rear = newNode;		// rear�� �� ��� ����Ű����
	}
}

// ���� ť���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
element deLQueue(LQueueType* LQ) {
	QNode* old = LQ->front;
	element item;
	if(isLQEmpty(LQ)) return ;
	else {
		item = old->data;
		LQ->front = LQ->front->link;	// ù��° ��尡 ����Ű�� ��带 ù����
		if (LQ->front == NULL)		// ���� �����ϰ� ���� ��尡 ���� ���
			LQ->rear = NULL;
		free(old);
		return item;
	}	
}

// ���� ť���� ���Ҹ� �˻��ϴ� ����
element peekLQ(LQueueType* LQ) {
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = LQ->front->data;		// ù ����� ���� ��ȯ
		return item;
	}
}

// ���� ť�� ���Ҹ� ����ϴ� ����
void printLQ(LQueueType* LQ) {
	QNode* temp = LQ->front;
	printf(" Linked Queue  : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}