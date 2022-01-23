// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    int dp[10001];
    //Function to find the maximum money the thief can get.
    
    int max_money(int *arr, int i, int n)
    {
        if(i>=n)
        return 0;
        
        if(dp[i] != -1)
        return dp[i];
        
        int a1 = arr[i] + max_money(arr,i+2,n);
        int a2 = max_money(arr,i+1,n);
        dp[i] = max(a1,a2);
        return dp[i];
    }
    
    int FindMaxSum(int arr[], int n)
    {
        for(int i=0;i<n;i++)
            dp[i] = -1;
        
        return max_money(arr,0,n);
        // Your code here
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends