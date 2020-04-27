#include<stdio.h>

void scale(int arr[])
{
    int a = 0;
    int b = 0;
    for (int i = 1; i <= 8; i++)
    {
        if (arr[i-1] == i) {
            a++;
        }
        else if (arr[8-i] == i) {
            b++;
        }
    }
    if (a == 8) printf("ascending");
    else if (b == 8) printf("descending");
    else printf("mixed");
}

int main()
{
    int arr[8] = {0,};
    for (int i = 0; i < 8;i++) {
        scanf("%d", &arr[i]);
    }
    scale(arr);
    return 0;
}