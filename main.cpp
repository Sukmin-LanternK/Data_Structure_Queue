//#include "CircularQueue.h"
#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** Queue);
void LQ_DestroyQueue(LinkedQueue* Queue);
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* LQ_Dequeue(LinkedQueue* Queue);
int LQ_IsEmpty(LinkedQueue* Queue);
Node* LQ_CreateNode(char* Data);
void LQ_DestroyNode(Node* Node);

int main() {

	LinkedQueue* Queue;
	LQ_CreateQueue(&Queue);

	LQ_Enqueue(Queue, LQ_CreateNode("abc"));
	LQ_Enqueue(Queue, LQ_CreateNode("efg"));
	LQ_Enqueue(Queue, LQ_CreateNode("ifg"));
	LQ_Enqueue(Queue, LQ_CreateNode("cfd"));

	printf("Queue Size: %d\n",Queue->Count);

	while (LQ_IsEmpty(Queue)==0) {
		printf("Dequeue: %s\n",LQ_Dequeue(Queue)->Data);
	}


	return 0;
}