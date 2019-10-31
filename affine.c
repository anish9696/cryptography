#include<stdio.h>
#include<string.h>
void encrypt(char *a,int key1,int key2)
{
int i,l=strlen(a);
for(i=0;i<l;i++)
{
a[i]=(((a[i]-65)*key1)+key2)%26;
}
for(i=0;i<l;i++){
a[i]=a[i]+65;
}
for(i=0;i<l;i++)
printf("%c",a[i]);
printf("\n");
}
void decrypt(char *a,int key1,int key2)
{
int num=26;
int i,l=strlen(a),mod;
mod=modinverse(num,key1);
printf("modular inverse value is%d\n",mod);
for(i=0;i<l;i++)
{
a[i]=((a[i]-65)-key2);
	if(a[i]<0)
		{
		while(a[i]<0)
		{
		a[i]=a[i]+num;
		}
		a[i]=((a[i]*mod)%26);
		}
	else
	{
		a[i]=(a[i]*mod)%26;
	}
}
for(i=0;i<l;i++){
a[i]=a[i]+65;
}
for(i=0;i<l;i++)
printf("%c",a[i]);
printf("\n");
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
	int key1,key2,g,num=26;
	char a[100];
	printf("enter the text\n");
	scanf("%s",a);
	printf("enter the key values\n");
	scanf("%d %d",&key1,&key2);
	g=gcd(num,key1);
	if(g==1)
	{
	encrypt(a,key1,key2);
	decrypt(a,key1,key2);	
	}
	else
	printf("enter valid key1\n");
}	
