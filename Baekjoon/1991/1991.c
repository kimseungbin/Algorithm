#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode {
    char data;
    struct _TreeNode *left, *right;
} TreeNode;

TreeNode* new_node(char data)
{
    TreeNode *new = (TreeNode*)malloc(sizeof(TreeNode));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

void preorder(TreeNode *root)
{
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode *root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void postorder(TreeNode *root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

TreeNode* insert(TreeNode *node, char data, int flag)
{   
    if (node == NULL) return new_node(data);
    if (flag == 0) node->left = insert(node->left, data, 0);
    else if (flag == 1) node->right = insert(node->right, data, 1);
    return node;
}

TreeNode* search(TreeNode *node, char data)
{
    TreeNode *tmp;
    if (node == NULL) return NULL;
    if (node->data == data) return node;
    tmp = search(node->left, data);
    if (tmp == NULL) tmp = search(node->right, data);
    return tmp;
}

int main()
{
    int treeN;
    char node[4];
    TreeNode *root = NULL;
    TreeNode *find = NULL;
    scanf("%d", &treeN);
    for (int i = 0; i < treeN; i++) {
        for (int j = 0; j < 3; j++) {
            getchar();
            scanf("%c", &node[j]);
        }
        if (find == NULL) root = find = insert(root, node[0], 0); // 최초로 넣는건 왼쪽, 오른쪽 상관x
        find = search(root, node[0]);
        if (find == NULL) return 0;
        if (node[1] != '.') insert(find, node[1], 0);
        if (node[2] != '.') insert(find, node[2], 1);
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    free(root);
    return 0;
}