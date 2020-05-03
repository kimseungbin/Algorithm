#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define MAX_STACK_SIZE 100000

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

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
        fprintf(stderr, "스택 포화에러\n");
        return;
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백에러\n");
        exit(1);
        
    }
    return s->data[(s->top)];
}

void func(int *SIZE, char *PP, int *INDEX)
{
    (*SIZE)++;
    PP = (char *)realloc(PP, (*SIZE) * sizeof(char));
    PP[*INDEX] = '-';
    (*INDEX)++;
}

void seq(int N)
{
    StackType s;
    init_stack(&s);
    int *n = (int *)malloc(N * sizeof(int));
    int size = 1;
    int index = 0;
    char *pp = (char *)malloc(size * sizeof(char));
    int max = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    for (int i = 0; i < N; i++) {;
        if (is_empty(&s) && n[i] < max) {
            printf("NO\n");
            free(n);
            exit(0);
        }
        else if (i == 0 || n[i] > max) {
            for (int j = max+1; j <= n[i]; j++) {
                push(&s, j);
                size++;
                pp = (char *)realloc(pp, size * sizeof(char));
                pp[index] = '+';
                index++;
            }
            pop(&s);
            func(&size, pp, &index);
            max = n[i];
        }
        else if (n[i] < max) {
            for (int j = s.top; j != -1; j--) {
                if (is_empty(&s)) {
                    printf("NO\n");
                    free(n);
                    exit(0);
                }
                else if (peek(&s) == n[i]) {
                    pop(&s);
                    func(&size, pp, &index);
                    break;
                }
                else if (peek(&s) < n[i] ){
                    pop(&s);
                    func(&size, pp, &index);
                }
                else {
                    printf("NO\n");
                    free(n);
                    exit(0);
                }
            }
        }
    }

    for (int i = 0; i < index; i++) {
        printf("%c\n", pp[i]);
    }
    free(n);
}

int main()
{
    int n;
    scanf("%d", &n);
    seq(n);
    return 0;
}