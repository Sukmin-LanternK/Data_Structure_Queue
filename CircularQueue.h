#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
}Node;

typedef struct tagCircularQueue {
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;
}CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void CQ_DestroyQueue(CircularQueue* Queue);
void CQ_EnqueueQueue(CircularQueue* Queue, ElementType Data);
ElementType CQ_DequeueQueue(CircularQueue* Queue);
int CQ_IsEmpty(CircularQueue* Queue);
int CQ_isFull(CircularQueue* Queue);
int CQ_GetSize(CircularQueue* Queue);
