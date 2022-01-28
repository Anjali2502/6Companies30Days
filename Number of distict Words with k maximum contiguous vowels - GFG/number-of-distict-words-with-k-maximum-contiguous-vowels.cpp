// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  
    long long power(long long x, long long y, long long p)
{
    long long int res = 1;

    x = x % p;

    if (x == 0)
        return 0;

    while (y > 0) {

        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
  
    int kvowelwords(int N, int K) {
        
        // Write Your Code here
        long long dp[N+1][K+1] = {0};
        
        long long n = 1000000007;
        
        // dp[0][0] = 1;
        
        // for(int i=0;i<=K;i++)
        // {
        //     dp[0][i] = 1;
        // }
        long long sum=1;
        
        for(long long i=1;i<=N;i++)
        {
            dp[i][0] = sum*21;
            dp[i][0]%= n;
            sum = dp[i][0];
            for(long long j=1;j<=K;j++)
            {
                if(j>i)
                dp[i][j] = 0;
                
                else if(j == i)
                dp[i][j] = power(5,i,n);
                
                else
                dp[i][j] = dp[i-1][j-1]*5;
                
                dp[i][j]%= n;
                
                sum += dp[i][j];
                sum%= n;
            }
        }
        return sum;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends