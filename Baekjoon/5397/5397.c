#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;
typedef struct _ListNode {
    element data;
    struct _ListNode *llink;
    struct _ListNode *rlink;
} ListNode;

void init(ListNode *phead)
{
    phead->llink = phead->rlink = phead;
}

ListNode* insert(ListNode *before, element data)
{
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    ListNode *curs;
    new->data = data;
	new->llink = before;
	new->rlink = before->rlink;
	before->rlink->llink = new;
	before->rlink = new;
    curs = new;
    return curs;
}

ListNode* delete(ListNode *removed, ListNode *phead)
{
    ListNode *curs = removed->llink;;
    if (removed == phead) return phead;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
    return curs;
}

void print_node(ListNode *phead)
{
    for (ListNode *p = phead->rlink; p != phead; p = p->rlink) {
        printf("%c", p->data);
    }
    printf("\n");
}

void KeyLoger(ListNode *phead, ListNode *curs, char *ch)
{
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] == '<') {
            if (curs == phead)
            continue;
            curs = curs->llink;
        }
        else if (ch[i] == '>') {
            if (curs->rlink == phead) continue;
            curs = curs->rlink;
        }
        else if (ch[i] == '-') {
            if (curs == phead) continue;
            curs = delete(curs, phead);
        }
        else {
            curs = insert(curs, ch[i]);
        }
    }
    print_node(phead);
}

int main()
{
    ListNode *phead = (ListNode *)malloc(sizeof(ListNode));
    ListNode *curs = NULL;
    init(phead);
    curs = phead;
    int n;
    char ch[1000001];   
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", ch);
        KeyLoger(phead, curs, ch);
        init(phead);
    }
    free(phead);
}