class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<int>zeros;
        
        for(int i=0;i<n;i++)
        {
            int n_zero = 0;
            for(int j=n-1;j>=0;j--)
            {
                if(grid[i][j] == 0)
                    n_zero++;
                else
                    break;
            }
            zeros.push_back(n_zero);
        }
        
        int count=0;
        
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(zeros[i]>= n-i-1)
                continue;
            
            flag = 0;
            
            for(int j=i+1;j<n;j++)
            {
                if(zeros[j]>=n-i-1)
                {
                    flag = 1;
                    while(i<j)
                    {
                         int temp=zeros[j];
                        zeros[j]=zeros[j-1];
                        zeros[j-1]=temp;
                        j--;
                        count++;
                    }
                    break;
                }
            }
            if(!flag)
                return -1;
        }
        return count;
    }
};