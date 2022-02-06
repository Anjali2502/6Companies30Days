class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int flag_0 = 0;
        int flag_1 = 0;
        queue<pair<int,int>>q;
        vector<vector<int>> vis( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                    flag_0 = 1;
                else
                {
                    flag_1 = 1;
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        if(!flag_0 || !flag_1)
            return -1;
        
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        int distance = -1;
        while(!q.empty())
        {
            distance++;
            int k = q.size();
            for(int i=0;i<k;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int new_x = x + dir[j][0];
                    int new_y = y + dir[j][1];
                    
                    if(new_x<0 || new_y<0 || new_x>=n || new_y>=n)
                        continue;
                    
                    if(vis[new_x][new_y])
                        continue;
                    
                    q.push({new_x,new_y});
                    vis[new_x][new_y] = 1;
                }
            }
        }
        
        return distance;
    }
};