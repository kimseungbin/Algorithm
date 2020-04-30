#include<stdio.h>

int main()
{
   int N, max = 0;
   double grade[1000], sum = 0;
   scanf("%d", &N);
   for (int i = 0; i < N; i++) {
       scanf("%lf", &grade[i]);
       if (grade[i] > max) max = grade[i];
   }
   for (int i = 0; i < N; i++) {
       grade[i] = grade[i]/max*100;
       sum += grade[i];
   }
   printf("%f", sum/N);
   return 0;
}