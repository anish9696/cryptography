#include<stdio.h>
#define N 5
#define M 3
#define L 10
int keygen(int input[N],int key[M],int l,int m)
{
int i;
int xout,key1;
xout=input[key[0]];
for(i=1;i<m;i++)
{
xout=xout^input[key[i]];
}
key1=input[l-1];
for(i=l-1;i>=0;i--)
{
input[i+1]=input[i];
}
input[0]=xout;
return key1;
}
void performenxor(int plain[L],int keyout[L],int cipher[L])
{
int i;
for(i=0;i<L;i++)
{
cipher[i]=plain[i]^keyout[i];
}
for(i=0;i<L;i++)
{
printf("%d",cipher[i]);
}
printf("\n");
}
void performdexor(int cipher[L],int keyout[L])
{
int out[L],i;
for(i=0;i<L;i++)
{
out[i]=cipher[i]^keyout[i];
}
for(i=0;i<L;i++)
{
printf("%d",out[i]);
}
printf("\n");
}
int main()
{
int m,n,i,input[N],key[M],plain[L],cipher[L];
printf("enter plain text bits\n");
for(i=0;i<L;i++)
{
scanf("%d",&plain[i]);
}
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
int keyout[L];
for(i=0;i<L;i++){
keyout[i]=keygen(input,key,n,m);
}
for(i=0;i<L;i++){
printf("%d",keyout[i]);
}
printf("\n");
printf("after encryption cipher text is\n");
performenxor(plain,keyout,cipher);
printf("\n");
printf("after decryption cipher text is\n");
performdexor(cipher,keyout);
}
