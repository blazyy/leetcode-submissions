// Keep another vector containing all the updates, this is more efficient than going through the entire matrix which will lead to a time complexity of O(m x n)
​
// Time Complexity  - O(u) where u is the number of updates made
// Space Complexity - O(u) (Actually 5u, but we ignore the constants)
​
class SubrectangleQueries {
public:
    vector <vector <int>> rect, updates;
    
    SubrectangleQueries(vector <vector <int>> &rectangle) {
        rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates.push_back(vector <int> {row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        // While iterating the updates vector, we check if the row and col are within the rows and cols that were used to update the rectangle at some point in time. If they are, return the value.
        for(int i = updates.size() - 1; i >= 0; i--) {
            if(row >= updates[i][0] and row <= updates[i][2] and col >= updates[i][1] and col <= updates[i][3])
                return updates[i][4];
        }
        return rect[row][col]; // Code reaches here when the value at [row][col] wasn't even updated once.
    }
};
​
/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
​
// Old Solution
​
// Time Complexity  - O(m x n)
// Space Complexity - O(1) (disregarding the actual matrix itself)
​
// class SubrectangleQueries {
// public:
//     vector <vector <int>> rectangle;
    
//     SubrectangleQueries(vector <vector <int>> &rect) {
//         rectangle = rect;
//     }
    
//     void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
//         for(int r = row1; r <= row2; r++)
