class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        //固定住i，然后使用双指针
        for (int i = 0; i < n;)
        {
            int left = i + 1, right = n - 1, target = -nums[i];
            while(left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum > target)  //说明大了
                    right--;
                else if (sum < target)
                    left++;
                else
                {
                    res.push_back({nums[left], nums[right], nums[i]});
                    //进行去重
                    ++left, --right;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                }
            }
            ++i;
            while (i < n && nums[i] == nums[i - 1]) ++i;
        }

        return res;
    }
};