class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[26] = {0};
        int hash2[26] = {0};
        vector<int> res;

        for (int i = 0; i < p.size(); ++ i)
        {
            hash1[p[i] - 'a']++;
        }

        for (int left = 0, right = 0; right < s.size(); ++ right)
        {
            //1.进窗口
            hash2[s[right] - 'a']++;
            
            //2.比较hash1和hash2
            if (right - left + 1 == p.size())
            {
                bool issame = true;
                for (int i = 0; i < 26; ++ i)
                {
                    if (hash1[i] != hash2[i])
                    {
                        issame = false;
                        break;
                    }
                }

                //说明hash1和hash2相等
                if (issame)
                {
                    res.push_back(left);
                }

                //3.出窗口
                hash2[s[left] - 'a']--;
                ++left;
            }
        }

        return res;
    }
};