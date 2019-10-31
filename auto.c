#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void encrypt(char *a,char *key)
{
int i,l=strlen(a);
for(i=0;i<l;i++)
{
a[i]=((a[i]-65)+(key[i]-65)+26)%26;
}
for(i=0;i<l;i++){
a[i]=a[i]+65;
printf("%c",a[i]);
}
printf("\n");
}

void decrypt(char *a,char *key)
{
int i,l=strlen(a);
for(i=0;i<l;i++)
{
a[i]=((a[i]-65)-(key[i]-65)+26)%26;
}
for(i=0;i<l;i++){
a[i]=a[i]+65;
}
for(i=0;i<l;i++)
printf("%c",a[i]);
printf("\n");
}
void newkey(char *a,char *b,int key)
{
	int i,j,l=strlen(a);
	b[0]=65+key;
	for(i=1,j=0;i<l;i++)
	{
	b[i]=a[j]-65;
	j++;
	}
	for(i=1;i<l;i++){
	b[i]=b[i]+65;
	}
	printf("key value is\n");
	for(i=0;i<l;i++)
	printf("%c",b[i]);
	printf("\n");
}
void main(){
int key;
char a[100],b[100];
printf("enter the text");
gets(a);
printf("enter the key value\n");
scanf("%d",&key);
newkey(a,b,key);
encrypt(a,b);
decrypt(a,b);
}

