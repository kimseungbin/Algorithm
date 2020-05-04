#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_QUEUE_SIZE 100000

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char *c)
{
    fprintf(stderr, "%s\n", c);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front = q->rear = -1;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return (q->rear == (MAX_QUEUE_SIZE - 1));
}

void push(QueueType *q, element item)
{
    if(is_full(q)) {
        error("큐 포화에러\n");
    }
    q->data[++(q->rear)] = item;
}

int size(QueueType *q)
{
    if(is_empty(q)) {
        return 0;
    }
    return (q->rear - q->front);
}

element pop(QueueType *q)
{
    if(is_empty(q)) {
        return -1;
    }
    return q->data[++(q->front)];
}

element front(QueueType *q)
{
    if(is_empty(q)) {
        return -1;
    }
    return q->data[q->front+1];
}

element back(QueueType *q)
{
    if(is_empty(q)) {
        return -1;
    }
    return q->data[q->rear];
}

int main()
{
    QueueType q;
    init_queue(&q);

    int N, num;
    char com[10];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", com);
        if (strcmp(com, "push") == 0) {
            scanf("%d", &num);
            push(&q, num);
        }
        else if (strcmp(com, "front") == 0) {
            printf("%d\n", front(&q));
        }
        else if (strcmp(com, "back") == 0) {
            printf("%d\n", back(&q));
        }
        else if (strcmp(com, "size") == 0) {
            printf("%d\n", size(&q));
        }
        else if (strcmp(com, "empty") == 0) {
            printf("%d\n", is_empty(&q));
        }
        else if (strcmp(com, "pop") == 0) {
            printf("%d\n", pop(&q));
        }
    }
    return 0;
}