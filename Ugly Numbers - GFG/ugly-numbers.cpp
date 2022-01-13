// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {	   
	    if(n==1)
	    return 1;
	    
	    int f2 = 0;
	    int f3 = 0;
	    int f5 = 0;
	    vector<ull> v(n+1);
	    v[0] = 1;
	    for(int i=1;i<=n;i++)
	    {
	        ull k =  min(2*v[f2], 3*v[f3]);
	        v[i] = min(k, 5*v[f5]);
	        if(v[i] == 2*v[f2])
	        f2++;
	        if(v[i] == 3*v[f3])
	        f3++;
	        if(v[i] == 5*v[f5])
	        f5++;
	    }
	    // code here
	    ull ans = v[n-1];
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends