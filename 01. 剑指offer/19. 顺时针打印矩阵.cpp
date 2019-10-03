// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
// 例如，如果输入如下 4 X 4 矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16，则依次打印出数字 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size(), col, start = 0;
        vector<int> res;
        
        if(row == 0) return res;
        col = matrix[0].size();
        if(col == 0) return res;
        while(col>start*2 && row>start*2) {
            helper(matrix, row, col, start, res);
            ++start;
        }
        return res;
    }
    
    void helper(vector<vector<int>> &matrix, int row, int col, int start, vector<int> &res) {
        int i, x = col-1-start, y = row-1-start;
        
        for(i=start; i<=x; ++i) res.push_back(matrix[start][i]);
        if(start < y) for(i=start+1; i<=y; ++i) res.push_back(matrix[i][x]);
        if(start<x && start<y) for(i=x-1; i>=start; --i) res.push_back(matrix[y][i]);
        if(start<x && start<y-1) for(i=y-1; i>=start+1; --i) res.push_back(matrix[i][start]);
    }
};
