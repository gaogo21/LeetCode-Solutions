class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>> res;

        while (i < firstList.size() && j < secondList.size())
        {
            //1.找到交集的第一个值
            int start = max(firstList[i][0], secondList[j][0]);
            //2.找到交集的第二个值
            int end = min(firstList[i][1], secondList[j][1]);

            if (start <= end)
            {
                res.push_back({start, end});
            }

            //如果小于，说明已经处理（比较）过， 直接跳过，进入下一个区间
            if (firstList[i][1]< secondList[j][1])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }

        return res;
    }
};