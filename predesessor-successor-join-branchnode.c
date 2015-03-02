#include<stdio.h>
main()
{
	int a[100][100],i,j,k,count,n;
	printf("ENTER TOTAL NUMBER OF BASIC BLOCKS:");
	scanf("%d",&n);
	printf("ENTER THE DEPENDENCY MATRIX FROM INPUT TREE:\n");

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
	for(i=0;i<n;i++)
	{
		count=0;		
		for(j=i;j>=0;j--)
		{
			if(a[i][j]==1)
			{
				printf("Predessor of node %d is:%d\n",i,j);
				count=count+1;
			}
		}
		if(count==0)
		{
			printf("Node %d \thas no predesessor.\n",i);
		}
		if(count>1)
		{
			printf("Node %d \tis JOIN node.\n",i);
		}
	}
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=i;j<n;j++)
		{
			if(a[i][j]==1)
			{
				printf("Successor of node %d is:%d\n",i,j);
				count=count+1;			
			}
		}
		if(count==0)
		{
			printf("Node %d \thas no successor.\n",i);
		}
		if(count>1)
		{
			printf("Node %d \tis BRANCH node.\n",i);
		}
	}
}
