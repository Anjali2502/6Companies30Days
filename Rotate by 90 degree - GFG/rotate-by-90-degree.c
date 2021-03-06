// { Driver Code Starts
//Initial Template for C



#include<stdio.h>

 // } Driver Code Ends
//User function Template for C


void rotate(int n,int a[][n])
{
    
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            int temp = a[i][j];
            
            a[i][j] = a[j][n-i-1];
            a[j][n-i-1] = a[n-i-1][n-j-1];
            a[n-i-1][n-j-1] = a[n-j-1][i];
            a[n-j-1][i] = temp;
        }
    }
    //code here
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d",&t); 
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }
        rotate(n,a);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}

  // } Driver Code Ends