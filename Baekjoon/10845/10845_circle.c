#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_QUEUE_SIZE 10000

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init(QueueType *q) {
    q->front = q->rear = 0;
}

int is_full(QueueType *q) {
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int size(QueueType *q) {
    return (q->rear - q->front);
}

void push(QueueType *q, element item) {
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element pop(QueueType *q) {
    if(is_empty(q)) {
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element front(QueueType *q) {
    if (is_empty(q)) {
        return -1;
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

element back(QueueType *q) {
    if (is_empty(q)) {
        return -1;
    }
    return q->data[q->rear];
}

int main()
{
    int n, m;
    char c[10];
    QueueType q;
    init(&q);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", c);
        if (strcmp(c, "push") == 0) {
            scanf("%d", &m);
            push(&q, m);
        }
        else if (strcmp(c, "front") == 0) {
            printf("%d\n", front(&q));
        }
        else if (strcmp(c, "back") == 0) {
            printf("%d\n", back(&q));
        }
        else if (strcmp(c, "size") == 0) {
            printf("%d\n", size(&q));
        }
        else if (strcmp(c, "empty") == 0) {
            printf("%d\n", is_empty(&q));
        }
        else if (strcmp(c, "pop") == 0) {
            printf("%d\n", pop(&q));
        }
    }
    return 0;
}