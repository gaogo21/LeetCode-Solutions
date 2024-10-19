class Solution {
public:
    void duplicateZeros(vector<int>& nums) {
        int cur = 0, dest = -1, n = nums.size();
        while(cur < n)
        {
            if (nums[cur] == 0)
                dest += 2;
            else
                ++dest;

            if (dest >= n - 1)
                break;
            
            ++cur;
        }

        //处理边界问题--> 特殊情况
        if (dest == n)
        {
            nums[n - 1] = 0;
            --cur;
            dest -= 2;
        }

        while(cur >= 0)
        {
            if (nums[cur] == 0)
            {
                nums[dest] = 0;
                --dest;
                nums[dest] = 0;
            }
            else
            {
                nums[dest] = nums[cur];
            }

            --cur;
            --dest;
        }
    }
};