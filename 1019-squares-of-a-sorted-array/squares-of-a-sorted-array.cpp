class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //1.将所有的数先平方
        for (int i = 0; i < nums.size(); ++ i)
        {
            nums[i] = nums[i] * nums[i];
        }

        //2.将所有数排序一遍
        sort(nums.begin(), nums.end());

        return nums;
    }
};