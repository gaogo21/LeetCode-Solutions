class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int left = 0, right =  nums.size() - 1;
        while(left < right) //是否取等？
        {
            int mid = left + (right - left ) / 2;  //是否 + 1？
            if (nums[mid] < nums[mid + 1])  //说明在上升的那一半
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        //最终的结果就是left == right,这时候left和right都指向峰值
        return left;
    }
};