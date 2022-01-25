// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>ans;
        ans.push_back(1);
        
        stack<int>s;
        s.push(0);
        
        for(int j=1;j<n;j++)
        {
            
            while(!s.empty() && price[s.top()] <= price[j])
            {
                s.pop();
            }
            if(s.empty())
            {
                ans.push_back(j+1);
            }
            else
            {
                ans.push_back(j-s.top());
            }
            s.push(j);
            
            // if(price[j] < price[j-1])
            // ans.push_back(1);
            // else
            // {
            //     int i=j-1;
            //     int count = 1;
            //     while(i>=0 && price[i] <= price[j])
            //     {
            //         count++;
            //         i--;
            //     }
            //     ans.push_back(count);
            // }
        }
        
        return ans;
       // Your code here
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends