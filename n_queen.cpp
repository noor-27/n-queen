#include<iostream>
#include<stdlib.h>
using namespace std;
int isOk(char **A,int i,int j,int n)
{
	int l,k;
	for(l=0;l<n;l++)		//check horizontal
	{
		if(A[i][l]=='#')
		return 0;
	}
	for(k=i+1,l=j+1;k<n&&l<n;k++,l++) //chek diagonally left downward;
	{
		if(A[k][l]=='#')
		return 0;
	}
	for(k=i-1,l=j-1;k>=0&&l>=0;k--,l--) //chek diagonally left upward
	{
		if(A[k][l]=='#')
		return 0;
	}  
	for(k=i-1,l=j+1;k>=0&&l<n;k--,l++) //chek diagonally right upward
	{
		if(A[k][l]=='#')
		return 0;
	}
	for(k=i+1,l=j-1;k<n&&l>=0;k++,l--) //chek diagonally right downward
	{
		if(A[k][l]=='#')
		return 0;
	}
	return 1;
}
void n_queen(char **A,int n)
{
	//cout<<"inside n_queen";
	int B[n+1],C[n+1],i,s,t,j,p=-1,q=-1,i1,j1;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{	
		//	cout<<" "<<i<<" "<<j<<"\n";
			int res=isOk(A,i,j,n);
		//	cout<<res<<".............\n";
			if(res==1)
			{
			//	cout<<"inside n_queen isok\n";
				A[i][j]='#';
				B[++p]=i;
				C[++q]=j;
				break;
			}
		}
		while(i>=n)				//backtracking
		{
	//	cout<<"inside n_queen while";
			A[B[p]][C[q]]='0';
			i=B[p]+1;
			j=C[q];
			B[p--]=0;
			C[q--]=0;
			while(i<n)
			{
				if(isOk(A,i,j,n)==1)
				{
					A[i][j]='#';
					B[++p]=i;
					C[++q]=j;
					break;
				}
				i++;
			}
		}
	}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
		}
}
int main()
{
	
	int n,i,j;
	cout<<"enter the size of board\n";
	cin>>n;
	do
	{
	char **A=(char**)malloc(sizeof(char*)*n);
		for(i=0;i<n;i++){
			A[i]=(char*)malloc(sizeof(char)*n);
		}
		
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j]='0';
		}
	}
	cout<<endl;
	n_queen(A,n);
	cout<<"\npress valid choice more than 3 to continue";
	cin>>n;
	}while(n>3);
}
