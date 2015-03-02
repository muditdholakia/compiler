#include<stdio.h>
int a[100][100],b[100][100],n,i,xx,x2,j,k,dom[100][100],pre[100][100],inloop[100],np,be[100];
void nlp(int x)
{
	int in,el;
	inloop[x]=1;
	for(in=0;in<n;in++)
	{
		if(pre[x][in]==111)
		{
			return;
		}
		else
		{
			el=pre[x][in];
			if(inloop[el]!=1)
			{
				inloop[el]=1;
				nlp(el);
			}
			else
			{
				continue;
			}
		}
	}
}

main()
{
	printf("ENTER TOTAL NUMBER OF BASIC BLOCKS:");
	scanf("%d",&n);
	printf("\nASSUMPTION::-->>BY DEFAULT FIRST AND LAST NODE WILL BE TREATED AS ENTRY AND EXIT NODES.\n");
	printf("ENTER THE DEPENDENCY MATRIX FROM INPUT TREE:\n");
	printf("ENTER THE DEPENDENCY MATRIX FROM INPUT TREE-CONSIDER DIRECTED EDGES ONLY:\n");

	for(i=0;i<n;i++)
	{
		printf("FOR BLOCK NO:%d",i);
		for(j=0;j<n;j++)
		{
			printf("\nCONNECTION WITH BLOCK NO%d:",j);
			scanf("%d",&b[i][j]);
		}
		printf("\n");
	}
	printf("YOUR DIRECTED DEPENDENCY MATRIX IS:\n");
	for(i=0;i<n;i++)
	{
		printf("FOR BLOCK NO:%d",i);
		for(j=0;j<n;j++)
		{
			printf("\nCONNECTION WITH BLOCK NO%d:",j);
			printf("%d",b[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<n;i++)
	{
		printf("Enter the dominators of node:%d:PRESS 111 to show the end and jump to the next block:- ",i);		
		for(j=0;j<n;j++)
		{
			scanf("%d",&xx);
			if(xx!=111)
			{
				dom[i][j]=xx;
			}
			else
			{
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("Enter the predesessor of node:%d:PRESS 111 to show the end and jump to the next block:- ",i);		
		for(j=0;j<n;j++)
		{
			scanf("%d",&x2);
			if(x2!=111)
			{
				pre[i][j]=x2;
			}
			else
			{
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=0;j--)
		{
			if(b[i][j]==1)
			{
				for(k=0;k<n;k++)
				{
					if(dom[i][k]==j)
					{
						printf("Edge %d->%d is back edge:-\n",i,j);
						inloop[j]=1;
						nlp(i);
						for(i=0;i<n;i++)
						{
							if(inloop[i]==1)
							{
								printf("%d",i);
							}
						}					
					}
				}
			}
		}
	}
}
