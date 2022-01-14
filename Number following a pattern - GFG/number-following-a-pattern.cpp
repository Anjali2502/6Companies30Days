// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        
        // int n = S.length();
        stack<int>q;
        string t = "";
        int n = 1;
        set<int>s;
        for(int i=0;i<S.length();i++)
        {
            if(S[i] == 'D')
            {
                q.push(n++);
            }
            else
            {
                q.push(n++);
                while(!q.empty())
                {
                    t += to_string(q.top());
                    q.pop();
                }
            }
        }
        
        q.push(n);
        while(!q.empty())
        {
            t += to_string(q.top());
            q.pop();
        }
        return t;
        // code here 
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends