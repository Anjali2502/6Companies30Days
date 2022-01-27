// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int n = 0; 
        if(str[0] == '-')
        {
            for(int i=1;i<str.length();i++)
            {
                if(str[i]<48 || str[i] >57)
                return -1;
                else
                {
                    n = n*10;
                    n += str[i] - 48;
                }
            }
            n = n*(-1);
            return n;
        }
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]<48 || str[i] >57)
            return -1;
            else
            {
                n = n*10;
                n += str[i] - 48;
            }
        }
        
        return n;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends