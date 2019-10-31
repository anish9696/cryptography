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
    int a,determinant,z;
    int arr[2][2],i,j;
    printf("enter mod number ");
    scanf("%d ",&a);
    printf("enter the elemants of array");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
            scanf("%d ",arr[i][j]);
    }
    printf("entered matrix is ");
    for(i=0;i<2;i++)
    {
        printf("\n");
        for(j=0;j<2;j++)
            printf("%d ",arr[i][j]);
    }
    printf("\n");
    determinant=(arr[0][0]* arr[1][1])-(arr[0][1]*arr[1][0]);
    z=modinverse(a,determinant);
    printf("the output of code is %d",z);
    return 0;
}
