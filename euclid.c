#include<stdio.h>
int main(){
int a,b,r;
printf("enter the numbers");
scanf("%d %d",&a,&b);
while(b>0)
{
r=a%b;
a=b;
b=r;
}
printf("gcd of two number is %d",a);
return 0;
}
