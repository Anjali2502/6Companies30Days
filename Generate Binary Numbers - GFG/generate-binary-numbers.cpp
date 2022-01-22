// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    vector<string>s;
    s.push_back("1");
    if(N==1)
    return s;
    
    for(int i=2;i<=N;i++)
    {
        int k=i;
        string str = "";
        while(k)
        {
            int t = k%2;
            str = to_string(t) + str;
            k = k/2;
        }
        s.push_back(str);
    }
    
    return s;
	// Your code here
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends