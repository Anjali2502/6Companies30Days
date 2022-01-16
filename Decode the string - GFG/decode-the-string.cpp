// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        
        if(!s.length())
            return s;
        stack<int>num;
        stack<char>s1;
        int i=0;
        while(i<s.length())
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int digit = 0;
                while(i<s.length())
                {
                    digit = 10*digit + s[i] - 48;
                    if(s[i+1] >= '0' && s[i+1] <= '9')
                        i++;
                    else
                        break;
                }
                num.push(digit);
                // cout<<num.top();
            }
            else if(s[i] == '[')
            {
                if(s[i-1] >= '0' && s[i-1] <= '9')
                    ;
                else
                {
                    num.push(1);
                    // cout<<num.top();
                }
                s1.push(s[i]);
                // cout<<s1.top();
            }
            else if(s[i] == ']')
            {
                int t;
                string temp = "";
                if(!num.empty())
                {
                    t = num.top();
                    num.pop();
                }
                while(!s1.empty() && s1.top() != '[')
                {
                    temp = s1.top() + temp;
                    s1.pop();
                }
                if(s1.top() == '[')
                    s1.pop();
                string combine = "";
                for(int k=0;k<t;k++)
                    combine = combine + temp;
                for(int k=0;k<combine.length();k++)
                    s1.push(combine[k]);
            }
            else
            {
                s1.push(s[i]);
                // cout<<s1.top();
            }
            i++;
        }
        s = "";
        while(!s1.empty())
        {
            s = s1.top() + s;
            s1.pop();
        }
        return s;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends