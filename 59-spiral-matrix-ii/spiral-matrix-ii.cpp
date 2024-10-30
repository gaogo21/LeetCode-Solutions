class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        int target = n * n;

        int l = 0;
        int r = n - 1;
        int u = 0;
        int d = n - 1;

        while(num <= target)
        {   
            //1.从左往右
            for (int i = l; i <= r; ++ i)
                res[u][i] = num++;
            if (++u > d) break;

            //2.从上往下
            for (int i = u; i <= d; ++ i)
                res[i][r] = num++;
            if (--r < l) break;

            //3.从右往左
            for (int i = r; i >= l; -- i)
                res[d][i] = num++;
            if (--d < u) break;

            //4.从下往上
            for (int i = d; i >= u; -- i)
                res[i][l] = num++;
            if (++l > r) break;
        }

        return res;
    }
};