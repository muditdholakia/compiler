#include<stdio.h>
main()
{
	int a[100][100],xct,cnt,i,j,k,l,m,n,p,q,n1,n2,dom[100][100],tmp[100][100],tmp2[100][100],tmp3[100][100],mt[100],mtc[100];
	printf("ENTER TOTAL NUMBER OF BASIC BLOCKS:");
	scanf("%d",&n);
	printf("\nASSUMPTION::-->>BY DEFAULT FIRST AND LAST NODE WILL BE TREATED AS ENTRY AND EXIT NODES.\n");
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
	dom[0][0]=1;
	for(i=1;i<n;i++)
	{
		if(a[i][0]==1)
		{
			dom[i][0]=1;
		}		
		else
		{
			for(j=i;j>=0;j--)
			{		
				if(a[i][j]==1)
				{
					for(k=0;k<n;k++)
					{
						dom[i][k]=dom[j][k];
					}
					dom[i][j]=1;				
					break;
				}
			}

		}	
	}

for(i=n-1;i>=0;i--)
{	
	cnt=0;	
	for(j=i-1;j>0;j--)
	{
		if(a[i][j]==1)
		{
			tmp[i][cnt]=j;
			cnt++;	
			if(cnt>1)
			{
				mt[i]=1;
				mtc[i]=cnt;
			}
		}
	}
}


for(i=1;i<n;i++)
{
	xct=0;	
	if(mt[i]==1)
	{
		for(j=mtc[i]-1;j>0;j--)
		{
			for(k=j-1;k>=0;k--)
			{
				for(p=0;p<i;p++)
				{
					if(dom[tmp[i][j]][p]==dom[tmp[i][k]][p])
					{
						tmp2[i][xct]=dom[tmp[i][j]][p];
						xct++;
					}
				}	
			}
		}
	}
}

for(i=0;i<n;i++)
{
	if(mt[i]==1)
	{
		for(k=0;k<n;k++)
		{
			dom[i][k]=tmp2[i][k];
			for(j=i+1;j<n;j++)
			{
				if(a[i][j]==1)
				{
					for(n1=0;n1<n;n1++)
					{
						dom[j][n1]=dom[i][n1];
					}
					dom[j][i]=1;
				}
			}
		}
	}
}

for(i=0;i<n;i++)
	{
		printf("FOR BLOCK NO:%d",i);
		printf("\nDominator are:");
		for(j=0;j<n;j++)
		{
			if(dom[i][j]==1)
			{
				printf("\t%d",j);
			}
		}
		printf("\n");
	}

}

