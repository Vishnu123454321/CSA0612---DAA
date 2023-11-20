#include <stdio.h>
#include <stdlib.h>
int main()
{
     int m, n, i, j;
     printf("Enter maximum weight of knapsack    ");
     scanf("%d", &m);
     printf("\nEnter number of objects    ");
     scanf("%d", &n);
     int wt = 0, k = 0;
     float cal[n], p[n], w[n], x[n], prof = 0;
     for (i = 0; i < n; i++)
          x[i] = 0;
     printf("\nEnter weights\n");
     for (i = 0; i < n; i++)
     {
          printf("w[%d] = ", i);
          scanf("%f", &w[i]);
     }
     printf("\nEnter profits\n");
     for (i = 0; i < n; i++)
     {
          printf("p[%d] = ", i);
          scanf("%f", &p[i]);
     }
     for (i = 0; i < n; i++)
          cal[i] = p[i] / w[i];
     for (i = 0; i < n; i++)
     {
          for (j = i + 1; j < n; j++)
          {
               if (cal[i] < cal[j])
               {
                    int t1, t2, t3;
                    t1 = cal[i];
                    cal[i] = cal[j];
                    cal[j] = t1;
                    t2 = w[i];
                    w[i] = w[j];
                    w[j] = t2;
                    t3 = p[i];
                    p[i] = p[j];
                    p[j] = t3;
               }
          }
     }
     printf("\n\n  p[i]\t\t  w[i]\t\t  cal[i]\n");
     for (i = 0; i < n; i++)
          printf("%f\t %f\t %f\t\n", p[i], w[i], cal[i]);
     for (i = 0; i < n; i++)
     {
          if ((wt + w[i]) <= m)
          {
               k++;
               x[i] = 1;
               wt += w[i];
               prof += p[i];
          }
          else
          {
               k++;
               x[i] = (m - wt) / w[i];
               w[i] = m - wt;
               wt = m;
               prof += (x[i] * p[i]);
               p[i] = (x[i] * p[i]);
               break;
          }
     }
     printf("\nThe selected weights are \n\ni\t  w[i]\t\t  p[i]\n");
     for (i = 0; i < k; i++)
          printf("%d\t%f\t%f\n", i + 1, w[i], p[i]);
     printf("\n\nThe total profit is  %f\n\n", prof);
     return 0;
}

