class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        while(right < nums.size())
        {
            if (nums[left] == nums[right])
                ++right;
            else
            {
                ++left;
                swap(nums[left], nums[right]);
                ++right;
            }
        }

        return left + 1;
    }
};