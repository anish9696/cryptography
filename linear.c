#include<stdio.h>
int* exgcd(int a,int b)
{
int r,q,s,t,s1=1,s2=0,t1=0,t2=1;
int arr[2];
	while(b>0)
	{
	q=a/b;
	r=a%b;
	a=b;
	b=r;
	if(r==0)
	break;
	s=s1-(q*s2);
	s1=s2;
	s2=s;
	t=t1-(q*t2);
	t1=t2;
	t2=t;
	}
	arr[0]=s;
	arr[1]=t;
return arr;
}
void main()
{
	int x,y,c,s,t;	
	printf("enter x coefficient ");
	scanf("%d",&x);
	printf("enter y coefficient");
	scanf("%d",&y);
	printf("enter value of constant");
	scanf("%d",&c);
	int gc=gcd(x,y);
	printf("gcd is %d",gc);
	s=x/gc;
	t=y/gc;
	if(gc==1)
		printf("no solution exist");
	if(gc>1)
{
	int *d=exgcd(s,t);
	int x1=(c/gc)*d[0];
	printf("value of particularx= %d \n ",x1);
	int y1=(c/gc)*d[1];
	printf("value of particulary= %d \n ",y1);
	int px,py,i;
	for(i=1;i<=5;i++)
		{
			px=x1+i*(y/gc);
			printf("general= %d \n",px);
			py=y1+i*(x/gc);
			printf("general= %d \n",py);
		}	
	}
}
int gcd(int a,int b)
{
	int r;
	while(b>0)
{
r=a%b;
a=b;
b=r;
}
return a;
}

