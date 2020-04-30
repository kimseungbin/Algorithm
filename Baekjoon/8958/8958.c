#include <stdio.h>

int main()
{
    int T, cnt, grade;
    char ch[81];
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        cnt = 1; grade = 0;
        scanf("%s", ch);
        getchar();
        for (int j = 0; ch[j] != '\0'; j++) {
            if (ch[j] == 'O') {
                grade += cnt++;
            }
            else cnt = 1;
        }
        printf("%d\n", grade);
    }
    return 0;
}