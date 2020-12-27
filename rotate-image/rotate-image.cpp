class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if(i != j)
                    swap(matrix[i][j], matrix[j][i]);
        // horizontal flip
        int start = 0;
        int end = n - 1;
        while(start < end){
            for(int i = 0; i < n; i++)
                swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
};
