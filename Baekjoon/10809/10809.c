#include<stdio.h>
#include<string.h>

int main()
{
    char s[101];
    int a[26], id;
    memset(a, -1, sizeof(a));
    scanf("%s", s);
    for (int i = 0; s[i] !='\0'; i++) {
        id = s[i] - 'a';
        if (a[id] == -1) a[id] = i;
    }
    for (int i = 0; i < 26; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}