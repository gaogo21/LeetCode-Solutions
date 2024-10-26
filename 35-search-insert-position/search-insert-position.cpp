class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //特判
        if (nums[0] > target)
            return 0;
        
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if (target < nums[mid])
            {
                right = mid - 1;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        //走到这里，说明没有找到
        if (nums[left] < target)    
            return left + 1;
        else
            return left;
    }
};