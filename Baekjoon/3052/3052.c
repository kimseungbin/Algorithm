#include<stdio.h>
#define N 42

void _remainder(int arr[])
{
    int n = 0;

    for (int i = 0; i < 10; i++) { // ������ ���ؼ� ����
        arr[i] = arr[i] % N;
    }

    for (int i = 0; i < 10; i++) { // �ϳ��� ��� ��
        if (arr[i] != N) {
        n++;
        }
        else {
            continue;
        }
        for (int j = i+1; j < 10; j++) { // �ڽŰ� �� �� �ʿ���� / ���� �̹� ����
            if ( arr[i] == arr[j] ) { // �ߺ��Ǹ� �ߺ��Ǵ� �ڸ��� N�ֱ�
                arr[j] = N;
            }
        }
    }
    printf("%d\n", n);
}

int main()
{
    int arr[10] = {0,};
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    _remainder(arr);
    return 0;
}