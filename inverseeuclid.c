#include<stdio.h>
int modinverse(int ar1,int br2)
{
    int q,r,t1=0,t2=1,t;
    int z=ar1;
    if(br2<0)
        br2=br2+ar1;
    while(ar1>1)
    {
        r=ar1%br2;
        q=ar1/br2;
        ar1=br2;
        br2=r;

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
    int a[2][2],i,j,b1,b2,b3,b4,m;
    int det;
    printf("enter the mod value ");
    scanf("%d ",&m);
    printf("enter the elemants of array \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
            scanf("%d ",&a[i][j]);
    }
    printf("the entered matrix is");
    for(i=0;i<2;i++)
    {
        printf("\n");
        for(j=0;j<2;j++)
            printf("%d ",a[i][j]);
    }
    printf("\n");
    det=(a[0][0]* a[1][1])-(a[0][1]*a[1][0]);
    int n2=det;
    printf("the determinant of matrix is %d ",det);
    printf("\n");
    printf("adjoint of matrix is \n");
    b1=a[0][0];
    b2=a[0][1];
    b3=a[1][0];
    b4=a[1][1];
    a[0][0]=b4;
    a[0][1]=(-b2);
    a[1][0]=(-b3);
    a[1][1]=b1;
    for(i=0;i<2;i++)
    {
        printf("\n");
        for(j=0;j<2;j++)
            printf("%d ",a[i][j]);
    }

    int modinv;
    modinv=modinverse(m,n2);
    printf("modular inverser value is %d",modinv);
}
