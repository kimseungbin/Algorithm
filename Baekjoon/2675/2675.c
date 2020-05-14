#include<stdio.h>

int main()
{
    int T, R;
    char S[21];
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &R);
        scanf("%s", S);
        for (int j = 0; S[j] != '\0'; j++) {
            for (int k = 0; k < R; k++) {
                printf("%c", S[j]);
            }
        }
        printf("\n");
    }
    return 0;
}