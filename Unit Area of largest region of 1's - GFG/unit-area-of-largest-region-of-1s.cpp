// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    
    int unit_area(vector<vector<int>>& g, int i, int j)
    {
        if(i>=0 && j>=0 && i<g.size() && j<g[0].size() && g[i][j]==1)
        {
            g[i][j] = 0;
            return 1 + unit_area(g,i+1,j) + unit_area(g,i,j+1) + unit_area(g,i-1,j) + unit_area(g,i,j-1) + unit_area(g,i+1,j+1) +unit_area(g,i-1,j-1) + unit_area(g,i+1,j-1) + unit_area(g,i-1,j+1);
        }
        else
        return 0;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        int count = 0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j])
                {
                    count = max(count,unit_area(grid,i,j));
                }
            }
        }
        
        return count;
        
        // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends