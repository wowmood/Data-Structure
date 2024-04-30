#include <stdio.h>
#include <stdlib.h>
#include "StackS.h"

int main(void) {
	element item;
	printf("\n** 순차 스택 연산 **\n");
	printStack();
	push(1);	printStack(); // 1 삽입
	push(2); printStack();	// 2 삽입
	push(3); printStack(); // 3삽입

	item = peek(); printStack();	// 현재 top의 원소 출력
	printf("peek => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack;
	printf("\t pop => %d\n", item);

	getchar(); return 0;
}