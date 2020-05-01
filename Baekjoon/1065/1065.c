#include<stdio.h>

int func(int N)
{
    int cnt = 0, k, m, h;
    for (int i = 1; i <= N; i++) {
        if (i < 100) {
            cnt++;
        }
        else {
            k = i/100; m = (i%100)/10; h = i%10;
            if (k-m == m-h) cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
    return 0;
}