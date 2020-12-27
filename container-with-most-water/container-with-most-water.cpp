class Solution {
public:
    int maxArea(vector <int> &height) {
        int max_area = 0, l = 0, r = height.size() - 1;
        while(l < r){
            max_area = max(max_area, (r - l) * min(height[l], height[r]));
            if(height[l] < height[r]) l++;
            else if(height[l] > height[r]) r--;
            else{
                l++, r--;
            }
        }
        return max_area;
    }
};
​
// TLE Solution
// class Solution {
// public:
//     int maxArea(vector <int> &height) {
//         int max_area = 0;
//         for(int i = 0; i < height.size(); i++)
//             for(int j = i + 1; j < height.size() - 1; j++)
//                 if(j != i)
//                     max_area = max(max_area, (j - i) * min(height[i], height[j]));
//         return max_area;
//     }
// };
