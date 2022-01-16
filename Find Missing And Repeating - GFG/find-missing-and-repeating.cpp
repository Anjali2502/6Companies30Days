// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    
    int arr1[2];
    
    int *findTwoElement(int *arr, int n) {
        // code here
        
        // sort(arr, arr+n);
        // long long sum = 0;
        // long long missing =0;
        // for(int i=0;i<n;i++)
        // {
        //     sum+=arr[i];
        //     if(i==n-1)
        //     break;
        //     if(arr[i] == arr[i+1])
        //     arr1[0] = arr[i];
        // }
        // long long s = (n*(n+1))/2;
        // missing = s + arr1[0] - sum;
        // arr1[1] = missing;
        // return arr1;
        
        for(int j=0;j<n;j++)
        {
            if(arr[abs(arr[j])-1] < 0)
            {
                arr1[0] = abs(arr[j]);
            }
            
            else
            arr[abs(arr[j])-1] = -arr[abs(arr[j])-1];
        }
        
        for(int j=0;j<n;j++)
        {
            if(arr[j] > 0)
            {
                arr1[1] = j+1;
                break;
            }
        }
        return arr1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends