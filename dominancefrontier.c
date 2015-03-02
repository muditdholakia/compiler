#include<stdio.h>
int i,j,k,x,y,z,n,sdom[100][100],reach[100][100],sd,dfront[100][100],df[100];

void dfrnt(int d)
{
	df[d]=1;	
	for(k=0;k<n;k++)
	{
		if(reach[d][k]==1)
		{
			if(sdom[k][d]!=1)
			{
				if(df[k]==1)
				{				
					dfront[d][k]=1;
					break;
				}
				else
				{
					dfront[d][k]=1;
				}	
			}
		}
	}
}
void main()
{

printf("Enter total number of basic blocks:-");
scanf("%d",&n);
printf("Insert strict dominator set of every basic block press 1 if it is strict dominator of corresponding block else 0 .\n");
for(i=0;i<n;i++)
{
	printf("node number:-%d:-",i);
	for(j=0;j<n;j++)
	{
		printf("Is %d the strict dominator of %d?press 1 for yes and 0 for no the n press ENTER\n",j,i);
		scanf("%d",&sdom[i][j]);
	}
}

printf("Insert reachable set of every basic block press 1 if it is reachable else 0 .\n");
for(i=0;i<n;i++)
{
	printf("node number:-%d:-",i);
	for(j=0;j<n;j++)
	{
		printf("Is %d reachable?press 1 for yes and 0 for no the n press ENTER\n",j);
		scanf("%d",&reach[i][j]);
	}
}


printf("CHECKING!!Dominance Frontier:-");

for(i=0;i<n;i++)
{
	dfrnt(i);
}
for(i=0;i<n;i++)
{
	printf("Dominance Frontier set for node %d is:-",i);	
	printf("{");	
	for(j=0;j<n;j++)
	{
		if(dfront[i][j]==1)
		{
			printf("%d",j);
		}
	}
	printf("}");
}
}
