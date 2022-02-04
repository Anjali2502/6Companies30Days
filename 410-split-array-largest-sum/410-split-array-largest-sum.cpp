class Solution {
public:
    
    int no_of_splits(int sum,vector<int>& nums)
    {
        int count = 1;
        int sub_array_sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sub_array_sum += nums[i];
            if(sub_array_sum > sum)
            {
                sub_array_sum = nums[i];
                count++;
            }
            
            // if(count>m)
            //     return false;
        }
        return count;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        int max_ele = INT_MIN;
        int right =0;
        int left = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            
            max_ele = max(max_ele,nums[i]);
        }
        
        left = max_ele;
        right = sum;
        // cout<<left<<" "<<right<<" ";
        int mid = 0;
        int ans = 0;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            
            if(no_of_splits(mid,nums)<=m)
            {
                right = mid-1;
                // ans = mid;
            }
            else
                left = mid+1;
                
        }
        return left;
    }
};