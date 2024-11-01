class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();

        // 如果元素个数不相同，返回原矩阵
        if (r * c != m * n) {
            return mat;
        }

        // 初始化为r行c列的矩阵
        vector<vector<int>> res(r, vector<int>(c, 0));

        for (int i = 0; i < m * n; ++i) {
            // 直接计算出新矩阵中的行列位置，并填充元素
            res[i / c][i % c] = mat[i / n][i % n];
        }
        
        return res;
    }

    //通过一维坐标访问二维数组中的元素
    int get(vector<vector<int>> matrix, int index)
    {
        int m = matrix.size(), n = matrix[0].size();  //行，列
        //计算二维中的横纵坐标 -- 通过index计算出在二维矩阵中的横纵坐标
        int i = index / n, j = index % n;
        return matrix[i][j];
    }

    //通过一维坐标设置二维数组中的元素
    //第三个参数是每一个二维坐标的值
    void set(vector<vector<int>> matrix, int index, int value)   
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = index / n, j = index % n;
        matrix[i][j] = value;
    }
};