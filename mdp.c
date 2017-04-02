#include <stdio.h>
#include <math.h>

float max(float a,float b)
{
	if(a>b)
		return a;
	else
		return b;
}
float a[6][6],first[6][6],second[6][6],ans,x,p,q,r,s;
float func(int p,int b,int c,int d)
{
	if(a[p][b]==-1)
		return first[c][d];
	else
		return first[p][b];
}
int main()
{

	int i,j,count=0;
	scanf("%f",&x);
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
			a[i][j]=-1;
	}
	a[1][3]=x;
	a[2][1]=0;
	a[2][2]=0;
	a[2][3]=0;
	a[2][4]=0;
	a[3][1]=0;
	a[3][2]=-x;
	a[3][4]=0;
	a[4][1]=0;
	a[4][2]=0;
	a[4][3]=0;
	a[4][4]=0;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			if(a[i][j]==x || a[i][j]==-x)
			first[i][j]=a[i][j];
			else
			first[i][j]=0;
		}
	}
	while(1)
	{
		for(i=1;i<5;i++)
		{
			for(j=1;j<5;j++)
			{
				printf("%f ",first[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			{
				if(a[i][j]==0)
				{
					//north
					p=0.8*func(i-1,j,i,j)+0.1*func(i,j-1,i,j)+0.1*func(i,j+1,i,j)-x/20;
					printf("%d %d north %f %f %f %f\n",i-1,j-1,func(i-1,j,i,j),func(i,j-1,i,j),func(i,j+1,i,j),p);

					//south
					q=0.8*func(i+1,j,i,j)+0.1*func(i,j-1,i,j)+0.1*func(i,j+1,i,j)-x/20;
					printf("%d %d south %f %f %f %f\n",i-1,j-1,func(i+1,j,i,j),func(i,j-1,i,j),func(i,j+1,i,j),q);
					//east
					r=0.8*func(i,j+1,i,j)+0.1*func(i-1,j,i,j)+0.1*func(i+1,j,i,j)-x/20;
					printf("%d %d east %f %f %f %f\n",i-1,j-1,func(i,j+1,i,j),func(i-1,j,i,j),func(i+1,j,i,j),r);

					//west
					s=0.8*func(i,j-1,i,j)+0.1*func(i-1,j,i,j)+0.1*func(i+1,j,i,j)-x/20;
					printf("%d %d west %f %f %f %f\n",i-1,j-1,func(i,j-1,i,j),func(i-1,j,i,j),func(i+1,j,i,j),s);
//					printf("%d %d north %f south %f west %f east %f\n",i,j,p,q,r,s);
					second[i][j]=max(max(p,q),max(r,s));
				}
				else
					second[i][j]=first[i][j];
			}
		}
		ans=-100000.2;
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			{
				if(a[i][j]==0)
				ans=max(fabs(second[i][j]-first[i][j]),ans);
			}
		}

		printf("delta is %f\n",ans);
		if(ans<=x/20 && count>=11)
			break;
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
				first[i][j]=second[i][j];
		}


		count++;
	}
	printf("%d\n",count);
	return 0;
}





