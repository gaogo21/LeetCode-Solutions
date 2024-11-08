class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int hash1[26] = {0};
        int hash2[26] = {0};

        for (int i = 0; i < s1.size(); ++ i)
        {
            hash1[s1[i] - 'a']++;
        }

        for (int left = 0, right = 0; right < s2.size(); ++ right)
        {
            //1.进窗口
            hash2[s2[right] - 'a']++;

            if (right - left + 1 == s1.size())
            {
                bool issame = true;
                //2.判断hash1和hash2是否相等 --更新结果
                for (int i = 0; i < 26; ++ i)
                {
                    if (hash1[i] != hash2[i])
                    {
                        issame = false;
                        break;
                    }
                }

                if (issame)
                {
                    return true;
                }

                //3.出窗口
                hash2[s2[left] - 'a']--;
                ++left;
            }
        }
        return false;
    }
};