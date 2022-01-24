// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    
	    if(n == 1)
	    return arr[0];
	    
	    if(n==2)
	    return abs(arr[0] - arr[1]);
	    
	     int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	       
	    bool dp[n+1][sum+1];
	    
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(j==0)
	                dp[i][j]=true;
	            else if(i==0)
	                dp[i][j]=false;
	            else if(arr[i-1]>j)
	                dp[i][j]=dp[i-1][j];
	            else
	                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
	        }
	    }
	    
	    int minimum=INT_MAX;
	    for(int i=0;i<=sum/2;i++)
	    {
	        if(dp[n][i]==true)
	            minimum=min(minimum,sum-2*i);
	    }
	    
	    return minimum;
	    
	    // Your code goes here
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends