#include<stdio.h>

int main()
{
    int C, N, cnt = 0, grade[1000];
    float avr = 0;
    scanf("%d", &C);
    for (int i = 0; i < C; i++) {
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &grade[j]);
            avr += grade[j];
        }
        avr /= N;
        for (int j = 0; j < N; j++) {
            if (grade[j] > avr) cnt++;
        }
        printf("%.3f%%\n", (float)cnt/N*100);
        avr = 0; cnt = 0;
    }
    return 0;
}