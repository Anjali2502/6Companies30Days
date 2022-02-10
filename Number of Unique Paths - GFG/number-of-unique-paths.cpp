// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        
        int arr[a][b] = {0};
        
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(i == 0 || j== 0)
                arr[i][j] = 1;
                
                else
                
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        
        return arr[a-1][b-1];
        //code here
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends