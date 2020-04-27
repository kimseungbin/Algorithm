#include<stdio.h>

void cook(int (*ary)[5])
{
    int score = 0;
    int flag = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            ary[i][4] += ary[i][j];
        }
        if (ary[i][4] > score) {
            score = ary[i][4];
            flag = i;
        }
    }
    printf("%d %d\n", flag+1, score);
}

int main()
{
    int arr[5][5] = {0,};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    cook(arr);
    return 0;
}