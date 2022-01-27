// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        if(s[0] >= 65 && s[0] <=90)
        {
            s[0] = s[0] + 32;
        }
        
        if(s.length() == 1)
        return s;
        
        for(int i=1;i<s.length();i++)
        {
            if(s[i]>=65 && s[i] <=90)
            {
                s[i] = s[i] + 32;
                s.insert(i," ");
            }
        }
        return s;
        // your code here
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends