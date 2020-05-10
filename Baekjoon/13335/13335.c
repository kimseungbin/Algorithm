#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct _QueueNode {
    element data;
    struct _QueueNode *link;
} QueueNode;

typedef struct {
    int size;
    QueueNode *front, *rear;
} LinkedQueueType;

void init(LinkedQueueType *q)
{
    q->front = q->rear = NULL;
    q->size = 0;
}

int is_empty(LinkedQueueType *q)
{
    return (q->front == NULL);
}

void enqueue(LinkedQueueType *q, element data)
{
    QueueNode *new = (QueueNode *)malloc(sizeof(QueueNode));
    new->data = data;
    new->link = NULL;
    if (is_empty(q)) {
        q->front = new;
        q->rear = new;
    }
    else {
        q->rear->link = new;
        q->rear = new;
    }
    q->size++;
}

element dequeue(LinkedQueueType *q)
{
    QueueNode *removed = q->front;
    element data;
    if (is_empty(q)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        data = removed->data;
        q->front = q->front->link;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(removed);
        q->size--;
        return data;
    }
}

int main()
{
    LinkedQueueType q;
    init(&q);
    int TruckNum;
    int Bridge;
    int BridgeLoad;
    int *TruckWeight = NULL; // TruckWeight[1000] = {0};
    int max = 0;
    int i = 0;
    int cnt = 0;
    int dequeue_cnt = 0;
    scanf("%d %d %d", &TruckNum, &Bridge, &BridgeLoad);
    TruckWeight = (int *)malloc(sizeof(int)*TruckNum);
    memset(TruckWeight, 0, sizeof(int)*TruckNum);
    for (int i = 0; i < TruckNum; i++) {
        scanf("%d", &TruckWeight[i]);
    }
    while (dequeue_cnt != TruckNum) {
        if (max+TruckWeight[i] <= BridgeLoad) {
            if (q.size < Bridge) {
                enqueue(&q, TruckWeight[i]);
                max += TruckWeight[i];
                cnt++;
                i++;
            }
            else if (q.front->data == 0) {
                dequeue(&q);
            }
            else {
                max -= dequeue(&q);
                dequeue_cnt++;
            }
        }
        else if (max+TruckWeight[i] > BridgeLoad) {
            if (q.size < Bridge) {
                enqueue(&q, 0);
                cnt++;
            }
            else if (q.front->data == 0) {
                dequeue(&q);
            }
            else {
                max -= dequeue(&q);
                dequeue_cnt++;
            }
        }
    }
    cnt++;
    printf("%d\n", cnt);
    return 0;
}