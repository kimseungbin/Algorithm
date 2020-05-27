#include <stdio.h>

int main()
{
    int N;
    int cnt = 2;
    int tmp1 = 2, tmp2 = 2, c = 0;
    scanf("%d", &N);
    if (N == 1) {
        printf("1");
        return 0;
    }
    while (1) {
        tmp1 += 6*c;
        tmp2 += 6*(c+1);
        if ( (tmp1 <= N) && (N < tmp2) ) break;
        cnt++;
        c++;
    }
    printf("%d", cnt);
    return 0;
}