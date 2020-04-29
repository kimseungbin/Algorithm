#include <stdio.h>

int main()
{
    int N, temp, i = 0;
    scanf("%d", &N);
    temp = N;
    do {
        temp = (temp%10)*10 + ((temp/10) + (temp%10))%10;
        i++;
    } while (N != temp);
    printf("%d", i);
    return 0;
}