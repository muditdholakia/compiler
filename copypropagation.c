#include<stdio.h>
#include<string.h>
int l,m,p,q,r,n,nd,c[100][100],k[100][100],i,j,npre[100],pre[100][100],init[100],cpin[100][100],cpout[100][100],tmp,tmp2[100],cnt,bl[100][2];


void cpinn(int x)
{
for(i=0;i<nd;i++)
{
	init[i]=1;
}
	for(l=0;l<npre[x];l++)
	{
				
		if(pre[x][l]!=0)
		{
			cnt=0;
			for(p=0;p<nd;p++)
			{
				if(cpout[pre[x][l]][p]==0)
				{
					cnt++;
				}			
			}
			if(cnt==nd)
			{
				for(m=0;m<nd;m++)
				{
					init[m]=init[m]&1;	
				}		
			}
			else
			{
				for(m=0;m<nd;m++)
				{
					init[m]=init[m]&cpout[pre[x][l]][m];	
				}
			}
		}
		else
		{
			for(i=0;i<nd;i++)
			{
				init[i]=0;
			}
		}
	}
for(m=0;m<nd;m++)
{
	cpin[x][m]=init[m];	
}

}

void cpoutt(int y)
{
	int tempx;	
	for(i=0;i<nd;i++)
	{
		if(cpin[y][i]-k[y][i]<0)
		{
			tempx=0;
		}
		else
		{
			tempx=cpin[y][i]-k[y][i];
		}
		cpout[y][i]=c[y][i]|tempx;
	}
}

void main()
{
char qd[100][100];

printf("Enter total number of node:-");
scanf("%d",&n);
printf("Enter total number of definations");
scanf("%d",&nd);
for(i=0;i<nd;i++)
{
	printf("Quadreuple of defination no:-%d:-\n",i);
	printf("Left side of the assignment.ex x<-y is there then press x then press enter\n");
	scanf("%s",&qd[i][0]);
	printf("Right side of the assignment.ex x<-y is there then press y then press enter\n");
	scanf("%s",&qd[i][1]);
	printf("Blocknumber is\n");
	scanf("%d",&bl[i][0]);
	printf("Enter line number then press enter:-\n");
	scanf("%d",&bl[i][1]);
}
for(i=0;i<n;i++)
{
	printf("Copy definations for node :%d:-",i);
	for(j=0;j<nd;j++)
	{
			scanf("%d",&c[i][j]);
	}
}
for(i=0;i<n;i++)
{
	printf("Kill definations for node :%d:-",i);
	for(j=0;j<nd;j++)
	{
			scanf("%d",&k[i][j]);
	}
}
for(i=0;i<n;i++)
{
	printf("Number of predesessor for node :%d:-",i);
	scanf("%d",&npre[i]);
	for(j=0;j<npre[i];j++)
	{
		printf("Predesessor number:-%d:-is:-",j);
		scanf("%d",&pre[i][j]);
	}
}
for(i=0;i<n;i++)
{
	for(j=0;j<nd;j++)
	{
		cpin[i][j]=0;
		cpout[i][j]=0;
	}
}
for(r=1;r<n;r++)
{
	cpinn(r);
	cpoutt(r);
}
for(i=0;i<n;i++)
{
	printf("\nCpin set for block no:-%d:-",i);
	printf("{");
	for(j=0;j<nd;j++)
	{
		if(cpin[i][j]==1)
		{
			printf("<%c,%c,%d,%d>",qd[j][0],qd[j][1],bl[j][0],bl[j][1]);
		}
	}
	printf("}");
}
for(r=0;r<nd;r++)
{
	cpout[n-1][r]=0;
}
for(i=0;i<n;i++)
{
	printf("\nCpout set for block no:-%d:-",i);
	printf("{");
	for(j=0;j<nd;j++)
	{
		if(cpout[i][j]==1)
		{
			printf("<%c,%c,%d,%d>",qd[j][0],qd[j][1],bl[j][0],bl[j][1]);
		}
	}
	printf("}");
}
}
