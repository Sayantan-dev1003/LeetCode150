class Solution {
    void shift(int val, vector<int>& nums1, int leng, int i) {
        for (int j = leng-1; j > i; j--)
            nums1[j] = nums1[j-1];
        nums1[i] = val;
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) 
        {
            nums1 = nums2;
            return;
        }
        int i = 0;
        for (int j = 0; j<n; j++)
        {
            while (nums1[i] <= nums2[j] && (m+j)>i)
                i++;
            shift(nums2[j], nums1, m+n, i);
        }
    }
};
