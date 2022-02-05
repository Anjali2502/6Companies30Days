class Solution {
public:
    
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    void solve(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<bool>>& ocean)
    {
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size())
            return ;
        if(heights[i][j] < prev || ocean[i][j]) return ;
        
        ocean[i][j] = true;
        
        for(int k=0;k<4;k++)
        {
            solve(heights,i+dir[k][0],j+dir[k][1],heights[i][j],ocean);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>>ans;
        if(heights.size() == 0 || heights[0].size() == 0)
            return ans;
        
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<bool>> pacific( row , vector<bool> (col));
        vector<vector<bool>> atlantic( row , vector<bool> (col));
        
        for(int i=0;i<col;i++)
        {
            solve(heights,0,i,INT_MIN,pacific);
            solve(heights,row-1,i,INT_MIN,atlantic);
        }
        
        for(int i=0;i<row;i++)
        {
            solve(heights,i,0,INT_MIN,pacific);
            solve(heights,i,col-1,INT_MIN,atlantic);
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
        
    }
};