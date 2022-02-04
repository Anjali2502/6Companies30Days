/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int right = mountainArr.length() - 1;
        int left = 0;
        int peak = 0;
        int mid = 0;
        while(left<right)
        {
            mid = (left + right)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
            {
                left = mid+1;
                peak = mid+1;
            }
            else
                right = mid;
        }
        // cout<<peak<<" ";
        
        left = 0;
        right = peak;
        
        while(left <= right)
        {
            mid = (left+right)/2;
            
            if(mountainArr.get(mid) == target)
            return mid;
            
            else if(mountainArr.get(mid) > target)
            {
                right = mid-1;
            }
            else
                left = mid+1;
        }
        
        
        left = peak;
        right = mountainArr.length() - 1;
        while(left <= right)
        {
            mid = (left+right)/2;
            
            if(mountainArr.get(mid) == target)
            return mid;
            
            else if(mountainArr.get(mid) < target)
            {
                right = mid-1;
            }
            else
                left = mid+1;
        }
        
        return -1;
    }
};