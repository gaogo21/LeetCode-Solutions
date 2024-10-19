class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int left = 0, right = 0; right < nums.size();)
        {
            if (nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                ++ left;
            }
            ++right;
        }
    }
};