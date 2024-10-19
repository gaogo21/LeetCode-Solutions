class Solution {
public:

    //计算平方和
    int func(int n)
    {
        int sum = 0, b = 0;
        while(n != 0)
        {
            b = n % 10;
            n /= 10;
            sum += b * b;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = func(n);
        while(slow != fast)
        {
            slow = func(slow);
            fast = func(func(fast));
        }

        return slow == 1;
    }
};