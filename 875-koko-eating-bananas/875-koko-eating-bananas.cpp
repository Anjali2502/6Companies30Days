class Solution {
public:
    
    bool can_finish(int k, vector<int>& piles, int H)
    {
        int count = 0;
        for(int i=0;i<piles.size();i++)
        {
            count += (1 + (piles[i]-1)/k);
        }
        if(count <=H)
            return true;
        
        return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = 1;
        
        for(int i=0;i<piles.size();i++)
        {
            right = max(right,piles[i]);
        }
        int ans = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(can_finish(mid,piles,h))
            {
                right = mid-1;
                ans = mid;
            }
            else
                left = mid+1;
        }
        return ans;
    }
};