#include<stdio.h>
#include<malloc.h>

void blackjack(int n, int m, int *p)
{
    int tmp = 0;
    int max = 0;
    for (int i = 0; i <= n-3; i++) {
        for (int j = i+1; j <= n-2; j++) {
            for (int k = j+1; k <= n-1; k++) {
                tmp = p[i] + p[j] + p[k];
                if((tmp<=m) && (tmp>max)) {
                    max = tmp;
                }
                tmp = 0;
            }
        }
    }
    printf("%d\n", max);
}

int main()
{
    int N, M, *P;
    scanf("%d %d", &N, &M);
    P = (int *)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }
    blackjack(N, M, P);
    free(P);
    return 0;
}