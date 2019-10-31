#include<stdio.h>
#include<string.h>
void encrypt(char *a,int key)
{
int i,l=strlen(a);
for(i=0;i<l;i++)
{
a[i]=((a[i]-65)*key)%26;
}
for(i=0;i<l;i++){
a[i]=a[i]+65;
}
for(i=0;i<l;i++)
printf("%c",a[i]);
printf("%c",key+65);
printf("\n");
}
void decrypt(char *a,int key)
{
int num=26;
int i,l=strlen(a),mod;
mod=modinverse(num,key);
printf("modular inverse value is%d\n",mod);
for(i=0;i<l;i++)
{
a[i]=((a[i]-65)*mod)%26;
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
	int key,g,num=26;
	char a[100];
	printf("enter the text\n");
	scanf("%s",a);
	printf("enter the key value\n");
	scanf("%d",&key);
	g=gcd(num,key);
	if(g==1)
	{
	encrypt(a,key);
	decrypt(a,key);	
	}
	else
	printf("enter valid key\n");
}	
