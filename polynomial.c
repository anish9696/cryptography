#include<stdio.h>
#include<string.h>
#include<math.h>
int convtodec(char *a)
{
int l=strlen(a),i,sum=0;
for(i=0;i<l;i++)
{
sum=sum+(a[i]*pow(2,i));
}
return sum;
}
int modinverse(int a,int b)
{
	int z=a;
	int q,r,t1=0,t2=1,t;
	while(b<0)
	{
		b=b+a;
	}
	while(a>1)
	{
		r=a%b;
		q=a/b;
		a=b;
		b=r;
		t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	if(t1<0)
		t1=t1+z;
	return t1;
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
void main()
{
    char a1[10],a2[10];
    int num1,num2,gc;
    printf("enter x1 coefficients \n");
    gets(a1);
    printf("enter x2 coefficients\n");
    gets(a2);
    num1=convtodec(a1);
    printf("%d",num1);
    //num2=convtodec(a2);
    //gc=mod(num1,num2);
}

