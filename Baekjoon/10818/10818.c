#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, *p, min, max;
    scanf("%d", &N);
    p = (int *)malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
    }
    min = max = p[0];
    for (int i = 1; i < N; i++) {
        if (p[i] > max) max = p[i];
        else if (p[i] < min) min = p[i];
    }
    printf("%d %d\n", min, max);
    free(p);
    return 0;
}