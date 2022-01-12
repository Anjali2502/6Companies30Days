// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        int x1 = L1[0];
        int y1 = L1[1];
        int x2 = R1[0];
        int y2 = R1[1];
        int x3 = L2[0];
        int y3 = L2[1];
        int x4 = R2[0];
        int y4 = R2[1];
        
        if(x1 > x4 || x3 > x2)
        return 0;
        
        if(y1 < y4 || y3 < y2)
        return 0;
        
        return 1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends