#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101

typedef int elemnet;
typedef struct {
    elemnet imp[MAX_SIZE];
    int front, rear;
}QueueType;

void error(char *e)
{
    fprintf(stderr, "%s", e);
    exit(1);
}

void init(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_full(QueueType *q)
{
    return (q->front == (q->rear + 1) % MAX_SIZE);
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

void push(QueueType *q, elemnet imp)
{
    if(is_full(q)) {
        error("큐 포화에러\n");
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->imp[q->rear] = imp;
}


elemnet pop(QueueType *q)
{
    if (is_empty(q)) {
        error("스택 공백에러\n");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->imp[q->front];
}

elemnet peek_imp(QueueType *q)
{
    if (is_empty(q)) {
        error("스택 공백에러\n");
    }
    return q->imp[(q->front + 1) % MAX_SIZE];
}

int print(int N, int index)
{
    QueueType q;
    init(&q);

    int cnt = 0;
    int pri;
    int flag = 0;
    int LOC = index+1;

    for (int i = 0; i < N; i++) {
        scanf("%d", &pri);
        push(&q, pri);
    }

    if (N == 1) {
        return 1;
    }

    while(1) {
        flag = 0;
        for (int j = (q.front+2) % MAX_SIZE; j != q.rear; (j++) % MAX_SIZE) {
            if (peek_imp(&q) < q.imp[j]) {
                if ((q.front+1) % MAX_SIZE != LOC) {
                    push(&q, pop(&q));
                    flag = 1;
                    break;
                }
                else {
                    push(&q, pop(&q));
                    LOC = q.rear;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            if ((q.front+1) % MAX_SIZE == LOC) {
                pop(&q);
                cnt++;
                return cnt;
            }
            else {
                pop(&q);
                cnt++;
            }
        }
    }
}

int main()
{
    int n, m;
    int testcase_n;
    scanf("%d", &testcase_n);
    
    for (int i = 0; i < testcase_n; i++) {
        scanf("%d %d", &n, &m);
        printf("%d\n", print(n, m));
    }
    return 0;
}