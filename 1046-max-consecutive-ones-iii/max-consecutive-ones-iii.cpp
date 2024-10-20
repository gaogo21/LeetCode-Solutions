class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int tmp = 0;
        for (int left = 0, right = 0; right < n; ++ right)
        {
            //进窗口
            if (nums[right] == 0)
            {
                ++tmp;
            }

            //出窗口
            while(tmp > k)
            {
                if (nums[left] == 0)
                    tmp--;
                ++left;
            }

            res = max(res, (right - left + 1));
        }

        return res;
    }
};