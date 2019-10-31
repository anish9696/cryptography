#include<stdio.h>
#define N 3
int determinant(int mat[N][N],int n)
{
int d=0,f;
if(n==1)
return mat[0][0];
int temp[N][N];
int sign=1;
for(f=0;f<n;f++)
{
getcofactor(mat,temp,0,f,n);
d+=sign*mat[0][f]*determinant(temp,n-1);
sign=-sign;
}
return d;
}
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
void adjoint(int A[N][N],int adj[N][N])
{
	int i,j;
	if(N==1)
	{
		adj[0][0]=1;
		return;	
	}
	int sign=1,temp[N][N];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			getcofactor(A,temp,i,j,N);
			sign=((i+j)%2==0)?1:-1;
			adj[j][i]=(sign)*(determinant(temp,N-1));
		}
	}		
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
	int i,j,n,mat[N][N],det;
	int adj[N][N];
	float inv[N][N],deter;
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
	det=determinant(mat,n);
	deter=determinant(mat,n);
	printf("determinant of matrix is%d\n",det);
	display(mat,n);
	adjoint(mat,adj);
	display(adj,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			inv[i][j]=adj[i][j]/deter;
		}
	}
	printf("inverse of matrix is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%.3f",inv[i][j]);
		}
		printf("\n");
	}
return 0;
}
