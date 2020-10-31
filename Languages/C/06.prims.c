// source - http://www.c4learn.com/c-programs/c-program-to-implement-prims-algorithm.html
#include<stdio.h>
#include<conio.h>

int n, cost[10][10];

void prim() {
   int i, j, startVertex, endVertex;
   int k, nr[10], temp, minimumCost = 0, tree[10][3];

   /* For first smallest edge */
   temp = cost[0][0];
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         if (temp > cost[i][j]) {
            temp = cost[i][j];
            startVertex = i;
            endVertex = j;
         }
      }
   }
   /* Now we have fist smallest edge in graph */
   tree[0][0] = startVertex;
   tree[0][1] = endVertex;
   tree[0][2] = temp;
   minimumCost = temp;

   /* Now we have to find min dis of each vertex from either
    startVertex or endVertex by initialising nr[] array
    */

   for (i = 0; i < n; i++) {
      if (cost[i][startVertex] < cost[i][endVertex])
         nr[i] = startVertex;
      else
         nr[i] = endVertex;
   }

   /* To indicate visited vertex initialise nr[] for them to 100 */
   nr[startVertex] = 100;
   nr[endVertex] = 100;

   /* Now find out remaining n-2 edges */
   temp = 99;
   for (i = 1; i < n - 1; i++) {
      for (j = 0; j < n; j++) {
         if (nr[j] != 100 && cost[j][nr[j]] < temp) {
            temp = cost[j][nr[j]];
            k = j;
         }
      }
      /* Now i have got next vertex */
      tree[i][0] = k;
      tree[i][1] = nr[k];
      tree[i][2] = cost[k][nr[k]];
      minimumCost = minimumCost + cost[k][nr[k]];
      nr[k] = 100;

      /* Now find if k is nearest to any vertex
       than its previous near value */

      for (j = 0; j < n; j++) {
         if (nr[j] != 100 && cost[j][nr[j]] > cost[j][k])
            nr[j] = k;
      }
      temp = 99;
   }
   /* Now i have the answer, just going to print it */
   printf("\nThe min spanning tree is:- ");
   for (i = 0; i < n - 1; i++) {
      for (j = 0; j < 3; j++)
         printf("%d", tree[i][j]);
      printf("\n");
   }

   printf("\nMin cost : %d", minimumCost);
}

void main() {
   int i, j;
   clrscr();

   printf("\nEnter the no. of vertices :");
   scanf("%d", &n);

   printf("\nEnter the costs of edges in matrix form :");
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) {
         scanf("%d", &cost[i][j]);
      }

   printf("\nThe matrix is : ");
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         printf("%d\t", cost[i][j]);
      }
      printf("\n");
   }
   prim();
   getch();
}