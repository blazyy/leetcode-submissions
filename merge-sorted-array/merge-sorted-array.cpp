class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
        m--, n--;
        int index = nums1.size() - 1;
        while(index >= 0) {
            if(m < 0)
                nums1[index] = nums2[n--];
            else if(n < 0)
                nums1[index] = nums1[m--];
            else
                if(nums1[m] < nums2[n])
                    nums1[index] = nums2[n--];
                else
                    nums1[index] = nums1[m--];
            index--;
        }
    }
};

// Old Solution. Bad. O((n + m)log(n + m)).
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for(int i = m, j = 0; i < m + n; i++, j++)
//             nums1[i] = nums2[j];
//         sort(nums1.begin(), nums1.end());
//     }
// };
