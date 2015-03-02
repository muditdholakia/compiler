#include<stdio.h>
void main()
{
      int union1(int,int);
      int intersection(int,int);
      int gen[8][8],pre[8][8],rin[8][8],rout[8][8];
      int graph[8][8];
	int i,j,k;
      printf("Enter 8x8 Graph Metrices:\n");
      for(i=0;i<8;i++)
      {
              for(j=0;j<8;j++)
              {
                 scanf("%d",&graph[i][j]);
              }
      }
      printf("Enter 8x8 GEN Metrices:\n");
      for(i=0;i<8;i++)
      {
              for(j=0;j<8;j++)
              {
                 scanf("%d",&gen[i][j]);
              }
      }
      printf("Enter 8x8 PRE Metrices:\n");
      for(i=0;i<8;i++)
      {
              for(j=0;j<8;j++)
              {
                 scanf("%d",&pre[i][j]);
              }
      }
     int flag=1;
     
     for(i=0;i<8;i++)
     {
        for(j=0;j<8;j++)
        {
            rout[i][j]=gen[i][j];
        }
     }
    
     int p=1;
     while(p<=2)
     {
        flag=0;
        for(i=0;i<8;i++)
        {
           int t1[8],t2[8][8],t3[8];
           for(j=0;j<8;j++)
           {
                   t1[j]=0;
                   t3[j]=0;
                   for(k=0;k<8;k++)
                   {
                     t2[j][k]=0;
                   }
           }
           for(j=0;j<8;j++)
           {
              if(graph[j][i]==1)
              {
                  for(k=0;k<8;k++)
                  {
                     t1[k]=union1(t1[k],rout[j][k]);
                  }
              }
           }  
           for(j=0;j<8;j++)
           {
              rin[i][j]=t1[j];
           }
           
           for(j=0;j<8;j++)
           {
                t3[j]=intersection(rin[i][j],pre[i][j]);
           }
           for(j=0;j<8;j++)
           {
               rout[i][j]=union1(t3[j],gen[i][j]);
           }
        }
        
        p++;
     }
     
    printf("\nrin\n");
        for(i=0;i<8;i++)
        {
        for(j=0;j<8;j++)
        {
            printf("%d ",rin[i][j]);
        }
        printf("\n");
        }
        printf("\nrout\n");
        for(i=0;i<8;i++)
        {
        for(j=0;j<8;j++)
        {
            printf("%d ",rout[i][j]);
        }
        printf("\n");
        }
     printf("done\n");
 
}

int union1(int i,int j)
{
    if (i==1)
       return 1;
    else if(j==1)
       return 1;
    else
       return 0;
}

int intersection(int i,int j)
{
    return (i*j);
}
