// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    
		    int n = str.length();
		    
		    if(str[0] == '0')
		    return 0;
		    
		    vector<int> v(n+1);
		    v[0] = 1;
		    v[1] = 1;
		    int c1 = 0; 
		    int c2 = 0;
		    for(int i=2;i<=n;i++)
		    {
		        if(str[i-1] > '0')
		        {
		            c1 = v[i-1];
		            if(str[i-2] == '1' || str[i-2] == '2' && str[i-1] < '7')
		            {
		                c2 = v[i-2];
		                v[i] = (c1+c2)%(1000000007);
		            }
		            else
		            v[i] = c1%1000000007;
		        }
		        else if(str[i-2] == '1' || str[i-2] == '2')
		        {
		            v[i] = v[i-2]%1000000007;
		        }
		        else
		        return 0;
		        
		    }
		    return v[n]%(1000000007);
		    // Code here
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends