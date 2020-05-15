#include<stdio.h>

int main()
{
    char word[1000001] = "\0";
    int apb[26] = {0};
    int id = 0;
    int max = 0;
    scanf("%s", word);
    for (int i = 0; word[i] != '\0'; i++) {
        id = word[i] >= 'a' ? word[i] - 'a' : word[i] - 'A';
        apb[id]++;
    }
    for (int i = 0; i < 26; i++) {
        if (apb[i] > max) {
            max = apb[i];
            id = i;
        }
        else if (apb[i] != 0 && apb[i] == max) {
            id = -1;
        }
    }
    printf("%c", (id == -1) ? '?' : 'A'+id);
    return 0;
}