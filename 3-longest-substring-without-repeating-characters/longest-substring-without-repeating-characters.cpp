class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = {0};
        int res = 0;
        for (int left = 0, right = 0; right < s.size(); ++ right)
        {
            //1.进窗口
            hash[s[right]]++;

            //2.出窗口
            while(hash[s[right]] > 1)
            {
                hash[s[left]]--;
                ++left;
            }

            //更新结果
            res = max(res, (right - left + 1));
        }

        return res;
    }
};