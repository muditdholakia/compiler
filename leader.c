#include<stdio.h>
void main()
{
	int n=0,i=0,k=0,co,j,leader[100],x=0,m=0,p=0,rep[100];
	char a[100][500],cr;
		printf("Enter total line numbers of code:-");
		scanf("%d",&n);
		if(n>0)
		{
			leader[x]=x;
			x=x+1;
		}
		for(i=0;i<n;i++)
		{
			
			printf("\nYour are giving code of line number %d:",i);
			for(j=0;j<500;j++)
			{
				scanf("%c",&cr);
					if(cr==';')
					{
						a[i][j]=';';
						break;
					}
					else
					{
						a[i][j]=cr;
					}
			}
			
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<500;j++)
			{
				if(a[i][j]=='i')
				{
					if(a[i][j+1]=='f')
					{
						leader[x]=i+1;
						x=x+1;
					}
				}
				if(a[i][j]=='r')
				{
					if(a[i][j+1]=='e')
					{
						if(a[i][j+2]=='t')
						{	
							if(a[i][j+3]=='u')
							{
								if(a[i][j+4]=='r')
								{
									if(a[i][j+5]='n')
									{
										leader[x]=i+1;
										x=x+1;
									}
								}
							}
						}
					}
				}
				if(a[i][j]=='e')
				{
					if(a[i][j+1]=='l')
					{
						if(a[i][j+2]=='s')
						{	
							if(a[i][j+3]=='e')
							{
										leader[x]=i+1;
										x=x+1;
							}
						}
					}
				}
				if(a[i][j]=='e')
				{
					if(a[i][j+1]=='l')
					{
						if(a[i][j+2]=='s')
						{	
							if(a[i][j+3]=='e')
							{
								if(a[i][j+4]=='i')
								{
									if(a[i][j+5]='f')
									{

										leader[x]=i+1;
										x=x+1;
									}
								}
							}
						}
					}
				}
				if(a[i][j]=='c')
				{
					if(a[i][j+1]=='o')
					{
						if(a[i][j+2]=='n')
						{	
							if(a[i][j+3]=='t')
							{
								if(a[i][j+4]=='i')
								{
									if(a[i][j+4]='n')
									{
										if(a[i][j+5]=='u')
										{
											if(a[i][j+6]=='e')
											{	
												leader[x]=i+1;
												x=x+1;
											}
										}
									}
								}
							}
						}
					}
				}
				if(a[i][j]=='g')
				{
					if(a[i][j+1]=='o')
					{
						if(a[i][j+2]=='t')
						{		
							if(a[i][j+3]=='o')
							{
									
								for(m=0;m<n;m++)
								{
									if(a[m][1]==a[i][j+5] && a[m][2]==a[i][j+6])
									{
										leader[x]=m;
										x=x+1;
									}
								}
							}
						}
					}
				}
			}
		}
		printf("Leaders are:");
		for(i=0;i<x;i++)
		{			
			co=0;			
			for(j=0;j<=i;j++)
			{
				if(rep[j]==leader[i])
				{
					co=co+1;
				}		
			}
			if(co>0)
			{
				continue;
			}
			else
			{
			rep[i]=leader[i];
			printf("\n%d",leader[i]);
			}
		
		}
		
		/*for(i=0;i<n;i++)
		{
			j=0;
			printf("\n");
			for(j=0;j<500;j++)
			{
				
					if(a[i][j]==';')
					{
						printf("%c",a[i][j]);
						break;
					}
					else
					{
						printf("%c",a[i][j]);
					}
			}
			
			
		}*/
}
