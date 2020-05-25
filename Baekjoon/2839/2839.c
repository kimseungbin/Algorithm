#include <stdio.h>

int main()
{
    int N, res = 0;
    scanf("%d", &N);
    if (N % 5 == 0) res = N/5;
    else if (N == 4 || N == 7) res = -1;
    else if (N % 5 == 1 || N % 5 == 3) res = N/5 + 1;
    else if (N % 5 == 2 || N % 5 == 4) res = N/5 + 2;
    printf("%d", res);
    return 0;
}