class Solution {
    //采用移动零的策略，将0改为val
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = 0;
        for (; right < nums.size();)
        {
            if (nums[right] != val)
            {
                swap(nums[left], nums[right]);
                ++left;
                ++right;
            }
            else
            {
                ++right;
            }
        }

        return left;
    }
};