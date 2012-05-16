#ifndef __H_STACK__
#define __H_STACK__

#define CO_MAX_STACK_ELEM 30

struct stack {
	int top;
	int elem[CO_MAX_STACK_ELEM];
};

void StackStart(stack *q);
void StackPush(stack *q, int value);
int StackPop(stack *q);
int StackCount(stack *q);
int StackIsEmpty(stack *q);
void StackClear(stack *q);
int StackTop(stack *q);

#endif
