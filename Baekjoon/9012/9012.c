#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 51

typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s)
{
    s->top = -1;
}

int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

void push(StackType *s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화\n");
        return;
    }
    else {
        s->data[++(s->top)] == item;
    }
}

element pop(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백\n");
        exit(1);
    }
    else {
        return s->data[(s->top)--];
    }
}

void check(char *p)
{
    StackType s;
    init_stack(&s);

    char tmp, temp;

    for (int i = 0; i < strlen(p); i++) {
        tmp = p[i];
        switch(tmp) {
            case '(' :
                push(&s, tmp);
                break;
            case ')' :
                if(!is_empty(&s)) {
                    temp = pop(&s);
                    if (temp == '(' && tmp != ')') {
                        printf("NO\n");
                        return;
                    }
                    break;
                }
                else {
                    printf("NO\n");
                    return;
                }
        }
    }

    if (is_empty(&s)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

int main()
{
    int n;
    char p[51] = "\0";
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %s", p);
        check(p);
    }

    return 0;
}