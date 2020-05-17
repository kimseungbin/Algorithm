#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char A[4], B[4], tmp;
    int tA, tB;
    scanf("%s %s", A, B);
    for (int i = 0, j = 2; i < j; i++, j--) {
        tmp = A[i]; A[i] = A[j]; A[j] = tmp;
        tmp = B[i]; B[i] = B[j]; B[j] = tmp;
    }
    tA = atoi(A); tB = atoi(B);
    printf("%d", tA > tB ? tA : tB);
    return 0;
}