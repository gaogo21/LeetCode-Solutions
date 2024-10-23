class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int, int> hash;
        int ret = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right)
        {
            //1.进窗口
            hash[nums[right]]++;

            //2.出窗口
            while(hash.size() > 2)
            {
                hash[nums[left]]--;
                if (hash[nums[left]] == 0)
                {
                    hash.erase(nums[left]);
                }
                ++left;
            }

            //更新结果
            ret = max(ret, (right - left + 1));
        }

        return ret;
    }
};