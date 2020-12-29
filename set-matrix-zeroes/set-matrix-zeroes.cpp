// Using the first row and first column to mark which rows and colums have zeroes in them.
// Time Complexity  - O(m x n)
// Space Complexity - O(1)
​
class Solution {
public:
    void setZeroes(vector <vector <int>> &matrix) {
        
        int nrows = matrix.size();
        int ncols = matrix[0].size();
        bool first_row_has_zeros = false;
        bool first_col_has_zeros = false;
        
        // Checking if first row has zeros
        for(int col = 0; col < ncols; col++) {
            if(matrix[0][col] == 0) {
                first_row_has_zeros = true;
                break;
            }            
        }
        
        // Checking if first column has zeros
        for(int row = 0; row < nrows; row++) {
            if(matrix[row][0] == 0) {
                first_col_has_zeros = true;
                break;
            }
        }
        
        // Going through matrix and marking (in the first row and column) which rows and columns have zeros
        for(int row = 1; row < nrows; row++) {
            for(int col = 1; col < ncols; col++) {
                if(matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }
        
        // Setting rows to zero using the first column as guide
        for(int row = 1; row < nrows; row++)
            if(matrix[row][0] == 0)
                set_row_to_zero(matrix, row);
        
        // Setting columns to zero using the first row as guide
        for(int col = 1; col < ncols; col++)
            if(matrix[0][col] == 0)
                set_col_to_zero(matrix, col);
        
        // Last thing is to set the first row to zeroes if the initial unmodified matrix had zeroes in the first row
        if(first_row_has_zeros)
            set_row_to_zero(matrix, 0);
        
        // Same thing but for the column
        if(first_col_has_zeros)
            set_col_to_zero(matrix, 0);
    }
    
    void set_row_to_zero(vector <vector <int>> &matrix, int row) {
        for(int col = 0; col < matrix[0].size(); col++)
            matrix[row][col] = 0;
    }
    
    void set_col_to_zero(vector <vector <int>> &matrix, int col) {
        for(int row = 0; row < matrix.size(); row++)
            matrix[row][col] = 0;
    }
};
