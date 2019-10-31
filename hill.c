#include<stdio.h>
#include<string.h>
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
void adjoint(int A[N][N],int adj[N][N])
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[N][N];

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            getcofactor(A, temp, i, j, N);

            sign = ((i+j)%2==0)? 1: -1;

            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}
void encrypt(int plain[3][4],int key[N][N],int cipher[3][4],int m)
{
    int i,j,k,sum;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < N; j++)
        {
            cipher[i][j] = 0;
            for (k = 0; k < N; k++)
                cipher[i][j] += plain[i][k]*key[k][j];
        }
    }

}
int mode(int out[N][N],int k)
{
	int i,j;
	for(i=0;i<N;i++){
	    for(j=0;j<N;j++)
	    {
		if(out[i][j]<0)
		{
		while(out[i][j]<0)
		{
		out[i][j]=out[i][j]+k;
		}
		out[i][j]=out[i][j]%k;
		}
		else
		out[i][j]=out[i][j]%k;
        }
	}
}
void decrypt(int cipher[3][4],int adj[N][N],int out[3][4],int m,int modd)
{
       int i,j,k,sum,z=26;
       for(i=0;i<N;i++)
       {
           for(j=0;j<N;j++)
           {
               adj[i][j]=modd*adj[i][j];
           }
       }
       mode(adj,z);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < N; j++)
        {
            out[i][j] = 0;
            for (k = 0; k < N; k++)
                out[i][j] += cipher[i][k]*adj[k][j];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<N;j++)
        {
            out[i][j]=out[i][j]%26;
        }
    }
}

int main()
{
    int n,key[N][N],l,k=0,i,j,m;
    char a[100];
    printf("enter the plain text\n");
    gets(a);
    printf("enter the size of key matrix\n");
    scanf("%d",&n);
    printf("enter the key matrix\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&key[i][j]);
        }
    }
    l=strlen(a);
    m=l/N;
    int plain[m][N],cipher[m][N];
    for(i=0;i<m;i++)
    {
        for(j=0;j<N;j++)
        {
            plain[i][j]=(a[k]-65)%26;
            k++;
        }
    }
    printf("plaintext is\n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",plain[i][j]);
        }
        printf("\n");
    }
    printf("key is\n");
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",key[i][j]);
        }
        printf("\n");
    }
    encrypt(plain,key,cipher,m);
    printf("cipher text is\n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cipher[i][j]=cipher[i][j]%26;
            printf("%d ",cipher[i][j]);
        }
        printf("\n");
    }
    int det,modd,z=26,adj[m][N];
    det=determinant(key,n);
    printf("determinant of matrix is %d\n",det);
    modd=modinverse(z,det);
    printf("modular inverse of determinant is%d\n",modd);
    adjoint(key,adj);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    int out[m][N];
    decrypt(cipher,adj,out,m,modd);
    for(i=0;i<m;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",out[i][j]);
        }
        printf("\n");
    }
    return 0;
}
