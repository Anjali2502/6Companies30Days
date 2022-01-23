// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        
        vector<int>ans;
        
        if(r==1 && c==1)
        {
            ans.push_back(matrix[0][0]);
            return ans;
        }
        
        if(c == 1)
        {
            for(int i=0;i<r;i++)
            {
                ans.push_back(matrix[i][0]);
            }
            return ans;
        }
        
        if(r == 1)
        {
            for(int i=0;i<c;i++)
            {
                ans.push_back(matrix[0][i]);
            }
            return ans;
        }
        
        int left = c;
        int right = c;
        int down = r;
        int up = r-1;
        
        int row = 0;
        int col = 0;
        
        int flag = 0;
        ans.push_back(matrix[0][0]);
        while((row<r && col<c) && (row>=0 && col>=0))
        {
            if(right > 1)
            {
                for(int i=1;i<right;i++)
                {
                    if(row>=0 && col<c)
                    {
                        col+=1;
                        if(col<c)
                        {
                            ans.push_back(matrix[row][col]);
                        }
                    }
                }
                if(flag == 0)
                {
                    right--;
                    flag = 1;
                }
                else
                right-=2;
            }
            else
            break;
            
            if(down > 1)
            {
                for(int i=1;i<down;i++)
                {
                    if(row<r && col>=0)
                    {
                        row+=1;
                        if(row<r)
                        {
                            ans.push_back(matrix[row][col]);
                        }
                    }
                }
                down-=2;
            }
            else
            break;
            
            if(left > 1)
            {
                for(int i=1;i<left;i++)
                {
                    if(row>=0 && col>=0)
                    {
                        col-=1;
                        if(col>=0)
                        {
                            ans.push_back(matrix[row][col]);
                        }
                    }
                }
                left-=2;
            }
            else
            break;
            
            if(up >1)
            {
                for(int i=1;i<up;i++)
                {
                    if(row>=0 && col>=0)
                    {
                        row-=1;
                        if(row>=0)
                        {
                            ans.push_back(matrix[row][col]);
                        }
                    }
                }
                up = up-2;
            }
            else
            break;
            
            
            // cout<<up<<"--";
        }
        
        return ans;
        // code here 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends