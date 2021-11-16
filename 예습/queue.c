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
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}


element dequeue(QueueType* q) {
	if (isEmpty(q)) {
		error("큐가 공백상태입니다.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;

	return q->data[q->front];
}

element peek(QueueType* q) {
	if (isEmpty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front) % MAX_QUEUE_SIZE];
}

int main(void) {
	QueueType queue;
	int element;
	initQueue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!isFull(&queue)) {
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queuePrint(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");


	printf("--데이터 삭제 단계--\n");
	while (!isEmpty(&queue)) {
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queuePrint(&queue);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}

