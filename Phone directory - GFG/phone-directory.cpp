// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>>ans;
        
        string s1 = "";
        for(int i=0;i<s.length();i++)
        {
            
            s1 += s[i];
            vector<string>temp;
            for(int j=0;j<n;j++)
            {
                string str = "";
                str = contact[j];
                string str1 = "";
                str1 = str.substr(0,i+1);
                if(s1 == str1)
                {
                    auto itr = find(temp.begin(),temp.end(),str);
                    if(itr == temp.end())
                    {
                        temp.push_back(str);
                    }
                }
            }
            // for(int k=0;k<temp.size();k++)
            // cout<<temp[k]<<endl;
            if(temp.size() == 0)
            {
                temp.push_back("0");
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends