#include<stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n%d\n%d\n%d\n", (b%10)*a, ((b%100)/10)*a, (b/100)*a, a*b);
    return 0;
}