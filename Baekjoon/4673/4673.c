#include<stdio.h>

void d()
{
    int res[10001] = {0};
    int id;
    for (int i = 1; i <= 10000; i++) {
        if (i < 10) {
            res[i+i] = 1;
        }
        else if (i < 100) {
            id = i + i/10 + i%10;
            res[id] = 1;
        }
        else if (i < 1000) {
            id = i + i/100 + (i%100)/10 + i%10;
            res[id] = 1;
        }
        else if (i < 10000) {
            id = i + i/1000 + (i%1000)/100 + ((i%1000)%100)/10 + i%10;
            if (id <= 10000) res[id] = 1;
        }
        if (res[i] == 0) printf("%d\n", i);
    }
}

int main()
{
    d();
    return 0;
}