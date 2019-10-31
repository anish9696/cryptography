#include<stdio.h>
#include<string.h>
#define N 5
#define M 3
void performxor(int input[N],int key[M],int l,int m)
{
int i;
int xout;
xout=input[key[0]];
for(i=1;i<m;i++)
{
xout=xout^input[key[i]];
}
for(i=l-1;i>=0;i--)
{
input[i+1]=input[i];
}
input[0]=xout;
for(i=0;i<l;i++)
{
printf("%d\t",input[i]);
}
printf("\n");
}
int main()
{
int n,input[10],key[10],m;
int i;
printf("enter initial seed length value\n");
scanf("%d",&n);
printf("enter initial seed value\n");
for(i=0;i<n;i++)
{
scanf("%d",&input[i]);
}
printf("enter no of xor operation\n");
scanf("%d",&m);
printf("enter xor performing key values\n");
for(i=0;i<=m;i++)
{
scanf("%d",&key[i]);
}
for(i=0;i<20;i++){
performxor(input,key,n,m);
}
}

