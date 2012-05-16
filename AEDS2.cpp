// AEDS2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

#include "stdafx.h"
#include "Stack.h"

#define CO_NUM_BLOCKS 5

stack blocks[CO_NUM_BLOCKS];

/*
 * Create blocks
 */
void CreateBlocks()
{
	int i;
	for(i = 0; i < CO_NUM_BLOCKS; i++)
	{
		StartStack(&blocks[i]);
		Enqueue(&blocks[i], i);
	}
}

/*
 * Show stack data
 */
void ShowData()
{
	int i, j;
	for(i = 0; i < CO_NUM_BLOCKS; i++)
	{
		printf("\nbloco %i\n", i);

		for(j = FirstStackPos(&blocks[i]); j >= LastStackPos(&blocks[i]); j--)
		{
			printf("%i\n", blocks[i].elem[j]);
		}

		printf("\n\n");
	}
}

/*
 * Copy values of s_from stack to s_to stack without overwrite it.
 */
void MoveToStack(stack *s_from, stack *s_to)
{
	stack s_aux;
	StartStack(&s_aux);

	// Get from stack
	while(!StackIsEmpty(s_from))
	{
		Enqueue(&s_aux, Dequeue(s_from));
	}

	// Get from stack
	while(!StackIsEmpty(&s_aux))
	{
		Enqueue(s_to, Dequeue(&s_aux));
	}
}


void MoveAbove(int pBlockNumberFrom, int pBlockNumberTo) 
{
	int i;
	int value;
	stack *s_from = &blocks[pBlockNumberFrom];
	stack *s_to = &blocks[pBlockNumberTo];
	stack *s_ori;
	stack s_tmp;
	stack s_aux;

	StartStack(&s_aux);

	// Get from stack
	for(i = FirstStackPos(s_to); i >= LastStackPos(s_to); i--)
	{
		if(s_to->elem[i] == pBlockNumberTo) break;
		Enqueue(&s_aux, Dequeue(s_to));
	}

	// Restore blocks
	while(!StackIsEmpty(&s_aux))
	{
		value = Dequeue(&s_aux);
		s_ori = &blocks[value]; // point to block indicated by 'value'

		// ->
		// -> Copy original block to a temporary stack
		// ->
		StartStack(&s_tmp); // Start temporary stack
		MoveToStack(s_ori, &s_tmp); // Move original block to a temporary stack
		Enqueue(s_ori, value); // Restore original 'value' to its respective block
		MoveToStack(&s_tmp, s_ori); // Restore temporary stack to original stack
	}

	// Copy s_from stack to s_to stack
	MoveToStack(s_from, s_to);
}

void MoveToTop(int pBlockNumberFrom, int pBlockNumberTo) 
{
	stack *s_from = &blocks[pBlockNumberFrom];
	stack *s_to = &blocks[pBlockNumberTo];
	MoveToStack(s_from, s_to);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// Create data
	printf("\n== Create ==\n");
	CreateBlocks();
	ShowData();
	
	// Move
	//printf("\n== Move ==\n");
	//MoveToTop(4, 0);
	//MoveToTop(1, 0);
	//ShowData();

	// Move Above
	printf("\n== Move Above ==\n");
	MoveAbove(3, 0);
	ShowData();

	printf("\n== Test ==\n");
	MoveAbove(3, 0);
	MoveToTop(2, 4);
	MoveAbove(4, 0);
	ShowData();

	getchar();
	return 0;
}

