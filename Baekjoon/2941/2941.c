#include <stdio.h>

int main()
{
    char ch[101] = "\0";
    int cnt = 0;
    scanf("%s", ch);
    for (int i = 0; ch[i] != '\0'; ) {
        if (ch[i] == 'c' && ch[i+1] == '=') {cnt++; i += 2;}
        else if (ch[i] == 'c' && ch[i+1] == '-') {cnt++; i += 2;}
        else if (ch[i] == 'd' && ch[i+1] == 'z' && ch[i+2] == '=') {cnt++; i += 3;}
        else if (ch[i] == 'd' && ch[i+1] == '-') {cnt++; i += 2;}
        else if (ch[i] == 'l' && ch[i+1] == 'j') {cnt++; i += 2;}
        else if (ch[i] == 'n' && ch[i+1] == 'j') {cnt++; i += 2;}
        else if (ch[i] == 's' && ch[i+1] == '=') {cnt++; i += 2;}
        else if (ch[i] == 'z' && ch[i+1] == '=') {cnt++; i += 2;}
        else {cnt++; i++;}
    }
    printf("%d", cnt);
    return 0;
}