#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue** Queue, int Capacity) {
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));
	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_DestroyQueue(CircularQueue* Queue) {
	free(Queue->Nodes);
	free(Queue);
}

void CQ_EnqueueQueue(CircularQueue* Queue, ElementType Data) {
	int Position = 0;

	if (Queue->Rear == Queue->Capacity) {
		Position = Queue->Rear;
		Queue->Rear = 0;
	}
	else Position = Queue->Rear++;

	Queue->Nodes[Position].Data = Data;
}

ElementType CQ_DequeueQueue(CircularQueue* Queue) {
	int Position = 0;

	if (Queue->Front == Queue->Capacity) {
		Position = Queue->Front;
		Queue->Front = 0;
	}
	else Position = Queue->Front++;

	return Queue->Nodes[Position].Data;
}

int CQ_IsEmpty(CircularQueue* Queue) {
	return(Queue->Front == Queue->Rear);
}

int CQ_isFull(CircularQueue* Queue) {
	if (Queue->Rear < Queue->Front) {
		return (Queue->Rear + 1 == Queue->Front);
	}
	else return (Queue->Rear - Queue->Front == Queue->Capacity);
}

int CQ_GetSize(CircularQueue* Queue) {
	if (Queue->Rear > Queue->Front) {
		return (Queue->Rear - Queue->Front);
	}
	else {
		return (Queue->Capacity - Queue->Front) + 1 + (Queue->Rear);
	}

}