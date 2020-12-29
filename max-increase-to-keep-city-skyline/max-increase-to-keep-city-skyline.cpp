// Go through entire matrix, and keep a count of the max value in each column and each row using seperate vectors
// Go through matrix again, this time, increase the total_sum by the difference in height if the new height (min(col_max[r][c], row_max[r][c])) is greater than the current height.
​
// Time Complexity  - O(mn)
// Space Complexity - O(m + n) 
​
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int n = grid.size(), current, total_sum = 0;
        vector <int> row_maxes(n, 0), col_maxes(n, 0);
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                col_maxes[c] = max(col_maxes[c], grid[r][c]);
                row_maxes[r] = max(row_maxes[r], grid[r][c]);
            }
        }
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                current = max(grid[r][c], min(row_maxes[r], col_maxes[c]));
                if(current > grid[r][c])
                    total_sum += current - grid[r][c];
            }
        }
        
        return total_sum;
    }
};
