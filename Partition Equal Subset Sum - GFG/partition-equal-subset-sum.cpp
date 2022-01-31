// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:


    int dp[1001][1001];
    int solve(int n, int arr[], int sum)
    {
        if(n<0)
        {
            if(sum == 0)
            return 1;
            
            return 0;
        }
        
        if(sum<0)
        return 0;
        
        if(sum ==0)
        return 1;
        
        if(dp[n][sum] != -1)
        return dp[n][sum];
        
        return dp[n][sum] = solve(n-1,arr,sum-arr[n]) || solve(n-1,arr,sum);
        
    }

    int equalPartition(int N, int arr[])
    {
        if(N==1)
        return 0;
        int sum = 0;
        sum = accumulate(arr, arr+N, sum);
        if(sum % 2 == 1)
        return 0;
        
        sum = sum/2;
        dp[N][sum];
        memset(dp,-1,sizeof(dp));
        
        return solve(N-1,arr,sum);
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends