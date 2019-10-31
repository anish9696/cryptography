#include<stdio.h>
#include<string.h>
#define N 4
void encrypt(char *a,int key[N])
{
int l=strlen(a),i;
for(i=0;i<l/2;i++)
{
a[i]=a[i]^key[i];
}
}
void decrypt(char *a,int key[N])
{
int l=strlen(a),i;
for(i=0;i<l/2;i++)
{
a[i]=a[i]^key[i];
}
}
void swap(char *a)
{
int i;
char temp;
for(i=0;i<N;i++)
{
temp=a[i];
a[i]=a[i+4];
a[i+4]=temp;
}
}
void main()
{
srand(time(0));
int i,key1[10],key2[10];
char a[100];
printf("enter plain text\n");
gets(a);
for(i=0;i<4;i++)
{
key1[i]=rand()%10;
}
for(i=0;i<N;i++)
{
printf("%d",key1[i]);
}
printf("\n");
encrypt(a,key1);
printf("%s\n",a);
swap(a);
printf("%s",a);
printf("\n");
for(i=0;i<4;i++)
{
key2[i]=rand()%10;
}
for(i=0;i<N;i++)
{
printf("%d",key2[i]);
}
printf("\n");
encrypt(a,key2);
printf("%s",a);
printf("\n");
decrypt(a,key2);
printf("%s",a);
printf("\n");
swap(a);
decrypt(a,key1);
printf("%s",a);
printf("\n");
}
