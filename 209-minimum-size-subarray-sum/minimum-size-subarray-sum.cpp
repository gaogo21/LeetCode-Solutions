class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, sum = 0;
        for (int left = 0, right = 0; right < nums.size(); ++ right)
        {
            //1.进窗口
            sum += nums[right];

            //2.出窗口 --> 有条件
            while(sum >= target)
            {
                //3.更新结果
                res = min(res, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }

        //如果res没有被改变，说明整个数组加起来都没有target大，因此返回0
        if (res == INT_MAX)
            return 0;
        return res;
    }
};