#include <stdio.h>

long long aly[31][31] = { 0 };

long long yac(int w, int h)
{
    if (w == 0) return 1;
    if (aly[w][h] > 0) return aly[w][h];
    if (w > 0) aly[w][h] += yac(w - 1, h + 1);
    if (h > 0) aly[w][h] += yac(w, h - 1);
    return aly[w][h];
}

int main()
{
    int n = 0;
    while(scanf("%d", &n) && n != 0)
    {
        printf("%lld\n",yac(n, 0));
    }
    return 0;
}