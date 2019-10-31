#include<stdio.h>
int main(){
int a,b,r,q,s,t,s1=1,s2=0,t1=0,t2=1;
printf("enter the numbers");
scanf("%d %d",&a,&b);

while(b>0)
{
q=a/b;
r=a%b;
a=b;
b=r;
if(r==0)
break;
s=s1-(q*s2);
s1=s2;
s2=s;
t=t1-(q*t2);
t1=t2;
t2=t;

}
printf("gcd of two number is %d %d %d",a,s2,t2);
return 0;
}
