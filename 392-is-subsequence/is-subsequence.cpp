class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        
        while(i < n && j < m)
        {
            if (s[i] == t[j])   //如果匹配到了，就i ++
                ++i;
            ++j;  //不管有没有匹配到。都++j
        }

        //走到最后，判断i是否等于s.size()就行了，如果等于，就说明s全部匹配到了
        return i == n;
    }
};