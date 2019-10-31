#include<stdio.h>
#define N 3
int modinverse(int a,int b)
{
	int z=a;
	int q,r,t1=0,t2=1,t;
	while(b<0)
	{
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
		t1=t1+z;
	return t1;
}
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
int solution(int S[N][N],int co[N],int m,int k)
{
	int i,j,d[N];
	for(i=0;i<N;i++)
		d[i]=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{	
			d[i]=d[i]+(S[i][j]*co[j]);		
		}
	}
	for(i=0;i<N;i++)
		d[i]=m*d[i];
	mode(d,k);
	for(i=0;i<N;i++)
	{
		printf("%d\n",d[i]);
	}
return 0;
}
int mode(int out[N],int k)
{
	int i;
	for(i=0;i<N;i++){
		if(out[i]<0)
		{
		while(out[i]<0)
		{
		out[i]=out[i]+k;
		}
		out[i]=out[i]%k;
		}
		else
		out[i]=out[i]%k; 
	}
}
int main()
{
	int i,j,n,mat[N][N],det,c[N];
	int adj[N][N],mod,mdinverse;
	printf("enter the mod value\n");
	scanf("%d",&mod);
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
	printf("enter the elemants of coefficient matrix\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	printf("random text");
	det=determinant(mat,n);
	printf("determinanat is%d",det);
	mdinverse=modinverse(mod,det);

	printf("modular inverse value is%d\n",mdinverse);
	adjoint(mat,adj);
	display(adj,n);
	solution(adj,c,mdinverse,mod);
	return 0;
}
