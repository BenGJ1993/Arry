#include <stdio.h>

int main()
{
   int M, N;
   int i,j;
   int a[1000000]={0};
   int count;

   scanf("%d %d", &M, &N);
   for (i = M; i <= N; i++)
		for (j = 2; j<=N; j++)
			if (i*j <= N) a[i*j] = 1;
   for (i = M; i <= N; i++)
	   if (a[i] == 0) ++count;
   printf("%d", count);
   return 0;
}
