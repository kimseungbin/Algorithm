#include <stdio.h>

int main()
{
    int A, B, C, D, res[10] = {0};
    scanf("%d %d %d", &A, &B, &C);
    D = A * B * C;
    for (int i = D; i > 0; i /= 10) {
        res[i%10]++;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}