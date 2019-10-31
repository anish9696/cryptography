#include<stdio.h>
#define N 4
void getcofactor(int mat[N][N],int temp[N][N],int p,int q,int n)
{
        int i=0,j=0,row,col;
        for(row=0;row<n;row++)
        {
            for(col=0;col<n;col++)
            {
                if(row!=p && col!=q)
                {
                    temp[i][j++]=mat[row][col];
                    if(j==n-1)
                    {
                       j=0;
                       i++;
                    }
                }
            }
        }
}

int determinant(int mat[N][N],int n)
{
    int d=0,f;
    if(n==1)
        return mat[0][0];
    int temp[n][n];
    int sign=1;
    for(f=0;f<n;f++)
    {
        getcofactor(mat,temp,0,f,n);
        d+=sign*mat[0][f]*determinant(temp,n-1);
        sign=-sign;
    }
    return d;
}


void display(int mat[N][N],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            {
            printf("%d ",mat[i][j]);
            }
    printf("\n");
    }
}
int main()
{
    int i,j,n,mat[10][10];
    printf("enter the size of matrix\n");
    scanf("%d",&n);
    printf("enter the elemants of array\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    printf("Determinant of the matrix is : %d",
            determinant(mat, n));
    return 0;

}
