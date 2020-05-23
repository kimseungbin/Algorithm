#include<stdio.h>
#include<string.h>
int main()
{
    int N, cnt = 0, flag;
    char ch[101] = "\0";
    int alp[26] = {0};
    scanf("%d", &N);
    for (int i  = 0; i < N; i++) {
        flag = 0;
        scanf("%s", ch);
        for (int j = 0; ch[j] != '\0'; j++) {
            alp[ch[j] - 'a']++;
            if (ch[1] == '\0') break;
            else if (ch[j] != ch[j+1]) {
                if (alp[ch[j+1] -'a'] != 0) {
                    flag = 1;
                    break;
                }
            }
        }
        cnt = (flag != 1) ? cnt + 1 : cnt;
        memset(alp, 0, sizeof(alp));
    }
    printf("%d", cnt);
    return 0;
}