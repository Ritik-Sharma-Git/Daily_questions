class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();    
        for (int row = 0; row < num_rows; ++row) {
            if (grid[row][0] == 0) {
                for (int col = 0; col < num_cols; ++col) {
                    grid[row][col] ^= 1; 
                }
            }
        }
        int total_score = 0;
        for (int col = 0; col < num_cols; ++col) {
            int col_count = 0; 
            for (int row = 0; row < num_rows; ++row) {
                col_count += grid[row][col];
            }
            int max_col_value = std::max(col_count, num_rows - col_count);
            total_score += max_col_value * (1 << (num_cols - col - 1));
        }
        return total_score;
        
    }
};