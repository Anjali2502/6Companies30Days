class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0;
        int max_len = nums.size()+1;
        
        int sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            
            while(sum>=target)
            {
                max_len = min(max_len,i-left+1);
                sum -= nums[left];
                left++;
            }
        }
        
        if(max_len == nums.size()+1)
            return 0;
        
        return max_len;
        
    }
};