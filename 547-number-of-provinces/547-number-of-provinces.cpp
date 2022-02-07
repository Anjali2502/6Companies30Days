class Solution {
public:
    
    void solve(vector<vector<int>>&graph, int i)
    {
        graph[i][i] = 0;
        for(int j=0;j<graph.size();j++)
        {
            if(graph[i][j] == 1)
            {
                graph[i][j] = 0;
                if(graph[j][j] == 1)
                    solve(graph,j);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        
        int n = isConnected.size();
        
        for(int i=0;i<n;i++)
        {
            if(isConnected[i][i] == 0)
                continue;
            
            ans++;
            solve(isConnected,i);
        }
        return ans;
    }
};