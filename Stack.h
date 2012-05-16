#ifndef __H_STACK__
#define __H_STACK__

#define CO_MAX_STACK_ELEM 30

struct stack {
	int top;
	int elem[CO_MAX_STACK_ELEM];
};

void StartStack(stack *q);
void Enqueue(stack *q, int value);
int Dequeue(stack *q);
int CountStack(stack *q);
int StackIsEmpty(stack *q);
void ClearStack(stack *q);
void SwapStack(stack *q);
int FirstStackPos(stack *q);
int LastStackPos(stack *q);

#endif
