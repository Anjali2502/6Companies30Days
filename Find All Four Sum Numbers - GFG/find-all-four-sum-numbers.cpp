// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-3;i++)
        {
            for(int j=i+1;j<arr.size()-2;j++)
            {
                int m = j+1;
                int l = arr.size() - 1;
                
                while(m<l)
                {
                    vector<int>temp;
                    if((arr[m]+arr[l]) == (k-arr[i]-arr[j]))
                    {
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[m]);
                        temp.push_back(arr[l]);
                        ans.push_back(temp);
                        
                        while(m<l && arr[m]==temp[2])
                            m++;
                            
                        while(m<l && arr[l]==temp[3])
                            l--;
                    }
                    else if((arr[m]+arr[l]) > (k-arr[i]-arr[j]))
                    {
                        l--;
                    }
                    else
                    m++;
                }
                
                while(j+1<arr.size() && arr[j+1]==arr[j])
                    j++;
            }
            
            while(i+1<arr.size() && arr[i+1]==arr[i])
                    i++;
        }
        return ans;
        // Your code goes here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends