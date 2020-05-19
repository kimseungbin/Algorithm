#include <stdio.h>
int main()
{
    int time = 0;
    char ch[16] = "\0";
    scanf("%s", ch);
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] == 'A' || ch[i] == 'B' || ch[i] == 'C') time += 3;
        else if (ch[i] == 'D' || ch[i] == 'E' || ch[i] == 'F') time += 4;
        else if (ch[i] == 'G' || ch[i] == 'H' || ch[i] == 'I') time += 5;
        else if (ch[i] == 'J' || ch[i] == 'K' || ch[i] == 'L') time += 6;
        else if (ch[i] == 'M' || ch[i] == 'N' || ch[i] == 'O') time += 7;
        else if (ch[i] == 'P' || ch[i] == 'Q' || ch[i] == 'R' || ch[i] == 'S') time += 8;
        else if (ch[i] == 'T' || ch[i] == 'U' || ch[i] == 'V') time += 9;
        else time += 10;
    }
    printf("%d", time);
    return 0;
}