// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void backtrack(string temp, int start,int closed,int n,vector<string> &ans)
    {
        if(temp.length() == 2*n)
        {
            ans.push_back(temp);
            return ;
        }
        else
        {
            if(start<n)
            backtrack(temp+"(",start+1,closed,n,ans);
            
            if(closed<start)
            backtrack(temp+")",start,closed+1,n,ans);
            
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        vector<string>ans;
        backtrack("(",1,0,n,ans);
        
        return ans;
        // Your code goes here 
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends