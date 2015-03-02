#include<stdio.h>
int a[100][100],i,j,k,count,n,visited[100],left[100],right[100];
void dfs(int x)
{
	int i1,l;
	l=x;
	printf("%d",l);
	for(i1=0;i1<n;i1++)
	{	
		if(a[l][i1]==1)
		{
			if(visited[i1]!=1)
			{
				visited[i1]=1;
				dfs(i1);
			}
			else if(visited[i1]==1)
			{
				a[l][i1]=0;
				continue;
			}
		}
	}
}
main()
{
	
	printf("ENTER TOTAL NUMBER OF BASIC BLOCKS:");
	scanf("%d",&n);
	printf("ENTER THE FORWARD DEPENDENCY MATRIX FROM INPUT TREE:\n");

	for(i=0;i<n;i++)
	{
		printf("FOR BLOCK NO:%d",i);
		for(j=0;j<n;j++)
		{
			printf("\nCONNECTION WITH BLOCK NO%d:",j);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	printf("YOUR DEPENDENCY MATRIX IS:\n");
	for(i=0;i<n;i++)
	{
		printf("FOR BLOCK NO:%d",i);
		for(j=0;j<n;j++)
		{
			printf("\nCONNECTION WITH BLOCK NO%d:",j);
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	visited[0]=1;	
	dfs(0);
	printf("DFS MATRIX WILL BE AS FOLLOW:-");	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
	
}
