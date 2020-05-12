#include<stdio.h>

int main()
{
    int N, sum = 0;
    char num;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        num = getchar();
        sum = sum + num - '0';
    }
    printf("%d", sum);
    return 0;
}