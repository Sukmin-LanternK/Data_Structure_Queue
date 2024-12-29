#include "CircularQueue.h"


void CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void CQ_DestroyQueue(CircularQueue* Queue);
void CQ_EnqueueQueue(CircularQueue* Queue, ElementType Data);
ElementType CQ_DequeueQueue(CircularQueue* Queue);
int CQ_IsEmpty(CircularQueue* Queue);
int CQ_isFull(CircularQueue* Queue);
int CQ_GetSize(CircularQueue* Queue);


int main() {

	CircularQueue* Queue; 
	CQ_CreateQueue(&Queue, 10);

	CQ_EnqueueQueue(Queue, 1);
	CQ_EnqueueQueue(Queue, 2);
	CQ_EnqueueQueue(Queue, 3);
	CQ_EnqueueQueue(Queue, 4);

	for (int i = 0;i < 3;i++) {
		printf("Dequeue: %d ",CQ_DequeueQueue(Queue));
		printf("Front: %d ",Queue->Front);
		printf("Rear: %d\n",Queue->Rear);
	}

	int i = 100;
	while (CQ_isFull(Queue) == 0) {
		CQ_EnqueueQueue(Queue, i++);
	}

	while (CQ_IsEmpty(Queue) == 0) {
		printf("Dequeue: %d ", CQ_DequeueQueue(Queue));
		printf("Front: %d ", Queue->Front);
		printf("Rear: %d\n", Queue->Rear);
	}

	CQ_DestroyQueue(Queue);

	return 0;
}