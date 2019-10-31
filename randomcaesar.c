#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char *a,int key)
{
int i,l=strlen(a);
for(i=0;i<l;i++)
{
a[i]=(a[i]-65+key)%26;
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
int i,l=strlen(a);
for(i=0;i<l;i++)
{
a[i]=(a[i]-65-key+26)%26;
}
for(i=0;i<l;i++){
a[i]=a[i]+65;
}
for(i=0;i<l;i++)
printf("%c",a[i]);
printf("\n");
}

void main(){
char a[100];
printf("enter the text");
scanf("%s",a);
srand(time(0));
int key=rand()%26;
encrypt(a,key);
decrypt(a,key);
}

