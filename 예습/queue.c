#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void initQueue(QueueType* q) {
	q->front = q->rear = 0;
}

int isEmpty(QueueType* q) {
	return (q->front == q->rear);
}

int isFull(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queuePrint(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!isEmpty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}


void enqueue(QueueType* q, element item) {
	if (isFull(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}


element dequeue(QueueType* q) {
	if (isEmpty(q)) {
		error("ť�� ��������Դϴ�.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;

	return q->data[q->front];
}

element peek(QueueType* q) {
	if (isEmpty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->front) % MAX_QUEUE_SIZE];
}

int main(void) {
	QueueType queue;
	int element;
	initQueue(&queue);
	printf("--������ �߰� �ܰ�--\n");
	while (!isFull(&queue)) {
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queuePrint(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");


	printf("--������ ���� �ܰ�--\n");
	while (!isEmpty(&queue)) {
		element = dequeue(&queue);
		printf("������ ����: %d \n", element);
		queuePrint(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");
	return 0;
}

