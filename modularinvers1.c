#include<stdio.h>
int modinverse(int a,int b)
{
    int z=a;
    int q,r,t1=0,t2=1,t;
    while(b<0){
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
        t1+=z;
        return t1;
}
int main()
{
    int num1,num2;
    printf("enter the numbers");
    scanf("%d %d",&num1,&num2);
    int z=modinverse(num1,num2);
    printf("output is%d",z);
    return 0;
}
