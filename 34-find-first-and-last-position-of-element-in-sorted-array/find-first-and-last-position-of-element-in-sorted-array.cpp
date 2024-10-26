class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};

        //1.找左端点
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if (target > nums[mid])
            {
                left = mid + 1;  
            }
            else
            {
                right = mid;    //target <= nums[mid]
            }          
        }

        int begin = left;
        //特殊情况处理：如果nums[left] 不等于 target，说明target不存在
        if (nums[left] != target)
            return {-1, -1};

        //找右端点
        left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }

        int end = right;
        return {begin, end};
    }
};