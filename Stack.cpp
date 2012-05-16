#include "stdafx.h"
#include "Stack.h"

void StartStack(stack *q) {
	q->top = -1;
}

void Enqueue(stack *q, int value) {
	if(q->top == (CO_MAX_STACK_ELEM - 1)) 
		perror("Stack is full");
	q->top++;
	q->elem[q->top] = value;
}

int Dequeue(stack *q) {
	if(StackIsEmpty(q)) {
		perror("Stack is empty");
		return -1;
	}
	return q->elem[q->top--];
}

int CountStack(stack *q) {
	return (q->top + 1);
}

int StackIsEmpty(stack *q) {
	return (q->top < 0);
}

void ClearStack(stack *q) {
	q->top = -1;
}

int FirstStackPos(stack *q) {
	return q->top;
}

int LastStackPos(stack *q) {
	return 0;
}
