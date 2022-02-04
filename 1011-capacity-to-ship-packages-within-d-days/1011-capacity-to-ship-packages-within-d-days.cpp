class Solution {
public:
    
    bool solve(int sum, vector<int>& num, int days)
    {
        int count =1;
        int total = 0;
        
        for(int i=0;i<num.size();i++)
        {
            total += num[i];
            
            if(total > sum)
            {
                total = num[i];
                count++;
            }
            
            if(count > days)
                return false;
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int max_ele = INT_MIN;
        int sum =0;
        int left = 0;
        int right = 0;
        
        for(int i=0;i<weights.size();i++)
        {
            sum += weights[i];
            max_ele = max(max_ele,weights[i]);
        }
        
        left = max_ele;
        right = sum;
        
        int mid = 0;
        
        while(left<=right)
        {
            mid = left + (right-left)/2;
            
            if(solve(mid,weights,days))
            {
                right = mid-1;
            }
            else
                left = mid + 1;
        }
        return left;
    }
};