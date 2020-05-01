#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef int elemnet;
typedef struct {
    elemnet *data;
    int cap;
    int top;
}StackType;

void init_stack(StackType *s)
{
    s->cap = 1;
    s->top = -1;
    s->data = (elemnet *)malloc(s->cap * sizeof(elemnet));
}

int is_full(StackType *s)
{
    return (s->top == (s->cap - 1));
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

void push(StackType *s, elemnet item)
{
    if(is_full(s)) {
        s->cap *= 2;
        s->data = (elemnet *)realloc(s->data, (s->cap)*sizeof(elemnet));
    }
    s->data[++(s->top)] = item;
}

void pop(StackType *s)
{
    if(is_empty(s)) {
        printf("-1\n");
    }
    else {
        printf("%d\n", s->data[(s->top)--]);
    }
}

void size(StackType *s)
{
    printf("%d\n", s->top + 1);
}


void top(StackType *s)
{
    if (is_empty(s)) {
        printf("-1\n");
    }
    else {
        printf("%d\n", s->data[s->top]);
    }
}

int main()
{
    StackType ss;
    init_stack(&ss);

    int n, nn;
    char *cc;
    char c[12] = "\0";
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]s", c);
        if (!strcmp(c,"top")) {
            top(&ss);
        }
        else if (!strcmp(c,"size")) {
            size(&ss);
        }
        else if (!strcmp(c,"empty")) {
            printf("%d\n", is_empty(&ss));
        }
        else if (!strcmp(c,"pop")) {
            pop(&ss);
        }
        else {
            cc = strtok(c, " ");
            cc = strtok(NULL, " ");
            nn = atoi(cc);
            push(&ss, nn);
        }
    }

    free(ss.data);
    return 0;
}