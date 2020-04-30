#include <stdio.h>

int main()
{
    int arr[9], max = 0, id = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 9; i++) {
        if (arr[i] > max) {
            max = arr[i];
            id = i+1;
        }
    }
    printf("%d\n%d", max, id);
    return 0;
}