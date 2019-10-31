#include<stdio.h>
int main()
{
	int s,a[10][10],b[10][10],co[10],output[10];
	printf("enter the size of array");
	scanf("%d",&s);
	printf("enter the elemants of array");
	int i,j;	
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			scanf("%d",&a[i][j]);
		}	
	}
	printf("enter the coefficient value");
	for(i=0;i<s;i++)
		scanf("%d",&co[i]);
	int det,num1,num2;		
	if(s==3)
	{
num1=(a[0][0]*a[1][1]*a[2][2])+(a[0][1]*a[1][2]*a[2][0])+(a[0][2]*a[1][0]*a[2][1]);
num2=(a[0][1]*a[1][0]*a[2][2])+(a[0][0]*a[1][2]*a[2][1])+(a[0][2]*a[1][1]*a[2][0]);
det=num1-num2;
	b[0][0]=(a[1][1]*a[2][2])-(a[1][2]*a[2][1]);
	b[1][0]=(a[1][2]*a[2][0])-(a[1][0]*a[2][2]);
	b[2][0]=(a[1][0]*a[2][1])-(a[1][1]*a[2][0]);
	b[0][1]=(a[2][1]*a[0][2])-(a[2][2]*a[0][1]);
	b[1][1]=(a[2][2]*a[0][0])-(a[2][0]*a[0][2]);
	b[0][2]=(a[0][1]*a[1][2])-(a[0][2]*a[1][1]);
	b[1][2]=(a[0][2]*a[1][0])-(a[0][0]*a[1][2]);
	b[2][1]=(a[2][0]*a[0][1])-(a[2][1]*a[0][0]);
	b[2][2]=(a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
	}
	if(s==2)
	{
	det=(a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
	}
	printf("determinant of matrix is %d \n",det);
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			printf("%d ",b[i][j]);
		}	
		printf("\n");
	}
	int mod,r;
	printf("enter mod value");
	scanf("%d",&mod);
	r=modulus(det,mod);
	printf("%d "r);
	//if(s==3)
	for(i=0;i<s;i++){
		for(j=0;j<s;j++){
			output[i]+=b[i][j]*co[j];
}
}
	for(i=0;i<s;i++)
		printf("%d",output[i]);
					
}
int modulus(int a,int b)
{
	int q,r,t1=0,t2=1,t;
	int z=a;
	if(b<0)
		b=b+a;
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
