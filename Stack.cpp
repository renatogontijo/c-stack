#include "stdafx.h"
#include "Stack.h"

void StackStart(stack *q) {
	q->top = -1;
}

void StackPush(stack *q, int value) {
	if(q->top == (CO_MAX_STACK_ELEM - 1)) 
		perror("Stack is full");
	q->top++;
	q->elem[q->top] = value;
}

int StackPop(stack *q) {
	if(StackIsEmpty(q)) {
		perror("Stack is empty");
		return -1;
	}
	return q->elem[q->top--];
}

int StackCount(stack *q) {
	return (q->top + 1);
}

int StackIsEmpty(stack *q) {
	return (q->top < 0);
}

void StackClear(stack *q) {
	q->top = -1;
}

int StackTop(stack *q) {
	return q->top;
}
