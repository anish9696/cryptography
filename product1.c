#include<stdio.h>
#include<string.h>
#define N 8
void performxor(char *a,int key[N])
{
int l=strlen(a),i;
for(i=0;i<l;i++)
{
a[i]=a[i]^key[i];
}
}
void sbox(char *a)
{
int i;
char temp;
for(i=2;i<(N-2);i=i+2)
{
temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
}
}
void dbox(char *a)
{
int i;
char temp;
for(i=0;i<N/2;i++)
{
temp=a[i];
a[i]=a[i+4];
a[i+4]=temp;
}
}
void main()
{
char a[100];
srand(time(0));
int key[N],i,num[10];
printf("enter plain text\n");
gets(a);
printf("enter key\n");
for(i=0;i<N;i++)
{
scanf("%d",&key[i]);
}

performxor(a,key);
printf("after performing xor\n");
printf("%s\n",a);
sbox(a);
printf("after performing sboxing\n");
printf("%s\n",a);
dbox(a);
printf("after performing dboxing\n");
printf("%s\n",a);
dbox(a);
printf("decryption process\n");
printf("after performin dboxing\n");
printf("%s\n",a);
sbox(a);
printf("after performin sboxing\n");
printf("%s\n",a);
performxor(a,key);
printf("after performin xor\n");
printf("%s\n",a);
}
