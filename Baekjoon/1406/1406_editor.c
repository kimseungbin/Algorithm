#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct _ListNode {
    element data;
    struct _ListNode *llink, *rlink;
} ListNode;

void init(ListNode *head)
{
    head->llink = head->rlink = head;
}

void insert(ListNode *before, element data)
{
    ListNode *new = (ListNode*)malloc(sizeof(ListNode));
    new->data = data;
    new->llink = before;
    new->rlink = before->rlink;
    before->rlink->llink = new;
    before->rlink = new;
}

void delete(ListNode *before, ListNode *removed)
{
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

ListNode* editor(ListNode *head, ListNode *cur)
{
    char Com1, Com2;
    scanf("%c", &Com1);
    getchar();
    switch (Com1) {
        case 'L':
            if (cur != head->llink) cur = cur->rlink;
            break;
        case 'D':
            if (cur != head) cur = cur->llink;
            break;
        case 'B':
            if (cur != head->llink) delete(cur, cur->rlink);
            break;
        case 'P':
            scanf("%c", &Com2);
            insert(cur, Com2);
            getchar();
            break;
    }
    return cur;
}

int main()
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = NULL;
    char ch[100001] = "\0";
    char c;
    int comN;

    init(head);
    scanf("%s", ch);
    for (int i = 0; ch[i] != '\0'; i++) {
        insert(head, ch[i]);
    }
    scanf("%d", &comN);
    getchar();
    cur = head;
    for (int i = 0; i < comN; i++) {
        cur = editor(head, cur);
    }
    for (ListNode *p = head->llink; p != head; p = p->llink) {
        printf("%c", p->data);
    }
    free(head);
}