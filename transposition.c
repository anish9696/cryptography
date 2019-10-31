#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 5
void transposition(char *a, int key[N],char *c)
{
int i,j;
int k=0,l=strlen(a);
for(i=0;i<l;i=i+5)
{
for(j=0;j<N;j++)
{
c[i+j]=a[key[j]+i];
}
}
for(i=0;i<l;i++)
{
printf("%c",c[i]);
}
printf("\n");
}
int main()
{
int key1[N],key2[N],i;
char a[100];
printf("enter plain text\n");
gets(a);
printf("enter encryption key value\n");
for(i=0;i<N;i++)
scanf("%d",&key1[i]);
int l=strlen(a);
char c[l],d[l];
printf("encrypted text is\n");
transposition(a,key1,c);
printf("enter decryption key value\n");
for(i=0;i<N;i++)
scanf("%d",&key2[i]);
transposition(c,key2,d);
}
