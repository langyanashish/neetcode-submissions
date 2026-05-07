class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int rowStart = 0, colStart = 0;
        vector<int> ans;
        while(rowStart < rows && colStart < cols)
        {
            for(int i = colStart; i < cols; i++)
                ans.push_back(matrix[rowStart][i]);
            rowStart++;
            for(int i = rowStart; i < rows; i++)
                ans.push_back(matrix[i][cols-1]);
            cols--;
            if(rowStart < rows)
            {
                for(int i = cols-1; i>=colStart; i--)
                    ans.push_back(matrix[rows-1][i]);
                rows--;
            }
            if(colStart < cols)
            {
                for(int i = rows-1; i >= rowStart; i--)
                    ans.push_back(matrix[i][colStart]);
                colStart++;
            }
        }
        return ans;
    }
};
