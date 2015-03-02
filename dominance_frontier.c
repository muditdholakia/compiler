#include<stdio.h>

int main()
{
  int graph11[15][15];
  int tmpdom[15];
  int universal[15];
  int temp,m;
  int x[15];
  int p,q;
  int i,j,k,z,flag1,f;
  int pred[15][15],succ[15][15];
  int dom[15][15],sdom[15][15];
  int n;int count;
  int node;char ch;
  
  printf("Enter number of nodes in a graph\n");
  scanf("%d",&n);
  printf("Enter Graph\n");
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
     scanf("%d",&graph11[i][j]);
   }
  }
  for(i=0;i<n;i++)
    universal[i]=1;
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    if(graph11[j][i]==1)
     pred[i][j]=1;
    else
     pred[i][j]=0;

   }
  }
   for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    if(graph11[i][j]==1)
     succ[i][j]=1;
    else
     succ[i][j]=0;

   }
  }

  printf("The Graph is:\n");
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
     printf("%d\t",graph11[i][j]);
   }
   printf("\n");
  }
  printf("Predecessors:\n");
   for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
     printf("%d\t",pred[i][j]);
   }
   printf("\n");
  }
  printf("Successors:\n");
   for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
     printf("%d\t",succ[i][j]);
   }
   printf("\n");
  }
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    if(i!=j)
      dom[i][j]=0;
    else
      dom[i][j]=1;
   }
  }
  count=0;
  for(i=1;i<n;i++)
  {
    count=0;
    for(j=0;j<n;j++)
    {
      if(pred[i][j]==1 && count==0)
      {
	m=j;
	for(p=0,q=0;p<n,q<n;p++,q++)
	{
	  dom[i][q]=dom[m][p];
	}
	dom[i][j]=1;
	count++;
	temp=j;
      }
      else
       {
	if(i!=j && pred[i][j]==1)
	 {
	  for(k=0;k<n;k++)
	  {
	    if(dom[temp][k]==1 && dom[i][k]==1)
	    {
	       dom[i][k]=1;
	    }
	    else if(j>i)
	    {
	       if(dom[temp][k]==1 && universal[k]==1)
	       {
		 dom[i][k]=1;
	       }
	    }
	    else
	    {
	       dom[i][k]=0;
	    }} }}
     }
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
     sdom[i][j]=dom[i][j];
    }
  }
 for(i=0;i<n;i++)
   { dom[i][i]=1;
    sdom[i][i]=0;
   }
  printf("Strict Dominance:\n");
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
     printf("%d\t",sdom[i][j]);
   }
  printf("\n");
  }
   printf("Dominance Matrix:\n");
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
     printf("%d\t",dom[i][j]);
   }
  printf("\n");
  }

 printf("Dominance Frontier\n");

 for( ;  ; )
 {
 printf("enter character");
 scanf("%c",&ch);
 if(ch=='c')
  break;
  printf("enter node number");
 scanf("%d",&node);
 for(i=0;i<n;i++)
 {
   tmpdom[i]=dom[node][i];
 }
 flag1=0;
 for(i=0;i<n;i++)
 { if(flag1==1) break;
   if(succ[node][i]==1)
   {
   if(sdom[i][node]==1)
     {  for(k=0;k<n;k++)
	  {
	    if(succ[i][k]==1)
	     {
	      node=k;
	      i=-1;
	      break;
	     }
	  }
     }
     else
     {
     for(m=0;m<n;m++)
	{
	  if(pred[i][m]==1)
	  {
	    if(dom[node][m]==1)
	    {
	     printf("%d\n",i);
	     flag1=1;
	     break;
	    }
	  }
	}
     }
   }
 }
}
 return 0;
}

