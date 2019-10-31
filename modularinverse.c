#include<stdio.h>
int modinverse(int a,int b)
{
    int q,r,t1=0,t2=1,t;
    int z=a;
    if(b<0)
        b=b+a;
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
    int a,b,z;
    printf("enter two number ");
    scanf("%d %d",&a,&b);
    z=modinverse(a,b);
    printf("the output of code is %d",z);
    return 0;
}
