#include <stdio.h>

int main()
{
    int A, X, N;
    scanf("%d %d", &A, &X);
    for (int i = 0; i < A; i++) {
        scanf("%d", &N);
        if (N < X) {
            printf("%d ", N);
        }
    }
    return 0;
}