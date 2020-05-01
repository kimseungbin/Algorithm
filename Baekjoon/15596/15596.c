#include <stdio.h>
#include <stdlib.h>

long long sum(int *a, int n)
{
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    return ans;
}

int main()
{
    int n, *p;
    long long res;
    scanf("%d", &n);
    p = (int *)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    printf("%lld", sum(p, n));
    return 0;
}