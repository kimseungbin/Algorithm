#include <stdio.h>

int main()
{
    int cnt = 0, i = 0;
    char ch[1000002] = "0";
    fgets(ch, 1000002, stdin);
    if (ch[0] == 32 || ch[0] == '\n') cnt--;
    for (i = 0; ch[i] != '\n'; i++) {
        if (ch[i] == 32) cnt++;
    }
    if (ch[i-1] == 32) cnt--;
    printf("%d", ++cnt);
    return 0;
}